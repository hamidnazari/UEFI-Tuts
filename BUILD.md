# UEFI Tutorials
## Manipulating the Disk Image
When we develop an EFI binary, we will need to have a way of feeding it to an emulator for it to boot from. One good way
of doing this is to create a disk image with appropriate partitioning and file systems, and configure the emulator to
use that image as the booting drive.

Additionally, we will need a way of moving our EFI builds into this image. This part of the document explains how this
step can be performed on various operating systems.

There's a ZIP called called `drive-gpt.zip` in `UEFI-Tuts/hold` directory that contains a 256MB disk image. Unzip it and
use it for the remainder of the tutorial.

**Note:** There's also have a 40MB drive in `UEFI-Tuts/drive` directory that mounts nicely on Windows, however on
other operating systems it may not behave so nicely.

### Windows - Method 1: GUI
#### Mounting
1. Have [OSFMount][osfmount] installed.
1. Open OSFMount.
1. Click on `Mount`.
1. Pick `Disk image file`, browse to `drive.hdd`, select and open it. Click on `Next`.
1. Select `Mount entire image as virtual disk`, and click `Next`.
1. Uncheck `Read-only drive` and set `Write mode` to `Direct`.
1. Set `Drive type` as HDD and click on `Mount`.

Following these steps, you should now have a drive in Windows file explorer that you can interact with, i.e. copy your
EFI builds onto it.

#### Unmounting
1. Make sure all operations on the disk is done and the disk is not busy.
1. Open OFMount.
1. Select the virtual drive you wish to unmount and click on `Dismount`.

### Windows - Method 2: CLI
1. Have [OSFMount][osfmount] installed.
1. Open any tutorial folders from the `UEFI-Tuts/src` folder.
1. Make sure you have a `BOOTX64.EFI` file ready, if not, follow the build instructions below.
1. Run `mountdrive.bat`.

This will copy the EFI binary in the tutorial directory onto the drive which now your emulator can read and execute.

#### Unmounting
1. Make sure all operations on the disk is done and the disk is not busy.
1. Run the `UEFI-Tuts/src/unmount.bat` file.

### MacOS
#### Mounting
**Note:** There is no need to run `sudo` for any of the commands below.
1. Unzip the `UEFI-Tuts/hold/drive-gpt.zip`, it contains a 256MB disk image called `drive.hdd`. (Do not use the 40MB
   disk image.)
1. _Attach_ the disk (but not mount),
   ```
   $ hdiutil attach -imagekey diskimage-class=CRawDiskImage -nomount drive.hdd
   /dev/disk2          	GUID_partition_scheme
   /dev/disk2s1        	Microsoft Reserved
   /dev/disk2s2        	Microsoft Basic Data
   ```
1. The command before will show you the device name that's been given to the image. In this case, it's `/dev/disk2`, but
   we are interested in its second partition, `/dev/disk2s2`.
1. Create a directory that will be our mountpoint, e.g. `/tmp/mnt/`.
   ```
   mkdir /tmp/mnt
   ```
1. Mount the device on this directory
   ```
   $ mount -t msdos /dev/disk2s2 /tmp/mnt
   ```
1. Now you can interact with the contents on the image using the `/tmp/mnt` directory.

#### Unmounting
1. Make sure all operations on the disk is done and the disk is not busy.
1. Unmount the disk
   ```
   $ umount /tmp/mnt
   ```
1. Detach the disk
   ```
   $ hdiutil detach /dev/disk2
   ```

## Build Instructions

### Windows
1. Install an emulator, QEMU, or VirtualBox, or both from the links below:
    - QEMU: https://www.qemu.org/
    - VirtualBox: https://www.virtualbox.org/
1. Install MinGW GCC from https://nuwen.net/mingw.html
1. Each tutorial has accompanying `compileEFI.bat` and `mountdrive.bat` files;
    1. Run `compileEFI.bat` to compile the `BOOTX64.EFI` binary.
    1. Once you have `BOOTX64.EFI` compiled, run `mountdrive.bat` to copy the binary to `drive.hdd`.
1. Now run your VirtualBox VM, or execute `run-qemu.bat` in the root directory of this repository and you'll see the
   tutorial running in the emulator.

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

**Note:** Your QEMU build most likely does not support SDL out of the box. If you run into any issues regarding SDL and
QEMU, ensure you're not passing the `-display sdl` argument to it.

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

**Note:** Your QEMU build most likely does not support SDL out of the box. If you run into any issues regarding SDL and
QEMU, ensure you're not passing the `-display sdl` argument to it.

[osfmount]: https://www.osforensics.com/tools/mount-disk-images.html
