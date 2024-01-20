#include <iostream>

using namespace std;

int max(int a, int b) {
		return (a > b) ? a : b;
	}

int knapsack(int cap, int weights[], int values[], int n, int** dp) {
		if (n == 0 || cap == 0) {
			return 0;
		}

		if (dp[n][cap] != -1) {
			return dp[n][cap];
		}

		if (weights[n-1] > cap) {
			return dp[n][cap] = knapsack(cap, weights, values, n-1, dp);
		}

		return dp[n][cap] = max(
			values[n-1] + knapsack(cap - weights[n-1], weights, values, n-1, dp),
			knapsack(cap, weights, values, n-1, dp)
		);
	}

int knapsackMem(int cap, int weights[], int values[], int n) {
		int** dp = new int*[n+1];

		for (int i = 0; i < n+1; i++) {
			dp[i] = new int[cap+1];
			for (int j = 0; j < cap+1; j++) {
				dp[i][j] = -1;
			}
		}

		return knapsack(cap, weights, values, n, dp);
	}

int main() {
	int N; cin >> N;

		for (int C = 1; C <= N; C++) {
			int K, M; cin >> K >> M;
			int A[M], B[M];

			for (int i = 0; i < M; i++) {
				cin >> A[i] >> B[i];
			}

			int P = knapsackMem(K, A, B, M);
			cout << "Hey stupid robber, you can get " << P << "." << endl;
		}
	}

