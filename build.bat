@echo off

rem -------------------------------- 
rem Prepare
rem -------------------------------- 

if not exist bin\iso\ mkdir bin\iso\
if not exist bin\obj\ mkdir bin\obj\

rem -------------------------------- 
rem Build
rem -------------------------------- 

rem compile EFI_Main.c
gcc -Wall -Werror -m64 -mabi=ms -ffreestanding -mno-red-zone -c src\EFI_Main.c -o bin\obj\EFI_Main.o
gcc -Wall -Werror -m64 -mabi=ms -nostdlib -shared -Wl,-dll -Wl,--subsystem,10 -e EFI_Main bin\obj\EFI_Main.o -o bin\obj\BOOTX64.EFI

rem create os.img
wsl dd if=/dev/zero of=bin/iso/os.img bs=1k count=1440
wsl mformat -i bin/iso/os.img -f 1440 ::
wsl mmd -i bin/iso/os.img ::/EFI
wsl mmd -i bin/iso/os.img ::/EFI/BOOT
wsl mcopy -i bin/iso/os.img bin/obj/BOOTX64.EFI ::/EFI/BOOT

rem create AkenoOS.iso
wsl xorriso -as mkisofs -R -f -e os.img -no-emul-boot -o bin/AkenoOS.iso bin/iso

rem -------------------------------- 
rem Emulate
rem -------------------------------- 

if "%1"=="run" (
    qemu-system-x86_64 -bios deps\ovmf.fd -net none -cdrom bin\AkenoOS.iso
)
