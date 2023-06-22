.section ".text.boot"           // Tell linker to put this at the start of the kernel
.global _start                  // Make the _start label accessible outside this file

_start:
    mrs     x1, MPIDR_EL1
    and     x1, x1, 0b11        // Get the CPU ID (bits [1:0]) indicating the core number

    // RPi 4B has four cores and writing multi-core OS is hard. So, to simplify, we'll only use
    // core 0 and halt the others.
    cbz     x1, init            // Initialize if control is on core 0
    b       halt                // Halt if on other cores

init:
    adr     x1, __stack_base    // Defined in the linker script
    mov     sp, x1

    // BSS will contain uninitialized global variables. C runtime expects them to be
    // initialized to zero so we fill the entire region with zeroes.
    adr     x1, __bss_start     // Defined in the linker script
    adr     x2, __bss_size      // Defined in the linker script
    cbz     x2, exec_kernel     // Don't clear BSS if it is empty

clear_bss:
    str     xzr, [x1], 8        // Zero out [x1] and increment x1 by 8 bytes
    sub     x2, x2, 1           // Decrement counter
    cbnz    w2, clear_bss       // Loop until counter is zero

exec_kernel:
    // Call kernel's main function. If it returns, then halt the main core too.
    bl      main

halt:
    wfe                         // Enter low power standby mode until events occurs
    b       halt
