#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"repair_scheme_tbl.h"

unsigned char *binGap(int t, int m){

    int q; 
    int i, log; 
    static unsigned char bin[8];


    for (i = 0; i < (t); i++){
        bin[i] = 0;
    }
    while ( m > 1){
        log = log2(m);
        bin[t-log-1] = 1;
        m = m - pow(2, log);
    }
    
    if( m == 1){
        bin[t-1] = 1;
    }
    return bin;

}

int main(){
    int i, j, z;
    unsigned char *p1;
    unsigned char htbl[9][9][9];


    for (i = 0; i < 9; i++){
        printf("{");
        for (j = 0; j < 9; j++){
            printf("{ ");
            for (z = 0; z < 9; z++){
                //printf("%u, ", h_htbl[i][j][z]);
                p1 = binGap(8, h_htbl[i][j][z]);
                for(int l = 0; l < 8; l++){
                    htbl[i][j][z] = p1[l];
                    printf("%u,", p1[l]);
                }
                printf(" ");
                 
            }
            printf("}, \n");
        }
        printf(" },\n");
    }
    printf("\n");

    
    return 0;

}

