################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/w25qxx/w25qxx_qspi.c 

OBJS += \
./Drivers/BSP/w25qxx/w25qxx_qspi.o 

C_DEPS += \
./Drivers/BSP/w25qxx/w25qxx_qspi.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/w25qxx/%.o: ../Drivers/BSP/w25qxx/%.c Drivers/BSP/w25qxx/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/BSP/w25qxx -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-w25qxx

clean-Drivers-2f-BSP-2f-w25qxx:
	-$(RM) ./Drivers/BSP/w25qxx/w25qxx_qspi.d ./Drivers/BSP/w25qxx/w25qxx_qspi.o

.PHONY: clean-Drivers-2f-BSP-2f-w25qxx

