/** @file PIT.c
*
* @brief We have the functions for the initialization of the PIT as interruption
* 		 and also a function for the timer set of the PIT, and at the final
* 		 the callback void of the PIT
*
* @par
* Diego Fernando Perez Gonzalez EXP. 736696
* Angel Noe Barrera Villalpando EXP. 734472
*/

/**Included files*/
#include <PIT.h>
#include "fsl_pit.h"
#include "defines.h"

/**PIT's ISR flag*/
static volatile bool pitIsrFlag0 = FALSE;

/**Initializing PIT*/
void PIT_init()
{
	uint32_t time = 3000000U;
	pit_config_t pitConfig;
	//CLOCK_SetSimSafeDivs();
	PIT_GetDefaultConfig(&pitConfig);
	PIT_Init(PIT, &pitConfig);
	PIT_set_time(time);
	/* Enable timer interrupts for channel 0 */
	PIT_EnableInterrupts(DEMO_PIT_BASEADDR, PIT_CHANNEL, kPIT_TimerInterruptEnable);
	/* Enable at the NVIC */
	EnableIRQ(PIT0_IRQn);
	PIT_StartTimer(PIT, PIT_CHANNEL);
}

/**Setting the timer period of PIT channel 0*/
void PIT_set_time(uint8_t time)
{
	CLOCK_SetSimSafeDivs();
    PIT_SetTimerPeriod(PIT, PIT_CHANNEL, PIT_CYCLES);
}

/*Handlers of PIT interrupts*/
void PIT0_IRQHandler(void)
	{
	/* Clear interrupt flag.*/
	PIT_ClearStatusFlags(DEMO_PIT_BASEADDR, PIT_CHANNEL, kPIT_TimerFlag);
	pitIsrFlag0 = TRUE;
	__DSB();
}


/**Function to check the interrupt status of the channel 0 of the PIT*/
uint8_t PIT0_get_irq_status()
{
	uint8_t status = 0;
	status = pitIsrFlag0;

	return(status);
}

/**Functtion to erase the status flag of the PIT ISR*/
void PIT0_clear_irq_status()
{
	pitIsrFlag0 = FALSE;
}
