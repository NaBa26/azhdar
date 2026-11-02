#include <stdint.h>

extern unsigned long __StackTop;

void Reset_Handler(void);
void Default_Handler(void);

__attribute__((weak, alias("Default_Handler")))
void NMI_Handler(void);

__attribute__((weak, alias("Default_Handler")))
void HardFault_Handler(void);

__attribute__((weak, alias("Default_Handler")))
void MemManage_Handler(void);

__attribute__((weak, alias("Default_Handler")))
void BusFault_Handler(void);

__attribute__((weak, alias("Default_Handler")))
void UsageFault_Handler(void);

__attribute__((weak, alias("Default_Handler")))
void SVC_Handler(void);

__attribute__((weak, alias("Default_Handler")))
void DebugMon_Handler(void);

__attribute__((weak, alias("Default_Handler")))
void PendSV_Handler(void);

__attribute__((weak, alias("Default_Handler")))
void SysTick_Handler(void);

__attribute__((used, section(".isr_vector")))
const uintptr_t vector_table[] = {
    (uintptr_t)&__StackTop,
    (uintptr_t)Reset_Handler,
    (uintptr_t)NMI_Handler,
    (uintptr_t)HardFault_Handler,
    (uintptr_t)MemManage_Handler,
    (uintptr_t)BusFault_Handler,
    (uintptr_t)UsageFault_Handler,
    0,
    0,
    0,
    0,
    (uintptr_t)SVC_Handler,
    (uintptr_t)DebugMon_Handler,
    0,
    (uintptr_t)PendSV_Handler,
    (uintptr_t)SysTick_Handler
};

void Reset_Handler(void)
{
    extern int main(void);

    (void)main();

    while (1) {
        __asm volatile ("nop");
    }
}

void Default_Handler(void)
{
    while (1) {
        __asm volatile ("nop");
    }
}
