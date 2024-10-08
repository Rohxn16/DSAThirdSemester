#include <stdio.h>

int main(){

    // Create 2 double dimensional arrays, matrices
    int a[2][2] = {{1,2},{3,4}};
    int b[2][2] = {{1,2},{3,4}};

    // multiply matrices
    int c[2][2] = {{0,0},{0,0}};
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}