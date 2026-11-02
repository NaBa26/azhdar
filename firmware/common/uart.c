#include <stdint.h>
#include "uart.h"

#define UART0_BASE      0x40004000UL

#define UART_DATA       (*(volatile uint32_t *)(UART0_BASE + 0x00))
#define UART_STATE      (*(volatile uint32_t *)(UART0_BASE + 0x04))
#define UART_CTRL       (*(volatile uint32_t *)(UART0_BASE + 0x08))
#define UART_BAUDDIV    (*(volatile uint32_t *)(UART0_BASE + 0x10))

#define UART_STATE_TXFULL   (1UL << 0)

#define UART_CTRL_TX_EN     (1UL << 0)
#define UART_CTRL_RX_EN     (1UL << 1)

void uart_init(void)
{
    /*
     * QEMU's AN386 system clock is 25 MHz.
     * 25,000,000 / 217 ≈ 115200 baud.
     */
    UART_BAUDDIV = 217;

    UART_CTRL = UART_CTRL_TX_EN | UART_CTRL_RX_EN;
}

void uart_putc(char c)
{
    while (UART_STATE & UART_STATE_TXFULL) {
    }

    UART_DATA = (uint8_t)c;
}

void uart_puts(const char *s)
{
    while (*s != '\0') {
        uart_putc(*s++);
    }
}
