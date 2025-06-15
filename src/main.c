#include "main.h"


void delay_ms(uint32_t ms) {
    LL_mDelay(ms);  // Uses SysTick
}

int main(void)
{
    // Configure system clock (needed for LL_mDelay)
    LL_InitTick(16000000, 1000);  // Assuming HSI @ 16 MHz
    LL_SetSystemCoreClock(16000000);  // Optional if not using CMSIS SysInit

    // Enable GPIOB clock
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);

    // Configure PB0 as output
    LL_GPIO_InitTypeDef gpio_init = {0};
    gpio_init.Pin = LL_GPIO_PIN_0;
    gpio_init.Mode = LL_GPIO_MODE_OUTPUT;
    gpio_init.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    gpio_init.Pull = LL_GPIO_PULL_NO;
    gpio_init.Speed = LL_GPIO_SPEED_FREQ_LOW;
    LL_GPIO_Init(GPIOB, &gpio_init);

    while (1)
    {
        LL_GPIO_TogglePin(GPIOB, LL_GPIO_PIN_0);
        delay_ms(500);
    }
}
