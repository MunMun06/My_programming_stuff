#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

// Convert a positions vector (row -> col) into a string representation
// for lexicographic comparison: "c0,c1,c2,..."
string pos_to_string(const vector<int> &pos) {
  string s;
  for (size_t i = 0; i < pos.size(); ++i) {
    if (i)
      s.push_back(',');
    s += to_string(pos[i]);
  }
  return s;
}

// Given original pos (row -> col), produce transformed pos for the 8
// symmetries. t in [0..7]: 0 = identity 1 = rotate 90 2 = rotate 180 3 = rotate
// 270 4 = reflect (mirror vertical) 5 = reflect then rotate 90 6 = reflect then
// rotate 180 7 = reflect then rotate 270
vector<int> transform_pos(const vector<int> &pos, int t) {
  int N = (int)pos.size();
  vector<int> out(N, -1);
  for (int r = 0; r < N; ++r) {
    int c = pos[r];
    int r2, c2;
    // apply base transform depending on t
    switch (t) {
    case 0: // identity
      r2 = r;
      c2 = c;
      break;
    case 1: // rot90: (r,c) -> (c, N-1-r)
      r2 = c;
      c2 = N - 1 - r;
      break;
    case 2: // rot180
      r2 = N - 1 - r;
      c2 = N - 1 - c;
      break;
    case 3: // rot270
      r2 = N - 1 - c;
      c2 = r;
      break;
    case 4: // reflect vertical: (r,c) -> (r, N-1-c)
      r2 = r;
      c2 = N - 1 - c;
      break;
    case 5: // reflect then rot90
      // reflect: (r,c) -> (r, N-1-c) then rot90: (r',c') -> (c', N-1-r')
      {
        int rr = r;
        int cc = N - 1 - c;
        r2 = cc;
        c2 = N - 1 - rr;
      }
      break;
    case 6: // reflect then rot180
    {
      int rr = r;
      int cc = N - 1 - c;
      r2 = N - 1 - rr;
      c2 = N - 1 - cc;
    } break;
    case 7: // reflect then rot270
    {
      int rr = r;
      int cc = N - 1 - c;
      r2 = N - 1 - cc;
      c2 = rr;
    } break;
    default:
      r2 = r;
      c2 = c;
      break;
    }
    out[r2] = c2;
  }
  return out;
}

// Return the canonical (minimal lexicographic) string representation among the
// 8 transforms
string canonical_string(const vector<int> &pos) {
  string best;
  bool first = true;
  for (int t = 0; t < 8; ++t) {
    vector<int> tr = transform_pos(pos, t);
    string s = pos_to_string(tr);
    if (first || s < best) {
      best = s;
      first = false;
    }
  }
  return best;
}

// Pretty-print a solution (pos is row -> col, zero-indexed)
void print_solution_board(const vector<int> &pos) {
  int N = (int)pos.size();
  for (int r = 0; r < N; ++r) {
    for (int c = 0; c < N; ++c) {
      cout << (pos[r] == c ? 'Q' : '.');
    }
    cout << '\n';
  }
}

// Print also a compact list of columns (1-based)
void print_solution_compact(const vector<int> &pos) {
  cout << "cols: [";
  for (size_t i = 0; i < pos.size(); ++i) {
    if (i)
      cout << ", ";
    cout << (pos[i] + 1);
  }
  cout << "]\n";
}

int main(int argc, char **argv) {
  if (argc < 2) {
    cerr << "Usage: " << argv[0] << " N\n";
    return 1;
  }
  int N = stoi(argv[1]);
  if (N <= 0) {
    cerr << "N must be positive\n";
    return 1;
  }
  if (N > 60) {
    cerr << "N too large for this implementation (use N <= 60)\n";
    return 1;
  }

  ull all = (N == 64) ? ~0ULL : ((1ULL << N) - 1ULL);

  vector<int> pos(N, -1);
  unordered_set<string> seen; // store canonical strings we've already printed
  long long unique_count = 0;

  // backtracking with bitmask (row by row)
  function<void(int, ull, ull, ull)> dfs = [&](int row, ull cols, ull d1,
                                               ull d2) {
    if (row == N) {
      // found a solution stored in pos
      string canon = canonical_string(pos);
      if (seen.find(canon) == seen.end()) {
        seen.insert(canon);
        ++unique_count;
        // print the canonical form (we'll print the canonical transform so
        // output is normalized) find which transform equals the canonical
        // string and print that transform
        vector<int> to_print;
        for (int t = 0; t < 8; ++t) {
          vector<int> tr = transform_pos(pos, t);
          if (pos_to_string(tr) == canon) {
            to_print = std::move(tr);
            break;
          }
        }
        cout << "Solution #" << unique_count << " (canonical):\n";
        print_solution_board(to_print);
        print_solution_compact(to_print);
        cout << '\n';
      }
      return;
    }
    ull avail = ~(cols | d1 | d2) & all;
    while (avail) {
      ull bit = avail & -avail;
      avail -= bit;
      int c = __builtin_ctzll(bit); // column index
      pos[row] = c;
      dfs(row + 1, cols | bit, (d1 | bit) << 1, (d2 | bit) >> 1);
      pos[row] = -1;
    }
  };

  dfs(0, 0ULL, 0ULL, 0ULL);

  cout << "Done. Unique solutions up to rotation/reflection: " << unique_count
       << "\n";
  return 0;
}
