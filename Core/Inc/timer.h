/*
 * timer.h
 *
 *  Created on: Oct 12, 2024
 *      Author: mary_uri
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

#define RED_TIME 500
#define YELLOW_TIME 200
#define GREEN_TIME 300
#define RED 1
#define GREEN 2

extern int led_mode;
extern int led_status;
extern int counter;
extern int counter_blynk;
extern int state_red_button[2];
extern int state_green_button[2];
extern int state_yellow_button[2];
extern int state_reset_button[2];

void auto_light();
void turn_off_light();
void runLight();
void reset_light();
void blynk_yellow_led();
void manual_light(int status);

#endif /* INC_TIMER_H_ */
