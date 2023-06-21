#include<stdio.h>

long long int C[1001][1001], K, count, N, i, j;

int main(){

    int flag = 0;
    scanf("%lld %lld", &N, &K);

    //first for-loop is for ncr
    for (i = 1; i <= N; i++){
        for (j = 0; j <= i; j++){
            if (j == 0 || j == i) C[i][j] = 1;

            else{
                if (j == 1 || j == i-1) C[i][j] = i;
                else C[i][j] = C[i-1][j] + C[i-1][j-1];
            }
        }
    }

    //second for-loop for checking
    for (i = 1; i <= N; i ++){
        flag = 0;

        for (j = 0; j <= i; j++){
            if (C[i][j] > K){
                flag = 1;
                break;
            }
        }

        if (flag == 1)
            count += (i - j-j + 1);
    }

    printf("%lld", count);

    return 0;
}
