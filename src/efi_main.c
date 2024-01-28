#include "efi_defs.h"
#include "efi_libs.h"

EFI_STATUS efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *_SystemTable)
{
    SystemTable = _SystemTable;

    ResetOutput();
    ResetInput();

    SetOutputAttribute(EFI_GREEN);
    Print(L"Press any key to continue...", TRUE);

    WaitForKey();

    return EFI_SUCCESS;
}
