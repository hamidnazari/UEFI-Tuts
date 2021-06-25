// UEFI From Scratch Tutorials - ThatOSDev ( 2021 )
// https://github.com/ThatOSDev/UEFI-Tuts

#include "efi.h"
#include "ErrorCodes.h"
#include "efilibs.h"
#include "clibs.h"

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
    Print(L"Hit Any Key to read value from external file\r\n");

    HitAnyKey();
    
            // Kernel stuff here

    InitializeFILESYSTEM();
    
    void* ExternalFileBuffer;

    EFI_FILE_PROTOCOL* efimyfile = openFile(L"myfile.bin");

    UINT64 fsize = 0x00001000;

    EFI_STATUS Status = SystemTable->BootServices->AllocatePool(EfiLoaderData, fsize, (void**)&ExternalFileBuffer);
    Print(L"AllocatePool ExternalFileBuffer");
    Print(CheckStandardEFIError(Status));

    efimyfile->SetPosition(efimyfile, 0);
    
    efimyfile->Read(efimyfile, &fsize, ExternalFileBuffer);
    SetColor(EFI_GREEN);
    Print(L"\r\nRead ExternalFileBuffer");
    Print(CheckStandardEFIError(Status));

    SetColor(EFI_LIGHTCYAN);    
    Print(L"\r\nFile Signature\r\n");
    SetColor(EFI_LIGHTRED);    
    UINT8* test = (UINT8*)ExternalFileBuffer;

    for(int m = 0; m < 5; m++)
    {
        int j = *test;
        UINT16 s[2];
        itoa(j, s, HEX);
        Print(s);
        Print(L"  ");
        test++;
    }

    Print(L"\r\n\r\n");
    
    efimyfile->SetPosition(efimyfile, 262);
    
    efimyfile->Read(efimyfile, &fsize, ExternalFileBuffer);
    SetColor(EFI_GREEN);
    Print(L"Read ExternalFileBuffer");
    Print(CheckStandardEFIError(Status));
    
    closeFile(efimyfile);
    
    SetColor(EFI_LIGHTCYAN);    
    Print(L"\r\nEntry Point\r\n");
    SetColor(EFI_YELLOW);
    UINT8* test2 = (UINT8*)ExternalFileBuffer;
    for(int m = 0; m < 4; m++)
    {
        int j = *test2;
        UINT16 s[2];
        itoa(j, s, HEX);
        Print(s);
        Print(L"  ");
        test2++;
    }

    SetColor(EFI_LIGHTCYAN);
    int (*KernelBinFile)() = ((__attribute__((ms_abi)) int (*)() ) (UINT8*)ExternalFileBuffer);
    int g = KernelBinFile();
    
    UINT16 tmp[8];
    itoa(g, tmp, 10);
    Print(L"\r\n\r\nThe returned number is : ");
    SetColor(EFI_LIGHTMAGENTA);
    Print(tmp);

    SetColor(EFI_GREEN);
    SetTextPosition(8, 24);
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
