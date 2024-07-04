################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32f103c6_drivers/GPIO_driver.c 

OBJS += \
./stm32f103c6_drivers/GPIO_driver.o 

C_DEPS += \
./stm32f103c6_drivers/GPIO_driver.d 


# Each subdirectory must supply rules for building sources it contributes
stm32f103c6_drivers/GPIO_driver.o: ../stm32f103c6_drivers/GPIO_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F101C6Tx -DSTM32 -DSTM32F1 -DDEBUG -c -I"E:/Embedded/New_Drivers/Drivers/LCD_KEYPAD/inc" -I"E:/Embedded/New_Drivers/Drivers/stm32f103c6_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_drivers/GPIO_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

