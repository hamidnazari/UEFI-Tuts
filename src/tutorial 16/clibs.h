// UEFI From Scratch Tutorials - ThatOSDev ( 2021 )
// https://github.com/ThatOSDev/UEFI-Tuts

#ifndef CLIBS_H
#define CLIBS_H

#define NULL (void*)0

#define DECIMAL 10
#define HEX     16

void itoa(unsigned long int n, CHAR16 *buffer, int basenumber)
{
	unsigned long int hold;
	int i, j;
	hold = n;
	i = 0;
	
	do{
		hold = n % basenumber;
		buffer[i++] = (hold < 10) ? (hold + '0') : (hold + 'a' - 10);
	} while(n /= basenumber);
	buffer[i--] = 0;
	
	for(j = 0; j < i; j++, i--)
	{
		hold = buffer[j];
		buffer[j] = buffer[i];
		buffer[i] = hold;
	}
}

typedef unsigned long long     size_t;
typedef unsigned char          uint8_t;

void* memcpy(void* dst, const void* src, size_t size)
{
    for ( size_t i = 0; i < size; i++ )
        ((uint8_t*) dst)[i] = ((const uint8_t*) src)[i];
    return dst;
}

#endif // CLIBS_H