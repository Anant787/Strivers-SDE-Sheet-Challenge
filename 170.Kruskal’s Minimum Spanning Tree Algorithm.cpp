#include <bits/stdc++.h>

/* DISJOINT UNION BY RANK */
class Disjoint {
private:
  vector<int> parent, rank;

public:
  Disjoint(int n) {
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++)
      parent[i] = i;
    rank.resize(n + 1, 0);
  }

  int findParent(int node) {
    if (node == parent[node])
      return node;
    return parent[node] = findParent(parent[node]);
  }

  void unionByRank(int u, int v) {
    int pu = findParent(u);
    int pv = findParent(v);

    if (rank[pu] > rank[v])
      parent[pv] = pu;
    else if (rank[pv] > rank[pu])
      parent[pu] = pv;
    else {
      parent[pv] = pu;
      rank[pu]++;
    }
  }
};

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
  sort(graph.begin(), graph.end(),
       [](vector<int> &a, vector<int> &b) { return a[2] < b[2]; });
  Disjoint d(n);

  int sum = 0;
  for (auto i : graph) {
    int wt = i[2], u = i[0], v = i[1];
        if(d.findParent(u) != d.findParent(v)) {
                sum += wt;
                d.unionByRank(u, v);
        }
  }

  return sum;
}

/* DISJOINT UNION BY SIZE */
// class Disjoint {
// private:
//   vector<int> parent, size;

// public:
//   Disjoint(int n) {
//     parent.resize(n + 1);
//     for (int i = 1; i <= n; i++)
//       parent[i] = i;
//     size.resize(n + 1, 1);
//   }

//   int findParent(int node) {
//     if (node == parent[node])
//       return node;
//     return parent[node] = findParent(parent[node]);
//   }

//   void unionBySize(int u, int v) {
//     int pu = findParent(u);
//     int pv = findParent(v);

//     if (size[pu] > size[v]) {
//       parent[pv] = pu;
//       size[pu] += size[pv];
//     } else {
//       parent[pu] = pv;
//       size[pv] += size[pu];
//     }
//   }
// };

// int kruskalMST(int n, int m, vector<vector<int>> &graph) {
//   sort(graph.begin(), graph.end(),
//        [](vector<int> &a, vector<int> &b) { return a[2] < b[2]; });
//   Disjoint d(n);

//   int sum = 0;
//   for (auto i : graph) {
//     int wt = i[2], u = i[0], v = i[1];
//     if (d.findParent(u) != d.findParent(v)) {
//       sum += wt;
//       d.unionBySize(u, v);
//     }
//   }

//   return sum;
// }
