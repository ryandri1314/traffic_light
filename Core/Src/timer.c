/*
 * timer.c
 *
 *  Created on: Oct 12, 2024
 *      Author: mary_uri
 */

#include "timer.h"

int led_mode = 1;
int led_status = 0;
int counter = YELLOW_TIME;
int counter_blynk = 50;
int state_red_button[2] = {NORMAL_STATE, NORMAL_STATE};
int state_green_button[2] = {NORMAL_STATE, NORMAL_STATE};
int state_yellow_button[2] = {NORMAL_STATE, NORMAL_STATE};
int state_reset_button[2] = {NORMAL_STATE, NORMAL_STATE};

void auto_light() {
	switch (led_status) {
		case 0: {
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
			counter = YELLOW_TIME;
			break;
		}
		case 1: {
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
			counter = RED_TIME;
			break;
		}
		case 2: {
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
			counter = GREEN_TIME;
			break;
		}
		default:
			break;
	}
}

void turn_off_light() {
	switch (led_status) {
		case 0: {
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
			break;
		}
		case 1: {
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
			break;
		}
		case 2: {
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);
			break;
		}
		default:
			break;
	}
}

void manual_light(int status) {
	turn_off_light();

	led_status = status;

	switch (status) {
		case 1: {
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
			break;
		}
		case 2: {
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
			break;
		}
		default:
			break;
	}
}

void blynk_yellow_led() {
	if (counter_blynk-- > 0) {
		if (counter_blynk <= 0) {
			counter_blynk = 50;
			HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
		}
	}
}

void reset_light() {
	led_mode = 1;
	switch (led_status) {
		case 0: {
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
			counter = YELLOW_TIME;
			break;
		}
		case 1: {
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
			counter = RED_TIME;
			break;
		}
		case 2: {
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
			counter = GREEN_TIME;
			break;
		}
		default:
			break;
	}
}

void runLight() {
	if (led_mode == 2)
		blynk_yellow_led();

	if (led_mode == 1) {
		if (counter-- > 0) {
			if (counter <= 0) {
				led_status = led_status == 2 ? 0 : led_status + 1;
				auto_light();
			}
		}
	}
}
