gcc -Wall -Werror -m64 -mabi=ms -ffreestanding -c efimain.c -o efimain.o
gcc -Wall -Werror -m64 -mabi=ms efimain.o -nostdlib -shared -Wl,-dll -Wl,--subsystem,10 -e efi_main -o BOOTX64.EFI

del *.o

gcc -m64 -mabi=ms -Wl,--oformat=binary -c kernel\kernel.c -e main -o myfile.bin

pause
