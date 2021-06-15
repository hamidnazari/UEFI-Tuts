OSFMount -a -t file -f ..\..\drive\drive.hdd -s 40M -o rw -m F:

timeout 2

move /y BOOTX64.EFI "F:\EFI\Boot\"

timeout 2

OSFMount -d -m F:

pause

