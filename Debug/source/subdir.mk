################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/CLK_Tree.c \
../source/Delay.c \
../source/LCD_nokia.c \
../source/LCD_nokia_images.c \
../source/SPI.c \
../source/SPI_memory.c \
../source/main.c \
../source/semihost_hardfault.c 

C_DEPS += \
./source/CLK_Tree.d \
./source/Delay.d \
./source/LCD_nokia.d \
./source/LCD_nokia_images.d \
./source/SPI.d \
./source/SPI_memory.d \
./source/main.d \
./source/semihost_hardfault.d 

OBJS += \
./source/CLK_Tree.o \
./source/Delay.o \
./source/LCD_nokia.o \
./source/LCD_nokia_images.o \
./source/SPI.o \
./source/SPI_memory.o \
./source/main.o \
./source/semihost_hardfault.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DSERIAL_PORT_TYPE_UART=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Embebidos\Clase\T9_LCD_Nokia\board" -I"C:\Embebidos\Clase\T9_LCD_Nokia\utilities" -I"C:\Embebidos\Clase\T9_LCD_Nokia\drivers" -I"C:\Embebidos\Clase\T9_LCD_Nokia\device" -I"C:\Embebidos\Clase\T9_LCD_Nokia\component\serial_manager" -I"C:\Embebidos\Clase\T9_LCD_Nokia\component\lists" -I"C:\Embebidos\Clase\T9_LCD_Nokia\CMSIS" -I"C:\Embebidos\Clase\T9_LCD_Nokia\component\uart" -I"C:\Embebidos\Clase\T9_LCD_Nokia\source" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/CLK_Tree.d ./source/CLK_Tree.o ./source/Delay.d ./source/Delay.o ./source/LCD_nokia.d ./source/LCD_nokia.o ./source/LCD_nokia_images.d ./source/LCD_nokia_images.o ./source/SPI.d ./source/SPI.o ./source/SPI_memory.d ./source/SPI_memory.o ./source/main.d ./source/main.o ./source/semihost_hardfault.d ./source/semihost_hardfault.o

.PHONY: clean-source

