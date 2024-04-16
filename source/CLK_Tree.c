/*
 *  Authors: Angel Noe; Diego Perez (Team 2)
 *  Date: 10/04/2024
 *
 *  Brief: To control the clock frequency for the FRDM K-64 we need to use the tree
 *  clocks mode, in this file we are configuring the mode of 120Mhz from the board, this
 *  is made dividing the system frequency and then multiplying it, after that we set that frecuency
 *  in the system to use it
 */

#include "CLK_Tree.h"
#include "MK64F12.h"
#include "fsl_clock.h"
#include "defines.h"

void CLK_config()
{
	 mcg_pll_config_t 	 pll0Config =
		 	        {
		 	            .enableMode = MCG_PLL_DISABLE, /* MCGPLLCLK disabled */
		 	            .prdiv      = 0xFU,            /* PLL Reference divider: divided by 15 */
		 	            .vdiv       = 0x0U,            /* VCO divider: multiplied by 36 */
		 	        };


		const osc_config_t osc_config = {
		    .freq        = OSCILLATOR_FREQ,    /* Oscillator frequency: 50000000Hz */
		    .capLoad     = (OSC_CAP0P),  /* Oscillator capacity load: 0pF */
		    .workMode    = kOSC_ModeExt, /* Use external clock */
		    .oscerConfig = {
		        .enableMode =
		            kOSC_ErClkEnable, /* Enable external reference clock, disable external reference clock in STOP mode */
		    }};

		CLOCK_SetSimSafeDivs();
		CLOCK_InitOsc0(&osc_config);
		CLOCK_SetXtal0Freq(osc_config.freq);
		CLOCK_BootToPeeMode(kMCG_OscselOsc, kMCG_PllClkSelPll0,&pll0Config);
}
