
#include <iostream>

using namespace std;

int main(){
    int T; cin >> T;

    while (T--) {
        long long sqSum = 0, sum = 0;
        int N; cin >> N;

        for (int j = 1; j <= N; j++)
            sum += j, sqSum += j*j;

        cout << abs(sum*sum - sqSum) << endl;
    }

    return 0;
}


/**
T = input()
square_sum = 0
sum = 0

for i in range(T):
	N = input()

	for j in range(1, N + 1):
		sum += j
		square_sum += j * j

	ans = abs(sum * sum - square_sum)
	print ans

	square_sum = 0
	sum = 0
*/
