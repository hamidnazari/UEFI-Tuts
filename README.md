# Step by Step Tutorials on how to use the UEFI for OS Development from scratch

THIS IS WINDOWS BASED TUTS, BUT CODE SHOULD WORK IN LINUX AND MAC.  

**DISCORD** : https://discord.gg/6gxEF3QCtB  
**YOUTUBE** : https://www.youtube.com/channel/UCouyC9D6WFBwc24sqdkS-jw  

NOTE : You WILL need to change the makefile to work with Linux / MAC gcc compilers. I do not have Linux or Mac, so I have no way to test it. The line in the makefile "-Wl,-dll -Wl,--subsystem,10" is a WINDOWS gcc compiler line. You do not need it for Linux / Mac GCC versions.  

NOTE 2 : Thanks to FueledByOCHD for his contribution of making this readme file much better to read.  


[Original 2.9 Specs PDF](https://uefi.org/specifications )  


[MinGWx64 ( GCC )](https://nuwen.net/mingw.html) ( For windows, no cross-compiler needed )  

**NOTE :** This works in Windows. Cross-compiler is not needed. But in Linux GCC should still work.  

[OSFMount](https://www.osforensics.com/tools/mount-disk-images.html)  
**NOTE :** I have now included BAT files with the command line switches to use OSFMount without the GUI interface.  
 

**NOTE :** The create image is there for your convenience. I include the EXE and source code to create your own drive.hdd file from scratch. It even has the code setup with a 40 Meg GPT/EFI partition. This way you can see how it works.  

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

More Tuts Coming soon...  


![Current Progress](progress.png)  

![Current Progress](progress2.png)  


