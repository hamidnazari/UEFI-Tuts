# UEFI Tutorials
## Build Instructions

### Windows
1. Install an emulator, QEMU, or VirtualBox, or both from the links below:
    - QEMU: https://www.qemu.org/
    - VirtualBox: https://www.virtualbox.org/
1. Install MinGW GCC from https://nuwen.net/mingw.html
1. Install OSFMount from https://www.osforensics.com/tools/mount-disk-images.html
1. Each tutorial has accompanying `compileEFI.bat` and `mountdrive.bat` files;
    1. Run `compileEFI.bat` to compile the `BOOTX64.EFI` binary.
    1. Once you have `BOOTX64.EFI` compiled, run `mountdrive.bat` to copy the binary to `drive.hdd`.
1. Now run `run-qemu.bat` in the root directory of this repository and you'll see that tutorial running in QEMU.

### MacOS
1. Install Homebrew from https://brew.sh/
1. Install an emulator, QEMU, or VirtualBox, or both. Run:
    - `brew install qemu`  
    - `brew install virtualbox`
1. Install MinGW GCC by running:
    - `brew install mingw-w64`
1. Each tutorial has an accompanying `Makefile`;
    - Run `make clean` to start with a clean slate.
    - Run `make` to build `BOOTX64.EFI`.
1. Copy `BOOTX64.EFI` into `drive.hdd` and run QEMU or VirtualBox with the new build.

### Linux
I'll be using Debian and Apt for demonstration purposes. Use your system's equivalent package manager and package names for the software below.

1. Install an emulator, QEMU, or VirtualBox, or both. Run:  
   - `apt-get install qemu-kvm`
   - For VirtualBox, follow instructions here: https://www.virtualbox.org/wiki/Linux_Downloads
1. Install MinGW GCC by running:
   - `apt-get install build-essential`
   - `apt-get install mingw-w64`
1. Each tutorial has an accompanying `Makefile`;
    - Run `make clean` to start with a clean slate.
    - Run `make` to build `BOOTX64.EFI`.
1. Copy `BOOTX64.EFI` into `drive.hdd` and run QEMU or VirtualBox with the new build.
