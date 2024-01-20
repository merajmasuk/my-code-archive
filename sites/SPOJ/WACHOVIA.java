import java.util.*;

class WACHOVIA {

	static int max(int a, int b) {
		return (a > b) ? a : b;
	}

	static int knapsack(int cap, int weights[], int values[], int n, int[][] dp) {
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

	static int knapsackMem(int cap, int weights[], int values[], int n) {
		int dp[][] = new int[n+1][cap+1];

		for (int i = 0; i < n+1; i++) {
			for (int j = 0; j < cap+1; j++) {
				dp[i][j] = -1;
			}
		}

		return knapsack(cap, weights, values, n, dp);
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int N = scan.nextInt();

		for (int C = 1; C <= N; C++) {
			int K = scan.nextInt(), M = scan.nextInt();
			int[] A = new int[M], B = new int[M];

			for (int i = 0; i < M; i++) {
				A[i] = scan.nextInt();
				B[i] = scan.nextInt();
			}

			int P = knapsackMem(K, A, B, M);
			System.out.println("Hey stupid robber, you can get " + P + ".");
		}
	}
}
