#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  deque<string> dq;
  while (cin >> s) {
    dq.push_back(s);
  }
  int ans = 0;
  int n = dq.size(), m = dq[0].size();
  string temp = dq[0];
  dq.pop_front();

  while (!dq.empty()) {
    for (int i = 0; i < m; i++) {
      string &a = dq.front();
      if (temp[i] == 'S') {
        a[i] = '|';
      }
      if (temp[i] == '|') {
        if (a[i] == '.')
          a[i] = '|';
        else if (a[i] == '^') {
          ans++;
          if (i - 1 >= 0)
            a[i - 1] = '|';
          if (i + 1 < m)
            a[i + 1] = '|';
        }
      }
    }
    temp = dq.front();
    dq.pop_front();
  }
  cout << ans << endl;
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
