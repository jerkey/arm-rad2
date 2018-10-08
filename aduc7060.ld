ENTRY(_reset)

SECTIONS {
	 . = 0x0;
	 .text : {
	       startup.o(.vectors)
	       *(.text)
	 }

	 .data : {
	       *(.data)
	 }

	 .bss : {
	      *(.bss COMMON)
	 }

	 . = ALIGN(8);
	 . = . + 0x100;
	 Stack_Top = .;
}
