#pragma once

// This file contains functions that wrap around UEFI protocols to
// make life easier

#include "efi_defs.h"
EFI_SYSTEM_TABLE *SystemTable;

// ResetOutput, clear it and place cursor to origin
void ResetOutput()
{
    SystemTable->ConOut->Reset(SystemTable->ConOut, 1);
}

// ResetInput, clear the input buffer
void ResetInput()
{
    SystemTable->ConIn->Reset(SystemTable->ConIn, 1);
}

// SetOutputAttribute, set the given attribute which is a colour
void SetOutputAttribute(UINTN Attribute)
{
    SystemTable->ConOut->SetAttribute(SystemTable->ConOut, Attribute);
}

// Print, output the given string to the screen
void Print(CHAR16 *String, BOOLEAN AppendNewLine)
{
    SystemTable->ConOut->OutputString(SystemTable->ConOut, String);

    if (AppendNewLine)
        SystemTable->ConOut->OutputString(SystemTable->ConOut, L"\r\n");
}

// WaitForKey, wait for a keystroke then return it
EFI_INPUT_KEY WaitForKey()
{
    EFI_INPUT_KEY key;
    while (SystemTable->ConIn->ReadKeyStroke(SystemTable->ConIn, &key) == EFI_NOT_READY);

    return key;
}
