#include <iostream>
using namespace std;



int main()
{

    int q;
    cin >> q;

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int N ; cin >> N;
        cout << primeCount(N) << endl;
    }

    return 0;
}
