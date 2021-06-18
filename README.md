# Step by Step Tutorials on how to use the UEFI for OS Development from scratch

THIS IS WINDOWS BASED TUTS, BUT CODE SHOULD WORK IN LINUX AND MAC.  

**DISCORD** : https://discord.gg/6gxEF3QCtB  
**YOUTUBE** : https://www.youtube.com/channel/UCouyC9D6WFBwc24sqdkS-jw  

NOTE : MAKEFILES have been updated to work with linux and osx. Just make sure you use the correct GCC version that will work with the switches in the makefile.  

**Original 2.9 Specs PDF** : https://uefi.org/specifications  

**MinGWx64 ( GCC )** : https://nuwen.net/mingw.html ( This is for windows, no cross-compiler needed. )  

**OSFMount** : https://www.osforensics.com/tools/mount-disk-images.html  
**NOTE** : I have now included BAT files with the command line switches to use OSFMount without the GUI interface.  

**NOTE** : The create image is there for your convenience. I include the EXE and source code to create your own drive.hdd file from scratch. It even has the code setup with a 40 Meg GPT/EFI partition. This way you can see how it works.  

I supplied the qemu bat file to launch qemu and load the drive.hdd file.

- **Tutorials**
    - [TUTORIAL	 1 - TEXT](https://github.com/ThatOSDev/UEFI-Tuts/tree/master/src/tutorial%201)  
    - [TUTORIAL  2 - COLOR](https://github.com/ThatOSDev/UEFI-Tuts/tree/master/src/tutorial%202)  
    - [TUTORIAL  3 - KEYBOARD](https://github.com/ThatOSDev/UEFI-Tuts/tree/master/src/tutorial%203)  
    - [TUTORIAL  4 - ERROR CHECKING](https://github.com/ThatOSDev/UEFI-Tuts/tree/master/src/tutorial%204)  
    - [TUTORIAL  5 - EFI LIBS FILE](https://github.com/ThatOSDev/UEFI-Tuts/tree/master/src/tutorial%205) 
    - [TUTORIAL  6 - CURSOR POSITIONS](https://github.com/ThatOSDev/UEFI-Tuts/tree/master/src/tutorial%206) 
    - [TUTORIAL  7 - GRAPHICS OUTPUT PROTOCOL](https://github.com/ThatOSDev/UEFI-Tuts/tree/master/src/tutorial%207)
    - [TUTORIAL  8 - EFI STALL ( A.K.A. Delay )](https://github.com/ThatOSDev/UEFI-Tuts/tree/master/src/tutorial%208)    
    - [TUTORIAL  9 - COLD REBOOT / SHUTDOWN](https://github.com/ThatOSDev/UEFI-Tuts/tree/master/src/tutorial%209)  
    - [TUTORIAL 10 - UNICODE KeyStroke ( UnicodeChar )](https://github.com/ThatOSDev/UEFI-Tuts/tree/master/src/tutorial%2010)
    - [TUTORIAL 11 - LOAD / OPEN / CLOSE VOLUME + FILE SYSTEM + FILES](https://github.com/ThatOSDev/UEFI-Tuts/tree/master/src/tutorial%2011)  
    - [TUTORIAL 12 - LOADED FILE TO BUFFER + READING IT](https://github.com/ThatOSDev/UEFI-Tuts/tree/master/src/tutorial%2012)
    - [TUTORIAL 13 - CUSTOM FONT](https://github.com/ThatOSDev/UEFI-Tuts/tree/master/src/tutorial%2013)

More Tuts Coming soon... ( **NOTE : The order is subject to change** )  

    * Print String ( With our new font )  
    * Change Resolution  
    * Transfer to test Kernel   
    * Graphics BackBuffer  
    * Image Loading ( BMP, TGA )  
    * PCI  

![Current Progress](progress.png)  

![Current Progress](progress2.png)  

![Current Progress](progress3.png)  
