ENTRY(_start)
OUTPUT_FORMAT("elf64-littleaarch64")

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
    . = __kernel_load_address;
    
    /* .startup contains the bootstrapping routine for our C code. */
    .init : { *(.init*) }

    /* .text contains the compiled C code. */
    .text : { *(.text*) }

    /*
     * Put padding between data and text sections to ensure data is not marked
     * as executable.
     */
    . = ALIGN(CONSTANT(MAXPAGESIZE));

    /*
     * BSS contains uninitialized variables which default to zero. Instead of
     * copying the entire BSS section to memory, it is faster to have the
     * linker compute the offset and length of the BSS section and tell the
     * loader to fill that region with zeroes on startup.
     * NOLOAD is used to indicate that this section should not be loaded into
     * memory.
     */
    __bss_start = .;
    .bss (NOLOAD) : { *(.bss*) }
    /* BSS is DWORD aligned */
    __bss_end = .;
    __bss_size = (__bss_end - __bss_start) / 8;

    /* FIXME: This has something to do with freezes */
    /* . = ALIGN(CONSTANT(COMMONPAGESIZE)); */

    /* .rodata contains readonly data. */
    .rodata : { *(.rodata*) }

    . = ALIGN(CONSTANT(COMMONPAGESIZE));

    /* .data contains mutable variables */
    .data : { *(.data*) }

    /*
     * Discard unnecessary sections from the ELF.
     *     .comment: includes compiler metadata
     */
    /DISCARD/ : { *(.comment) }
}
