#include<stdio.h>

#define PRINT(ARR,N) for(int i=0;i<N;i++) printf("%d ",ARR[i]); printf("\n");
#define uint unsigned int
#define MAX 0xffffffff
void findCoeff(uint *arr, uint *coeff, uint K);
int countBits(int x);
int main(){
    int n=4;
    //scanf("%d",&n);

    uint K=1<<n;
    printf("COEFF are represented as x1x2x3x4\n");
    //uint arr[] = {0,1,1,1 ,1,1,0,0, 0,0,0,0, 0,0,0,0};
    uint arr[] = {1,0,1,1, 1,0,1,0, 0,1,0,0, 1,0,1,1};
    
    uint coeff[K];
    for(uint i=0;i<K;i++) coeff[i] = 0;
    findCoeff(arr,coeff, K);
    PRINT(coeff,K);
    return 0;
}
void findCoeff(uint *arr, uint *coeff, uint K){
    coeff[0] = arr[0];
    uint tmp;
    uint cnt;
    for(uint i=1;i<K;i++){
        printf("%04b ",i);
        cnt=arr[0];
        for(uint j=1;j<=i;j++){          //rather than finding subsets, use this condition
            if((j|i)<=i){
                cnt^=arr[j];
                //printf("%d ",j);
            }
        }
        printf("\n");
        
        coeff[i] = cnt;
    }
}
/*
uint arr[] = {1,0,1,1, 1,0,1,0, 0,1,0,0, 1,0,1,1};
x1x2x3x4    f(x)
0000        1
0001        0 
0010        1
0011        1
0100        1
0101        0
0110        1
0111        0
1000        0
1001        1
1010        0
1011        0
1100        1
1101        0
1110        1
1111        1

this truth table's ANF represntation is
f (x1 , x2 , x3 , x4 ) = 1 + x1 + x4 + (x1 x2) + (x3 x4) + (x2 x3 x4) + (x1 x2 x3 x4) .
which correspond to the index
1               -> 0
x1              -> 8
x4              -> 1
x1 x2           -> 12
x3 x4           -> 3
x2 x3 x4        -> 7
x1 x2 x3 x4     -> 15

and these are indices which are 1 in the output.
Output:
0 1 2 3 4 5 6 7 8 9 a b c d e f ==> indices
1 1 0 1 0 0 0 1 1 0 0 0 1 0 0 1 ==> coeff present in ANF
*/
