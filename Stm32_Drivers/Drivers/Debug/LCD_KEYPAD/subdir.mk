################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LCD_KEYPAD/Keypad.c \
../LCD_KEYPAD/LCD.c 

OBJS += \
./LCD_KEYPAD/Keypad.o \
./LCD_KEYPAD/LCD.o 

C_DEPS += \
./LCD_KEYPAD/Keypad.d \
./LCD_KEYPAD/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
LCD_KEYPAD/Keypad.o: ../LCD_KEYPAD/Keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F101C6Tx -DSTM32 -DSTM32F1 -DDEBUG -c -I"E:/Embedded/New_Drivers/Drivers/LCD_KEYPAD/inc" -I"E:/Embedded/New_Drivers/Drivers/stm32f103c6_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"LCD_KEYPAD/Keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
LCD_KEYPAD/LCD.o: ../LCD_KEYPAD/LCD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F101C6Tx -DSTM32 -DSTM32F1 -DDEBUG -c -I"E:/Embedded/New_Drivers/Drivers/LCD_KEYPAD/inc" -I"E:/Embedded/New_Drivers/Drivers/stm32f103c6_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"LCD_KEYPAD/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

