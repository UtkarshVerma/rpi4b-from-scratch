ENTRY(_start)

SECTIONS {
    /* Raspberry Pi firmware's kernel load address for 64-bit mode */
    __kernel_load_address = 0x80000;

    /*
     * Stack grows towards lower addresses in AAPCS64. Therefore place it
     * before the ROM to avoid any clobbering.
     */
    __stack_base = __kernel_load_address;

    /*
     * Align .init to suit the RPi bootloader's kernel load address. As it is
     * not referenced in the code, use KEEP to ensure it's not stripped from
     * the ELF.
     */
    .init __kernel_load_address : { *(.init) }

    /* .text contains the compiled C code. */
    .text   : { *(.text) *(.gnu.linkonce.t*) }

    /* Add padding executable .text from data sections */
    . = ALIGN(8);

    .rodata : { *(.rodata*) *(.gnu.linkonce.d*) }

    /* Add padding to separate R and RW sections */
    . = ALIGN(8);

    .data   : { *(.data*) *(.gnu.linkonce.d*) }

    /*
     * BSS contains uninitialized variables which default to zero. Instead of
     * copying the entire BSS section to memory, it is faster to have the
     * linker compute the offset and length of the BSS section and tell the
     * loader to fill that region with zeroes on startup.
     * NOLOAD is used to indicate that this section should not be loaded into
     * memory.
     */
    .bss (NOLOAD) : {
        /* Align .bss to dword as the `str` instruction fills dwords */
        . = ALIGN(8);
        __bss_start = .;

        *(.bss*)
        *(.gnu.linkonce.b*)
        *(COMMON)

        . = ALIGN(8);
        __bss_end = .;
    }
    /* BSS is dword aligned */
    __bss_size = (__bss_end - __bss_start) >> 3;


    /*
     * Discard unnecessary sections from the ELF.
     * .comment: includes compiler metadata
     */
    /DISCARD/ : { *(.comment) }
}
