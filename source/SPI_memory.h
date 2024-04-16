/*
 * SPI_memory.h
 *
 *  Created on: 15 abr. 2024
 *      Author: feRaf
 */

#ifndef SPI_MEMORY_H_
#define SPI_MEMORY_H_

#include "stdint.h"

#define BASE_ADDRESS_MEM 0x40000U
#define READ_CMD 0x03U
#define TWO_BYTES 16U
#define ONE_BYTES 8U
#define ZERO 0U
#define ONE 1U
#define FOUR 4U

uint8_t memory_read_byte( uint32_t location);


#endif /* SPI_MEMORY_H_ */
