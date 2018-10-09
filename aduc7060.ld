ENTRY(_reset)

MEMORY
{
       rem		: ORIGIN = 0x0, LENGTH = 32K
       ram (wx)	  	: ORIGIN = 0x40000, LENGTH = 4K
       rom (rx)  	: ORIGIN = 0x80000, LENGTH = 32K
       mmr (w)		: ORIGIN = 0xffff0000, LENGTH = 1M
}

SECTIONS
{
	 . = 0x0;
	 .text : {
	       startup.o(.vectors)
	       *(.text)
	 } >rom

	 .data : {
	       *(.data)
	 } >ram

	 .bss : {
	      *(.bss COMMON)
	 } >ram

	 . = ALIGN(8);
	 . = . + 0x100;
	 Stack_Top = .;
}
