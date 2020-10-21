#include <stdio.h>
#include <string.h>

unsigned short comp(unsigned short temp, int tbit) {

    unsigned short comp_temp = temp;
    comp_temp ^= 1 << tbit;
    return comp_temp;
}
unsigned short set(unsigned short temp, int tbit, int diffValue) {

    unsigned short move_temp = temp;
    move_temp = move_temp & (~(1 << tbit));
    move_temp |= diffValue << tbit;
    return move_temp;
}
unsigned short get(unsigned short temp, int n) {
    unsigned short currentBit;
    currentBit = (temp >> n) & 1;
    return currentBit;
}
int main(int argc, char* argv[]) {

    FILE *tfile;
    tfile = fopen(argv[1], "r");
    if(tfile == NULL) {
        printf("error\n");
        return 0;
    }
    
    
    int num1;
    int num2;
    char gianna[5];
    unsigned short bkush;
    fscanf(tfile, "%hu\n", &bkush);

    while(fscanf(tfile, "%s\t%d\t%d", gianna, &num1, &num2) == 3) {
        if(strcmp(gianna, "comp\0") == 0) {
            bkush = comp(bkush, num1);
            printf("%hu\n", bkush);
        }
         else if(strcmp(gianna, "set\0") == 0) {
            bkush = set(bkush, num1, num2);
            printf("%hu\n", bkush);
		}
         else if(strcmp(gianna, "get\0") == 0) {
            printf("%hu\n", get(bkush, num1));
		}
        else {
            return 0;
        }
    }
    return 0;
}
