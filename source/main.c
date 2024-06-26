/**
*	main.c
*
*	Authors: Angel Noe Barrera Villalpando
*			 Diego Fernando Perez Gonzalez
*			 Team 2
*
*	Date: 16/04/2024
*
*	Brief: In this SPI project we are making use of a NOKIA LCD and a non-volatile
*		   flash memory, both working with SPI protocol. We displayed on the LCD 6
*		   images of which 5 of them are stored in the memory. Therefore we had to
*		   read them (byte by byte) in order to be able to show them afterwards.
*
*/

 
/**Included files:*/
#include "LCD_nokia.h"
#include "LCD_nokia_images.h"
#include "stdint.h"
#include "SPI.h"


#include "SPI_memory.h"
#include "PIT.h"

int main(void)
{
	SPI_config();		/**SPI essential configuration for both the LCD and the memory*/
	LCD_nokia_init(); 	/*! Initialization function for the LCD */

	PIT_init();

	/**Control counters and base addresses:*/
	uint8_t image_count = ZERO;
	uint16_t byte_elemnt = ZERO;
	uint8_t image[IMG_LENGTH] = {ZERO};
	uint32_t mem_images_address = BASE_ADDRESS_MEM;
	uint8_t * ITESO = ITESO_IMG();

	/**Infinite loop (where we constantly display the 6 images)*/
	for(;;)
	{
		if(TRUE ==  PIT0_get_irq_status())
		{
			image_count++;
			LCD_nokia_clear();/**! It clears the information printed in the LCD*/

			if(TOTAL_IMAGES != image_count )
			{
				while(IMG_LENGTH > byte_elemnt)
				{
					image[byte_elemnt] = memory_read_byte(mem_images_address);
					byte_elemnt++;
					mem_images_address++;
				}

				byte_elemnt = ZERO;
				LCD_nokia_bitmap(image);
				mem_images_address += ELEMENTS_TO_NEXT_IMAGE;

				if(NO_MORE_IMAGES_ADDRESS == mem_images_address)
				{
					mem_images_address = BASE_ADDRESS_MEM;
				}
			}
			else
			{
				LCD_nokia_bitmap(ITESO);
				image_count = ZERO;
			}

			PIT0_clear_irq_status();
		}

	}
	return 0;
}

