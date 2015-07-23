TARGET := libuvl_stub.a

PREFIX  = $(DEVKITARM)/bin/arm-none-eabi
CC      = $(PREFIX)-gcc
CFLAGS  = -Wall -specs=psp2.specs

ENTRIES := $(addsuffix .o,$(addprefix UVL_,BCEAB831 98D1C91D EEC99826 C85B400C D4F59028 E8E92954))
OBJS	:= UVL_head.o UVL_NIDS.o $(ENTRIES)

all: $(TARGET)

$(TARGET): $(OBJS)
	ar rvs $@ $^

UVL_head.o: UVL.S
	$(CC) $(CFLAGS) -DHEAD -c $< -o $@

UVL_NIDS.o: UVL.S
	$(CC) $(CFLAGS) -DNIDS -c $< -o $@

$(ENTRIES): UVL.S
	$(CC) $(CFLAGS) -DFUNC=$(subst UVL_,0x,$*) $< -c -o $@

clean:
	@rm -rf $(OBJS) $(TARGET)
