#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

    char* numPtr;
    int numberCount = 0;
    int sameCount = 0;
    unsigned short count = (unsigned short) strtoul(argv[1], &numPtr, 10);

    int foo;
    int ret = 0;

    while(count > 0) {
        foo = count;
        ret = 0;
        int currentBit = (foo >> 0) & 1;
        if(currentBit == 1) {
            numberCount++;
            foo = count;
            currentBit = (foo >> 1) & 1;
            if(currentBit == 1) {
			numberCount++;
            sameCount++;
            ret  = 1;
            }
        }
        if(ret != 1)
            count = (count >> 1);
        else
            count = (count >> 2);
    }
    if(numberCount % 2 != 0)
		printf("Odd-Parity\t%d\n", sameCount);
    else
        printf("Even-Parity\t%d\n", sameCount);
    return 0;
}
