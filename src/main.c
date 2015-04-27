#include "ch.h"
#include "hal.h"

int main(void) {
	//Start System
	halInit();
	chSysInit();

	startBlinkyGreen();
	startBlinkyRed();

	while (TRUE) {
		chThdSleepMilliseconds(1000);
	}
}
