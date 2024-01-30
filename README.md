# Akeno

## Overview

Akeno is an x64 UEFI operating system. This project was made for educational purposes and may not be efficient or well written.
To emulate, you will need to use a UEFI system. Qemu with OVMF works from my experience.

## Building

### Windows

Using Windows Subsystem for Linux, run `make` on the provided Makefile.

### Dependencies

- xorriso (>= 1.5.4-2)
- mtools (>= 4.0.33-1+really4.0.32-1build1)
- clang (>= 1:14.0-55~exp2)
- llvm (>= 1:14.0-55~exp2)
- lld (>= 16.0.6-1)
