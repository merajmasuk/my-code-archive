
#include <iostream>

using namespace std;

long long C[1001][1001];

void nCr(){
    int n = 500;

    for (int j = 1; j <= n; j++){
        for (int k = 0; k <= j; k++){
            if (k == 0 || k == j) C[j][k] = 1;

            else{
                if (k == 1 || k == j-1) C[j][k] = j;
                else C[j][k] = (C[j-1][k] + C[j-1][k-1]) % 1000000007;
            }
        }
    }
}

int main() {
    nCr();
    int T; cin >> T;

    while (T--) {
        int N, M; cin >> N >> M;
        cout << C[N+M][N] << endl;
    }

    return 0;
}

/**
from math import factorial

T = int(input())
for _ in range(T):
    N, M = input().split()
    N = int(N)
    M = int(M)
    print((factorial(N + M) // (factorial(N) * factorial(M))) % 1000000007)
*/
