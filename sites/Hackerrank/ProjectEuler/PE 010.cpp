
#include <iostream>
#include <vector>

using namespace std;

#define SIZE 1000000
vector<int> prime;
int sieve_arr[SIZE], nthPrime;

void sieve(){
    prime.push_back(2);
    for (long long i = 3; i <= SIZE; i += 2){
        if (!sieve_arr[i]){
            prime.push_back(i);
            if (i*i <= SIZE)
                for (long long j = i*i; j <= SIZE; j += i+i) sieve_arr[j] = 1;
        }
    }
}

int main(){
    sieve();

    int k; cin >> k;

    for (int i = 0; i < k; i++){
        long long sum = 0;
        int n; cin >> n;

        int j = 0;
        while (prime[j] <= n) sum += (long long) prime[j], j++;

        cout << sum << endl;
    }

    return 0;
}
