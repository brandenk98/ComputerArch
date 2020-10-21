#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

    FILE *tfile;
    tfile = fopen(argv[1], "r");
    if(tfile == NULL) {
        printf("error\n");
        return 0;
    }
    int row1 = 0;
    int col1 = 0;
    int row2 = 0;
    int col2 = 0;
    int ** matrix1;
    int ** matrix2;
    fscanf(tfile, "%d\t%d\n", &row1, &col1);
    matrix1 = malloc( row1 * sizeof(int *));
    for(int i = 0; i < row1; i++) {
        matrix1[i] = malloc(col1 * sizeof(int));
    }
    for(int i = 0; i < row1; i++) {
        for(int j = 0; j < col1; j++) {
            fscanf(tfile, "%d\t", &matrix1[i][j]);
        }
    }
    fscanf(tfile, "%d\t%d\n", &row2, &col2);
    matrix2 = malloc( row2 * sizeof(int *));
    for(int i = 0; i < row2; i++) {
        matrix2[i] = malloc(col2* sizeof(int));
    }
    for(int i = 0; i < row2; i++) {
        for(int j = 0; j < col2; j++) {
            fscanf(tfile, "%d\t", &matrix2[i][j]);
        }
    }
    if( col1 == row2 ) {
        int sum = 0;
        for(int i = 0; i < row1; i++) {
            for(int j = 0; j < col2; j++) {
                for(int k = 0; k < col1; k++) {
                    sum += matrix1[i][k] * matrix2[k][j];
                }
                printf("%d\t", sum);
                sum = 0;
            }
            printf("\n");
        }
    }
    else {
        printf("bad-matrices");
    }
    for(int i = 0; i < row1; i++) {
        free(matrix1[i]);
    }
    free(matrix1);
    for(int i = 0; i < row2; i++) {
        free(matrix2[i]);
    }
    free(matrix2);
    fclose(tfile);
    return 0;
}
