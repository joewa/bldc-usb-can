#include <stdio.h>
#include <string.h>

#include "ch.h"
#include "hal.h"

#include "blinky.h"
#include "myusb.h"
#include "obldc_can.h"

//#include "test.h"

int main(void) {
	//Start System
	/*halInit();
	chSysInit();

	startBlinkyGreen();
	startBlinkyRed();

	while (TRUE) {
		chThdSleepMilliseconds(1000);
	}*/

	/*
	 * System initializations.
	 * - HAL initialization, this also initializes the configured device drivers
	 *   and performs the board-specific initializations.
	 * - Kernel initialization, the main() function becomes a thread and the
	 *   RTOS is active.
	 */
	halInit();
	chSysInit();

	startBlinkyBlue();
	obldc_can_init(); // Start CAN bus
	startUSB(); // BLOCKING!!

	/*
	 * Normal main() thread activity.
	 */
	while (true) {
		chThdSleepMilliseconds(1000);
	}
}
