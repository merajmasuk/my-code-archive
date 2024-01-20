#include <iostream>
#include <string>

using namespace std;

int main(){
    int T; cin >> T;

    while (T-- > 0){
        int N, K; string series; cin >> N >> K >> series; int arr[N];
        for (int i = 0; i < N; i++) arr[i] = series[i]-'0';

        int ans = 0, product = 1;
        for (int i = 0; i < N-K; i++){
            for (int j = i; j < i + K; j++) product *= arr[j];
            if (product > ans) ans = product;
            product = 1;
        }

        cout << ans << endl;
    }

    return 0;
}
