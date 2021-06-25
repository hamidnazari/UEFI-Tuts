# UEFI Tutorials
## Manipulating the Disk Image
When we develop an EFI binary, we will need to have a way of feeding it to an emulator for it to boot from. One good way
of doing this is to create a disk image with appropriate partitioning and file systems, and configure the emulator to
use that image as the booting drive.

Additionally, we will need a way of moving our EFI builds into this image. This part of the document explains how this
step can be performed on various operating systems.

There's a disk image called `drive.hdd` located in `UEFI-Tuts/drive` directory. We will be using this image for these
tutorials.

**Note:** There's also a 256MB disk image ZIP file in `UEFI-Tuts/hold` directory which you may choose to utilise in case
any issues arise with the 40MB one.

To speed up the process of mounting, copying builds, unmounting the disk image, create `.bat` or `.sh` scripts to
perform the commands appropriate to your system. `mountdrive.bat` in the tutorials directories does exactly this on
Windows.

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
**Note:** There is no need to `sudo` for any of the commands below.
1. _Attach_ (not mount) the disk image located at `UEFI-Tuts/drive/drive.hdd`.
   ```
   $ hdiutil attach -imagekey diskimage-class=CRawDiskImage -nomount drive/drive.hdd
   /dev/disk2          	GUID_partition_scheme
   /dev/disk2s1        	Microsoft Basic Data
   ```
1. The command before will show you the device name that's been given to the image. In this case, it's `/dev/disk2`. You
   may get a different name. We are interested in the `Microsoft Basic Data` (or `EFI System`) partition, so in our
   example it would be `/dev/disk2s1`.
1. Create a directory that will be our mountpoint, e.g. `/tmp/uefi-tuts`.
   ```
   $ mkdir /tmp/uefi-tuts
   ```
1. Mount the device on this directory.
   ```
   $ mount -t msdos /dev/disk2s1 /tmp/uefi-tuts
   ```
1. Now you can interact with the contents on the image using the `/tmp/uefi-tuts` directory.

#### Unmounting
1. Make sure all operations on the disk is done and the disk is not busy.
1. Unmount the disk.
   ```
   $ umount /tmp/uefi-tuts
   ```
1. Detach the disk.
   ```
   $ hdiutil detach /dev/disk2
   ```

### Linux
#### Mounting
There are many ways of going about this, but I'm opting to stick to the widely available tools that most Linux distros
come with. Having said that, I've tested the steps below on Debian 10.10.
1. Create a loop device from the disk image located at `UEFI-Tuts/drive/drive.hdd`.
   ```
   $ sudo losetup -fP --show drive/drive.hdd 
   /dev/loop0
   ```
1. Inspect the loop device that was just created. Note that you may have gotten a different device name.
   ```
   $ sudo fdisk -l /dev/loop0
   Disk /dev/loop0: 40 MiB, 41943040 bytes, 81920 sectors
   Units: sectors of 1 * 512 = 512 bytes
   Sector size (logical/physical): 512 bytes / 512 bytes
   I/O size (minimum/optimal): 512 bytes / 512 bytes
   Disklabel type: gpt
   Disk identifier: 3F250645-B761-4631-8F45-D9930BF98FF5

   Device       Start   End Sectors Size Type
   /dev/loop0p1   128 77951   77824  38M Microsoft basic data
   ```
   We are interested in the `Microsoft Basic Data` (or `EFI System`) partition, in this case it's `/dev/loop0p1`.
1. Create a directory to serve as a mountpoint.
   ```
   $ sudo mkdir /mnt/uefi-tuts
   ```
1. Mount the loop device on it.
   ```
   $ sudo mount -t vfat /dev/loop0p1 /mnt/uefi-tuts
   ```
1. Now you can interact with the contents on the image using the `/mnt/uefi-tuts` directory.

#### Unmounting
1. Make sure all operations on the disk is done and the disk is not busy.
1. Unmount from the mountpoint.
   ```
   $ sudo umount /mnt/uefi-tuts
   ```
1. Detach the loop device.
   ```
   $ sudo losetup -d /dev/loop0
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
