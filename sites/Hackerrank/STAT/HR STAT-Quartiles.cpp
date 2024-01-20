
#include <iostream>
#include <algorithm>

using namespace std;

int main () {
    int n; cin >> n; int x[n];
    for (int i = 0; i < n; i++) cin >> x[i];
    sort(x, x+n);

    //for (int i = 0; i < n; i++) cout << x[i] << ' '; cout << endl;

    int q1 = n/4,
        q2 = n/2, q3 = (q2+n)/2;

    int Q1 = x[q1],
        Q2 = x[q2],
        Q3 = x[q3];

         if (n%4 == 0 || n%4 == 1) Q1 = (Q1+x[q1-1])/2;

         if (n%2 == 0)             Q2 = (Q2+x[q2-1])/2;

         if (n%4 == 1)             Q3 = (Q3+x[q3+1])/2;
    else if (n%4 == 0)             Q3 = (Q3+x[q3-1])/2;

    cout << Q1 << endl;
    cout << Q2 << endl;
    cout << Q3 << endl;

    return 0;
}
