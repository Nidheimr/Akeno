CROSS_COMPILER = clang
COMMON_FLAGS   = -target x86_64-unknown-windows -I include/
COMPILER_FLAGS = -ffreestanding -fshort-wchar -mno-red-zone
LINKER_FLAGS   = -nostdlib -Wl,-entry:efi_main -Wl,-subsystem:efi_application -fuse-ld=lld-link

OBJECTS = efi_main.o

all: prepare AkenoOS.iso clean

prepare:
	mkdir -p bin/obj/
	mkdir -p bin/iso/

%.o: src/%.c
	$(CROSS_COMPILER) $(COMMON_FLAGS) $(COMPILER_FLAGS) -c -o bin/obj/$@ $<

bootx64.efi: $(OBJECTS)
	$(CROSS_COMPILER) $(COMMON_FLAGS) $(LINKER_FLAGS) -o bin/obj/$@ bin/obj/$<

AkenoOS.img: bootx64.efi
	dd if=/dev/zero of=bin/iso/$@ bs=1k count=1440
	mformat -i bin/iso/$@ -f 1440 ::
	mmd -i bin/iso/$@ ::/efi
	mmd -i bin/iso/$@ ::/efi/boot
	mcopy -i bin/iso/$@ bin/obj/$< ::/efi/boot

AkenoOS.iso: AkenoOS.img
	xorriso -as mkisofs -R -f -e $< -no-emul-boot -o bin/$@ bin/iso/

clean:
	rm -r bin/obj/
	rm -r bin/iso/
