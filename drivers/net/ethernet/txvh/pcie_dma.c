#include <linux/pci.h>
#include "pcie.h"

static void dma_imwr(struct pci_dev *pdev, unsigned int chn_num,
			unsigned int w_r, unsigned int done_addr,
			unsigned int abrt_addr, unsigned short int data)
{
	if (w_r) {  //read
		pci_write_config_dword(pdev, DMA_READ_DONE_IMWR_LOW_OFF, done_addr);
		pci_write_config_dword(pdev, DMA_READ_DONE_IMWR_HIGH_OFF, 0x0); 
		pci_write_config_dword(pdev, DMA_READ_ABORT_IMWR_LOW_OFF, abrt_addr);
		pci_write_config_dword(pdev, DMA_READ_ABORT_IMWR_HIGH_OFF, 0x0);
		//at most two channels supported here
		switch(chn_num) {
		case 0:
			pci_write_config_dword(pdev, DMA_READ_CH01_IMWR_DATA_OFF, data);
			break;
		case 1:
			pci_write_config_dword(pdev, DMA_READ_CH01_IMWR_DATA_OFF, (data << 16));
			break;
		default:
			break;
		}
	} else {  //write
		pci_write_config_dword(pdev, DMA_WRITE_DONE_IMWR_LOW_OFF, done_addr);
		pci_write_config_dword(pdev, DMA_WRITE_DONE_IMWR_HIGH_OFF, 0x0);
		pci_write_config_dword(pdev, DMA_WRITE_ABORT_IMWR_LOW_OFF, abrt_addr);
		pci_write_config_dword(pdev, DMA_WRITE_ABORT_IMWR_HIGH_OFF, 0x0);
		switch(chn_num) {
		case 0:
			pci_write_config_dword(pdev, DMA_WRITE_CH01_IMWR_DATA_OFF, data);
			break;
		case 1: 
			pci_write_config_dword(pdev, DMA_WRITE_CH01_IMWR_DATA_OFF, (data << 16));
			break;
		default:
			break;
		}
	}
}

//w_r: 0(write), 1(read), 32-bit system
static void nonll_dma_config(struct pci_dev *pdev,
				unsigned int chn_num,
				unsigned int w_r, unsigned int sz_byte,
				unsigned int sar, unsigned int dar)
{
	if(w_r) {  //read
		pci_write_config_dword(pdev, DMA_READ_ENGINE_EN_OFF, 0x1);
		pci_write_config_dword(pdev, DMA_VIEWPORT_SEL_OFF, ((w_r << 31) + chn_num));
		pci_write_config_dword(pdev, DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF, 0x8421);    //weight arbitration for channel 0-3
		pci_write_config_dword(pdev, DMA_READ_INT_MASK_OFF, 0x0);
		pci_write_config_dword(pdev, DMA_CH_CONTROL1_OFF_RDCH_0_0, ((0x1 << 4) + (0x1 << 3)));
		pci_write_config_dword(pdev, DMA_TRANSFER_SIZE_OFF_RDCH_0_0, sz_byte);
		pci_write_config_dword(pdev, DMA_SAR_LOW_OFF_RDCH_0_0, sar);
		pci_write_config_dword(pdev, DMA_SAR_HIGH_OFF_RDCH_0_0, 0x0);
		pci_write_config_dword(pdev, DMA_DAR_LOW_OFF_RDCH_0_0, dar);
		pci_write_config_dword(pdev, DMA_DAR_HIGH_OFF_RDCH_0_0, 0x0);
	} else { //write
		pci_write_config_dword(pdev, DMA_WRITE_ENGINE_EN_OFF, 0x1);
		pci_write_config_dword(pdev, DMA_VIEWPORT_SEL_OFF, ((w_r << 31) + chn_num));
		pci_write_config_dword(pdev, DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF, 0x8421);  //weight arbitration for channel 0-3
		pci_write_config_dword(pdev, DMA_WRITE_INT_MASK_OFF, 0x0);
		pci_write_config_dword(pdev, DMA_CH_CONTROL1_OFF_WRCH_0, ((0x1 << 4) + (0x1 << 3)));  
		pci_write_config_dword(pdev, DMA_TRANSFER_SIZE_OFF_WRCH_0, sz_byte);
		pci_write_config_dword(pdev, DMA_SAR_LOW_OFF_WRCH_0, sar);
		pci_write_config_dword(pdev, DMA_SAR_HIGH_OFF_WRCH_0, 0x0);
		pci_write_config_dword(pdev, DMA_DAR_LOW_OFF_WRCH_0, dar);
		pci_write_config_dword(pdev, DMA_DAR_HIGH_OFF_WRCH_0, 0x0); 
	}
}

