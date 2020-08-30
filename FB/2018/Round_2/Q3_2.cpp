#pragma comment(linker, "/STACK:512000000")
#include <bits/stdc++.h>
#include <sys/resource.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(__attribute__((unused)) bool);
void precalc();
clock_t start;
#define FILENAME ""

int main() {
#ifdef AIM
    string s = FILENAME;
//    assert(!s.empty());
    freopen("/home/alexandero/ClionProjects/cryptozoology/input.txt", "r", stdin);
  freopen("/home/alexandero/ClionProjects/cryptozoology/output.txt", "w", stdout);
#else
//    freopen(FILENAME ".in", "r", stdin);
//    freopen(FILENAME ".out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;
#ifndef AIM
    cout.sync_with_stdio(0);
    cin.tie(0);
#endif

  const rlim_t kStackSize = 256 * 1024 * 1024;
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
    if (rl.rlim_cur < kStackSize)
    {
      rl.rlim_cur = kStackSize;
      result = setrlimit(RLIMIT_STACK, &rl);
      if (result != 0)
      {
        fprintf(stderr, "setrlimit returned result = %d\n", result);
      }
    }
  }


  precalc();
    cout.precision(10);
    cout << fixed;
    cin >> t;
    int testNum = 1;
    while (t--) {
        cout << "Case #" << testNum++ << ": ";
        solve(true);
    }
    cout.flush();
#ifdef AIM1
    while (true) {
      solve(false);
  }
#endif

#ifdef AIM
    cout.flush();
    auto end = clock();

    usleep(10000);
    print_stats(end - start);
    usleep(10000);
#endif

    return 0;
}

template<typename T>
T binpow(T q, T w, T mod) {
    if (!w)
        return 1 % mod;
    if (w & 1)
        return q * 1LL * binpow(q, w - 1, mod) % mod;
    return binpow(q * 1LL * q % mod, w / 2, mod);
}

template<typename T>
T gcd(T q, T w) {
    while (w) {
        q %= w;
        swap(q, w);
    }
    return q;
}
template<typename T>
T lcm(T q, T w) {
    return q / gcd(q, w) * w;
}

template <typename T>
void make_unique(vector<T>& a) {
    sort(all(a));
    a.erase(unique(all(a)), a.end());
}

template<typename T>
void relax_min(T& cur, T val) {
    cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
    cur = max(cur, val);
}

void precalc() {
}

//#define int li

const int mod = 1000000007;
const int C = 53;
int dp[2][C][C][C][C];

void add(int& cur, int val) {
  cur += val;
  if (cur >= mod) {
    cur -= mod;
  }
}

void solve(__attribute__((unused)) bool read) {
  int n, S, E;
  cin >> n >> S >> E;
  vector<int> ys = {S, E};
  vector<pair<int, int>> points(n);
  ys.push_back(-1);
  ys.push_back((int)1e9 + 5);
  for (int i = 0; i < n; ++i) {
    cin >> points[i].first >> points[i].second;
    ys.push_back(points[i].second);
  }
  sort(all(points));
  sort(all(ys));
  auto get_index = [&] (int val) {
    return (int)(lower_bound(all(ys), val) - ys.begin());
  };
  S = get_index(S);
  E = get_index(E);
  for (auto& pt : points) {
    pt.second = get_index(pt.second);
  }
  int par = 0;
  memset(dp, 0, sizeof dp);
  dp[par][S][S][0][(int)ys.size() - 1] = 1;
  for (auto& pt : points) {
    memset(dp[par ^ 1], 0, sizeof dp[par ^ 1]);
    for (int a = 0; a <= S; ++a) {
      for (int b = S; b < ys.size(); ++b) {
        for (int c = 0; c <= E; ++c) {
          for (int d = E; d < ys.size(); ++d) {
            int cur_dp = dp[par][a][b][c][d];
            if (cur_dp == 0) {
              continue;
            }
            int y = pt.second;
            if (y < a || y > b) {
              add(dp[par ^ 1][a][b][c][d], cur_dp);
            }
            if (y > c) {
              add(dp[par ^ 1][min(a, y)][b][c][d], cur_dp);
            }
            if (y < d) {
              add(dp[par ^ 1][a][max(b, y)][c][d], cur_dp);
            }
            if (y > E) {
              add(dp[par ^ 1][a][b][c][min(y, d)], cur_dp);
            } else {
              add(dp[par ^ 1][a][b][max(c, y)][d], cur_dp);
            }
          }
        }
      }
    }
    par ^= 1;
  }

  li res = binpow(4LL, (li)n, (li)mod);
  for (int a = 0; a <= S; ++a) {
    for (int b = S; b < ys.size(); ++b) {
      for (int c = 0; c <= E; ++c) {
        for (int d = E; d < ys.size(); ++d) {
          int cur_dp = dp[par][a][b][c][d];
          res -= cur_dp;
          if (res < 0) {
            res += mod;
          }
        }
      }
    }
  }
  res %= mod;
  cout << res << "\n";
}