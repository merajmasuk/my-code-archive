#include <iostream>
using namespace std;

int main(){
    int T, N;
    cin >> T;

    for (int i = 0; i < T; i++){
        cin >> N;

        long long three, five, fifteen;
        three   = (N - 1) / 03;
        five    = (N - 1) / 05;
        fifteen = (N - 1) / 15;

        long long sum = 0;
        sum = sum + 03 * three   * (three   + 1) / 2;
        sum = sum + 05 * five    * (five    + 1) / 2;
        sum = sum - 15 * fifteen * (fifteen + 1) / 2;

        cout << sum << endl;
    }
}
