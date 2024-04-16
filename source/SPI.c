
#include "SPI.h"
#include "fsl_dspi.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "fsl_clock.h"
#include "clock_config.h"

void SPI_config(void)
{
	uint32_t srcClock_Hz_LCD;
	uint32_t srcClock_Hz_MEM;

	CLOCK_SetSimSafeDivs();

	 dspi_master_config_t masterConfig_LCD;
	 dspi_master_config_t masterConfig_MEM;


	CLOCK_EnableClock(kCLOCK_PortC);                           /* Port C Clock Gate Control: Clock enabled */
	CLOCK_EnableClock(kCLOCK_PortD);                           /* Port D Clock Gate Control: Clock enabled */

	/**Pines para la LCD y memoria*/
	PORT_SetPinMux(PORTD, PIN0_IDX, kPORT_MuxAlt2);            /* PORTD0 (pin 93) is configured as SPI0_PCS0 */
	PORT_SetPinMux(PORTD, PIN1_IDX, kPORT_MuxAlt2);            /* PORTD1 (pin 94) is configured as SPI0_SCK */
	PORT_SetPinMux(PORTD, PIN2_IDX, kPORT_MuxAlt2);            /* PORTD2 (pin 95) is configured as SPI0_SOUT */


	/**Pines para la memoria exclusivamente*/
	PORT_SetPinMux(PORTC, PIN3_IDX, kPORT_MuxAlt2);            /* PORTC3 is configured as SPI0_PCS1 */
	PORT_SetPinMux(PORTD, PIN3_IDX, kPORT_MuxAlt2);            /* PORTD3 is configured as SPI0_SOUT */



	 /* Master config (LCD)*/
	masterConfig_LCD.whichCtar                                = kDSPI_Ctar0;   //Configuracion de transmision. Tener 2 ctars para la pantalla y la memoria
	masterConfig_LCD.ctarConfig.baudRate                      = TRANSFER_BAUDRATE;
	masterConfig_LCD.ctarConfig.bitsPerFrame                  = 8U;
	masterConfig_LCD.ctarConfig.cpol                          = kDSPI_ClockPolarityActiveHigh;
	masterConfig_LCD.ctarConfig.cpha                          = kDSPI_ClockPhaseFirstEdge;
	masterConfig_LCD.ctarConfig.direction                     = kDSPI_MsbFirst;
	masterConfig_LCD.ctarConfig.pcsToSckDelayInNanoSec        = 1000000000U / TRANSFER_BAUDRATE;   //Tiempos con los que jugar en la tarea
	masterConfig_LCD.ctarConfig.lastSckToPcsDelayInNanoSec    = 1000000000U / TRANSFER_BAUDRATE;
	masterConfig_LCD.ctarConfig.betweenTransferDelayInNanoSec = 1000000000U / TRANSFER_BAUDRATE;

	masterConfig_LCD.whichPcs           = kDSPI_Pcs0;
	masterConfig_LCD.pcsActiveHighOrLow = kDSPI_PcsActiveLow;   //

	masterConfig_LCD.enableContinuousSCK        = false;
	masterConfig_LCD.enableRxFifoOverWrite      = false;
	masterConfig_LCD.enableModifiedTimingFormat = false;
	masterConfig_LCD.samplePoint                = kDSPI_SckToSin0Clock;

	srcClock_Hz_LCD = CLOCK_GetFreq(kCLOCK_BusClk);
	DSPI_MasterInit(SPI0, &masterConfig_LCD, srcClock_Hz_LCD);

 /* Master config (Memory)*/
	masterConfig_MEM.whichCtar                                = kDSPI_Ctar1;   //Configuracion de transmision. Tener 2 ctars para la pantalla y la memoria
	masterConfig_MEM.ctarConfig.baudRate                      = 2000000U;
	masterConfig_MEM.ctarConfig.bitsPerFrame                  = 8U;
	masterConfig_MEM.ctarConfig.cpol                          = kDSPI_ClockPolarityActiveLow;
	masterConfig_MEM.ctarConfig.cpha                          = kDSPI_ClockPolarityActiveLow;
	masterConfig_MEM.ctarConfig.direction                     = kDSPI_MsbFirst;
	masterConfig_MEM.ctarConfig.pcsToSckDelayInNanoSec        = 1000000000U / TRANSFER_BAUDRATE;   //Tiempos con los que jugar en la tarea
	masterConfig_MEM.ctarConfig.lastSckToPcsDelayInNanoSec    = 1000000000U / TRANSFER_BAUDRATE;
	masterConfig_MEM.ctarConfig.betweenTransferDelayInNanoSec = 1000000000U / TRANSFER_BAUDRATE;

	masterConfig_MEM.whichPcs           = kDSPI_Pcs1;
	masterConfig_MEM.pcsActiveHighOrLow = kDSPI_PcsActiveLow;   //

	masterConfig_MEM.enableContinuousSCK        = false;
	masterConfig_MEM.enableRxFifoOverWrite      = false;
	masterConfig_MEM.enableModifiedTimingFormat = false;
	masterConfig_MEM.samplePoint                = kDSPI_SckToSin0Clock;

	srcClock_Hz_MEM = CLOCK_GetFreq(DSPI0_CLK_SRC);
	DSPI_MasterInit(SPI0, &masterConfig_MEM, srcClock_Hz_MEM);
}
