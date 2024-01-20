
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int T; cin >> T;
    int a_power[12], a[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

    for (int i = 0; i < T; i++){
        long long multiple = 1;
        for (int j = 0; j < 12; j++) a_power[j] = 0;
        int N; cin >> N;

        for (int j = 0; j < N; j++)
            for (int k = 1; k <= 5; k++)
                if (pow(a[j], k) <= N) a_power[j] = ceil(pow(a[j], k));

        for (int j = 0; j < 12; j++)
            if (a_power[j] > 0) multiple = multiple * a_power[j];

        cout << multiple;
    }

    return 0;
}
