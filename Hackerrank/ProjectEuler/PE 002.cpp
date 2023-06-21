#include <iostream>

using namespace std;

int main(){
    int T; cin >> T;

    long long t1 = 1, t2 = 2, tn;
    long long sum = t2;

    for (int i = 0; i < T; i++){
        long long N; cin >> N;

        if (N == 1) tn = 1;
        else{
            for (int j = 0; j < N-2; j++){
                tn = t1+t2, t1 = t2, t2 = tn;

                if (tn   >= N) break;
                if (tn%2 == 0) sum += tn;
            }
        }

        cout << sum << endl;
        t1 = 1, t2 = 2, sum = t2;
    }

    return 0;
}
