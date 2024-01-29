# Akeno

## Overview

A probably badly written x64 UEFI operating system, to learn how it all works. This project will probably be abandoned and never be finished.

## Building

### Windows

Using Windows Subsystem for Linux, run `make` on the provided Makefile.

### Dependencies

- xorriso (>= 1.5.4-2)
- mtools (>= 4.0.33-1+really4.0.32-1build1)
- clang (>= 1:14.0-55~exp2)
- llvm (>= 1:14.0-55~exp2)
- lld (>= 16.0.6-1)

## Credit

`deps/ovmf.fd` is not mine, it is a 64-bit debug build of OVMF from https://github.com/tianocore/edk2
