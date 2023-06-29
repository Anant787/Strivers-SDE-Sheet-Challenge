#include <bits/stdc++.h>

/* bool solve(int ind, vector<string> &arr, int n, string &target,
           vector<int> &dp) {
  if (ind == n)
    return true;

  if (dp[ind] != -1)
    return dp[ind];

  for (auto word : arr)
    if (target.substr(ind, word.size()) == word and
        solve(ind + word.size(), arr, n, target, dp))
      return dp[ind] = true;

  return dp[ind] = false;
}

bool wordBreak(vector<string> &arr, int n, string &target) {
  vector<int> dp(target.size() + 1, -1);
  return solve(0, arr, target.size(), target, dp);
} */

bool wordBreak(vector<string> &arr, int n, string &target) {
  n = target.size();
  vector<int> dp(n + 1, 0);

  dp[n] = 1;
  for (int i = n - 1; i >= 0; i--) {
    for (auto word : arr) {
      if (i + word.size() <= n and target.substr(i, word.size()) == word and
          dp[i + word.size()])
        dp[i] = true;
    }
  }

  return dp[0];
}
