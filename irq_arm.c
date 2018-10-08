/*    Function Pointers for Interrupts  */
typedef void (* tyVctHndlr) (void);

tyVctHndlr    IRQ     = (tyVctHndlr)0x0;
tyVctHndlr    SWI     = (tyVctHndlr)0x0;
tyVctHndlr    FIQ     = (tyVctHndlr)0x0;
tyVctHndlr    UNDEF   = (tyVctHndlr)0x0;
tyVctHndlr    PABORT  = (tyVctHndlr)0x0;
tyVctHndlr    DABORT  = (tyVctHndlr)0x0;

void	IRQ_Handler   (void) __attribute__((interrupt("IRQ")));
void	SWI_Handler   (void) __attribute__((interrupt("SWI")));
void	FIQ_Handler   (void) __attribute__((interrupt("FIQ")));
void	Undef_Handler (void) __attribute__((interrupt("UNDEF")));
void	PAbt_Handler  (void) __attribute__((interrupt("ABORT")));
void	DAbt_Handler  (void) __attribute__((interrupt("ABORT")));

/*void	IRQ_Handler(void) __attribute__((interrupt("IRQ")))
{
	if ( *IRQ !=0x00)
	{
		IRQ();
	}
}*/

void	FIQ_Handler(void) __attribute__((interrupt("FIQ")))
{
	if ( *FIQ !=0x00)
	{
		FIQ();
	}
}

void	SWI_Handler(void) __attribute__((interrupt("SWI")))
{
	if ( *SWI !=0x00)
	{
		SWI();
	}
}

void	Undef_Handler(void)__attribute__((interrupt("UNDEF"))) 
{
	if ( *UNDEF !=0x00)
	{
		UNDEF();
	}
}

void	PAbt_Handler(void) __attribute__((interrupt("ABORT")))
{
	if ( *PABORT !=0x00)
	{
		PABORT();
	}
}

void	DAbt_Handler(void) __attribute__((interrupt("ABORT")))
{
	if ( *DABORT !=0x00)
	{
		DABORT();
	}
}

