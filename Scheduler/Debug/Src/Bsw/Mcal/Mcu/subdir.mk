################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Src/Bsw/Mcal/Mcu/Mcu.c" \

C_SRCS += \
../Src/Bsw/Mcal/Mcu/Mcu.c \

OBJS_OS_FORMAT += \
./Src/Bsw/Mcal/Mcu/Mcu.o \

C_DEPS_QUOTED += \
"./Src/Bsw/Mcal/Mcu/Mcu.d" \

OBJS += \
./Src/Bsw/Mcal/Mcu/Mcu.o \

OBJS_QUOTED += \
"./Src/Bsw/Mcal/Mcu/Mcu.o" \

C_DEPS += \
./Src/Bsw/Mcal/Mcu/Mcu.d \


# Each subdirectory must supply rules for building sources it contributes
Src/Bsw/Mcal/Mcu/Mcu.o: ../Src/Bsw/Mcal/Mcu/Mcu.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Src/Bsw/Mcal/Mcu/Mcu.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "Src/Bsw/Mcal/Mcu/Mcu.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


