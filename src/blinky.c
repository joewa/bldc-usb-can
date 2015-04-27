/*
 * blinky.c
 *
 *  Created on: Dec 10, 2013
 *      Author: kjell
 */

#include "ch.h"
#include "hal.h"
#include "blinky.h"


static THD_WORKING_AREA(waBlinkyRed, BLINKY_STACK_SIZE);
static THD_FUNCTION(tBlinkyRed, arg) {
  (void)arg;
  chRegSetThreadName("BlinkyRed");
  while (TRUE) {
      chThdSleepMilliseconds(200);
      palTogglePad(GPIOE, GPIOE_LED10_RED);
    }
  return 0;
}

void startBlinkyRed(void) {
  chThdCreateStatic(waBlinkyRed, sizeof(waBlinkyRed),
  NORMALPRIO,
                    tBlinkyRed, NULL);
}

static THD_WORKING_AREA(waBlinkyGreen, BLINKY_STACK_SIZE);
static THD_FUNCTION(tBlinkyGreen, arg) {
  (void)arg;
  chRegSetThreadName("BlinkyGreen");
  while (TRUE) {
    chThdSleepMilliseconds(50);
    palTogglePad(GPIOE, GPIOE_LED7_GREEN);
  }
  return 0;
}

void startBlinkyGreen(void) {
  chThdCreateStatic(waBlinkyGreen, sizeof(waBlinkyGreen),
  NORMALPRIO,
                    tBlinkyGreen, NULL);
}
