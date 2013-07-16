include Make_dirs

ARMTK := g:\bada\2.0.6\Tools\Toolchains\ARM

CC := $(ARMTK)/bin/arm-bada-eabi-gcc.exe
AS := $(ARMTK)/bin/arm-bada-eabi-as.exe
LD := $(ARMTK)/bin/arm-bada-eabi-ld.exe
RM := $(ARMTK)/bin/rm.exe
OBJCOPY := $(ARMTK)/bin/arm-bada-eabi-objcopy.exe

Applications := FBOOT_S8500_b2x
OutputFiles := $(patsubst %, $(OutDir)/%.fota, $(Applications))

application: $(OutputFiles)

rebuild: clean application

include $(SrcMake)
