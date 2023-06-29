/* int solve(int ind, int n, vector<int> &price, vector<vector<int>> &dp) {
        if(ind == 0)
                return price[0] * n;

        if(dp[ind][n] != -1)
                return dp[ind][n];

        int notTake = solve(ind - 1, n, price, dp);
        int take = -1e9, rodlen = ind + 1;
        if(rodlen <= n)
                take = price[ind] + solve(ind, n - rodlen, price, dp);

        return dp[ind][n] = max(take, notTake);
}

int cutRod(vector<int> &price, int n)
{
        vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        return solve(n - 1, n, price, dp);
} */

/* int cutRod(vector<int> &price, int n) {
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
  for (int i = 0; i <= n; i++)
    dp[0][i] = price[0] * i;

	for(int i = 1; i < n; i++) {
		for(int j=0;j<=n;j++) {
			int notTake = dp[i - 1][j];
			int take = -1e9, rodlen = i + 1;
			if(rodlen <= j)
				take = price[i] + dp[i][j - rodlen];

			dp[i][j] = max(take, notTake);
		}
	}

	return dp[n - 1][n];
} */

int cutRod(vector<int> &price, int n) {
 vector<int> prev(n + 1), curr(n + 1);
  for (int i = 0; i <= n; i++)
    prev[i] = price[0] * i;

	for(int i = 1; i < n; i++) {
		for(int j=0;j<=n;j++) {
			int notTake = prev[j];
			int take = -1e9, rodlen = i + 1;
			if(rodlen <= j)
				take = price[i] + curr[j - rodlen];

			curr[j] = max(take, notTake);
		}
		prev = curr;
	}

	return prev[n];
}
