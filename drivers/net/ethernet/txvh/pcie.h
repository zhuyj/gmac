/*
 * ABSTRACT : Register definition header file for 
 */
#define PCIE_BASE		0x0 //(tp->bar1_addr)
#define PF0_TYPE0_HDR_BaseAddress (PCIE_BASE + 0x0)

#define PF0_PM_CAP_BaseAddress (PCIE_BASE + 0x40)

#define PF0_PCIE_CAP_BaseAddress (PCIE_BASE + 0x70)

#define PF0_AER_CAP_BaseAddress (PCIE_BASE + 0x100)

#define PF0_MSI_CAP_BaseAddress (PCIE_BASE + 0x50)

#define VF1_PF0_TYPE0_HDR_BaseAddress (PCIE_BASE + 0x200000)

#define VF1_PF0_ARI_CAP_BaseAddress (PCIE_BASE + 0x200148)

#define VF1_PF0_PCIE_CAP_BaseAddress (PCIE_BASE + 0x200070)

#define PF0_PORT_LOGIC_BaseAddress (PCIE_BASE + 0x700)

/* Register DEVICE_ID_VENDOR_ID_REG */
/* Device ID and Vendor ID Register.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_ID_VENDOR_ID_REG (PF0_TYPE0_HDR_BaseAddress + 0x0)
#define DEVICE_ID_VENDOR_ID_REG_RegisterSize 32
#define DEVICE_ID_VENDOR_ID_REG_RegisterResetValue 0xabcd16c3
#define DEVICE_ID_VENDOR_ID_REG_RegisterResetMask 0xffffffff

/* Register Field information for DEVICE_ID_VENDOR_ID_REG */

/* Register DEVICE_ID_VENDOR_ID_REG field PCI_TYPE0_VENDOR_ID */
/* Vendor ID. PCI-SIG assigned Manufacturer Identifier.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W(sticky) else R(sticky) 
 - Dbi2: R */
#define DEVICE_ID_VENDOR_ID_REG_PCI_TYPE0_VENDOR_ID_BitAddressOffset 0
#define DEVICE_ID_VENDOR_ID_REG_PCI_TYPE0_VENDOR_ID_RegisterSize 16

/* Register DEVICE_ID_VENDOR_ID_REG field PCI_TYPE0_DEVICE_ID */
/* Device ID. Vendor Assigned Device Identifier.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W(sticky) else R(sticky) 
 - Dbi2: R */
#define DEVICE_ID_VENDOR_ID_REG_PCI_TYPE0_DEVICE_ID_BitAddressOffset 16
#define DEVICE_ID_VENDOR_ID_REG_PCI_TYPE0_DEVICE_ID_RegisterSize 16

/* End of Register Definition for DEVICE_ID_VENDOR_ID_REG */

/* Register STATUS_COMMAND_REG */
/* Command and Status Register.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define STATUS_COMMAND_REG (PF0_TYPE0_HDR_BaseAddress + 0x4)
#define STATUS_COMMAND_REG_RegisterSize 32
#define STATUS_COMMAND_REG_RegisterResetValue 0x100000
#define STATUS_COMMAND_REG_RegisterResetMask 0xffffffff

/* Register Field information for STATUS_COMMAND_REG */

/* Register STATUS_COMMAND_REG field PCI_TYPE0_IO_EN */
/* Enables IO Access Response.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br>You cannot write to this register if your configuration has no IO bars; that is, the internal signal has_io_bar=0.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W(sticky) else R(sticky) 
 - Dbi2: if (DBI_RO_WR_EN == 1) then R/W(sticky) else R(sticky) */
#define STATUS_COMMAND_REG_PCI_TYPE0_IO_EN_BitAddressOffset 0
#define STATUS_COMMAND_REG_PCI_TYPE0_IO_EN_RegisterSize 1

/* Register STATUS_COMMAND_REG field PCI_TYPE0_MEM_SPACE_EN */
/* Enables Memory Access Response.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br>You cannot write to this register if your configuration has no MEM bars; that is, the internal signal has_mem_bar=0.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W(sticky) else R(sticky) 
 - Dbi2: if (DBI_RO_WR_EN == 1) then R/W(sticky) else R(sticky) */
#define STATUS_COMMAND_REG_PCI_TYPE0_MEM_SPACE_EN_BitAddressOffset 1
#define STATUS_COMMAND_REG_PCI_TYPE0_MEM_SPACE_EN_RegisterSize 1

/* Register STATUS_COMMAND_REG field PCI_TYPE0_BUS_MASTER_EN */
/* Bus Master Enable. Controls Issuing of Memory and I/O Requests.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define STATUS_COMMAND_REG_PCI_TYPE0_BUS_MASTER_EN_BitAddressOffset 2
#define STATUS_COMMAND_REG_PCI_TYPE0_BUS_MASTER_EN_RegisterSize 1

/* Register STATUS_COMMAND_REG field PCI_TYPE0_SPECIAL_CYCLE_OPERATION */
/* Special Cycle Enable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define STATUS_COMMAND_REG_PCI_TYPE0_SPECIAL_CYCLE_OPERATION_BitAddressOffset 3
#define STATUS_COMMAND_REG_PCI_TYPE0_SPECIAL_CYCLE_OPERATION_RegisterSize 1

/* Register STATUS_COMMAND_REG field PCI_TYPE_MWI_ENABLE */
/* Memory Write and Invalidate.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define STATUS_COMMAND_REG_PCI_TYPE_MWI_ENABLE_BitAddressOffset 4
#define STATUS_COMMAND_REG_PCI_TYPE_MWI_ENABLE_RegisterSize 1

/* Register STATUS_COMMAND_REG field PCI_TYPE_VGA_PALETTE_SNOOP */
/* VGA Palette Snoop.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define STATUS_COMMAND_REG_PCI_TYPE_VGA_PALETTE_SNOOP_BitAddressOffset 5
#define STATUS_COMMAND_REG_PCI_TYPE_VGA_PALETTE_SNOOP_RegisterSize 1

/* Register STATUS_COMMAND_REG field PCI_TYPE0_PARITY_ERR_EN */
/* Controls Logging of Poisoned TLPs.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define STATUS_COMMAND_REG_PCI_TYPE0_PARITY_ERR_EN_BitAddressOffset 6
#define STATUS_COMMAND_REG_PCI_TYPE0_PARITY_ERR_EN_RegisterSize 1

/* Register STATUS_COMMAND_REG field PCI_TYPE_IDSEL_STEPPING */
/* IDSEL Stepping.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define STATUS_COMMAND_REG_PCI_TYPE_IDSEL_STEPPING_BitAddressOffset 7
#define STATUS_COMMAND_REG_PCI_TYPE_IDSEL_STEPPING_RegisterSize 1

/* Register STATUS_COMMAND_REG field PCI_TYPE0_SERREN */
/* Enables Error Reporting.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define STATUS_COMMAND_REG_PCI_TYPE0_SERREN_BitAddressOffset 8
#define STATUS_COMMAND_REG_PCI_TYPE0_SERREN_RegisterSize 1

/* Register STATUS_COMMAND_REG field RSVDP_9 */
/* Reserved for future use. */
#define STATUS_COMMAND_REG_RSVDP_9_BitAddressOffset 9
#define STATUS_COMMAND_REG_RSVDP_9_RegisterSize 1

/* Register STATUS_COMMAND_REG field PCI_TYPE0_INT_EN */
/* Controls generation of interrupts by a function.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define STATUS_COMMAND_REG_PCI_TYPE0_INT_EN_BitAddressOffset 10
#define STATUS_COMMAND_REG_PCI_TYPE0_INT_EN_RegisterSize 1

/* Register STATUS_COMMAND_REG field PCI_TYPE_RESERV */
/* Reserved.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define STATUS_COMMAND_REG_PCI_TYPE_RESERV_BitAddressOffset 11
#define STATUS_COMMAND_REG_PCI_TYPE_RESERV_RegisterSize 5

/* Register STATUS_COMMAND_REG field RSVDP_17 */
/* Reserved for future use. */
#define STATUS_COMMAND_REG_RSVDP_17_BitAddressOffset 17
#define STATUS_COMMAND_REG_RSVDP_17_RegisterSize 2

/* Register STATUS_COMMAND_REG field INT_STATUS */
/* Emulation interrupt pending.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define STATUS_COMMAND_REG_INT_STATUS_BitAddressOffset 19
#define STATUS_COMMAND_REG_INT_STATUS_RegisterSize 1

/* Register STATUS_COMMAND_REG field CAP_LIST */
/* Extended Capability.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define STATUS_COMMAND_REG_CAP_LIST_BitAddressOffset 20
#define STATUS_COMMAND_REG_CAP_LIST_RegisterSize 1

/* Register STATUS_COMMAND_REG field FAST_66MHZ_CAP */
/* PCI 66MHz Capability.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define STATUS_COMMAND_REG_FAST_66MHZ_CAP_BitAddressOffset 21
#define STATUS_COMMAND_REG_FAST_66MHZ_CAP_RegisterSize 1

/* Register STATUS_COMMAND_REG field RSVDP_22 */
/* Reserved for future use. */
#define STATUS_COMMAND_REG_RSVDP_22_BitAddressOffset 22
#define STATUS_COMMAND_REG_RSVDP_22_RegisterSize 1

/* Register STATUS_COMMAND_REG field FAST_B2B_CAP */
/* Fast Back to Back Transaction Capable and Enable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define STATUS_COMMAND_REG_FAST_B2B_CAP_BitAddressOffset 23
#define STATUS_COMMAND_REG_FAST_B2B_CAP_RegisterSize 1

/* Register STATUS_COMMAND_REG field MASTER_DPE */
/* Controls poisoned Completion and Request error reporting.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define STATUS_COMMAND_REG_MASTER_DPE_BitAddressOffset 24
#define STATUS_COMMAND_REG_MASTER_DPE_RegisterSize 1

/* Register STATUS_COMMAND_REG field DEV_SEL_TIMING */
/* Device Select Timing.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define STATUS_COMMAND_REG_DEV_SEL_TIMING_BitAddressOffset 25
#define STATUS_COMMAND_REG_DEV_SEL_TIMING_RegisterSize 2

/* Register STATUS_COMMAND_REG field SIGNALED_TARGET_ABORT */
/* Completer Abort Error.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define STATUS_COMMAND_REG_SIGNALED_TARGET_ABORT_BitAddressOffset 27
#define STATUS_COMMAND_REG_SIGNALED_TARGET_ABORT_RegisterSize 1

/* Register STATUS_COMMAND_REG field RCVD_TARGET_ABORT */
/* Completer Abort received.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define STATUS_COMMAND_REG_RCVD_TARGET_ABORT_BitAddressOffset 28
#define STATUS_COMMAND_REG_RCVD_TARGET_ABORT_RegisterSize 1

/* Register STATUS_COMMAND_REG field RCVD_MASTER_ABORT */
/* Unsupported request completion status received.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define STATUS_COMMAND_REG_RCVD_MASTER_ABORT_BitAddressOffset 29
#define STATUS_COMMAND_REG_RCVD_MASTER_ABORT_RegisterSize 1

/* Register STATUS_COMMAND_REG field SIGNALED_SYS_ERR */
/* Fatal or Non-Fatal Error Message sent by function.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define STATUS_COMMAND_REG_SIGNALED_SYS_ERR_BitAddressOffset 30
#define STATUS_COMMAND_REG_SIGNALED_SYS_ERR_RegisterSize 1

/* Register STATUS_COMMAND_REG field DETECTED_PARITY_ERR */
/* Poisoned TLP received by function.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define STATUS_COMMAND_REG_DETECTED_PARITY_ERR_BitAddressOffset 31
#define STATUS_COMMAND_REG_DETECTED_PARITY_ERR_RegisterSize 1

/* End of Register Definition for STATUS_COMMAND_REG */

/* Register CLASS_CODE_REVISION_ID */
/* Class Code and Revision ID Register.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define CLASS_CODE_REVISION_ID (PF0_TYPE0_HDR_BaseAddress + 0x8)
#define CLASS_CODE_REVISION_ID_RegisterSize 32
#define CLASS_CODE_REVISION_ID_RegisterResetValue 0x1
#define CLASS_CODE_REVISION_ID_RegisterResetMask 0xffffffff

/* Register Field information for CLASS_CODE_REVISION_ID */

/* Register CLASS_CODE_REVISION_ID field REVISION_ID */
/* Vendor chosen Revision ID.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R (sticky) 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W(sticky) else R(sticky) 
 - Dbi2: R (sticky)
<i>Note</i>: This register field is sticky. */
#define CLASS_CODE_REVISION_ID_REVISION_ID_BitAddressOffset 0
#define CLASS_CODE_REVISION_ID_REVISION_ID_RegisterSize 8

/* Register CLASS_CODE_REVISION_ID field PROGRAM_INTERFACE */
/* Class Code Programming Interface.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R (sticky) 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W(sticky) else R(sticky) 
 - Dbi2: R (sticky)
<i>Note</i>: This register field is sticky. */
#define CLASS_CODE_REVISION_ID_PROGRAM_INTERFACE_BitAddressOffset 8
#define CLASS_CODE_REVISION_ID_PROGRAM_INTERFACE_RegisterSize 8

/* Register CLASS_CODE_REVISION_ID field SUBCLASS_CODE */
/* Subclass Code to represent Device Type.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R (sticky) 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W(sticky) else R(sticky) 
 - Dbi2: R (sticky)
<i>Note</i>: This register field is sticky. */
#define CLASS_CODE_REVISION_ID_SUBCLASS_CODE_BitAddressOffset 16
#define CLASS_CODE_REVISION_ID_SUBCLASS_CODE_RegisterSize 8

/* Register CLASS_CODE_REVISION_ID field BASE_CLASS_CODE */
/* Base Class Code to represent Device Type.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R (sticky) 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W(sticky) else R(sticky) 
 - Dbi2: R (sticky)
<i>Note</i>: This register field is sticky. */
#define CLASS_CODE_REVISION_ID_BASE_CLASS_CODE_BitAddressOffset 24
#define CLASS_CODE_REVISION_ID_BASE_CLASS_CODE_RegisterSize 8

/* End of Register Definition for CLASS_CODE_REVISION_ID */

/* Register BIST_HEADER_TYPE_LATENCY_CACHE_LINE_SIZE_REG */
/* BIST, Header Type, Cache Line Size, and Latency Timer Registers.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define BIST_HEADER_TYPE_LATENCY_CACHE_LINE_SIZE_REG (PF0_TYPE0_HDR_BaseAddress + 0xc)
#define BIST_HEADER_TYPE_LATENCY_CACHE_LINE_SIZE_REG_RegisterSize 32
#define BIST_HEADER_TYPE_LATENCY_CACHE_LINE_SIZE_REG_RegisterResetValue 0x0
#define BIST_HEADER_TYPE_LATENCY_CACHE_LINE_SIZE_REG_RegisterResetMask 0xffffffff

/* Register Field information for BIST_HEADER_TYPE_LATENCY_CACHE_LINE_SIZE_REG */

/* Register BIST_HEADER_TYPE_LATENCY_CACHE_LINE_SIZE_REG field CACHE_LINE_SIZE */
/* Cache Line Size. Has no effect on PCIe device behavior.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define BIST_HEADER_TYPE_LATENCY_CACHE_LINE_SIZE_REG_CACHE_LINE_SIZE_BitAddressOffset 0
#define BIST_HEADER_TYPE_LATENCY_CACHE_LINE_SIZE_REG_CACHE_LINE_SIZE_RegisterSize 8

/* Register BIST_HEADER_TYPE_LATENCY_CACHE_LINE_SIZE_REG field LATENCY_MASTER_TIMER */
/* Does not apply to PCI Express.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define BIST_HEADER_TYPE_LATENCY_CACHE_LINE_SIZE_REG_LATENCY_MASTER_TIMER_BitAddressOffset 8
#define BIST_HEADER_TYPE_LATENCY_CACHE_LINE_SIZE_REG_LATENCY_MASTER_TIMER_RegisterSize 8

/* Register BIST_HEADER_TYPE_LATENCY_CACHE_LINE_SIZE_REG field HEADER_TYPE */
/* Specifies Header Type.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define BIST_HEADER_TYPE_LATENCY_CACHE_LINE_SIZE_REG_HEADER_TYPE_BitAddressOffset 16
#define BIST_HEADER_TYPE_LATENCY_CACHE_LINE_SIZE_REG_HEADER_TYPE_RegisterSize 7

/* Register BIST_HEADER_TYPE_LATENCY_CACHE_LINE_SIZE_REG field MULTI_FUNC */
/* Specifies whether device is multifunction.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R (sticky) 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W(sticky) else R(sticky) 
 - Dbi2: R (sticky)
<i>Note</i>: This register field is sticky. */
#define BIST_HEADER_TYPE_LATENCY_CACHE_LINE_SIZE_REG_MULTI_FUNC_BitAddressOffset 23
#define BIST_HEADER_TYPE_LATENCY_CACHE_LINE_SIZE_REG_MULTI_FUNC_RegisterSize 1

/* Register BIST_HEADER_TYPE_LATENCY_CACHE_LINE_SIZE_REG field BIST */
/* Optional for BIST support.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define BIST_HEADER_TYPE_LATENCY_CACHE_LINE_SIZE_REG_BIST_BitAddressOffset 24
#define BIST_HEADER_TYPE_LATENCY_CACHE_LINE_SIZE_REG_BIST_RegisterSize 8

/* End of Register Definition for BIST_HEADER_TYPE_LATENCY_CACHE_LINE_SIZE_REG */

/* Register BAR0_MASK_REG */
/* BAR0 and BAR Mask.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. The mask for this BAR exists (if implemented) as a shadow register at this address. The assertion of CS2 (that is, assert the dbi_cs2 input, or the CS2 address bit for the AHB/AXI bridge) is required to write to the second register at this address. For more details, see "Accessing Configuration Registers". */
#define BAR0_MASK_REG (PF0_TYPE0_HDR_BaseAddress + 0x10)
#define BAR0_MASK_REG_RegisterSize 32
#define BAR0_MASK_REG_RegisterResetValue 0x1ffff
#define BAR0_MASK_REG_RegisterResetMask 0xffffffff

/* Register Field information for BAR0_MASK_REG */

/* Register BAR0_MASK_REG field PCI_TYPE0_BAR0_ENABLED */
/* BAR0 Mask Enabled.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: No access 
 - Dbi: No access 
 - Dbi2: W (sticky) */
#define BAR0_MASK_REG_PCI_TYPE0_BAR0_ENABLED_BitAddressOffset 0
#define BAR0_MASK_REG_PCI_TYPE0_BAR0_ENABLED_RegisterSize 1

/* Register BAR0_MASK_REG field PCI_TYPE0_BAR0_MASK */
/* BAR0 Mask.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: No access 
 - Dbi: No access 
 - Dbi2: W (sticky) */
#define BAR0_MASK_REG_PCI_TYPE0_BAR0_MASK_BitAddressOffset 1
#define BAR0_MASK_REG_PCI_TYPE0_BAR0_MASK_RegisterSize 31

/* End of Register Definition for BAR0_MASK_REG */

/* Register BAR0_REG */
/* BAR0 and BAR Mask.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. The mask for this BAR exists (if implemented) as a shadow register at this address. The assertion of CS2 (that is, assert the dbi_cs2 input, or the CS2 address bit for the AHB/AXI bridge) is required to write to the second register at this address. For more details, see "Accessing Configuration Registers". */
#define BAR0_REG (PF0_TYPE0_HDR_BaseAddress + 0x10)
#define BAR0_REG_RegisterSize 32
#define BAR0_REG_RegisterResetValue 0x4
#define BAR0_REG_RegisterResetMask 0xffffffff

/* Register Field information for BAR0_REG */

/* Register BAR0_REG field BAR0_MEM_IO */
/* BAR0 Memory Space Indicator.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (BAR_ENABLED == 1) then (if [DBI_RO_WR_EN == 1] then R/W else R) else RO 
 - Dbi2: R<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && CX_DBI_RO_WR_EN && DEFAULT_BAR0_ENABLED_$pf) ?  R/W : (CX_MEMORY_MAP_VIEW==0 ) ?  R: (CX_MEMORY_MAP_VIEW==1 ) ? R:  R</ct> */
#define BAR0_REG_BAR0_MEM_IO_BitAddressOffset 0
#define BAR0_REG_BAR0_MEM_IO_RegisterSize 1

/* Register BAR0_REG field BAR0_TYPE */
/* BAR0 32-bit or 64-bit.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (BAR_ENABLED == 1) then (if [DBI_RO_WR_EN == 1] then R/W else R) else RO 
 - Dbi2: R */
#define BAR0_REG_BAR0_TYPE_BitAddressOffset 1
#define BAR0_REG_BAR0_TYPE_RegisterSize 2

/* Register BAR0_REG field BAR0_PREFETCH */
/* BAR0 Prefetchable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (BAR_ENABLED == 1) then (if [DBI_RO_WR_EN == 1] then R/W else R) else RO 
 - Dbi2: R */
#define BAR0_REG_BAR0_PREFETCH_BitAddressOffset 3
#define BAR0_REG_BAR0_PREFETCH_RegisterSize 1

/* Register BAR0_REG field BAR0_START */
/* BAR0 Base Address.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R/W if enabled else R 
 - Dbi: R/W if enabled else R 
 - Dbi2: R */
#define BAR0_REG_BAR0_START_BitAddressOffset 4
#define BAR0_REG_BAR0_START_RegisterSize 28

/* End of Register Definition for BAR0_REG */

/* Register BAR1_MASK_REG */
/* BAR1 and BAR Mask.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. The mask for this BAR exists (if implemented) as a shadow register at this address. The assertion of CS2 (that is, assert the dbi_cs2 input, or the CS2 address bit for the AHB/AXI bridge) is required to write to the second register at this address. For more details, see "Accessing Configuration Registers". */
#define BAR1_MASK_REG (PF0_TYPE0_HDR_BaseAddress + 0x14)
#define BAR1_MASK_REG_RegisterSize 32
#define BAR1_MASK_REG_RegisterResetValue 0x1fffe
#define BAR1_MASK_REG_RegisterResetMask 0xffffffff

/* Register Field information for BAR1_MASK_REG */

/* Register BAR1_MASK_REG field PCI_TYPE0_BAR1_ENABLED */
/* BAR1 Mask Enabled.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: No access 
 - Dbi: No access 
 - Dbi2: W (sticky) */
#define BAR1_MASK_REG_PCI_TYPE0_BAR1_ENABLED_BitAddressOffset 0
#define BAR1_MASK_REG_PCI_TYPE0_BAR1_ENABLED_RegisterSize 1

/* Register BAR1_MASK_REG field PCI_TYPE0_BAR1_MASK */
/* BAR1 Mask.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: No access 
 - Dbi: No access 
 - Dbi2: W (sticky) */
#define BAR1_MASK_REG_PCI_TYPE0_BAR1_MASK_BitAddressOffset 1
#define BAR1_MASK_REG_PCI_TYPE0_BAR1_MASK_RegisterSize 31

/* End of Register Definition for BAR1_MASK_REG */

/* Register BAR1_REG */
/* BAR1 and BAR Mask.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. The mask for this BAR exists (if implemented) as a shadow register at this address. The assertion of CS2 (that is, assert the dbi_cs2 input, or the CS2 address bit for the AHB/AXI bridge) is required to write to the second register at this address. For more details, see "Accessing Configuration Registers". */
#define BAR1_REG (PF0_TYPE0_HDR_BaseAddress + 0x14)
#define BAR1_REG_RegisterSize 32
#define BAR1_REG_RegisterResetValue 0x0
#define BAR1_REG_RegisterResetMask 0xffffffff

/* Register Field information for BAR1_REG */

/* Register BAR1_REG field BAR1_MEM_IO */
/* BAR1 Memory Space Indicator.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (BAR_ENABLED == 1) then (if [DBI_RO_WR_EN == 1] then R/W else R) else RO 
 - Dbi2: R<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && CX_DBI_RO_WR_EN && DEFAULT_BAR1_ENABLED_$pf) ?  R/W : (CX_MEMORY_MAP_VIEW==0 ) ?  R: (CX_MEMORY_MAP_VIEW==1 ) ? R:  R</ct> */
#define BAR1_REG_BAR1_MEM_IO_BitAddressOffset 0
#define BAR1_REG_BAR1_MEM_IO_RegisterSize 1

/* Register BAR1_REG field BAR1_TYPE */
/* BAR1 32-bit or 64-bit.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (BAR_ENABLED == 1) then (if [DBI_RO_WR_EN == 1] then R/W else R) else RO 
 - Dbi2: R */
#define BAR1_REG_BAR1_TYPE_BitAddressOffset 1
#define BAR1_REG_BAR1_TYPE_RegisterSize 2

/* Register BAR1_REG field BAR1_PREFETCH */
/* BAR1 Prefetchable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (BAR_ENABLED == 1) then (if [DBI_RO_WR_EN == 1] then R/W else R) else RO 
 - Dbi2: R */
#define BAR1_REG_BAR1_PREFETCH_BitAddressOffset 3
#define BAR1_REG_BAR1_PREFETCH_RegisterSize 1

/* Register BAR1_REG field BAR1_START */
/* BAR1 Base Address.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R/W if enabled else R 
 - Dbi: R/W if enabled else R 
 - Dbi2: R */
#define BAR1_REG_BAR1_START_BitAddressOffset 4
#define BAR1_REG_BAR1_START_RegisterSize 28

/* End of Register Definition for BAR1_REG */

/* Register BAR2_MASK_REG */
/* BAR2 and BAR Mask.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. The mask for this BAR exists (if implemented) as a shadow register at this address. The assertion of CS2 (that is, assert the dbi_cs2 input, or the CS2 address bit for the AHB/AXI bridge) is required to write to the second register at this address. For more details, see "Accessing Configuration Registers". */
#define BAR2_MASK_REG (PF0_TYPE0_HDR_BaseAddress + 0x18)
#define BAR2_MASK_REG_RegisterSize 32
#define BAR2_MASK_REG_RegisterResetValue 0x1ffff
#define BAR2_MASK_REG_RegisterResetMask 0xffffffff

/* Register Field information for BAR2_MASK_REG */

/* Register BAR2_MASK_REG field PCI_TYPE0_BAR2_ENABLED */
/* BAR2 Mask Enabled.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: No access 
 - Dbi: No access 
 - Dbi2: W (sticky) */
#define BAR2_MASK_REG_PCI_TYPE0_BAR2_ENABLED_BitAddressOffset 0
#define BAR2_MASK_REG_PCI_TYPE0_BAR2_ENABLED_RegisterSize 1

/* Register BAR2_MASK_REG field PCI_TYPE0_BAR2_MASK */
/* BAR2 Mask.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: No access 
 - Dbi: No access 
 - Dbi2: W (sticky) */
#define BAR2_MASK_REG_PCI_TYPE0_BAR2_MASK_BitAddressOffset 1
#define BAR2_MASK_REG_PCI_TYPE0_BAR2_MASK_RegisterSize 31

/* End of Register Definition for BAR2_MASK_REG */

/* Register BAR2_REG */
/* BAR2 and BAR Mask.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. The mask for this BAR exists (if implemented) as a shadow register at this address. The assertion of CS2 (that is, assert the dbi_cs2 input, or the CS2 address bit for the AHB/AXI bridge) is required to write to the second register at this address. For more details, see "Accessing Configuration Registers". */
#define BAR2_REG (PF0_TYPE0_HDR_BaseAddress + 0x18)
#define BAR2_REG_RegisterSize 32
#define BAR2_REG_RegisterResetValue 0x0
#define BAR2_REG_RegisterResetMask 0xffffffff

/* Register Field information for BAR2_REG */

/* Register BAR2_REG field BAR2_MEM_IO */
/* BAR2 Memory Space Indicator.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (BAR_ENABLED == 1) then (if [DBI_RO_WR_EN == 1] then R/W else R) else RO 
 - Dbi2: R<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && CX_DBI_RO_WR_EN && DEFAULT_BAR2_ENABLED_$pf) ?  R/W : (CX_MEMORY_MAP_VIEW==0 ) ?  R: (CX_MEMORY_MAP_VIEW==1 ) ? R:  R</ct> */
#define BAR2_REG_BAR2_MEM_IO_BitAddressOffset 0
#define BAR2_REG_BAR2_MEM_IO_RegisterSize 1

/* Register BAR2_REG field BAR2_TYPE */
/* BAR2 32-bit or 64-bit.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (BAR_ENABLED == 1) then (if [DBI_RO_WR_EN == 1] then R/W else R) else RO 
 - Dbi2: R */
#define BAR2_REG_BAR2_TYPE_BitAddressOffset 1
#define BAR2_REG_BAR2_TYPE_RegisterSize 2

/* Register BAR2_REG field BAR2_PREFETCH */
/* BAR2 Prefetchable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (BAR_ENABLED == 1) then (if [DBI_RO_WR_EN == 1] then R/W else R) else RO 
 - Dbi2: R */
#define BAR2_REG_BAR2_PREFETCH_BitAddressOffset 3
#define BAR2_REG_BAR2_PREFETCH_RegisterSize 1

/* Register BAR2_REG field BAR2_START */
/* BAR2 Base Address.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R/W if enabled else R 
 - Dbi: R/W if enabled else R 
 - Dbi2: R */
#define BAR2_REG_BAR2_START_BitAddressOffset 4
#define BAR2_REG_BAR2_START_RegisterSize 28

/* End of Register Definition for BAR2_REG */

/* Register BAR3_MASK_REG */
/* BAR3 and BAR Mask.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. The mask for this BAR exists (if implemented) as a shadow register at this address. The assertion of CS2 (that is, assert the dbi_cs2 input, or the CS2 address bit for the AHB/AXI bridge) is required to write to the second register at this address. For more details, see "Accessing Configuration Registers". */
#define BAR3_MASK_REG (PF0_TYPE0_HDR_BaseAddress + 0x1c)
#define BAR3_MASK_REG_RegisterSize 32
#define BAR3_MASK_REG_RegisterResetValue 0x1fffe
#define BAR3_MASK_REG_RegisterResetMask 0xffffffff

/* Register Field information for BAR3_MASK_REG */

/* Register BAR3_MASK_REG field PCI_TYPE0_BAR3_ENABLED */
/* BAR3 Mask Enabled.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: No access 
 - Dbi: No access 
 - Dbi2: W (sticky) */
#define BAR3_MASK_REG_PCI_TYPE0_BAR3_ENABLED_BitAddressOffset 0
#define BAR3_MASK_REG_PCI_TYPE0_BAR3_ENABLED_RegisterSize 1

/* Register BAR3_MASK_REG field PCI_TYPE0_BAR3_MASK */
/* BAR3 Mask.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: No access 
 - Dbi: No access 
 - Dbi2: W (sticky) */
#define BAR3_MASK_REG_PCI_TYPE0_BAR3_MASK_BitAddressOffset 1
#define BAR3_MASK_REG_PCI_TYPE0_BAR3_MASK_RegisterSize 31

/* End of Register Definition for BAR3_MASK_REG */

/* Register BAR3_REG */
/* BAR3 and BAR Mask.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. The mask for this BAR exists (if implemented) as a shadow register at this address. The assertion of CS2 (that is, assert the dbi_cs2 input, or the CS2 address bit for the AHB/AXI bridge) is required to write to the second register at this address. For more details, see "Accessing Configuration Registers". */
#define BAR3_REG (PF0_TYPE0_HDR_BaseAddress + 0x1c)
#define BAR3_REG_RegisterSize 32
#define BAR3_REG_RegisterResetValue 0x0
#define BAR3_REG_RegisterResetMask 0xffffffff

/* Register Field information for BAR3_REG */

/* Register BAR3_REG field BAR3_MEM_IO */
/* BAR3 Memory Space Indicator.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (BAR_ENABLED == 1) then (if [DBI_RO_WR_EN == 1] then R/W else R) else RO 
 - Dbi2: R<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && CX_DBI_RO_WR_EN && DEFAULT_BAR3_ENABLED_$pf) ?  R/W : (CX_MEMORY_MAP_VIEW==0 ) ?  R: (CX_MEMORY_MAP_VIEW==1 ) ? R:  R</ct> */
#define BAR3_REG_BAR3_MEM_IO_BitAddressOffset 0
#define BAR3_REG_BAR3_MEM_IO_RegisterSize 1

/* Register BAR3_REG field BAR3_TYPE */
/* BAR3 32-bit or 64-bit.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (BAR_ENABLED == 1) then (if [DBI_RO_WR_EN == 1] then R/W else R) else RO 
 - Dbi2: R */
#define BAR3_REG_BAR3_TYPE_BitAddressOffset 1
#define BAR3_REG_BAR3_TYPE_RegisterSize 2

/* Register BAR3_REG field BAR3_PREFETCH */
/* BAR3 Prefetchable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (BAR_ENABLED == 1) then (if [DBI_RO_WR_EN == 1] then R/W else R) else RO 
 - Dbi2: R */
#define BAR3_REG_BAR3_PREFETCH_BitAddressOffset 3
#define BAR3_REG_BAR3_PREFETCH_RegisterSize 1

/* Register BAR3_REG field BAR3_START */
/* BAR3 Base Address.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R/W if enabled else R 
 - Dbi: R/W if enabled else R 
 - Dbi2: R */
#define BAR3_REG_BAR3_START_BitAddressOffset 4
#define BAR3_REG_BAR3_START_RegisterSize 28

/* End of Register Definition for BAR3_REG */

/* Register BAR4_MASK_REG */
/* BAR4 and BAR Mask.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. The mask for this BAR exists (if implemented) as a shadow register at this address. The assertion of CS2 (that is, assert the dbi_cs2 input, or the CS2 address bit for the AHB/AXI bridge) is required to write to the second register at this address. For more details, see "Accessing Configuration Registers". */
#define BAR4_MASK_REG (PF0_TYPE0_HDR_BaseAddress + 0x20)
#define BAR4_MASK_REG_RegisterSize 32
#define BAR4_MASK_REG_RegisterResetValue 0x1ffff
#define BAR4_MASK_REG_RegisterResetMask 0xffffffff

/* Register Field information for BAR4_MASK_REG */

/* Register BAR4_MASK_REG field PCI_TYPE0_BAR4_ENABLED */
/* BAR4 Mask Enabled.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: No access 
 - Dbi: No access 
 - Dbi2: W (sticky) */
#define BAR4_MASK_REG_PCI_TYPE0_BAR4_ENABLED_BitAddressOffset 0
#define BAR4_MASK_REG_PCI_TYPE0_BAR4_ENABLED_RegisterSize 1

/* Register BAR4_MASK_REG field PCI_TYPE0_BAR4_MASK */
/* BAR4 Mask.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: No access 
 - Dbi: No access 
 - Dbi2: W (sticky) */
#define BAR4_MASK_REG_PCI_TYPE0_BAR4_MASK_BitAddressOffset 1
#define BAR4_MASK_REG_PCI_TYPE0_BAR4_MASK_RegisterSize 31

/* End of Register Definition for BAR4_MASK_REG */

/* Register BAR4_REG */
/* BAR4 and BAR Mask.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. The mask for this BAR exists (if implemented) as a shadow register at this address. The assertion of CS2 (that is, assert the dbi_cs2 input, or the CS2 address bit for the AHB/AXI bridge) is required to write to the second register at this address. For more details, see "Accessing Configuration Registers". */
#define BAR4_REG (PF0_TYPE0_HDR_BaseAddress + 0x20)
#define BAR4_REG_RegisterSize 32
#define BAR4_REG_RegisterResetValue 0x1
#define BAR4_REG_RegisterResetMask 0xffffffff

/* Register Field information for BAR4_REG */

/* Register BAR4_REG field BAR4_MEM_IO */
/* BAR4 Memory Space Indicator.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (BAR_ENABLED == 1) then (if [DBI_RO_WR_EN == 1] then R/W else R) else RO 
 - Dbi2: R<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && CX_DBI_RO_WR_EN && DEFAULT_BAR4_ENABLED_$pf) ?  R/W : (CX_MEMORY_MAP_VIEW==0 ) ?  R: (CX_MEMORY_MAP_VIEW==1 ) ? R:  R</ct> */
#define BAR4_REG_BAR4_MEM_IO_BitAddressOffset 0
#define BAR4_REG_BAR4_MEM_IO_RegisterSize 1

/* Register BAR4_REG field BAR4_TYPE */
/* BAR4 32-bit or 64-bit.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (BAR_ENABLED == 1) then (if [DBI_RO_WR_EN == 1] then R/W else R) else RO 
 - Dbi2: R */
#define BAR4_REG_BAR4_TYPE_BitAddressOffset 1
#define BAR4_REG_BAR4_TYPE_RegisterSize 2

/* Register BAR4_REG field BAR4_PREFETCH */
/* BAR4 Prefetchable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (BAR_ENABLED == 1) then (if [DBI_RO_WR_EN == 1] then R/W else R) else RO 
 - Dbi2: R */
#define BAR4_REG_BAR4_PREFETCH_BitAddressOffset 3
#define BAR4_REG_BAR4_PREFETCH_RegisterSize 1

/* Register BAR4_REG field BAR4_START */
/* BAR4 Base Address.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R/W if enabled else R 
 - Dbi: R/W if enabled else R 
 - Dbi2: R */
#define BAR4_REG_BAR4_START_BitAddressOffset 4
#define BAR4_REG_BAR4_START_RegisterSize 28

/* End of Register Definition for BAR4_REG */

/* Register BAR5_MASK_REG */
/* BAR5 and BAR Mask.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. The mask for this BAR exists (if implemented) as a shadow register at this address. The assertion of CS2 (that is, assert the dbi_cs2 input, or the CS2 address bit for the AHB/AXI bridge) is required to write to the second register at this address. For more details, see "Accessing Configuration Registers". */
#define BAR5_MASK_REG (PF0_TYPE0_HDR_BaseAddress + 0x24)
#define BAR5_MASK_REG_RegisterSize 32
#define BAR5_MASK_REG_RegisterResetValue 0x1fffe
#define BAR5_MASK_REG_RegisterResetMask 0xffffffff

/* Register Field information for BAR5_MASK_REG */

/* Register BAR5_MASK_REG field PCI_TYPE0_BAR5_ENABLED */
/* BAR5 Mask Enabled.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: No access 
 - Dbi: No access 
 - Dbi2: W (sticky) */
#define BAR5_MASK_REG_PCI_TYPE0_BAR5_ENABLED_BitAddressOffset 0
#define BAR5_MASK_REG_PCI_TYPE0_BAR5_ENABLED_RegisterSize 1

/* Register BAR5_MASK_REG field PCI_TYPE0_BAR5_MASK */
/* BAR5 Mask.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: No access 
 - Dbi: No access 
 - Dbi2: W (sticky) */
#define BAR5_MASK_REG_PCI_TYPE0_BAR5_MASK_BitAddressOffset 1
#define BAR5_MASK_REG_PCI_TYPE0_BAR5_MASK_RegisterSize 31

/* End of Register Definition for BAR5_MASK_REG */

/* Register BAR5_REG */
/* BAR5 and BAR Mask.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. The mask for this BAR exists (if implemented) as a shadow register at this address. The assertion of CS2 (that is, assert the dbi_cs2 input, or the CS2 address bit for the AHB/AXI bridge) is required to write to the second register at this address. For more details, see "Accessing Configuration Registers". */
#define BAR5_REG (PF0_TYPE0_HDR_BaseAddress + 0x24)
#define BAR5_REG_RegisterSize 32
#define BAR5_REG_RegisterResetValue 0x0
#define BAR5_REG_RegisterResetMask 0xffffffff

/* Register Field information for BAR5_REG */

/* Register BAR5_REG field BAR5_MEM_IO */
/* BAR5 Memory Space Indicator.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (BAR_ENABLED == 1) then (if [DBI_RO_WR_EN == 1] then R/W else R) else RO 
 - Dbi2: R<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && CX_DBI_RO_WR_EN && DEFAULT_BAR5_ENABLED_$pf) ?  R/W : (CX_MEMORY_MAP_VIEW==0 ) ?  R: (CX_MEMORY_MAP_VIEW==1 ) ? R:  R</ct> */
#define BAR5_REG_BAR5_MEM_IO_BitAddressOffset 0
#define BAR5_REG_BAR5_MEM_IO_RegisterSize 1

/* Register BAR5_REG field BAR5_TYPE */
/* BAR5 32-bit or 64-bit.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (BAR_ENABLED == 1) then (if [DBI_RO_WR_EN == 1] then R/W else R) else RO 
 - Dbi2: R */
#define BAR5_REG_BAR5_TYPE_BitAddressOffset 1
#define BAR5_REG_BAR5_TYPE_RegisterSize 2

/* Register BAR5_REG field BAR5_PREFETCH */
/* BAR5 Prefetchable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (BAR_ENABLED == 1) then (if [DBI_RO_WR_EN == 1] then R/W else R) else RO 
 - Dbi2: R */
#define BAR5_REG_BAR5_PREFETCH_BitAddressOffset 3
#define BAR5_REG_BAR5_PREFETCH_RegisterSize 1

/* Register BAR5_REG field BAR5_START */
/* BAR5 Base Address.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R/W if enabled else R 
 - Dbi: R/W if enabled else R 
 - Dbi2: R */
#define BAR5_REG_BAR5_START_BitAddressOffset 4
#define BAR5_REG_BAR5_START_RegisterSize 28

/* End of Register Definition for BAR5_REG */

/* Register CARDBUS_CIS_PTR_REG */
/* CardBus CIS Pointer Register.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define CARDBUS_CIS_PTR_REG (PF0_TYPE0_HDR_BaseAddress + 0x28)
#define CARDBUS_CIS_PTR_REG_RegisterSize 32
#define CARDBUS_CIS_PTR_REG_RegisterResetValue 0x0
#define CARDBUS_CIS_PTR_REG_RegisterResetMask 0xffffffff

/* Register Field information for CARDBUS_CIS_PTR_REG */

/* Register CARDBUS_CIS_PTR_REG field CARDBUS_CIS_POINTER */
/* Pointer to Card information Structure (CIS) for the CardBus card.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R (sticky) 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W(sticky) else R(sticky) 
 - Dbi2: R (sticky)
<i>Note</i>: This register field is sticky. */
#define CARDBUS_CIS_PTR_REG_CARDBUS_CIS_POINTER_BitAddressOffset 0
#define CARDBUS_CIS_PTR_REG_CARDBUS_CIS_POINTER_RegisterSize 32

/* End of Register Definition for CARDBUS_CIS_PTR_REG */

/* Register SUBSYSTEM_ID_SUBSYSTEM_VENDOR_ID_REG */
/* Subsystem ID and Subsystem Vendor ID Register.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define SUBSYSTEM_ID_SUBSYSTEM_VENDOR_ID_REG (PF0_TYPE0_HDR_BaseAddress + 0x2c)
#define SUBSYSTEM_ID_SUBSYSTEM_VENDOR_ID_REG_RegisterSize 32
#define SUBSYSTEM_ID_SUBSYSTEM_VENDOR_ID_REG_RegisterResetValue 0x0
#define SUBSYSTEM_ID_SUBSYSTEM_VENDOR_ID_REG_RegisterResetMask 0xffffffff

/* Register Field information for SUBSYSTEM_ID_SUBSYSTEM_VENDOR_ID_REG */

/* Register SUBSYSTEM_ID_SUBSYSTEM_VENDOR_ID_REG field SUBSYS_VENDOR_ID */
/* Subsystem Vendor ID.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R (sticky) 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W(sticky) else R(sticky) 
 - Dbi2: R (sticky)
<i>Note</i>: This register field is sticky. */
#define SUBSYSTEM_ID_SUBSYSTEM_VENDOR_ID_REG_SUBSYS_VENDOR_ID_BitAddressOffset 0
#define SUBSYSTEM_ID_SUBSYSTEM_VENDOR_ID_REG_SUBSYS_VENDOR_ID_RegisterSize 16

/* Register SUBSYSTEM_ID_SUBSYSTEM_VENDOR_ID_REG field SUBSYS_DEV_ID */
/* Subsystem Device ID.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R (sticky) 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W(sticky) else R(sticky) 
 - Dbi2: R (sticky)
<i>Note</i>: This register field is sticky. */
#define SUBSYSTEM_ID_SUBSYSTEM_VENDOR_ID_REG_SUBSYS_DEV_ID_BitAddressOffset 16
#define SUBSYSTEM_ID_SUBSYSTEM_VENDOR_ID_REG_SUBSYS_DEV_ID_RegisterSize 16

/* End of Register Definition for SUBSYSTEM_ID_SUBSYSTEM_VENDOR_ID_REG */

/* Register EXP_ROM_BAR_MASK_REG */
/* Expansion ROM BAR and Mask Register.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. The mask for this ROM BAR exists (if implemented) as a shadow register at this address. The assertion of CS2 (that is, assert the dbi_cs2 input, or the CS2 address bit for the AHB/AXI bridge) is required to write to the second register at this address. For more details, see "Accessing Configuration Registers". */
#define EXP_ROM_BAR_MASK_REG (PF0_TYPE0_HDR_BaseAddress + 0x30)
#define EXP_ROM_BAR_MASK_REG_RegisterSize 32
#define EXP_ROM_BAR_MASK_REG_RegisterResetValue 0x1ffff
#define EXP_ROM_BAR_MASK_REG_RegisterResetMask 0xffffffff

/* Register Field information for EXP_ROM_BAR_MASK_REG */

/* Register EXP_ROM_BAR_MASK_REG field ROM_BAR_ENABLED */
/* Expansion ROM Bar Mask Register Enabled.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: No access 
 - Dbi: No access 
 - Dbi2: if ROM_BAR_ENABLED then W else R */
#define EXP_ROM_BAR_MASK_REG_ROM_BAR_ENABLED_BitAddressOffset 0
#define EXP_ROM_BAR_MASK_REG_ROM_BAR_ENABLED_RegisterSize 1

/* Register EXP_ROM_BAR_MASK_REG field ROM_MASK */
/* Expansion ROM Mask.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: No access 
 - Dbi: No access 
 - Dbi2: if ROM_BAR_ENABLED then W else R */
#define EXP_ROM_BAR_MASK_REG_ROM_MASK_BitAddressOffset 1
#define EXP_ROM_BAR_MASK_REG_ROM_MASK_RegisterSize 31

/* End of Register Definition for EXP_ROM_BAR_MASK_REG */

/* Register EXP_ROM_BASE_ADDR_REG */
/* Expansion ROM BAR and Mask Register.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. The mask for this ROM BAR exists (if implemented) as a shadow register at this address. The assertion of CS2 (that is, assert the dbi_cs2 input, or the CS2 address bit for the AHB/AXI bridge) is required to write to the second register at this address. For more details, see "Accessing Configuration Registers". */
#define EXP_ROM_BASE_ADDR_REG (PF0_TYPE0_HDR_BaseAddress + 0x30)
#define EXP_ROM_BASE_ADDR_REG_RegisterSize 32
#define EXP_ROM_BASE_ADDR_REG_RegisterResetValue 0x1
#define EXP_ROM_BASE_ADDR_REG_RegisterResetMask 0xffffffff

/* Register Field information for EXP_ROM_BASE_ADDR_REG */

/* Register EXP_ROM_BASE_ADDR_REG field ROM_BAR_ENABLE */
/* Expansion ROM Enable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: R 
 - Dbi2: if (DBI_RO_WR_EN == 1) then R/W else R */
#define EXP_ROM_BASE_ADDR_REG_ROM_BAR_ENABLE_BitAddressOffset 0
#define EXP_ROM_BASE_ADDR_REG_ROM_BAR_ENABLE_RegisterSize 1

/* Register EXP_ROM_BASE_ADDR_REG field RSVDP_1 */
/* Reserved for future use. */
#define EXP_ROM_BASE_ADDR_REG_RSVDP_1_BitAddressOffset 1
#define EXP_ROM_BASE_ADDR_REG_RSVDP_1_RegisterSize 10

/* Register EXP_ROM_BASE_ADDR_REG field EXP_ROM_BASE_ADDRESS */
/* Expansion ROM Base Address.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R/W 
 - Dbi: R/W 
 - Dbi2: if (DBI_RO_WR_EN == 1) then R/W else R */
#define EXP_ROM_BASE_ADDR_REG_EXP_ROM_BASE_ADDRESS_BitAddressOffset 11
#define EXP_ROM_BASE_ADDR_REG_EXP_ROM_BASE_ADDRESS_RegisterSize 21

/* End of Register Definition for EXP_ROM_BASE_ADDR_REG */

/* Register PCI_CAP_PTR_REG */
/* Capability Pointer Register.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define PCI_CAP_PTR_REG (PF0_TYPE0_HDR_BaseAddress + 0x34)
#define PCI_CAP_PTR_REG_RegisterSize 32
#define PCI_CAP_PTR_REG_RegisterResetValue 0x40
#define PCI_CAP_PTR_REG_RegisterResetMask 0xffffffff

/* Register Field information for PCI_CAP_PTR_REG */

/* Register PCI_CAP_PTR_REG field CAP_POINTER */
/* Pointer to first item in the PCI Capability Structure.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R (sticky) 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W(sticky) else R(sticky) 
 - Dbi2: R (sticky)
<i>Note</i>: This register field is sticky. */
#define PCI_CAP_PTR_REG_CAP_POINTER_BitAddressOffset 0
#define PCI_CAP_PTR_REG_CAP_POINTER_RegisterSize 8

/* Register PCI_CAP_PTR_REG field RSVDP_8 */
/* Reserved for future use. */
#define PCI_CAP_PTR_REG_RSVDP_8_BitAddressOffset 8
#define PCI_CAP_PTR_REG_RSVDP_8_RegisterSize 24

/* End of Register Definition for PCI_CAP_PTR_REG */

/* Register MAX_LATENCY_MIN_GRANT_INTERRUPT_PIN_INTERRUPT_LINE_REG */
/* Interrupt Line and Pin Register.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define MAX_LATENCY_MIN_GRANT_INTERRUPT_PIN_INTERRUPT_LINE_REG (PF0_TYPE0_HDR_BaseAddress + 0x3c)
#define MAX_LATENCY_MIN_GRANT_INTERRUPT_PIN_INTERRUPT_LINE_REG_RegisterSize 32
#define MAX_LATENCY_MIN_GRANT_INTERRUPT_PIN_INTERRUPT_LINE_REG_RegisterResetValue 0x1ff
#define MAX_LATENCY_MIN_GRANT_INTERRUPT_PIN_INTERRUPT_LINE_REG_RegisterResetMask 0xffffffff

/* Register Field information for MAX_LATENCY_MIN_GRANT_INTERRUPT_PIN_INTERRUPT_LINE_REG */

/* Register MAX_LATENCY_MIN_GRANT_INTERRUPT_PIN_INTERRUPT_LINE_REG field INT_LINE */
/* PCI Compatible Interrupt Line Routing Register Field.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define MAX_LATENCY_MIN_GRANT_INTERRUPT_PIN_INTERRUPT_LINE_REG_INT_LINE_BitAddressOffset 0
#define MAX_LATENCY_MIN_GRANT_INTERRUPT_PIN_INTERRUPT_LINE_REG_INT_LINE_RegisterSize 8

/* Register MAX_LATENCY_MIN_GRANT_INTERRUPT_PIN_INTERRUPT_LINE_REG field INT_PIN */
/* PCI Compatible Interrupt Pin Register Field.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: R */
#define MAX_LATENCY_MIN_GRANT_INTERRUPT_PIN_INTERRUPT_LINE_REG_INT_PIN_BitAddressOffset 8
#define MAX_LATENCY_MIN_GRANT_INTERRUPT_PIN_INTERRUPT_LINE_REG_INT_PIN_RegisterSize 8

/* Register MAX_LATENCY_MIN_GRANT_INTERRUPT_PIN_INTERRUPT_LINE_REG field RSVDP_16 */
/* Reserved for future use. */
#define MAX_LATENCY_MIN_GRANT_INTERRUPT_PIN_INTERRUPT_LINE_REG_RSVDP_16_BitAddressOffset 16
#define MAX_LATENCY_MIN_GRANT_INTERRUPT_PIN_INTERRUPT_LINE_REG_RSVDP_16_RegisterSize 16

/* End of Register Definition for MAX_LATENCY_MIN_GRANT_INTERRUPT_PIN_INTERRUPT_LINE_REG */


/* Register CAP_ID_NXT_PTR_REG */
/* Power Management Capabilities Register.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define CAP_ID_NXT_PTR_REG (PF0_PM_CAP_BaseAddress + 0x0)
#define CAP_ID_NXT_PTR_REG_RegisterSize 32
#define CAP_ID_NXT_PTR_REG_RegisterResetValue 0xdbc35001
#define CAP_ID_NXT_PTR_REG_RegisterResetMask 0xffffffff

/* Register Field information for CAP_ID_NXT_PTR_REG */

/* Register CAP_ID_NXT_PTR_REG field PM_CAP_ID */
/* Power Management Capability ID.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define CAP_ID_NXT_PTR_REG_PM_CAP_ID_BitAddressOffset 0
#define CAP_ID_NXT_PTR_REG_PM_CAP_ID_RegisterSize 8

/* Register CAP_ID_NXT_PTR_REG field PM_NEXT_POINTER */
/* Next Capability Pointer.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: R */
#define CAP_ID_NXT_PTR_REG_PM_NEXT_POINTER_BitAddressOffset 8
#define CAP_ID_NXT_PTR_REG_PM_NEXT_POINTER_RegisterSize 8

/* Register CAP_ID_NXT_PTR_REG field PM_SPEC_VER */
/* Power Management Spec Version.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: R */
#define CAP_ID_NXT_PTR_REG_PM_SPEC_VER_BitAddressOffset 16
#define CAP_ID_NXT_PTR_REG_PM_SPEC_VER_RegisterSize 3

/* Register CAP_ID_NXT_PTR_REG field PME_CLK */
/* PCI Clock Requirement.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define CAP_ID_NXT_PTR_REG_PME_CLK_BitAddressOffset 19
#define CAP_ID_NXT_PTR_REG_PME_CLK_RegisterSize 1

/* Register CAP_ID_NXT_PTR_REG field PME_IMM_READI_RETURN_DO */
/* Immediate Readiness on Return to D0.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: R */
#define CAP_ID_NXT_PTR_REG_PME_IMM_READI_RETURN_DO_BitAddressOffset 20
#define CAP_ID_NXT_PTR_REG_PME_IMM_READI_RETURN_DO_RegisterSize 1

/* Register CAP_ID_NXT_PTR_REG field DSI */
/* Device Specific Initialization Bit.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: R */
#define CAP_ID_NXT_PTR_REG_DSI_BitAddressOffset 21
#define CAP_ID_NXT_PTR_REG_DSI_RegisterSize 1

/* Register CAP_ID_NXT_PTR_REG field AUX_CURR */
/* Auxiliary Current Requirements.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: R */
#define CAP_ID_NXT_PTR_REG_AUX_CURR_BitAddressOffset 22
#define CAP_ID_NXT_PTR_REG_AUX_CURR_RegisterSize 3

/* Register CAP_ID_NXT_PTR_REG field D1_SUPPORT */
/* D1 State Support.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: R */
#define CAP_ID_NXT_PTR_REG_D1_SUPPORT_BitAddressOffset 25
#define CAP_ID_NXT_PTR_REG_D1_SUPPORT_RegisterSize 1

/* Register CAP_ID_NXT_PTR_REG field D2_SUPPORT */
/* D2 State Support.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: R */
#define CAP_ID_NXT_PTR_REG_D2_SUPPORT_BitAddressOffset 26
#define CAP_ID_NXT_PTR_REG_D2_SUPPORT_RegisterSize 1

/* Register CAP_ID_NXT_PTR_REG field PME_SUPPORT */
/* Power Management Event Support.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br>The read value from this field is the write value && {sys_aux_pwr_det, 1'b1, D2_SUPPORT, D1_SUPPORT, 1'b1}, where D1_SUPPORT and D2_SUPPORT are fields in this register.
<br>The reset value PME_SUPPORT_<i>n</i> && {sys_aux_pwr_det, 1'b1, D2_SUPPORT, D1_SUPPORT, 1'b1}, where PME_SUPPORT_<i>n</i> is a configuration parameter.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: R */
#define CAP_ID_NXT_PTR_REG_PME_SUPPORT_BitAddressOffset 27
#define CAP_ID_NXT_PTR_REG_PME_SUPPORT_RegisterSize 5

/* End of Register Definition for CAP_ID_NXT_PTR_REG */

/* Register CON_STATUS_REG */
/* Power Management Control and Status Register.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define CON_STATUS_REG (PF0_PM_CAP_BaseAddress + 0x4)
#define CON_STATUS_REG_RegisterSize 32
#define CON_STATUS_REG_RegisterResetValue 0x0
#define CON_STATUS_REG_RegisterResetMask 0xffffffff

/* Register Field information for CON_STATUS_REG */

/* Register CON_STATUS_REG field POWER_STATE */
/* Power State.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br>You can write to this register. However, the read-back value is the actual power state, not the write value.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R/W 
 - Dbi: R/W 
 - Dbi2: R */
#define CON_STATUS_REG_POWER_STATE_BitAddressOffset 0
#define CON_STATUS_REG_POWER_STATE_RegisterSize 2

/* Register CON_STATUS_REG field RSVDP_2 */
/* Reserved for future use. */
#define CON_STATUS_REG_RSVDP_2_BitAddressOffset 2
#define CON_STATUS_REG_RSVDP_2_RegisterSize 1

/* Register CON_STATUS_REG field NO_SOFT_RST */
/* No soft Reset.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: R */
#define CON_STATUS_REG_NO_SOFT_RST_BitAddressOffset 3
#define CON_STATUS_REG_NO_SOFT_RST_RegisterSize 1

/* Register CON_STATUS_REG field RSVDP_4 */
/* Reserved for future use. */
#define CON_STATUS_REG_RSVDP_4_BitAddressOffset 4
#define CON_STATUS_REG_RSVDP_4_RegisterSize 4

/* Register CON_STATUS_REG field PME_ENABLE */
/* PME Enable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br>The PMC registers this value under aux power. Sometimes it might remember the old value, even if you try to clear it by writing '0'.
<br><i>Note</i>: This register field is sticky. */
#define CON_STATUS_REG_PME_ENABLE_BitAddressOffset 8
#define CON_STATUS_REG_PME_ENABLE_RegisterSize 1

/* Register CON_STATUS_REG field DATA_SELECT */
/* Data Select.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define CON_STATUS_REG_DATA_SELECT_BitAddressOffset 9
#define CON_STATUS_REG_DATA_SELECT_RegisterSize 4

/* Register CON_STATUS_REG field DATA_SCALE */
/* Data Scaling Factor.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define CON_STATUS_REG_DATA_SCALE_BitAddressOffset 13
#define CON_STATUS_REG_DATA_SCALE_RegisterSize 2

/* Register CON_STATUS_REG field PME_STATUS */
/* PME Status.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define CON_STATUS_REG_PME_STATUS_BitAddressOffset 15
#define CON_STATUS_REG_PME_STATUS_RegisterSize 1

/* Register CON_STATUS_REG field RSVDP_16 */
/* Reserved for future use. */
#define CON_STATUS_REG_RSVDP_16_BitAddressOffset 16
#define CON_STATUS_REG_RSVDP_16_RegisterSize 6

/* Register CON_STATUS_REG field B2_B3_SUPPORT */
/* B2B3 Support for D3hot.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define CON_STATUS_REG_B2_B3_SUPPORT_BitAddressOffset 22
#define CON_STATUS_REG_B2_B3_SUPPORT_RegisterSize 1

/* Register CON_STATUS_REG field BUS_PWR_CLK_CON_EN */
/* Bus Power/Clock Control Enable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define CON_STATUS_REG_BUS_PWR_CLK_CON_EN_BitAddressOffset 23
#define CON_STATUS_REG_BUS_PWR_CLK_CON_EN_RegisterSize 1

/* Register CON_STATUS_REG field DATA_REG_ADD_INFO */
/* Power Data Information Register.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define CON_STATUS_REG_DATA_REG_ADD_INFO_BitAddressOffset 24
#define CON_STATUS_REG_DATA_REG_ADD_INFO_RegisterSize 8

/* End of Register Definition for CON_STATUS_REG */


/* Register PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG */
/* PCI Express Capabilities, ID, Next Pointer Register.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG (PF0_PCIE_CAP_BaseAddress + 0x0)
#define PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_RegisterSize 32
#define PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_RegisterResetValue 0x20010
#define PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_RegisterResetMask 0xffffffff

/* Register Field information for PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG */

/* Register PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG field PCIE_CAP_ID */
/* PCIE Capability ID.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_ID_BitAddressOffset 0
#define PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_ID_RegisterSize 8

/* Register PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG field PCIE_CAP_NEXT_PTR */
/* PCIE Next Capability Pointer.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: R */
#define PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_NEXT_PTR_BitAddressOffset 8
#define PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_NEXT_PTR_RegisterSize 8

/* Register PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG field PCIE_CAP_REG */
/* PCIE Capability Version Number.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_REG_BitAddressOffset 16
#define PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_REG_RegisterSize 4

/* Register PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG field PCIE_DEV_PORT_TYPE */
/* PCIE Device/PortType.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_DEV_PORT_TYPE_BitAddressOffset 20
#define PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_DEV_PORT_TYPE_RegisterSize 4

/* Register PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG field PCIE_SLOT_IMP */
/* PCIe Slot Implemented Valid.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: HWINIT 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: R */
#define PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_SLOT_IMP_BitAddressOffset 24
#define PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_SLOT_IMP_RegisterSize 1

/* Register PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG field PCIE_INT_MSG_NUM */
/* PCIE Interrupt Message Number.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: R */
#define PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_INT_MSG_NUM_BitAddressOffset 25
#define PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_INT_MSG_NUM_RegisterSize 5

/* Register PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG field RSVD */
/* Reserved.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_RSVD_BitAddressOffset 30
#define PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_RSVD_RegisterSize 1

/* Register PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG field RSVDP_31 */
/* Reserved for future use. */
#define PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_RSVDP_31_BitAddressOffset 31
#define PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_RSVDP_31_RegisterSize 1

/* End of Register Definition for PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG */

/* Register DEVICE_CAPABILITIES_REG */
/* Device Capabilities Register.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_CAPABILITIES_REG (PF0_PCIE_CAP_BaseAddress + 0x4)
#define DEVICE_CAPABILITIES_REG_RegisterSize 32
#define DEVICE_CAPABILITIES_REG_RegisterResetValue 0x8fc1
#define DEVICE_CAPABILITIES_REG_RegisterResetMask 0xffffffff

/* Register Field information for DEVICE_CAPABILITIES_REG */

/* Register DEVICE_CAPABILITIES_REG field PCIE_CAP_MAX_PAYLOAD_SIZE */
/* Max Payload Size Supported.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: R */
#define DEVICE_CAPABILITIES_REG_PCIE_CAP_MAX_PAYLOAD_SIZE_BitAddressOffset 0
#define DEVICE_CAPABILITIES_REG_PCIE_CAP_MAX_PAYLOAD_SIZE_RegisterSize 3

/* Register DEVICE_CAPABILITIES_REG field PCIE_CAP_PHANTOM_FUNC_SUPPORT */
/* Phantom Functions Supported.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: R */
#define DEVICE_CAPABILITIES_REG_PCIE_CAP_PHANTOM_FUNC_SUPPORT_BitAddressOffset 3
#define DEVICE_CAPABILITIES_REG_PCIE_CAP_PHANTOM_FUNC_SUPPORT_RegisterSize 2

/* Register DEVICE_CAPABILITIES_REG field PCIE_CAP_EXT_TAG_SUPP */
/* Extended Tag Field Supported.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: R */
#define DEVICE_CAPABILITIES_REG_PCIE_CAP_EXT_TAG_SUPP_BitAddressOffset 5
#define DEVICE_CAPABILITIES_REG_PCIE_CAP_EXT_TAG_SUPP_RegisterSize 1

/* Register DEVICE_CAPABILITIES_REG field PCIE_CAP_EP_L0S_ACCPT_LATENCY */
/* Applies to endpoints only L0s acceptable latency.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: R */
#define DEVICE_CAPABILITIES_REG_PCIE_CAP_EP_L0S_ACCPT_LATENCY_BitAddressOffset 6
#define DEVICE_CAPABILITIES_REG_PCIE_CAP_EP_L0S_ACCPT_LATENCY_RegisterSize 3

/* Register DEVICE_CAPABILITIES_REG field PCIE_CAP_EP_L1_ACCPT_LATENCY */
/* Applies to endpoints only L1 acceptable latency.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: R */
#define DEVICE_CAPABILITIES_REG_PCIE_CAP_EP_L1_ACCPT_LATENCY_BitAddressOffset 9
#define DEVICE_CAPABILITIES_REG_PCIE_CAP_EP_L1_ACCPT_LATENCY_RegisterSize 3

/* Register DEVICE_CAPABILITIES_REG field RSVDP_12 */
/* Reserved for future use. */
#define DEVICE_CAPABILITIES_REG_RSVDP_12_BitAddressOffset 12
#define DEVICE_CAPABILITIES_REG_RSVDP_12_RegisterSize 3

/* Register DEVICE_CAPABILITIES_REG field PCIE_CAP_ROLE_BASED_ERR_REPORT */
/* Role-based Error Reporting Implemented.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: R */
#define DEVICE_CAPABILITIES_REG_PCIE_CAP_ROLE_BASED_ERR_REPORT_BitAddressOffset 15
#define DEVICE_CAPABILITIES_REG_PCIE_CAP_ROLE_BASED_ERR_REPORT_RegisterSize 1

/* Register DEVICE_CAPABILITIES_REG field RSVDP_16 */
/* Reserved for future use. */
#define DEVICE_CAPABILITIES_REG_RSVDP_16_BitAddressOffset 16
#define DEVICE_CAPABILITIES_REG_RSVDP_16_RegisterSize 2

/* Register DEVICE_CAPABILITIES_REG field PCIE_CAP_CAP_SLOT_PWR_LMT_VALUE */
/* Captured Slot Power Limit Value.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_CAPABILITIES_REG_PCIE_CAP_CAP_SLOT_PWR_LMT_VALUE_BitAddressOffset 18
#define DEVICE_CAPABILITIES_REG_PCIE_CAP_CAP_SLOT_PWR_LMT_VALUE_RegisterSize 8

/* Register DEVICE_CAPABILITIES_REG field PCIE_CAP_CAP_SLOT_PWR_LMT_SCALE */
/* Captured Slot Power Limit Scale.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_CAPABILITIES_REG_PCIE_CAP_CAP_SLOT_PWR_LMT_SCALE_BitAddressOffset 26
#define DEVICE_CAPABILITIES_REG_PCIE_CAP_CAP_SLOT_PWR_LMT_SCALE_RegisterSize 2

/* Register DEVICE_CAPABILITIES_REG field PCIE_CAP_FLR_CAP */
/* Function Level Reset Capability (endpoints only).
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: R */
#define DEVICE_CAPABILITIES_REG_PCIE_CAP_FLR_CAP_BitAddressOffset 28
#define DEVICE_CAPABILITIES_REG_PCIE_CAP_FLR_CAP_RegisterSize 1

/* Register DEVICE_CAPABILITIES_REG field RSVDP_29 */
/* Reserved for future use. */
#define DEVICE_CAPABILITIES_REG_RSVDP_29_BitAddressOffset 29
#define DEVICE_CAPABILITIES_REG_RSVDP_29_RegisterSize 3

/* End of Register Definition for DEVICE_CAPABILITIES_REG */

/* Register DEVICE_CONTROL_DEVICE_STATUS */
/* Device Control and Status Register.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_CONTROL_DEVICE_STATUS (PF0_PCIE_CAP_BaseAddress + 0x8)
#define DEVICE_CONTROL_DEVICE_STATUS_RegisterSize 32
#define DEVICE_CONTROL_DEVICE_STATUS_RegisterResetValue 0x2010
#define DEVICE_CONTROL_DEVICE_STATUS_RegisterResetMask 0xffffffff

/* Register Field information for DEVICE_CONTROL_DEVICE_STATUS */

/* Register DEVICE_CONTROL_DEVICE_STATUS field PCIE_CAP_CORR_ERR_REPORT_EN */
/* Correctable Error Reporting Enable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_CORR_ERR_REPORT_EN_BitAddressOffset 0
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_CORR_ERR_REPORT_EN_RegisterSize 1

/* Register DEVICE_CONTROL_DEVICE_STATUS field PCIE_CAP_NON_FATAL_ERR_REPORT_EN */
/* Non-fatal Error Reporting Enable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_NON_FATAL_ERR_REPORT_EN_BitAddressOffset 1
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_NON_FATAL_ERR_REPORT_EN_RegisterSize 1

/* Register DEVICE_CONTROL_DEVICE_STATUS field PCIE_CAP_FATAL_ERR_REPORT_EN */
/* Fatal Error Reporting Enable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_FATAL_ERR_REPORT_EN_BitAddressOffset 2
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_FATAL_ERR_REPORT_EN_RegisterSize 1

/* Register DEVICE_CONTROL_DEVICE_STATUS field PCIE_CAP_UNSUPPORT_REQ_REP_EN */
/* Unsupported Request Reporting Enable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_UNSUPPORT_REQ_REP_EN_BitAddressOffset 3
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_UNSUPPORT_REQ_REP_EN_RegisterSize 1

/* Register DEVICE_CONTROL_DEVICE_STATUS field PCIE_CAP_EN_REL_ORDER */
/* Enable Relaxed Ordering.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_EN_REL_ORDER_BitAddressOffset 4
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_EN_REL_ORDER_RegisterSize 1

/* Register DEVICE_CONTROL_DEVICE_STATUS field PCIE_CAP_MAX_PAYLOAD_SIZE_CS */
/* Max Payload Size.
Max_Payload_Size . This field sets maximum TLP payload size for the Function. Permissible values that can be programmed are indicated by the Max_Payload_Size Supported field (PCIE_CAP_MAX_PAYLOAD_SIZE) in the Device Capabilities register (DEVICE_CAPABILITIES_REG). */
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_MAX_PAYLOAD_SIZE_CS_BitAddressOffset 5
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_MAX_PAYLOAD_SIZE_CS_RegisterSize 3

/* Register DEVICE_CONTROL_DEVICE_STATUS field PCIE_CAP_EXT_TAG_EN */
/* Extended Tag Field Enable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br>The write value is gated with the PCIE_CAP_EXT_TAG_SUPP field of DEVICE_CAPABILITIES_REG.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: DEVICE_CAPABILITIES_REG.PCIE_CAP_EXT_TAG_SUPP ? RW : RO  
 - Dbi: DEVICE_CAPABILITIES_REG.PCIE_CAP_EXT_TAG_SUPP ? RW : RO  
 - Dbi2: DEVICE_CAPABILITIES_REG.PCIE_CAP_EXT_TAG_SUPP ? RW : RO <ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && DEFAULT_EXT_TAG_FIELD_SUPPORTED_$pf) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && !DEFAULT_EXT_TAG_FIELD_SUPPORTED_$pf) ?  R: (CX_MEMORY_MAP_VIEW==1 &&  DEFAULT_EXT_TAG_FIELD_SUPPORTED_$pf) ?R/W:  (CX_MEMORY_MAP_VIEW==1 &&  !DEFAULT_EXT_TAG_FIELD_SUPPORTED_$pf) ? R: (DEFAULT_EXT_TAG_FIELD_SUPPORTED_$pf)? R/W:R</ct> */
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_EXT_TAG_EN_BitAddressOffset 8
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_EXT_TAG_EN_RegisterSize 1

/* Register DEVICE_CONTROL_DEVICE_STATUS field PCIE_CAP_PHANTOM_FUNC_EN */
/* Phantom Functions Enable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br>The write value is gated with the PCIE_CAP_PHANTOM_FUNC_SUPPORT field of DEVICE_CAPABILITIES_REG.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: DEVICE_CAPABILITIES_REG.PCIE_CAP_PHANTOM_FUNC_SUPPORT ? RW : RO  
 - Dbi: DEVICE_CAPABILITIES_REG.PCIE_CAP_PHANTOM_FUNC_SUPPORT ? RW : RO  
 - Dbi2: DEVICE_CAPABILITIES_REG.PCIE_CAP_PHANTOM_FUNC_SUPPORT ? RW : RO <ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && DEFAULT_PHANTOM_FUNC_SUPPORTED_$pf) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && !DEFAULT_PHANTOM_FUNC_SUPPORTED_$pf) ?  R: (CX_MEMORY_MAP_VIEW==1 && DEFAULT_PHANTOM_FUNC_SUPPORTED_$pf) ?R/W:  (CX_MEMORY_MAP_VIEW==1 &&  !DEFAULT_PHANTOM_FUNC_SUPPORTED_$pf) ? R: (DEFAULT_PHANTOM_FUNC_SUPPORTED_$pf)? R/W:R</ct> */
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_PHANTOM_FUNC_EN_BitAddressOffset 9
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_PHANTOM_FUNC_EN_RegisterSize 1

/* Register DEVICE_CONTROL_DEVICE_STATUS field PCIE_CAP_AUX_POWER_PM_EN */
/* Aux Power PM Enable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br>This bit is derived by sampling the sys_aux_pwr_det input.
<br><i>Note</i>: This register field is sticky. */
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_AUX_POWER_PM_EN_BitAddressOffset 10
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_AUX_POWER_PM_EN_RegisterSize 1

/* Register DEVICE_CONTROL_DEVICE_STATUS field PCIE_CAP_EN_NO_SNOOP */
/* Enable No Snoop.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: R 
 - Dbi2: R<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && DEFAULT_NO_SNOOP_SUPPORTED_$pf) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && !DEFAULT_NO_SNOOP_SUPPORTED_$pf) ?  R: (CX_MEMORY_MAP_VIEW==1 &&  DEFAULT_NO_SNOOP_SUPPORTED_$pf) ? R/W:  (CX_MEMORY_MAP_VIEW==1 &&  !DEFAULT_NO_SNOOP_SUPPORTED_$pf) ? R: (DEFAULT_NO_SNOOP_SUPPORTED_$pf)? R/W:R</ct> */
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_EN_NO_SNOOP_BitAddressOffset 11
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_EN_NO_SNOOP_RegisterSize 1

/* Register DEVICE_CONTROL_DEVICE_STATUS field PCIE_CAP_MAX_READ_REQ_SIZE */
/* Max Read Request Size.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_MAX_READ_REQ_SIZE_BitAddressOffset 12
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_MAX_READ_REQ_SIZE_RegisterSize 3

/* Register DEVICE_CONTROL_DEVICE_STATUS field PCIE_CAP_INITIATE_FLR */
/* Initiate Function Level Reset (for endpoints).
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_INITIATE_FLR_BitAddressOffset 15
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_INITIATE_FLR_RegisterSize 1

/* Register DEVICE_CONTROL_DEVICE_STATUS field PCIE_CAP_CORR_ERR_DETECTED */
/* Correctable Error Detected Status.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_CORR_ERR_DETECTED_BitAddressOffset 16
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_CORR_ERR_DETECTED_RegisterSize 1

/* Register DEVICE_CONTROL_DEVICE_STATUS field PCIE_CAP_NON_FATAL_ERR_DETECTED */
/* Non-Fatal Error Detected Status.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_NON_FATAL_ERR_DETECTED_BitAddressOffset 17
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_NON_FATAL_ERR_DETECTED_RegisterSize 1

/* Register DEVICE_CONTROL_DEVICE_STATUS field PCIE_CAP_FATAL_ERR_DETECTED */
/* Fatal Error Detected Status.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_FATAL_ERR_DETECTED_BitAddressOffset 18
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_FATAL_ERR_DETECTED_RegisterSize 1

/* Register DEVICE_CONTROL_DEVICE_STATUS field PCIE_CAP_UNSUPPORTED_REQ_DETECTED */
/* Unsupported Request Detected Status.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_UNSUPPORTED_REQ_DETECTED_BitAddressOffset 19
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_UNSUPPORTED_REQ_DETECTED_RegisterSize 1

/* Register DEVICE_CONTROL_DEVICE_STATUS field PCIE_CAP_AUX_POWER_DETECTED */
/* Aux Power Detected Status.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br>This bit is derived by sampling the sys_aux_pwr_det input. */
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_AUX_POWER_DETECTED_BitAddressOffset 20
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_AUX_POWER_DETECTED_RegisterSize 1

/* Register DEVICE_CONTROL_DEVICE_STATUS field PCIE_CAP_TRANS_PENDING */
/* Transactions Pending Status.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_TRANS_PENDING_BitAddressOffset 21
#define DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_TRANS_PENDING_RegisterSize 1

/* Register DEVICE_CONTROL_DEVICE_STATUS field RSVDP_22 */
/* Reserved for future use. */
#define DEVICE_CONTROL_DEVICE_STATUS_RSVDP_22_BitAddressOffset 22
#define DEVICE_CONTROL_DEVICE_STATUS_RSVDP_22_RegisterSize 10

/* End of Register Definition for DEVICE_CONTROL_DEVICE_STATUS */

/* Register LINK_CAPABILITIES_REG */
/* Link Capabilities Register.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define LINK_CAPABILITIES_REG (PF0_PCIE_CAP_BaseAddress + 0xc)
#define LINK_CAPABILITIES_REG_RegisterSize 32
#define LINK_CAPABILITIES_REG_RegisterResetValue 0x433c12
#define LINK_CAPABILITIES_REG_RegisterResetMask 0xffffffff

/* Register Field information for LINK_CAPABILITIES_REG */

/* Register LINK_CAPABILITIES_REG field PCIE_CAP_MAX_LINK_SPEED */
/* Maximum Link Speed.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br>In M-PCIe mode, the reset and dynamic values of this field are calculated by the core.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: R */
#define LINK_CAPABILITIES_REG_PCIE_CAP_MAX_LINK_SPEED_BitAddressOffset 0
#define LINK_CAPABILITIES_REG_PCIE_CAP_MAX_LINK_SPEED_RegisterSize 4

/* Register LINK_CAPABILITIES_REG field PCIE_CAP_MAX_LINK_WIDTH */
/* Maximum Link Width.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br>In M-PCIe mode, the reset and dynamic values of this field are calculated by the core.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: R */
#define LINK_CAPABILITIES_REG_PCIE_CAP_MAX_LINK_WIDTH_BitAddressOffset 4
#define LINK_CAPABILITIES_REG_PCIE_CAP_MAX_LINK_WIDTH_RegisterSize 6

/* Register LINK_CAPABILITIES_REG field PCIE_CAP_ACTIVE_STATE_LINK_PM_SUPPORT */
/* Level of ASPM (Active State Power Management) Support.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: R */
#define LINK_CAPABILITIES_REG_PCIE_CAP_ACTIVE_STATE_LINK_PM_SUPPORT_BitAddressOffset 10
#define LINK_CAPABILITIES_REG_PCIE_CAP_ACTIVE_STATE_LINK_PM_SUPPORT_RegisterSize 2

/* Register LINK_CAPABILITIES_REG field PCIE_CAP_L0S_EXIT_LATENCY */
/* LOs Exit Latency.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
There are two each of these register fields, this one and a shadow one at the same address.
The Common Clock bit (PCIE_CAP_COMMON_CLK_CONFIG) of the Link Control Register (LINK_CONTROL_LINK_STATUS_REG) determines which one is used by the core and which one is accessed by a read request.
Common Clock operation is supported (possible) in the core when one or more of the following expressions is true:
 - CX_NFTS !=CX_COMM_NFTS
 - DEFAULT_L0S_EXIT_LATENCY !=DEFAULT_COMM_L0S_EXIT_LATENCY
 - DEFAULT_L1_EXIT_LATENCY !=DEFAULT_COMM_L1_EXIT_LATENCY
Common Clock operation is enabled in the core when you set the Common Clock bit (PCIE_CAP_COMMON_CLK_CONFIG) of the Link Control Register (LINK_CONTROL_LINK_STATUS_REG).
The assertion of CS2 (that is, assert the dbi_cs2 input, or the CS2 address bit for the AHB/AXI bridge) is required to write to the shadow field at this location.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: if (DBI_RO_WR_EN == 1) then R/W else R */
#define LINK_CAPABILITIES_REG_PCIE_CAP_L0S_EXIT_LATENCY_BitAddressOffset 12
#define LINK_CAPABILITIES_REG_PCIE_CAP_L0S_EXIT_LATENCY_RegisterSize 3

/* Register LINK_CAPABILITIES_REG field PCIE_CAP_L1_EXIT_LATENCY */
/* L1 Exit Latency.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
There are two each of these register fields, this one and a shadow one at the same address.
The Common Clock bit (PCIE_CAP_COMMON_CLK_CONFIG) of the Link Control Register (LINK_CONTROL_LINK_STATUS_REG) determines which one is used by the core and which one is accessed by a read request.
Common Clock operation is supported (possible) in the core when one or more of the following expressions is true:
 - CX_NFTS !=CX_COMM_NFTS
 - DEFAULT_L0S_EXIT_LATENCY !=DEFAULT_COMM_L0S_EXIT_LATENCY
 - DEFAULT_L1_EXIT_LATENCY !=DEFAULT_COMM_L1_EXIT_LATENCY
Common Clock operation is enabled in the core when you set the Common Clock bit (PCIE_CAP_COMMON_CLK_CONFIG) of the Link Control Register (LINK_CONTROL_LINK_STATUS_REG).
The assertion of CS2 (that is, assert the dbi_cs2 input, or the CS2 address bit for the AHB/AXI bridge) is required to write to the shadow field at this location.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: if (DBI_RO_WR_EN == 1) then R/W else R */
#define LINK_CAPABILITIES_REG_PCIE_CAP_L1_EXIT_LATENCY_BitAddressOffset 15
#define LINK_CAPABILITIES_REG_PCIE_CAP_L1_EXIT_LATENCY_RegisterSize 3

/* Register LINK_CAPABILITIES_REG field PCIE_CAP_CLOCK_POWER_MAN */
/* Clock Power Management.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: R */
#define LINK_CAPABILITIES_REG_PCIE_CAP_CLOCK_POWER_MAN_BitAddressOffset 18
#define LINK_CAPABILITIES_REG_PCIE_CAP_CLOCK_POWER_MAN_RegisterSize 1

/* Register LINK_CAPABILITIES_REG field PCIE_CAP_SURPRISE_DOWN_ERR_REP_CAP */
/* Surprise Down Error Reporting Capable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define LINK_CAPABILITIES_REG_PCIE_CAP_SURPRISE_DOWN_ERR_REP_CAP_BitAddressOffset 19
#define LINK_CAPABILITIES_REG_PCIE_CAP_SURPRISE_DOWN_ERR_REP_CAP_RegisterSize 1

/* Register LINK_CAPABILITIES_REG field PCIE_CAP_DLL_ACTIVE_REP_CAP */
/* Data Link Layer Link Active Reporting Capable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define LINK_CAPABILITIES_REG_PCIE_CAP_DLL_ACTIVE_REP_CAP_BitAddressOffset 20
#define LINK_CAPABILITIES_REG_PCIE_CAP_DLL_ACTIVE_REP_CAP_RegisterSize 1

/* Register LINK_CAPABILITIES_REG field PCIE_CAP_LINK_BW_NOT_CAP */
/* Link Bandwidth Notification Capable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define LINK_CAPABILITIES_REG_PCIE_CAP_LINK_BW_NOT_CAP_BitAddressOffset 21
#define LINK_CAPABILITIES_REG_PCIE_CAP_LINK_BW_NOT_CAP_RegisterSize 1

/* Register LINK_CAPABILITIES_REG field PCIE_CAP_ASPM_OPT_COMPLIANCE */
/* ASPM Optionality Compliance.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: HWINIT 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: HWINIT */
#define LINK_CAPABILITIES_REG_PCIE_CAP_ASPM_OPT_COMPLIANCE_BitAddressOffset 22
#define LINK_CAPABILITIES_REG_PCIE_CAP_ASPM_OPT_COMPLIANCE_RegisterSize 1

/* Register LINK_CAPABILITIES_REG field RSVDP_23 */
/* Reserved for future use. */
#define LINK_CAPABILITIES_REG_RSVDP_23_BitAddressOffset 23
#define LINK_CAPABILITIES_REG_RSVDP_23_RegisterSize 1

/* Register LINK_CAPABILITIES_REG field PCIE_CAP_PORT_NUM */
/* Port Number.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: HWINIT 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: HWINIT */
#define LINK_CAPABILITIES_REG_PCIE_CAP_PORT_NUM_BitAddressOffset 24
#define LINK_CAPABILITIES_REG_PCIE_CAP_PORT_NUM_RegisterSize 8

/* End of Register Definition for LINK_CAPABILITIES_REG */

/* Register LINK_CONTROL_LINK_STATUS_REG */
/* Link Control and Status Register.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define LINK_CONTROL_LINK_STATUS_REG (PF0_PCIE_CAP_BaseAddress + 0x10)
#define LINK_CONTROL_LINK_STATUS_REG_RegisterSize 32
#define LINK_CONTROL_LINK_STATUS_REG_RegisterResetValue 0x10110000
#define LINK_CONTROL_LINK_STATUS_REG_RegisterResetMask 0xffffffff

/* Register Field information for LINK_CONTROL_LINK_STATUS_REG */

/* Register LINK_CONTROL_LINK_STATUS_REG field PCIE_CAP_ACTIVE_STATE_LINK_PM_CONTROL */
/* Active State Power Management (ASPM) Control.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_ACTIVE_STATE_LINK_PM_CONTROL_BitAddressOffset 0
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_ACTIVE_STATE_LINK_PM_CONTROL_RegisterSize 2

/* Register LINK_CONTROL_LINK_STATUS_REG field RSVDP_2 */
/* Reserved for future use. */
#define LINK_CONTROL_LINK_STATUS_REG_RSVDP_2_BitAddressOffset 2
#define LINK_CONTROL_LINK_STATUS_REG_RSVDP_2_RegisterSize 1

/* Register LINK_CONTROL_LINK_STATUS_REG field PCIE_CAP_RCB */
/* Read Completion Boundary (RCB).
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R/W 
 - Dbi: R/W 
 - Dbi2: R/W<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && CX_RCB_SUPPORT) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && !CX_RCB_SUPPORT) ?  R: (CX_MEMORY_MAP_VIEW==1 && CX_RCB_SUPPORT ) ? R/W: (CX_MEMORY_MAP_VIEW==1 && !CX_RCB_SUPPORT ) ? R : (CX_RCB_SUPPORT) ? R/W : R</ct> */
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_RCB_BitAddressOffset 3
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_RCB_RegisterSize 1

/* Register LINK_CONTROL_LINK_STATUS_REG field PCIE_CAP_LINK_DISABLE */
/* Initiate Link Disable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br>In a DSP that supports crosslink, the core gates the write value with the CROSS_LINK_EN field in PORT_LINK_CTRL_OFF.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: CX_CROSSLINK_ENABLE=1 && PORT_LINK_CTRL_OFF.CROSS_LINK_EN=1||CX_CROSSLINK_ENABLE=0 && dsp=1 ? RW : RO 
 - Dbi: CX_CROSSLINK_ENABLE=1 && PORT_LINK_CTRL_OFF.CROSS_LINK_EN=1||CX_CROSSLINK_ENABLE=0 && dsp=1? RW : RO 
 - Dbi2: CX_CROSSLINK_ENABLE=1 && PORT_LINK_CTRL_OFF.CROSS_LINK_EN=1||CX_CROSSLINK_ENABLE=0 && dsp=1? RW : RO */
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_DISABLE_BitAddressOffset 4
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_DISABLE_RegisterSize 1

/* Register LINK_CONTROL_LINK_STATUS_REG field PCIE_CAP_RETRAIN_LINK */
/* Initiate Link Retrain.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: see description 
 - Dbi: see description 
 - Dbi2: see description */
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_RETRAIN_LINK_BitAddressOffset 5
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_RETRAIN_LINK_RegisterSize 1

/* Register LINK_CONTROL_LINK_STATUS_REG field PCIE_CAP_COMMON_CLK_CONFIG */
/* Common Clock Configuration.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_COMMON_CLK_CONFIG_BitAddressOffset 6
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_COMMON_CLK_CONFIG_RegisterSize 1

/* Register LINK_CONTROL_LINK_STATUS_REG field PCIE_CAP_EXTENDED_SYNCH */
/* Extended Synch.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_EXTENDED_SYNCH_BitAddressOffset 7
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_EXTENDED_SYNCH_RegisterSize 1

/* Register LINK_CONTROL_LINK_STATUS_REG field PCIE_CAP_EN_CLK_POWER_MAN */
/* Enable Clock Power Management.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br>The write value is gated with the PCIE_CAP_CLOCK_POWER_MAN field in LINK_CAPABILITIES_REG.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: LINK_CAPABILITIES_REG.PCIE_CAP_CLOCK_POWER_MAN ? RW : RO 
 - Dbi: LINK_CAPABILITIES_REG.PCIE_CAP_CLOCK_POWER_MAN ? RW : RO 
 - Dbi2: LINK_CAPABILITIES_REG.PCIE_CAP_CLOCK_POWER_MAN ? RW : RO */
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_EN_CLK_POWER_MAN_BitAddressOffset 8
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_EN_CLK_POWER_MAN_RegisterSize 1

/* Register LINK_CONTROL_LINK_STATUS_REG field PCIE_CAP_HW_AUTO_WIDTH_DISABLE */
/* Hardware Autonomous Width Disable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_HW_AUTO_WIDTH_DISABLE_BitAddressOffset 9
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_HW_AUTO_WIDTH_DISABLE_RegisterSize 1

/* Register LINK_CONTROL_LINK_STATUS_REG field PCIE_CAP_LINK_BW_MAN_INT_EN */
/* Hardware Autonomous Width Disable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br>The write value is gated with the PCIE_CAP_LINK_BW_NOT_CAP field in LINK_CAPABILITIES_REG.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: LINK_CAPABILITIES_REG.PCIE_CAP_LINK_BW_NOT_CAP ? RW : RO  
 - Dbi: LINK_CAPABILITIES_REG.PCIE_CAP_LINK_BW_NOT_CAP ? RW : RO  
 - Dbi2: LINK_CAPABILITIES_REG.PCIE_CAP_LINK_BW_NOT_CAP ? RW : RO */
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_BW_MAN_INT_EN_BitAddressOffset 10
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_BW_MAN_INT_EN_RegisterSize 1

/* Register LINK_CONTROL_LINK_STATUS_REG field PCIE_CAP_LINK_AUTO_BW_INT_EN */
/* Link Bandwidth Management Interrupt Enable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br>The write value is gated with the PCIE_CAP_LINK_BW_NOT_CAP field in LINK_CAPABILITIES_REG.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: LINK_CAPABILITIES_REG.PCIE_CAP_LINK_BW_NOT_CAP ? RW : RO 
 - Dbi: LINK_CAPABILITIES_REG.PCIE_CAP_LINK_BW_NOT_CAP ? RW : RO 
 - Dbi2: LINK_CAPABILITIES_REG.PCIE_CAP_LINK_BW_NOT_CAP ? RW : RO */
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_AUTO_BW_INT_EN_BitAddressOffset 11
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_AUTO_BW_INT_EN_RegisterSize 1

/* Register LINK_CONTROL_LINK_STATUS_REG field RSVDP_12 */
/* Reserved for future use. */
#define LINK_CONTROL_LINK_STATUS_REG_RSVDP_12_BitAddressOffset 12
#define LINK_CONTROL_LINK_STATUS_REG_RSVDP_12_RegisterSize 2

/* Register LINK_CONTROL_LINK_STATUS_REG field PCIE_CAP_DRS_SIGNALING_CONTROL */
/* DRS Signaling Control.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_DRS_SIGNALING_CONTROL_BitAddressOffset 14
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_DRS_SIGNALING_CONTROL_RegisterSize 2

/* Register LINK_CONTROL_LINK_STATUS_REG field PCIE_CAP_LINK_SPEED */
/* Current Link Speed.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_SPEED_BitAddressOffset 16
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_SPEED_RegisterSize 4

/* Register LINK_CONTROL_LINK_STATUS_REG field PCIE_CAP_NEGO_LINK_WIDTH */
/* Negotiated Link Width.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_NEGO_LINK_WIDTH_BitAddressOffset 20
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_NEGO_LINK_WIDTH_RegisterSize 6

/* Register LINK_CONTROL_LINK_STATUS_REG field RSVDP_26 */
/* Reserved for future use. */
#define LINK_CONTROL_LINK_STATUS_REG_RSVDP_26_BitAddressOffset 26
#define LINK_CONTROL_LINK_STATUS_REG_RSVDP_26_RegisterSize 1

/* Register LINK_CONTROL_LINK_STATUS_REG field PCIE_CAP_LINK_TRAINING */
/* LTSSM is in Configuration or Recovery State.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: RSVDP 
 - Dbi: R 
 - Dbi2: R */
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_TRAINING_BitAddressOffset 27
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_TRAINING_RegisterSize 1

/* Register LINK_CONTROL_LINK_STATUS_REG field PCIE_CAP_SLOT_CLK_CONFIG */
/* Slot Clock Configuration.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: HWINIT 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: HWINIT */
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_SLOT_CLK_CONFIG_BitAddressOffset 28
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_SLOT_CLK_CONFIG_RegisterSize 1

/* Register LINK_CONTROL_LINK_STATUS_REG field PCIE_CAP_DLL_ACTIVE */
/* Data Link Layer Active.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_DLL_ACTIVE_BitAddressOffset 29
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_DLL_ACTIVE_RegisterSize 1

/* Register LINK_CONTROL_LINK_STATUS_REG field PCIE_CAP_LINK_BW_MAN_STATUS */
/* Link Bandwidth Management Status.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br>The write value is gated with the PCIE_CAP_LINK_BW_NOT_CAP field in LINK_CAPABILITIES_REG.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: LINK_CAPABILITIES_REG.PCIE_CAP_LINK_BW_NOT_CAP ? RW1C : RO 
 - Dbi: LINK_CAPABILITIES_REG.PCIE_CAP_LINK_BW_NOT_CAP ? RW1C : RO 
 - Dbi2: LINK_CAPABILITIES_REG.PCIE_CAP_LINK_BW_NOT_CAP ? RW1C : RO */
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_BW_MAN_STATUS_BitAddressOffset 30
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_BW_MAN_STATUS_RegisterSize 1

/* Register LINK_CONTROL_LINK_STATUS_REG field PCIE_CAP_LINK_AUTO_BW_STATUS */
/* Link Autonomous Bandwidth Status.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br>The write value is gated with the PCIE_CAP_LINK_BW_NOT_CAP field in LINK_CAPABILITIES_REG.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: LINK_CAPABILITIES_REG.PCIE_CAP_LINK_BW_NOT_CAP ? RW1C : RO 
 - Dbi: LINK_CAPABILITIES_REG.PCIE_CAP_LINK_BW_NOT_CAP ? RW1C : RO 
 - Dbi2: LINK_CAPABILITIES_REG.PCIE_CAP_LINK_BW_NOT_CAP ? RW1C : RO */
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_AUTO_BW_STATUS_BitAddressOffset 31
#define LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_AUTO_BW_STATUS_RegisterSize 1

/* End of Register Definition for LINK_CONTROL_LINK_STATUS_REG */

/* Register DEVICE_CAPABILITIES2_REG */
/* Device Capabilities 2 Register.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_CAPABILITIES2_REG (PF0_PCIE_CAP_BaseAddress + 0x24)
#define DEVICE_CAPABILITIES2_REG_RegisterSize 32
#define DEVICE_CAPABILITIES2_REG_RegisterResetValue 0x10
#define DEVICE_CAPABILITIES2_REG_RegisterResetMask 0xffffffff

/* Register Field information for DEVICE_CAPABILITIES2_REG */

/* Register DEVICE_CAPABILITIES2_REG field PCIE_CAP_CPL_TIMEOUT_RANGE */
/* Completion Timeout Ranges Supported.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_CAPABILITIES2_REG_PCIE_CAP_CPL_TIMEOUT_RANGE_BitAddressOffset 0
#define DEVICE_CAPABILITIES2_REG_PCIE_CAP_CPL_TIMEOUT_RANGE_RegisterSize 4

/* Register DEVICE_CAPABILITIES2_REG field PCIE_CAP_CPL_TIMEOUT_DISABLE_SUPPORT */
/* Completion Timeout Disable Supported.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_CAPABILITIES2_REG_PCIE_CAP_CPL_TIMEOUT_DISABLE_SUPPORT_BitAddressOffset 4
#define DEVICE_CAPABILITIES2_REG_PCIE_CAP_CPL_TIMEOUT_DISABLE_SUPPORT_RegisterSize 1

/* Register DEVICE_CAPABILITIES2_REG field PCIE_CAP_ARI_FORWARD_SUPPORT */
/* ARI Forwarding Supported.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_CAPABILITIES2_REG_PCIE_CAP_ARI_FORWARD_SUPPORT_BitAddressOffset 5
#define DEVICE_CAPABILITIES2_REG_PCIE_CAP_ARI_FORWARD_SUPPORT_RegisterSize 1

/* Register DEVICE_CAPABILITIES2_REG field PCIE_CAP_ATOMIC_ROUTING_SUPP */
/* Atomic Operation Routing Supported.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_CAPABILITIES2_REG_PCIE_CAP_ATOMIC_ROUTING_SUPP_BitAddressOffset 6
#define DEVICE_CAPABILITIES2_REG_PCIE_CAP_ATOMIC_ROUTING_SUPP_RegisterSize 1

/* Register DEVICE_CAPABILITIES2_REG field PCIE_CAP_32_ATOMIC_CPL_SUPP */
/* 32 Bit AtomicOp Completer Supported.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_CAPABILITIES2_REG_PCIE_CAP_32_ATOMIC_CPL_SUPP_BitAddressOffset 7
#define DEVICE_CAPABILITIES2_REG_PCIE_CAP_32_ATOMIC_CPL_SUPP_RegisterSize 1

/* Register DEVICE_CAPABILITIES2_REG field PCIE_CAP_64_ATOMIC_CPL_SUPP */
/* 64 Bit AtomicOp Completer Supported.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_CAPABILITIES2_REG_PCIE_CAP_64_ATOMIC_CPL_SUPP_BitAddressOffset 8
#define DEVICE_CAPABILITIES2_REG_PCIE_CAP_64_ATOMIC_CPL_SUPP_RegisterSize 1

/* Register DEVICE_CAPABILITIES2_REG field PCIE_CAP_128_CAS_CPL_SUPP */
/* 128 Bit CAS Completer Supported.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_CAPABILITIES2_REG_PCIE_CAP_128_CAS_CPL_SUPP_BitAddressOffset 9
#define DEVICE_CAPABILITIES2_REG_PCIE_CAP_128_CAS_CPL_SUPP_RegisterSize 1

/* Register DEVICE_CAPABILITIES2_REG field PCIE_CAP_NO_RO_EN_PR2PR_PAR */
/* No Relaxed Ordering Enabled PR-PR Passing.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_CAPABILITIES2_REG_PCIE_CAP_NO_RO_EN_PR2PR_PAR_BitAddressOffset 10
#define DEVICE_CAPABILITIES2_REG_PCIE_CAP_NO_RO_EN_PR2PR_PAR_RegisterSize 1

/* Register DEVICE_CAPABILITIES2_REG field PCIE_CAP_LTR_SUPP */
/* LTR Mechanism Supported.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_CAPABILITIES2_REG_PCIE_CAP_LTR_SUPP_BitAddressOffset 11
#define DEVICE_CAPABILITIES2_REG_PCIE_CAP_LTR_SUPP_RegisterSize 1

/* Register DEVICE_CAPABILITIES2_REG field PCIE_CAP_TPH_CMPLT_SUPPORT_0 */
/* TPH Completer Supported Bit 0.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_CAPABILITIES2_REG_PCIE_CAP_TPH_CMPLT_SUPPORT_0_BitAddressOffset 12
#define DEVICE_CAPABILITIES2_REG_PCIE_CAP_TPH_CMPLT_SUPPORT_0_RegisterSize 1

/* Register DEVICE_CAPABILITIES2_REG field PCIE_CAP_TPH_CMPLT_SUPPORT_1 */
/* TPH Completer Supported Bit 1.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_CAPABILITIES2_REG_PCIE_CAP_TPH_CMPLT_SUPPORT_1_BitAddressOffset 13
#define DEVICE_CAPABILITIES2_REG_PCIE_CAP_TPH_CMPLT_SUPPORT_1_RegisterSize 1

/* Register DEVICE_CAPABILITIES2_REG field RSVDP_14 */
/* Reserved for future use. */
#define DEVICE_CAPABILITIES2_REG_RSVDP_14_BitAddressOffset 14
#define DEVICE_CAPABILITIES2_REG_RSVDP_14_RegisterSize 4

/* Register DEVICE_CAPABILITIES2_REG field PCIE_CAP_OBFF_SUPPORT */
/* (OBFF) Optimized Buffer Flush/fill Supported.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_CAPABILITIES2_REG_PCIE_CAP_OBFF_SUPPORT_BitAddressOffset 18
#define DEVICE_CAPABILITIES2_REG_PCIE_CAP_OBFF_SUPPORT_RegisterSize 2

/* Register DEVICE_CAPABILITIES2_REG field RSVDP_24 */
/* Reserved for future use. */
#define DEVICE_CAPABILITIES2_REG_RSVDP_24_BitAddressOffset 24
#define DEVICE_CAPABILITIES2_REG_RSVDP_24_RegisterSize 7

/* End of Register Definition for DEVICE_CAPABILITIES2_REG */

/* Register DEVICE_CONTROL2_DEVICE_STATUS2_REG */
/* Device Control 2 and Status 2 Register.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_CONTROL2_DEVICE_STATUS2_REG (PF0_PCIE_CAP_BaseAddress + 0x28)
#define DEVICE_CONTROL2_DEVICE_STATUS2_REG_RegisterSize 32
#define DEVICE_CONTROL2_DEVICE_STATUS2_REG_RegisterResetValue 0x0
#define DEVICE_CONTROL2_DEVICE_STATUS2_REG_RegisterResetMask 0xffffffff

/* Register Field information for DEVICE_CONTROL2_DEVICE_STATUS2_REG */

/* Register DEVICE_CONTROL2_DEVICE_STATUS2_REG field PCIE_CAP_CPL_TIMEOUT_VALUE */
/* Completion Timeout Value.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R/W 
 - Dbi: R/W 
 - Dbi2: R/W<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && CX_CPL_TO_RANGES_ENABLE) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && !CX_CPL_TO_RANGES_ENABLE) ?  R: (CX_MEMORY_MAP_VIEW==1 &&  CX_CPL_TO_RANGES_ENABLE) ? R/W:  (CX_MEMORY_MAP_VIEW==1 &&  !CX_CPL_TO_RANGES_ENABLE) ? R: (CX_CPL_TO_RANGES_ENABLE)? R/W:R</ct> */
#define DEVICE_CONTROL2_DEVICE_STATUS2_REG_PCIE_CAP_CPL_TIMEOUT_VALUE_BitAddressOffset 0
#define DEVICE_CONTROL2_DEVICE_STATUS2_REG_PCIE_CAP_CPL_TIMEOUT_VALUE_RegisterSize 4

/* Register DEVICE_CONTROL2_DEVICE_STATUS2_REG field PCIE_CAP_CPL_TIMEOUT_DISABLE */
/* Completion Timeout Disable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_CONTROL2_DEVICE_STATUS2_REG_PCIE_CAP_CPL_TIMEOUT_DISABLE_BitAddressOffset 4
#define DEVICE_CONTROL2_DEVICE_STATUS2_REG_PCIE_CAP_CPL_TIMEOUT_DISABLE_RegisterSize 1

/* Register DEVICE_CONTROL2_DEVICE_STATUS2_REG field PCIE_CAP_ARI_FORWARD_SUPPORT_CS */
/* ARI Forwarding Enable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define DEVICE_CONTROL2_DEVICE_STATUS2_REG_PCIE_CAP_ARI_FORWARD_SUPPORT_CS_BitAddressOffset 5
#define DEVICE_CONTROL2_DEVICE_STATUS2_REG_PCIE_CAP_ARI_FORWARD_SUPPORT_CS_RegisterSize 1

/* End of Register Definition for DEVICE_CONTROL2_DEVICE_STATUS2_REG */

/* Register LINK_CAPABILITIES2_REG */
/* Link Capabilities 2 Register.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define LINK_CAPABILITIES2_REG (PF0_PCIE_CAP_BaseAddress + 0x2c)
#define LINK_CAPABILITIES2_REG_RegisterSize 32
#define LINK_CAPABILITIES2_REG_RegisterResetValue 0x4
#define LINK_CAPABILITIES2_REG_RegisterResetMask 0xffffffff

/* Register Field information for LINK_CAPABILITIES2_REG */

/* Register LINK_CAPABILITIES2_REG field RSVDP_0 */
/* Reserved for future use. */
#define LINK_CAPABILITIES2_REG_RSVDP_0_BitAddressOffset 0
#define LINK_CAPABILITIES2_REG_RSVDP_0_RegisterSize 1

/* Register LINK_CAPABILITIES2_REG field PCIE_CAP_SUPPORT_LINK_SPEED_VECTOR */
/* Supported Link Speeds Vector.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br>This field has a default of (PCIE_CAP_MAX_LINK_SPEED == 0100) ? 0001111 : (PCIE_CAP_MAX_LINK_SPEED == 0011) ? 0000111 : (PCIE_CAP_MAX_LINK_SPEED == 0010) ? 0000011 : 0000001 where PCIE_CAP_MAX_LINK_SPEED is a field in the LINK_CAPABILITIES_REG register. */
#define LINK_CAPABILITIES2_REG_PCIE_CAP_SUPPORT_LINK_SPEED_VECTOR_BitAddressOffset 1
#define LINK_CAPABILITIES2_REG_PCIE_CAP_SUPPORT_LINK_SPEED_VECTOR_RegisterSize 7

/* Register LINK_CAPABILITIES2_REG field PCIE_CAP_CROSS_LINK_SUPPORT */
/* Cross Link Supported.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define LINK_CAPABILITIES2_REG_PCIE_CAP_CROSS_LINK_SUPPORT_BitAddressOffset 8
#define LINK_CAPABILITIES2_REG_PCIE_CAP_CROSS_LINK_SUPPORT_RegisterSize 1

/* Register LINK_CAPABILITIES2_REG field RSVDP_9 */
/* Reserved for future use. */
#define LINK_CAPABILITIES2_REG_RSVDP_9_BitAddressOffset 9
#define LINK_CAPABILITIES2_REG_RSVDP_9_RegisterSize 22

/* Register LINK_CAPABILITIES2_REG field DRS_SUPPORTED */
/* DRS Supported.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: HWINIT 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: R */
#define LINK_CAPABILITIES2_REG_DRS_SUPPORTED_BitAddressOffset 31
#define LINK_CAPABILITIES2_REG_DRS_SUPPORTED_RegisterSize 1

/* End of Register Definition for LINK_CAPABILITIES2_REG */

/* Register LINK_CONTROL2_LINK_STATUS2_REG */
/* Link Control 2 and Status 2 Register.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define LINK_CONTROL2_LINK_STATUS2_REG (PF0_PCIE_CAP_BaseAddress + 0x30)
#define LINK_CONTROL2_LINK_STATUS2_REG_RegisterSize 32
#define LINK_CONTROL2_LINK_STATUS2_REG_RegisterResetValue 0x10002
#define LINK_CONTROL2_LINK_STATUS2_REG_RegisterResetMask 0xffffffff

/* Register Field information for LINK_CONTROL2_LINK_STATUS2_REG */

/* Register LINK_CONTROL2_LINK_STATUS2_REG field PCIE_CAP_TARGET_LINK_SPEED */
/* Target Link Speed.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br> In M-PCIe mode, the contents of this field are derived from other registers.
<br><i>Note</i>: This register field is sticky. */
#define LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_TARGET_LINK_SPEED_BitAddressOffset 0
#define LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_TARGET_LINK_SPEED_RegisterSize 4

/* Register LINK_CONTROL2_LINK_STATUS2_REG field PCIE_CAP_ENTER_COMPLIANCE */
/* Enter Compliance Mode.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_ENTER_COMPLIANCE_BitAddressOffset 4
#define LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_ENTER_COMPLIANCE_RegisterSize 1

/* Register LINK_CONTROL2_LINK_STATUS2_REG field PCIE_CAP_HW_AUTO_SPEED_DISABLE */
/* Hardware Autonomous Speed Disable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R (sticky) 
 - Dbi: R (sticky) 
 - Dbi2: R (sticky)<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && $pf == 0) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && $pf != 0  ) ?  R: (CX_MEMORY_MAP_VIEW==1 && $pf == 0 ) ? R/W:  (CX_MEMORY_MAP_VIEW==1 &&  $pf != 0) ? R: ($pf == 0)? R/W:R</ct>
<i>Note</i>: This register field is sticky. */
#define LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_HW_AUTO_SPEED_DISABLE_BitAddressOffset 5
#define LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_HW_AUTO_SPEED_DISABLE_RegisterSize 1

/* Register LINK_CONTROL2_LINK_STATUS2_REG field PCIE_CAP_SEL_DEEMPHASIS */
/* Controls Selectable De-emphasis for 5 GT/s.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_SEL_DEEMPHASIS_BitAddressOffset 6
#define LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_SEL_DEEMPHASIS_RegisterSize 1

/* Register LINK_CONTROL2_LINK_STATUS2_REG field PCIE_CAP_TX_MARGIN */
/* Controls Transmit Margin for Debug or Compliance.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_TX_MARGIN_BitAddressOffset 7
#define LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_TX_MARGIN_RegisterSize 3

/* Register LINK_CONTROL2_LINK_STATUS2_REG field PCIE_CAP_ENTER_MODIFIED_COMPLIANCE */
/* Enter Modified Compliance.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R (sticky) 
 - Dbi: R (sticky) 
 - Dbi2: R (sticky)<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && $pf == 0) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && $pf != 0  ) ?  R: (CX_MEMORY_MAP_VIEW==1 && $pf == 0 ) ? R/W:  (CX_MEMORY_MAP_VIEW==1 &&  $pf != 0) ? R: ($pf == 0)? R/W:R</ct>
<i>Note</i>: This register field is sticky. */
#define LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_ENTER_MODIFIED_COMPLIANCE_BitAddressOffset 10
#define LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_ENTER_MODIFIED_COMPLIANCE_RegisterSize 1

/* Register LINK_CONTROL2_LINK_STATUS2_REG field PCIE_CAP_COMPLIANCE_SOS */
/* Sets Compliance Skip Ordered Sets transmission.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R/W (sticky) 
 - Dbi: R/W (sticky) 
 - Dbi2: R/W (sticky)<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && $pf == 0) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && $pf != 0  ) ?  R: (CX_MEMORY_MAP_VIEW==1 && $pf == 0 ) ? R/W:  (CX_MEMORY_MAP_VIEW==1 &&  $pf != 0) ? R: ($pf == 0)? R/W:R</ct>
<i>Note</i>: This register field is sticky. */
#define LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_COMPLIANCE_SOS_BitAddressOffset 11
#define LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_COMPLIANCE_SOS_RegisterSize 1

/* Register LINK_CONTROL2_LINK_STATUS2_REG field PCIE_CAP_COMPLIANCE_PRESET */
/* Sets Compliance Preset/De-emphasis for 5 GT/s and 8 GT/s.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R/W (sticky) 
 - Dbi: R/W (sticky) 
 - Dbi2: R/W (sticky)<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && $pf == 0) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && $pf != 0  ) ?  R: (CX_MEMORY_MAP_VIEW==1 && $pf == 0 ) ? R/W:  (CX_MEMORY_MAP_VIEW==1 &&  $pf != 0) ? R: ($pf == 0)? R/W:R</ct>
<i>Note</i>: This register field is sticky. */
#define LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_COMPLIANCE_PRESET_BitAddressOffset 12
#define LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_COMPLIANCE_PRESET_RegisterSize 4

/* Register LINK_CONTROL2_LINK_STATUS2_REG field PCIE_CAP_CURR_DEEMPHASIS */
/* Current De-emphasis Level.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br> In M-PCIe mode this register is always 0x0. In C-PCIe mode, its contents are derived by sampling the PIPE */
#define LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_CURR_DEEMPHASIS_BitAddressOffset 16
#define LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_CURR_DEEMPHASIS_RegisterSize 1

/* Register LINK_CONTROL2_LINK_STATUS2_REG field RSVDP_27 */
/* Reserved for future use. */
#define LINK_CONTROL2_LINK_STATUS2_REG_RSVDP_27_BitAddressOffset 27
#define LINK_CONTROL2_LINK_STATUS2_REG_RSVDP_27_RegisterSize 1

/* Register LINK_CONTROL2_LINK_STATUS2_REG field DOWNSTREAM_COMPO_PRESENCE */
/* Downstream Component Presence.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 4.0</i>. */
#define LINK_CONTROL2_LINK_STATUS2_REG_DOWNSTREAM_COMPO_PRESENCE_BitAddressOffset 28
#define LINK_CONTROL2_LINK_STATUS2_REG_DOWNSTREAM_COMPO_PRESENCE_RegisterSize 3

/* Register LINK_CONTROL2_LINK_STATUS2_REG field DRS_MESSAGE_RECEIVED */
/* DRS Message Received.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 4.0</i>. */
#define LINK_CONTROL2_LINK_STATUS2_REG_DRS_MESSAGE_RECEIVED_BitAddressOffset 31
#define LINK_CONTROL2_LINK_STATUS2_REG_DRS_MESSAGE_RECEIVED_RegisterSize 1

/* End of Register Definition for LINK_CONTROL2_LINK_STATUS2_REG */


/* Register AER_EXT_CAP_HDR_OFF */
/* Advanced Error Reporting Extended Capability Header.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define AER_EXT_CAP_HDR_OFF (PF0_AER_CAP_BaseAddress + 0x0)
#define AER_EXT_CAP_HDR_OFF_RegisterSize 32
#define AER_EXT_CAP_HDR_OFF_RegisterResetValue 0x20001
#define AER_EXT_CAP_HDR_OFF_RegisterResetMask 0xffffffff

/* Register Field information for AER_EXT_CAP_HDR_OFF */

/* Register AER_EXT_CAP_HDR_OFF field CAP_ID */
/* AER Extended Capability ID.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W(sticky) else R(sticky) 
 - Dbi2: R */
#define AER_EXT_CAP_HDR_OFF_CAP_ID_BitAddressOffset 0
#define AER_EXT_CAP_HDR_OFF_CAP_ID_RegisterSize 16

/* Register AER_EXT_CAP_HDR_OFF field CAP_VERSION */
/* Capability Version.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W(sticky) else R(sticky) 
 - Dbi2: R */
#define AER_EXT_CAP_HDR_OFF_CAP_VERSION_BitAddressOffset 16
#define AER_EXT_CAP_HDR_OFF_CAP_VERSION_RegisterSize 4

/* Register AER_EXT_CAP_HDR_OFF field NEXT_OFFSET */
/* Next Capability Offset.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W(sticky) else R(sticky) 
 - Dbi2: R */
#define AER_EXT_CAP_HDR_OFF_NEXT_OFFSET_BitAddressOffset 20
#define AER_EXT_CAP_HDR_OFF_NEXT_OFFSET_RegisterSize 12

/* End of Register Definition for AER_EXT_CAP_HDR_OFF */

/* Register UNCORR_ERR_STATUS_OFF */
/* Uncorrectable Error Status Register.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define UNCORR_ERR_STATUS_OFF (PF0_AER_CAP_BaseAddress + 0x4)
#define UNCORR_ERR_STATUS_OFF_RegisterSize 32
#define UNCORR_ERR_STATUS_OFF_RegisterResetValue 0x0
#define UNCORR_ERR_STATUS_OFF_RegisterResetMask 0xffffffff

/* Register Field information for UNCORR_ERR_STATUS_OFF */

/* Register UNCORR_ERR_STATUS_OFF field RSVDP_0 */
/* Reserved for future use. */
#define UNCORR_ERR_STATUS_OFF_RSVDP_0_BitAddressOffset 0
#define UNCORR_ERR_STATUS_OFF_RSVDP_0_RegisterSize 4

/* Register UNCORR_ERR_STATUS_OFF field DL_PROTOCOL_ERR_STATUS */
/* Data Link Protocol Error Status.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define UNCORR_ERR_STATUS_OFF_DL_PROTOCOL_ERR_STATUS_BitAddressOffset 4
#define UNCORR_ERR_STATUS_OFF_DL_PROTOCOL_ERR_STATUS_RegisterSize 1

/* Register UNCORR_ERR_STATUS_OFF field SUR_DWN_ERR_STATUS */
/* Surprise Down Error Status (Optional).
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note:</i> Not supported. */
#define UNCORR_ERR_STATUS_OFF_SUR_DWN_ERR_STATUS_BitAddressOffset 5
#define UNCORR_ERR_STATUS_OFF_SUR_DWN_ERR_STATUS_RegisterSize 1

/* Register UNCORR_ERR_STATUS_OFF field RSVDP_6 */
/* Reserved for future use. */
#define UNCORR_ERR_STATUS_OFF_RSVDP_6_BitAddressOffset 6
#define UNCORR_ERR_STATUS_OFF_RSVDP_6_RegisterSize 6

/* Register UNCORR_ERR_STATUS_OFF field POIS_TLP_ERR_STATUS */
/* Poisoned TLP Status.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define UNCORR_ERR_STATUS_OFF_POIS_TLP_ERR_STATUS_BitAddressOffset 12
#define UNCORR_ERR_STATUS_OFF_POIS_TLP_ERR_STATUS_RegisterSize 1

/* Register UNCORR_ERR_STATUS_OFF field FC_PROTOCOL_ERR_STATUS */
/* Flow Control Protocol Error Status.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define UNCORR_ERR_STATUS_OFF_FC_PROTOCOL_ERR_STATUS_BitAddressOffset 13
#define UNCORR_ERR_STATUS_OFF_FC_PROTOCOL_ERR_STATUS_RegisterSize 1

/* Register UNCORR_ERR_STATUS_OFF field CMPLT_TIMEOUT_ERR_STATUS */
/* Completion Timeout Status.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define UNCORR_ERR_STATUS_OFF_CMPLT_TIMEOUT_ERR_STATUS_BitAddressOffset 14
#define UNCORR_ERR_STATUS_OFF_CMPLT_TIMEOUT_ERR_STATUS_RegisterSize 1

/* Register UNCORR_ERR_STATUS_OFF field CMPLT_ABORT_ERR_STATUS */
/* Completer Abort Status.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define UNCORR_ERR_STATUS_OFF_CMPLT_ABORT_ERR_STATUS_BitAddressOffset 15
#define UNCORR_ERR_STATUS_OFF_CMPLT_ABORT_ERR_STATUS_RegisterSize 1

/* Register UNCORR_ERR_STATUS_OFF field UNEXP_CMPLT_ERR_STATUS */
/* Unexpected Completion Status.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define UNCORR_ERR_STATUS_OFF_UNEXP_CMPLT_ERR_STATUS_BitAddressOffset 16
#define UNCORR_ERR_STATUS_OFF_UNEXP_CMPLT_ERR_STATUS_RegisterSize 1

/* Register UNCORR_ERR_STATUS_OFF field REC_OVERFLOW_ERR_STATUS */
/* Receiver Overflow Status.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define UNCORR_ERR_STATUS_OFF_REC_OVERFLOW_ERR_STATUS_BitAddressOffset 17
#define UNCORR_ERR_STATUS_OFF_REC_OVERFLOW_ERR_STATUS_RegisterSize 1

/* Register UNCORR_ERR_STATUS_OFF field MALF_TLP_ERR_STATUS */
/* Malformed TLP Status.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define UNCORR_ERR_STATUS_OFF_MALF_TLP_ERR_STATUS_BitAddressOffset 18
#define UNCORR_ERR_STATUS_OFF_MALF_TLP_ERR_STATUS_RegisterSize 1

/* Register UNCORR_ERR_STATUS_OFF field ECRC_ERR_STATUS */
/* ECRC Error Status.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define UNCORR_ERR_STATUS_OFF_ECRC_ERR_STATUS_BitAddressOffset 19
#define UNCORR_ERR_STATUS_OFF_ECRC_ERR_STATUS_RegisterSize 1

/* Register UNCORR_ERR_STATUS_OFF field UNSUPPORTED_REQ_ERR_STATUS */
/* Unsupported Request Error Status.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define UNCORR_ERR_STATUS_OFF_UNSUPPORTED_REQ_ERR_STATUS_BitAddressOffset 20
#define UNCORR_ERR_STATUS_OFF_UNSUPPORTED_REQ_ERR_STATUS_RegisterSize 1

/* Register UNCORR_ERR_STATUS_OFF field RSVDP_21 */
/* Reserved for future use. */
#define UNCORR_ERR_STATUS_OFF_RSVDP_21_BitAddressOffset 21
#define UNCORR_ERR_STATUS_OFF_RSVDP_21_RegisterSize 1

/* Register UNCORR_ERR_STATUS_OFF field INTERNAL_ERR_STATUS */
/* Uncorrectable Internal Error Status.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br> The core sets this bit when your application asserts app_err_bus[9]. It does not set this bit when it detects internal uncorrectable internal errors such as parity and ECC failures. You should use the outputs from these errors to drive the app_err_bus[9] input. For more details, see the "Data Integrity (Wire, Datapath, and RAM Protection)" section in the <i>Databook.</i> */
#define UNCORR_ERR_STATUS_OFF_INTERNAL_ERR_STATUS_BitAddressOffset 22
#define UNCORR_ERR_STATUS_OFF_INTERNAL_ERR_STATUS_RegisterSize 1

/* Register UNCORR_ERR_STATUS_OFF field RSVDP_23 */
/* Reserved for future use. */
#define UNCORR_ERR_STATUS_OFF_RSVDP_23_BitAddressOffset 23
#define UNCORR_ERR_STATUS_OFF_RSVDP_23_RegisterSize 2

/* Register UNCORR_ERR_STATUS_OFF field TLP_PRFX_BLOCKED_ERR_STATUS */
/* TLP Prefix Blocked Error Status.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note:</i> Not supported. */
#define UNCORR_ERR_STATUS_OFF_TLP_PRFX_BLOCKED_ERR_STATUS_BitAddressOffset 25
#define UNCORR_ERR_STATUS_OFF_TLP_PRFX_BLOCKED_ERR_STATUS_RegisterSize 1

/* Register UNCORR_ERR_STATUS_OFF field RSVDP_26 */
/* Reserved for future use. */
#define UNCORR_ERR_STATUS_OFF_RSVDP_26_BitAddressOffset 26
#define UNCORR_ERR_STATUS_OFF_RSVDP_26_RegisterSize 6

/* End of Register Definition for UNCORR_ERR_STATUS_OFF */

/* Register UNCORR_ERR_MASK_OFF */
/* Uncorrectable Error Mask Register.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define UNCORR_ERR_MASK_OFF (PF0_AER_CAP_BaseAddress + 0x8)
#define UNCORR_ERR_MASK_OFF_RegisterSize 32
#define UNCORR_ERR_MASK_OFF_RegisterResetValue 0x400000
#define UNCORR_ERR_MASK_OFF_RegisterResetMask 0xffffffff

/* Register Field information for UNCORR_ERR_MASK_OFF */

/* Register UNCORR_ERR_MASK_OFF field RSVDP_0 */
/* Reserved for future use. */
#define UNCORR_ERR_MASK_OFF_RSVDP_0_BitAddressOffset 0
#define UNCORR_ERR_MASK_OFF_RSVDP_0_RegisterSize 4

/* Register UNCORR_ERR_MASK_OFF field DL_PROTOCOL_ERR_MASK */
/* Data Link Protocol Error Mask.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define UNCORR_ERR_MASK_OFF_DL_PROTOCOL_ERR_MASK_BitAddressOffset 4
#define UNCORR_ERR_MASK_OFF_DL_PROTOCOL_ERR_MASK_RegisterSize 1

/* Register UNCORR_ERR_MASK_OFF field SUR_DWN_ERR_MASK */
/* Surprise Down Error Mask.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note:</i> Not supported. */
#define UNCORR_ERR_MASK_OFF_SUR_DWN_ERR_MASK_BitAddressOffset 5
#define UNCORR_ERR_MASK_OFF_SUR_DWN_ERR_MASK_RegisterSize 1

/* Register UNCORR_ERR_MASK_OFF field RSVDP_6 */
/* Reserved for future use. */
#define UNCORR_ERR_MASK_OFF_RSVDP_6_BitAddressOffset 6
#define UNCORR_ERR_MASK_OFF_RSVDP_6_RegisterSize 6

/* Register UNCORR_ERR_MASK_OFF field POIS_TLP_ERR_MASK */
/* Poisoned TLP Error Mask.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define UNCORR_ERR_MASK_OFF_POIS_TLP_ERR_MASK_BitAddressOffset 12
#define UNCORR_ERR_MASK_OFF_POIS_TLP_ERR_MASK_RegisterSize 1

/* Register UNCORR_ERR_MASK_OFF field FC_PROTOCOL_ERR_MASK */
/* Flow Control Protocol Error Mask.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define UNCORR_ERR_MASK_OFF_FC_PROTOCOL_ERR_MASK_BitAddressOffset 13
#define UNCORR_ERR_MASK_OFF_FC_PROTOCOL_ERR_MASK_RegisterSize 1

/* Register UNCORR_ERR_MASK_OFF field CMPLT_TIMEOUT_ERR_MASK */
/* Completion Timeout Error Mask.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define UNCORR_ERR_MASK_OFF_CMPLT_TIMEOUT_ERR_MASK_BitAddressOffset 14
#define UNCORR_ERR_MASK_OFF_CMPLT_TIMEOUT_ERR_MASK_RegisterSize 1

/* Register UNCORR_ERR_MASK_OFF field CMPLT_ABORT_ERR_MASK */
/* Completer Abort Error Mask (Optional).
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define UNCORR_ERR_MASK_OFF_CMPLT_ABORT_ERR_MASK_BitAddressOffset 15
#define UNCORR_ERR_MASK_OFF_CMPLT_ABORT_ERR_MASK_RegisterSize 1

/* Register UNCORR_ERR_MASK_OFF field UNEXP_CMPLT_ERR_MASK */
/* Unexpected Completion Mask.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define UNCORR_ERR_MASK_OFF_UNEXP_CMPLT_ERR_MASK_BitAddressOffset 16
#define UNCORR_ERR_MASK_OFF_UNEXP_CMPLT_ERR_MASK_RegisterSize 1

/* Register UNCORR_ERR_MASK_OFF field REC_OVERFLOW_ERR_MASK */
/* Receiver Overflow Mask (Optional).
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define UNCORR_ERR_MASK_OFF_REC_OVERFLOW_ERR_MASK_BitAddressOffset 17
#define UNCORR_ERR_MASK_OFF_REC_OVERFLOW_ERR_MASK_RegisterSize 1

/* Register UNCORR_ERR_MASK_OFF field MALF_TLP_ERR_MASK */
/* Malformed TLP Mask.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define UNCORR_ERR_MASK_OFF_MALF_TLP_ERR_MASK_BitAddressOffset 18
#define UNCORR_ERR_MASK_OFF_MALF_TLP_ERR_MASK_RegisterSize 1

/* Register UNCORR_ERR_MASK_OFF field ECRC_ERR_MASK */
/* ECRC Error Mask (Optional).
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R/W (sticky) 
 - Dbi: R/W (sticky) 
 - Dbi2: R/W (sticky)<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && DEFAULT_ECRC_CHK_CAP_$pf) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && !DEFAULT_ECRC_CHK_CAP_$pf) ?  R: (CX_MEMORY_MAP_VIEW==1 &&  DEFAULT_ECRC_CHK_CAP_$pf) ? R/W:  (CX_MEMORY_MAP_VIEW==1 &&  !DEFAULT_ECRC_CHK_CAP_$pf) ? R: (DEFAULT_ECRC_CHK_CAP_$pf)? R/W:R</ct>
<i>Note</i>: This register field is sticky. */
#define UNCORR_ERR_MASK_OFF_ECRC_ERR_MASK_BitAddressOffset 19
#define UNCORR_ERR_MASK_OFF_ECRC_ERR_MASK_RegisterSize 1

/* Register UNCORR_ERR_MASK_OFF field UNSUPPORTED_REQ_ERR_MASK */
/* Unsupported Request Error Mask.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define UNCORR_ERR_MASK_OFF_UNSUPPORTED_REQ_ERR_MASK_BitAddressOffset 20
#define UNCORR_ERR_MASK_OFF_UNSUPPORTED_REQ_ERR_MASK_RegisterSize 1

/* Register UNCORR_ERR_MASK_OFF field RSVDP_21 */
/* Reserved for future use. */
#define UNCORR_ERR_MASK_OFF_RSVDP_21_BitAddressOffset 21
#define UNCORR_ERR_MASK_OFF_RSVDP_21_RegisterSize 1

/* Register UNCORR_ERR_MASK_OFF field INTERNAL_ERR_MASK */
/* Uncorrectable Internal Error Mask (Optional).
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define UNCORR_ERR_MASK_OFF_INTERNAL_ERR_MASK_BitAddressOffset 22
#define UNCORR_ERR_MASK_OFF_INTERNAL_ERR_MASK_RegisterSize 1

/* Register UNCORR_ERR_MASK_OFF field RSVDP_23 */
/* Reserved for future use. */
#define UNCORR_ERR_MASK_OFF_RSVDP_23_BitAddressOffset 23
#define UNCORR_ERR_MASK_OFF_RSVDP_23_RegisterSize 1

/* Register UNCORR_ERR_MASK_OFF field ATOMIC_EGRESS_BLOCKED_ERR_MASK */
/* AtomicOp Egress Block Mask (Optional).
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R/W (sticky) 
 - Dbi: R/W (sticky) 
 - Dbi2: R/W (sticky)<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && ATOMIC_ROUTING_SUP) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && !ATOMIC_ROUTING_SUP) ?  R: (CX_MEMORY_MAP_VIEW==1 && ATOMIC_ROUTING_SUP) ?  R/W : (CX_MEMORY_MAP_VIEW==1 && !ATOMIC_ROUTING_SUP  ) ? R: (ATOMIC_ROUTING_SUP) ? R/W : R</ct>
<i>Note</i>: This register field is sticky. */
#define UNCORR_ERR_MASK_OFF_ATOMIC_EGRESS_BLOCKED_ERR_MASK_BitAddressOffset 24
#define UNCORR_ERR_MASK_OFF_ATOMIC_EGRESS_BLOCKED_ERR_MASK_RegisterSize 1

/* Register UNCORR_ERR_MASK_OFF field TLP_PRFX_BLOCKED_ERR_MASK */
/* TLP Prefix Blocked Error Mask.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note:</i> Not supported.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R/W (sticky) 
 - Dbi: R/W (sticky) 
 - Dbi2: R/W (sticky)<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && CX_TLP_PREFIX_ENABLE) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && !CX_TLP_PREFIX_ENABLE) ?  R: (CX_MEMORY_MAP_VIEW==1 && CX_TLP_PREFIX_ENABLE) ?  R/W : (CX_MEMORY_MAP_VIEW==1 && !CX_TLP_PREFIX_ENABLE ) ? R: (CX_TLP_PREFIX_ENABLE) ? R/W : R</ct>
<i>Note</i>: This register field is sticky. */
#define UNCORR_ERR_MASK_OFF_TLP_PRFX_BLOCKED_ERR_MASK_BitAddressOffset 25
#define UNCORR_ERR_MASK_OFF_TLP_PRFX_BLOCKED_ERR_MASK_RegisterSize 1

/* Register UNCORR_ERR_MASK_OFF field RSVDP_26 */
/* Reserved for future use. */
#define UNCORR_ERR_MASK_OFF_RSVDP_26_BitAddressOffset 26
#define UNCORR_ERR_MASK_OFF_RSVDP_26_RegisterSize 6

/* End of Register Definition for UNCORR_ERR_MASK_OFF */

/* Register UNCORR_ERR_SEV_OFF */
/* Uncorrectable Error Severity Register.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define UNCORR_ERR_SEV_OFF (PF0_AER_CAP_BaseAddress + 0xc)
#define UNCORR_ERR_SEV_OFF_RegisterSize 32
#define UNCORR_ERR_SEV_OFF_RegisterResetValue 0x462030
#define UNCORR_ERR_SEV_OFF_RegisterResetMask 0xffffffff

/* Register Field information for UNCORR_ERR_SEV_OFF */

/* Register UNCORR_ERR_SEV_OFF field RSVDP_0 */
/* Reserved for future use. */
#define UNCORR_ERR_SEV_OFF_RSVDP_0_BitAddressOffset 0
#define UNCORR_ERR_SEV_OFF_RSVDP_0_RegisterSize 4

/* Register UNCORR_ERR_SEV_OFF field DL_PROTOCOL_ERR_SEVERITY */
/* Data Link Protocol Error Severity.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define UNCORR_ERR_SEV_OFF_DL_PROTOCOL_ERR_SEVERITY_BitAddressOffset 4
#define UNCORR_ERR_SEV_OFF_DL_PROTOCOL_ERR_SEVERITY_RegisterSize 1

/* Register UNCORR_ERR_SEV_OFF field SUR_DWN_ERR_SEVERITY */
/* Surprise Down Error Severity (Optional).
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note:</i> Not supported.
<br><i>Note</i>: This register field is sticky. */
#define UNCORR_ERR_SEV_OFF_SUR_DWN_ERR_SEVERITY_BitAddressOffset 5
#define UNCORR_ERR_SEV_OFF_SUR_DWN_ERR_SEVERITY_RegisterSize 1

/* Register UNCORR_ERR_SEV_OFF field RSVDP_6 */
/* Reserved for future use. */
#define UNCORR_ERR_SEV_OFF_RSVDP_6_BitAddressOffset 6
#define UNCORR_ERR_SEV_OFF_RSVDP_6_RegisterSize 6

/* Register UNCORR_ERR_SEV_OFF field POIS_TLP_ERR_SEVERITY */
/* Poisoned TLP Severity.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define UNCORR_ERR_SEV_OFF_POIS_TLP_ERR_SEVERITY_BitAddressOffset 12
#define UNCORR_ERR_SEV_OFF_POIS_TLP_ERR_SEVERITY_RegisterSize 1

/* Register UNCORR_ERR_SEV_OFF field FC_PROTOCOL_ERR_SEVERITY */
/* Flow Control Protocol Error Severity (Optional).
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define UNCORR_ERR_SEV_OFF_FC_PROTOCOL_ERR_SEVERITY_BitAddressOffset 13
#define UNCORR_ERR_SEV_OFF_FC_PROTOCOL_ERR_SEVERITY_RegisterSize 1

/* Register UNCORR_ERR_SEV_OFF field CMPLT_TIMEOUT_ERR_SEVERITY */
/* Completion Timeout Error Severity.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define UNCORR_ERR_SEV_OFF_CMPLT_TIMEOUT_ERR_SEVERITY_BitAddressOffset 14
#define UNCORR_ERR_SEV_OFF_CMPLT_TIMEOUT_ERR_SEVERITY_RegisterSize 1

/* Register UNCORR_ERR_SEV_OFF field CMPLT_ABORT_ERR_SEVERITY */
/* Completer Abort Error Severity (Optional).
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define UNCORR_ERR_SEV_OFF_CMPLT_ABORT_ERR_SEVERITY_BitAddressOffset 15
#define UNCORR_ERR_SEV_OFF_CMPLT_ABORT_ERR_SEVERITY_RegisterSize 1

/* Register UNCORR_ERR_SEV_OFF field UNEXP_CMPLT_ERR_SEVERITY */
/* Unexpected Completion Error Severity.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define UNCORR_ERR_SEV_OFF_UNEXP_CMPLT_ERR_SEVERITY_BitAddressOffset 16
#define UNCORR_ERR_SEV_OFF_UNEXP_CMPLT_ERR_SEVERITY_RegisterSize 1

/* Register UNCORR_ERR_SEV_OFF field REC_OVERFLOW_ERR_SEVERITY */
/* Receiver Overflow Error Severity (Optional).
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define UNCORR_ERR_SEV_OFF_REC_OVERFLOW_ERR_SEVERITY_BitAddressOffset 17
#define UNCORR_ERR_SEV_OFF_REC_OVERFLOW_ERR_SEVERITY_RegisterSize 1

/* Register UNCORR_ERR_SEV_OFF field MALF_TLP_ERR_SEVERITY */
/* Malformed TLP Severity.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define UNCORR_ERR_SEV_OFF_MALF_TLP_ERR_SEVERITY_BitAddressOffset 18
#define UNCORR_ERR_SEV_OFF_MALF_TLP_ERR_SEVERITY_RegisterSize 1

/* Register UNCORR_ERR_SEV_OFF field ECRC_ERR_SEVERITY */
/* ECRC Error Severity (Optional).
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R/W (sticky) 
 - Dbi: R/W (sticky) 
 - Dbi2: R/W (sticky)<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && DEFAULT_ECRC_CHK_CAP_$pf) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && !DEFAULT_ECRC_CHK_CAP_$pf) ?  R: (CX_MEMORY_MAP_VIEW==1 &&  DEFAULT_ECRC_CHK_CAP_$pf) ? R/W:  (CX_MEMORY_MAP_VIEW==1 &&  !DEFAULT_ECRC_CHK_CAP_$pf) ?  R: (DEFAULT_ECRC_CHK_CAP_$pf)? R/W:R</ct>
<i>Note</i>: This register field is sticky. */
#define UNCORR_ERR_SEV_OFF_ECRC_ERR_SEVERITY_BitAddressOffset 19
#define UNCORR_ERR_SEV_OFF_ECRC_ERR_SEVERITY_RegisterSize 1

/* Register UNCORR_ERR_SEV_OFF field UNSUPPORTED_REQ_ERR_SEVERITY */
/* Unsupported Request Error Severity.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define UNCORR_ERR_SEV_OFF_UNSUPPORTED_REQ_ERR_SEVERITY_BitAddressOffset 20
#define UNCORR_ERR_SEV_OFF_UNSUPPORTED_REQ_ERR_SEVERITY_RegisterSize 1

/* Register UNCORR_ERR_SEV_OFF field RSVDP_21 */
/* Reserved for future use. */
#define UNCORR_ERR_SEV_OFF_RSVDP_21_BitAddressOffset 21
#define UNCORR_ERR_SEV_OFF_RSVDP_21_RegisterSize 1

/* Register UNCORR_ERR_SEV_OFF field INTERNAL_ERR_SEVERITY */
/* Uncorrectable Internal Error Severity (Optional).
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define UNCORR_ERR_SEV_OFF_INTERNAL_ERR_SEVERITY_BitAddressOffset 22
#define UNCORR_ERR_SEV_OFF_INTERNAL_ERR_SEVERITY_RegisterSize 1

/* Register UNCORR_ERR_SEV_OFF field RSVDP_23 */
/* Reserved for future use. */
#define UNCORR_ERR_SEV_OFF_RSVDP_23_BitAddressOffset 23
#define UNCORR_ERR_SEV_OFF_RSVDP_23_RegisterSize 1

/* Register UNCORR_ERR_SEV_OFF field ATOMIC_EGRESS_BLOCKED_ERR_SEVERITY */
/* AtomicOp Egress Blocked Severity (Optional).
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R/W (sticky) 
 - Dbi: R/W (sticky) 
 - Dbi2: R/W (sticky)<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && ATOMIC_ROUTING_SUP) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && !ATOMIC_ROUTING_SUP) ?  R: (CX_MEMORY_MAP_VIEW==1 && ATOMIC_ROUTING_SUP) ?  R/W : (CX_MEMORY_MAP_VIEW==1 && !ATOMIC_ROUTING_SUP  ) ? R: (ATOMIC_ROUTING_SUP) ? R/W : R</ct>
<i>Note</i>: This register field is sticky. */
#define UNCORR_ERR_SEV_OFF_ATOMIC_EGRESS_BLOCKED_ERR_SEVERITY_BitAddressOffset 24
#define UNCORR_ERR_SEV_OFF_ATOMIC_EGRESS_BLOCKED_ERR_SEVERITY_RegisterSize 1

/* Register UNCORR_ERR_SEV_OFF field TLP_PRFX_BLOCKED_ERR_SEVERITY */
/* TLP Prefix Blocked Error Severity (Optional).
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note:</i> Not supported.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R/W (sticky) 
 - Dbi: R/W (sticky) 
 - Dbi2: R/W (sticky)<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && CX_TLP_PREFIX_ENABLE) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && !CX_TLP_PREFIX_ENABLE) ?  R: (CX_MEMORY_MAP_VIEW==1 && CX_TLP_PREFIX_ENABLE) ?  R/W : (CX_MEMORY_MAP_VIEW==1 && !CX_TLP_PREFIX_ENABLE ) ? R: (CX_TLP_PREFIX_ENABLE) ? R/W : R</ct>
<i>Note</i>: This register field is sticky. */
#define UNCORR_ERR_SEV_OFF_TLP_PRFX_BLOCKED_ERR_SEVERITY_BitAddressOffset 25
#define UNCORR_ERR_SEV_OFF_TLP_PRFX_BLOCKED_ERR_SEVERITY_RegisterSize 1

/* Register UNCORR_ERR_SEV_OFF field RSVDP_26 */
/* Reserved for future use. */
#define UNCORR_ERR_SEV_OFF_RSVDP_26_BitAddressOffset 26
#define UNCORR_ERR_SEV_OFF_RSVDP_26_RegisterSize 6

/* End of Register Definition for UNCORR_ERR_SEV_OFF */

/* Register CORR_ERR_STATUS_OFF */
/* Correctable Error Status Register.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define CORR_ERR_STATUS_OFF (PF0_AER_CAP_BaseAddress + 0x10)
#define CORR_ERR_STATUS_OFF_RegisterSize 32
#define CORR_ERR_STATUS_OFF_RegisterResetValue 0x0
#define CORR_ERR_STATUS_OFF_RegisterResetMask 0xffffffff

/* Register Field information for CORR_ERR_STATUS_OFF */

/* Register CORR_ERR_STATUS_OFF field RX_ERR_STATUS */
/* Receiver Error Status (Optional).
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define CORR_ERR_STATUS_OFF_RX_ERR_STATUS_BitAddressOffset 0
#define CORR_ERR_STATUS_OFF_RX_ERR_STATUS_RegisterSize 1

/* Register CORR_ERR_STATUS_OFF field RSVDP_1 */
/* Reserved for future use. */
#define CORR_ERR_STATUS_OFF_RSVDP_1_BitAddressOffset 1
#define CORR_ERR_STATUS_OFF_RSVDP_1_RegisterSize 5

/* Register CORR_ERR_STATUS_OFF field BAD_TLP_STATUS */
/* Bad TLP Status.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define CORR_ERR_STATUS_OFF_BAD_TLP_STATUS_BitAddressOffset 6
#define CORR_ERR_STATUS_OFF_BAD_TLP_STATUS_RegisterSize 1

/* Register CORR_ERR_STATUS_OFF field BAD_DLLP_STATUS */
/* Bad DLLP Status.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define CORR_ERR_STATUS_OFF_BAD_DLLP_STATUS_BitAddressOffset 7
#define CORR_ERR_STATUS_OFF_BAD_DLLP_STATUS_RegisterSize 1

/* Register CORR_ERR_STATUS_OFF field REPLAY_NO_ROLEOVER_STATUS */
/* REPLAY_NUM Rollover Status.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define CORR_ERR_STATUS_OFF_REPLAY_NO_ROLEOVER_STATUS_BitAddressOffset 8
#define CORR_ERR_STATUS_OFF_REPLAY_NO_ROLEOVER_STATUS_RegisterSize 1

/* Register CORR_ERR_STATUS_OFF field RSVDP_9 */
/* Reserved for future use. */
#define CORR_ERR_STATUS_OFF_RSVDP_9_BitAddressOffset 9
#define CORR_ERR_STATUS_OFF_RSVDP_9_RegisterSize 3

/* Register CORR_ERR_STATUS_OFF field RPL_TIMER_TIMEOUT_STATUS */
/* Replay Timer Timeout Status.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define CORR_ERR_STATUS_OFF_RPL_TIMER_TIMEOUT_STATUS_BitAddressOffset 12
#define CORR_ERR_STATUS_OFF_RPL_TIMER_TIMEOUT_STATUS_RegisterSize 1

/* Register CORR_ERR_STATUS_OFF field ADVISORY_NON_FATAL_ERR_STATUS */
/* Advisory Non-Fatal Error Status.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define CORR_ERR_STATUS_OFF_ADVISORY_NON_FATAL_ERR_STATUS_BitAddressOffset 13
#define CORR_ERR_STATUS_OFF_ADVISORY_NON_FATAL_ERR_STATUS_RegisterSize 1

/* Register CORR_ERR_STATUS_OFF field CORRECTED_INT_ERR_STATUS */
/* Corrected Internal Error Status (Optional).
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define CORR_ERR_STATUS_OFF_CORRECTED_INT_ERR_STATUS_BitAddressOffset 14
#define CORR_ERR_STATUS_OFF_CORRECTED_INT_ERR_STATUS_RegisterSize 1

/* Register CORR_ERR_STATUS_OFF field RSVDP_15 */
/* Reserved for future use. */
#define CORR_ERR_STATUS_OFF_RSVDP_15_BitAddressOffset 15
#define CORR_ERR_STATUS_OFF_RSVDP_15_RegisterSize 17

/* End of Register Definition for CORR_ERR_STATUS_OFF */

/* Register CORR_ERR_MASK_OFF */
/* Correctable Error Mask Register.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define CORR_ERR_MASK_OFF (PF0_AER_CAP_BaseAddress + 0x14)
#define CORR_ERR_MASK_OFF_RegisterSize 32
#define CORR_ERR_MASK_OFF_RegisterResetValue 0x6000
#define CORR_ERR_MASK_OFF_RegisterResetMask 0xffffffff

/* Register Field information for CORR_ERR_MASK_OFF */

/* Register CORR_ERR_MASK_OFF field RX_ERR_MASK */
/* Receiver Error Mask (Optional).
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define CORR_ERR_MASK_OFF_RX_ERR_MASK_BitAddressOffset 0
#define CORR_ERR_MASK_OFF_RX_ERR_MASK_RegisterSize 1

/* Register CORR_ERR_MASK_OFF field RSVDP_1 */
/* Reserved for future use. */
#define CORR_ERR_MASK_OFF_RSVDP_1_BitAddressOffset 1
#define CORR_ERR_MASK_OFF_RSVDP_1_RegisterSize 5

/* Register CORR_ERR_MASK_OFF field BAD_TLP_MASK */
/* Bad TLP Mask.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define CORR_ERR_MASK_OFF_BAD_TLP_MASK_BitAddressOffset 6
#define CORR_ERR_MASK_OFF_BAD_TLP_MASK_RegisterSize 1

/* Register CORR_ERR_MASK_OFF field BAD_DLLP_MASK */
/* Bad DLLP Mask.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define CORR_ERR_MASK_OFF_BAD_DLLP_MASK_BitAddressOffset 7
#define CORR_ERR_MASK_OFF_BAD_DLLP_MASK_RegisterSize 1

/* Register CORR_ERR_MASK_OFF field REPLAY_NO_ROLEOVER_MASK */
/* REPLAY_NUM Rollover Mask.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define CORR_ERR_MASK_OFF_REPLAY_NO_ROLEOVER_MASK_BitAddressOffset 8
#define CORR_ERR_MASK_OFF_REPLAY_NO_ROLEOVER_MASK_RegisterSize 1

/* Register CORR_ERR_MASK_OFF field RSVDP_9 */
/* Reserved for future use. */
#define CORR_ERR_MASK_OFF_RSVDP_9_BitAddressOffset 9
#define CORR_ERR_MASK_OFF_RSVDP_9_RegisterSize 3

/* Register CORR_ERR_MASK_OFF field RPL_TIMER_TIMEOUT_MASK */
/* Replay Timer Timeout Mask.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define CORR_ERR_MASK_OFF_RPL_TIMER_TIMEOUT_MASK_BitAddressOffset 12
#define CORR_ERR_MASK_OFF_RPL_TIMER_TIMEOUT_MASK_RegisterSize 1

/* Register CORR_ERR_MASK_OFF field ADVISORY_NON_FATAL_ERR_MASK */
/* Advisory Non-Fatal Error Mask.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define CORR_ERR_MASK_OFF_ADVISORY_NON_FATAL_ERR_MASK_BitAddressOffset 13
#define CORR_ERR_MASK_OFF_ADVISORY_NON_FATAL_ERR_MASK_RegisterSize 1

/* Register CORR_ERR_MASK_OFF field CORRECTED_INT_ERR_MASK */
/* Corrected Internal Error Mask (Optional).
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define CORR_ERR_MASK_OFF_CORRECTED_INT_ERR_MASK_BitAddressOffset 14
#define CORR_ERR_MASK_OFF_CORRECTED_INT_ERR_MASK_RegisterSize 1

/* Register CORR_ERR_MASK_OFF field RSVDP_15 */
/* Reserved for future use. */
#define CORR_ERR_MASK_OFF_RSVDP_15_BitAddressOffset 15
#define CORR_ERR_MASK_OFF_RSVDP_15_RegisterSize 17

/* End of Register Definition for CORR_ERR_MASK_OFF */

/* Register ADV_ERR_CAP_CTRL_OFF */
/* Advanced Error Capabilities and Control Register.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define ADV_ERR_CAP_CTRL_OFF (PF0_AER_CAP_BaseAddress + 0x18)
#define ADV_ERR_CAP_CTRL_OFF_RegisterSize 32
#define ADV_ERR_CAP_CTRL_OFF_RegisterResetValue 0xa0
#define ADV_ERR_CAP_CTRL_OFF_RegisterResetMask 0xffffffff

/* Register Field information for ADV_ERR_CAP_CTRL_OFF */

/* Register ADV_ERR_CAP_CTRL_OFF field FIRST_ERR_POINTER */
/* First Error Pointer.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define ADV_ERR_CAP_CTRL_OFF_FIRST_ERR_POINTER_BitAddressOffset 0
#define ADV_ERR_CAP_CTRL_OFF_FIRST_ERR_POINTER_RegisterSize 5

/* Register ADV_ERR_CAP_CTRL_OFF field ECRC_GEN_CAP */
/* ECRC Generation Capable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define ADV_ERR_CAP_CTRL_OFF_ECRC_GEN_CAP_BitAddressOffset 5
#define ADV_ERR_CAP_CTRL_OFF_ECRC_GEN_CAP_RegisterSize 1

/* Register ADV_ERR_CAP_CTRL_OFF field ECRC_GEN_EN */
/* ECRC Generation Enable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define ADV_ERR_CAP_CTRL_OFF_ECRC_GEN_EN_BitAddressOffset 6
#define ADV_ERR_CAP_CTRL_OFF_ECRC_GEN_EN_RegisterSize 1

/* Register ADV_ERR_CAP_CTRL_OFF field ECRC_CHECK_CAP */
/* ECRC Check Capable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define ADV_ERR_CAP_CTRL_OFF_ECRC_CHECK_CAP_BitAddressOffset 7
#define ADV_ERR_CAP_CTRL_OFF_ECRC_CHECK_CAP_RegisterSize 1

/* Register ADV_ERR_CAP_CTRL_OFF field ECRC_CHECK_EN */
/* ECRC Check Enable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define ADV_ERR_CAP_CTRL_OFF_ECRC_CHECK_EN_BitAddressOffset 8
#define ADV_ERR_CAP_CTRL_OFF_ECRC_CHECK_EN_RegisterSize 1

/* Register ADV_ERR_CAP_CTRL_OFF field RSVDP_9 */
/* Reserved for future use. */
#define ADV_ERR_CAP_CTRL_OFF_RSVDP_9_BitAddressOffset 9
#define ADV_ERR_CAP_CTRL_OFF_RSVDP_9_RegisterSize 2

/* Register ADV_ERR_CAP_CTRL_OFF field RSVDP_12 */
/* Reserved for future use. */
#define ADV_ERR_CAP_CTRL_OFF_RSVDP_12_BitAddressOffset 12
#define ADV_ERR_CAP_CTRL_OFF_RSVDP_12_RegisterSize 20

/* End of Register Definition for ADV_ERR_CAP_CTRL_OFF */

/* Register HDR_LOG_0_OFF */
/* Header Log Register 0.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define HDR_LOG_0_OFF (PF0_AER_CAP_BaseAddress + 0x1c)
#define HDR_LOG_0_OFF_RegisterSize 32
#define HDR_LOG_0_OFF_RegisterResetValue 0x0
#define HDR_LOG_0_OFF_RegisterResetMask 0xffffffff

/* Register Field information for HDR_LOG_0_OFF */

/* Register HDR_LOG_0_OFF field FIRST_DWORD */
/* First 32 bit Data Word.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define HDR_LOG_0_OFF_FIRST_DWORD_BitAddressOffset 0
#define HDR_LOG_0_OFF_FIRST_DWORD_RegisterSize 32

/* End of Register Definition for HDR_LOG_0_OFF */

/* Register HDR_LOG_1_OFF */
/* Header Log Register 1.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define HDR_LOG_1_OFF (PF0_AER_CAP_BaseAddress + 0x20)
#define HDR_LOG_1_OFF_RegisterSize 32
#define HDR_LOG_1_OFF_RegisterResetValue 0x0
#define HDR_LOG_1_OFF_RegisterResetMask 0xffffffff

/* Register Field information for HDR_LOG_1_OFF */

/* Register HDR_LOG_1_OFF field SECOND_DWORD */
/* Second 32 bit Data Word.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define HDR_LOG_1_OFF_SECOND_DWORD_BitAddressOffset 0
#define HDR_LOG_1_OFF_SECOND_DWORD_RegisterSize 32

/* End of Register Definition for HDR_LOG_1_OFF */

/* Register HDR_LOG_2_OFF */
/* Header Log Register 2.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define HDR_LOG_2_OFF (PF0_AER_CAP_BaseAddress + 0x24)
#define HDR_LOG_2_OFF_RegisterSize 32
#define HDR_LOG_2_OFF_RegisterResetValue 0x0
#define HDR_LOG_2_OFF_RegisterResetMask 0xffffffff

/* Register Field information for HDR_LOG_2_OFF */

/* Register HDR_LOG_2_OFF field THIRD_DWORD */
/* Third 32 bit Data Word.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define HDR_LOG_2_OFF_THIRD_DWORD_BitAddressOffset 0
#define HDR_LOG_2_OFF_THIRD_DWORD_RegisterSize 32

/* End of Register Definition for HDR_LOG_2_OFF */

/* Register HDR_LOG_3_OFF */
/* Header Log Register 3.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define HDR_LOG_3_OFF (PF0_AER_CAP_BaseAddress + 0x28)
#define HDR_LOG_3_OFF_RegisterSize 32
#define HDR_LOG_3_OFF_RegisterResetValue 0x0
#define HDR_LOG_3_OFF_RegisterResetMask 0xffffffff

/* Register Field information for HDR_LOG_3_OFF */

/* Register HDR_LOG_3_OFF field FOURTH_DWORD */
/* Fourth 32 bit Data Word.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define HDR_LOG_3_OFF_FOURTH_DWORD_BitAddressOffset 0
#define HDR_LOG_3_OFF_FOURTH_DWORD_RegisterSize 32

/* End of Register Definition for HDR_LOG_3_OFF */

/* Register TLP_PREFIX_LOG_1_OFF */
/* TLP Prefix Log Register.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define TLP_PREFIX_LOG_1_OFF (PF0_AER_CAP_BaseAddress + 0x38)
#define TLP_PREFIX_LOG_1_OFF_RegisterSize 32
#define TLP_PREFIX_LOG_1_OFF_RegisterResetValue 0x0
#define TLP_PREFIX_LOG_1_OFF_RegisterResetMask 0xffffffff

/* Register Field information for TLP_PREFIX_LOG_1_OFF */

/* Register TLP_PREFIX_LOG_1_OFF field CFG_TLP_PFX_LOG_1 */
/* Error TLP Prefix Log 1.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_BitAddressOffset 0
#define TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_RegisterSize 32

/* End of Register Definition for TLP_PREFIX_LOG_1_OFF */

/* Register TLP_PREFIX_LOG_2_OFF */
/* TLP Prefix Log Register.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define TLP_PREFIX_LOG_2_OFF (PF0_AER_CAP_BaseAddress + 0x3c)
#define TLP_PREFIX_LOG_2_OFF_RegisterSize 32
#define TLP_PREFIX_LOG_2_OFF_RegisterResetValue 0x0
#define TLP_PREFIX_LOG_2_OFF_RegisterResetMask 0xffffffff

/* Register Field information for TLP_PREFIX_LOG_2_OFF */

/* Register TLP_PREFIX_LOG_2_OFF field CFG_TLP_PFX_LOG_2 */
/* Error TLP Prefix Log 2.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_BitAddressOffset 0
#define TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_RegisterSize 32

/* End of Register Definition for TLP_PREFIX_LOG_2_OFF */

/* Register TLP_PREFIX_LOG_3_OFF */
/* TLP Prefix Log Register.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define TLP_PREFIX_LOG_3_OFF (PF0_AER_CAP_BaseAddress + 0x40)
#define TLP_PREFIX_LOG_3_OFF_RegisterSize 32
#define TLP_PREFIX_LOG_3_OFF_RegisterResetValue 0x0
#define TLP_PREFIX_LOG_3_OFF_RegisterResetMask 0xffffffff

/* Register Field information for TLP_PREFIX_LOG_3_OFF */

/* Register TLP_PREFIX_LOG_3_OFF field CFG_TLP_PFX_LOG_3 */
/* Error TLP Prefix Log 3.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_BitAddressOffset 0
#define TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_RegisterSize 32

/* End of Register Definition for TLP_PREFIX_LOG_3_OFF */

/* Register TLP_PREFIX_LOG_4_OFF */
/* TLP Prefix Log Register.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define TLP_PREFIX_LOG_4_OFF (PF0_AER_CAP_BaseAddress + 0x44)
#define TLP_PREFIX_LOG_4_OFF_RegisterSize 32
#define TLP_PREFIX_LOG_4_OFF_RegisterResetValue 0x0
#define TLP_PREFIX_LOG_4_OFF_RegisterResetMask 0xffffffff

/* Register Field information for TLP_PREFIX_LOG_4_OFF */

/* Register TLP_PREFIX_LOG_4_OFF field CFG_TLP_PFX_LOG_4 */
/* Error TLP Prefix Log 4.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: This register field is sticky. */
#define TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_BitAddressOffset 0
#define TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_RegisterSize 32

/* End of Register Definition for TLP_PREFIX_LOG_4_OFF */


/* Register PCI_MSI_CAP_ID_NEXT_CTRL_REG */
/* MSI Capability ID, Next Pointer, Capability/Control Registers.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define PCI_MSI_CAP_ID_NEXT_CTRL_REG (PF0_MSI_CAP_BaseAddress + 0x0)
#define PCI_MSI_CAP_ID_NEXT_CTRL_REG_RegisterSize 32
#define PCI_MSI_CAP_ID_NEXT_CTRL_REG_RegisterResetValue 0x807005
#define PCI_MSI_CAP_ID_NEXT_CTRL_REG_RegisterResetMask 0xffffffff

/* Register Field information for PCI_MSI_CAP_ID_NEXT_CTRL_REG */

/* Register PCI_MSI_CAP_ID_NEXT_CTRL_REG field PCI_MSI_CAP_ID */
/* MSI Capability ID.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_CAP_ID_BitAddressOffset 0
#define PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_CAP_ID_RegisterSize 8

/* Register PCI_MSI_CAP_ID_NEXT_CTRL_REG field PCI_MSI_CAP_NEXT_OFFSET */
/* MSI Capability Next Pointer.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: R */
#define PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_CAP_NEXT_OFFSET_BitAddressOffset 8
#define PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_CAP_NEXT_OFFSET_RegisterSize 8

/* Register PCI_MSI_CAP_ID_NEXT_CTRL_REG field PCI_MSI_ENABLE */
/* MSI Enable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_ENABLE_BitAddressOffset 16
#define PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_ENABLE_RegisterSize 1

/* Register PCI_MSI_CAP_ID_NEXT_CTRL_REG field PCI_MSI_MULTIPLE_MSG_CAP */
/* MSI Multiple Message Capable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: R */
#define PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_MULTIPLE_MSG_CAP_BitAddressOffset 17
#define PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_MULTIPLE_MSG_CAP_RegisterSize 3

/* Register PCI_MSI_CAP_ID_NEXT_CTRL_REG field PCI_MSI_MULTIPLE_MSG_EN */
/* MSI Multiple Message Enable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_MULTIPLE_MSG_EN_BitAddressOffset 20
#define PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_MULTIPLE_MSG_EN_RegisterSize 3

/* Register PCI_MSI_CAP_ID_NEXT_CTRL_REG field PCI_MSI_64_BIT_ADDR_CAP */
/* MSI 64-bit Address Capable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R 
 - Dbi2: R */
#define PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_64_BIT_ADDR_CAP_BitAddressOffset 23
#define PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_64_BIT_ADDR_CAP_RegisterSize 1

/* Register PCI_MSI_CAP_ID_NEXT_CTRL_REG field PCI_PVM_SUPPORT */
/* MSI Per Vector Masking Capable.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>. */
#define PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_PVM_SUPPORT_BitAddressOffset 24
#define PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_PVM_SUPPORT_RegisterSize 1

/* Register PCI_MSI_CAP_ID_NEXT_CTRL_REG field RSVDP_25 */
/* Reserved for future use. */
#define PCI_MSI_CAP_ID_NEXT_CTRL_REG_RSVDP_25_BitAddressOffset 25
#define PCI_MSI_CAP_ID_NEXT_CTRL_REG_RSVDP_25_RegisterSize 7

/* End of Register Definition for PCI_MSI_CAP_ID_NEXT_CTRL_REG */

/* Register MSI_CAP_OFF_04H_REG */
/* MSI Message Lower Address Register.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define MSI_CAP_OFF_04H_REG (PF0_MSI_CAP_BaseAddress + 0x4)
#define MSI_CAP_OFF_04H_REG_RegisterSize 32
#define MSI_CAP_OFF_04H_REG_RegisterResetValue 0x0
#define MSI_CAP_OFF_04H_REG_RegisterResetMask 0xffffffff

/* Register Field information for MSI_CAP_OFF_04H_REG */

/* Register MSI_CAP_OFF_04H_REG field RSVDP_0 */
/* Reserved for future use. */
#define MSI_CAP_OFF_04H_REG_RSVDP_0_BitAddressOffset 0
#define MSI_CAP_OFF_04H_REG_RSVDP_0_RegisterSize 2

/* Register MSI_CAP_OFF_04H_REG field PCI_MSI_CAP_OFF_04H */
/* MSI Message Lower Address Field.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R/W 
 - Dbi: R/W 
 - Dbi2: R/W<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && MSI_CAP_ENABLE) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && !MSI_CAP_ENABLE) ?  R: (CX_MEMORY_MAP_VIEW==1 && MSI_CAP_ENABLE) ?  R/W : (CX_MEMORY_MAP_VIEW==1 && !MSI_CAP_ENABLE ) ? R: (MSI_CAP_ENABLE) ? R/W : R</ct> */
#define MSI_CAP_OFF_04H_REG_PCI_MSI_CAP_OFF_04H_BitAddressOffset 2
#define MSI_CAP_OFF_04H_REG_PCI_MSI_CAP_OFF_04H_RegisterSize 30

/* End of Register Definition for MSI_CAP_OFF_04H_REG */

/* Register MSI_CAP_OFF_08H_REG */
/* For a 32 bit MSI Message, this register contains Data. For 64 bit it contains the Upper Address.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define MSI_CAP_OFF_08H_REG (PF0_MSI_CAP_BaseAddress + 0x8)
#define MSI_CAP_OFF_08H_REG_RegisterSize 32
#define MSI_CAP_OFF_08H_REG_RegisterResetValue 0x0
#define MSI_CAP_OFF_08H_REG_RegisterResetMask 0xffffffff

/* Register Field information for MSI_CAP_OFF_08H_REG */

/* Register MSI_CAP_OFF_08H_REG field PCI_MSI_CAP_OFF_08H */
/* For a 32-bit MSI Message, this field contains Data. For 64-bit it contains lower 16 bits of the Upper Address.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: PCI_MSI_64_BIT_ADDR_CAP ? R/W : R 
 - Dbi: PCI_MSI_64_BIT_ADDR_CAP ? R/W : R 
 - Dbi2: PCI_MSI_64_BIT_ADDR_CAP ? R/W : R<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && MSI_64_EN) ?  R/W : (CX_MEMORY_MAP_VIEW==0 ) ?  R: (CX_MEMORY_MAP_VIEW==1 &&  MSI_64_EN  ) ?  R/W : (CX_MEMORY_MAP_VIEW==1 ) ? R: ( MSI_64_EN) ? R/W : R</ct> */
#define MSI_CAP_OFF_08H_REG_PCI_MSI_CAP_OFF_08H_BitAddressOffset 0
#define MSI_CAP_OFF_08H_REG_PCI_MSI_CAP_OFF_08H_RegisterSize 16

/* Register MSI_CAP_OFF_08H_REG field PCI_MSI_CAP_OFF_0AH */
/* For a 32 bit MSI Message, this is reserved. For 64-bit it contains upper 16 bits of the Upper Address.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: PCI_MSI_64_BIT_ADDR_CAP ? R/W : R 
 - Dbi: PCI_MSI_64_BIT_ADDR_CAP ? R/W : R 
 - Dbi2: PCI_MSI_64_BIT_ADDR_CAP ? R/W : R<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && MSI_64_EN) ?  R/W : (CX_MEMORY_MAP_VIEW==0 ) ?  R: (CX_MEMORY_MAP_VIEW==1 &&  MSI_64_EN  ) ?  R/W : (CX_MEMORY_MAP_VIEW==1 ) ? R: ( MSI_64_EN) ? R/W : R</ct> */
#define MSI_CAP_OFF_08H_REG_PCI_MSI_CAP_OFF_0AH_BitAddressOffset 16
#define MSI_CAP_OFF_08H_REG_PCI_MSI_CAP_OFF_0AH_RegisterSize 16

/* End of Register Definition for MSI_CAP_OFF_08H_REG */

/* Register MSI_CAP_OFF_0CH_REG */
/* For a 64 bit MSI Message, this register contains Data. For 32 bit, it contains Mask Bits if PVM enabled.
For a description of this standard PCIe register, see the <i>PCI Express Base Specification 3.1</i>. */
#define MSI_CAP_OFF_0CH_REG (PF0_MSI_CAP_BaseAddress + 0xc)
#define MSI_CAP_OFF_0CH_REG_RegisterSize 32
#define MSI_CAP_OFF_0CH_REG_RegisterResetValue 0x0
#define MSI_CAP_OFF_0CH_REG_RegisterResetMask 0xffffffff

/* Register Field information for MSI_CAP_OFF_0CH_REG */

/* Register MSI_CAP_OFF_0CH_REG field PCI_MSI_CAP_OFF_0CH */
/* For a 64-bit MSI Message, this field contains Data. For 32-bit, it contains the lower Mask Bits if PVM is enabled.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: PCI_MSI_64_BIT_ADDR_CAP || MSI_PVM_EN ? R/W : R 
 - Dbi: PCI_MSI_64_BIT_ADDR_CAP || MSI_PVM_EN ? R/W : R 
 - Dbi2: PCI_MSI_64_BIT_ADDR_CAP || MSI_PVM_EN ? R/W : R<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && (MSI_64_EN ||MSI_PVM_EN) ) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && !MSI_CAP_ENABLE) ?  R: (CX_MEMORY_MAP_VIEW==1 && (MSI_64_EN || MSI_PVM_EN) ) ?  R/W : (CX_MEMORY_MAP_VIEW==1 && !MSI_CAP_ENABLE ) ? R: (MSI_64_EN ||MSI_PVM_EN) ? R/W : R</ct> */
#define MSI_CAP_OFF_0CH_REG_PCI_MSI_CAP_OFF_0CH_BitAddressOffset 0
#define MSI_CAP_OFF_0CH_REG_PCI_MSI_CAP_OFF_0CH_RegisterSize 16

/* Register MSI_CAP_OFF_0CH_REG field PCI_MSI_CAP_OFF_0EH */
/* For a 64-bit MSI Message, this field contains Data. For 32-bit, it contains the upper Mask Bits if PVM is enabled.
For a description of this standard PCIe register field, see the <i>PCI Express Base Specification 3.1</i>
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: !PCI_MSI_64_BIT_ADDR_CAP && MSI_PVM_EN ? R/W : R 
 - Dbi: !PCI_MSI_64_BIT_ADDR_CAP && MSI_PVM_EN ? R/W : R 
 - Dbi2: !PCI_MSI_64_BIT_ADDR_CAP && MSI_PVM_EN ? R/W : R<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && MSI_PVM_EN_VALUE && !MSI_64_EN) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && !MSI_CAP_ENABLE) ?  R: (CX_MEMORY_MAP_VIEW==1 && MSI_PVM_EN_VALUE && !MSI_64_EN) ?  R/W : (CX_MEMORY_MAP_VIEW==1 && !MSI_CAP_ENABLE ) ? R: (MSI_PVM_EN_VALUE && !MSI_64_EN) ? R/W : R</ct> */
#define MSI_CAP_OFF_0CH_REG_PCI_MSI_CAP_OFF_0EH_BitAddressOffset 16
#define MSI_CAP_OFF_0CH_REG_PCI_MSI_CAP_OFF_0EH_RegisterSize 16

/* End of Register Definition for MSI_CAP_OFF_0CH_REG */


/* Register ACK_LATENCY_TIMER_OFF */
/* Ack Latency Timer and Replay Timer Register. */
#define ACK_LATENCY_TIMER_OFF (PF0_PORT_LOGIC_BaseAddress + 0x0)
#define ACK_LATENCY_TIMER_OFF_RegisterSize 32
#define ACK_LATENCY_TIMER_OFF_RegisterResetValue 0x18460817
#define ACK_LATENCY_TIMER_OFF_RegisterResetMask 0xffffffff

/* Register Field information for ACK_LATENCY_TIMER_OFF */

/* Register ACK_LATENCY_TIMER_OFF field ROUND_TRIP_LATENCY_TIME_LIMIT */
/* Ack Latency Timer Limit. The Ack latency timer expires when it reaches this limit. For more details, see "Ack Scheduling".
You can modify the effective timer limit with the TIMER_MOD_ACK_NAK field of the TIMER_CTRL_MAX_FUNC_NUM_OFF register.
After reset, the core updates the default according to the Negotiated Link Width, Max_Payload_Size, and speed.
The value is determined from Tables 3-7, 3-8, and 3-9 of the PCIe 3.0 specification.
The limit must reflect the round trip latency from requester to completer.
If there is a change in the payload size or link width, the core will override any value that you have written to this register field, and reset the field back to the specification-defined value. It will not change the value in the TIMER_MOD_ACK_NAK field of the TIMER_CTRL_MAX_FUNC_NUM_OFF register. */
#define ACK_LATENCY_TIMER_OFF_ROUND_TRIP_LATENCY_TIME_LIMIT_BitAddressOffset 0
#define ACK_LATENCY_TIMER_OFF_ROUND_TRIP_LATENCY_TIME_LIMIT_RegisterSize 16

/* Register ACK_LATENCY_TIMER_OFF field REPLAY_TIME_LIMIT */
/* Replay Timer Limit. The replay timer expires when it reaches this limit. The core initiates a replay upon reception of a NAK or when the replay timer expires. For more details, see "Transmit Replay".
You can modify the effective timer limit with the TIMER_MOD_REPLAY_TIMER field of the TIMER_CTRL_MAX_FUNC_NUM_OFF register.
After reset, the core updates the default according to the Negotiated Link Width, Max_Payload_Size, and speed.
The value is determined from Tables 3-4, 3-5, and 3-6 of the PCIe 3.0 specification.
If there is a change in the payload size or link speed, the core will override any value that you have written to this register field, and reset the field back to the specification-defined value. It will not change the value in the TIMER_MOD_REPLAY_TIMER field of the TIMER_CTRL_MAX_FUNC_NUM_OFF register. */
#define ACK_LATENCY_TIMER_OFF_REPLAY_TIME_LIMIT_BitAddressOffset 16
#define ACK_LATENCY_TIMER_OFF_REPLAY_TIME_LIMIT_RegisterSize 16

/* End of Register Definition for ACK_LATENCY_TIMER_OFF */

/* Register VENDOR_SPEC_DLLP_OFF */
/* Vendor Specific DLLP Register. */
#define VENDOR_SPEC_DLLP_OFF (PF0_PORT_LOGIC_BaseAddress + 0x4)
#define VENDOR_SPEC_DLLP_OFF_RegisterSize 32
#define VENDOR_SPEC_DLLP_OFF_RegisterResetValue 0xffffffff
#define VENDOR_SPEC_DLLP_OFF_RegisterResetMask 0xffffffff

/* Register Field information for VENDOR_SPEC_DLLP_OFF */

/* Register VENDOR_SPEC_DLLP_OFF field VENDOR_SPEC_DLLP */
/* Vendor Specific DLLP Register. Used to send a specific PCI Express DLLP. Your application writes the 8-bit DLLP Type and 24-bits of Payload data into this register, then sets bit "0" of the "Port Link Control Register" to send the DLLP. */
#define VENDOR_SPEC_DLLP_OFF_VENDOR_SPEC_DLLP_BitAddressOffset 0
#define VENDOR_SPEC_DLLP_OFF_VENDOR_SPEC_DLLP_RegisterSize 32

/* End of Register Definition for VENDOR_SPEC_DLLP_OFF */

/* Register PORT_FORCE_OFF */
/* Port Force Link Register. */
#define PORT_FORCE_OFF (PF0_PORT_LOGIC_BaseAddress + 0x8)
#define PORT_FORCE_OFF_RegisterSize 32
#define PORT_FORCE_OFF_RegisterResetValue 0x7000004
#define PORT_FORCE_OFF_RegisterResetMask 0xffffffff

/* Register Field information for PORT_FORCE_OFF */

/* Register PORT_FORCE_OFF field LINK_NUM */
/* Link Number. Not used for endpoint. Not used for M-PCIe.
<br><i>Note</i>: This register field is sticky. */
#define PORT_FORCE_OFF_LINK_NUM_BitAddressOffset 0
#define PORT_FORCE_OFF_LINK_NUM_RegisterSize 8

/* Register PORT_FORCE_OFF field FORCED_LTSSM */
/* Forced Link Command. The link command that the core is forced to transmit when you set FORCE_EN bit (Force Link).
Link command encoding is defined by the ltssm_cmd variable in workspace/src/Layer1/smlh_ltssm.v.
<br><i>Note</i>: This register field is sticky. */
#define PORT_FORCE_OFF_FORCED_LTSSM_BitAddressOffset 8
#define PORT_FORCE_OFF_FORCED_LTSSM_RegisterSize 4

/* Register PORT_FORCE_OFF field RSVDP_12 */
/* Reserved for future use. */
#define PORT_FORCE_OFF_RSVDP_12_BitAddressOffset 12
#define PORT_FORCE_OFF_RSVDP_12_RegisterSize 3

/* Register PORT_FORCE_OFF field FORCE_EN */
/* Force Link. The core supports a testing and debug capability to allow your software to force the LTSSM state machine into a specific state, and to force the core to transmit a specific Link Command. Asserting this bit triggers the following actions:
 - Forces the LTSSM to the state specified by the Forced LTSSM State field.
 - Forces the core to transmit the command specified by the Forced Link Command field.
This is a self-clearing register field. Reading from this register field always returns a "0". */
#define PORT_FORCE_OFF_FORCE_EN_BitAddressOffset 15
#define PORT_FORCE_OFF_FORCE_EN_RegisterSize 1

/* Register PORT_FORCE_OFF field LINK_STATE */
/* Forced LTSSM State. The LTSSM state that the core is forced to when you set the FORCE_EN bit (Force Link).
LTSSM state encoding is defined by the lts_state variable in workspace/src/Layer1/smlh_ltssm.v.
<br><i>Note</i>: This register field is sticky. */
#define PORT_FORCE_OFF_LINK_STATE_BitAddressOffset 16
#define PORT_FORCE_OFF_LINK_STATE_RegisterSize 6

/* Register PORT_FORCE_OFF field RSVDP_22 */
/* Reserved for future use. */
#define PORT_FORCE_OFF_RSVDP_22_BitAddressOffset 22
#define PORT_FORCE_OFF_RSVDP_22_RegisterSize 2

/* Register PORT_FORCE_OFF field CPL_SENT_COUNT */
/* Low Power Entrance Count. The Power Management state waits for this many clock cycles for the associated completion of a CfgWr to D-state register to go low-power. This register is intended for applications that do not let the core handle a completion for configuration request to the PMCSCR register.
Not used in downstream ports.
<br><i>Note</i>: This register field is sticky. */
#define PORT_FORCE_OFF_CPL_SENT_COUNT_BitAddressOffset 24
#define PORT_FORCE_OFF_CPL_SENT_COUNT_RegisterSize 8

/* End of Register Definition for PORT_FORCE_OFF */

/* Register ACK_F_ASPM_CTRL_OFF */
/* Ack Frequency and L0-L1 ASPM Control Register. */
#define ACK_F_ASPM_CTRL_OFF (PF0_PORT_LOGIC_BaseAddress + 0xc)
#define ACK_F_ASPM_CTRL_OFF_RegisterSize 32
#define ACK_F_ASPM_CTRL_OFF_RegisterResetValue 0x1b0f0f00
#define ACK_F_ASPM_CTRL_OFF_RegisterResetMask 0xffffffff

/* Register Field information for ACK_F_ASPM_CTRL_OFF */

/* Register ACK_F_ASPM_CTRL_OFF field ACK_FREQ */
/* Ack Frequency. The core accumulates the number of pending ACKs specified here (up to 255) before sending an ACK DLLP.
 - 0: Indicates that this Ack frequency control feature is turned off. The core schedules a low-priority ACK DLLP for every TLP that it receives.
 - 1-255: Indicates that the core will schedule a high-priority ACK after receiving this number of TLPs. It might schedule the ACK before receiving this number of TLPs, but never later.
For a typical system, you do not have to modify the default setting. For more details, see "ACK/NAK Scheduling".
<br><i>Note</i>: This register field is sticky. */
#define ACK_F_ASPM_CTRL_OFF_ACK_FREQ_BitAddressOffset 0
#define ACK_F_ASPM_CTRL_OFF_ACK_FREQ_RegisterSize 8

/* Register ACK_F_ASPM_CTRL_OFF field ACK_N_FTS */
/* N_FTS. The number of Fast Training Sequence ordered sets to be transmitted when transitioning from L0s to L0. The maximum number of FTS ordered-sets that a component can request is 255.
The core does not support a value of zero; a value of zero can cause the LTSSM to go into the recovery state when exiting from L0s.
This field is reserved (fixed to '0') for M-PCIe.
<br><i>Note</i>: This register field is sticky. */
#define ACK_F_ASPM_CTRL_OFF_ACK_N_FTS_BitAddressOffset 8
#define ACK_F_ASPM_CTRL_OFF_ACK_N_FTS_RegisterSize 8

/* Register ACK_F_ASPM_CTRL_OFF field COMMON_CLK_N_FTS */
/* Common Clock N_FTS. This is the N_FTS when common clock is used.
The number of Fast Training Sequence ordered sets to be transmitted when transitioning from L0s to L0. The maximum number of FTS ordered-sets that a component can request is 255. This field is only writable (sticky) when all of the following configuration parameter equations are true:
 - CX_NFTS !=CX_COMM_NFTS
 - DEFAULT_L0S_EXIT_LATENCY !=DEFAULT_COMM_L0S_EXIT_LATENCY
 - DEFAULT_L1_EXIT_LATENCY !=DEFAULT_COMM_L1_EXIT_LATENCY
The core does not support a value of zero; a value of zero can cause the LTSSM to go into the recovery state when exiting from L0s.
This field is reserved (fixed to '0') for M-PCIe.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: R 
 - Dbi2: R<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && CX_COMM_CLK_EN) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && !CX_COMM_CLK_EN) ?  R: (CX_MEMORY_MAP_VIEW==1 &&  CX_COMM_CLK_EN) ? R/W:  (CX_MEMORY_MAP_VIEW==1 &&  !CX_COMM_CLK_EN) ? R: (CX_COMM_CLK_EN)? R/W:R</ct> */
#define ACK_F_ASPM_CTRL_OFF_COMMON_CLK_N_FTS_BitAddressOffset 16
#define ACK_F_ASPM_CTRL_OFF_COMMON_CLK_N_FTS_RegisterSize 8

/* Register ACK_F_ASPM_CTRL_OFF field L0S_ENTRANCE_LATENCY */
/* L0s Entrance Latency. Values correspond to:
 - 000: 1 us
 - 001: 2 us
 - 010: 3 us
 - 011: 4 us
 - 100: 5 us
 - 101: 6 us
 - 110 or 111: 7 us
This field is applicable to STALL while in L0 for M-PCIe.
<br><i>Note</i>: This register field is sticky. */
#define ACK_F_ASPM_CTRL_OFF_L0S_ENTRANCE_LATENCY_BitAddressOffset 24
#define ACK_F_ASPM_CTRL_OFF_L0S_ENTRANCE_LATENCY_RegisterSize 3

/* Register ACK_F_ASPM_CTRL_OFF field L1_ENTRANCE_LATENCY */
/* L1 Entrance Latency. Value range is:
 - 000: 1 us
 - 001: 2 us
 - 010: 4 us
 - 011: 8 us
 - 100: 16 us
 - 101: 32 us
 - 110 or 111: 64 us
<i>Note</i>: Programming this timer with a value greater that 32us has no effect unless extended sync is used, or all of the credits are infinite.
<br><i>Note</i>: This register field is sticky. */
#define ACK_F_ASPM_CTRL_OFF_L1_ENTRANCE_LATENCY_BitAddressOffset 27
#define ACK_F_ASPM_CTRL_OFF_L1_ENTRANCE_LATENCY_RegisterSize 3

/* Register ACK_F_ASPM_CTRL_OFF field ENTER_ASPM */
/* Enter ASPM L1 Without Receive In L0s. Allow core to enter ASPM L1 even when link partner did not go to L0s (receive is not in L0s).
When not set, core goes to ASPM L1 only after idle period during which both receive and transmit are in L0s.
<br><i>Note</i>: This register field is sticky. */
#define ACK_F_ASPM_CTRL_OFF_ENTER_ASPM_BitAddressOffset 30
#define ACK_F_ASPM_CTRL_OFF_ENTER_ASPM_RegisterSize 1

/* Register ACK_F_ASPM_CTRL_OFF field RSVDP_31 */
/* Reserved for future use. */
#define ACK_F_ASPM_CTRL_OFF_RSVDP_31_BitAddressOffset 31
#define ACK_F_ASPM_CTRL_OFF_RSVDP_31_RegisterSize 1

/* End of Register Definition for ACK_F_ASPM_CTRL_OFF */

/* Register PORT_LINK_CTRL_OFF */
/* Port Link Control Register. */
#define PORT_LINK_CTRL_OFF (PF0_PORT_LOGIC_BaseAddress + 0x10)
#define PORT_LINK_CTRL_OFF_RegisterSize 32
#define PORT_LINK_CTRL_OFF_RegisterResetValue 0x10120
#define PORT_LINK_CTRL_OFF_RegisterResetMask 0xffffffff

/* Register Field information for PORT_LINK_CTRL_OFF */

/* Register PORT_LINK_CTRL_OFF field VENDOR_SPECIFIC_DLLP_REQ */
/* Vendor Specific DLLP Request. When software writes a "1" to this bit, the core transmits the DLLP contained in the "Vendor Specific DLLP Register".
<br>Reading from this self-clearing register field always returns a "0". */
#define PORT_LINK_CTRL_OFF_VENDOR_SPECIFIC_DLLP_REQ_BitAddressOffset 0
#define PORT_LINK_CTRL_OFF_VENDOR_SPECIFIC_DLLP_REQ_RegisterSize 1

/* Register PORT_LINK_CTRL_OFF field SCRAMBLE_DISABLE */
/* Scramble Disable. Turns off data scrambling.
<br><i>Note</i>: This register field is sticky. */
#define PORT_LINK_CTRL_OFF_SCRAMBLE_DISABLE_BitAddressOffset 1
#define PORT_LINK_CTRL_OFF_SCRAMBLE_DISABLE_RegisterSize 1

/* Register PORT_LINK_CTRL_OFF field LOOPBACK_ENABLE */
/* Loopback Enable. Turns on loopback. For more details, see "Loopback".
For M-PCIe, to force the master to enter Digital Loopback mode, you must set this field to "1" during Configuration.start state(initial discovery/configuration).
M-PCIe doesn't support loopback mode from L0 state - only from Configuration.start.
<br><i>Note</i>: This register field is sticky. */
#define PORT_LINK_CTRL_OFF_LOOPBACK_ENABLE_BitAddressOffset 2
#define PORT_LINK_CTRL_OFF_LOOPBACK_ENABLE_RegisterSize 1

/* Register PORT_LINK_CTRL_OFF field RESET_ASSERT */
/* Reset Assert. Triggers a recovery and forces the LTSSM to the hot reset state (downstream port only).
<br><i>Note</i>: This register field is sticky. */
#define PORT_LINK_CTRL_OFF_RESET_ASSERT_BitAddressOffset 3
#define PORT_LINK_CTRL_OFF_RESET_ASSERT_RegisterSize 1

/* Register PORT_LINK_CTRL_OFF field RSVDP_4 */
/* Reserved for future use. */
#define PORT_LINK_CTRL_OFF_RSVDP_4_BitAddressOffset 4
#define PORT_LINK_CTRL_OFF_RSVDP_4_RegisterSize 1

/* Register PORT_LINK_CTRL_OFF field DLL_LINK_EN */
/* DLL Link Enable. Enables link initialization. When DLL Link Enable =0, the core does not transmit InitFC DLLPs and does not establish a link.
<br><i>Note</i>: This register field is sticky. */
#define PORT_LINK_CTRL_OFF_DLL_LINK_EN_BitAddressOffset 5
#define PORT_LINK_CTRL_OFF_DLL_LINK_EN_RegisterSize 1

/* Register PORT_LINK_CTRL_OFF field LINK_DISABLE */
/* This is an internally reserved field. Do not use.
<br><i>Note</i>: This register field is sticky. */
#define PORT_LINK_CTRL_OFF_LINK_DISABLE_BitAddressOffset 6
#define PORT_LINK_CTRL_OFF_LINK_DISABLE_RegisterSize 1

/* Register PORT_LINK_CTRL_OFF field FAST_LINK_MODE */
/* Fast Link Mode. Sets all internal timers to Fast Mode for speeding up simulation. Forces the LTSSM training (link initialization) to use shorter time-outs and to link up faster. The scaling factor is 1024 for all internal timers.
Fast Link Mode can also be activated by setting the diag_ctrl_bus[2] pin to "1". For more details, see "SII Signals: Diagnostic Control".
For M-PCIe, this field also affects Remain Hibern8 Time, Minimum Activate Time, and RRAP timeout. If this bit is set to '1', tRRAPInitiatorResponse is set to 1.88 ms(60 ms/32).
<br><i>Note</i>: This register field is sticky. */
#define PORT_LINK_CTRL_OFF_FAST_LINK_MODE_BitAddressOffset 7
#define PORT_LINK_CTRL_OFF_FAST_LINK_MODE_RegisterSize 1

/* Register PORT_LINK_CTRL_OFF field LINK_RATE */
/* This is an internally reserved field. Do not use.
<br><i>Note</i>: This register field is sticky. */
#define PORT_LINK_CTRL_OFF_LINK_RATE_BitAddressOffset 8
#define PORT_LINK_CTRL_OFF_LINK_RATE_RegisterSize 4

/* Register PORT_LINK_CTRL_OFF field RSVDP_12 */
/* Reserved for future use. */
#define PORT_LINK_CTRL_OFF_RSVDP_12_BitAddressOffset 12
#define PORT_LINK_CTRL_OFF_RSVDP_12_RegisterSize 4

/* Register PORT_LINK_CTRL_OFF field LINK_CAPABLE */
/* Link Mode Enable. Sets the number of lanes in the link that you want to connect to the link partner. When you have unused lanes in your system, then you must change the value in this register to reflect the number of lanes. You must also change the value in the "Predetermined Number of Lanes" field of the "Link Width and Speed Change Control Register". For more information, see "How to Tie Off Unused Lanes". For information on upsizing and downsizing the link width, see "Link Establishment".
 - 000001: x1
 - 000011: x2
 - 000111: x4
 - 001111: x8
 - 011111: x16
 - 111111: x32 (not supported)
This field is reserved (fixed to '0') for M-PCIe.
<br><i>Note</i>: This register field is sticky. */
#define PORT_LINK_CTRL_OFF_LINK_CAPABLE_BitAddressOffset 16
#define PORT_LINK_CTRL_OFF_LINK_CAPABLE_RegisterSize 6

/* Register PORT_LINK_CTRL_OFF field BEACON_ENABLE */
/* This is an internally reserved field. Do not use.
<br><i>Note</i>: This register field is sticky. */
#define PORT_LINK_CTRL_OFF_BEACON_ENABLE_BitAddressOffset 24
#define PORT_LINK_CTRL_OFF_BEACON_ENABLE_RegisterSize 1

/* Register PORT_LINK_CTRL_OFF field CORRUPT_LCRC_ENABLE */
/* This is an internally reserved field. Do not use.
<br><i>Note</i>: This register field is sticky. */
#define PORT_LINK_CTRL_OFF_CORRUPT_LCRC_ENABLE_BitAddressOffset 25
#define PORT_LINK_CTRL_OFF_CORRUPT_LCRC_ENABLE_RegisterSize 1

/* Register PORT_LINK_CTRL_OFF field EXTENDED_SYNCH */
/* This is an internally reserved field. Do not use.
<br><i>Note</i>: This register field is sticky. */
#define PORT_LINK_CTRL_OFF_EXTENDED_SYNCH_BitAddressOffset 26
#define PORT_LINK_CTRL_OFF_EXTENDED_SYNCH_RegisterSize 1

/* Register PORT_LINK_CTRL_OFF field TRANSMIT_LANE_REVERSALE_ENABLE */
/* This is an internally reserved field. Do not use.
<br><i>Note</i>: This register field is sticky. */
#define PORT_LINK_CTRL_OFF_TRANSMIT_LANE_REVERSALE_ENABLE_BitAddressOffset 27
#define PORT_LINK_CTRL_OFF_TRANSMIT_LANE_REVERSALE_ENABLE_RegisterSize 1

/* Register PORT_LINK_CTRL_OFF field RSVDP_28 */
/* Reserved for future use. */
#define PORT_LINK_CTRL_OFF_RSVDP_28_BitAddressOffset 28
#define PORT_LINK_CTRL_OFF_RSVDP_28_RegisterSize 4

/* End of Register Definition for PORT_LINK_CTRL_OFF */

/* Register LANE_SKEW_OFF */
/* Lane Skew Register. */
#define LANE_SKEW_OFF (PF0_PORT_LOGIC_BaseAddress + 0x14)
#define LANE_SKEW_OFF_RegisterSize 32
#define LANE_SKEW_OFF_RegisterResetValue 0x0
#define LANE_SKEW_OFF_RegisterResetMask 0xffffffff

/* Register Field information for LANE_SKEW_OFF */

/* Register LANE_SKEW_OFF field INSERT_LANE_SKEW */
/* Insert Lane Skew for Transmit (not supported for x16). Optional feature that causes the core to insert skew between Lanes for test purposes. There are three bits per Lane. The value is in units of one symbol time. For example, the value 010b for a Lane forces a skew of two symbol times for that Lane. The maximum skew value for any Lane is 5 symbol times.
<br><i>Note</i>: This register field is sticky. */
#define LANE_SKEW_OFF_INSERT_LANE_SKEW_BitAddressOffset 0
#define LANE_SKEW_OFF_INSERT_LANE_SKEW_RegisterSize 24

/* Register LANE_SKEW_OFF field FLOW_CTRL_DISABLE */
/* Flow Control Disable. Prevents the core from sending FC DLLPs.
<br><i>Note</i>: This register field is sticky. */
#define LANE_SKEW_OFF_FLOW_CTRL_DISABLE_BitAddressOffset 24
#define LANE_SKEW_OFF_FLOW_CTRL_DISABLE_RegisterSize 1

/* Register LANE_SKEW_OFF field ACK_NAK_DISABLE */
/* Ack/Nak Disable. Prevents the core from sending ACK and NAK DLLPs.
<br><i>Note</i>: This register field is sticky. */
#define LANE_SKEW_OFF_ACK_NAK_DISABLE_BitAddressOffset 25
#define LANE_SKEW_OFF_ACK_NAK_DISABLE_RegisterSize 1

/* Register LANE_SKEW_OFF field RSVDP_26 */
/* Reserved for future use. */
#define LANE_SKEW_OFF_RSVDP_26_BitAddressOffset 26
#define LANE_SKEW_OFF_RSVDP_26_RegisterSize 5

/* Register LANE_SKEW_OFF field DISABLE_LANE_TO_LANE_DESKEW */
/* Disable Lane-to-Lane Deskew. Causes the core to disable the internal Lane-to-Lane deskew logic.
<br><i>Note</i>: This register field is sticky. */
#define LANE_SKEW_OFF_DISABLE_LANE_TO_LANE_DESKEW_BitAddressOffset 31
#define LANE_SKEW_OFF_DISABLE_LANE_TO_LANE_DESKEW_RegisterSize 1

/* End of Register Definition for LANE_SKEW_OFF */

/* Register TIMER_CTRL_MAX_FUNC_NUM_OFF */
/* Timer Control and Max Function Number Register. */
#define TIMER_CTRL_MAX_FUNC_NUM_OFF (PF0_PORT_LOGIC_BaseAddress + 0x18)
#define TIMER_CTRL_MAX_FUNC_NUM_OFF_RegisterSize 32
#define TIMER_CTRL_MAX_FUNC_NUM_OFF_RegisterResetValue 0x8000
#define TIMER_CTRL_MAX_FUNC_NUM_OFF_RegisterResetMask 0xffffffff

/* Register Field information for TIMER_CTRL_MAX_FUNC_NUM_OFF */

/* Register TIMER_CTRL_MAX_FUNC_NUM_OFF field MAX_FUNC_NUM */
/* Maximum function number that can be used in a request. Configuration requests targeted at function numbers above this value are returned with UR (unsupported request).
<br><i>Note</i>: This register field is sticky. */
#define TIMER_CTRL_MAX_FUNC_NUM_OFF_MAX_FUNC_NUM_BitAddressOffset 0
#define TIMER_CTRL_MAX_FUNC_NUM_OFF_MAX_FUNC_NUM_RegisterSize 8

/* Register TIMER_CTRL_MAX_FUNC_NUM_OFF field RSVDP_8 */
/* Reserved for future use. */
#define TIMER_CTRL_MAX_FUNC_NUM_OFF_RSVDP_8_BitAddressOffset 8
#define TIMER_CTRL_MAX_FUNC_NUM_OFF_RSVDP_8_RegisterSize 6

/* Register TIMER_CTRL_MAX_FUNC_NUM_OFF field TIMER_MOD_REPLAY_TIMER */
/* Replay Timer Limit Modifier. Increases the time-out value for the replay timer in increments of 64 clock cycles at Gen1 or Gen2 speed, and in increments of 256 clock cycles at Gen3 speed. A value of "0" represents no modification to the timer limit. For more details, see the REPLAY_TIME_LIMIT field of the ACK_LATENCY_TIMER_OFF register.
At Gen3 speed, the core automatically changes the value of this field to DEFAULT_GEN3_REPLAY_ADJ.
For M-PCIe, this field increases the time-out value for the replay timer in increments of 64 clock cycles at HS-Gear1, HS-Gear2, or HS-Gear3 speed.
<br><i>Note</i>: This register field is sticky. */
#define TIMER_CTRL_MAX_FUNC_NUM_OFF_TIMER_MOD_REPLAY_TIMER_BitAddressOffset 14
#define TIMER_CTRL_MAX_FUNC_NUM_OFF_TIMER_MOD_REPLAY_TIMER_RegisterSize 5

/* Register TIMER_CTRL_MAX_FUNC_NUM_OFF field TIMER_MOD_ACK_NAK */
/* Ack Latency Timer Modifier. Increases the timer value for the Ack latency timer in increments of 64 clock cycles. A value of "0" represents no modification to the timer value. For more details, see the ROUND_TRIP_LATENCY_TIME_LIMIT field of the ACK_LATENCY_TIMER_OFF register.
<br><i>Note</i>: This register field is sticky. */
#define TIMER_CTRL_MAX_FUNC_NUM_OFF_TIMER_MOD_ACK_NAK_BitAddressOffset 19
#define TIMER_CTRL_MAX_FUNC_NUM_OFF_TIMER_MOD_ACK_NAK_RegisterSize 5

/* Register TIMER_CTRL_MAX_FUNC_NUM_OFF field UPDATE_FREQ_TIMER */
/* This is an internally reserved field. Do not use.
<br><i>Note</i>: This register field is sticky. */
#define TIMER_CTRL_MAX_FUNC_NUM_OFF_UPDATE_FREQ_TIMER_BitAddressOffset 24
#define TIMER_CTRL_MAX_FUNC_NUM_OFF_UPDATE_FREQ_TIMER_RegisterSize 5

/* Register TIMER_CTRL_MAX_FUNC_NUM_OFF field RSVDP_29 */
/* Reserved for future use. */
#define TIMER_CTRL_MAX_FUNC_NUM_OFF_RSVDP_29_BitAddressOffset 29
#define TIMER_CTRL_MAX_FUNC_NUM_OFF_RSVDP_29_RegisterSize 3

/* End of Register Definition for TIMER_CTRL_MAX_FUNC_NUM_OFF */

/* Register SYMBOL_TIMER_FILTER_1_OFF */
/* Symbol Timer Register and Filter Mask 1 Register. The Filter Mask 1 Register modifies the RADM filtering and error handling rules. For more details, see the "Receive Filtering" section. In each case, '0' applies the associated filtering rule and '1' masks the associated filtering rule. */
#define SYMBOL_TIMER_FILTER_1_OFF (PF0_PORT_LOGIC_BaseAddress + 0x1c)
#define SYMBOL_TIMER_FILTER_1_OFF_RegisterSize 32
#define SYMBOL_TIMER_FILTER_1_OFF_RegisterResetValue 0x280
#define SYMBOL_TIMER_FILTER_1_OFF_RegisterResetMask 0xffffffff

/* Register Field information for SYMBOL_TIMER_FILTER_1_OFF */

/* Register SYMBOL_TIMER_FILTER_1_OFF field SKP_INT_VAL */
/* SKP Interval Value. The number of symbol times to wait between transmitting SKP ordered sets. Note that the core actually waits the number of symbol times in this register plus 1 between transmitting SKP ordered sets. Your application must program this register accordingly. For example, if 1536 were programmed into this register (in a 250 MHz core), then the core actually transmits SKP ordered sets once every 1537 symbol times.
The value programmed to this register is actually clock ticks and not symbol times. In a 125 MHz core, programming the value programmed to this register should be scaled down by a factor of 2 (because one clock tick = two symbol times in this case).
<br><i>Note:</i> This value is not used at Gen3 speed; the skip interval is hardcoded to 370 blocks.
<br><i>Note</i>: This register field is sticky. */
#define SYMBOL_TIMER_FILTER_1_OFF_SKP_INT_VAL_BitAddressOffset 0
#define SYMBOL_TIMER_FILTER_1_OFF_SKP_INT_VAL_RegisterSize 11

/* Register SYMBOL_TIMER_FILTER_1_OFF field EIDLE_TIMER */
/* This is an internally reserved field. Do not use.
<br><i>Note</i>: This register field is sticky. */
#define SYMBOL_TIMER_FILTER_1_OFF_EIDLE_TIMER_BitAddressOffset 11
#define SYMBOL_TIMER_FILTER_1_OFF_EIDLE_TIMER_RegisterSize 4

/* Register SYMBOL_TIMER_FILTER_1_OFF field DISABLE_FC_WD_TIMER */
/* Disable FC Watchdog Timer.
<br><i>Note</i>: This register field is sticky. */
#define SYMBOL_TIMER_FILTER_1_OFF_DISABLE_FC_WD_TIMER_BitAddressOffset 15
#define SYMBOL_TIMER_FILTER_1_OFF_DISABLE_FC_WD_TIMER_RegisterSize 1

/* Register SYMBOL_TIMER_FILTER_1_OFF field MASK_RADM_1 */
/* Filter Mask 1. The Filter Mask 1 Register modifies the RADM filtering and error handling rules. For more details, see the "Receive Filtering" section. In each case, '0' applies the associated filtering rule and '1' masks the associated filtering rule.
<br>[31]: CX_FLT_MASK_RC_CFG_DISCARD
 - 0: For RADM RC filter to not allow CFG transaction being received
 - 1: For RADM RC filter to allow CFG transaction being received
[30]: CX_FLT_MASK_RC_IO_DISCARD
 - 0: For RADM RC filter to not allow IO transaction being received
 - 1: For RADM RC filter to allow IO transaction being received
[29]: CX_FLT_MASK_MSG_DROP
 - 0: Drop MSG TLP (except for Vendor MSG). Send decoded message on the SII.
 - 1: Do not Drop MSG (except for Vendor MSG). Send message TLPs to your application on TRGT1 and send decoded message on the SII.
 - The default for this bit is the inverse of FLT_DROP_MSG. That is, if FLT_DROP_MSG =1, then the default of this bit is "0" (drop message TLPs). This bit only controls message TLPs other than Vendor MSGs. Vendor MSGs are controlled by Filter Mask Register 2, bits [1:0]. <br>The core never passes ATS Invalidate messages to the SII interface regardless of this filter rule setting. The core passes all ATS Invalidate messages to TRGT1 (or AHB/AXI bridge master), as they are too big for the SII.
[28]: CX_FLT_MASK_CPL_ECRC_DISCARD
 - Only used when completion queue is advertised with infinite credits and is in store-and-forward mode.
 - 0: Discard completions with ECRC errors
 - 1: Allow completions with ECRC errors to be passed up
 - Reserved field for SW.
[27]: CX_FLT_MASK_ECRC_DISCARD
 - 0: Discard TLPs with ECRC errors
 - 1: Allow TLPs with ECRC errors to be passed up
[26]: CX_FLT_MASK_CPL_LEN_MATCH
 - 0: Enforce length match for completions; a violation results in cpl_abort, and possibly AER of unexp_cpl_err
 - 1: MASK length match for completions
[25]: CX_FLT_MASK_CPL_ATTR_MATCH
 - 0: Enforce attribute match for completions; a violation results in a malformed TLP error, and possibly AER of unexp_cpl_err, cpl_rcvd_ur, cpl_rcvd_ca
 - 1: Mask attribute match for completions
[24]: CX_FLT_MASK_CPL_TC_MATCH
 - 0: Enforce Traffic Class match for completions; a violation results in a malformed TLP error, and possibly AER of unexp_cpl_err, cpl_rcvd_ur, cpl_rcvd_ca
 - 1: Mask Traffic Class match for completions
[23]: CX_FLT_MASK_CPL_FUNC_MATCH
 - 0: Enforce function match for completions; a violation results in cpl_abort, and possibly AER of unexp_cpl_err, cpl_rcvd_ur, cpl_rcvd_ca
 - 1: Mask function match for completions
[22]: CX_FLT_MASK_CPL_REQID_MATCH
 - 0: Enforce Req. Id match for completions; a violation result in cpl_abort, and possibly AER of unexp_cpl_err, cpl_rcvd_ur, cpl_rcvd_ca
 - 1: Mask Req. Id match for completions
[21]: CX_FLT_MASK_CPL_TAGERR_MATCH
 - 0: Enforce Tag Error Rules for completions; a violation result in cpl_abort, and possibly AER of unexp_cpl_err, cpl_rcvd_ur, cpl_rcvd_ca
 - 1: Mask Tag Error Rules for completions
[20]: CX_FLT_MASK_LOCKED_RD_AS_UR
 - 0: Treat locked Read TLPs as UR for EP; Supported for RC
 - 1: Treat locked Read TLPs as Supported for EP; UR for RC
[19]: CX_FLT_MASK_CFG_TYPE1_RE_AS_UR
 - 0: Treat CFG type1 TLPs as UR for EP; Supported for RC
 - 1: Treat CFG type1 TLPs as Supported for EP; UR for RC
 - When CX_SRIOV_ENABLE is set then this bit is set to allow the filter to process Type 1 Config requests if the EP consumes more than one bus number.
[18]: CX_FLT_MASK_UR_OUTSIDE_BAR
 - 0: Treat out-of-bar TLPs as UR
 - 1: Do not treat out-of-bar TLPs as UR
[17]: CX_FLT_MASK_UR_POIS
 - 0: Treat poisoned request TLPs as UR
 - 1: Do not treat poisoned request TLPs as UR
 - The native core always passes poisoned completions to your application except when you are using the DMA read channel.
[16]: CX_FLT_MASK_UR_FUNC_MISMATCH
 - 0: Treat Function MisMatched TLPs as UR
 - 1: Do not treat Function MisMatched TLPs as UR
<i>Note</i>: This register field is sticky. */
#define SYMBOL_TIMER_FILTER_1_OFF_MASK_RADM_1_BitAddressOffset 16
#define SYMBOL_TIMER_FILTER_1_OFF_MASK_RADM_1_RegisterSize 16

/* End of Register Definition for SYMBOL_TIMER_FILTER_1_OFF */

/* Register FILTER_MASK_2_OFF */
/* Filter Mask 2 Register. This register modifies the RADM filtering and error handling rules. For more details, see the "Receive Filtering" section. In each case, '0' applies the associated filtering rule and '1' masks the associated filtering rule. */
#define FILTER_MASK_2_OFF (PF0_PORT_LOGIC_BaseAddress + 0x20)
#define FILTER_MASK_2_OFF_RegisterSize 32
#define FILTER_MASK_2_OFF_RegisterResetValue 0x0
#define FILTER_MASK_2_OFF_RegisterResetMask 0xffffffff

/* Register Field information for FILTER_MASK_2_OFF */

/* Register FILTER_MASK_2_OFF field MASK_RADM_2 */
/* Filter Mask 2. This field modifies the RADM filtering and error handling rules. For more details, see the "Receive Filtering" section. In each case, '0' applies the associated filtering rule and '1' masks the associated filtering rule.
<br>[31:5]: Reserved
<br>
[4]: CX_FLT_MASK_LN_VENMSG1_DROP
 - 0: Allow LN message to pass through
 - 1: Drop LN Messages silently
[3]: CX_FLT_MASK_HANDLE_FLUSH
 - 0: Disable core Filter to handle flush request
 - 1: Enable core Filter to handle flush request
[2]: CX_FLT_MASK_DABORT_4UCPL
 - 0: Enable DLLP abort for unexpected completion
 - 1: Do not enable DLLP abort for unexpected completion
[1]: CX_FLT_MASK_VENMSG1_DROP
 - 0: Vendor MSG Type 1 dropped silently
 - 1: Vendor MSG Type 1 not dropped
[0]: CX_FLT_MASK_VENMSG0_DROP
 - 0: Vendor MSG Type 0 dropped with UR error reporting
 - 1: Vendor MSG Type 0 not dropped
<i>Note</i>: This register field is sticky. */
#define FILTER_MASK_2_OFF_MASK_RADM_2_BitAddressOffset 0
#define FILTER_MASK_2_OFF_MASK_RADM_2_RegisterSize 32

/* End of Register Definition for FILTER_MASK_2_OFF */

/* Register AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF */
/* AMBA Multiple Outbound Decomposed NP SubRequests Control Register. */
#define AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF (PF0_PORT_LOGIC_BaseAddress + 0x24)
#define AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF_RegisterSize 32
#define AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF_RegisterResetValue 0x1
#define AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF_RegisterResetMask 0xffffffff

/* Register Field information for AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF */

/* Register AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF field OB_RD_SPLIT_BURST_EN */
/* Enable AMBA Multiple Outbound Decomposed NP SubRequests. This bit when set to "0" disables the possibility of having multiple outstanding non-posted requests that were derived from decomposition of an outbound AMBA request. For more details, see "Transaction Ordering" or "AXI Bridge Ordering" in the AHB and AXI chapters (respectively) of the <i>Databook</i>.
You should not clear this register unless your application master is requesting an amount of read data greater than Max_Read_Request_Size, and the remote device (or switch) is reordering completions that have different tags.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R/W (sticky) 
 - Dbi: R/W (sticky) 
 - Dbi2: R/W (sticky)<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && (AMBA_INTERFACE!=0)) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && (AMBA_INTERFACE==0) ) ?  R: (CX_MEMORY_MAP_VIEW==1 && (AMBA_INTERFACE!=0)) ?  R/W : (CX_MEMORY_MAP_VIEW==1 &&  (AMBA_INTERFACE==0) ) ? R: (AMBA_INTERFACE!=0) ? R/W : R</ct>
<i>Note</i>: This register field is sticky. */
#define AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF_OB_RD_SPLIT_BURST_EN_BitAddressOffset 0
#define AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF_OB_RD_SPLIT_BURST_EN_RegisterSize 1

/* Register AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF field RSVDP_1 */
/* Reserved for future use. */
#define AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF_RSVDP_1_BitAddressOffset 1
#define AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF_RSVDP_1_RegisterSize 31

/* End of Register Definition for AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF */

/* Register PL_DEBUG0_OFF */
/* Debug Register 0 */
#define PL_DEBUG0_OFF (PF0_PORT_LOGIC_BaseAddress + 0x28)
#define PL_DEBUG0_OFF_RegisterSize 32
#define PL_DEBUG0_OFF_RegisterResetValue 0x0
#define PL_DEBUG0_OFF_RegisterResetMask 0x0

/* Register Field information for PL_DEBUG0_OFF */

/* Register PL_DEBUG0_OFF field DEB_REG_0 */
/* The value on cxpl_debug_info[31:0]. */
#define PL_DEBUG0_OFF_DEB_REG_0_BitAddressOffset 0
#define PL_DEBUG0_OFF_DEB_REG_0_RegisterSize 32

/* End of Register Definition for PL_DEBUG0_OFF */

/* Register PL_DEBUG1_OFF */
/* Debug Register 1 */
#define PL_DEBUG1_OFF (PF0_PORT_LOGIC_BaseAddress + 0x2c)
#define PL_DEBUG1_OFF_RegisterSize 32
#define PL_DEBUG1_OFF_RegisterResetValue 0x0
#define PL_DEBUG1_OFF_RegisterResetMask 0x0

/* Register Field information for PL_DEBUG1_OFF */

/* Register PL_DEBUG1_OFF field DEB_REG_1 */
/* The value on cxpl_debug_info[63:32]. */
#define PL_DEBUG1_OFF_DEB_REG_1_BitAddressOffset 0
#define PL_DEBUG1_OFF_DEB_REG_1_RegisterSize 32

/* End of Register Definition for PL_DEBUG1_OFF */

/* Register TX_P_FC_CREDIT_STATUS_OFF */
/* Transmit Posted FC Credit Status */
#define TX_P_FC_CREDIT_STATUS_OFF (PF0_PORT_LOGIC_BaseAddress + 0x30)
#define TX_P_FC_CREDIT_STATUS_OFF_RegisterSize 32
#define TX_P_FC_CREDIT_STATUS_OFF_RegisterResetValue 0x0
#define TX_P_FC_CREDIT_STATUS_OFF_RegisterResetMask 0xffffffff

/* Register Field information for TX_P_FC_CREDIT_STATUS_OFF */

/* Register TX_P_FC_CREDIT_STATUS_OFF field TX_P_DATA_FC_CREDIT */
/* Transmit Posted Data FC Credits. The posted Data credits advertised by the receiver at the other end of the link, updated with each UpdateFC DLLP.
Default value depends on the number of advertised credits for header and data
[12'b0, xtlh_xadm_ph_cdts, xtlh_xadm_pd_cdts]; When the number of advertised completion credits (both header and data) are infinite, then the default would be [12'b0, 8'hFF, 12'hFFF]. */
#define TX_P_FC_CREDIT_STATUS_OFF_TX_P_DATA_FC_CREDIT_BitAddressOffset 0
#define TX_P_FC_CREDIT_STATUS_OFF_TX_P_DATA_FC_CREDIT_RegisterSize 12

/* Register TX_P_FC_CREDIT_STATUS_OFF field TX_P_HEADER_FC_CREDIT */
/* Transmit Posted Header FC Credits. The posted Header credits advertised by the receiver at the other end of the link, updated with each UpdateFC DLLP.
Default value depends on the number of advertised credits for header and data
[12'b0, xtlh_xadm_ph_cdts, xtlh_xadm_pd_cdts]; When the number of advertised completion credits (both header and data) are infinite, then the default would be [12'b0, 8'hFF, 12'hFFF]. */
#define TX_P_FC_CREDIT_STATUS_OFF_TX_P_HEADER_FC_CREDIT_BitAddressOffset 12
#define TX_P_FC_CREDIT_STATUS_OFF_TX_P_HEADER_FC_CREDIT_RegisterSize 8

/* Register TX_P_FC_CREDIT_STATUS_OFF field RSVDP_20 */
/* Reserved for future use. */
#define TX_P_FC_CREDIT_STATUS_OFF_RSVDP_20_BitAddressOffset 20
#define TX_P_FC_CREDIT_STATUS_OFF_RSVDP_20_RegisterSize 12

/* End of Register Definition for TX_P_FC_CREDIT_STATUS_OFF */

/* Register TX_NP_FC_CREDIT_STATUS_OFF */
/* Transmit Non-Posted FC Credit Status */
#define TX_NP_FC_CREDIT_STATUS_OFF (PF0_PORT_LOGIC_BaseAddress + 0x34)
#define TX_NP_FC_CREDIT_STATUS_OFF_RegisterSize 32
#define TX_NP_FC_CREDIT_STATUS_OFF_RegisterResetValue 0x0
#define TX_NP_FC_CREDIT_STATUS_OFF_RegisterResetMask 0xffffffff

/* Register Field information for TX_NP_FC_CREDIT_STATUS_OFF */

/* Register TX_NP_FC_CREDIT_STATUS_OFF field TX_NP_DATA_FC_CREDIT */
/* Transmit Non-Posted Data FC Credits. The non-posted Data credits advertised by the receiver at the other end of the link, updated with each UpdateFC DLLP.
Default value depends on the number of advertised credits for header and data
[12'b0, xtlh_xadm_nph_cdts, xtlh_xadm_npd_cdts]; When the number of advertised completion credits (both header and data) are infinite, then the default would be [12'b0, 8'hFF, 12'hFFF]. */
#define TX_NP_FC_CREDIT_STATUS_OFF_TX_NP_DATA_FC_CREDIT_BitAddressOffset 0
#define TX_NP_FC_CREDIT_STATUS_OFF_TX_NP_DATA_FC_CREDIT_RegisterSize 12

/* Register TX_NP_FC_CREDIT_STATUS_OFF field TX_NP_HEADER_FC_CREDIT */
/* Transmit Non-Posted Header FC Credits. The non-posted Header credits advertised by the receiver at the other end of the link, updated with each UpdateFC DLLP.
Default value depends on the number of advertised credits for header and data
[12'b0, xtlh_xadm_nph_cdts, xtlh_xadm_npd_cdts]; When the number of advertised completion credits (both header and data) are infinite, then the default would be [12'b0, 8'hFF, 12'hFFF]. */
#define TX_NP_FC_CREDIT_STATUS_OFF_TX_NP_HEADER_FC_CREDIT_BitAddressOffset 12
#define TX_NP_FC_CREDIT_STATUS_OFF_TX_NP_HEADER_FC_CREDIT_RegisterSize 8

/* Register TX_NP_FC_CREDIT_STATUS_OFF field RSVDP_20 */
/* Reserved for future use. */
#define TX_NP_FC_CREDIT_STATUS_OFF_RSVDP_20_BitAddressOffset 20
#define TX_NP_FC_CREDIT_STATUS_OFF_RSVDP_20_RegisterSize 12

/* End of Register Definition for TX_NP_FC_CREDIT_STATUS_OFF */

/* Register TX_CPL_FC_CREDIT_STATUS_OFF */
/* Transmit Completion FC Credit Status */
#define TX_CPL_FC_CREDIT_STATUS_OFF (PF0_PORT_LOGIC_BaseAddress + 0x38)
#define TX_CPL_FC_CREDIT_STATUS_OFF_RegisterSize 32
#define TX_CPL_FC_CREDIT_STATUS_OFF_RegisterResetValue 0x0
#define TX_CPL_FC_CREDIT_STATUS_OFF_RegisterResetMask 0xffffffff

/* Register Field information for TX_CPL_FC_CREDIT_STATUS_OFF */

/* Register TX_CPL_FC_CREDIT_STATUS_OFF field TX_CPL_DATA_FC_CREDIT */
/* Transmit Completion Data FC Credits. The Completion Data credits advertised by the receiver at the other end of the link, updated with each UpdateFC DLLP.
Default value depends on the number of advertised credits for header and data
[12'b0, xtlh_xadm_cplh_cdts, xtlh_xadm_cpld_cdts]; When the number of advertised completion credits (both header and data) are infinite, then the default would be [12'b0, 8'hFF, 12'hFFF]. */
#define TX_CPL_FC_CREDIT_STATUS_OFF_TX_CPL_DATA_FC_CREDIT_BitAddressOffset 0
#define TX_CPL_FC_CREDIT_STATUS_OFF_TX_CPL_DATA_FC_CREDIT_RegisterSize 12

/* Register TX_CPL_FC_CREDIT_STATUS_OFF field TX_CPL_HEADER_FC_CREDIT */
/* Transmit Completion Header FC Credits. The Completion Header credits advertised by the receiver at the other end of the link, updated with each UpdateFC DLLP.
Default value depends on the number of advertised credits for header and data
[12'b0, xtlh_xadm_cplh_cdts, xtlh_xadm_cpld_cdts]; When the number of advertised completion credits (both header and data) are infinite, then the default would be [12'b0, 8'hFF, 12'hFFF]. */
#define TX_CPL_FC_CREDIT_STATUS_OFF_TX_CPL_HEADER_FC_CREDIT_BitAddressOffset 12
#define TX_CPL_FC_CREDIT_STATUS_OFF_TX_CPL_HEADER_FC_CREDIT_RegisterSize 8

/* Register TX_CPL_FC_CREDIT_STATUS_OFF field RSVDP_20 */
/* Reserved for future use. */
#define TX_CPL_FC_CREDIT_STATUS_OFF_RSVDP_20_BitAddressOffset 20
#define TX_CPL_FC_CREDIT_STATUS_OFF_RSVDP_20_RegisterSize 12

/* End of Register Definition for TX_CPL_FC_CREDIT_STATUS_OFF */

/* Register QUEUE_STATUS_OFF */
/* Queue Status */
#define QUEUE_STATUS_OFF (PF0_PORT_LOGIC_BaseAddress + 0x3c)
#define QUEUE_STATUS_OFF_RegisterSize 32
#define QUEUE_STATUS_OFF_RegisterResetValue 0x0
#define QUEUE_STATUS_OFF_RegisterResetMask 0xffffffff

/* Register Field information for QUEUE_STATUS_OFF */

/* Register QUEUE_STATUS_OFF field RX_TLP_FC_CREDIT_NON_RETURN */
/* Received TLP FC Credits Not Returned. Indicates that the core has sent a TLP but has not yet received an UpdateFC DLLP indicating that the credits for that TLP have been restored by the receiver at the other end of the link. */
#define QUEUE_STATUS_OFF_RX_TLP_FC_CREDIT_NON_RETURN_BitAddressOffset 0
#define QUEUE_STATUS_OFF_RX_TLP_FC_CREDIT_NON_RETURN_RegisterSize 1

/* Register QUEUE_STATUS_OFF field TX_RETRY_BUFFER_NE */
/* Transmit Retry Buffer Not Empty. Indicates that there is data in the transmit retry buffer. */
#define QUEUE_STATUS_OFF_TX_RETRY_BUFFER_NE_BitAddressOffset 1
#define QUEUE_STATUS_OFF_TX_RETRY_BUFFER_NE_RegisterSize 1

/* Register QUEUE_STATUS_OFF field RX_QUEUE_NON_EMPTY */
/* Received Queue Not Empty. Indicates there is data in one or more of the receive buffers. */
#define QUEUE_STATUS_OFF_RX_QUEUE_NON_EMPTY_BitAddressOffset 2
#define QUEUE_STATUS_OFF_RX_QUEUE_NON_EMPTY_RegisterSize 1

/* Register QUEUE_STATUS_OFF field RSVDP_3 */
/* Reserved for future use. */
#define QUEUE_STATUS_OFF_RSVDP_3_BitAddressOffset 3
#define QUEUE_STATUS_OFF_RSVDP_3_RegisterSize 13

/* Register QUEUE_STATUS_OFF field TIMER_MOD_FLOW_CONTROL */
/* FC Latency Timer Override Value. When you set the "FC Latency Timer Override Enable" in this register, the value in this field will override the FC latency timer value that the core calculates according to the PCIe specification. For more details, see "Flow Control". */
#define QUEUE_STATUS_OFF_TIMER_MOD_FLOW_CONTROL_BitAddressOffset 16
#define QUEUE_STATUS_OFF_TIMER_MOD_FLOW_CONTROL_RegisterSize 13

/* Register QUEUE_STATUS_OFF field RSVDP_29 */
/* Reserved for future use. */
#define QUEUE_STATUS_OFF_RSVDP_29_BitAddressOffset 29
#define QUEUE_STATUS_OFF_RSVDP_29_RegisterSize 2

/* Register QUEUE_STATUS_OFF field TIMER_MOD_FLOW_CONTROL_EN */
/* FC Latency Timer Override Enable. When this bit is set, the value from the "FC Latency Timer Override Value" field in this register will override the FC latency timer value that the core calculates according to the PCIe specification. */
#define QUEUE_STATUS_OFF_TIMER_MOD_FLOW_CONTROL_EN_BitAddressOffset 31
#define QUEUE_STATUS_OFF_TIMER_MOD_FLOW_CONTROL_EN_RegisterSize 1

/* End of Register Definition for QUEUE_STATUS_OFF */

/* Register VC_TX_ARBI_1_OFF */
/* VC Transmit Arbitration Register 1 */
#define VC_TX_ARBI_1_OFF (PF0_PORT_LOGIC_BaseAddress + 0x40)
#define VC_TX_ARBI_1_OFF_RegisterSize 32
#define VC_TX_ARBI_1_OFF_RegisterResetValue 0xf
#define VC_TX_ARBI_1_OFF_RegisterResetMask 0xffffffff

/* Register Field information for VC_TX_ARBI_1_OFF */

/* Register VC_TX_ARBI_1_OFF field WRR_WEIGHT_VC_0 */
/* WRR Weight for VC0.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: R 
 - Dbi2: R<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && CX_LPVC_WRR_WEIGHT_WRITABLE) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && !CX_LPVC_WRR_WEIGHT_WRITABLE) ?  R: (CX_MEMORY_MAP_VIEW==1 &&  CX_LPVC_WRR_WEIGHT_WRITABLE) ? R/W:  (CX_MEMORY_MAP_VIEW==1 &&  !CX_LPVC_WRR_WEIGHT_WRITABLE) ? R: (CX_LPVC_WRR_WEIGHT_WRITABLE)? R/W:R</ct> */
#define VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_0_BitAddressOffset 0
#define VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_0_RegisterSize 8

/* Register VC_TX_ARBI_1_OFF field WRR_WEIGHT_VC_1 */
/* WRR Weight for VC1.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: R 
 - Dbi2: R<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && CX_LPVC_WRR_WEIGHT_WRITABLE) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && !CX_LPVC_WRR_WEIGHT_WRITABLE) ?  R: (CX_MEMORY_MAP_VIEW==1 &&  CX_LPVC_WRR_WEIGHT_WRITABLE) ? R/W:  (CX_MEMORY_MAP_VIEW==1 &&  !CX_LPVC_WRR_WEIGHT_WRITABLE) ? R: (CX_LPVC_WRR_WEIGHT_WRITABLE)? R/W:R</ct> */
#define VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_1_BitAddressOffset 8
#define VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_1_RegisterSize 8

/* Register VC_TX_ARBI_1_OFF field WRR_WEIGHT_VC_2 */
/* WRR Weight for VC2.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: R 
 - Dbi2: R<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && CX_LPVC_WRR_WEIGHT_WRITABLE) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && !CX_LPVC_WRR_WEIGHT_WRITABLE) ?  R: (CX_MEMORY_MAP_VIEW==1 &&  CX_LPVC_WRR_WEIGHT_WRITABLE) ? R/W:  (CX_MEMORY_MAP_VIEW==1 &&  !CX_LPVC_WRR_WEIGHT_WRITABLE) ? R: (CX_LPVC_WRR_WEIGHT_WRITABLE)? R/W:R</ct> */
#define VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_2_BitAddressOffset 16
#define VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_2_RegisterSize 8

/* Register VC_TX_ARBI_1_OFF field WRR_WEIGHT_VC_3 */
/* WRR Weight for VC3.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: R 
 - Dbi2: R<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && CX_LPVC_WRR_WEIGHT_WRITABLE) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && !CX_LPVC_WRR_WEIGHT_WRITABLE) ?  R: (CX_MEMORY_MAP_VIEW==1 &&  CX_LPVC_WRR_WEIGHT_WRITABLE) ? R/W:  (CX_MEMORY_MAP_VIEW==1 &&  !CX_LPVC_WRR_WEIGHT_WRITABLE) ? R: (CX_LPVC_WRR_WEIGHT_WRITABLE)? R/W:R</ct> */
#define VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_3_BitAddressOffset 24
#define VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_3_RegisterSize 8

/* End of Register Definition for VC_TX_ARBI_1_OFF */

/* Register VC_TX_ARBI_2_OFF */
/* VC Transmit Arbitration Register 2 */
#define VC_TX_ARBI_2_OFF (PF0_PORT_LOGIC_BaseAddress + 0x44)
#define VC_TX_ARBI_2_OFF_RegisterSize 32
#define VC_TX_ARBI_2_OFF_RegisterResetValue 0x0
#define VC_TX_ARBI_2_OFF_RegisterResetMask 0xffffffff

/* Register Field information for VC_TX_ARBI_2_OFF */

/* Register VC_TX_ARBI_2_OFF field WRR_WEIGHT_VC_4 */
/* WRR Weight for VC4.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: R 
 - Dbi2: R<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && CX_LPVC_WRR_WEIGHT_WRITABLE) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && !CX_LPVC_WRR_WEIGHT_WRITABLE) ?  R: (CX_MEMORY_MAP_VIEW==1 &&  CX_LPVC_WRR_WEIGHT_WRITABLE) ? R/W:  (CX_MEMORY_MAP_VIEW==1 &&  !CX_LPVC_WRR_WEIGHT_WRITABLE) ? R: (CX_LPVC_WRR_WEIGHT_WRITABLE)? R/W:R</ct> */
#define VC_TX_ARBI_2_OFF_WRR_WEIGHT_VC_4_BitAddressOffset 0
#define VC_TX_ARBI_2_OFF_WRR_WEIGHT_VC_4_RegisterSize 8

/* Register VC_TX_ARBI_2_OFF field WRR_WEIGHT_VC_5 */
/* WRR Weight for VC5.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: R 
 - Dbi2: R<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && CX_LPVC_WRR_WEIGHT_WRITABLE) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && !CX_LPVC_WRR_WEIGHT_WRITABLE) ?  R: (CX_MEMORY_MAP_VIEW==1 &&  CX_LPVC_WRR_WEIGHT_WRITABLE) ? R/W:  (CX_MEMORY_MAP_VIEW==1 &&  !CX_LPVC_WRR_WEIGHT_WRITABLE) ? R: (CX_LPVC_WRR_WEIGHT_WRITABLE)? R/W:R</ct> */
#define VC_TX_ARBI_2_OFF_WRR_WEIGHT_VC_5_BitAddressOffset 8
#define VC_TX_ARBI_2_OFF_WRR_WEIGHT_VC_5_RegisterSize 8

/* Register VC_TX_ARBI_2_OFF field WRR_WEIGHT_VC_6 */
/* WRR Weight for VC6.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: R 
 - Dbi2: R<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && CX_LPVC_WRR_WEIGHT_WRITABLE) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && !CX_LPVC_WRR_WEIGHT_WRITABLE) ?  R: (CX_MEMORY_MAP_VIEW==1 &&  CX_LPVC_WRR_WEIGHT_WRITABLE) ? R/W:  (CX_MEMORY_MAP_VIEW==1 &&  !CX_LPVC_WRR_WEIGHT_WRITABLE) ? R: (CX_LPVC_WRR_WEIGHT_WRITABLE)? R/W:R</ct> */
#define VC_TX_ARBI_2_OFF_WRR_WEIGHT_VC_6_BitAddressOffset 16
#define VC_TX_ARBI_2_OFF_WRR_WEIGHT_VC_6_RegisterSize 8

/* Register VC_TX_ARBI_2_OFF field WRR_WEIGHT_VC_7 */
/* WRR Weight for VC7.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R 
 - Dbi: R 
 - Dbi2: R<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && CX_LPVC_WRR_WEIGHT_WRITABLE) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && !CX_LPVC_WRR_WEIGHT_WRITABLE) ?  R: (CX_MEMORY_MAP_VIEW==1 &&  CX_LPVC_WRR_WEIGHT_WRITABLE) ? R/W:  (CX_MEMORY_MAP_VIEW==1 &&  !CX_LPVC_WRR_WEIGHT_WRITABLE) ? R: (CX_LPVC_WRR_WEIGHT_WRITABLE)? R/W:R</ct> */
#define VC_TX_ARBI_2_OFF_WRR_WEIGHT_VC_7_BitAddressOffset 24
#define VC_TX_ARBI_2_OFF_WRR_WEIGHT_VC_7_RegisterSize 8

/* End of Register Definition for VC_TX_ARBI_2_OFF */

/* Register VC0_P_RX_Q_CTRL_OFF */
/* Segmented-Buffer VC0 Posted Receive Queue Control. */
#define VC0_P_RX_Q_CTRL_OFF (PF0_PORT_LOGIC_BaseAddress + 0x48)
#define VC0_P_RX_Q_CTRL_OFF_RegisterSize 32
#define VC0_P_RX_Q_CTRL_OFF_RegisterResetValue 0x4021c040
#define VC0_P_RX_Q_CTRL_OFF_RegisterResetMask 0xffffffff

/* Register Field information for VC0_P_RX_Q_CTRL_OFF */

/* Register VC0_P_RX_Q_CTRL_OFF field VC0_P_DATA_CREDIT */
/* VC0 Posted Data Credits. The number of initial posted data credits for VC0, used only in the segmented-buffer configuration.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R (sticky) 
 - Dbi: R (sticky) 
 - Dbi2: R<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && CX_DYNAMIC_FC_CREDIT) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && !CX_DYNAMIC_FC_CREDIT) ?  R: (CX_MEMORY_MAP_VIEW==1 &&  CX_DYNAMIC_FC_CREDIT) ? R/W:  (CX_MEMORY_MAP_VIEW==1 &&  !CX_DYNAMIC_FC_CREDIT) ? R: (CX_DYNAMIC_FC_CREDIT)? R/W:R</ct>
<i>Note</i>: This register field is sticky. */
#define VC0_P_RX_Q_CTRL_OFF_VC0_P_DATA_CREDIT_BitAddressOffset 0
#define VC0_P_RX_Q_CTRL_OFF_VC0_P_DATA_CREDIT_RegisterSize 12

/* Register VC0_P_RX_Q_CTRL_OFF field VC0_P_HEADER_CREDIT */
/* VC0 Posted Header Credits. The number of initial posted header credits for VC0, used only in the segmented-buffer configuration.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R (sticky) 
 - Dbi: R (sticky) 
 - Dbi2: R<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && CX_DYNAMIC_FC_CREDIT) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && !CX_DYNAMIC_FC_CREDIT) ?  R: (CX_MEMORY_MAP_VIEW==1 &&  CX_DYNAMIC_FC_CREDIT) ? R/W:  (CX_MEMORY_MAP_VIEW==1 &&  !CX_DYNAMIC_FC_CREDIT) ? R: (CX_DYNAMIC_FC_CREDIT)? R/W:R</ct>
<i>Note</i>: This register field is sticky. */
#define VC0_P_RX_Q_CTRL_OFF_VC0_P_HEADER_CREDIT_BitAddressOffset 12
#define VC0_P_RX_Q_CTRL_OFF_VC0_P_HEADER_CREDIT_RegisterSize 8

/* Register VC0_P_RX_Q_CTRL_OFF field RESERVED4 */
/* Reserved.
<br><i>Note</i>: This register field is sticky. */
#define VC0_P_RX_Q_CTRL_OFF_RESERVED4_BitAddressOffset 20
#define VC0_P_RX_Q_CTRL_OFF_RESERVED4_RegisterSize 1

/* Register VC0_P_RX_Q_CTRL_OFF field VC0_P_TLP_Q_MODE */
/* Reserved.
<br><i>Note</i>: This register field is sticky. */
#define VC0_P_RX_Q_CTRL_OFF_VC0_P_TLP_Q_MODE_BitAddressOffset 21
#define VC0_P_RX_Q_CTRL_OFF_VC0_P_TLP_Q_MODE_RegisterSize 3

/* Register VC0_P_RX_Q_CTRL_OFF field RESERVED5 */
/* Reserved.
<br><i>Note</i>: This register field is sticky. */
#define VC0_P_RX_Q_CTRL_OFF_RESERVED5_BitAddressOffset 24
#define VC0_P_RX_Q_CTRL_OFF_RESERVED5_RegisterSize 6

/* Register VC0_P_RX_Q_CTRL_OFF field TLP_TYPE_ORDERING_VC0 */
/* TLP Type Ordering for VC0. Determines the TLP type ordering rule for VC0 receive queues, used only in the segmented-buffer configuration:
 - 1: PCIe ordering rules
 - 0: Strict ordering: posted, completion, then non-posted
<i>Note</i>: This register field is sticky. */
#define VC0_P_RX_Q_CTRL_OFF_TLP_TYPE_ORDERING_VC0_BitAddressOffset 30
#define VC0_P_RX_Q_CTRL_OFF_TLP_TYPE_ORDERING_VC0_RegisterSize 1

/* Register VC0_P_RX_Q_CTRL_OFF field VC_ORDERING_RX_Q */
/* VC Ordering for Receive Queues. Determines the VC ordering rule for the receive queues, used only in the segmented-buffer configuration:
 - 1: Strict ordering, higher numbered VCs have higher priority
 - 0: Round robin
<i>Note</i>: This register field is sticky. */
#define VC0_P_RX_Q_CTRL_OFF_VC_ORDERING_RX_Q_BitAddressOffset 31
#define VC0_P_RX_Q_CTRL_OFF_VC_ORDERING_RX_Q_RegisterSize 1

/* End of Register Definition for VC0_P_RX_Q_CTRL_OFF */

/* Register VC0_NP_RX_Q_CTRL_OFF */
/* Segmented-Buffer VC0 Non-Posted Receive Queue Control. */
#define VC0_NP_RX_Q_CTRL_OFF (PF0_PORT_LOGIC_BaseAddress + 0x4c)
#define VC0_NP_RX_Q_CTRL_OFF_RegisterSize 32
#define VC0_NP_RX_Q_CTRL_OFF_RegisterResetValue 0x21c006
#define VC0_NP_RX_Q_CTRL_OFF_RegisterResetMask 0xffffffff

/* Register Field information for VC0_NP_RX_Q_CTRL_OFF */

/* Register VC0_NP_RX_Q_CTRL_OFF field VC0_NP_DATA_CREDIT */
/* VC0 Non-Posted Data Credits. The number of initial non-posted data credits for VC0, used only in the segmented-buffer configuration.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R (sticky) 
 - Dbi: R (sticky) 
 - Dbi2: R (sticky)<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && CX_DYNAMIC_FC_CREDIT) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && !CX_DYNAMIC_FC_CREDIT) ?  R: (CX_MEMORY_MAP_VIEW==1 &&  CX_DYNAMIC_FC_CREDIT) ? R/W:  (CX_MEMORY_MAP_VIEW==1 &&  !CX_DYNAMIC_FC_CREDIT) ? R: (CX_DYNAMIC_FC_CREDIT)? R/W:R</ct>
<i>Note</i>: This register field is sticky. */
#define VC0_NP_RX_Q_CTRL_OFF_VC0_NP_DATA_CREDIT_BitAddressOffset 0
#define VC0_NP_RX_Q_CTRL_OFF_VC0_NP_DATA_CREDIT_RegisterSize 12

/* Register VC0_NP_RX_Q_CTRL_OFF field VC0_NP_HEADER_CREDIT */
/* VC0 Non-Posted Header Credits. The number of initial non-posted header credits for VC0, used only in the segmented-buffer configuration.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R (sticky) 
 - Dbi: R (sticky) 
 - Dbi2: R (sticky)<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && CX_DYNAMIC_FC_CREDIT) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && !CX_DYNAMIC_FC_CREDIT) ?  R: (CX_MEMORY_MAP_VIEW==1 &&  CX_DYNAMIC_FC_CREDIT) ? R/W:  (CX_MEMORY_MAP_VIEW==1 &&  !CX_DYNAMIC_FC_CREDIT) ? R: (CX_DYNAMIC_FC_CREDIT)? R/W:R</ct>
<i>Note</i>: This register field is sticky. */
#define VC0_NP_RX_Q_CTRL_OFF_VC0_NP_HEADER_CREDIT_BitAddressOffset 12
#define VC0_NP_RX_Q_CTRL_OFF_VC0_NP_HEADER_CREDIT_RegisterSize 8

/* Register VC0_NP_RX_Q_CTRL_OFF field RESERVED6 */
/* Reserved.
<br><i>Note</i>: This register field is sticky. */
#define VC0_NP_RX_Q_CTRL_OFF_RESERVED6_BitAddressOffset 20
#define VC0_NP_RX_Q_CTRL_OFF_RESERVED6_RegisterSize 1

/* Register VC0_NP_RX_Q_CTRL_OFF field VC0_NP_TLP_Q_MODE */
/* Reserved.
<br><i>Note</i>: This register field is sticky. */
#define VC0_NP_RX_Q_CTRL_OFF_VC0_NP_TLP_Q_MODE_BitAddressOffset 21
#define VC0_NP_RX_Q_CTRL_OFF_VC0_NP_TLP_Q_MODE_RegisterSize 3

/* Register VC0_NP_RX_Q_CTRL_OFF field RESERVED7 */
/* Reserved.
<br><i>Note</i>: This register field is sticky. */
#define VC0_NP_RX_Q_CTRL_OFF_RESERVED7_BitAddressOffset 24
#define VC0_NP_RX_Q_CTRL_OFF_RESERVED7_RegisterSize 8

/* End of Register Definition for VC0_NP_RX_Q_CTRL_OFF */

/* Register VC0_CPL_RX_Q_CTRL_OFF */
/* Segmented-Buffer VC0 Completion Receive Queue Control. */
#define VC0_CPL_RX_Q_CTRL_OFF (PF0_PORT_LOGIC_BaseAddress + 0x50)
#define VC0_CPL_RX_Q_CTRL_OFF_RegisterSize 32
#define VC0_CPL_RX_Q_CTRL_OFF_RegisterResetValue 0x800000
#define VC0_CPL_RX_Q_CTRL_OFF_RegisterResetMask 0xffffffff

/* Register Field information for VC0_CPL_RX_Q_CTRL_OFF */

/* Register VC0_CPL_RX_Q_CTRL_OFF field VC0_CPL_DATA_CREDIT */
/* VC0 Completion Data Credits. The number of initial Completion data credits for VC0, used only in the segmented-buffer configuration.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R (sticky) 
 - Dbi: R (sticky) 
 - Dbi2: R (sticky)<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && CX_DYNAMIC_FC_CREDIT) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && !CX_DYNAMIC_FC_CREDIT) ?  R: (CX_MEMORY_MAP_VIEW==1 &&  CX_DYNAMIC_FC_CREDIT) ? R/W:  (CX_MEMORY_MAP_VIEW==1 &&  !CX_DYNAMIC_FC_CREDIT) ? R: (CX_DYNAMIC_FC_CREDIT)? R/W:R</ct>
<i>Note</i>: This register field is sticky. */
#define VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_DATA_CREDIT_BitAddressOffset 0
#define VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_DATA_CREDIT_RegisterSize 12

/* Register VC0_CPL_RX_Q_CTRL_OFF field VC0_CPL_HEADER_CREDIT */
/* VC0 Completion Header Credits. The number of initial Completion header credits for VC0, used only in the segmented-buffer configuration.
<br><i>Note</i>: The access attributes of this field are as follows:
 - Wire: R (sticky) 
 - Dbi: R (sticky) 
 - Dbi2: R (sticky)<ct:[incorebuilder]><br>and more specifically: (CX_MEMORY_MAP_VIEW==0 && CX_DYNAMIC_FC_CREDIT) ?  R/W : (CX_MEMORY_MAP_VIEW==0 && !CX_DYNAMIC_FC_CREDIT) ?  R: (CX_MEMORY_MAP_VIEW==1 &&  CX_DYNAMIC_FC_CREDIT) ? R/W:  (CX_MEMORY_MAP_VIEW==1 &&  !CX_DYNAMIC_FC_CREDIT) ? R: (CX_DYNAMIC_FC_CREDIT)? R/W:R</ct>
<i>Note</i>: This register field is sticky. */
#define VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_HEADER_CREDIT_BitAddressOffset 12
#define VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_HEADER_CREDIT_RegisterSize 8

/* Register VC0_CPL_RX_Q_CTRL_OFF field RESERVED8 */
/* Reserved.
<br><i>Note</i>: This register field is sticky. */
#define VC0_CPL_RX_Q_CTRL_OFF_RESERVED8_BitAddressOffset 20
#define VC0_CPL_RX_Q_CTRL_OFF_RESERVED8_RegisterSize 1

/* Register VC0_CPL_RX_Q_CTRL_OFF field VC0_CPL_TLP_Q_MODE */
/* Reserved.
<br><i>Note</i>: This register field is sticky. */
#define VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_TLP_Q_MODE_BitAddressOffset 21
#define VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_TLP_Q_MODE_RegisterSize 3

/* Register VC0_CPL_RX_Q_CTRL_OFF field RESERVED9 */
/* Reserved.
<br><i>Note</i>: This register field is sticky. */
#define VC0_CPL_RX_Q_CTRL_OFF_RESERVED9_BitAddressOffset 24
#define VC0_CPL_RX_Q_CTRL_OFF_RESERVED9_RegisterSize 8

/* End of Register Definition for VC0_CPL_RX_Q_CTRL_OFF */

/* Register GEN2_CTRL_OFF */
/* Link Width and Speed Change Control Register. */
#define GEN2_CTRL_OFF (PF0_PORT_LOGIC_BaseAddress + 0x10c)
#define GEN2_CTRL_OFF_RegisterSize 32
#define GEN2_CTRL_OFF_RegisterResetValue 0x10f
#define GEN2_CTRL_OFF_RegisterResetMask 0xffffffff

/* Register Field information for GEN2_CTRL_OFF */

/* Register GEN2_CTRL_OFF field FAST_TRAINING_SEQ */
/* Sets the Number of Fast Training Sequences (N_FTS) that the core advertises as its N_FTS during Gen2 or Gen3 link training. This value is used to inform the link partner about the PHY's ability to recover synchronization after a low power state. The number should be provided by the PHY vendor. Do not set N_FTS to zero; doing so can cause the LTSSM to go into the recovery state when exiting from L0s.
This field is reserved (fixed to '0') for M-PCIe.
<br><i>Note</i>: This register field is sticky. */
#define GEN2_CTRL_OFF_FAST_TRAINING_SEQ_BitAddressOffset 0
#define GEN2_CTRL_OFF_FAST_TRAINING_SEQ_RegisterSize 8

/* Register GEN2_CTRL_OFF field NUM_OF_LANES */
/* Predetermined Number of Lanes. Defines the number of lanes which are connected and not bad. Used to limit the effective link width to ignore 'broken" or "unused" lanes that detect a receiver. Indicates the number of lanes to check for exit from Electrical Idle in Polling.Active and L2.Idle. It is possible that the LTSSM might detect a receiver on a bad or broken lane during the Detect Substate. However, it is also possible that such a lane might also fail to exit Electrical Idle and therefore prevent a valid link from being configured. This value is referred to as the "Predetermined Number of Lanes" in section 4.2.6.2.1 of the PCI Express Base 3.0 Specification, revision 1.0. Encoding is as follows:
 - 0x01: 1 lane
 - 0x02: 2 lanes
 - 0x03: 3 lanes
 - ..
When you have unused lanes in your system, then you must change the value in this register to reflect the number of lanes. You must also change the value in the "Link Mode Enable" field of the "Port Link Control Register". The value in this register is normally the same as the encoded value in the "Port Link Control Register". If you find that one of your used lanes is bad then you must reduce the value in this register. For more information, see "How to Tie Off Unused Lanes." For information on upsizing and downsizing the link width, see "Link Establishment."
This field is reserved (fixed to '0') for M-PCIe.
<br><i>Note</i>: This register field is sticky. */
#define GEN2_CTRL_OFF_NUM_OF_LANES_BitAddressOffset 8
#define GEN2_CTRL_OFF_NUM_OF_LANES_RegisterSize 5

/* Register GEN2_CTRL_OFF field PRE_DET_LANE */
/* Predetermined Lane for Auto Flip. This field defines which physical lane is connected to logical Lane0 by the flip operation performed in Detect. Allowed values are:
 - 3'b000: Connect logical Lane0 to physical lane 0 or CX_NL-1 or CX_NL/2-1 or CX_NL/4-1 or CX_NL/8-1, depending on which lane is detected
 - 3'b001: Connect logical Lane0 to physical lane 1
 - 3'b010: Connect logical Lane0 to physical lane 3
 - 3'b011: Connect logical Lane0 to physical lane 7
 - 3'b100: Connect logical Lane0 to physical lane 15
This field is used to restrict the receiver detect procedure to a particular lane when the default detect and polling procedure performed on all lanes cannot be successful. A notable example of when it is useful to program this field to a value different from the default, is when a lane is asymmetrically broken, that is, it is detected in Detect LTSSM state but it cannot exit Electrical Idle in Polling LTSSM state.
<br><i>Note:</i> This field is reserved (fixed to '0') for M-PCIe.
<br><i>Note</i>: This register field is sticky. */
#define GEN2_CTRL_OFF_PRE_DET_LANE_BitAddressOffset 13
#define GEN2_CTRL_OFF_PRE_DET_LANE_RegisterSize 3

/* Register GEN2_CTRL_OFF field AUTO_LANE_FLIP_CTRL_EN */
/* Enable Auto flipping of the lanes. You must set the CX_AUTO_LANE_FLIP_CTRL_EN configuration parameter to include the hardware for this feature in the core. For more details, see the 'Lane Reversal' appendix in the <i>Databook</i>. This field is reserved (fixed to '0') for M-PCIe.
<br><i>Note</i>: This register field is sticky. */
#define GEN2_CTRL_OFF_AUTO_LANE_FLIP_CTRL_EN_BitAddressOffset 16
#define GEN2_CTRL_OFF_AUTO_LANE_FLIP_CTRL_EN_RegisterSize 1

/* Register GEN2_CTRL_OFF field DIRECT_SPEED_CHANGE */
/* Directed Speed Change. Writing "1" to this field instructs the LTSSM to initiate a speed change to Gen2 or Gen3 after the link is initialized at Gen1 speed.
When the speed change occurs, the core will clear the contents of this field; and a read to this field by your software will return a "0".
To manually initiate the speed change:
 - Write to LINK_CONTROL2_LINK_STATUS2_REG . PCIE_CAP_TARGET_LINK_SPEED in the local device
 - Deassert this field
 - Assert this field
If you set the default of this field using the DEFAULT_GEN2_SPEED_CHANGE configuration parameter to "1", then the speed change is initiated automatically after link up, and the core clears the contents of this field. If you want to prevent this automatic speed change, then write a lower speed value to the Target Link Speed field of the Link Control 2 register (LINK_CONTROL2_LINK_STATUS2_OFF . PCIE_CAP_TARGET_LINK_SPEED) through the DBI before link up.
This field is reserved (fixed to '0') for M-PCIe. */
#define GEN2_CTRL_OFF_DIRECT_SPEED_CHANGE_BitAddressOffset 17
#define GEN2_CTRL_OFF_DIRECT_SPEED_CHANGE_RegisterSize 1

/* Register GEN2_CTRL_OFF field CONFIG_PHY_TX_CHANGE */
/* Config PHY Tx Swing. Controls the PHY transmitter voltage swing level. The core drives the mac_phy_txswing output from this register bit field.
 - 0: Full Swing
 - 1: Low Swing
This field is reserved (fixed to '0') for M-PCIe.
<br><i>Note</i>: This register field is sticky. */
#define GEN2_CTRL_OFF_CONFIG_PHY_TX_CHANGE_BitAddressOffset 18
#define GEN2_CTRL_OFF_CONFIG_PHY_TX_CHANGE_RegisterSize 1

/* Register GEN2_CTRL_OFF field CONFIG_TX_COMP_RX */
/* Config Tx Compliance Receive Bit. When set to 1, signals LTSSM to transmit TS ordered sets with the compliance receive bit assert (equal to "1").
This field is reserved (fixed to '0') for M-PCIe.
<br><i>Note</i>: This register field is sticky. */
#define GEN2_CTRL_OFF_CONFIG_TX_COMP_RX_BitAddressOffset 19
#define GEN2_CTRL_OFF_CONFIG_TX_COMP_RX_RegisterSize 1

/* Register GEN2_CTRL_OFF field SEL_DEEMPHASIS */
/* Used to set the de-emphasis level for upstream ports. This bit selects the level of de-emphasis the link operates at.
 - 0: -6 dB
 - 1: -3.5 dB
This field is reserved (fixed to '0') for M-PCIe.
<br><i>Note</i>: This register field is sticky. */
#define GEN2_CTRL_OFF_SEL_DEEMPHASIS_BitAddressOffset 20
#define GEN2_CTRL_OFF_SEL_DEEMPHASIS_RegisterSize 1

/* Register GEN2_CTRL_OFF field GEN1_EI_INFERENCE */
/* Electrical Idle Inference Mode at Gen1 Rate. Programmable mode to determine inferred electrical idle (EI) in Recovery.Speed or Loopback.Active (as slave) state at Gen1 speed by looking for a "1" value on RxElecIdle instead of looking for a "0" on RxValid. If the PHY fails to deassert the RxValid signal in Recovery.Speed or Loopback.Active (because of corrupted EIOS for example), then EI cannot be inferred successfully in the core by just detecting the condition RxValid=0.
 - 0: Use RxElecIdle signal to infer Electrical Idle
 - 1: Use RxValid signal to infer Electrical Idle
<i>Note</i>: This register field is sticky. */
#define GEN2_CTRL_OFF_GEN1_EI_INFERENCE_BitAddressOffset 21
#define GEN2_CTRL_OFF_GEN1_EI_INFERENCE_RegisterSize 1

/* Register GEN2_CTRL_OFF field RSVDP_22 */
/* Reserved for future use. */
#define GEN2_CTRL_OFF_RSVDP_22_BitAddressOffset 22
#define GEN2_CTRL_OFF_RSVDP_22_RegisterSize 10

/* End of Register Definition for GEN2_CTRL_OFF */

/* Register PHY_STATUS_OFF */
/* PHY Status Register. Memory mapped register from phy_cfg_status GPIO input pins. */
#define PHY_STATUS_OFF (PF0_PORT_LOGIC_BaseAddress + 0x110)
#define PHY_STATUS_OFF_RegisterSize 32
#define PHY_STATUS_OFF_RegisterResetValue 0x0
#define PHY_STATUS_OFF_RegisterResetMask 0x0

/* Register Field information for PHY_STATUS_OFF */

/* Register PHY_STATUS_OFF field PHY_STATUS */
/* PHY Status. Data received directly from the phy_cfg_status bus.
These is a GPIO register reflecting the values on the static phy_cfg_status input signals. The usage is left completely to the user and does not in any way influence core functionality. You can use it for any static sideband status signalling requirements that you have for your PHY.
This field is reserved (fixed to '0') for M-PCIe.
<br><i>Note</i>: This register field is sticky. */
#define PHY_STATUS_OFF_PHY_STATUS_BitAddressOffset 0
#define PHY_STATUS_OFF_PHY_STATUS_RegisterSize 32

/* End of Register Definition for PHY_STATUS_OFF */

/* Register PHY_CONTROL_OFF */
/* PHY Control Register. Memory mapped register to cfg_phy_control GPIO output pins. */
#define PHY_CONTROL_OFF (PF0_PORT_LOGIC_BaseAddress + 0x114)
#define PHY_CONTROL_OFF_RegisterSize 32
#define PHY_CONTROL_OFF_RegisterResetValue 0x0
#define PHY_CONTROL_OFF_RegisterResetMask 0xffffffff

/* Register Field information for PHY_CONTROL_OFF */

/* Register PHY_CONTROL_OFF field PHY_CONTROL */
/* PHY Control. Data sent directly to the cfg_phy_control bus.
These is a GPIO register driving the values on the static cfg_phy_control output signals. The usage is left completely to the user and does not in any way influence core functionality. You can use it for any static sideband control signalling requirements that you have for your PHY.
This field is reserved (fixed to '0') for M-PCIe.
<br><i>Note</i>: This register field is sticky. */
#define PHY_CONTROL_OFF_PHY_CONTROL_BitAddressOffset 0
#define PHY_CONTROL_OFF_PHY_CONTROL_RegisterSize 32

/* End of Register Definition for PHY_CONTROL_OFF */

/* Register PIPE_LOOPBACK_CONTROL_OFF */
/* PIPE Loopback Control Register. */
#define PIPE_LOOPBACK_CONTROL_OFF (PF0_PORT_LOGIC_BaseAddress + 0x1b8)
#define PIPE_LOOPBACK_CONTROL_OFF_RegisterSize 32
#define PIPE_LOOPBACK_CONTROL_OFF_RegisterResetValue 0x1
#define PIPE_LOOPBACK_CONTROL_OFF_RegisterResetMask 0xffffffff

/* Register Field information for PIPE_LOOPBACK_CONTROL_OFF */

/* Register PIPE_LOOPBACK_CONTROL_OFF field LPBK_RXVALID */
/* This is an internally reserved field. Do not use. */
#define PIPE_LOOPBACK_CONTROL_OFF_LPBK_RXVALID_BitAddressOffset 0
#define PIPE_LOOPBACK_CONTROL_OFF_LPBK_RXVALID_RegisterSize 16

/* Register PIPE_LOOPBACK_CONTROL_OFF field RXSTATUS_LANE */
/* This is an internally reserved field. Do not use. */
#define PIPE_LOOPBACK_CONTROL_OFF_RXSTATUS_LANE_BitAddressOffset 16
#define PIPE_LOOPBACK_CONTROL_OFF_RXSTATUS_LANE_RegisterSize 6

/* Register PIPE_LOOPBACK_CONTROL_OFF field RSVDP_22 */
/* Reserved for future use. */
#define PIPE_LOOPBACK_CONTROL_OFF_RSVDP_22_BitAddressOffset 22
#define PIPE_LOOPBACK_CONTROL_OFF_RSVDP_22_RegisterSize 2

/* Register PIPE_LOOPBACK_CONTROL_OFF field RXSTATUS_VALUE */
/* This is an internally reserved field. Do not use. */
#define PIPE_LOOPBACK_CONTROL_OFF_RXSTATUS_VALUE_BitAddressOffset 24
#define PIPE_LOOPBACK_CONTROL_OFF_RXSTATUS_VALUE_RegisterSize 3

/* Register PIPE_LOOPBACK_CONTROL_OFF field RSVDP_27 */
/* Reserved for future use. */
#define PIPE_LOOPBACK_CONTROL_OFF_RSVDP_27_BitAddressOffset 27
#define PIPE_LOOPBACK_CONTROL_OFF_RSVDP_27_RegisterSize 4

/* Register PIPE_LOOPBACK_CONTROL_OFF field PIPE_LOOPBACK */
/* PIPE Loopback Enable. Indicates RMMI Loopback if M-PCIe. */
#define PIPE_LOOPBACK_CONTROL_OFF_PIPE_LOOPBACK_BitAddressOffset 31
#define PIPE_LOOPBACK_CONTROL_OFF_PIPE_LOOPBACK_RegisterSize 1

/* End of Register Definition for PIPE_LOOPBACK_CONTROL_OFF */

/* Register MISC_CONTROL_1_OFF */
/* DBI Read-Only Write Enable Register. */
#define MISC_CONTROL_1_OFF (PF0_PORT_LOGIC_BaseAddress + 0x1bc)
#define MISC_CONTROL_1_OFF_RegisterSize 32
#define MISC_CONTROL_1_OFF_RegisterResetValue 0x0
#define MISC_CONTROL_1_OFF_RegisterResetMask 0xffffffff

/* Register Field information for MISC_CONTROL_1_OFF */

/* Register MISC_CONTROL_1_OFF field DBI_RO_WR_EN */
/* Write to RO Registers Using DBI. When you set this field to "1", then some RO and HwInit bits are writable from the local application through the DBI.
For more details, see "Writing to Read-Only Registers." */
#define MISC_CONTROL_1_OFF_DBI_RO_WR_EN_BitAddressOffset 0
#define MISC_CONTROL_1_OFF_DBI_RO_WR_EN_RegisterSize 1

/* Register MISC_CONTROL_1_OFF field RSVDP_1 */
/* Reserved for future use. */
#define MISC_CONTROL_1_OFF_RSVDP_1_BitAddressOffset 1
#define MISC_CONTROL_1_OFF_RSVDP_1_RegisterSize 31

/* End of Register Definition for MISC_CONTROL_1_OFF */

/* Register LINK_FLUSH_CONTROL_OFF */
/* Link Reset Request Flush Control Register. */
#define LINK_FLUSH_CONTROL_OFF (PF0_PORT_LOGIC_BaseAddress + 0x1cc)
#define LINK_FLUSH_CONTROL_OFF_RegisterSize 32
#define LINK_FLUSH_CONTROL_OFF_RegisterResetValue 0x32000001
#define LINK_FLUSH_CONTROL_OFF_RegisterResetMask 0xffffffff

/* Register Field information for LINK_FLUSH_CONTROL_OFF */

/* Register LINK_FLUSH_CONTROL_OFF field AUTO_FLUSH_EN */
/* Enables automatic flushing of pending requests before sending the reset request to the application logic to reset the PCIe core and the AXI Bridge.
The flushing process is initiated if any of the following events occur:
 - Hot reset request. A downstream port (DSP) can "hot reset" an upstream port (USP) by sending two consecutive TS1 ordered sets with the hot reset bit asserted.
 - Warm (Soft) reset request. Generated when exiting from D3 to D0 and cfg_pm_no_soft_rst=0.
 - Link down reset request. A high to low transition on smlh_req_rst_not indicates the link has gone down and the core is requesting a reset.
 - Link timeout event.The link timeout timer (AMBA_LINK_TIMEOUT_OFF) expires before the link is established.
If you disable automatic flushing, your application is responsible for resetting the PCIe core and the AXI Bridge. For more details see "Warm and Hot Resets" section in the Architecture chapter of the <i>Databook</i>.
<br><i>Note</i>: This register field is sticky. */
#define LINK_FLUSH_CONTROL_OFF_AUTO_FLUSH_EN_BitAddressOffset 0
#define LINK_FLUSH_CONTROL_OFF_AUTO_FLUSH_EN_RegisterSize 1

/* Register LINK_FLUSH_CONTROL_OFF field RSVDP_1 */
/* Reserved for future use. */
#define LINK_FLUSH_CONTROL_OFF_RSVDP_1_BitAddressOffset 1
#define LINK_FLUSH_CONTROL_OFF_RSVDP_1_RegisterSize 23

/* Register LINK_FLUSH_CONTROL_OFF field RSVD_I_8 */
/* This is an internally reserved field. Do not use.
<br><i>Note</i>: This register field is sticky. */
#define LINK_FLUSH_CONTROL_OFF_RSVD_I_8_BitAddressOffset 24
#define LINK_FLUSH_CONTROL_OFF_RSVD_I_8_RegisterSize 8

/* End of Register Definition for LINK_FLUSH_CONTROL_OFF */

/* Register AMBA_ERROR_RESPONSE_DEFAULT_OFF */
/* AHB/AXI Bridge Slave Error Response Register. */
#define AMBA_ERROR_RESPONSE_DEFAULT_OFF (PF0_PORT_LOGIC_BaseAddress + 0x1d0)
#define AMBA_ERROR_RESPONSE_DEFAULT_OFF_RegisterSize 32
#define AMBA_ERROR_RESPONSE_DEFAULT_OFF_RegisterResetValue 0xa400
#define AMBA_ERROR_RESPONSE_DEFAULT_OFF_RegisterResetMask 0xffffffff

/* Register Field information for AMBA_ERROR_RESPONSE_DEFAULT_OFF */

/* Register AMBA_ERROR_RESPONSE_DEFAULT_OFF field AMBA_ERROR_RESPONSE_GLOBAL */
/* Global Slave Error Response Mapping. Determines the AHB/AXI slave response for all error scenarios on non-posted requests. For more details see "Error Handling" in the AXI and AHB chapters of the <i>Databook</i>.
<br><b>AHB:</b>
 - 0: OKAY (with FFFF data for non-posted requests) and ignore the setting in bit [2] of this register.
 - 1: ERROR for normal link (data) accesses and look at bit [2] for other scenarios.
<b>AXI:</b>
 - 0: OKAY (with FFFF data for non-posted requests)
 - 1: ERROR (the AXI_ERROR_RESPONSE_MAP field determines the PCIe to AXI Slave error response mapping)
The error response mapping is not applicable to Non-existent Vendor ID register reads.
<br><i>Note</i>: This register field is sticky. */
#define AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_GLOBAL_BitAddressOffset 0
#define AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_GLOBAL_RegisterSize 1

/* Register AMBA_ERROR_RESPONSE_DEFAULT_OFF field RSVDP_1 */
/* Reserved for future use. */
#define AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_1_BitAddressOffset 1
#define AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_1_RegisterSize 1

/* Register AMBA_ERROR_RESPONSE_DEFAULT_OFF field AMBA_ERROR_RESPONSE_VENDORID */
/* Vendor ID Non-existent Slave Error Response Mapping. Determines the AHB/AXI slave response for errors on reads to non-existent Vendor ID register. For more details see "Error Handling" in the AXI and AHB chapters of the <i>Databook</i>.<br><b>AHB:</b>
 - 0: OKAY (with FFFF data). The core ignores the setting in the bit when bit 0 of this register is "0".
 - 1: ERROR
<b>AXI:</b>
 - 0: OKAY (with FFFF data).
 - 1: ERROR (the AXI_ERROR_RESPONSE_MAP field determines the PCIe to AXI Slave error response mapping)
<i>Note</i>: This register field is sticky. */
#define AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_VENDORID_BitAddressOffset 2
#define AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_VENDORID_RegisterSize 1

/* Register AMBA_ERROR_RESPONSE_DEFAULT_OFF field RSVDP_3 */
/* Reserved for future use. */
#define AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_3_BitAddressOffset 3
#define AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_3_RegisterSize 7

/* Register AMBA_ERROR_RESPONSE_DEFAULT_OFF field AMBA_ERROR_RESPONSE_MAP */
/* AXI Slave Response Error Map. This map allows the application to selectively map the errors received from the PCIe completion (for non-posted requests) to the AXI slave responses, slv_rresp or slv_bresp. For each bit, a '1' maps the completion error to SLVERR and a '0' maps the completion error to DECERR. The recommended setting is SLVERR. The individual bits represent the following completion errors:
 - [0]: UR (unsupported request)
 - [2]: CA (completer abort)
 - [5]: Completion Timeout. The AXI bridge internally drops (services internally but not passing to your application) a completion that has been marked by the RADM as UC or MLF and does not pass its status directly down to the slave interface. It waits for a timeout and then signals "Completion Timeout" to the slave interface.
The AXI slave data bus returns error responses with FFFF data.
<br><i>Note</i>: This register field is sticky. */
#define AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_MAP_BitAddressOffset 10
#define AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_MAP_RegisterSize 6

/* Register AMBA_ERROR_RESPONSE_DEFAULT_OFF field RSVDP_16 */
/* Reserved for future use. */
#define AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_16_BitAddressOffset 16
#define AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_16_RegisterSize 16

/* End of Register Definition for AMBA_ERROR_RESPONSE_DEFAULT_OFF */

/* Register AMBA_LINK_TIMEOUT_OFF */
/* Link Down AXI Bridge Slave Timeout Register. If your application AXI master issues outbound requests to the AXI bridge slave interface before the PCIe link is operational, the core starts a "flush" timer. The timeout value of the timer is set by this register. The timer will timeout and then flush the bridge TX request queues after this amount of time. The timer counts when there are pending outbound AXI slave interface (or DMA) requests and the PCIe TX link is not transmitting any of these requests. For more details, see the "AXI Bridge Initialization, Clocking and Reset" section in the AHB chapter of the <i>Databook.</i> */
#define AMBA_LINK_TIMEOUT_OFF (PF0_PORT_LOGIC_BaseAddress + 0x1d4)
#define AMBA_LINK_TIMEOUT_OFF_RegisterSize 32
#define AMBA_LINK_TIMEOUT_OFF_RegisterResetValue 0x32
#define AMBA_LINK_TIMEOUT_OFF_RegisterResetMask 0xffffffff

/* Register Field information for AMBA_LINK_TIMEOUT_OFF */

/* Register AMBA_LINK_TIMEOUT_OFF field LINK_TIMEOUT_PERIOD_DEFAULT */
/* Timeout Value (ms). The timer will timeout and then flush the bridge TX request queues after this amount of time. The timer counts when there are pending outbound AXI slave interface requests and the PCIe TX link is not transmitting any of these requests.
The timer is clocked by core_clk. For an M-PCIe configuration:
 - Time unit of this field is 4 ms.
 - Margin of error for RateA clock is < 1%.
 - Margin of error for RateB clock is between 16% and 17%.
<i>Note</i>: This register field is sticky. */
#define AMBA_LINK_TIMEOUT_OFF_LINK_TIMEOUT_PERIOD_DEFAULT_BitAddressOffset 0
#define AMBA_LINK_TIMEOUT_OFF_LINK_TIMEOUT_PERIOD_DEFAULT_RegisterSize 8

/* Register AMBA_LINK_TIMEOUT_OFF field LINK_TIMEOUT_ENABLE_DEFAULT */
/* Disable Flush. You can disable the flush feature by setting this field to "1".
<br><i>Note</i>: This register field is sticky. */
#define AMBA_LINK_TIMEOUT_OFF_LINK_TIMEOUT_ENABLE_DEFAULT_BitAddressOffset 8
#define AMBA_LINK_TIMEOUT_OFF_LINK_TIMEOUT_ENABLE_DEFAULT_RegisterSize 1

/* Register AMBA_LINK_TIMEOUT_OFF field RSVDP_9 */
/* Reserved for future use. */
#define AMBA_LINK_TIMEOUT_OFF_RSVDP_9_BitAddressOffset 9
#define AMBA_LINK_TIMEOUT_OFF_RSVDP_9_RegisterSize 23

/* End of Register Definition for AMBA_LINK_TIMEOUT_OFF */

/* Register AMBA_ORDERING_CTRL_OFF */
/* AMBA Ordering Control. */
#define AMBA_ORDERING_CTRL_OFF (PF0_PORT_LOGIC_BaseAddress + 0x1d8)
#define AMBA_ORDERING_CTRL_OFF_RegisterSize 32
#define AMBA_ORDERING_CTRL_OFF_RegisterResetValue 0x0
#define AMBA_ORDERING_CTRL_OFF_RegisterResetMask 0xffffffff

/* Register Field information for AMBA_ORDERING_CTRL_OFF */

/* Register AMBA_ORDERING_CTRL_OFF field AX_MSTR_NP_PASS_P */
/* AXI Master NP can pass P.
<br>This field enables software to relax the PCIe ordering rule, NP must not pass P at the AXI Master Interface. The AXI protocol does not support ordering between channels. Therefore, NP reads can pass P on your AXI bus fabric. This can result in an ordering violation when the read overtakes a P that is going to the same address. Therefore, the bridge master does not issue any NP requests until all outstanding P writes reach their destination. It does this by waiting for the write responses on the B channel. This can affect the performance of the master read channel. To relax this rule, set this field. For more details, see the "AXI Bridge Ordering" section in the AXI chapter of the <i>Databook.</i>
 - 0: Dequeue NP requests at the AXI master interface when write responses to P requests, dequeued before the pending NP request, have been received.
 - 1: Dequeue NP requests at AXI master interface immediately. Do not wait for write responses to P requests, dequeued before the NP request. Enables NP requests to pass P requests on the AXI fabric. */
#define AMBA_ORDERING_CTRL_OFF_AX_MSTR_NP_PASS_P_BitAddressOffset 0
#define AMBA_ORDERING_CTRL_OFF_AX_MSTR_NP_PASS_P_RegisterSize 1

/* Register AMBA_ORDERING_CTRL_OFF field AX_SNP_EN */
/* AXI Serialize Non-Posted Requests Enable. This field enables the AXI Bridge to serialize same ID Non-Posted Read/Write Requests on the wire. Serialization implies one outstanding same ID NP Read or Write on the wire and used to avoid AXI RAR and WAW hazards at the remote link partner. For more details, see the "Optional Serialization of AXI Slave Non-posted Requests" section in the AXI chapter of the <i>Databook.</i> */
#define AMBA_ORDERING_CTRL_OFF_AX_SNP_EN_BitAddressOffset 1
#define AMBA_ORDERING_CTRL_OFF_AX_SNP_EN_RegisterSize 1

/* Register AMBA_ORDERING_CTRL_OFF field RSVDP_2 */
/* Reserved for future use. */
#define AMBA_ORDERING_CTRL_OFF_RSVDP_2_BitAddressOffset 2
#define AMBA_ORDERING_CTRL_OFF_RSVDP_2_RegisterSize 30

/* End of Register Definition for AMBA_ORDERING_CTRL_OFF */

/* Register COHERENCY_CONTROL_1_OFF */
/* ACE Cache Coherency Control Register 1 */
#define COHERENCY_CONTROL_1_OFF (PF0_PORT_LOGIC_BaseAddress + 0x1e0)
#define COHERENCY_CONTROL_1_OFF_RegisterSize 32
#define COHERENCY_CONTROL_1_OFF_RegisterResetValue 0x0
#define COHERENCY_CONTROL_1_OFF_RegisterResetMask 0xffffffff

/* Register Field information for COHERENCY_CONTROL_1_OFF */

/* Register COHERENCY_CONTROL_1_OFF field CFG_MEMTYPE_VALUE */
/* Sets the memory type for the lower and upper parts of the address space:
 - 0: lower = Peripheral; upper = Memory
 - 1: lower = Memory type; upper = Peripheral
<i>Note</i>: This register field is sticky. */
#define COHERENCY_CONTROL_1_OFF_CFG_MEMTYPE_VALUE_BitAddressOffset 0
#define COHERENCY_CONTROL_1_OFF_CFG_MEMTYPE_VALUE_RegisterSize 1

/* Register COHERENCY_CONTROL_1_OFF field RSVDP_1 */
/* Reserved for future use. */
#define COHERENCY_CONTROL_1_OFF_RSVDP_1_BitAddressOffset 1
#define COHERENCY_CONTROL_1_OFF_RSVDP_1_RegisterSize 1

/* Register COHERENCY_CONTROL_1_OFF field CFG_MEMTYPE_BOUNDARY_LOW_ADDR */
/* Boundary Lower Address For Memory Type. Bits [31:0] of dword-aligned address of the boundary for Memory type. The two lower address LSBs are "0". Addresses up to but not including this value are in the lower address space region; addresses equal or greater than this value are in the upper address space region.
<br><i>Note</i>: This register field is sticky. */
#define COHERENCY_CONTROL_1_OFF_CFG_MEMTYPE_BOUNDARY_LOW_ADDR_BitAddressOffset 2
#define COHERENCY_CONTROL_1_OFF_CFG_MEMTYPE_BOUNDARY_LOW_ADDR_RegisterSize 30

/* End of Register Definition for COHERENCY_CONTROL_1_OFF */

/* Register COHERENCY_CONTROL_3_OFF */
/* ACE Cache Coherency Control Register 3 */
#define COHERENCY_CONTROL_3_OFF (PF0_PORT_LOGIC_BaseAddress + 0x1e8)
#define COHERENCY_CONTROL_3_OFF_RegisterSize 32
#define COHERENCY_CONTROL_3_OFF_RegisterResetValue 0x0
#define COHERENCY_CONTROL_3_OFF_RegisterResetMask 0xffffffff

/* Register Field information for COHERENCY_CONTROL_3_OFF */

/* Register COHERENCY_CONTROL_3_OFF field CFG_MSTR_ARCACHE_MODE */
/* Master Read CACHE Signal Behavior.
Defines how the individual bits in mstr_arcache are controlled:
 - 0: set automatically by the AXI master
 - 1: set by the value of the corresponding bit of the CFG_MSTR_ARCACHE_VALUE field
<i>Note</i>: This register field is sticky. */
#define COHERENCY_CONTROL_3_OFF_CFG_MSTR_ARCACHE_MODE_BitAddressOffset 3
#define COHERENCY_CONTROL_3_OFF_CFG_MSTR_ARCACHE_MODE_RegisterSize 4

/* Register COHERENCY_CONTROL_3_OFF field CFG_MSTR_AWCACHE_MODE */
/* Master Write CACHE Signal Behavior.
Defines how the individual bits in mstr_awcache are controlled:
 - 0: set automatically by the AXI master
 - 1: set by the value of the corresponding bit of the CFG_MSTR_AWCACHE_VALUE field
Note: for message requests the value of mstr_awcache is always 0000 regardless of the value of this bit
<br><i>Note</i>: This register field is sticky. */
#define COHERENCY_CONTROL_3_OFF_CFG_MSTR_AWCACHE_MODE_BitAddressOffset 11
#define COHERENCY_CONTROL_3_OFF_CFG_MSTR_AWCACHE_MODE_RegisterSize 4

/* Register COHERENCY_CONTROL_3_OFF field CFG_MSTR_ARCACHE_VALUE */
/* Master Read CACHE Signal Value.
Value of the individual bits in mstr_arcache when CFG_MSTR_ARCACHE_MODE is "1"
<br><i>Note</i>: This register field is sticky. */
#define COHERENCY_CONTROL_3_OFF_CFG_MSTR_ARCACHE_VALUE_BitAddressOffset 19
#define COHERENCY_CONTROL_3_OFF_CFG_MSTR_ARCACHE_VALUE_RegisterSize 4

/* Register COHERENCY_CONTROL_3_OFF field CFG_MSTR_AWCACHE_VALUE */
/* Master Write CACHE Signal Value.
Value of the individual bits in mstr_awcache when CFG_MSTR_AWCACHE_MODE is "1"
<br>Note: not applicable to message requests; for message requests the value of mstr_awcache is always 0000
<br><i>Note</i>: This register field is sticky. */
#define COHERENCY_CONTROL_3_OFF_CFG_MSTR_AWCACHE_VALUE_BitAddressOffset 27
#define COHERENCY_CONTROL_3_OFF_CFG_MSTR_AWCACHE_VALUE_RegisterSize 4

/* End of Register Definition for COHERENCY_CONTROL_3_OFF */

/* Register PL_LAST_OFF */
/* This is an internally reserved register. Do not use. */
#define PL_LAST_OFF (PF0_PORT_LOGIC_BaseAddress + 0x1fc)
#define PL_LAST_OFF_RegisterSize 32
#define PL_LAST_OFF_RegisterResetValue 0x0
#define PL_LAST_OFF_RegisterResetMask 0xffffffff

/* Register Field information for PL_LAST_OFF */

/* Register PL_LAST_OFF field PL_LAST */
/* This is an internally reserved field. Do not use. */
#define PL_LAST_OFF_PL_LAST_BitAddressOffset 0
#define PL_LAST_OFF_PL_LAST_RegisterSize 1

/* Register PL_LAST_OFF field RSVDP_1 */
/* Reserved for future use. */
#define PL_LAST_OFF_RSVDP_1_BitAddressOffset 1
#define PL_LAST_OFF_RSVDP_1_RegisterSize 31

/* End of Register Definition for PL_LAST_OFF */

/* Register DMA_CTRL_DATA_ARB_PRIOR_OFF */
/* DMA Arbitration Scheme for TRGT1 Interface. This register is used to control traffic priorities among various sources that are delivered to your application through TRGT1 where 0x0 represents the highest priority.
 - Non-DMA Rx Requests
 - DMA Write Channel MRd Requests (DMA data requests and LL element/descriptor access) 
 - DMA Read Channel MRd Requests (LL element/descriptor access)
 - DMA Read Channel MWr Requests
Concurrent traffic from channels with same priority are sorted according to Round-Robin arbitration rules.
The arbitration priority defaults to Non-DMA requests (highest), Write Channel MRd, Read Channel MRd, Read Channel MWr.
For more details, see the For more details, see the Internal Architecture section in the DMA chapter of the <i>Databook</i>. */
#define DMA_CTRL_DATA_ARB_PRIOR_OFF (PF0_PORT_LOGIC_BaseAddress + 0x270)
#define DMA_CTRL_DATA_ARB_PRIOR_OFF_RegisterSize 32
#define DMA_CTRL_DATA_ARB_PRIOR_OFF_RegisterResetValue 0x688
#define DMA_CTRL_DATA_ARB_PRIOR_OFF_RegisterResetMask 0xffffffff

/* Register Field information for DMA_CTRL_DATA_ARB_PRIOR_OFF */

/* Register DMA_CTRL_DATA_ARB_PRIOR_OFF field RTRGT1_WEIGHT */
/* Non-DMA Rx Requests. */
#define DMA_CTRL_DATA_ARB_PRIOR_OFF_RTRGT1_WEIGHT_BitAddressOffset 0
#define DMA_CTRL_DATA_ARB_PRIOR_OFF_RTRGT1_WEIGHT_RegisterSize 3

/* Register DMA_CTRL_DATA_ARB_PRIOR_OFF field WR_CTRL_TRGT_WEIGHT */
/* DMA Write Channel MRd Requests. For DMA data requests and LL element/descriptor access. */
#define DMA_CTRL_DATA_ARB_PRIOR_OFF_WR_CTRL_TRGT_WEIGHT_BitAddressOffset 3
#define DMA_CTRL_DATA_ARB_PRIOR_OFF_WR_CTRL_TRGT_WEIGHT_RegisterSize 3

/* Register DMA_CTRL_DATA_ARB_PRIOR_OFF field RD_CTRL_TRGT_WEIGHT */
/* DMA Read Channel MRd Requests. For LL element/descriptor access. */
#define DMA_CTRL_DATA_ARB_PRIOR_OFF_RD_CTRL_TRGT_WEIGHT_BitAddressOffset 6
#define DMA_CTRL_DATA_ARB_PRIOR_OFF_RD_CTRL_TRGT_WEIGHT_RegisterSize 3

/* Register DMA_CTRL_DATA_ARB_PRIOR_OFF field RDBUFF_TRGT_WEIGHT */
/* DMA Read Channel MWr Requests. */
#define DMA_CTRL_DATA_ARB_PRIOR_OFF_RDBUFF_TRGT_WEIGHT_BitAddressOffset 9
#define DMA_CTRL_DATA_ARB_PRIOR_OFF_RDBUFF_TRGT_WEIGHT_RegisterSize 3

/* Register DMA_CTRL_DATA_ARB_PRIOR_OFF field RSVDP_12 */
/* Reserved for future use. */
#define DMA_CTRL_DATA_ARB_PRIOR_OFF_RSVDP_12_BitAddressOffset 12
#define DMA_CTRL_DATA_ARB_PRIOR_OFF_RSVDP_12_RegisterSize 20

/* End of Register Definition for DMA_CTRL_DATA_ARB_PRIOR_OFF */

/* Register DMA_CTRL_OFF */
/* DMA Number of Channels Register. */
#define DMA_CTRL_OFF (PF0_PORT_LOGIC_BaseAddress + 0x278)
#define DMA_CTRL_OFF_RegisterSize 32
#define DMA_CTRL_OFF_RegisterResetValue 0x10001
#define DMA_CTRL_OFF_RegisterResetMask 0xffffffff

/* Register Field information for DMA_CTRL_OFF */

/* Register DMA_CTRL_OFF field NUM_DMA_WR_CHAN */
/* Number of Write Channels. You can read this register to determine the number of write channels the DMA controller has been configured to support. */
#define DMA_CTRL_OFF_NUM_DMA_WR_CHAN_BitAddressOffset 0
#define DMA_CTRL_OFF_NUM_DMA_WR_CHAN_RegisterSize 4

/* Register DMA_CTRL_OFF field RSVDP_4 */
/* Reserved for future use. */
#define DMA_CTRL_OFF_RSVDP_4_BitAddressOffset 4
#define DMA_CTRL_OFF_RSVDP_4_RegisterSize 12

/* Register DMA_CTRL_OFF field NUM_DMA_RD_CHAN */
/* Number of Read Channels. You can read this register to determine the number of read channels the DMA controller has been configured to support. */
#define DMA_CTRL_OFF_NUM_DMA_RD_CHAN_BitAddressOffset 16
#define DMA_CTRL_OFF_NUM_DMA_RD_CHAN_RegisterSize 4

/* Register DMA_CTRL_OFF field RSVDP_20 */
/* Reserved for future use. */
#define DMA_CTRL_OFF_RSVDP_20_BitAddressOffset 20
#define DMA_CTRL_OFF_RSVDP_20_RegisterSize 12

/* End of Register Definition for DMA_CTRL_OFF */

/* Register DMA_WRITE_ENGINE_EN_OFF */
/* DMA Write Engine Enable Register. */
#define DMA_WRITE_ENGINE_EN_OFF (PF0_PORT_LOGIC_BaseAddress + 0x27c)
#define DMA_WRITE_ENGINE_EN_OFF_RegisterSize 32
#define DMA_WRITE_ENGINE_EN_OFF_RegisterResetValue 0x0
#define DMA_WRITE_ENGINE_EN_OFF_RegisterResetMask 0xffffffff

/* Register Field information for DMA_WRITE_ENGINE_EN_OFF */

/* Register DMA_WRITE_ENGINE_EN_OFF field DMA_WRITE_ENGINE */
/* DMA Write Engine Enable.
 - 1: Enable
 - 0: Disable (Soft Reset)
For normal operation, you must initially set this bit to "1", before any other software setup actions. You do not need to toggle or rewrite to this bit during normal operation.
You should set this bit to "0" when you want to "Soft Reset" the DMA controller write logic. There are three possible reasons for resetting the DMA controller write logic:
 - The "Abort Interrupt Status" bit is set (in the "DMA Write Interrupt Status Register" DMA_WRITE_INT_STATUS_OFF), and any of the bits is in the "DMA Write Error Status Register" (DMA_WRITE_ERR_STATUS_OFF) are set. Resetting the DMA controller write logic re-initializes the control logic, ensuring that the next DMA write transfer is executed successfully.
 - You have executed the procedure outlined in "Stop Bit" , after which, the "Abort Interrupt Status" bit is set and the Channel Status field (CS) of the DMA write "DMA Channel Control 1 Register " (DMA_CH_CONTROL1_OFF_WRCH_0) is set to "Stopped." Resetting the DMA controller write logic re-initializes the control logic ensuring that the next DMA write transfer is executed successfully.
 - During software development, when you incorrectly program the DMA write engine.
To "Soft Reset" the DMA controller write logic, you must:
 - De-assert the DMA write engine enable bit.
 - Wait for the DMA to complete any in-progress TLP transfer, by waiting until a read on the DMA write engine enable bit returns a "0".
 - Assert the DMA write engine enable bit.
This "Soft Reset" does not clear the DMA configuration registers. The DMA write transfer does not start until you write to the "DMA Write Doorbell Register" (DMA_WRITE_DOORBELL_OFF). */
#define DMA_WRITE_ENGINE_EN_OFF_DMA_WRITE_ENGINE_BitAddressOffset 0
#define DMA_WRITE_ENGINE_EN_OFF_DMA_WRITE_ENGINE_RegisterSize 1

/* Register DMA_WRITE_ENGINE_EN_OFF field RSVDP_1 */
/* Reserved for future use. */
#define DMA_WRITE_ENGINE_EN_OFF_RSVDP_1_BitAddressOffset 1
#define DMA_WRITE_ENGINE_EN_OFF_RSVDP_1_RegisterSize 31

/* End of Register Definition for DMA_WRITE_ENGINE_EN_OFF */

/* Register DMA_WRITE_DOORBELL_OFF */
/* DMA Write Doorbell Register. */
#define DMA_WRITE_DOORBELL_OFF (PF0_PORT_LOGIC_BaseAddress + 0x280)
#define DMA_WRITE_DOORBELL_OFF_RegisterSize 32
#define DMA_WRITE_DOORBELL_OFF_RegisterResetValue 0x0
#define DMA_WRITE_DOORBELL_OFF_RegisterResetMask 0xffffffff

/* Register Field information for DMA_WRITE_DOORBELL_OFF */

/* Register DMA_WRITE_DOORBELL_OFF field WR_DOORBELL_NUM */
/* Doorbell Number. You must write the channel number to this register to start the DMA write transfer for that channel. The DMA detects a write to this register field even if the value of this field does not change. You do not need to toggle or write any other value to this register to start a new transfer.
The range of this field is 0x0 to 0x7, and 0x0 corresponds to channel 0. */
#define DMA_WRITE_DOORBELL_OFF_WR_DOORBELL_NUM_BitAddressOffset 0
#define DMA_WRITE_DOORBELL_OFF_WR_DOORBELL_NUM_RegisterSize 3

/* Register DMA_WRITE_DOORBELL_OFF field RSVDP_3 */
/* Reserved for future use. */
#define DMA_WRITE_DOORBELL_OFF_RSVDP_3_BitAddressOffset 3
#define DMA_WRITE_DOORBELL_OFF_RSVDP_3_RegisterSize 28

/* Register DMA_WRITE_DOORBELL_OFF field WR_STOP */
/* Stop. Set in conjunction with the Doorbell Number field. The DMA write channel stops issuing requests, sets the channel status to "Stopped", and asserts the "Abort" interrupt if it is enabled. Before setting the Stop bit, you must read the channel Status field (CS) of the "DMA Channel Control 1 Register " (DMA_CH_CONTROL1_OFF_WRCH_0) to ensure that the write channel is "Running" (transferring data).
For more information, see "Stopping the DMA Transfer (Software Stop)." */
#define DMA_WRITE_DOORBELL_OFF_WR_STOP_BitAddressOffset 31
#define DMA_WRITE_DOORBELL_OFF_WR_STOP_RegisterSize 1

/* End of Register Definition for DMA_WRITE_DOORBELL_OFF */

/* Register DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF */
/* DMA Write Engine Channel Arbitration Weight Low Register. The 5-bit channel weight (for write channels 0-3) specifies the number of TLP requests that the DMA can issue for that channel before it must return to the arbitration routine. When the channel weight count is reached, the WWR arbiter selects the next channel to be processed. Your software must initialize this register before ringing the doorbell. For more details, see "Multichannel Arbitration". <br>Value range is (0-0x1F) corresponding to (1-32) transactions. */
#define DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF (PF0_PORT_LOGIC_BaseAddress + 0x288)
#define DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_RegisterSize 32
#define DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_RegisterResetValue 0x8421
#define DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_RegisterResetMask 0xffffffff

/* Register Field information for DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF */

/* Register DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF field WRITE_CHANNEL0_WEIGHT */
/* Channel 0 Weight. */
#define DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL0_WEIGHT_BitAddressOffset 0
#define DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL0_WEIGHT_RegisterSize 5

/* Register DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF field WRITE_CHANNEL1_WEIGHT */
/* Channel 1 Weight. The weight is initialized by software before ringing the doorbell. The value is used by the channel weighted round robin arbiter to select the next channel read request. */
#define DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL1_WEIGHT_BitAddressOffset 5
#define DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL1_WEIGHT_RegisterSize 5

/* Register DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF field WRITE_CHANNEL2_WEIGHT */
/* Channel 2 Weight. The weight is initialized by software before ringing the doorbell. The value is used by the channel weighted round robin arbiter to select the next channel read request. */
#define DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL2_WEIGHT_BitAddressOffset 10
#define DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL2_WEIGHT_RegisterSize 5

/* Register DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF field WRITE_CHANNEL3_WEIGHT */
/* Channel 3 Weight. The weight is initialized by software before ringing the doorbell. The value is used by the channel weighted round robin arbiter to select the next channel read request. */
#define DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL3_WEIGHT_BitAddressOffset 15
#define DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL3_WEIGHT_RegisterSize 5

/* Register DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF field RSVDP_20 */
/* Reserved for future use. */
#define DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_RSVDP_20_BitAddressOffset 20
#define DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_RSVDP_20_RegisterSize 12

/* End of Register Definition for DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF */

/* Register DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF */
/* DMA Write Engine Channel Arbitration Weight High Register. The 5-bit channel weight (for write channels 4-7) specifies the number of TLP requests that the DMA can issue for that channel before it must return to the arbitration routine. When the channel weight count is reached, the WWR arbiter selects the next channel to be processed. Your software must initialize this register before ringing the doorbell. For more details, see "Multichannel Arbitration". <br>Value range is (0-0x1F) corresponding to (1-32) transactions. */
#define DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF (PF0_PORT_LOGIC_BaseAddress + 0x28c)
#define DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_RegisterSize 32
#define DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_RegisterResetValue 0x8421
#define DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_RegisterResetMask 0xffffffff

/* Register Field information for DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF */

/* Register DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF field WRITE_CHANNEL4_WEIGHT */
/* Channel 4 Weight. The weight is initialized by software before ringing the doorbell. The value is used by the channel weighted round robin arbiter to select the next channel read request. */
#define DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL4_WEIGHT_BitAddressOffset 0
#define DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL4_WEIGHT_RegisterSize 5

/* Register DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF field WRITE_CHANNEL5_WEIGHT */
/* Channel 5 Weight. The weight is initialized by software before ringing the doorbell. The value is used by the channel weighted round robin arbiter to select the next channel read request. */
#define DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL5_WEIGHT_BitAddressOffset 5
#define DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL5_WEIGHT_RegisterSize 5

/* Register DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF field WRITE_CHANNEL6_WEIGHT */
/* Channel 6 Weight. The weight is initialized by software before ringing the doorbell. The value is used by the channel weighted round robin arbiter to select the next channel read request. */
#define DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL6_WEIGHT_BitAddressOffset 10
#define DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL6_WEIGHT_RegisterSize 5

/* Register DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF field WRITE_CHANNEL7_WEIGHT */
/* Channel 7 Weight. The weight is initialized by software before ringing the doorbell. The value is used by the channel weighted round robin arbiter to select the next channel read request. */
#define DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL7_WEIGHT_BitAddressOffset 15
#define DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL7_WEIGHT_RegisterSize 5

/* Register DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF field RSVDP_20 */
/* Reserved for future use. */
#define DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_RSVDP_20_BitAddressOffset 20
#define DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_RSVDP_20_RegisterSize 12

/* End of Register Definition for DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF */

/* Register DMA_READ_ENGINE_EN_OFF */
/* DMA Read Engine Enable Register. */
#define DMA_READ_ENGINE_EN_OFF (PF0_PORT_LOGIC_BaseAddress + 0x29c)
#define DMA_READ_ENGINE_EN_OFF_RegisterSize 32
#define DMA_READ_ENGINE_EN_OFF_RegisterResetValue 0x0
#define DMA_READ_ENGINE_EN_OFF_RegisterResetMask 0xffffffff

/* Register Field information for DMA_READ_ENGINE_EN_OFF */

/* Register DMA_READ_ENGINE_EN_OFF field DMA_READ_ENGINE */
/* DMA Read Engine Enable.
 - 1: Enable
 - 0: Disable (Soft Reset)
For normal operation, you must initially set this bit to "1", before any other software setup actions. You do not need to toggle or rewrite to this bit during normal operation.
You should set this field to "0" when you want to "Soft Reset" the DMA controller read logic. There are three possible reasons for resetting the DMA controller read logic:
 - The "Abort Interrupt Status" bit is set (in the "DMA Read Interrupt Status Register" (DMA_READ_INT_STATUS_OFF), and any of the bits in the "DMA Read Error Status Low Register" (DMA_READ_ERR_STATUS_LOW_OFF) is set. Resetting the DMA controller read logic re-initializes the control logic, ensuring that the next DMA read transfer is executed successfully.
 - You have executed the procedure outlined in "Stop Bit", after which, the "Abort Interrupt Status" bit is set and the channel Status field (CS) of the DMA read "DMA Channel Control 1 Register " (DMA_CH_CONTROL1_OFF_WRCH_0) is set to "Stopped". Resetting the DMA controller read logic re-initializes the control logic ensuring that the next DMA read transfer is executed successfully.
 - During software development, when you incorrectly program the DMA read engine.
To "Soft Reset" the DMA controller read logic, you must:
 - De-assert the DMA read engine enable bit.
 - Wait for the DMA to complete any in-progress TLP transfer, by waiting until a read on the DMA read engine enable bit returns a "0".
 - Assert the DMA read engine enable bit.
This "Soft Reset" does not clear the DMA configuration registers. The DMA read transfer does not start until you write to the "DMA Read Doorbell Register" (DMA_READ_DOORBELL_OFF). */
#define DMA_READ_ENGINE_EN_OFF_DMA_READ_ENGINE_BitAddressOffset 0
#define DMA_READ_ENGINE_EN_OFF_DMA_READ_ENGINE_RegisterSize 1

/* Register DMA_READ_ENGINE_EN_OFF field RSVDP_1 */
/* Reserved for future use. */
#define DMA_READ_ENGINE_EN_OFF_RSVDP_1_BitAddressOffset 1
#define DMA_READ_ENGINE_EN_OFF_RSVDP_1_RegisterSize 31

/* End of Register Definition for DMA_READ_ENGINE_EN_OFF */

/* Register DMA_READ_DOORBELL_OFF */
/* DMA Read Doorbell Register. */
#define DMA_READ_DOORBELL_OFF (PF0_PORT_LOGIC_BaseAddress + 0x2a0)
#define DMA_READ_DOORBELL_OFF_RegisterSize 32
#define DMA_READ_DOORBELL_OFF_RegisterResetValue 0x0
#define DMA_READ_DOORBELL_OFF_RegisterResetMask 0xffffffff

/* Register Field information for DMA_READ_DOORBELL_OFF */

/* Register DMA_READ_DOORBELL_OFF field RD_DOORBELL_NUM */
/* Doorbell Number. You must write 0x0 to this register to start the DMA read transfer for that channel. The DMA detects a write to this register field even if the value of this field does not change.
The range of this field is 0x0 to 0x7, and 0x0 corresponds to channel 0. */
#define DMA_READ_DOORBELL_OFF_RD_DOORBELL_NUM_BitAddressOffset 0
#define DMA_READ_DOORBELL_OFF_RD_DOORBELL_NUM_RegisterSize 3

/* Register DMA_READ_DOORBELL_OFF field RSVDP_3 */
/* Reserved for future use. */
#define DMA_READ_DOORBELL_OFF_RSVDP_3_BitAddressOffset 3
#define DMA_READ_DOORBELL_OFF_RSVDP_3_RegisterSize 28

/* Register DMA_READ_DOORBELL_OFF field RD_STOP */
/* Stop. Set in conjunction with the Doorbell Number field. The DMA read channel stops issuing requests, sets the channel status to "Stopped", and asserts the "Abort" interrupt if it is enabled. Before setting the Stop bit, you must read the channel Status field (CS) of the "DMA Channel Control 1 Register " (DMA_CH_CONTROL1_OFF_RDCH_0) to ensure that the read channel is "Running" (transferring data).
For more information, see "Stopping the DMA Transfer (Software Stop)". */
#define DMA_READ_DOORBELL_OFF_RD_STOP_BitAddressOffset 31
#define DMA_READ_DOORBELL_OFF_RD_STOP_RegisterSize 1

/* End of Register Definition for DMA_READ_DOORBELL_OFF */

/* Register DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF */
/* DMA Read Engine Channel Arbitration Weight Low Register. The 5-bit channel weight (for read channels 0-3) specifies the number of TLP requests that the DMA can issue for that channel before it must return to the arbitration routine. When the channel weight count is reached, the WWR arbiter selects the next channel to be processed. Your software must initialize this register before ringing the doorbell. For more details, see "Multichannel Arbitration". Value range is (0-0x1F) corresponding to (1-32) transactions. */
#define DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF (PF0_PORT_LOGIC_BaseAddress + 0x2a8)
#define DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_RegisterSize 32
#define DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_RegisterResetValue 0x8421
#define DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_RegisterResetMask 0xffffffff

/* Register Field information for DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF */

/* Register DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF field READ_CHANNEL0_WEIGHT */
/* Channel 0 Weight. The weight is initialized by software before ringing the doorbell. The value is used by the channel weighted round robin arbiter to select the next channel read request. */
#define DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL0_WEIGHT_BitAddressOffset 0
#define DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL0_WEIGHT_RegisterSize 5

/* Register DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF field READ_CHANNEL1_WEIGHT */
/* Channel 1 Weight. The weight is initialized by software before ringing the doorbell. The value is used by the channel weighted round robin arbiter to select the next channel read request. */
#define DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL1_WEIGHT_BitAddressOffset 5
#define DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL1_WEIGHT_RegisterSize 5

/* Register DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF field READ_CHANNEL2_WEIGHT */
/* Channel 2 Weight. The weight is initialized by software before ringing the doorbell. The value is used by the channel weighted round robin arbiter to select the next channel read request. */
#define DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL2_WEIGHT_BitAddressOffset 10
#define DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL2_WEIGHT_RegisterSize 5

/* Register DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF field READ_CHANNEL3_WEIGHT */
/* Channel 3 Weight. The weight is initialized by software before ringing the doorbell. The value is used by the channel weighted round robin arbiter to select the next channel read request. */
#define DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL3_WEIGHT_BitAddressOffset 15
#define DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL3_WEIGHT_RegisterSize 5

/* Register DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF field RSVDP_20 */
/* Reserved for future use. */
#define DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_RSVDP_20_BitAddressOffset 20
#define DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_RSVDP_20_RegisterSize 12

/* End of Register Definition for DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF */

/* Register DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF */
/* DMA Read Engine Channel Arbitration Weight High Register. The 5-bit channel weight (for read channels 4-7) specifies the number of TLP requests that the DMA can issue for that channel before it must return to the arbitration routine. When the channel weight count is reached, the WWR arbiter selects the next channel to be processed. Your software must initialize this register before ringing the doorbell. For more details, see "Multichannel Arbitration". Value range is (0-0x1F) corresponding to (1-32) transactions. */
#define DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF (PF0_PORT_LOGIC_BaseAddress + 0x2ac)
#define DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_RegisterSize 32
#define DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_RegisterResetValue 0x8421
#define DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_RegisterResetMask 0xffffffff

/* Register Field information for DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF */

/* Register DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF field READ_CHANNEL4_WEIGHT */
/* Channel 4 Weight. The weight is initialized by software before ringing the doorbell. The value is used by the channel weighted round robin arbiter to select the next channel read request. */
#define DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL4_WEIGHT_BitAddressOffset 0
#define DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL4_WEIGHT_RegisterSize 5

/* Register DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF field READ_CHANNEL5_WEIGHT */
/* Channel 5 Weight. The weight is initialized by software before ringing the doorbell. The value is used by the channel weighted round robin arbiter to select the next channel read request. */
#define DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL5_WEIGHT_BitAddressOffset 5
#define DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL5_WEIGHT_RegisterSize 5

/* Register DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF field READ_CHANNEL6_WEIGHT */
/* Channel 6 Weight. The weight is initialized by software before ringing the doorbell. The value is used by the channel weighted round robin arbiter to select the next channel read request. */
#define DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL6_WEIGHT_BitAddressOffset 10
#define DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL6_WEIGHT_RegisterSize 5

/* Register DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF field READ_CHANNEL7_WEIGHT */
/* Channel 7 Weight. The weight is initialized by software before ringing the doorbell. The value is used by the channel weighted round robin arbiter to select the next channel read request. */
#define DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL7_WEIGHT_BitAddressOffset 15
#define DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL7_WEIGHT_RegisterSize 5

/* Register DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF field RSVDP_20 */
/* Reserved for future use. */
#define DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_RSVDP_20_BitAddressOffset 20
#define DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_RSVDP_20_RegisterSize 12

/* End of Register Definition for DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF */

/* Register DMA_WRITE_INT_STATUS_OFF */
/* DMA Write Interrupt Status Register. */
#define DMA_WRITE_INT_STATUS_OFF (PF0_PORT_LOGIC_BaseAddress + 0x2bc)
#define DMA_WRITE_INT_STATUS_OFF_RegisterSize 32
#define DMA_WRITE_INT_STATUS_OFF_RegisterResetValue 0x0
#define DMA_WRITE_INT_STATUS_OFF_RegisterResetMask 0xffffffff

/* Register Field information for DMA_WRITE_INT_STATUS_OFF */

/* Register DMA_WRITE_INT_STATUS_OFF field WR_DONE_INT_STATUS */
/* Done Interrupt Status. The DMA write channel has successfully completed the DMA transfer. For more details, see "Interrupts and Error Handling". Each bit corresponds to a DMA channel. Bit [0] corresponds to channel 0.
 - Enabling: For details, see "Interrupts and Error Handling".
 - Masking: The DMA write interrupt Mask register has no effect on this register.
 - Clearing: You must write a 1'b1 to the corresponding channel bit in the DMA write interrupt Clear register to clear this interrupt bit.
<b> Note: </b> You can write to this register to emulate interrupt generation, during software or hardware testing. A write to the address triggers an interrupt, but the DMA does not set the Done or Abort bits in this register. */
#define DMA_WRITE_INT_STATUS_OFF_WR_DONE_INT_STATUS_BitAddressOffset 0
#define DMA_WRITE_INT_STATUS_OFF_WR_DONE_INT_STATUS_RegisterSize 8

/* Register DMA_WRITE_INT_STATUS_OFF field RSVDP_8 */
/* Reserved for future use. */
#define DMA_WRITE_INT_STATUS_OFF_RSVDP_8_BitAddressOffset 8
#define DMA_WRITE_INT_STATUS_OFF_RSVDP_8_RegisterSize 8

/* Register DMA_WRITE_INT_STATUS_OFF field WR_ABORT_INT_STATUS */
/* Abort Interrupt Status. The DMA write channel has detected an error, or you manually stopped the transfer as described in "Error Handling Assistance by Remote Software". Each bit corresponds to a DMA channel. Bit [0] corresponds to channel 0.
 - Enabling: For details, see "Interrupts and Error Handling".
 - Masking: The DMA write interrupt Mask register has no effect on this register.
 - Clearing: You must write a 1'b1 to the corresponding channel bit in the DMA write interrupt Clear register to clear this interrupt bit.
<b> Note: </b> You can write to this register to emulate interrupt generation, during software or hardware testing. A write to the address triggers an interrupt, but the DMA does not set the Done or Abort bits in this register. */
#define DMA_WRITE_INT_STATUS_OFF_WR_ABORT_INT_STATUS_BitAddressOffset 16
#define DMA_WRITE_INT_STATUS_OFF_WR_ABORT_INT_STATUS_RegisterSize 8

/* Register DMA_WRITE_INT_STATUS_OFF field RSVDP_24 */
/* Reserved for future use. */
#define DMA_WRITE_INT_STATUS_OFF_RSVDP_24_BitAddressOffset 24
#define DMA_WRITE_INT_STATUS_OFF_RSVDP_24_RegisterSize 8

/* End of Register Definition for DMA_WRITE_INT_STATUS_OFF */

/* Register DMA_WRITE_INT_MASK_OFF */
/* DMA Write Interrupt Mask Register. */
#define DMA_WRITE_INT_MASK_OFF (PF0_PORT_LOGIC_BaseAddress + 0x2c4)
#define DMA_WRITE_INT_MASK_OFF_RegisterSize 32
#define DMA_WRITE_INT_MASK_OFF_RegisterResetValue 0x10001
#define DMA_WRITE_INT_MASK_OFF_RegisterResetMask 0xffffffff

/* Register Field information for DMA_WRITE_INT_MASK_OFF */

/* Register DMA_WRITE_INT_MASK_OFF field WR_DONE_INT_MASK */
/* Done Interrupt Mask. Prevents the Done interrupt status field in the DMA write interrupt status register from asserting the edma_int output. Each bit corresponds to a DMA channel. Bit [0] corresponds to channel 0. */
#define DMA_WRITE_INT_MASK_OFF_WR_DONE_INT_MASK_BitAddressOffset 0
#define DMA_WRITE_INT_MASK_OFF_WR_DONE_INT_MASK_RegisterSize 1

/* Register DMA_WRITE_INT_MASK_OFF field RSVDP_8 */
/* Reserved for future use. */
#define DMA_WRITE_INT_MASK_OFF_RSVDP_8_BitAddressOffset 8
#define DMA_WRITE_INT_MASK_OFF_RSVDP_8_RegisterSize 8

/* Register DMA_WRITE_INT_MASK_OFF field WR_ABORT_INT_MASK */
/* Abort Interrupt Mask. Prevents the Abort interrupt status field in the DMA write interrupt status register from asserting the edma_int output. Each bit corresponds to a DMA channel. Bit [0] corresponds to channel 0. */
#define DMA_WRITE_INT_MASK_OFF_WR_ABORT_INT_MASK_BitAddressOffset 16
#define DMA_WRITE_INT_MASK_OFF_WR_ABORT_INT_MASK_RegisterSize 1

/* Register DMA_WRITE_INT_MASK_OFF field RSVDP_24 */
/* Reserved for future use. */
#define DMA_WRITE_INT_MASK_OFF_RSVDP_24_BitAddressOffset 24
#define DMA_WRITE_INT_MASK_OFF_RSVDP_24_RegisterSize 8

/* End of Register Definition for DMA_WRITE_INT_MASK_OFF */

/* Register DMA_WRITE_INT_CLEAR_OFF */
/* DMA Write Interrupt Clear Register. */
#define DMA_WRITE_INT_CLEAR_OFF (PF0_PORT_LOGIC_BaseAddress + 0x2c8)
#define DMA_WRITE_INT_CLEAR_OFF_RegisterSize 32
#define DMA_WRITE_INT_CLEAR_OFF_RegisterResetValue 0x0
#define DMA_WRITE_INT_CLEAR_OFF_RegisterResetMask 0xffffffff

/* Register Field information for DMA_WRITE_INT_CLEAR_OFF */

/* Register DMA_WRITE_INT_CLEAR_OFF field WR_DONE_INT_CLEAR */
/* Done Interrupt Clear. You must write a 1'b1 to clear the corresponding bit in the Done interrupt status field of the DMA write interrupt status register. Each bit corresponds to a DMA channel. Bit [0] corresponds to channel 0.
<br><b>Note:</b> Reading from this self-clearing register field always returns a "0". */
#define DMA_WRITE_INT_CLEAR_OFF_WR_DONE_INT_CLEAR_BitAddressOffset 0
#define DMA_WRITE_INT_CLEAR_OFF_WR_DONE_INT_CLEAR_RegisterSize 8

/* Register DMA_WRITE_INT_CLEAR_OFF field RSVDP_8 */
/* Reserved for future use. */
#define DMA_WRITE_INT_CLEAR_OFF_RSVDP_8_BitAddressOffset 8
#define DMA_WRITE_INT_CLEAR_OFF_RSVDP_8_RegisterSize 8

/* Register DMA_WRITE_INT_CLEAR_OFF field WR_ABORT_INT_CLEAR */
/* Abort Interrupt Clear. You must write a 1'b1 to clear the corresponding bit in the Abort interrupt status field of the DMA write interrupt status register. Each bit corresponds to a DMA channel. Bit [0] corresponds to channel 0.
<br><b>Note:</b> Reading from this self-clearing register field always returns a "0". */
#define DMA_WRITE_INT_CLEAR_OFF_WR_ABORT_INT_CLEAR_BitAddressOffset 16
#define DMA_WRITE_INT_CLEAR_OFF_WR_ABORT_INT_CLEAR_RegisterSize 8

/* Register DMA_WRITE_INT_CLEAR_OFF field RSVDP_24 */
/* Reserved for future use. */
#define DMA_WRITE_INT_CLEAR_OFF_RSVDP_24_BitAddressOffset 24
#define DMA_WRITE_INT_CLEAR_OFF_RSVDP_24_RegisterSize 8

/* End of Register Definition for DMA_WRITE_INT_CLEAR_OFF */

/* Register DMA_WRITE_ERR_STATUS_OFF */
/* DMA Write Error Status Register */
#define DMA_WRITE_ERR_STATUS_OFF (PF0_PORT_LOGIC_BaseAddress + 0x2cc)
#define DMA_WRITE_ERR_STATUS_OFF_RegisterSize 32
#define DMA_WRITE_ERR_STATUS_OFF_RegisterResetValue 0x0
#define DMA_WRITE_ERR_STATUS_OFF_RegisterResetMask 0xffffffff

/* Register Field information for DMA_WRITE_ERR_STATUS_OFF */

/* Register DMA_WRITE_ERR_STATUS_OFF field APP_READ_ERR_DETECT */
/* Application Read Error Detected. The DMA write channel has received an error response from the AHB/AXI bus (or TRGT1 interface when the AHB/AXI Bridge is not used) while reading data from it. Each bit corresponds to a DMA channel. Bit [0] corresponds to channel 0.
 - Enabling: For details, see "Interrupts and Error Handling".
 - Masking: The DMA write interrupt Mask register has no effect on this register.
 - Clearing: You must write a 1'b1 to the corresponding channel bit in the Abort interrupt field of the "DMA Write Interrupt Clear Register" (DMA_WRITE_INT_CLEAR_OFF) to clear this error bit. */
#define DMA_WRITE_ERR_STATUS_OFF_APP_READ_ERR_DETECT_BitAddressOffset 0
#define DMA_WRITE_ERR_STATUS_OFF_APP_READ_ERR_DETECT_RegisterSize 8

/* Register DMA_WRITE_ERR_STATUS_OFF field RSVDP_8 */
/* Reserved for future use. */
#define DMA_WRITE_ERR_STATUS_OFF_RSVDP_8_BitAddressOffset 8
#define DMA_WRITE_ERR_STATUS_OFF_RSVDP_8_RegisterSize 8

/* Register DMA_WRITE_ERR_STATUS_OFF field LINKLIST_ELEMENT_FETCH_ERR_DETECT */
/* Linked List Element Fetch Error Detected. The DMA write channel has received an error response from the AHB/AXI bus (or TRGT1 interface when the AHB/AXI Bridge is not used) while reading a linked list element from local memory. Each bit corresponds to a DMA channel. Bit [0] corresponds to channel 0.
 - Enabling: For details, see "Interrupts and Error Handling".
 - Masking: The DMA write interrupt Mask register has no effect on this register.
 - Clearing: You must write a 1'b1 to the corresponding channel bit in the Abort interrupt field of the "DMA Write Interrupt Clear Register" (DMA_WRITE_INT_CLEAR_OFF) to clear this error bit. */
#define DMA_WRITE_ERR_STATUS_OFF_LINKLIST_ELEMENT_FETCH_ERR_DETECT_BitAddressOffset 16
#define DMA_WRITE_ERR_STATUS_OFF_LINKLIST_ELEMENT_FETCH_ERR_DETECT_RegisterSize 8

/* Register DMA_WRITE_ERR_STATUS_OFF field RSVDP_24 */
/* Reserved for future use. */
#define DMA_WRITE_ERR_STATUS_OFF_RSVDP_24_BitAddressOffset 24
#define DMA_WRITE_ERR_STATUS_OFF_RSVDP_24_RegisterSize 8

/* End of Register Definition for DMA_WRITE_ERR_STATUS_OFF */

/* Register DMA_WRITE_DONE_IMWR_LOW_OFF */
/* DMA Write Done IMWr Address Low Register. This register is implemented in RAM whose contents are uninitialized after power-on. Therefore, you must program and initialize every field as the default is undefined. All fields marked "Reserved" MUST be programmed to 1'b0. This register is not affected by any of the reset signals. */
#define DMA_WRITE_DONE_IMWR_LOW_OFF (PF0_PORT_LOGIC_BaseAddress + 0x2d0)
#define DMA_WRITE_DONE_IMWR_LOW_OFF_RegisterSize 32
#define DMA_WRITE_DONE_IMWR_LOW_OFF_RegisterResetValue 0x0
#define DMA_WRITE_DONE_IMWR_LOW_OFF_RegisterResetMask 0x0

/* Register Field information for DMA_WRITE_DONE_IMWR_LOW_OFF */

/* Register DMA_WRITE_DONE_IMWR_LOW_OFF field DMA_WRITE_DONE_LOW_REG */
/* The DMA uses this field to generate bits [31:0] of the address field for the Done IMWr TLP. Bits [1:0] must be "00" as this address must be dword aligned. */
#define DMA_WRITE_DONE_IMWR_LOW_OFF_DMA_WRITE_DONE_LOW_REG_BitAddressOffset 0
#define DMA_WRITE_DONE_IMWR_LOW_OFF_DMA_WRITE_DONE_LOW_REG_RegisterSize 32

/* End of Register Definition for DMA_WRITE_DONE_IMWR_LOW_OFF */

/* Register DMA_WRITE_DONE_IMWR_HIGH_OFF */
/* DMA Write Done IMWr Interrupt Address High Register. This register is implemented in RAM whose contents are uninitialized after power-on. Therefore, you must program and initialize every field as the default is undefined. All fields marked "Reserved" MUST be programmed to 1'b0. This register is not affected by any of the reset signals. */
#define DMA_WRITE_DONE_IMWR_HIGH_OFF (PF0_PORT_LOGIC_BaseAddress + 0x2d4)
#define DMA_WRITE_DONE_IMWR_HIGH_OFF_RegisterSize 32
#define DMA_WRITE_DONE_IMWR_HIGH_OFF_RegisterResetValue 0x0
#define DMA_WRITE_DONE_IMWR_HIGH_OFF_RegisterResetMask 0x0

/* Register Field information for DMA_WRITE_DONE_IMWR_HIGH_OFF */

/* Register DMA_WRITE_DONE_IMWR_HIGH_OFF field DMA_WRITE_DONE_HIGH_REG */
/* The DMA uses this field to generate bits [63:32] of the address field for the Done IMWr TLP. */
#define DMA_WRITE_DONE_IMWR_HIGH_OFF_DMA_WRITE_DONE_HIGH_REG_BitAddressOffset 0
#define DMA_WRITE_DONE_IMWR_HIGH_OFF_DMA_WRITE_DONE_HIGH_REG_RegisterSize 32

/* End of Register Definition for DMA_WRITE_DONE_IMWR_HIGH_OFF */

/* Register DMA_WRITE_ABORT_IMWR_LOW_OFF */
/* DMA Write Abort IMWr Address Low Register. This register is implemented in RAM whose contents are uninitialized after power-on. Therefore, you must program and initialize every field as the default is undefined. All fields marked "Reserved" MUST be programmed to 1'b0. This register is not affected by any of the reset signals. */
#define DMA_WRITE_ABORT_IMWR_LOW_OFF (PF0_PORT_LOGIC_BaseAddress + 0x2d8)
#define DMA_WRITE_ABORT_IMWR_LOW_OFF_RegisterSize 32
#define DMA_WRITE_ABORT_IMWR_LOW_OFF_RegisterResetValue 0x0
#define DMA_WRITE_ABORT_IMWR_LOW_OFF_RegisterResetMask 0x0

/* Register Field information for DMA_WRITE_ABORT_IMWR_LOW_OFF */

/* Register DMA_WRITE_ABORT_IMWR_LOW_OFF field DMA_WRITE_ABORT_LOW_REG */
/* The DMA uses this field to generate bits [31:0] of the address field for the Abort IMWr TLP it generates. Bits [1:0] must be "00" as this address must be dword aligned. */
#define DMA_WRITE_ABORT_IMWR_LOW_OFF_DMA_WRITE_ABORT_LOW_REG_BitAddressOffset 0
#define DMA_WRITE_ABORT_IMWR_LOW_OFF_DMA_WRITE_ABORT_LOW_REG_RegisterSize 32

/* End of Register Definition for DMA_WRITE_ABORT_IMWR_LOW_OFF */

/* Register DMA_WRITE_ABORT_IMWR_HIGH_OFF */
/* DMA Write Abort IMWr Address High Register. This register is implemented in RAM whose contents are uninitialized after power-on. Therefore, you must program and initialize every field as the default is undefined. All fields marked "Reserved" MUST be programmed to 1'b0. This register is not affected by any of the reset signals. */
#define DMA_WRITE_ABORT_IMWR_HIGH_OFF (PF0_PORT_LOGIC_BaseAddress + 0x2dc)
#define DMA_WRITE_ABORT_IMWR_HIGH_OFF_RegisterSize 32
#define DMA_WRITE_ABORT_IMWR_HIGH_OFF_RegisterResetValue 0x0
#define DMA_WRITE_ABORT_IMWR_HIGH_OFF_RegisterResetMask 0x0

/* Register Field information for DMA_WRITE_ABORT_IMWR_HIGH_OFF */

/* Register DMA_WRITE_ABORT_IMWR_HIGH_OFF field DMA_WRITE_ABORT_HIGH_REG */
/* The DMA uses this field to generate bits [63:32] of the address field for the Abort IMWr TLP. */
#define DMA_WRITE_ABORT_IMWR_HIGH_OFF_DMA_WRITE_ABORT_HIGH_REG_BitAddressOffset 0
#define DMA_WRITE_ABORT_IMWR_HIGH_OFF_DMA_WRITE_ABORT_HIGH_REG_RegisterSize 32

/* End of Register Definition for DMA_WRITE_ABORT_IMWR_HIGH_OFF */

/* Register DMA_WRITE_CH01_IMWR_DATA_OFF */
/* DMA Write Channel 1 and 0 IMWr Data Register. This register is implemented in RAM whose contents are uninitialized after power-on. Therefore, you must program and initialize every field as the default is undefined. All fields marked "Reserved" MUST be programmed to 1'b0. This register is not affected by any of the reset signals. */
#define DMA_WRITE_CH01_IMWR_DATA_OFF (PF0_PORT_LOGIC_BaseAddress + 0x2e0)
#define DMA_WRITE_CH01_IMWR_DATA_OFF_RegisterSize 32
#define DMA_WRITE_CH01_IMWR_DATA_OFF_RegisterResetValue 0x0
#define DMA_WRITE_CH01_IMWR_DATA_OFF_RegisterResetMask 0x0

/* Register Field information for DMA_WRITE_CH01_IMWR_DATA_OFF */

/* Register DMA_WRITE_CH01_IMWR_DATA_OFF field WR_CHANNEL_0_DATA */
/* The DMA uses this field to generate the data field for the Done or Abort IMWr TLPs it generates for write channel 0. */
#define DMA_WRITE_CH01_IMWR_DATA_OFF_WR_CHANNEL_0_DATA_BitAddressOffset 0
#define DMA_WRITE_CH01_IMWR_DATA_OFF_WR_CHANNEL_0_DATA_RegisterSize 16

/* Register DMA_WRITE_CH01_IMWR_DATA_OFF field WR_CHANNEL_1_DATA */
/* The DMA uses this field to generate the data field for the Done or Abort IMWr TLPs it generates for write channel 1. */
#define DMA_WRITE_CH01_IMWR_DATA_OFF_WR_CHANNEL_1_DATA_BitAddressOffset 16
#define DMA_WRITE_CH01_IMWR_DATA_OFF_WR_CHANNEL_1_DATA_RegisterSize 16

/* End of Register Definition for DMA_WRITE_CH01_IMWR_DATA_OFF */

/* Register DMA_WRITE_CH23_IMWR_DATA_OFF */
/* DMA Write Channel 3 and 2 IMWr Data Register. This register is implemented in RAM whose contents are uninitialized after power-on. Therefore, you must program and initialize every field as the default is undefined. All fields marked "Reserved" MUST be programmed to 1'b0. This register is not affected by any of the reset signals. */
#define DMA_WRITE_CH23_IMWR_DATA_OFF (PF0_PORT_LOGIC_BaseAddress + 0x2e4)
#define DMA_WRITE_CH23_IMWR_DATA_OFF_RegisterSize 32
#define DMA_WRITE_CH23_IMWR_DATA_OFF_RegisterResetValue 0x0
#define DMA_WRITE_CH23_IMWR_DATA_OFF_RegisterResetMask 0x0

/* Register Field information for DMA_WRITE_CH23_IMWR_DATA_OFF */

/* Register DMA_WRITE_CH23_IMWR_DATA_OFF field WR_CHANNEL_2_DATA */
/* The DMA uses this field to generate the data field for the Done or Abort IMWr TLPs it generates for write channel 2. */
#define DMA_WRITE_CH23_IMWR_DATA_OFF_WR_CHANNEL_2_DATA_BitAddressOffset 0
#define DMA_WRITE_CH23_IMWR_DATA_OFF_WR_CHANNEL_2_DATA_RegisterSize 16

/* Register DMA_WRITE_CH23_IMWR_DATA_OFF field WR_CHANNEL_3_DATA */
/* The DMA uses this field to generate the data field for the Done or Abort IMWr TLPs it generates for write channel 3. */
#define DMA_WRITE_CH23_IMWR_DATA_OFF_WR_CHANNEL_3_DATA_BitAddressOffset 16
#define DMA_WRITE_CH23_IMWR_DATA_OFF_WR_CHANNEL_3_DATA_RegisterSize 16

/* End of Register Definition for DMA_WRITE_CH23_IMWR_DATA_OFF */

/* Register DMA_WRITE_CH45_IMWR_DATA_OFF */
/* DMA Write Channel 5 and 4 IMWr Data Register. This register is implemented in RAM whose contents are uninitialized after power-on. Therefore, you must program and initialize every field as the default is undefined. All fields marked "Reserved" MUST be programmed to 1'b0. This register is not affected by any of the reset signals. */
#define DMA_WRITE_CH45_IMWR_DATA_OFF (PF0_PORT_LOGIC_BaseAddress + 0x2e8)
#define DMA_WRITE_CH45_IMWR_DATA_OFF_RegisterSize 32
#define DMA_WRITE_CH45_IMWR_DATA_OFF_RegisterResetValue 0x0
#define DMA_WRITE_CH45_IMWR_DATA_OFF_RegisterResetMask 0xffffffff

/* Register Field information for DMA_WRITE_CH45_IMWR_DATA_OFF */

/* Register DMA_WRITE_CH45_IMWR_DATA_OFF field WR_CHANNEL_4_DATA */
/* The DMA uses this field to generate the data field for the Done or Abort IMWr TLPs it generates for write channel 4. */
#define DMA_WRITE_CH45_IMWR_DATA_OFF_WR_CHANNEL_4_DATA_BitAddressOffset 0
#define DMA_WRITE_CH45_IMWR_DATA_OFF_WR_CHANNEL_4_DATA_RegisterSize 16

/* Register DMA_WRITE_CH45_IMWR_DATA_OFF field WR_CHANNEL_5_DATA */
/* The DMA uses this field to generate the data field for the Done or Abort IMWr TLPs it generates for write channel 5. */
#define DMA_WRITE_CH45_IMWR_DATA_OFF_WR_CHANNEL_5_DATA_BitAddressOffset 16
#define DMA_WRITE_CH45_IMWR_DATA_OFF_WR_CHANNEL_5_DATA_RegisterSize 16

/* End of Register Definition for DMA_WRITE_CH45_IMWR_DATA_OFF */

/* Register DMA_WRITE_CH67_IMWR_DATA_OFF */
/* DMA Write Channel 7 and 6 IMWr Data Register. This register is implemented in RAM whose contents are uninitialized after power-on. Therefore, you must program and initialize every field as the default is undefined. All fields marked "Reserved" MUST be programmed to 1'b0. This register is not affected by any of the reset signals. */
#define DMA_WRITE_CH67_IMWR_DATA_OFF (PF0_PORT_LOGIC_BaseAddress + 0x2ec)
#define DMA_WRITE_CH67_IMWR_DATA_OFF_RegisterSize 32
#define DMA_WRITE_CH67_IMWR_DATA_OFF_RegisterResetValue 0x0
#define DMA_WRITE_CH67_IMWR_DATA_OFF_RegisterResetMask 0x0

/* Register Field information for DMA_WRITE_CH67_IMWR_DATA_OFF */

/* Register DMA_WRITE_CH67_IMWR_DATA_OFF field WR_CHANNEL_6_DATA */
/* The DMA uses this field to generate the data field for the Done or Abort IMWr TLPs it generates for write channel 6. */
#define DMA_WRITE_CH67_IMWR_DATA_OFF_WR_CHANNEL_6_DATA_BitAddressOffset 0
#define DMA_WRITE_CH67_IMWR_DATA_OFF_WR_CHANNEL_6_DATA_RegisterSize 16

/* Register DMA_WRITE_CH67_IMWR_DATA_OFF field WR_CHANNEL_7_DATA */
/* The DMA uses this field to generate the data field for the Done or Abort IMWr TLPs it generates for write channel 7. */
#define DMA_WRITE_CH67_IMWR_DATA_OFF_WR_CHANNEL_7_DATA_BitAddressOffset 16
#define DMA_WRITE_CH67_IMWR_DATA_OFF_WR_CHANNEL_7_DATA_RegisterSize 16

/* End of Register Definition for DMA_WRITE_CH67_IMWR_DATA_OFF */

/* Register DMA_WRITE_LINKED_LIST_ERR_EN_OFF */
/* DMA Write Linked List Error Enable Register. The LIE and RIE bits in the LL element enable the channel "done" interrupts (local and remote). The LLLAIE and LLRAIE bits enable the channel "abort" interrupts (local and remote). */
#define DMA_WRITE_LINKED_LIST_ERR_EN_OFF (PF0_PORT_LOGIC_BaseAddress + 0x300)
#define DMA_WRITE_LINKED_LIST_ERR_EN_OFF_RegisterSize 32
#define DMA_WRITE_LINKED_LIST_ERR_EN_OFF_RegisterResetValue 0x0
#define DMA_WRITE_LINKED_LIST_ERR_EN_OFF_RegisterResetMask 0xffffffff

/* Register Field information for DMA_WRITE_LINKED_LIST_ERR_EN_OFF */

/* Register DMA_WRITE_LINKED_LIST_ERR_EN_OFF field WR_CHANNEL_LLRAIE */
/* Write Channel LL Remote Abort Interrupt Enable (LLRAIE). You enable the write channel remote abort interrupt through this bit. The LIE and RIE bits in the LL element enable the write channel done interrupts. Each bit corresponds to a DMA channel. Bit [0] corresponds to channel 0.
Used in linked list mode only.
For more details, see "Interrupt Handling". */
#define DMA_WRITE_LINKED_LIST_ERR_EN_OFF_WR_CHANNEL_LLRAIE_BitAddressOffset 0
#define DMA_WRITE_LINKED_LIST_ERR_EN_OFF_WR_CHANNEL_LLRAIE_RegisterSize 1

/* Register DMA_WRITE_LINKED_LIST_ERR_EN_OFF field RSVDP_8 */
/* Reserved for future use. */
#define DMA_WRITE_LINKED_LIST_ERR_EN_OFF_RSVDP_8_BitAddressOffset 8
#define DMA_WRITE_LINKED_LIST_ERR_EN_OFF_RSVDP_8_RegisterSize 8

/* Register DMA_WRITE_LINKED_LIST_ERR_EN_OFF field WR_CHANNEL_LLLAIE */
/* Write Channel LL Local Abort Interrupt Enable (LLLAIE). You enable the write channel local abort interrupt through this bit. The LIE and RIE bits in the LL element enable the write channel done interrupts. Each bit corresponds to a DMA channel. Bit [0] corresponds to channel 0.
Used in linked list mode only.
For more details, see "Interrupt Handling". */
#define DMA_WRITE_LINKED_LIST_ERR_EN_OFF_WR_CHANNEL_LLLAIE_BitAddressOffset 16
#define DMA_WRITE_LINKED_LIST_ERR_EN_OFF_WR_CHANNEL_LLLAIE_RegisterSize 1

/* Register DMA_WRITE_LINKED_LIST_ERR_EN_OFF field RSVDP_24 */
/* Reserved for future use. */
#define DMA_WRITE_LINKED_LIST_ERR_EN_OFF_RSVDP_24_BitAddressOffset 24
#define DMA_WRITE_LINKED_LIST_ERR_EN_OFF_RSVDP_24_RegisterSize 8

/* End of Register Definition for DMA_WRITE_LINKED_LIST_ERR_EN_OFF */

/* Register DMA_READ_INT_STATUS_OFF */
/* DMA Read Interrupt Status Register. */
#define DMA_READ_INT_STATUS_OFF (PF0_PORT_LOGIC_BaseAddress + 0x310)
#define DMA_READ_INT_STATUS_OFF_RegisterSize 32
#define DMA_READ_INT_STATUS_OFF_RegisterResetValue 0x0
#define DMA_READ_INT_STATUS_OFF_RegisterResetMask 0xffffffff

/* Register Field information for DMA_READ_INT_STATUS_OFF */

/* Register DMA_READ_INT_STATUS_OFF field RD_DONE_INT_STATUS */
/* Done Interrupt Status. The DMA read channel has successfully completed the DMA read transfer.
Each bit corresponds to a DMA channel. Bit [0] corresponds to channel 0.
 - Enabling: For details, see "Interrupts and Error Handling".
 - Masking: The DMA read interrupt Mask register has no effect on this register.
 - Clearing: You must write a 1'b1 to the corresponding channel bit in the DMA read interrupt Clear register to clear this interrupt bit.
<b> Note:</b> You can write to this register to emulate interrupt generation, during software or hardware testing. A write to the address triggers an interrupt, but the DMA does not set the Done or Abort bits in this register. */
#define DMA_READ_INT_STATUS_OFF_RD_DONE_INT_STATUS_BitAddressOffset 0
#define DMA_READ_INT_STATUS_OFF_RD_DONE_INT_STATUS_RegisterSize 8

/* Register DMA_READ_INT_STATUS_OFF field RSVDP_8 */
/* Reserved for future use. */
#define DMA_READ_INT_STATUS_OFF_RSVDP_8_BitAddressOffset 8
#define DMA_READ_INT_STATUS_OFF_RSVDP_8_RegisterSize 8

/* Register DMA_READ_INT_STATUS_OFF field RD_ABORT_INT_STATUS */
/* Abort Interrupt Status. The DMA read channel has detected an error, or you manually stopped the transfer as described in "Stopping the DMA Transfer (Software Stop)". Each bit corresponds to a DMA channel. Bit [0] corresponds to channel 0.
You can read the "DMA Read Error Status Low Register" (DMA_READ_ERR_STATUS_LOW_OFF) and "DMA Read Error Status High Register" (DMA_READ_ERR_STATUS_HIGH_OFF) to determine the source of the error.
 - Enabling: For details, see "Interrupts and Error Handling".
 - Masking: The DMA read interrupt Mask register has no effect on this register.
 - Clearing: You must write a 1'b1 to the corresponding channel bit in the DMA read interrupt Clear register to clear this interrupt bit.
<b> Note:</b> You can write to this register to emulate interrupt generation, during software or hardware testing. A write to the address triggers an interrupt, but the DMA does not set the Done or Abort bits in this register. */
#define DMA_READ_INT_STATUS_OFF_RD_ABORT_INT_STATUS_BitAddressOffset 16
#define DMA_READ_INT_STATUS_OFF_RD_ABORT_INT_STATUS_RegisterSize 8

/* Register DMA_READ_INT_STATUS_OFF field RSVDP_24 */
/* Reserved for future use. */
#define DMA_READ_INT_STATUS_OFF_RSVDP_24_BitAddressOffset 24
#define DMA_READ_INT_STATUS_OFF_RSVDP_24_RegisterSize 8

/* End of Register Definition for DMA_READ_INT_STATUS_OFF */

/* Register DMA_READ_INT_MASK_OFF */
/* DMA Read Interrupt Mask Register. */
#define DMA_READ_INT_MASK_OFF (PF0_PORT_LOGIC_BaseAddress + 0x318)
#define DMA_READ_INT_MASK_OFF_RegisterSize 32
#define DMA_READ_INT_MASK_OFF_RegisterResetValue 0x10001
#define DMA_READ_INT_MASK_OFF_RegisterResetMask 0xffffffff

/* Register Field information for DMA_READ_INT_MASK_OFF */

/* Register DMA_READ_INT_MASK_OFF field RD_DONE_INT_MASK */
/* Done Interrupt Mask. Prevents the Done interrupt status field in the DMA read interrupt status register from asserting the edma_int output. Each bit corresponds to a DMA channel. Bit [0] corresponds to channel 0. */
#define DMA_READ_INT_MASK_OFF_RD_DONE_INT_MASK_BitAddressOffset 0
#define DMA_READ_INT_MASK_OFF_RD_DONE_INT_MASK_RegisterSize 1

/* Register DMA_READ_INT_MASK_OFF field RSVDP_8 */
/* Reserved for future use. */
#define DMA_READ_INT_MASK_OFF_RSVDP_8_BitAddressOffset 8
#define DMA_READ_INT_MASK_OFF_RSVDP_8_RegisterSize 8

/* Register DMA_READ_INT_MASK_OFF field RD_ABORT_INT_MASK */
/* Abort Interrupt Mask. Prevents the Abort interrupt status field in the DMA read interrupt status register from asserting the edma_int output. Each bit corresponds to a DMA channel. Bit [0] corresponds to channel 0. */
#define DMA_READ_INT_MASK_OFF_RD_ABORT_INT_MASK_BitAddressOffset 16
#define DMA_READ_INT_MASK_OFF_RD_ABORT_INT_MASK_RegisterSize 1

/* Register DMA_READ_INT_MASK_OFF field RSVDP_24 */
/* Reserved for future use. */
#define DMA_READ_INT_MASK_OFF_RSVDP_24_BitAddressOffset 24
#define DMA_READ_INT_MASK_OFF_RSVDP_24_RegisterSize 8

/* End of Register Definition for DMA_READ_INT_MASK_OFF */

/* Register DMA_READ_INT_CLEAR_OFF */
/* DMA Read Interrupt Clear Register. */
#define DMA_READ_INT_CLEAR_OFF (PF0_PORT_LOGIC_BaseAddress + 0x31c)
#define DMA_READ_INT_CLEAR_OFF_RegisterSize 32
#define DMA_READ_INT_CLEAR_OFF_RegisterResetValue 0x0
#define DMA_READ_INT_CLEAR_OFF_RegisterResetMask 0xffffffff

/* Register Field information for DMA_READ_INT_CLEAR_OFF */

/* Register DMA_READ_INT_CLEAR_OFF field RD_DONE_INT_CLEAR */
/* Done Interrupt Clear. You must write a 1'b1 to clear the corresponding bit in the Done interrupt status field of the DMA read interrupt status register. Each bit corresponds to a DMA channel. Bit [0] corresponds to channel 0.
<br><b>Note:</b> Reading from this self-clearing register field always returns a "0". */
#define DMA_READ_INT_CLEAR_OFF_RD_DONE_INT_CLEAR_BitAddressOffset 0
#define DMA_READ_INT_CLEAR_OFF_RD_DONE_INT_CLEAR_RegisterSize 8

/* Register DMA_READ_INT_CLEAR_OFF field RSVDP_8 */
/* Reserved for future use. */
#define DMA_READ_INT_CLEAR_OFF_RSVDP_8_BitAddressOffset 8
#define DMA_READ_INT_CLEAR_OFF_RSVDP_8_RegisterSize 8

/* Register DMA_READ_INT_CLEAR_OFF field RD_ABORT_INT_CLEAR */
/* Abort Interrupt Clear. You must write a 1'b1 to clear the corresponding bit in the Abort interrupt status field of the DMA read interrupt status register. Each bit corresponds to a DMA channel. Bit [0] corresponds to channel 0.
<br><b>Note:</b> Reading from this self-clearing register field always returns a "0". */
#define DMA_READ_INT_CLEAR_OFF_RD_ABORT_INT_CLEAR_BitAddressOffset 16
#define DMA_READ_INT_CLEAR_OFF_RD_ABORT_INT_CLEAR_RegisterSize 8

/* Register DMA_READ_INT_CLEAR_OFF field RSVDP_24 */
/* Reserved for future use. */
#define DMA_READ_INT_CLEAR_OFF_RSVDP_24_BitAddressOffset 24
#define DMA_READ_INT_CLEAR_OFF_RSVDP_24_RegisterSize 8

/* End of Register Definition for DMA_READ_INT_CLEAR_OFF */

/* Register DMA_READ_ERR_STATUS_LOW_OFF */
/* DMA Read Error Status Low Register. */
#define DMA_READ_ERR_STATUS_LOW_OFF (PF0_PORT_LOGIC_BaseAddress + 0x324)
#define DMA_READ_ERR_STATUS_LOW_OFF_RegisterSize 32
#define DMA_READ_ERR_STATUS_LOW_OFF_RegisterResetValue 0x0
#define DMA_READ_ERR_STATUS_LOW_OFF_RegisterResetMask 0xffffffff

/* Register Field information for DMA_READ_ERR_STATUS_LOW_OFF */

/* Register DMA_READ_ERR_STATUS_LOW_OFF field APP_WR_ERR_DETECT */
/* Application Write Error Detected. The DMA read channel has received an error response from the AHB/AXI bus (or TRGT1 interface when the AHB/AXI Bridge is not used) while writing data to it. This error is fatal. You must restart the transfer from the beginning, as the channel context is corrupted, and the transfer is not rolled back. For more details, see "Linked List Mode". Each bit corresponds to a DMA channel. Bit [0] corresponds to channel 0.
 - Enabling: For details, see "Interrupts and Error Handling".
 - Masking: The DMA read interrupt Mask register has no effect on this register.
 - Clearing: You must write a 1'b1 to the corresponding channel bit in the Abort interrupt field of the "DMA Read Interrupt Clear Register" (DMA_READ_INT_CLEAR_OFF) to clear this error bit. Note, this clears all bits in this register, and also the DMA Read Error Status High register (DMA_READ_ERR_STATUS_HIGH_OFF). */
#define DMA_READ_ERR_STATUS_LOW_OFF_APP_WR_ERR_DETECT_BitAddressOffset 0
#define DMA_READ_ERR_STATUS_LOW_OFF_APP_WR_ERR_DETECT_RegisterSize 8

/* Register DMA_READ_ERR_STATUS_LOW_OFF field RSVDP_8 */
/* Reserved for future use. */
#define DMA_READ_ERR_STATUS_LOW_OFF_RSVDP_8_BitAddressOffset 8
#define DMA_READ_ERR_STATUS_LOW_OFF_RSVDP_8_RegisterSize 8

/* Register DMA_READ_ERR_STATUS_LOW_OFF field LINK_LIST_ELEMENT_FETCH_ERR_DETECT */
/* Linked List Element Fetch Error Detected.
 - The DMA read channel has received an error response from the AHB/AXI bus while reading a linked list element from local memory. Each bit corresponds to a DMA channel. Bit [0] corresponds to channel 0.
 - Enabling: For details, see "Interrupts and Error Handling".
 - Masking: The DMA read interrupt Mask register has no effect on this register.
 - Clearing: You must write a 1'b1 to the corresponding channel bit in the Abort interrupt field of the "DMA Read Interrupt Clear Register" (DMA_READ_INT_CLEAR_OFF) to clear this error bit. Note, this clears all bits in this register, and also the DMA Read Error Status High register (DMA_READ_ERR_STATUS_HIGH_OFF). */
#define DMA_READ_ERR_STATUS_LOW_OFF_LINK_LIST_ELEMENT_FETCH_ERR_DETECT_BitAddressOffset 16
#define DMA_READ_ERR_STATUS_LOW_OFF_LINK_LIST_ELEMENT_FETCH_ERR_DETECT_RegisterSize 8

/* Register DMA_READ_ERR_STATUS_LOW_OFF field RSVDP_24 */
/* Reserved for future use. */
#define DMA_READ_ERR_STATUS_LOW_OFF_RSVDP_24_BitAddressOffset 24
#define DMA_READ_ERR_STATUS_LOW_OFF_RSVDP_24_RegisterSize 8

/* End of Register Definition for DMA_READ_ERR_STATUS_LOW_OFF */

/* Register DMA_READ_ERR_STATUS_HIGH_OFF */
/* DMA Read Error Status High Register. */
#define DMA_READ_ERR_STATUS_HIGH_OFF (PF0_PORT_LOGIC_BaseAddress + 0x328)
#define DMA_READ_ERR_STATUS_HIGH_OFF_RegisterSize 32
#define DMA_READ_ERR_STATUS_HIGH_OFF_RegisterResetValue 0x0
#define DMA_READ_ERR_STATUS_HIGH_OFF_RegisterResetMask 0xffffffff

/* Register Field information for DMA_READ_ERR_STATUS_HIGH_OFF */

/* Register DMA_READ_ERR_STATUS_HIGH_OFF field UNSUPPORTED_REQ */
/* Unsupported Request. The DMA read channel has received a PCIe unsupported request completion status from the remote device in response to the MRd request. For more details, see "Linked List Mode". Each bit corresponds to a DMA channel. Bit [0] corresponds to channel 0.
 - Enabling: For details, see "Interrupts and Error Handling".
 - Masking: The DMA read interrupt Mask register has no effect on this register.
 - Clearing: You must write a 1'b1 to the corresponding channel bit in the Abort interrupt field of the "DMA Read Interrupt Clear Register" (DMA_READ_INT_CLEAR_OFF) to clear this error bit. Note, this also clears the other error bits for the same channel in this register and in the DMA Read Error Status Low register. */
#define DMA_READ_ERR_STATUS_HIGH_OFF_UNSUPPORTED_REQ_BitAddressOffset 0
#define DMA_READ_ERR_STATUS_HIGH_OFF_UNSUPPORTED_REQ_RegisterSize 8

/* Register DMA_READ_ERR_STATUS_HIGH_OFF field CPL_ABORT */
/* Completer Abort. The DMA read channel has received a PCIe completer abort completion status from the remote device in response to the MRd request. For more details, see "Linked List Mode".
Each bit corresponds to a DMA channel. Bit [0] corresponds to channel 0.
 - Enabling: For details, see "Interrupts and Error Handling".
 - Masking: The DMA read interrupt Mask register has no effect on this register.
 - Clearing: You must write a 1'b1 to the corresponding channel bit in the Abort interrupt field of the "DMA Read Interrupt Clear Register" (DMA_READ_INT_CLEAR_OFF) to clear this error bit. Note, this also clears the other error bits for the same channel in this register and in the DMA Read Error Status Low register. */
#define DMA_READ_ERR_STATUS_HIGH_OFF_CPL_ABORT_BitAddressOffset 8
#define DMA_READ_ERR_STATUS_HIGH_OFF_CPL_ABORT_RegisterSize 8

/* Register DMA_READ_ERR_STATUS_HIGH_OFF field CPL_TIMEOUT */
/* Completion Time Out. The DMA read channel has timed-out while waiting for the remote device to respond to the MRd request, or a malformed CplD has been received. For more details, see "Linked List Mode". Each bit corresponds to a DMA channel. Bit [0] corresponds to channel 0.
 - Enabling: For details, see "Interrupts and Error Handling" .
 - Masking: The DMA read interrupt Mask register has no effect on this register.
 - Clearing: You must write a 1'b1 to the corresponding channel bit in the Abort interrupt field of the "DMA Read Interrupt Clear Register" (DMA_READ_INT_CLEAR_OFF) to clear this error bit. Note, this also clears the other error bits for the same channel in this register and in the DMA Read Error Status Low register. */
#define DMA_READ_ERR_STATUS_HIGH_OFF_CPL_TIMEOUT_BitAddressOffset 16
#define DMA_READ_ERR_STATUS_HIGH_OFF_CPL_TIMEOUT_RegisterSize 8

/* Register DMA_READ_ERR_STATUS_HIGH_OFF field DATA_POISIONING */
/* Data Poisoning. The DMA read channel has detected data poisoning in the completion from the remote device (in response to the MRd request).
The DMA read channel will drop the completion and then be halted. The CX_FLT_MASK_UR_POIS filter rule does not affect this behavior.
Each bit corresponds to a DMA channel. Bit [0] corresponds to channel 0.
 - Enabling: For details, see "Interrupts and Error Handling".
 - Masking: The DMA read interrupt Mask register has no effect on this register.
 - Clearing: You must write a 1'b1 to the corresponding channel bit in the Abort interrupt field of the "DMA Read Interrupt Clear Register" (DMA_READ_INT_CLEAR_OFF) to clear this error bit. Note, this also clears the other error bits for the same channel in this register and in the DMA Read Error Status Low register. */
#define DMA_READ_ERR_STATUS_HIGH_OFF_DATA_POISIONING_BitAddressOffset 24
#define DMA_READ_ERR_STATUS_HIGH_OFF_DATA_POISIONING_RegisterSize 8

/* End of Register Definition for DMA_READ_ERR_STATUS_HIGH_OFF */

/* Register DMA_READ_LINKED_LIST_ERR_EN_OFF */
/* DMA Read Linked List Error Enable Register. The LIE and RIE bits in the LL element enable the channel "done" interrupts (local and remote). The LLLAIE and LLRAIE bits enable the channel "abort" interrupts (local and remote). */
#define DMA_READ_LINKED_LIST_ERR_EN_OFF (PF0_PORT_LOGIC_BaseAddress + 0x334)
#define DMA_READ_LINKED_LIST_ERR_EN_OFF_RegisterSize 32
#define DMA_READ_LINKED_LIST_ERR_EN_OFF_RegisterResetValue 0x0
#define DMA_READ_LINKED_LIST_ERR_EN_OFF_RegisterResetMask 0xffffffff

/* Register Field information for DMA_READ_LINKED_LIST_ERR_EN_OFF */

/* Register DMA_READ_LINKED_LIST_ERR_EN_OFF field RD_CHANNEL_LLRAIE */
/* Read Channel LL Remote Abort Interrupt Enable (LLRAIE). You enable the read channel Remote Abort interrupt through this bit. The LIE and RIE bits in the LL element enable the read channel done interrupts. Each bit corresponds to a DMA channel. Bit [0] corresponds to channel 0.
Used in linked list mode only.
For more details, see "Interrupt Handling". */
#define DMA_READ_LINKED_LIST_ERR_EN_OFF_RD_CHANNEL_LLRAIE_BitAddressOffset 0
#define DMA_READ_LINKED_LIST_ERR_EN_OFF_RD_CHANNEL_LLRAIE_RegisterSize 1

/* Register DMA_READ_LINKED_LIST_ERR_EN_OFF field RSVDP_8 */
/* Reserved for future use. */
#define DMA_READ_LINKED_LIST_ERR_EN_OFF_RSVDP_8_BitAddressOffset 8
#define DMA_READ_LINKED_LIST_ERR_EN_OFF_RSVDP_8_RegisterSize 8

/* Register DMA_READ_LINKED_LIST_ERR_EN_OFF field RD_CHANNEL_LLLAIE */
/* Read Channel LL Local Abort Interrupt Enable (LLLAIE). You enable the read channel Local Abort interrupt through this bit. The LIE and RIE bits in the LL element enable the read channel done interrupts. Each bit corresponds to a DMA channel. Bit [0] corresponds to channel 0.
Used in linked list mode only.
For more details, see "Interrupt Handling". */
#define DMA_READ_LINKED_LIST_ERR_EN_OFF_RD_CHANNEL_LLLAIE_BitAddressOffset 16
#define DMA_READ_LINKED_LIST_ERR_EN_OFF_RD_CHANNEL_LLLAIE_RegisterSize 1

/* Register DMA_READ_LINKED_LIST_ERR_EN_OFF field RSVDP_24 */
/* Reserved for future use. */
#define DMA_READ_LINKED_LIST_ERR_EN_OFF_RSVDP_24_BitAddressOffset 24
#define DMA_READ_LINKED_LIST_ERR_EN_OFF_RSVDP_24_RegisterSize 8

/* End of Register Definition for DMA_READ_LINKED_LIST_ERR_EN_OFF */

/* Register DMA_READ_DONE_IMWR_LOW_OFF */
/* DMA Read Done IMWr Address Low Register. This register is implemented in RAM whose contents are uninitialized after power-on. Therefore, you must always initialize this register value because the default is undefined. All fields marked "Reserved" MUST be programmed to 1'b0. This register is not affected by any of the reset signals. */
#define DMA_READ_DONE_IMWR_LOW_OFF (PF0_PORT_LOGIC_BaseAddress + 0x33c)
#define DMA_READ_DONE_IMWR_LOW_OFF_RegisterSize 32
#define DMA_READ_DONE_IMWR_LOW_OFF_RegisterResetValue 0x0
#define DMA_READ_DONE_IMWR_LOW_OFF_RegisterResetMask 0x0

/* Register Field information for DMA_READ_DONE_IMWR_LOW_OFF */

/* Register DMA_READ_DONE_IMWR_LOW_OFF field DMA_READ_DONE_LOW_REG */
/* The DMA uses this field to generate bits [31:0] of the address field for the Done IMWr TLP. Bits [1:0] must be "00" as this address must be dword aligned. */
#define DMA_READ_DONE_IMWR_LOW_OFF_DMA_READ_DONE_LOW_REG_BitAddressOffset 0
#define DMA_READ_DONE_IMWR_LOW_OFF_DMA_READ_DONE_LOW_REG_RegisterSize 32

/* End of Register Definition for DMA_READ_DONE_IMWR_LOW_OFF */

/* Register DMA_READ_DONE_IMWR_HIGH_OFF */
/* DMA Read Done IMWr Address High Register. This register is implemented in RAM whose contents are uninitialized after power-on. Therefore, you must always initialize this register value because the default is undefined. All fields marked "Reserved" MUST be programmed to 1'b0. This register is not affected by any of the reset signals. */
#define DMA_READ_DONE_IMWR_HIGH_OFF (PF0_PORT_LOGIC_BaseAddress + 0x340)
#define DMA_READ_DONE_IMWR_HIGH_OFF_RegisterSize 32
#define DMA_READ_DONE_IMWR_HIGH_OFF_RegisterResetValue 0x0
#define DMA_READ_DONE_IMWR_HIGH_OFF_RegisterResetMask 0x0

/* Register Field information for DMA_READ_DONE_IMWR_HIGH_OFF */

/* Register DMA_READ_DONE_IMWR_HIGH_OFF field DMA_READ_DONE_HIGH_REG */
/* The DMA uses this field to generate bits [63:32] of the address field for the Done IMWr TLP. */
#define DMA_READ_DONE_IMWR_HIGH_OFF_DMA_READ_DONE_HIGH_REG_BitAddressOffset 0
#define DMA_READ_DONE_IMWR_HIGH_OFF_DMA_READ_DONE_HIGH_REG_RegisterSize 32

/* End of Register Definition for DMA_READ_DONE_IMWR_HIGH_OFF */

/* Register DMA_READ_ABORT_IMWR_LOW_OFF */
/* DMA Read Abort IMWr Address Low Register. This register is implemented in RAM whose contents are uninitialized after power-on. Therefore, you must always initialize this register value because the default is undefined. All fields marked "Reserved" MUST be programmed to 1'b0. This register is not affected by any of the reset signals. */
#define DMA_READ_ABORT_IMWR_LOW_OFF (PF0_PORT_LOGIC_BaseAddress + 0x344)
#define DMA_READ_ABORT_IMWR_LOW_OFF_RegisterSize 32
#define DMA_READ_ABORT_IMWR_LOW_OFF_RegisterResetValue 0x0
#define DMA_READ_ABORT_IMWR_LOW_OFF_RegisterResetMask 0x0

/* Register Field information for DMA_READ_ABORT_IMWR_LOW_OFF */

/* Register DMA_READ_ABORT_IMWR_LOW_OFF field DMA_READ_ABORT_LOW_REG */
/* The DMA uses this field to generate bits [31:0] of the address field for the Abort IMWr TLP. Bits [1:0] must be "00" as this address must be dword aligned. */
#define DMA_READ_ABORT_IMWR_LOW_OFF_DMA_READ_ABORT_LOW_REG_BitAddressOffset 0
#define DMA_READ_ABORT_IMWR_LOW_OFF_DMA_READ_ABORT_LOW_REG_RegisterSize 32

/* End of Register Definition for DMA_READ_ABORT_IMWR_LOW_OFF */

/* Register DMA_READ_ABORT_IMWR_HIGH_OFF */
/* DMA Read Abort IMWr Address High Register. This register is implemented in RAM whose contents are uninitialized after power-on. Therefore, you must always initialize this register value because the default is undefined. All fields marked "Reserved" MUST be programmed to 1'b0. This register is not affected by any of the reset signals. */
#define DMA_READ_ABORT_IMWR_HIGH_OFF (PF0_PORT_LOGIC_BaseAddress + 0x348)
#define DMA_READ_ABORT_IMWR_HIGH_OFF_RegisterSize 32
#define DMA_READ_ABORT_IMWR_HIGH_OFF_RegisterResetValue 0x0
#define DMA_READ_ABORT_IMWR_HIGH_OFF_RegisterResetMask 0x0

/* Register Field information for DMA_READ_ABORT_IMWR_HIGH_OFF */

/* Register DMA_READ_ABORT_IMWR_HIGH_OFF field DMA_READ_ABORT_HIGH_REG */
/* The DMA uses this field to generate bits [63:32] of the address field for the Abort IMWr TLP. */
#define DMA_READ_ABORT_IMWR_HIGH_OFF_DMA_READ_ABORT_HIGH_REG_BitAddressOffset 0
#define DMA_READ_ABORT_IMWR_HIGH_OFF_DMA_READ_ABORT_HIGH_REG_RegisterSize 32

/* End of Register Definition for DMA_READ_ABORT_IMWR_HIGH_OFF */

/* Register DMA_READ_CH01_IMWR_DATA_OFF */
/* DMA Read Channel 1 and 0 IMWr Data Register. This register is implemented in RAM whose contents are uninitialized after power-on. Therefore, you must always initialize this register value because the default is undefined. All fields marked "Reserved" MUST be programmed to 1'b0. This register is not affected by any of the reset signals. */
#define DMA_READ_CH01_IMWR_DATA_OFF (PF0_PORT_LOGIC_BaseAddress + 0x34c)
#define DMA_READ_CH01_IMWR_DATA_OFF_RegisterSize 32
#define DMA_READ_CH01_IMWR_DATA_OFF_RegisterResetValue 0x0
#define DMA_READ_CH01_IMWR_DATA_OFF_RegisterResetMask 0x0

/* Register Field information for DMA_READ_CH01_IMWR_DATA_OFF */

/* Register DMA_READ_CH01_IMWR_DATA_OFF field RD_CHANNEL_0_DATA */
/* The DMA uses this field to generate the data field for the Done or Abort IMWr TLPs it generates for read channel 0. */
#define DMA_READ_CH01_IMWR_DATA_OFF_RD_CHANNEL_0_DATA_BitAddressOffset 0
#define DMA_READ_CH01_IMWR_DATA_OFF_RD_CHANNEL_0_DATA_RegisterSize 16

/* Register DMA_READ_CH01_IMWR_DATA_OFF field RD_CHANNEL_1_DATA */
/* The DMA uses this field to generate the data field for the Done or Abort IMWr TLPs it generates for read channel 1. */
#define DMA_READ_CH01_IMWR_DATA_OFF_RD_CHANNEL_1_DATA_BitAddressOffset 16
#define DMA_READ_CH01_IMWR_DATA_OFF_RD_CHANNEL_1_DATA_RegisterSize 16

/* End of Register Definition for DMA_READ_CH01_IMWR_DATA_OFF */

/* Register DMA_READ_CH23_IMWR_DATA_OFF */
/* DMA Read Channel 3 and 2 IMWr Data Register. This register is implemented in RAM whose contents are uninitialized after power-on. Therefore, you must always initialize this register value because the default is undefined. All fields marked "Reserved" MUST be programmed to 1'b0. This register is not affected by any of the reset signals. */
#define DMA_READ_CH23_IMWR_DATA_OFF (PF0_PORT_LOGIC_BaseAddress + 0x350)
#define DMA_READ_CH23_IMWR_DATA_OFF_RegisterSize 32
#define DMA_READ_CH23_IMWR_DATA_OFF_RegisterResetValue 0x0
#define DMA_READ_CH23_IMWR_DATA_OFF_RegisterResetMask 0x0

/* Register Field information for DMA_READ_CH23_IMWR_DATA_OFF */

/* Register DMA_READ_CH23_IMWR_DATA_OFF field RD_CHANNEL_2_DATA */
/* The DMA uses this field to generate the data field for the Done or Abort IMWr TLPs it generates for read channel 2. */
#define DMA_READ_CH23_IMWR_DATA_OFF_RD_CHANNEL_2_DATA_BitAddressOffset 0
#define DMA_READ_CH23_IMWR_DATA_OFF_RD_CHANNEL_2_DATA_RegisterSize 16

/* Register DMA_READ_CH23_IMWR_DATA_OFF field RD_CHANNEL_3_DATA */
/* The DMA uses this field to generate the data field for the Done or Abort IMWr TLPs it generates for read channel 3. */
#define DMA_READ_CH23_IMWR_DATA_OFF_RD_CHANNEL_3_DATA_BitAddressOffset 16
#define DMA_READ_CH23_IMWR_DATA_OFF_RD_CHANNEL_3_DATA_RegisterSize 16

/* End of Register Definition for DMA_READ_CH23_IMWR_DATA_OFF */

/* Register DMA_READ_CH45_IMWR_DATA_OFF */
/* DMA Read Channel 5 and 4 IMWr Data Register. This register is implemented in RAM whose contents are uninitialized after power-on. Therefore, you must always initialize this register value because the default is undefined. All fields marked "Reserved" MUST be programmed to 1'b0. This register is not affected by any of the reset signals. */
#define DMA_READ_CH45_IMWR_DATA_OFF (PF0_PORT_LOGIC_BaseAddress + 0x354)
#define DMA_READ_CH45_IMWR_DATA_OFF_RegisterSize 32
#define DMA_READ_CH45_IMWR_DATA_OFF_RegisterResetValue 0x0
#define DMA_READ_CH45_IMWR_DATA_OFF_RegisterResetMask 0x0

/* Register Field information for DMA_READ_CH45_IMWR_DATA_OFF */

/* Register DMA_READ_CH45_IMWR_DATA_OFF field RD_CHANNEL_4_DATA */
/* The DMA uses this field to generate the data field for the Done or Abort IMWr TLPs it generates for read channel 4. */
#define DMA_READ_CH45_IMWR_DATA_OFF_RD_CHANNEL_4_DATA_BitAddressOffset 0
#define DMA_READ_CH45_IMWR_DATA_OFF_RD_CHANNEL_4_DATA_RegisterSize 16

/* Register DMA_READ_CH45_IMWR_DATA_OFF field RD_CHANNEL_5_DATA */
/* The DMA uses this field to generate the data field for the Done or Abort IMWr TLPs it generates for read channel 5. */
#define DMA_READ_CH45_IMWR_DATA_OFF_RD_CHANNEL_5_DATA_BitAddressOffset 16
#define DMA_READ_CH45_IMWR_DATA_OFF_RD_CHANNEL_5_DATA_RegisterSize 16

/* End of Register Definition for DMA_READ_CH45_IMWR_DATA_OFF */

/* Register DMA_READ_CH67_IMWR_DATA_OFF */
/* DMA Read Channel 7 and 6 IMWr Data Register. This register is implemented in RAM whose contents are uninitialized after power-on. Therefore, you must always initialize this register value because the default is undefined. All fields marked "Reserved" MUST be programmed to 1'b0. This register is not affected by any of the reset signals. */
#define DMA_READ_CH67_IMWR_DATA_OFF (PF0_PORT_LOGIC_BaseAddress + 0x358)
#define DMA_READ_CH67_IMWR_DATA_OFF_RegisterSize 32
#define DMA_READ_CH67_IMWR_DATA_OFF_RegisterResetValue 0x0
#define DMA_READ_CH67_IMWR_DATA_OFF_RegisterResetMask 0x0

/* Register Field information for DMA_READ_CH67_IMWR_DATA_OFF */

/* Register DMA_READ_CH67_IMWR_DATA_OFF field RD_CHANNEL_6_DATA */
/* The DMA uses this field to generate the data field for the Done or Abort IMWr TLPs it generates for read channel 6. */
#define DMA_READ_CH67_IMWR_DATA_OFF_RD_CHANNEL_6_DATA_BitAddressOffset 0
#define DMA_READ_CH67_IMWR_DATA_OFF_RD_CHANNEL_6_DATA_RegisterSize 16

/* Register DMA_READ_CH67_IMWR_DATA_OFF field RD_CHANNEL_7_DATA */
/* The DMA uses this field to generate the data field for the Done or Abort IMWr TLPs it generates for read channel 7. */
#define DMA_READ_CH67_IMWR_DATA_OFF_RD_CHANNEL_7_DATA_BitAddressOffset 16
#define DMA_READ_CH67_IMWR_DATA_OFF_RD_CHANNEL_7_DATA_RegisterSize 16

/* End of Register Definition for DMA_READ_CH67_IMWR_DATA_OFF */

/* Register DMA_VIEWPORT_SEL_OFF */
/* DMA Channel Context Index Register. The DMA registers are programmed through an indirect addressing scheme (using this index register) to reduce the address footprint in the PCI Express extended configuration space. The size of the required port logic space does not depend on the number of regions defined as the index register is used to select which channel is being accessed.<ct:[incorebuilder]><br><b>Viewportdepth:</b> CC_NUM_DMA_WR_CHAN or CC_NUM_DMA_RD_CHAN</ct> */
#define DMA_VIEWPORT_SEL_OFF (PF0_PORT_LOGIC_BaseAddress + 0x36c)
#define DMA_VIEWPORT_SEL_OFF_RegisterSize 32
#define DMA_VIEWPORT_SEL_OFF_RegisterResetValue 0x0
#define DMA_VIEWPORT_SEL_OFF_RegisterResetMask 0xffffffff

/* Register Field information for DMA_VIEWPORT_SEL_OFF */

/* Register DMA_VIEWPORT_SEL_OFF field CHANNEL_NUM */
/* Channel Index. Selects the channel number associated with the DMA read or write context when writing to the registers in Table 5-547. The bits are encoded as follows:
 - 000: channel #0
 - 001: channel #1
 - ........
 - 111: channel #7
Must not be set to a number greater than CC_NUM_DMA_WR_CHAN - 1 when a write channel is being accessed.
<br> Must not be set to a number greater than CC_NUM_DMA_RD_CHAN - 1 when a read channel is being accessed. */
#define DMA_VIEWPORT_SEL_OFF_CHANNEL_NUM_BitAddressOffset 0
#define DMA_VIEWPORT_SEL_OFF_CHANNEL_NUM_RegisterSize 3

/* Register DMA_VIEWPORT_SEL_OFF field RSVDP_3 */
/* Reserved for future use. */
#define DMA_VIEWPORT_SEL_OFF_RSVDP_3_BitAddressOffset 3
#define DMA_VIEWPORT_SEL_OFF_RSVDP_3_RegisterSize 28

/* Register DMA_VIEWPORT_SEL_OFF field CHANNEL_DIR */
/* Channel Direction. Selects a write channel or read channel context.
 - 0: write channel 0
 - 1: read channel 0 */
#define DMA_VIEWPORT_SEL_OFF_CHANNEL_DIR_BitAddressOffset 31
#define DMA_VIEWPORT_SEL_OFF_CHANNEL_DIR_RegisterSize 1

/* End of Register Definition for DMA_VIEWPORT_SEL_OFF */

/* Register DMA_CH_CONTROL1_OFF_RDCH_0_0 */
/* DMA Read Channel Control 1 Register. This register is implemented in RAM whose contents are uninitialized after power-on. Therefore, you must always initialize this register value because the default is undefined. All fields marked "Reserved" MUST be programmed to 1'b0. This register is not affected by any of the reset signals. */
#define DMA_CH_CONTROL1_OFF_RDCH_0_0 (PF0_PORT_LOGIC_BaseAddress + 0x370)
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_RegisterSize 32
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_RegisterResetValue 0x0
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_RegisterResetMask 0x0

/* Register Field information for DMA_CH_CONTROL1_OFF_RDCH_0_0 */

/* Register DMA_CH_CONTROL1_OFF_RDCH_0_0 field CB */
/* Cycle Bit (CB). Used in linked list mode only. It is used to synchronize the producer (software) and the consumer (DMA). For more details, see "PCS-CCS-CB-TCB Producer-Consumer Synchronization".
The DMA loads this field with the CB of the linked list element. */
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_CB_BitAddressOffset 0
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_CB_RegisterSize 1

/* Register DMA_CH_CONTROL1_OFF_RDCH_0_0 field TCB */
/* Toggle Cycle Bit (TCB). Indicates to the DMA to toggle its interpretation of the CB. Used in linked list mode only. It is used to synchronize the producer (software) and the consumer (DMA). For more details, see "PCS-CCS-CB-TCB Producer-Consumer Synchronization".
The DMA loads this field with the TCB of the linked list element.
this field is not defined in a data LL element. */
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_TCB_BitAddressOffset 1
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_TCB_RegisterSize 1

/* Register DMA_CH_CONTROL1_OFF_RDCH_0_0 field LLP */
/* Load Link Pointer (LLP). Used in linked list mode only.
Indicates that this linked list element is a link element, and its LL element pointer dwords are pointing to the next (non-contiguous) element.
The DMA loads this field with the LLP of the linked list element. */
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_LLP_BitAddressOffset 2
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_LLP_RegisterSize 1

/* Register DMA_CH_CONTROL1_OFF_RDCH_0_0 field LIE */
/* Local Interrupt Enable (LIE). You must set this bit to enable the generation of the Done or Abort Local interrupts. For more details, see "Interrupts and Error Handling".
In LL mode, the DMA overwrites this with the LIE of the LL element. The LIE bit in a LL element only enables the Done interrupt. In non-LL mode, the LIE bit enables the Done and Abort interrupts.
<br>This field is not defined in a <i>link</i> LL element. */
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_LIE_BitAddressOffset 3
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_LIE_RegisterSize 1

/* Register DMA_CH_CONTROL1_OFF_RDCH_0_0 field RIE */
/* Remote Interrupt Enable (RIE). You must set this bit to enable the generation of the Done or Abort Remote interrupts. For more details, see "Interrupts and Error Handling".
In LL mode, the DMA overwrites this with the RIE of the LL element. The RIE bit in a LL element only enables the Done interrupt. In non-LL mode, the RIE bit enables the Done and Abort interrupts.
<br>This field is not defined in a <i>link</i> LL element. */
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_RIE_BitAddressOffset 4
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_RIE_RegisterSize 1

/* Register DMA_CH_CONTROL1_OFF_RDCH_0_0 field CS */
/* Channel Status (CS). The channel status bits identify the current operational state of the DMA channel. The operation state encoding for each DMA channel is a s follows:
 - 00: Reserved
 - 01: Running. This channel is active and transferring data.
 - 10: Halted. An error condition has been detected, and the DMA has stopped this channel.
 - 11: Stopped. The DMA has transferred all data for this channel, or you have prematurely stopped this channel by writing to the Stop field of the "DMA Read Doorbell Register" (DMA_WRITE_DOORBELL_OFF) or "DMA Read Doorbell Register" (DMA_READ_DOORBELL_OFF). */
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_CS_BitAddressOffset 5
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_CS_RegisterSize 2

/* Register DMA_CH_CONTROL1_OFF_RDCH_0_0 field DMA_RESERVED0 */
/* Reserved. */
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_DMA_RESERVED0_BitAddressOffset 7
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_DMA_RESERVED0_RegisterSize 1

/* Register DMA_CH_CONTROL1_OFF_RDCH_0_0 field CCS */
/* Consumer Cycle State (CCS). Used in linked list mode only. It is used to synchronize the producer (software) and the consumer (DMA). For more details, see "PCS-CCS-CB-TCB Producer-Consumer Synchronization".
<br> <b>You must initialize this bit. </b> The DMA updates this bit during linked list operation. */
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_CCS_BitAddressOffset 8
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_CCS_RegisterSize 1

/* Register DMA_CH_CONTROL1_OFF_RDCH_0_0 field LLE */
/* Linked List Enable (LLE).
 - 0: Disable linked list operation
 - 1: Enable linked list operation */
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_LLE_BitAddressOffset 9
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_LLE_RegisterSize 1

/* Register DMA_CH_CONTROL1_OFF_RDCH_0_0 field DMA_RESERVED1 */
/* Reserved. */
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_DMA_RESERVED1_BitAddressOffset 10
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_DMA_RESERVED1_RegisterSize 2

/* Register DMA_CH_CONTROL1_OFF_RDCH_0_0 field DMA_FUNC_NUM */
/* Function Number (FN). The core uses this field when generating the requester ID for the MRd/MWr DMA TLP. When you have enabled SR-IOV, then this field is ignored if you have set the VFE field in the "DMA Read Channel Control 2 Register" (DMA_CH_CONTROL2_OFF_RDCH_0). */
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_DMA_FUNC_NUM_BitAddressOffset 12
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_DMA_FUNC_NUM_RegisterSize 5

/* Register DMA_CH_CONTROL1_OFF_RDCH_0_0 field DMA_RESERVED2 */
/* Reserved. */
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_DMA_RESERVED2_BitAddressOffset 17
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_DMA_RESERVED2_RegisterSize 7

/* Register DMA_CH_CONTROL1_OFF_RDCH_0_0 field NS */
/* No Snoop TLP Header Bit (NS). <br> The DMA uses this TLP header field when generating MRd/MWr (not IMWr) TLPs. */
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_NS_BitAddressOffset 24
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_NS_RegisterSize 1

/* Register DMA_CH_CONTROL1_OFF_RDCH_0_0 field DMA_RO */
/* Relaxed Ordering TLP Header Bit (RO) <br> The DMA uses this TLP header field when generating MRd/MWr (not IMWr) TLPs. */
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_DMA_RO_BitAddressOffset 25
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_DMA_RO_RegisterSize 1

/* Register DMA_CH_CONTROL1_OFF_RDCH_0_0 field DMA_TD */
/* Traffic Digest TLP Header Bit (TD). The PCIe core adds the ECRC field and sets the TD bit in the TLP header. <br> The DMA uses this TLP header field when generating MRd/MWr (not IMWr) TLPs. */
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_DMA_TD_BitAddressOffset 26
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_DMA_TD_RegisterSize 1

/* Register DMA_CH_CONTROL1_OFF_RDCH_0_0 field DMA_TC */
/* Traffic Class TLP Header Bit (TC) <br> The DMA uses this TLP header field when generating MRd/MWr (not IMWr) TLPs. */
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_DMA_TC_BitAddressOffset 27
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_DMA_TC_RegisterSize 3

/* Register DMA_CH_CONTROL1_OFF_RDCH_0_0 field DMA_AT */
/* Address Translation TLP Header Bit (AT) <br> The DMA uses this TLP header field when generating MRd/MWr (not IMWr) TLPs. */
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_DMA_AT_BitAddressOffset 30
#define DMA_CH_CONTROL1_OFF_RDCH_0_0_DMA_AT_RegisterSize 2

/* End of Register Definition for DMA_CH_CONTROL1_OFF_RDCH_0_0 */

/* Register DMA_CH_CONTROL1_OFF_WRCH_0 */
/* DMA Write Channel Control 1 Register. This register is implemented in RAM whose contents are uninitialized after power-on. Therefore, you must always initialize this register value because the default is undefined. All fields marked "Reserved" MUST be programmed to 1'b0. This register is not affected by any of the reset signals. */
#define DMA_CH_CONTROL1_OFF_WRCH_0 (PF0_PORT_LOGIC_BaseAddress + 0x370)
#define DMA_CH_CONTROL1_OFF_WRCH_0_RegisterSize 32
#define DMA_CH_CONTROL1_OFF_WRCH_0_RegisterResetValue 0x0
#define DMA_CH_CONTROL1_OFF_WRCH_0_RegisterResetMask 0x0

/* Register Field information for DMA_CH_CONTROL1_OFF_WRCH_0 */

/* Register DMA_CH_CONTROL1_OFF_WRCH_0 field CB */
/* Cycle Bit (CB). Used in linked list mode only. It is used to synchronize the producer (software) and the consumer (DMA). For more details, see "PCS-CCS-CB-TCB Producer-Consumer Synchronization".
The DMA loads this field with the CB of the linked list element. */
#define DMA_CH_CONTROL1_OFF_WRCH_0_CB_BitAddressOffset 0
#define DMA_CH_CONTROL1_OFF_WRCH_0_CB_RegisterSize 1

/* Register DMA_CH_CONTROL1_OFF_WRCH_0 field TCB */
/* Toggle Cycle Bit (TCB). Indicates to the DMA to toggle its interpretation of the CB. Used in linked list mode only. It is used to synchronize the producer (software) and the consumer (DMA). For more details, see "PCS-CCS-CB-TCB Producer-Consumer Synchronization".
The DMA loads this field with the TCB of the linked list element.
this field is not defined in a data LL element. */
#define DMA_CH_CONTROL1_OFF_WRCH_0_TCB_BitAddressOffset 1
#define DMA_CH_CONTROL1_OFF_WRCH_0_TCB_RegisterSize 1

/* Register DMA_CH_CONTROL1_OFF_WRCH_0 field LLP */
/* Load Link Pointer (LLP). Used in linked list mode only.
Indicates that this linked list element is a link element, and its LL element pointer dwords are pointing to the next (non-contiguous) element.
The DMA loads this field with the LLP of the linked list element. */
#define DMA_CH_CONTROL1_OFF_WRCH_0_LLP_BitAddressOffset 2
#define DMA_CH_CONTROL1_OFF_WRCH_0_LLP_RegisterSize 1

/* Register DMA_CH_CONTROL1_OFF_WRCH_0 field LIE */
/* Local Interrupt Enable (LIE). You must set this bit to enable the generation of the Done or Abort Local interrupts. For more details, see "Interrupts and Error Handling".
In LL mode, the DMA overwrites this with the LIE of the LL element. The LIE bit in a LL element only enables the Done interrupt. In non-LL mode, the LIE bit enables the Done and Abort interrupts.
<br>This field is not defined in a <i>link</i> LL element. */
#define DMA_CH_CONTROL1_OFF_WRCH_0_LIE_BitAddressOffset 3
#define DMA_CH_CONTROL1_OFF_WRCH_0_LIE_RegisterSize 1

/* Register DMA_CH_CONTROL1_OFF_WRCH_0 field RIE */
/* Remote Interrupt Enable (RIE). You must set this bit to enable the generation of the Done or Abort Remote interrupts. For more details, see "Interrupts and Error Handling".
In LL mode, the DMA overwrites this with the RIE of the LL element. The RIE bit in a LL element only enables the Done interrupt. In non-LL mode, the RIE bit enables the Done and Abort interrupts.
<br>This field is not defined in a <i>link</i> LL element. */
#define DMA_CH_CONTROL1_OFF_WRCH_0_RIE_BitAddressOffset 4
#define DMA_CH_CONTROL1_OFF_WRCH_0_RIE_RegisterSize 1

/* Register DMA_CH_CONTROL1_OFF_WRCH_0 field CS */
/* Channel Status (CS). The channel status bits identify the current operational state of the DMA channel. The operation state encoding for each DMA channel is a s follows:
 - 00: Reserved
 - 01: Running. This channel is active and transferring data.
 - 10: Halted. An error condition has been detected, and the DMA has stopped this channel.
 - 11: Stopped. The DMA has transferred all data for this channel, or you have prematurely stopped this channel by writing to the Stop field of the "DMA Write Doorbell Register" (DMA_WRITE_DOORBELL_OFF) or "DMA Read Doorbell Register" (DMA_READ_DOORBELL_OFF). */
#define DMA_CH_CONTROL1_OFF_WRCH_0_CS_BitAddressOffset 5
#define DMA_CH_CONTROL1_OFF_WRCH_0_CS_RegisterSize 2

/* Register DMA_CH_CONTROL1_OFF_WRCH_0 field DMA_RESERVED0 */
/* Reserved. */
#define DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED0_BitAddressOffset 7
#define DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED0_RegisterSize 1

/* Register DMA_CH_CONTROL1_OFF_WRCH_0 field CCS */
/* Consumer Cycle State (CCS). Used in linked list mode only. It is used to synchronize the producer (software) and the consumer (DMA). For more details, see "PCS-CCS-CB-TCB Producer-Consumer Synchronization".
<br> <b>You must initialize this bit. </b> The DMA updates this bit during linked list operation. */
#define DMA_CH_CONTROL1_OFF_WRCH_0_CCS_BitAddressOffset 8
#define DMA_CH_CONTROL1_OFF_WRCH_0_CCS_RegisterSize 1

/* Register DMA_CH_CONTROL1_OFF_WRCH_0 field LLE */
/* Linked List Enable (LLE).
 - 0: Disable linked list operation
 - 1: Enable linked list operation */
#define DMA_CH_CONTROL1_OFF_WRCH_0_LLE_BitAddressOffset 9
#define DMA_CH_CONTROL1_OFF_WRCH_0_LLE_RegisterSize 1

/* Register DMA_CH_CONTROL1_OFF_WRCH_0 field DMA_RESERVED1 */
/* Reserved. */
#define DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED1_BitAddressOffset 10
#define DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED1_RegisterSize 2

/* Register DMA_CH_CONTROL1_OFF_WRCH_0 field DMA_FUNC_NUM */
/* Function Number (FN). The core uses this field when generating the requester ID for the MRd/MWr DMA TLP. When you have enabled SR-IOV, then this field is ignored if you have set the VFE field in the "DMA Write Channel Control 2 Register" (DMA_CH_CONTROL2_OFF_WRCH_0). */
#define DMA_CH_CONTROL1_OFF_WRCH_0_DMA_FUNC_NUM_BitAddressOffset 12
#define DMA_CH_CONTROL1_OFF_WRCH_0_DMA_FUNC_NUM_RegisterSize 5

/* Register DMA_CH_CONTROL1_OFF_WRCH_0 field DMA_RESERVED2 */
/* Reserved. */
#define DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED2_BitAddressOffset 17
#define DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED2_RegisterSize 7

/* Register DMA_CH_CONTROL1_OFF_WRCH_0 field NS */
/* No Snoop TLP Header Bit (NS). <br> The DMA uses this TLP header field when generating MRd/MWr (not IMWr) TLPs. */
#define DMA_CH_CONTROL1_OFF_WRCH_0_NS_BitAddressOffset 24
#define DMA_CH_CONTROL1_OFF_WRCH_0_NS_RegisterSize 1

/* Register DMA_CH_CONTROL1_OFF_WRCH_0 field DMA_RO */
/* Relaxed Ordering TLP Header Bit (RO) <br> The DMA uses this TLP header field when generating MRd/MWr (not IMWr) TLPs. */
#define DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RO_BitAddressOffset 25
#define DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RO_RegisterSize 1

/* Register DMA_CH_CONTROL1_OFF_WRCH_0 field DMA_TD */
/* Traffic Digest TLP Header Bit (TD). The PCIe core adds the ECRC field and sets the TD bit in the TLP header. <br> The DMA uses this TLP header field when generating MRd/MWr (not IMWr) TLPs. */
#define DMA_CH_CONTROL1_OFF_WRCH_0_DMA_TD_BitAddressOffset 26
#define DMA_CH_CONTROL1_OFF_WRCH_0_DMA_TD_RegisterSize 1

/* Register DMA_CH_CONTROL1_OFF_WRCH_0 field DMA_TC */
/* Traffic Class TLP Header Bit (TC) <br> The DMA uses this TLP header field when generating MRd/MWr (not IMWr) TLPs. */
#define DMA_CH_CONTROL1_OFF_WRCH_0_DMA_TC_BitAddressOffset 27
#define DMA_CH_CONTROL1_OFF_WRCH_0_DMA_TC_RegisterSize 3

/* Register DMA_CH_CONTROL1_OFF_WRCH_0 field DMA_AT */
/* Address Translation TLP Header Bit (AT) <br> The DMA uses this TLP header field when generating MRd/MWr (not IMWr) TLPs. */
#define DMA_CH_CONTROL1_OFF_WRCH_0_DMA_AT_BitAddressOffset 30
#define DMA_CH_CONTROL1_OFF_WRCH_0_DMA_AT_RegisterSize 2

/* End of Register Definition for DMA_CH_CONTROL1_OFF_WRCH_0 */

/* Register DMA_TRANSFER_SIZE_OFF_RDCH_0_0 */
/* DMA Read Transfer Size Register. This register is implemented in RAM whose contents are uninitialized after power-on. Therefore, you must always initialize this register value because the default is undefined. All fields marked "Reserved" MUST be programmed to 1'b0. This register is not affected by any of the reset signals. */
#define DMA_TRANSFER_SIZE_OFF_RDCH_0_0 (PF0_PORT_LOGIC_BaseAddress + 0x378)
#define DMA_TRANSFER_SIZE_OFF_RDCH_0_0_RegisterSize 32
#define DMA_TRANSFER_SIZE_OFF_RDCH_0_0_RegisterResetValue 0x0
#define DMA_TRANSFER_SIZE_OFF_RDCH_0_0_RegisterResetMask 0xffffffff

/* Register Field information for DMA_TRANSFER_SIZE_OFF_RDCH_0_0 */

/* Register DMA_TRANSFER_SIZE_OFF_RDCH_0_0 field DMA_TRANSFER_SIZE */
/* DMA Transfer Size. You program this register with the size of the DMA transfer. The maximum DMA transfer size is 4Gbytes. The minimum transfer size is one byte (0x1).
This field is automatically decremented by the DMA as the DMA write and read channel transfer progresses.
This field indicates the number bytes remaining to be transferred. When all bytes are successfully transferred the current transfer size is zero.
In LL mode, the DMA overwrites this with the corresponding dword of the LL element. */
#define DMA_TRANSFER_SIZE_OFF_RDCH_0_0_DMA_TRANSFER_SIZE_BitAddressOffset 0
#define DMA_TRANSFER_SIZE_OFF_RDCH_0_0_DMA_TRANSFER_SIZE_RegisterSize 32

/* End of Register Definition for DMA_TRANSFER_SIZE_OFF_RDCH_0_0 */

/* Register DMA_TRANSFER_SIZE_OFF_WRCH_0 */
/* DMA Write Transfer Size Register. This register is implemented in RAM whose contents are uninitialized after power-on. Therefore, you must always initialize this register value because the default is undefined. All fields marked "Reserved" MUST be programmed to 1'b0. This register is not affected by any of the reset signals. */
#define DMA_TRANSFER_SIZE_OFF_WRCH_0 (PF0_PORT_LOGIC_BaseAddress + 0x378)
#define DMA_TRANSFER_SIZE_OFF_WRCH_0_RegisterSize 32
#define DMA_TRANSFER_SIZE_OFF_WRCH_0_RegisterResetValue 0x0
#define DMA_TRANSFER_SIZE_OFF_WRCH_0_RegisterResetMask 0xffffffff

/* Register Field information for DMA_TRANSFER_SIZE_OFF_WRCH_0 */

/* Register DMA_TRANSFER_SIZE_OFF_WRCH_0 field DMA_TRANSFER_SIZE */
/* DMA Transfer Size. You program this register with the size of the DMA transfer. The maximum DMA transfer size is 4Gbytes. The minimum transfer size is one byte (0x1).
This field is automatically decremented by the DMA as the DMA write and read channel transfer progresses.
This field indicates the number bytes remaining to be transferred. When all bytes are successfully transferred the current transfer size is zero.
In LL mode, the DMA overwrites this with the corresponding dword of the LL element. */
#define DMA_TRANSFER_SIZE_OFF_WRCH_0_DMA_TRANSFER_SIZE_BitAddressOffset 0
#define DMA_TRANSFER_SIZE_OFF_WRCH_0_DMA_TRANSFER_SIZE_RegisterSize 32

/* End of Register Definition for DMA_TRANSFER_SIZE_OFF_WRCH_0 */

/* Register DMA_SAR_LOW_OFF_RDCH_0_0 */
/* DMA Read SAR Low Register. This register is implemented in RAM whose contents are uninitialized after power-on. Therefore, you must always initialize this register value because the default is undefined. All fields marked "Reserved" MUST be programmed to 1'b0. This register is not affected by any of the reset signals. */
#define DMA_SAR_LOW_OFF_RDCH_0_0 (PF0_PORT_LOGIC_BaseAddress + 0x37c)
#define DMA_SAR_LOW_OFF_RDCH_0_0_RegisterSize 32
#define DMA_SAR_LOW_OFF_RDCH_0_0_RegisterResetValue 0x0
#define DMA_SAR_LOW_OFF_RDCH_0_0_RegisterResetMask 0xffffffff

/* Register Field information for DMA_SAR_LOW_OFF_RDCH_0_0 */

/* Register DMA_SAR_LOW_OFF_RDCH_0_0 field SRC_ADDR_REG_LOW */
/* Source Address Register (Lower 32 bits). Indicates the next address to be read from. The DMA increments the SAR as the DMA transfer progresses. In LL mode, the DMA overwrites this with the corresponding dword of the LL element.
 - DMA Read: The SAR is the address of the remote memory.
 - DMA Read: The SAR is the address of the local memory. */
#define DMA_SAR_LOW_OFF_RDCH_0_0_SRC_ADDR_REG_LOW_BitAddressOffset 0
#define DMA_SAR_LOW_OFF_RDCH_0_0_SRC_ADDR_REG_LOW_RegisterSize 32

/* End of Register Definition for DMA_SAR_LOW_OFF_RDCH_0_0 */

/* Register DMA_SAR_LOW_OFF_WRCH_0 */
/* DMA Write SAR Low Register. This register is implemented in RAM whose contents are uninitialized after power-on. Therefore, you must always initialize this register value because the default is undefined. All fields marked "Reserved" MUST be programmed to 1'b0. This register is not affected by any of the reset signals. */
#define DMA_SAR_LOW_OFF_WRCH_0 (PF0_PORT_LOGIC_BaseAddress + 0x37c)
#define DMA_SAR_LOW_OFF_WRCH_0_RegisterSize 32
#define DMA_SAR_LOW_OFF_WRCH_0_RegisterResetValue 0x0
#define DMA_SAR_LOW_OFF_WRCH_0_RegisterResetMask 0xffffffff

/* Register Field information for DMA_SAR_LOW_OFF_WRCH_0 */

/* Register DMA_SAR_LOW_OFF_WRCH_0 field SRC_ADDR_REG_LOW */
/* Source Address Register (Lower 32 bits). Indicates the next address to be read from. The DMA increments the SAR as the DMA transfer progresses. In LL mode, the DMA overwrites this with the corresponding dword of the LL element.
 - DMA Read: The SAR is the address of the remote memory.
 - DMA Write: The SAR is the address of the local memory. */
#define DMA_SAR_LOW_OFF_WRCH_0_SRC_ADDR_REG_LOW_BitAddressOffset 0
#define DMA_SAR_LOW_OFF_WRCH_0_SRC_ADDR_REG_LOW_RegisterSize 32

/* End of Register Definition for DMA_SAR_LOW_OFF_WRCH_0 */

/* Register DMA_SAR_HIGH_OFF_RDCH_0_0 */
/* DMA Read SAR High Register. This register is implemented in RAM whose contents are uninitialized after power-on. Therefore, you must always initialize this register value because the default is undefined. All fields marked "Reserved" MUST be programmed to 1'b0. This register is not affected by any of the reset signals. */
#define DMA_SAR_HIGH_OFF_RDCH_0_0 (PF0_PORT_LOGIC_BaseAddress + 0x380)
#define DMA_SAR_HIGH_OFF_RDCH_0_0_RegisterSize 32
#define DMA_SAR_HIGH_OFF_RDCH_0_0_RegisterResetValue 0x0
#define DMA_SAR_HIGH_OFF_RDCH_0_0_RegisterResetMask 0xffffffff

/* Register Field information for DMA_SAR_HIGH_OFF_RDCH_0_0 */

/* Register DMA_SAR_HIGH_OFF_RDCH_0_0 field SRC_ADDR_REG_HIGH */
/* Source Address Register (Higher 32 bits). In LL mode, the DMA overwrites this with the corresponding dword of the LL element. */
#define DMA_SAR_HIGH_OFF_RDCH_0_0_SRC_ADDR_REG_HIGH_BitAddressOffset 0
#define DMA_SAR_HIGH_OFF_RDCH_0_0_SRC_ADDR_REG_HIGH_RegisterSize 32

/* End of Register Definition for DMA_SAR_HIGH_OFF_RDCH_0_0 */

/* Register DMA_SAR_HIGH_OFF_WRCH_0 */
/* DMA Write SAR High Register. This register is implemented in RAM whose contents are uninitialized after power-on. Therefore, you must always initialize this register value because the default is undefined. All fields marked "Reserved" MUST be programmed to 1'b0. This register is not affected by any of the reset signals. */
#define DMA_SAR_HIGH_OFF_WRCH_0 (PF0_PORT_LOGIC_BaseAddress + 0x380)
#define DMA_SAR_HIGH_OFF_WRCH_0_RegisterSize 32
#define DMA_SAR_HIGH_OFF_WRCH_0_RegisterResetValue 0x0
#define DMA_SAR_HIGH_OFF_WRCH_0_RegisterResetMask 0xffffffff

/* Register Field information for DMA_SAR_HIGH_OFF_WRCH_0 */

/* Register DMA_SAR_HIGH_OFF_WRCH_0 field SRC_ADDR_REG_HIGH */
/* Source Address Register (Higher 32 bits). In LL mode, the DMA overwrites this with the corresponding dword of the LL element. */
#define DMA_SAR_HIGH_OFF_WRCH_0_SRC_ADDR_REG_HIGH_BitAddressOffset 0
#define DMA_SAR_HIGH_OFF_WRCH_0_SRC_ADDR_REG_HIGH_RegisterSize 32

/* End of Register Definition for DMA_SAR_HIGH_OFF_WRCH_0 */

/* Register DMA_DAR_LOW_OFF_RDCH_0_0 */
/* DMA Read DAR Low Register. This register is implemented in RAM whose contents are uninitialized after power-on. Therefore, you must always initialize this register value because the default is undefined. All fields marked "Reserved" MUST be programmed to 1'b0. This register is not affected by any of the reset signals. */
#define DMA_DAR_LOW_OFF_RDCH_0_0 (PF0_PORT_LOGIC_BaseAddress + 0x384)
#define DMA_DAR_LOW_OFF_RDCH_0_0_RegisterSize 32
#define DMA_DAR_LOW_OFF_RDCH_0_0_RegisterResetValue 0x0
#define DMA_DAR_LOW_OFF_RDCH_0_0_RegisterResetMask 0xffffffff

/* Register Field information for DMA_DAR_LOW_OFF_RDCH_0_0 */

/* Register DMA_DAR_LOW_OFF_RDCH_0_0 field SRC_ADDR_REG_LOW */
/* Destination Address Register (Lower 32 bits). Indicates the next address to be written to. The DMA increments the DAR as the DMA transfer progresses. The DAR is always dword aligned even if the transfer size is byte aligned. In LL mode, the DMA overwrites this with the corresponding dword of the LL element.
 - DMA Read: The DAR is the address of the local memory.
 - DMA Read: The DAR is the address of the remote memory. */
#define DMA_DAR_LOW_OFF_RDCH_0_0_SRC_ADDR_REG_LOW_BitAddressOffset 0
#define DMA_DAR_LOW_OFF_RDCH_0_0_SRC_ADDR_REG_LOW_RegisterSize 32

/* End of Register Definition for DMA_DAR_LOW_OFF_RDCH_0_0 */

/* Register DMA_DAR_LOW_OFF_WRCH_0 */
/* DMA Write DAR Low Register. This register is implemented in RAM whose contents are uninitialized after power-on. Therefore, you must always initialize this register value because the default is undefined. All fields marked "Reserved" MUST be programmed to 1'b0. This register is not affected by any of the reset signals. */
#define DMA_DAR_LOW_OFF_WRCH_0 (PF0_PORT_LOGIC_BaseAddress + 0x384)
#define DMA_DAR_LOW_OFF_WRCH_0_RegisterSize 32
#define DMA_DAR_LOW_OFF_WRCH_0_RegisterResetValue 0x0
#define DMA_DAR_LOW_OFF_WRCH_0_RegisterResetMask 0xffffffff

/* Register Field information for DMA_DAR_LOW_OFF_WRCH_0 */

/* Register DMA_DAR_LOW_OFF_WRCH_0 field SRC_ADDR_REG_LOW */
/* Destination Address Register (Lower 32 bits). Indicates the next address to be written to. The DMA increments the DAR as the DMA transfer progresses. The DAR is always dword aligned even if the transfer size is byte aligned. In LL mode, the DMA overwrites this with the corresponding dword of the LL element.
 - DMA Read: The DAR is the address of the local memory.
 - DMA Write: The DAR is the address of the remote memory. */
#define DMA_DAR_LOW_OFF_WRCH_0_SRC_ADDR_REG_LOW_BitAddressOffset 0
#define DMA_DAR_LOW_OFF_WRCH_0_SRC_ADDR_REG_LOW_RegisterSize 32

/* End of Register Definition for DMA_DAR_LOW_OFF_WRCH_0 */

/* Register DMA_DAR_HIGH_OFF_RDCH_0_0 */
/* DMA Read DAR High Register. This register is implemented in RAM whose contents are uninitialized after power-on. Therefore, you must always initialize this register value because the default is undefined. All fields marked "Reserved" MUST be programmed to 1'b0. This register is not affected by any of the reset signals. */
#define DMA_DAR_HIGH_OFF_RDCH_0_0 (PF0_PORT_LOGIC_BaseAddress + 0x388)
#define DMA_DAR_HIGH_OFF_RDCH_0_0_RegisterSize 32
#define DMA_DAR_HIGH_OFF_RDCH_0_0_RegisterResetValue 0x0
#define DMA_DAR_HIGH_OFF_RDCH_0_0_RegisterResetMask 0xffffffff

/* Register Field information for DMA_DAR_HIGH_OFF_RDCH_0_0 */

/* Register DMA_DAR_HIGH_OFF_RDCH_0_0 field SRC_ADDR_REG_HIGH */
/* Destination Address Register (Higher 32 bits). In LL mode, the DMA overwrites this with the corresponding dword of the LL element. */
#define DMA_DAR_HIGH_OFF_RDCH_0_0_SRC_ADDR_REG_HIGH_BitAddressOffset 0
#define DMA_DAR_HIGH_OFF_RDCH_0_0_SRC_ADDR_REG_HIGH_RegisterSize 32

/* End of Register Definition for DMA_DAR_HIGH_OFF_RDCH_0_0 */

/* Register DMA_DAR_HIGH_OFF_WRCH_0 */
/* DMA Write DAR High Register. This register is implemented in RAM whose contents are uninitialized after power-on. Therefore, you must always initialize this register value because the default is undefined. All fields marked "Reserved" MUST be programmed to 1'b0. This register is not affected by any of the reset signals. */
#define DMA_DAR_HIGH_OFF_WRCH_0 (PF0_PORT_LOGIC_BaseAddress + 0x388)
#define DMA_DAR_HIGH_OFF_WRCH_0_RegisterSize 32
#define DMA_DAR_HIGH_OFF_WRCH_0_RegisterResetValue 0x0
#define DMA_DAR_HIGH_OFF_WRCH_0_RegisterResetMask 0xffffffff

/* Register Field information for DMA_DAR_HIGH_OFF_WRCH_0 */

/* Register DMA_DAR_HIGH_OFF_WRCH_0 field SRC_ADDR_REG_HIGH */
/* Destination Address Register (Higher 32 bits). In LL mode, the DMA overwrites this with the corresponding dword of the LL element.
 */
#define DMA_DAR_HIGH_OFF_WRCH_0_SRC_ADDR_REG_HIGH_BitAddressOffset 0
#define DMA_DAR_HIGH_OFF_WRCH_0_SRC_ADDR_REG_HIGH_RegisterSize 32

/* End of Register Definition for DMA_DAR_HIGH_OFF_WRCH_0 */

/* Register DMA_LLP_LOW_OFF_RDCH_0_0 */
/* DMA Read Linked List Pointer Low Register. This register is implemented in RAM whose contents are uninitialized after power-on. Therefore, you must always initialize this register value because the default is undefined. All fields marked "Reserved" MUST be programmed to 1'b0. This register is not affected by any of the reset signals. */
#define DMA_LLP_LOW_OFF_RDCH_0_0 (PF0_PORT_LOGIC_BaseAddress + 0x38c)
#define DMA_LLP_LOW_OFF_RDCH_0_0_RegisterSize 32
#define DMA_LLP_LOW_OFF_RDCH_0_0_RegisterResetValue 0x0
#define DMA_LLP_LOW_OFF_RDCH_0_0_RegisterResetMask 0xffffffff

/* Register Field information for DMA_LLP_LOW_OFF_RDCH_0_0 */

/* Register DMA_LLP_LOW_OFF_RDCH_0_0 field LLP_LOW */
/* Lower bits of the address of the linked list transfer list in local memory. Used in linked list mode only.
Updated by the DMA to point to the next element in the transfer list after the previous element is consumed.
 - When the current element is a data element; this field is incremented by 6.
 - When the current element is a link element; this field is overwritten by the LL Element Pointer of the element. */
#define DMA_LLP_LOW_OFF_RDCH_0_0_LLP_LOW_BitAddressOffset 0
#define DMA_LLP_LOW_OFF_RDCH_0_0_LLP_LOW_RegisterSize 32

/* End of Register Definition for DMA_LLP_LOW_OFF_RDCH_0_0 */

/* Register DMA_LLP_LOW_OFF_WRCH_0 */
/* DMA Write Linked List Pointer Low Register. This register is implemented in RAM whose contents are uninitialized after power-on. Therefore, you must always initialize this register value because the default is undefined. All fields marked "Reserved" MUST be programmed to 1'b0. This register is not affected by any of the reset signals. */
#define DMA_LLP_LOW_OFF_WRCH_0 (PF0_PORT_LOGIC_BaseAddress + 0x38c)
#define DMA_LLP_LOW_OFF_WRCH_0_RegisterSize 32
#define DMA_LLP_LOW_OFF_WRCH_0_RegisterResetValue 0x0
#define DMA_LLP_LOW_OFF_WRCH_0_RegisterResetMask 0xffffffff

/* Register Field information for DMA_LLP_LOW_OFF_WRCH_0 */

/* Register DMA_LLP_LOW_OFF_WRCH_0 field LLP_LOW */
/* Lower bits of the address of the linked list transfer list in local memory. Used in linked list mode only.
Updated by the DMA to point to the next element in the transfer list after the previous element is consumed.
 - When the current element is a data element; this field is incremented by 6.
 - When the current element is a link element; this field is overwritten by the LL Element Pointer of the element. */
#define DMA_LLP_LOW_OFF_WRCH_0_LLP_LOW_BitAddressOffset 0
#define DMA_LLP_LOW_OFF_WRCH_0_LLP_LOW_RegisterSize 32

/* End of Register Definition for DMA_LLP_LOW_OFF_WRCH_0 */

/* Register DMA_LLP_HIGH_OFF_RDCH_0_0 */
/* DMA Read Linked List Pointer High Register. This register is implemented in RAM whose contents are uninitialized after power-on. Therefore, you must always initialize this register value because the default is undefined. All fields marked "Reserved" MUST be programmed to 1'b0. This register is not affected by any of the reset signals. */
#define DMA_LLP_HIGH_OFF_RDCH_0_0 (PF0_PORT_LOGIC_BaseAddress + 0x390)
#define DMA_LLP_HIGH_OFF_RDCH_0_0_RegisterSize 32
#define DMA_LLP_HIGH_OFF_RDCH_0_0_RegisterResetValue 0x0
#define DMA_LLP_HIGH_OFF_RDCH_0_0_RegisterResetMask 0xffffffff

/* Register Field information for DMA_LLP_HIGH_OFF_RDCH_0_0 */

/* Register DMA_LLP_HIGH_OFF_RDCH_0_0 field LLP_HIGH */
/* Upper 32 bits of the address of the linked list transfer list in local memory. Used in linked list mode only.
Updated by the DMA to point to the next element in the transfer list as elements are consumed. */
#define DMA_LLP_HIGH_OFF_RDCH_0_0_LLP_HIGH_BitAddressOffset 0
#define DMA_LLP_HIGH_OFF_RDCH_0_0_LLP_HIGH_RegisterSize 32

/* End of Register Definition for DMA_LLP_HIGH_OFF_RDCH_0_0 */

/* Register DMA_LLP_HIGH_OFF_WRCH_0 */
/* DMA Write Linked List Pointer High Register. This register is implemented in RAM whose contents are uninitialized after power-on. Therefore, you must always initialize this register value because the default is undefined. All fields marked "Reserved" MUST be programmed to 1'b0. This register is not affected by any of the reset signals. */
#define DMA_LLP_HIGH_OFF_WRCH_0 (PF0_PORT_LOGIC_BaseAddress + 0x390)
#define DMA_LLP_HIGH_OFF_WRCH_0_RegisterSize 32
#define DMA_LLP_HIGH_OFF_WRCH_0_RegisterResetValue 0x0
#define DMA_LLP_HIGH_OFF_WRCH_0_RegisterResetMask 0xffffffff

/* Register Field information for DMA_LLP_HIGH_OFF_WRCH_0 */

/* Register DMA_LLP_HIGH_OFF_WRCH_0 field LLP_HIGH */
/* Upper 32 bits of the address of the linked list transfer list in local memory. Used in linked list mode only.
Updated by the DMA to point to the next element in the transfer list as elements are consumed. */
#define DMA_LLP_HIGH_OFF_WRCH_0_LLP_HIGH_BitAddressOffset 0
#define DMA_LLP_HIGH_OFF_WRCH_0_LLP_HIGH_RegisterSize 32

/* End of Register Definition for DMA_LLP_HIGH_OFF_WRCH_0 */

/* Register AUX_CLK_FREQ_OFF */
/* Auxiliary Clock Frequency Control Register. */
#define AUX_CLK_FREQ_OFF (PF0_PORT_LOGIC_BaseAddress + 0x440)
#define AUX_CLK_FREQ_OFF_RegisterSize 32
#define AUX_CLK_FREQ_OFF_RegisterResetValue 0xa
#define AUX_CLK_FREQ_OFF_RegisterResetMask 0xffffffff

/* Register Field information for AUX_CLK_FREQ_OFF */

/* Register AUX_CLK_FREQ_OFF field AUX_CLK_FREQ */
/* The aux_clk frequency in MHz. This value is used to provide a 1 us reference for counting time during low-power states with aux_clk when the PHY has removed the pipe_clk.
Frequencies lower than 1 MHz are possible but with a loss of accuracy in the time counted.
If the actual frequency (f) of aux_clk does not exactly match the programmed frequency (f_prog), then there is an error in the time counted by the core that can be expressed in percentage as: err% = (f_prog/f-1)*100. For example if f=2.5 MHz and f_prog=3 MHz, then err% =(3/2.5-1)*100 =20%, meaning that the time counted by the core on aux_clk will be 20% greater than the time in us programmed in the corresponding time register (for example T_POWER_ON).
<br><i>Note</i>: This register field is sticky. */
#define AUX_CLK_FREQ_OFF_AUX_CLK_FREQ_BitAddressOffset 0
#define AUX_CLK_FREQ_OFF_AUX_CLK_FREQ_RegisterSize 10

/* Register AUX_CLK_FREQ_OFF field RSVDP_10 */
/* Reserved for future use. */
#define AUX_CLK_FREQ_OFF_RSVDP_10_BitAddressOffset 10
#define AUX_CLK_FREQ_OFF_RSVDP_10_RegisterSize 22

/* End of Register Definition for AUX_CLK_FREQ_OFF */


