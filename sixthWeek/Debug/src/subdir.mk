################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/avgTempSecond.cpp \
../src/baseOfRegions.cpp \
../src/comparisonOperator.cpp \
../src/learnTypes.cpp \
../src/massOfBlocks.cpp \
../src/matrix.cpp \
../src/tasksTracker.cpp 

OBJS += \
./src/avgTempSecond.o \
./src/baseOfRegions.o \
./src/comparisonOperator.o \
./src/learnTypes.o \
./src/massOfBlocks.o \
./src/matrix.o \
./src/tasksTracker.o 

CPP_DEPS += \
./src/avgTempSecond.d \
./src/baseOfRegions.d \
./src/comparisonOperator.d \
./src/learnTypes.d \
./src/massOfBlocks.d \
./src/matrix.d \
./src/tasksTracker.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ --std=c++1z -O0 -g3 -Wall -Werror -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


