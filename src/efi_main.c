#include "uefi.h"

EFI_STATUS efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
    SystemTable->ConOut->Reset(SystemTable->ConOut, 1);                         // Clear screen
    SystemTable->ConOut->SetAttribute(SystemTable->ConOut, EFI_GREEN);          // Set print colour
    SystemTable->ConOut->OutputString(SystemTable->ConOut, L"Hit Any Key\r\n"); // Print
    SystemTable->ConIn->Reset(SystemTable->ConIn, 1);                           // Clear input buffer

    EFI_INPUT_KEY key; // Key to be read

    while((SystemTable->ConIn->ReadKeyStroke(SystemTable->ConIn, &key)) == EFI_NOT_READY) {}; // Pause until a key is pressed

    return EFI_SUCCESS; // Everything went right
}
