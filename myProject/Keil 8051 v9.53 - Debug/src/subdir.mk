################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
A51_UPPER_SRCS += \
../src/SILABS_STARTUP.A51 

C_SRCS += \
../src/InitDevice.c \
../src/Interrupts.c \
../src/moteur.c \
../src/myProject_main.c \
../src/variables_globales.c 

OBJS += \
./src/InitDevice.OBJ \
./src/Interrupts.OBJ \
./src/SILABS_STARTUP.OBJ \
./src/moteur.OBJ \
./src/myProject_main.OBJ \
./src/variables_globales.OBJ 


# Each subdirectory must supply rules for building sources it contributes
src/%.OBJ: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Compiler'
	C51 "@$(patsubst %.OBJ,%.__i,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

src/InitDevice.OBJ: C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/C8051F930/inc/SI_C8051F930_Register_Enums.h C:/Users/Minh\ Hac/SimplicityStudio/v3_workspace/myProject/inc/InitDevice.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/C8051F930/inc/SI_C8051F930_Defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/compiler_defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdbool.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdint.h

src/Interrupts.OBJ: C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/C8051F930/inc/SI_C8051F930_Register_Enums.h C:/Users/Minh\ Hac/SimplicityStudio/v3_workspace/myProject/inc/InitDevice.h C:/Users/Minh\ Hac/SimplicityStudio/v3_workspace/myProject/inc/variables_globales.h C:/Users/Minh\ Hac/SimplicityStudio/v3_workspace/myProject/inc/moteur.h C:/Users/Minh\ Hac/SimplicityStudio/v3_workspace/myProject/inc/moteur_port.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/C8051F930/inc/SI_C8051F930_Defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/compiler_defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdbool.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdint.h

src/%.OBJ: ../src/%.A51
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Assembler'
	AX51 "@$(patsubst %.OBJ,%.__ia,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

src/moteur.OBJ: C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/C8051F930/inc/SI_C8051F930_Register_Enums.h C:/Users/Minh\ Hac/SimplicityStudio/v3_workspace/myProject/inc/moteur_port.h C:/Users/Minh\ Hac/SimplicityStudio/v3_workspace/myProject/inc/variables_globales.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/C8051F930/inc/SI_C8051F930_Defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/compiler_defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdbool.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdint.h

src/myProject_main.OBJ: C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/C8051F930/inc/SI_C8051F930_Register_Enums.h C:/Users/Minh\ Hac/SimplicityStudio/v3_workspace/myProject/inc/InitDevice.h C:/Users/Minh\ Hac/SimplicityStudio/v3_workspace/myProject/inc/variables_globales.h C:/Users/Minh\ Hac/SimplicityStudio/v3_workspace/myProject/inc/moteur.h C:/Users/Minh\ Hac/SimplicityStudio/v3_workspace/myProject/inc/moteur_port.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/C8051F930/inc/SI_C8051F930_Defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/compiler_defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdbool.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdint.h


