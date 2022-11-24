/*
 * WS2812B.c
 *
 * Created: 03.05.2018 20:28:37
 *  Author: Quenon
 */
#include "WS2812B.h"
#include <string.h>
uint8_t WS2812B_ledbuffer[WS2812B_LEDS][3];

static void _port_init(void) {
    //Режим работы - OpenDrain, подтяжка включается на всякий случай
    furi_hal_gpio_init(
        LED_PIN, //Порт FZ
        GpioModeOutputPushPull, //Режим работы - открытый сток
        GpioPullNo, //Принудительная подтяжка линии данных к питанию
        GpioSpeedVeryHigh); //Скорость работы - максимальная
}

uint8_t red_value = 0;
uint8_t green_value = 0;
uint8_t blue_value = 0;
uint8_t mode;
uint8_t lastmode;
void WS2812B_send() {
    _port_init();

    __disable_irq();
    /* Последовательная отправка цветов светодиодов */
    for(uint8_t lednumber = 0; lednumber < WS2812B_LEDS; lednumber++) {
        //Последовательная отправка цветов светодиода
        for(uint8_t color = 0; color < 3; color++) {
            //Последовательная отправка битов цвета
            for(uint8_t i = 7; i != 255; i--) {
                if(WS2812B_ledbuffer[lednumber][color] & (1 << i)) {
                    furi_hal_gpio_write(LED_PIN, true);
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    furi_hal_gpio_write(LED_PIN, false);
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                } else {
                    furi_hal_gpio_write(LED_PIN, true);
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    furi_hal_gpio_write(LED_PIN, false);
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                    asm("nop");
                }
            }
        }
    }
    __enable_irq();
}
void WS2812B_setcolor(uint8_t lednumber, uint8_t R, uint8_t G, uint8_t B) {
    WS2812B_ledbuffer[lednumber][0] = G;
    WS2812B_ledbuffer[lednumber][1] = R;
    WS2812B_ledbuffer[lednumber][2] = B;
}
void WS2812B_clear(void) {
    for(uint8_t lednumber = 0; lednumber < WS2812B_LEDS; lednumber++) {
        memset(WS2812B_ledbuffer[lednumber], 0, 3);
    }
}
void WS2812B_rainbow() {
    uint8_t R = 255;
    uint8_t G = 0;
    uint8_t B = 0;
    //Из красного в жёлтый
    while(G != 255) {
        for(uint8_t i = 0; i < WS2812B_LEDS; i++) {
            WS2812B_setcolor(i, R, G, B);
        }
        WS2812B_send();
        G++;
        furi_delay_ms(RAINBOW_SPEED);
    }
    //Из жёлтого в зелёный
    while(R != 0) {
        for(uint8_t i = 0; i < WS2812B_LEDS; i++) {
            WS2812B_setcolor(i, R, G, B);
        }
        WS2812B_send();
        R--;
        furi_delay_ms(RAINBOW_SPEED);
    }
    //Из зелёного в голубой
    while(B != 255) {
        for(uint8_t i = 0; i < WS2812B_LEDS; i++) {
            WS2812B_setcolor(i, R, G, B);
        }
        WS2812B_send();
        B++;
        furi_delay_ms(RAINBOW_SPEED);
    }
    //Из голубого в синий
    while(G != 0) {
        for(uint8_t i = 0; i < WS2812B_LEDS; i++) {
            WS2812B_setcolor(i, R, G, B);
        }
        WS2812B_send();
        G--;
        furi_delay_ms(RAINBOW_SPEED);
    }
    //Из синего в фиолетовый
    while(R != 255) {
        for(uint8_t i = 0; i < WS2812B_LEDS; i++) {
            WS2812B_setcolor(i, R, G, B);
        }
        WS2812B_send();
        R++;
        furi_delay_ms(RAINBOW_SPEED);
    }
    while(B != 0) {
        for(uint8_t i = 0; i < WS2812B_LEDS; i++) {
            WS2812B_setcolor(i, R, G, B);
        }
        WS2812B_send();
        B--;
        furi_delay_ms(RAINBOW_SPEED);
    }
}
void WS2812B_gradient() {
    uint8_t R = 255;
    uint8_t G = 0;
    uint8_t B = 0;

    for(uint8_t i = 0; i < WS2812B_LEDS * (1.0 / 5.0); i++) {
        WS2812B_setcolor(i, R, G, B);
        G += (255.0 / ((float)WS2812B_LEDS / 5.0));
    }
    G = 255;

    for(uint8_t i = WS2812B_LEDS * (1.0 / 5.0); i < WS2812B_LEDS * (2.0 / 5.0); i++) {
        WS2812B_setcolor(i, R, G, B);
        R -= (255.0 / ((float)WS2812B_LEDS / 5.0));
    }
    R = 0;

    for(uint8_t i = WS2812B_LEDS * (2.0 / 5.0); i < WS2812B_LEDS * (3.0 / 5.0); i++) {
        WS2812B_setcolor(i, R, G, B);
        B += (255.0 / ((float)WS2812B_LEDS / 5.0));
    }
    B = 255;

    for(uint8_t i = WS2812B_LEDS * (3.0 / 5.0); i < WS2812B_LEDS * (4.0 / 5.0); i++) {
        WS2812B_setcolor(i, R, G, B);
        G -= (255.0 / ((float)WS2812B_LEDS / 5.0));
    }
    G = 0;

    for(uint8_t i = WS2812B_LEDS * (4.0 / 5.0); i < WS2812B_LEDS; i++) {
        WS2812B_setcolor(i, R, G, B);
        R += (255.0 / ((float)WS2812B_LEDS / 5.0));
    }
    R = 255;

    WS2812B_send();
}
void WS2812B_circular_gradient() {
    uint8_t R = 255;
    uint8_t G = 0;
    uint8_t B = 0;

    for(uint8_t i = 0; i < WS2812B_LEDS * (1.0 / 6.0); i++) {
        WS2812B_setcolor(i, R, G, B);
        G += (255.0 / ((float)WS2812B_LEDS / 6.0));
    }
    G = 255;

    for(uint8_t i = WS2812B_LEDS * (1.0 / 6.0); i < WS2812B_LEDS * (2.0 / 6.0); i++) {
        WS2812B_setcolor(i, R, G, B);
        R -= (255.0 / ((float)WS2812B_LEDS / 6.0));
    }
    R = 0;

    for(uint8_t i = WS2812B_LEDS * (2.0 / 6.0); i < WS2812B_LEDS * (3.0 / 6.0); i++) {
        WS2812B_setcolor(i, R, G, B);
        B += (255.0 / ((float)WS2812B_LEDS / 6.0));
    }
    B = 255;

    for(uint8_t i = WS2812B_LEDS * (3.0 / 6.0); i < WS2812B_LEDS * (4.0 / 6.0); i++) {
        WS2812B_setcolor(i, R, G, B);
        G -= (255.0 / ((float)WS2812B_LEDS / 6.0));
    }
    G = 0;

    for(uint8_t i = WS2812B_LEDS * (4.0 / 6.0); i < WS2812B_LEDS * (5.0 / 6.0); i++) {
        WS2812B_setcolor(i, R, G, B);
        R += (255.0 / ((float)WS2812B_LEDS / 6.0));
    }
    R = 255;

    for(uint8_t i = WS2812B_LEDS * (5.0 / 6.0); i < WS2812B_LEDS; i++) {
        WS2812B_setcolor(i, R, G, B);
        B -= (255.0 / ((float)WS2812B_LEDS / 6.0));
    }
    B = 0;

    WS2812B_send();
}
void WS2812B_setstripe(uint8_t red, uint8_t green, uint8_t blue) {
    for(uint8_t i = 0; i < WS2812B_LEDS; i++) {
        WS2812B_setcolor(i, red, green, blue);
    }
    WS2812B_send();
    // WS2812B_stripecolor_save();
}
// void WS2812B_stripecolor_load() {
//     red_value = eeprom_read_byte(&red_data);
//     green_value = eeprom_read_byte(&green_data);
//     blue_value = eeprom_read_byte(&blue_data);
// }
// void WS2812B_stripecolor_save() {
//     eeprom_update_byte(&red_data, red_value);
//     eeprom_update_byte(&green_data, green_value);
//     eeprom_update_byte(&blue_data, blue_value);
// }
// void WS2812B_mode_set(uint8_t stripemode) {
//     lastmode = WS2812B_mode_get();
//     mode = stripemode;
//     eeprom_update_byte(&mode_data, mode);
//     switch(mode) {
//     case SWITCH_ON:
//         WS2812B_mode_set(lastmode);
//     case OFF_MODE:
//         WS2812B_setstripe(0, 0, 0);
//         break;
//     case COLOR_MODE:
//         WS2812B_setstripe(red_value, green_value, blue_value);
//         break;
//     case RAINBOW_MODE:
//         WS2812B_rainbow();
//         break;
//     case GRADIENT_MODE:
//         WS2812B_gradient();
//         break;
//     }
// }
// void WS2812B_mode_load(void) {
//     WS2812B_mode_set(eeprom_read_byte(&mode_data));
//     if(mode == OFF_MODE) mode = COLOR_MODE;
// }
// uint8_t WS2812B_mode_get(void) {
//     return mode;
// }