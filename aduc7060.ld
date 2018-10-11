ENTRY(_reset)

STACK_SIZE = 0x400;

MEMORY
{
       rem		: ORIGIN = 0x0, LENGTH = 32K
       ram (wx)	  	: ORIGIN = 0x40000, LENGTH = 4K
       flash (rx)  	: ORIGIN = 0x80000, LENGTH = 32K
       mmr (w)		: ORIGIN = 0xffff0000, LENGTH = 1M
}

SECTIONS
{
	 . = 0x0;
	 .text : {
	       startup.o(.vectors)
	       *(.text)
	       	 . = ALIGN(4);
	       	 _text_end = .;
	 } >flash

	 .rodata : {
	       *(.rodata)
	       . = ALIGN(4);
	       _rodata_end = .;
	 } > flash

	 .mdata : AT( ADDR(.rodata) + SIZEOF(.rodata) ) {
	       _data_start = .;
	       *(.data)
	       _data_end = .;
	       . = ALIGN(4);
	       _mdata_end = .;
	 } >ram

	 _data_size = _mdata_end - _data_start;

	 _bss_begin = .;
	 .bss : {
	      *(.bss COMMON)
	 } >ram

	 . = ALIGN(8);
	 _bss_end = .;


	 .noinit (NOLOAD):
	 {
		PROVIDE(__noinit_start = .);
		*(.noinit*)
		PROVIDE(__noinit_end = .);
	 } >ram

	 stack ALIGN(256) :
	 {
		. += STACK_SIZE;
		PROVIDE(__stack_top = .);
	 } >ram

	 . = . + 0x100;
	 Stack_Top = .;
}
