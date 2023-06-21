#include <iostream>
using namespace std;

long long primeFactors(long long n){
    long long i, j;

    while (n % 2 == 0) n = n/2;
    if (n == 1) return 2;

    for (i = 3; i*i <= n; i += 2)
        if (n % i == 0) n = n/i, i = 1;

    if (n > 2) return   n;
    else       return i-2;
}

int main(){
    int t; cin >> t;

    while(t-- > 0){
        long long n; cin >> n;
        cout << primeFactors(n) << endl;
    }

    return 0;
}
