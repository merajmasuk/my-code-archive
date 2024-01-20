#include<stdio.h>
#include<stdlib.h>

int main(){
    int T; scanf("%d", &T);

    while (T--){
        long long int L = 1, H; scanf("%lld", &H);
        //if (L == 0 || H == 0) return 0;

        long long int S = 0, swapped = 0, V;
        if (L > H){
            long long int temp = L; L = H; H = temp;
            swapped = 1;
        }

        long long int i;
        for (i = H; i >= L; i--){
            long long int N = i, cycle_length = 1;

            if (N % 2) N = 3*N+1; else N /= 2;

            while (N != 1){
                if (N % 2) N = 3*N+1; else N /= 2;
                cycle_length++;
            }

            if (cycle_length >= S){
                S = cycle_length; V = i;
            }
        }

        printf("%lld\n", V);
        //printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n", L, H, V, S);
    }

    return 0;
}
