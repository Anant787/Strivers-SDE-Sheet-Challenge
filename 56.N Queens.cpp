void solve(int col, int n, vector<vector<int>> &res, vector<vector<int>> &mat,
           vector<int> &leftRow, vector<int> &lowerDiagonal,
           vector<int> &upperDiagonal) {
  if (col == n) {
    vector<int> ans;
    for (auto i : mat)
      for (auto j : i)
        ans.push_back(j);

    res.push_back(ans);
    return;
  }

  for (int i = 0; i < n; i++) {
    if (leftRow[i] == 0 and lowerDiagonal[i + col] == 0 and
        upperDiagonal[(n - 1) + (col - i)] == 0) {
      leftRow[i] = 1;
      lowerDiagonal[i + col] = 1;
      upperDiagonal[(n - 1) + (col - i)] = 1;
      mat[i][col] = 1;

      solve(col + 1, n, res, mat, leftRow, lowerDiagonal, upperDiagonal);

      leftRow[i] = 0;
      lowerDiagonal[i + col] = 0;
      upperDiagonal[(n - 1) + (col - i)] = 0;
      mat[i][col] = 0;
    }
  }
}

vector<vector<int>> solveNQueens(int n) {
  vector<vector<int>> res;
  vector<vector<int>> mat(n, vector<int>(n));

  vector<int> leftRow(n), lowerDiagonal(2 * n - 1), upperDiagonal(2 * n - 1);

  solve(0, n, res, mat, leftRow, lowerDiagonal, upperDiagonal);
  return res;
}
