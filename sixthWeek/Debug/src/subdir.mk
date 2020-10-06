################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/avgTempSecond.cpp \
../src/learnTypes.cpp \
../src/massOfBlocks.cpp \
../src/matrix.cpp 

OBJS += \
./src/avgTempSecond.o \
./src/learnTypes.o \
./src/massOfBlocks.o \
./src/matrix.o 

CPP_DEPS += \
./src/avgTempSecond.d \
./src/learnTypes.d \
./src/massOfBlocks.d \
./src/matrix.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -Werror -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


