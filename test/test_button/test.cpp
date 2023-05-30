#include "unity.h"
#include "bsp.h"
#include "button.h"

#define FOUR 4

static uint8_t pin_num = 34;

#ifndef DEVENV
#include <Arduino.h>
#endif

void setUp()
{
}
void tearDown() {}

void testing_button_uninit(void)
{
    button_update_state();
    TEST_ASSERT_EQUAL_UINT8(BUTTON_UNINITITIALIZED, button_get_state());
}

void testing_button_init(void)
{
    button_init(pin_num);
    TEST_ASSERT_EQUAL_UINT8(pin_num, bsp_get_pin_num());
    TEST_ASSERT_EQUAL_UINT8(BSP_INPUT_PULLUP, bsp_get_pin_mode());
    TEST_ASSERT_EQUAL_UINT8(BUTTON_RELEASED, button_get_state());
}

void testing_debounce_state_loop(void)
{
    button_update_state();

    for (uint8_t i = 0; i < FOUR; i++)
    {
        bsp_set_pin_state(BSP_LOW);
        button_update_state();
        TEST_ASSERT_EQUAL(BUTTON_RELEASED, button_get_state());
    }
    bsp_set_pin_state(BSP_LOW);
    button_update_state();
    TEST_ASSERT_EQUAL(BUTTON_FALLING_EDGE, button_get_state());
    button_update_state();

    for (int i = 0; i < FOUR; i++)
    {
        bsp_set_pin_state(BSP_HIGH);
        button_update_state();
        TEST_ASSERT_EQUAL(BUTTON_PRESSED, button_get_state());
    }
    bsp_set_pin_state(BSP_HIGH);
    button_update_state();
    TEST_ASSERT_EQUAL(BUTTON_RISING_EDGE, button_get_state());
}

#ifdef DEVENV
int main(void)
{
#else
void loop()
{
}

void setup()
{
    delay(2000);
#endif
    UNITY_BEGIN();

    RUN_TEST(testing_button_uninit);
    RUN_TEST(testing_button_init);
    RUN_TEST(testing_debounce_state_loop);

#ifdef DEVENV
    return UNITY_END();
#else
    UNITY_END();
#endif
}