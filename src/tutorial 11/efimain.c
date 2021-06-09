// UEFI From Scratch Tutorials - ThatOSDev ( 2021 )
// https://github.com/ThatOSDev/UEFI-Tuts

#include "efi.h"
#include "ErrorCodes.h"
#include "efilibs.h"

// This is like int main() in a typical C program.
// In this case, we create an ImageHandle for the overall EFI interface,
// as well as a System Table pointer to the EFI_SYSTEM_TABLE struct.
// UEFI 2.9 Specs PDF Page 91
EFI_STATUS efi_main(EFI_HANDLE IH, EFI_SYSTEM_TABLE *ST)
{
    // We setup this global variable in the efilibs.h file.
    ImageHandle = IH;
    SystemTable = ST;
    
    ResetScreen();
    
    SetColor(EFI_WHITE);
    SetTextPosition(3, 2);
    Print(L"Welcome to the UEFI From Scratch Tutorials\r\n\r\n");
    
    SetColor(EFI_GREEN);
    SetTextPosition(8, 4);
    Print(L"Hit Any Key to setup Initializations");

    HitAnyKey();
    
    InitializeGOP();

    InitializeFILESYSTEM();

    EFI_FILE_PROTOCOL* mytextfile = openFile(L"mytextfile.txt");

    // Here is where you would load the file into a buffer.

    closeFile(mytextfile);

    SetColor(EFI_GREEN);
    SetTextPosition(2, 13);
    Print(L"Hit q to quit");

    SetColor(EFI_WHITE);
    EFI_INPUT_KEY GetKey;
	UINTN u = 0;
	unsigned int x = 5;
	BOOLEAN y = 1;
	SystemTable->ConIn->Reset(SystemTable->ConIn, 1);
    while(1)
    {
		Delay1();
		u++;
		if(u > 36000)   // This is 36 * 1000 ==> 36 milliseconds
		{
			u = 0;
			SetTextPosition(x, 17);
			Print(L"   ...   ");
			if(y == 1)
			{
			    x++;
			} else {
				x--;
			}
			if(x < 5)
			{
				x = 5;
				y = 1;
			} else if(x > 50)
			{
				x = 50;
				y = 0;
			}
		}
        SystemTable->ConIn->ReadKeyStroke(SystemTable->ConIn, &GetKey);
        if(GetKey.UnicodeChar == 'q')
		{
			break;
        }
    }

    COLD_REBOOT();

    // We should not make it to this point.
    return EFI_SUCCESS;
}
