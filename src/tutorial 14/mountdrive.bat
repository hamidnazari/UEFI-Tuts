OSFMount -a -t file -f ..\..\drive\drive.hdd -s 40M -o rw -m F:

move /y BOOTX64.EFI "F:\EFI\Boot\"

move /y myfile.bin "F:\"

timeout 3

OSFMount -D -m F:

pause

