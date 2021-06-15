OSFMount -a -t file -f ..\..\drive\drive.hdd -s 40M -o rw -m F:

timeout 1

move /y BOOTX64.EFI "F:\EFI\Boot\"

timeout 1

OSFMount -d -m F:

pause

