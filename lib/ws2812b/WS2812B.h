/*
 * WS2812B.h
 *
 * Created: 03.05.2018 20:28:20
 *  Author: Quenon
 */

#ifndef WS2812B_H_
#define WS2812B_H_

#include "furi.h"
#include "input/input.h"

#define LED_PIN &gpio_ext_pa7

#define BLACK 0, 0, 0
#define WHITE 255, 255, 255
#define RED 255, 0, 0
#define ORANGE 255, 140, 0
#define YELLOW 255, 242, 0
#define GREEN 0, 255, 0
#define BLUE 0, 0, 255
#define CYAN 0, 255, 255
#define PURPLE 200, 63, 140
#define PINK 238, 96, 157

#define SWITCH_ON 0
#define OFF_MODE 1
#define COLOR_MODE 2
#define RAINBOW_MODE 3
#define GRADIENT_MODE 4

#define WS2812B_LEDS 10
#define RAINBOW_SPEED 10 //Скорость переключения одного оттенка в мс

void WS2812B_send(void);
void WS2812B_setcolor(uint8_t lednumber, uint8_t R, uint8_t G, uint8_t B);
void WS2812B_clear(void);
void WS2812B_rainbow(void);
void WS2812B_gradient(void);
void WS2812B_circular_gradient(void);
void WS2812B_setstripe(uint8_t red, uint8_t green, uint8_t blue);
void WS2812B_stripecolor_load(void);
void WS2812B_stripecolor_save(void);
void WS2812B_mode_set(uint8_t stripemode);
void WS2812B_mode_load(void);
uint8_t WS2812B_mode_get(void);

#endif /* WS2812B_H_ */