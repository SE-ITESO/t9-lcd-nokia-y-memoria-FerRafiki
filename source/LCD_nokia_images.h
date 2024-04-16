/*
 * LCD_nokia_images.h
 *
 *  Created on: 25/09/2018
 *      Author: jlpe
 */

#ifndef LCD_NOKIA_IMAGES_H_
#define LCD_NOKIA_IMAGES_H_

#include "stdint.h"

#define TOTAL_IMAGES 6U
#define IMG_LENGTH 504U
#define ELEMENTS_TO_NEXT_IMAGE 0xE08U
#define NO_MORE_IMAGES_ADDRESS 0x45000U

uint8_t * ITESO_IMG(void);

#endif /* LCD_NOKIA_IMAGES_H_ */
