#include "bsp.h"

static uint8_t pin_mode = 0xFFU;
static uint8_t pin_num = 0xFFU;
static uint8_t pin_state = 0xFFU;

void bsp_pin_mode(uint8_t pin, uint8_t mode)
{
    pin_num = pin;
    pin_mode = mode;
}

int bsp_digital_read(uint8_t pin)
{
    pin_num = pin;
    return pin_state;
}

// Helper function!
uint8_t bsp_get_pin_mode(void)
{
    return pin_mode;
}
// Helper function!
uint8_t bsp_get_pin_num(void)
{
    return pin_num;
}
// Helper function!
void bsp_set_pin_state(uint8_t state)
{
    pin_state = state;
}
