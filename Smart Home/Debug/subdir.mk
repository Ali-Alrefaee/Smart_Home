################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App.c \
../DIO.c \
../FLAME.c \
../KEYPAD.c \
../KEYPAD_cfg.c \
../LCD.c \
../LCD_cfg.c \
../RAIN_SENSOR.c \
../SERVO.c 

OBJS += \
./App.o \
./DIO.o \
./FLAME.o \
./KEYPAD.o \
./KEYPAD_cfg.o \
./LCD.o \
./LCD_cfg.o \
./RAIN_SENSOR.o \
./SERVO.o 

C_DEPS += \
./App.d \
./DIO.d \
./FLAME.d \
./KEYPAD.d \
./KEYPAD_cfg.d \
./LCD.d \
./LCD_cfg.d \
./RAIN_SENSOR.d \
./SERVO.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g3 -gdwarf-2 -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


