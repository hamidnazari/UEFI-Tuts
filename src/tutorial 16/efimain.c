// UEFI From Scratch Tutorials - ThatOSDev ( 2021 )
// https://github.com/ThatOSDev/UEFI-Tuts

#include "efi.h"
#include "ErrorCodes.h"
#include "clibs.h"
#include "efilibs.h"

EFI_STATUS efi_main(EFI_HANDLE IH, EFI_SYSTEM_TABLE *ST)
{
    ImageHandle = IH;
    SystemTable = ST;
    
    ResetScreen();
    
    SetColor(EFI_WHITE);
    SetTextPosition(3, 2);
    Print(L"Welcome to the UEFI From Scratch Tutorials");
    
    SetColor(EFI_GREEN);
    SetTextPosition(8, 4);
    Print(L"Hit Any Key to test Buffered Graphics\r\n");

    HitAnyKey();

    ClearScreen();
	
    if(InitializeGOP() != NULL)
	{
        // Testing our new Buffer pixel Graphics
        SetGraphicsColor(ORANGE);
        CreateBufferFilledBox(10, 10, gBuffer.ScreenWidth - 100, 200);
        SetGraphicsColor(BLUE);
        CreateBufferFilledBox(20, 20, 50, 80);
        SetGraphicsColor(CYAN);
        CreateBufferFilledBox(30, 30, 70, 40);
	}

    SetColor(EFI_GREEN);
    SetTextPosition(8, 10);
    Print(L"Hit q to quit | Hit r to reboot");

    ResetKeyboard();

    while(1)
    {
		Delay1();
		
		EFI_STATUS Status = CheckKey();
		if(Status == EFI_SUCCESS)
		{
			if(GetKey('q') == 1)
			{
				SHUTDOWN();
				break;
			}
			if(GetKey('r') == 1)
			{
				COLD_REBOOT();
				break;
			}
		}

	}

    // We should not make it to this point.
    COLD_REBOOT();

    // We should not make it to this point.
    return EFI_SUCCESS;
}
