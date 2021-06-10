// UEFI From Scratch Tutorials - ThatOSDev ( 2021 )
// https://github.com/ThatOSDev/UEFI-Tuts

#include "efi.h"
#include "ErrorCodes.h"
#include "efilibs.h"
#include "clibs.h"

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

    // We create the buffer, allocate memory for it, then read
    // the rile into the buffer. After which, we close the file.
    void* OSBuffer_Handle;
    
    EFI_FILE_PROTOCOL* mytextfile = openFile(L"mytextfile.txt");
    if(mytextfile != NULL)
    {
        SetColor(EFI_BROWN);
        Print(L"AllocatingPool ... ");
        EFI_STATUS Status = SystemTable->BootServices->AllocatePool(EfiLoaderData, 0x00100000, (void**)&OSBuffer_Handle);
        SetColor(EFI_CYAN);
        Print(CheckStandardEFIError(Status));
    
        UINT64 fileSize = 0x00100000;
        
        SetColor(EFI_BROWN);
        Print(L"Reading File ... ");
        Status = mytextfile->Read(mytextfile, &fileSize, OSBuffer_Handle);
        SetColor(EFI_CYAN);
        Print(CheckStandardEFIError(Status));

        closeFile(mytextfile);
    }

    Print(L"\r\n");

    // OSBuffer_Handle This is our new File Handle. We can access the file from here.
    
    SetColor(EFI_LIGHTGRAY);
    
    // What we do now is test to see what this buffer is holding.
    // The code below converts the binary code in the buffer,
    // into a readable ASCII numbers. Each set of numbers represents
    // a code in ASCII. So as an exercise, see if you can figure out
    // the message without looking at the text file.
    // I included clibs.h to house the C function known as itoa().
    UINT8* test = (UINT8*)OSBuffer_Handle;
    
    int m;
    for(m = 0; m < 20; m++)
    {
        UINT8 g = *test;
        UINT16 s[2];
        itoa(g, s, HEX);
        Print(s);
        Print(L" ");
        test++;
    }

    SetColor(EFI_GREEN);
    SetTextPosition(2, 18);
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
			SetTextPosition(x, 20);
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
