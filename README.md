# Step by Step Tutorials on how to use the UEFI for OS Development from scratch

THIS IS WINDOWS BASED TUTS, BUT CODE SHOULD WORK IN LINUX AND MAC.  

**DISCORD** : https://discord.gg/6gxEF3QCtB  

NOTE : You WILL need to change the makefile to work with Linux / MAC gcc compilers. I do not have Linux or Mac, so I have no way to test it. The line in the makefile "-Wl,-dll -Wl,--subsystem,10" is a WINDOWS gcc compiler line. You do not need it for Linux / Mac GCC versions.  

Original 2.9 Specs PDF  
https://uefi.org/specifications 

MinGWx64 ( GCC )  
https://nuwen.net/mingw.html  
**NOTE :** This works in Windows. Cross-compiler is not needed. But in Linux GCC should still work.  

OSFMount  
https://www.osforensics.com/tools/mount-disk-images.html  

**NOTE :** The create image is there for your convenience. I include the EXE and source code to create your own drive.hdd file from scratch. It even has the code setup with a 40 Meg GPT/EFI partition. This way you can see how it works.  

I supplied the qemu bat file to launch qemu and load the drive.hdd file.  

    - [TUTORIAL  1] TEXT  
    - [TUTORIAL  2] COLOR  
    - [TUTORIAL  3] KEYBOARD  
    - [TUTORIAL  4] ERROR CHECKING  
    - [TUTORIAL  5] EFI LIBS FILE 
    - [TUTORIAL  6] CURSOR POSITIONS 
    - [TUTORIAL  7] GRAPHICS OUTPUT PROTOCOL  
    - [TUTORIAL  8] EFI STALL ( A.K.A. Delay )    
    - [TUTORIAL  9] COLD REBOOT  
    - [TUTORIAL 10] UNICODE KeyStroke ( UnicodeChar )  
    - [TUTORIAL 11] LOAD / OPEN / CLOSE VOLUME + FILE SYSTEM + FILES  
    - [TUTORIAL 12] LOADED FILE TO BUFFER + READING IT 

More Tuts Coming soon...  


![Current Progress](progress.png)  

![Current Progress](progress2.png)  


