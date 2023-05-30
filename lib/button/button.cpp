#include "bsp.h"
#include "button.h"
#include <stdbool.h>

#define SAMPLES (5U)
static uint8_t count = 0xFF;
static uint8_t pin_num = 0xFF;
static uint8_t state = BUTTON_UNINITITIALIZED;

void edge_clear(void)
{

    if (state == BUTTON_FALLING_EDGE)
    {
        state = BUTTON_PRESSED;
    }

    else if (state == BUTTON_RISING_EDGE)
    {
        state = BUTTON_RELEASED;
    }
}

void button_init(uint8_t pin)
{
    bsp_pin_mode(pin, BSP_INPUT_PULLUP);
    state = BUTTON_RELEASED;
    pin_num = pin;
}

void button_update_state(void)
{
    if (state != BUTTON_UNINITITIALIZED)
    {
        edge_clear();
        uint8_t current_state = (BSP_HIGH == (bsp_digital_read(pin_num)) ? BUTTON_RELEASED : BUTTON_PRESSED);
        if (state == current_state)
        {
            count = 0;
        }
        else
        {
            count++;
            if (count == SAMPLES)
            {
                state = (state == BUTTON_RELEASED ? BUTTON_FALLING_EDGE : BUTTON_RISING_EDGE);
            }
        }
    }
}

uint8_t button_get_state(void)
{
    uint8_t temp = state;
    edge_clear();
    return temp;
}
