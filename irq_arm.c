/*    Function Pointers for Interrupts  */
typedef void (* tyVctHndlr) (void);

tyVctHndlr    IRQ     = (tyVctHndlr)0x0;
tyVctHndlr    SWI     = (tyVctHndlr)0x0;
tyVctHndlr    FIQ     = (tyVctHndlr)0x0;
tyVctHndlr    UNDEF   = (tyVctHndlr)0x0;
tyVctHndlr    PABORT  = (tyVctHndlr)0x0;
tyVctHndlr    DABORT  = (tyVctHndlr)0x0;

__attribute__((interrupt("IRQ"))) void IRQ_Handler(void);
__attribute__((interrupt("SWI"))) void SWI_Handler(void);
__attribute__((interrupt("FIQ"))) void FIQ_Handler(void);
__attribute__((interrupt("UNDEF"))) void Undef_Handler(void);
__attribute__((interrupt("ABORT"))) void PAbt_Handler(void);
__attribute__((interrupt("ABORT"))) void DAbt_Handler(void);

/*__attribute__((interrupt("IRQ"))) void IRQ_Handler(void)
{
	if ( *IRQ !=0x00)
	{
		IRQ();
	}
}*/

__attribute__((interrupt("FIQ"))) void FIQ_Handler(void)
{
	if ( *FIQ !=0x00)
	{
		FIQ();
	}
}

__attribute__((interrupt("SWI"))) void SWI_Handler(void)
{
	if ( *SWI !=0x00)
	{
		SWI();
	}
}

__attribute__((interrupt("UNDEF"))) void Undef_Handler(void) 
{
	if ( *UNDEF !=0x00)
	{
		UNDEF();
	}
}

__attribute__((interrupt("ABORT"))) void PAbt_Handler(void)
{
	if ( *PABORT !=0x00)
	{
		PABORT();
	}
}

__attribute__((interrupt("ABORT"))) void DAbt_Handler(void)
{
	if ( *DABORT !=0x00)
	{
		DABORT();
	}
}

