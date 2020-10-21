#include <stdio.h>
#include <stdlib.h>

unsigned short get(unsigned short temp, int n) {
    unsigned short currentBit;
    currentBit = (temp >> n) & 1;
    return currentBit;
}
int main(int argc, char* argv[]) {
    char* numPtr;
    unsigned short count = (unsigned short) strtoul(argv[1], &numPtr, 10);
    
    for(int k = 0; k <= 15; k++) {
        if(get(count, k) != get(count, 15 - k)) {
            printf("Not-Palindrome\n");
            return 0;
        }
    }
    printf("Is-Palindrome\n");
    return 0;
}
