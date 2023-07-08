ENTRY(_start)

__stack_size = 1K;

MEMORY {
    /*
     * Align the ROM in the ELF to suit the RPi bootloader's kernel load
     * address. ROM is where the kernel will reside. This value is for running
     * in 64-bit mode.
     */
    rom   (rx)  : ORIGIN = 0x80000, LENGTH = 4K

    ram   (rwx) : ORIGIN = ORIGIN(rom) + LENGTH(rom), LENGTH = 2K

    /* 
     * Stack grows towards lower addresses in AAPCS64. Therefore place it
     * before the ROM to avoid any clobbering.
     */
    stack (rw)  : ORIGIN = ORIGIN(rom) - __stack_size, LENGTH = __stack_size
}

SECTIONS {
    .text : {
        /* Don't discard .text.boot as it is referenced by the bootloader */
        KEEP(*(.text.boot))

        *(.text)
        *(.gnu.linkonce.t*)
    } > rom
    
    .rodata : { *(.rodata*) *(.gnu.linkonce.d*) } > rom

    .data   : { *(.data*) *(.gnu.linkonce.d*) } > ram

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
    } > ram
    /* BSS is dword aligned */
    __bss_size = (__bss_end - __bss_start) >> 3;

    __stack_base = ORIGIN(stack) + LENGTH(stack);

    /*
     * Discard unnecessary sections from the ELF.
     *
     * .comment: includes compiler metadata
     *
     */
    /DISCARD/ : { *(.comment) }
}
