// UEFI From Scratch Tutorials - ThatOSDev ( 2021 )
// https://github.com/ThatOSDev/UEFI-Tuts

#include "efi.h"
#include "ErrorCodes.h"

// This is like int main() in a typical C program.
// In this case, we create an ImageHandle for the overall EFI interface,
// as well as a System Table pointer to the EFI_SYSTEM_TABLE struct.
// UEFI 2.9 Specs PDF Page 91
EFI_STATUS efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
    // This clears the screen and buffer.
    SystemTable->ConOut->Reset(SystemTable->ConOut, 1);

    // We set the color Yellow for the text output.
    SystemTable->ConOut->SetAttribute(SystemTable->ConOut, EFI_YELLOW);

    // Text Output  ( A.K.A. ConOut is Console Out )
    SystemTable->ConOut->OutputString(SystemTable->ConOut, L"Flushing Keyboard ... ");
    
    // We set the color Cyan for the text output.
    SystemTable->ConOut->SetAttribute(SystemTable->ConOut, EFI_CYAN);

    // We flush the keyboard, but also get a return status result.
    EFI_STATUS results = SystemTable->ConIn->Reset(SystemTable->ConIn, 1);
    
    // We check for errors from the results.
    SystemTable->ConOut->OutputString(SystemTable->ConOut, CheckStandardEFIError(results));

    // Here is where we set the color Light Green for the text output.
    SystemTable->ConOut->SetAttribute(SystemTable->ConOut, EFI_LIGHTGREEN);

    // Text Output  ( A.K.A. ConOut is Console Out )
    SystemTable->ConOut->OutputString(SystemTable->ConOut, L"Hit Any Key\r\n");

    // We setup the struct to take keyboard input.
    EFI_INPUT_KEY Key;

    // In a while loop to see if the keyboard has a key stroke in the buffer.
    while((SystemTable->ConIn->ReadKeyStroke(SystemTable->ConIn, &Key)) == EFI_NOT_READY);

    // The EFI needs to have a 0 ( or EFI_SUCCESS ) in order to know everything is ok.
    return 0;
}
