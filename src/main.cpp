#include "bsp.h"
#include "button.h"

constexpr uint16_t time_div{80};
constexpr uint32_t debounceDelay{2000};

void setup()
{
    hw_timer_t *timer{timerBegin(0, time_div, true)};
    timerAttachInterrupt(timer, &button_update_state, true);
    timerAlarmWrite(timer, debounceDelay, true);
    timerAlarmEnable(timer);
    button_init(GPIO_NUM_34);
    Serial.begin(9600);
}
void loop()
{
    if (button_get_state() == BUTTON_FALLING_EDGE)
    {
        Serial.println("Falling Edge");
    }
}
