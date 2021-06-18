// UEFI From Scratch Tutorials - ThatOSDev ( 2021 )
// https://github.com/ThatOSDev/UEFI-Tuts

#include "efi.h"
#include "ErrorCodes.h"
#include "efilibs.h"
#include "clibs.h"
#include "tosdfont.h"

void GetCharacter(UINT32 character, UINT32 xPos, UINT32 yPos, UINT32 fs)
{
	pixelpos->PixelxPos = xPos;
	pixelpos->PixelyPos = yPos;
	UINT32 SelectASCII  = character;

	UINT32 mcX = pixelpos->PixelxPos;
	UINT32 mcY = pixelpos->PixelyPos;
	UINT32 pPos = 0;
	UINT32 sPos = 0;
	UINT32 FontSize = (UINT32)(fs / 4);

	for(UINT32 t = (SelectASCII * 128); t < ((SelectASCII * 128) + 128); t++)
	{
		if(pPos > 7)
		{
			pPos = 0;
			mcY += FontSize;
			mcX = pixelpos->PixelxPos;
			sPos++;
			if(sPos > 15)
			{
				sPos = 0;
				mcY += FontSize;
			}
		}
		UINT32 ASCIIColor = asciifont[t];
		switch(ASCIIColor)
		{
			case 0:
			{
				break;
			}
			case 1:
			{
				CreateFilledBox(mcX, mcY, FontSize, FontSize);
				break;
			}
		}
		mcX += FontSize;
		pPos++;
	}
}

void TestASCII(UINT32 sizeme)
{
	SetGraphicsColor(BLUE);
	
	CreateFilledBox(5, 5, (ScreenWidth - 15), (ScreenHeight - 15));
	
	SetGraphicsColor(GRAY);
		
	UINT32 tX = 8;
	UINT32 tY = 12;
	UINT32 fSize = sizeme;
	UINT32 fSize2 = sizeme;
	
	for(UINT32 k = 0; k < 256; k++)
    {
	    GetCharacter(k, tX, tY, fSize);
		tX += fSize + fSize;
		if(tX > (ScreenWidth - ((10 + fSize) + fSize)))
		{
			tX = 10;
			tY += (fSize * 2) + (fSize * 2);
		}
	}
	
	SetGraphicsColor(WHITE);
		
	tX = 10;
	tY = 10;
	
	for(UINT32 k = 0; k < 256; k++)
    {
	    GetCharacter(k, tX, tY, fSize2);
		tX += fSize2 + fSize2;
		if(tX > (ScreenWidth - ((10 + fSize2) + fSize2)))
		{
			tX = 10;
			tY += (fSize2 * 2) + (fSize2 * 2);
		}
	}
}

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
    Print(L"Hit Any Key to see a font");

    HitAnyKey();
    
    InitializeGOP();
	
	CreateFilledBox(5, 5, (ScreenWidth - 10), (ScreenHeight - 10));
	
	UINT32 FontSizeMin = 4;
	UINT32 FontSizeMax = 190;
	
    UINT32 ChangeSize = FontSizeMin;
	
    TestASCII(ChangeSize);

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
			if(GetKey('w') == 1)
			{
				ChangeSize++;
				if(ChangeSize > FontSizeMax) {ChangeSize = FontSizeMax;}
				TestASCII(ChangeSize);
			}
			if(GetKey('s') == 1)
			{
				ChangeSize--;
				if(ChangeSize < FontSizeMin) {ChangeSize = FontSizeMin;}
				TestASCII(ChangeSize);
			}
		}

	}

    // We should not make it to this point.
    COLD_REBOOT();

    // We should not make it to this point.
    return EFI_SUCCESS;
}
