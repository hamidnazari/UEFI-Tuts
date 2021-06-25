# Makefile
CC        :=gcc
CFLAGS    :=-Wall -Werror -m64 -mabi=ms
UNAME_S   :=$(shell uname -s)

ifeq ($(UNAME_S),Darwin)
CC        :=x86_64-w64-mingw32-gcc
endif
ifeq ($(UNAME_S),Linux)
CC        :=x86_64-w64-mingw32-gcc
endif

all: BOOTX64.EFI myfile.bin

%.o: %.c
	$(CC) $(CFLAGS) -ffreestanding -c $< -o $@

BOOTX64.EFI: efimain.o
	$(CC) $(CFLAGS) -nostdlib -shared -Wl,-dll -Wl,--subsystem,10 -e efi_main $^ -o $@

myfile.bin: kernel/kernel.c
	$(CC) $(CFLAGS) -Wl,--oformat=binary -e main -c $< -o $@

clean:
	@echo "Cleaning files...."
	rm -f *.o *.EFI *.bin
	@echo "Done."

.PHONY: clean
