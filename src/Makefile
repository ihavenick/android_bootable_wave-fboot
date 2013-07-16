vpath %.c $(SrcDir)

AppObjects := 	FOTA.o \
               s5pc110.o \
               BL3.o \
               string.o \
               footer.o \
               header.o \
               crc32.o \
               sha1.o \
               atag.o \
            
AppObjectsWithPath := $(patsubst %, $(ObjDir)/%, $(AppObjects))

ifeq ($(SYS), LINUX)
	DEFS := -DLINUX
else
	DEFS := -DWINDOWS
endif
#
$(OutDir)/%.fota: $(AppObjectsWithPath) $(ObjDir)/BL3_%.o $(ObjDir)/RAW_%.o
	$(LD) -T $*.lds $(AppObjectsWithPath) $(ObjDir)/RAW_$*.o $(ObjDir)/BL3_$*.o -o $(ObjDir)/$*.elf
	$(OBJCOPY) -O binary $(ObjDir)/$*.elf $@
   
$(ObjDir)/%.o: $(SrcDir)/%.c
	$(CC) $(DEFS) -c -Os $^ -o $@
   
$(ObjDir)/%.o: $(SrcDir)/%.s
	$(AS) $(DEFS) $^ -o $@

clean:
	$(RM) $(call FixPath,$(OutDir)/*.fota)
	$(RM) $(call FixPath,$(OutDir)/*.elf)
	$(RM) $(call FixPath,$(OutDir)/*.o)
