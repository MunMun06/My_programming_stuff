#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

struct Pos {
  int r, c;
};

// Convert vector of Pos into a canonical string (sorted by row,col)
string to_string_sorted(const vector<Pos> &ps, int N) {
  vector<pair<int, int>> arr;
  for (auto &p : ps)
    arr.emplace_back(p.r, p.c);
  sort(arr.begin(), arr.end());
  string s;
  for (auto &q : arr) {
    s += "(" + std::to_string(q.first) + "," + std::to_string(q.second) + ")";
  }
  return s;
}

// Apply transformation type t (0..7 for D8 group) to a point
Pos apply_symmetry(const Pos &p, int N, int t) {
  int r = p.r, c = p.c;
  int r2, c2;
  switch (t) {
  case 0:
    r2 = r;
    c2 = c;
    break; // identity
  case 1:
    r2 = c;
    c2 = (N - 1 - r);
    break; // rot90
  case 2:
    r2 = (N - 1 - r);
    c2 = (N - 1 - c);
    break; // rot180
  case 3:
    r2 = (N - 1 - c);
    c2 = r;
    break; // rot270
  case 4:
    r2 = r;
    c2 = (N - 1 - c);
    break; // reflect vertical
  case 5:
    r2 = c;
    c2 = r;
    break; // reflect main diag
  case 6:
    r2 = (N - 1 - r);
    c2 = c;
    break; // reflect horiz
  case 7:
    r2 = (N - 1 - c);
    c2 = (N - 1 - r);
    break; // reflect anti diag
  default:
    r2 = r;
    c2 = c;
    break;
  }
  return {(r2 % N + N) % N, (c2 % N + N) % N};
}

// Given a solution (row->col), return its canonical toroidal string
string canonical_toroidal(const vector<int> &pos) {
  int N = (int)pos.size();
  vector<Pos> original;
  for (int r = 0; r < N; r++)
    original.push_back({r, pos[r]});

  string best;
  bool first = true;

  for (int t = 0; t < 8; t++) { // all dihedral symmetries
    vector<Pos> trans;
    for (auto &p : original)
      trans.push_back(apply_symmetry(p, N, t));

    // Now apply all toroidal translations
    for (int dr = 0; dr < N; dr++) {
      for (int dc = 0; dc < N; dc++) {
        vector<Pos> shifted;
        for (auto &p : trans) {
          shifted.push_back({(p.r + dr) % N, (p.c + dc) % N});
        }
        string s = to_string_sorted(shifted, N);
        if (first || s < best) {
          best = s;
          first = false;
        }
      }
    }
  }
  return best;
}

// Pretty-print
void print_board(const vector<int> &pos) {
  int N = pos.size();
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      cout << (pos[r] == c ? 'Q' : '.');
    }
    cout << "\n";
  }
}

// N-Queens backtracking
int main(int argc, char **argv) {
  if (argc < 2) {
    cerr << "Usage: " << argv[0] << " N\n";
    return 1;
  }
  int N = stoi(argv[1]);
  ull all = (1ULL << N) - 1ULL;

  vector<int> pos(N, -1);
  unordered_set<string> seen;
  int unique_count = 0;

  function<void(int, ull, ull, ull)> dfs = [&](int row, ull cols, ull d1,
                                               ull d2) {
    if (row == N) {
      string canon = canonical_toroidal(pos);
      if (seen.insert(canon).second) {
        ++unique_count;
        cout << "Solution #" << unique_count << ":\n";
        print_board(pos);
        cout << "\n";
      }
      return;
    }
    ull avail = ~(cols | d1 | d2) & all;
    while (avail) {
      ull bit = avail & -avail;
      avail -= bit;
      int c = __builtin_ctzll(bit);
      pos[row] = c;
      dfs(row + 1, cols | bit, (d1 | bit) << 1, (d2 | bit) >> 1);
      pos[row] = -1;
    }
  };

  dfs(0, 0, 0, 0);
  cout << "Unique (toroidal) solutions: " << unique_count << "\n";
}
