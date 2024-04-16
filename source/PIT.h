/** @file PIT_Propio.h
*
* @brief Header file where we have the definition of variables for the PIT
* 		 and functions as well whit some for the callbacks
*
* @par
* Diego Fernando Perez Gonzalez EXP. 736696
* Angel Noe Barrera Villalpando EXP. 734472
*/

#ifndef PIT_H_
#define PIT_H_

#include "stdint.h"

#define FALSE 0U
#define TRUE 1U

#define PIT_CHANNEL  	  kPIT_Chnl_0
#define u_SECONDS_CONST (1000000.0F)
#define DEMO_PIT_BASEADDR PIT
#define PIT_CYCLES 30000000U

void PIT_init(void);
void PIT_set_time(uint8_t val_1);
void PIT_start(void);
uint8_t PIT0_get_irq_status(void);
void PIT0_clear_irq_status(void);

#endif /* PIT_H_ */
