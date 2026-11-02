#include "uart.h"

int main(void)
{
    uart_init();

    uart_puts("\r\n");
    uart_puts("1553 SECURITY LAB\r\n");
    uart_puts("BC NODE STARTED\r\n");

    while (1) {
        __asm volatile ("nop");
    }
}
