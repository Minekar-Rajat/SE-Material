################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ticket\ book.cpp 

OBJS += \
./src/ticket\ book.o 

CPP_DEPS += \
./src/ticket\ book.d 


# Each subdirectory must supply rules for building sources it contributes
src/ticket\ book.o: ../src/ticket\ book.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/ticket book.d" -MT"src/ticket\ book.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


