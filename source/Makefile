TARGET = kmenu
OBJS   = main.o 
VITA_MENU_LIB = ../vitamenulib/libvitamenu/*.cc

LIBS = -lvita2d -lm -lpng -ljpeg -lz -lc_stub -lSceKernel_stub -lSceDisplay_stub -lSceGxm_stub	\
	-lSceCtrl_stub -lSceTouch_stub

PREFIX  = $(DEVKITARM)/bin/arm-none-eabi
CC      = $(PREFIX)-gcc
CFLAGS  = -Wall -specs=psp2.specs
CXXFLAGS = $(CFLAGS) -I$(PSP2SDK)/include/c++ -fno-exceptions
CXX      = $(PREFIX)-g++
ASFLAGS = $(CFLAGS)

all: $(TARGET)_fixup.elf

%_fixup.elf: %.elf
	psp2-fixup -q -S $< $@

$(TARGET).elf: $(OBJS) $(VITA_MENU_LIB) libUVL/libuvl_stub.a
	$(CC) $(CXXFLAGS) $^ $(LIBS) -o $@ 

libUVL/libuvl_stub.a:
	$(MAKE) -C $(dir $@) $(notdir $@)

clean:
	@rm -rf $(TARGET)_fixup.elf $(TARGET).elf $(OBJS)
	@$(MAKE) -C libUVL clean