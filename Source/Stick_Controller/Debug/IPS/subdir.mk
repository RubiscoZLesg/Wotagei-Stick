################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../IPS/lcd.c \
../IPS/lcd_init.c 

OBJS += \
./IPS/lcd.o \
./IPS/lcd_init.o 

C_DEPS += \
./IPS/lcd.d \
./IPS/lcd_init.d 


# Each subdirectory must supply rules for building sources it contributes
IPS/%.o IPS/%.su IPS/%.cyclo: ../IPS/%.c IPS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G030xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I"D:/STM32CubeIDE_1.13.2/STM32Workspace/Stick_Controller/IPS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-IPS

clean-IPS:
	-$(RM) ./IPS/lcd.cyclo ./IPS/lcd.d ./IPS/lcd.o ./IPS/lcd.su ./IPS/lcd_init.cyclo ./IPS/lcd_init.d ./IPS/lcd_init.o ./IPS/lcd_init.su

.PHONY: clean-IPS

