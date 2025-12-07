#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(e) e.begin(), e.end()
int n, m, ans = 0;
deque<string> dq;
vector<vector<int>> ways;
void solve() {
  string s;
  while (cin >> s) {
    dq.push_back(s);
  }
  n = dq.size(), m = dq.front().size();
  int start = 0;
  ways.assign(n, vector<int>(m));
  for (int i = 0; i < m; i++) {
    if (dq.front()[i] == 'S') {
      start = i;
      ways[0][i] = 1;
      dq.front()[i] = '|';
      break;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m; j++) {
      if (dq[i + 1][j] == '^') {
        if (j - 1 >= 0)
          ways[i + 1][j - 1] += ways[i][j];
        if (j + 1 < m)
          ways[i + 1][j + 1] += ways[i][j];
      } else
        ways[i + 1][j] += ways[i][j];
    }
  }
  cout << accumulate(ways[n - 1].begin(), ways[n - 1].end(), 0LL) << endl;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

#ifdef QUEUE_T_PIE
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  freopen("./error.txt", "w", stderr);
#endif

  int tt = 1;
  while (tt--)
    solve();
}