static void dma_doorbell(struct pci_dev *pdev,
				unsigned int chn_num, unsigned int w_r)
{
	if (w_r) {  //read
		pci_write_config_dword(pdev, DMA_READ_DOORBELL_OFF, ((0 << 31) + (chn_num)));
	} else {  //write
		pci_write_config_dword(pdev, DMA_WRITE_DOORBELL_OFF, ((0 << 31) + (chn_num)));
	}  
}

static void dma_com(struct pci_dev *pdev,
			unsigned int chn_num, unsigned int w_r)
{
	if (w_r) {  //read
		u32 val;
		pci_read_config_dword(pdev, DMA_READ_INT_STATUS_OFF, &val);
		while(!(val & (0x1 << chn_num)))
			pci_read_config_dword(pdev, DMA_READ_INT_STATUS_OFF, &val);
		pci_write_config_dword(pdev, DMA_READ_INT_CLEAR_OFF, (0x1 << chn_num));
	} else { //write
		u32 val;
		pci_read_config_dword(pdev, DMA_WRITE_INT_STATUS_OFF, &val);
		while(!(val & (0x1 << chn_num)))
			pci_read_config_dword(pdev, DMA_WRITE_INT_STATUS_OFF, &val);
		pci_write_config_dword(pdev, DMA_WRITE_INT_CLEAR_OFF, (0x1 << chn_num));
	}
}

#define DRAM0_BASE	0x00010000
#define DRAM1_BASE	0x00040000

int pcie_dma_rw(struct pci_dev *pdev)
{
	//unsigned int i = 0;

	pci_write_config_dword(pdev, GEN2_CTRL_OFF, 0x00100000); //Select de-emphasis level -3.5db
	pci_write_config_dword(pdev, PORT_LINK_CTRL_OFF, 0x80);  //enable fast link mode

	pci_write_config_dword(pdev, DEVICE_CONTROL_DEVICE_STATUS, (0x1 << 5)); //max payload size = 256 bytes

	nonll_dma_config(pdev, 0/*chn_num*/, 1/*w_r*/, 0x200/*sz_byte*/, 0x8e6ff000/*sar*/, DRAM0_BASE/*dar*/);
	dma_imwr(pdev, 0/*chn_num*/, 1/*w_r*/, 0x8e6ff000/*done_addr*/, 0/*abrt_addr*/, 0x0/*data*/);
	dma_doorbell(pdev, 0/*chn_num*/, 1/*w_r*/);

	nonll_dma_config(pdev, 0/*chn_num*/, 0/*w_r*/, 0x200/*sz_byte*/, DRAM0_BASE/*sar*/, 0x8e6ff000/*dar*/);
	dma_imwr(pdev, 0/*chn_num*/, 0/*w_r*/, 0x8e6ff000/*done_addr*/, 0/*abrt_addr*/, 0x1/*data*/);
	dma_doorbell(pdev, 0/*chn_num*/, 0/*w_r*/);

	dma_com(pdev, 0/*chn_num*/, 1/*w_r*/);
	dma_com(pdev, 0/*chn_num*/, 0/*w_r*/);

	while(1);
}
