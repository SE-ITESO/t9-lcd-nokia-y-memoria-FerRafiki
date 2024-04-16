/**
*	SPI_memory.c
*
*	Authors: Angel Noe Barrera Villalpando
*			 Diego Fernando Perez Gonzalez
*			 Team 2
*
*	Date: 16/04/2024
*
*	Brief: In this module we have the memory's read function to be able to extract the images
*	in order to save them in an array an then display them on the LCD
*
*/

/**Included files*/
#include "SPI_memory.h"
#include "fsl_gpio.h"
#include "fsl_port.h"
#include "SPI.h"
#include "stdint.h"
#include "fsl_dspi.h"


/**Read function for the memory*/
uint8_t memory_read_byte( uint32_t location)
{
	/*
	 * Half duplex transfer configuration.
	 * Because we have communication in both directions for the memory:
	 */
	dspi_half_duplex_transfer_t masterXfer;

	/**Command read (0x03) and the separated address in blocks of one byte:*/
	uint8_t	commands[] = {READ_CMD,(location >> TWO_BYTES),((location & 0x0FF00)>>8),
						  location & 0x000FF};
	uint8_t byte_to_read[1] = {0};

	masterXfer.txData      = commands;
	masterXfer.rxData      = byte_to_read;
	masterXfer.txDataSize  = FOUR;
	masterXfer.rxDataSize  = ONE;
	masterXfer.configFlags = kDSPI_MasterCtar1 | kDSPI_MasterPcs1 | kDSPI_MasterPcsContinuous;
	masterXfer.isPcsAssertInTransfer = true;
	masterXfer.isTransmitFirst       = true;

	DSPI_MasterHalfDuplexTransferBlocking(SPI0, &masterXfer);

	return byte_to_read[0];
}
