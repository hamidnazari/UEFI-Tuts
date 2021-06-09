// UEFI From Scratch Tutorials - ThatOSDev ( 2021 )
// https://github.com/ThatOSDev/UEFI-Tuts

#include "efi.h"
#include "ErrorCodes.h"
#include "efilibs.h"

// This is like int main() in a typical C program.
// In this case, we create an ImageHandle for the overall EFI interface,
// as well as a System Table pointer to the EFI_SYSTEM_TABLE struct.
// UEFI 2.9 Specs PDF Page 91
EFI_STATUS efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *ST)
{
    // We setup this global variable in the libs.h file.
    SystemTable = ST;
    
    ResetScreen();
    
    SetColor(EFI_WHITE);
    SetTextPosition(3, 2);
    Print(L"Welcome to the UEFI From Scratch Tutorials\r\n\r\n");
    
    SetColor(EFI_YELLOW);
    SetTextPosition(3, 5);
    Print(L"We have Simple-Text Cursor Positions.");
    
    SetColor(EFI_GREEN);
    SetTextPosition(8, 8);
    Print(L"Hit Any Key to Clear the Screen");
    
    HitAnyKey();
    
    ClearScreen();

    SetColor(EFI_CYAN);
    SetTextPosition(2, 1);
    Print(L"The Screen has been cleared !");
    
    SetColor(EFI_GREEN);
    SetTextPosition(2, 4);
    Print(L"Hit Any Key");

    HitAnyKey();

    // The EFI needs to have a 0 ( or EFI_SUCCESS ) in order to know everything is ok.
    return 0;
}
