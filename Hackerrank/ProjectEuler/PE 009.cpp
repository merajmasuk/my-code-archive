
#include <iostream>

using namespace std;

int main(){
    int t; cin >> t;

    for (int i = 0; i < t; i++){
        int n; cin >> n;

        long long product = -1;
        for (int a = 1; a <= n/3; a++){
            int b = (n*n - 2*n*a) / (n+n-a-a);
            int c = n-a-b;

            if (c*c == (a*a + b*b)){
                long long temp = a*b*c;
                if (temp > product) product = temp;
            }
        }

        cout << product << endl;
    }

    return 0;
}
