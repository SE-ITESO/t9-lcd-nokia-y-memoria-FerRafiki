/*
 * SPI_memory.c
 *
 *  Created on: 15 abr. 2024
 *      Author: feRaf
 */

#include "SPI_memory.h"
#include "fsl_gpio.h"
#include "fsl_port.h"
#include "SPI.h"
#include "stdint.h"
#include "fsl_dspi.h"



uint8_t memory_read_byte( uint32_t location)
{

	dspi_half_duplex_transfer_t masterXfer;
	uint8_t	commands[] = {READ_CMD,(location >> TWO_BYTES),((location & 0x0FF00)>>8),location & 0x000FF};
	uint8_t byte_to_read[1] = {0};


	masterXfer.txData      = commands;
	masterXfer.rxData      = byte_to_read;
	masterXfer.txDataSize  = FOUR;
	masterXfer.rxDataSize  = ONE;
	masterXfer.configFlags = kDSPI_MasterCtar1 | kDSPI_MasterPcs1 | kDSPI_MasterPcsContinuous; //IMPORTANTE, se señala el ctar a utilizar y el chip select a utilizar
	masterXfer.isPcsAssertInTransfer = true;
	masterXfer.isTransmitFirst       = true;

	DSPI_MasterHalfDuplexTransferBlocking(SPI0, &masterXfer);

	return byte_to_read[0];
}
