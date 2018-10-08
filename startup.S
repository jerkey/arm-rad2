
	.global _reset

#define Mode_USR 0x10
#define Mode_FIQ 0x11
#define Mode_IRQ 0x12
#define Mode_SVC 0x13
#define Mode_ABT 0x17
#define Mode_UND 0x1B
#define Mode_SYS 0x1F

#define I_Bit 0x80
#define F_Bit 0x40

#define UND_Stack_Size 0x00
#define SVC_Stack_Size 0x00
#define ABT_Stack_Size 0x00
#define FIQ_Stack_Size 0x00
#define IRQ_Stack_Size 0x00
#define USR_Stack_Size 0x00

	.section ".vectors"

_reset:
	b Reset_Handler
	b Undef_Handler
	b SWI_Handler
	b PAbt_Handler
	b DAbt_Handler
	nop
	b IRQ_Handler
	b FIQ_Handler


	.section ".text"

Reset_Handler:
	/* Setup stack */
	ldr r0, =Stack_Top

	msr cpsr_c, #(Mode_UND | I_Bit | F_Bit)
	mov sp, r0
	sub r0, r0, #UND_Stack_Size

	msr cpsr_c, #(Mode_ABT | I_Bit | F_Bit)
	mov sp, r0
	sub r0, r0, #ABT_Stack_Size

	msr cpsr_c, #(Mode_FIQ | I_Bit | F_Bit)
	mov sp, r0
	sub r0, r0, #FIQ_Stack_Size

	msr cpsr_c, #(Mode_IRQ | I_Bit | F_Bit)
	mov sp, r0
	sub r0, r0, #IRQ_Stack_Size

	msr cpsr_c, #(Mode_SVC | I_Bit | F_Bit)
	mov sp, r0
	sub r0, r0, #SVC_Stack_Size

	msr cpsr_c, #Mode_USR
	mov sp, r0

	/* Set the stack limit */
	sub sl, sp, #USR_Stack_Size

	ldr r0, =main
	bx r0

