// Recursion + Memoization
int solve(int ind, vector<int> &values, vector<int> &weights, int w, vector<vector<int>> &dp) {
	if(ind == 0)
		return weights[0] <= w ? values[0] : 0;
	
	if(dp[ind][w] != -1)
		return dp[ind][w];
	
	int notTake = solve(ind - 1, values, weights, w, dp);

	int take = -1e9;
	if(weights[ind] <= w)
		take = values[ind] + solve(ind - 1, values, weights, w - weights[ind], dp);
	
	return dp[ind][w] = max(take, notTake);
}

// int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
// {
// 	vector<vector<int>> dp(n, vector<int> (w + 1, -1));
// 	return solve(n - 1, values, weights, w, dp);
// }

// Tabulation
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> dp(n, vector<int> (w + 1, 0));

	for(int i = weights[0]; i <= w; i++)
		dp[0][i] = values[0];

	for(int i = 1; i < n; i++) {
		for(int j = 0; j <= w; j++) {
			int notTake = dp[i - 1][j];
			int take = -1e9;
			if(weights[i] <= j)
				take = values[i] + dp[i - 1][j - weights[i]];

			dp[i][j] = max(take, notTake);
		}
	}

	return dp[n - 1][w];
}

// // Sapce Optimization
// int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
// {
// 	vector<int> prev (w + 1, 0), curr(w + 1, 0);

// 	for(int i = weights[0]; i <= w; i++)
// 		prev[i] = values[0];

// 	for(int i = 1; i < n; i++) {
// 		for(int j = 0; j <= w; j++) {
// 			int notTake = prev[j];
// 			int take = -1e9;
// 			if(weights[i] <= j)
// 				take = values[i] + prev[j - weights[i]];

// 			curr[j] = max(take, notTake);
// 		}
// 		prev = curr;
// 	}

// 	return prev[w];
// }
