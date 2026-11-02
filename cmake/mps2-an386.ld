ENTRY(Reset_Handler)

MEMORY
{
    RAM (rwx) : ORIGIN = 0x00000000, LENGTH = 4M
}

SECTIONS
{
    .isr_vector :
    {
        . = ALIGN(256);
        KEEP(*(.isr_vector))
    } > RAM

    .text :
    {
        . = ALIGN(4);
        *(.text*)
        *(.rodata*)
        . = ALIGN(4);
    } > RAM

    .data :
    {
        . = ALIGN(4);
        *(.data*)
        . = ALIGN(4);
    } > RAM

    .bss :
    {
        . = ALIGN(4);
        __bss_start__ = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        __bss_end__ = .;
    } > RAM

    . = ALIGN(8);

    __StackTop = ORIGIN(RAM) + LENGTH(RAM);

    /DISCARD/ :
    {
        *(.comment)
        *(.note*)
    }
}
