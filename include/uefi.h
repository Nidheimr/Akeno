#ifndef UEFI_H
#define UEFI_H

// This header is created using UEFI Specification 2.10 as a base.
// Not everything is declared, only what is used.
//
// https://uefi.org/sites/default/files/resources/UEFI_Spec_2_10_Aug29.pdf 

// -------------------------------- 
//
// Macros
//
// --------------------------------  

#define UNICODE

// EFI_STATUS
#define EFI_SUCCESS                 0x0000000000000000
#define EFI_NOT_READY               0x8000000000000006

// Text attributes
#define EFI_BLACK                   0x00
#define EFI_BLUE                    0x01
#define EFI_GREEN                   0x02
#define EFI_CYAN                    0x03
#define EFI_RED                     0x04
#define EFI_MAGENTA                 0x05
#define EFI_BROWN                   0x06
#define EFI_LIGHTGRAY               0x07
#define EFI_DARKGRAY                0x08
#define EFI_LIGHTBLUE               0x09
#define EFI_LIGHTGREEN              0x0A
#define EFI_LIGHTCYAN               0x0B
#define EFI_LIGHTRED                0x0C
#define EFI_LIGHTMAGENTA            0x0D
#define EFI_YELLOW                  0x0E
#define EFI_WHITE                   0x0F
#define EFI_BACKGROUND_BLACK        0x00
#define EFI_BACKGROUND_BLUE         0x10
#define EFI_BACKGROUND_GREEN        0x20
#define EFI_BACKGROUND_CYAN         0x30
#define EFI_BACKGROUND_RED          0x40
#define EFI_BACKGROUND_MAGENTA      0x50
#define EFI_BACKGROUND_BROWN        0x60
#define EFI_BACKGROUND_LIGHTGRAY    0x70

// -------------------------------- 
//
// Declarations
//
// --------------------------------  

typedef unsigned short      CHAR16;
typedef unsigned short      UINT16;
typedef unsigned int        UINT32;
typedef unsigned long long  UINT64;
typedef unsigned int        UINTN;
typedef unsigned char       BOOLEAN;

typedef void    *EFI_HANDLE;
typedef void    *EFI_EVENT;
typedef UINT64  EFI_STATUS;

typedef struct _EFI_TABLE_HEADER    EFI_TABLE_HEADER;
typedef struct _EFI_SYSTEM_TABLE    EFI_SYSTEM_TABLE;

// EFI_SIMPLE_TEXT_INPUT_PROTOCOL
typedef struct _EFI_SIMPLE_TEXT_INPUT_PROTOCOL  EFI_SIMPLE_TEXT_INPUT_PROTOCOL;
typedef struct _EFI_INPUT_KEY                   EFI_INPUT_KEY;
typedef EFI_STATUS  (*EFI_INPUT_RESET)          (EFI_SIMPLE_TEXT_INPUT_PROTOCOL *This, BOOLEAN ExtendedVerification);
typedef EFI_STATUS  (*EFI_INPUT_READ_KEY)       (EFI_SIMPLE_TEXT_INPUT_PROTOCOL *This, EFI_INPUT_KEY *Key);

// EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
typedef struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;
typedef EFI_STATUS  (*EFI_TEXT_RESET)           (EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, BOOLEAN ExtendedVerification);
typedef EFI_STATUS  (*EFI_TEXT_STRING)          (EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, CHAR16 *String);
typedef EFI_STATUS  (*EFI_TEXT_TEST_STRING)     (EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, CHAR16 *String);
typedef EFI_STATUS  (*EFI_TEXT_QUERY_MODE)      (EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, UINTN ModeNumber, UINTN *Columns, UINTN *Rows);
typedef EFI_STATUS  (*EFI_TEXT_SET_MODE)        (EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, UINTN ModeNumber);
typedef EFI_STATUS  (*EFI_TEXT_SET_ATTRIBUTE)   (EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, UINTN Attribute); 

// -------------------------------- 
//
// Definitions
//
// --------------------------------  

struct _EFI_TABLE_HEADER
{
    UINT64  Signature;
    UINT32  Revision;
    UINT32  HeaderSize;
    UINT32  CRC32;
    UINT32  Reserved;
};

struct _EFI_SYSTEM_TABLE
{
    EFI_TABLE_HEADER                hrd;
    CHAR16                          *FirmwareVendor;
    UINT32                          FirmwareVersion;
    EFI_HANDLE                      ConsoleInHandle;
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL  *ConIn;
    EFI_HANDLE                      ConsoleOutHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConOut;
};

struct _EFI_SIMPLE_TEXT_INPUT_PROTOCOL
{
    EFI_INPUT_RESET     Reset;
    EFI_INPUT_READ_KEY  ReadKeyStroke;
    EFI_EVENT           WaitForKey;
};

struct _EFI_INPUT_KEY
{
    UINT16  ScanCode;
    UINT16  UnicodeChar;
};

struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
{
    EFI_TEXT_RESET          Reset;
    EFI_TEXT_STRING         OutputString;
    EFI_TEXT_TEST_STRING    TestString;
    EFI_TEXT_QUERY_MODE     QueryMode;
    EFI_TEXT_SET_MODE       SetMode;
    EFI_TEXT_SET_ATTRIBUTE  SetAttribute;
};

#endif //UEFI_H
