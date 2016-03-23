################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/DivisactionCommandLine.cpp \
../src/Looper.cpp 

OBJS += \
./src/DivisactionCommandLine.o \
./src/Looper.o 

CPP_DEPS += \
./src/DivisactionCommandLine.d \
./src/Looper.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/ricardo/Documents/Eclipse C++ Workspaces/Divisaction/Divisaction" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++14 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


