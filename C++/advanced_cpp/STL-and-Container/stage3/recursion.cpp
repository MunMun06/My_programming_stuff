#include <iostream>
#include <vector>

int sumArray(int arr[], int n) {
  if (n == 0)
    return 0;                               // base case
  return arr[n - 1] + sumArray(arr, n - 1); // recursive step
}

void reverseArray(int arr[], int start, int end) {
  if (start >= end)
    return; // base case
  std::swap(arr[start], arr[end]);
  reverseArray(arr, start + 1, end - 1); // recursive step
}

int power(int x, int n) {
  if (n == 0)
    return 1;                 // base case
  return x * power(x, n - 1); // recursive step
}

int sumDigits(int n) {
  if (n == 0)
    return 0; // base case
  return n % 10 + sumDigits(n / 10);
}

int factorial(int x) {
  if (x <= 1)
    return 1;
  return x * factorial(x - 1);
}

int fibonacci(int n) {
  if (n == 0)
    return 0; // base case
  if (n == 1)
    return 1; // base case
  return fibonacci(n - 1) + fibonacci(n - 2);
}

void towerOfHanoi(int n, char from, char to, char aux) {
  if (n == 1) {
    std::cout << "Move disk 1 from " << from << " to " << to << '\n';
    return;
  }
  towerOfHanoi(n - 1, from, aux, to); // move n-1 disks to auxiliary
  std::cout << "Move disk " << n << " from " << from << " to " << to << '\n';
  towerOfHanoi(n - 1, aux, to, from); // move n-1 disks to destination
}

// base case
// choice
// constraint
// backtrack

void generateSubsets(std::vector<int> &nums, int index,
                     std::vector<int> &current) {
  if (index == nums.size()) {
    // print the current subset
    // current also work as output
    std::cout << "{ ";
    for (int x : current)
      std::cout << x << " ";
    std::cout << "}\n";
    return;
  }

  // Exclude nums[index] because no push_back
  generateSubsets(nums, index + 1, current);

  // Include nums[index]
  current.push_back(nums[index]);
  generateSubsets(nums, index + 1, current);

  // Backtrack (undo the choice) works because we always exclude before include
  current.pop_back();
}

void generatePermutations(std::vector<int> &nums, int start) {
  if (start == nums.size()) {
    for (int x : nums)
      std::cout << x << " ";
    std::cout << "\n";
    return;
  }

  for (int i = start; i < nums.size(); i++) {
    std::swap(nums[start], nums[i]); // choose. place num[i] at index
    generatePermutations(nums,
                         start + 1); // explore. recurse for the next index
    std::swap(nums[start], nums[i]); // backtrack. undo the swap
  }
}

void generateCombinations(std::vector<int> &nums, int k, int start,
                          std::vector<int> &current) {
  if (current.size() == k) {
    for (int x : current)
      std::cout << x << " ";
    std::cout << "\n";
    return; // print when size = k
  }

  for (int i = start; i < nums.size(); i++) {
    current.push_back(nums[i]); // choose nums[i] as first element
    generateCombinations(nums, k, i + 1, current); // recurse with next index
    current.pop_back(); // pop the last element to backtrack
  }
}

bool isSafe(const std::vector<std::string> &board, int row, int col, int n) {
  // Check column
  for (int i = 0; i < row; i++) {
    if (board[i][col] == 'Q')
      return false;
  }

  // Check upper-left diagonal
  for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j] == 'Q')
      return false;
  }

  // Check upper-right diagonal
  for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
    if (board[i][j] == 'Q')
      return false;
  }

  return true;
}

void solve(int row, int n, std::vector<std::string> &board,
           std::vector<std::vector<std::string>> &solutions) {
  if (row == n) {
    solutions.push_back(board); // Found a solution
    return;
  }

  for (int col = 0; col < n; col++) {
    if (isSafe(board, row, col, n)) {
      board[row][col] = 'Q'; // Place queen
      solve(row + 1, n, board, solutions);
      board[row][col] = '.'; // Backtrack
    }
  }
}

std::vector<std::vector<std::string>> solveNQueens(int n) {
  std::vector<std::vector<std::string>> solutions;
  std::vector<std::string> board(n, std::string(n, '.')); // empty board
  solve(0, n, board, solutions);
  return solutions;
}

void solveMaze(int x, int y, std::vector<std::vector<int>> &maze, int n,
               std::vector<std::vector<int>> &visited, std::string path,
               std::vector<std::string> &paths) {
  // If destination reached
  if (x == n - 1 && y == n - 1) {
    paths.push_back(path);
    return;
  }

  // use DFS with backtracking

  // Direction arrays: D, L, R, U
  int dx[] = {1, 0, 0, -1};
  int dy[] = {0, -1, 1, 0};
  char dir[] = {'D', 'L', 'R', 'U'};

  for (int k = 0; k < 4; k++) {
    int newX = x + dx[k]; // generate a move
    int newY = y + dy[k];

    // Check valid move
    if (newX >= 0 && newX < n && newY >= 0 && newY < n &&
        maze[newX][newY] == 1 &&
        visited[newX][newY] == 0) { // 1 = clear, 0 = blocked

      visited[x][y] = 1; // mark visited
      solveMaze(
          newX, newY, maze, n, visited, path + dir[k],
          paths); // explore
                  // path + dir[k] concat the char to the string and create a
                  // new copy (not using the original in the recursion)
      visited[x][y] = 0; // backtrack
    }
  }
}

std::vector<std::string> findPaths(std::vector<std::vector<int>> &maze, int n) {
  std::vector<std::string> paths;
  std::vector<std::vector<int>> visited(n, std::vector<int>(n, 0));
  // visited matrix size n*n and populate every cell with 0

  if (maze[0][0] == 1) {
    solveMaze(0, 0, maze, n, visited, "", paths);
  }

  return paths;
}

bool dfs(std::vector<std::vector<char>> &board, std::string &word, int index,
         int i, int j) {
  if (index == (int)word.size())
    return true; // finished matching the word
  if (i < 0 || j < 0 || i >= (int)board.size() || j >= (int)board[0].size())
    return false; // out of bounds
  if (board[i][j] != word[index])
    return false; // mismatch
  if (board[i][j] == '#')
    return false; // already visited

  char temp = board[i][j]; // save original
  board[i][j] = '#';       // mark visited

  // explore 4 directions
  bool found = dfs(board, word, index + 1, i + 1, j) ||
               dfs(board, word, index + 1, i - 1, j) ||
               dfs(board, word, index + 1, i, j + 1) ||
               dfs(board, word, index + 1, i, j - 1);

  board[i][j] = temp; // backtrack (restore)
  return found;
}

bool exist(std::vector<std::vector<char>> &board, std::string word) {
  int m = board.size();
  int n = board[0].size();

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (dfs(board, word, 0, i, j)) {
        return true;
      }
    }
  }
  return false;
}

bool isSafe(std::vector<std::vector<char>> &board, int row, int col, char c) {
  for (int i = 0; i < 9; i++) {
    // check row
    if (board[row][i] == c)
      return false;
    // check column
    if (board[i][col] == c)
      return false;
    // check 3x3 box
    int boxRow = 3 * (row / 3) + i / 3;
    int boxCol = 3 * (col / 3) + i % 3;
    if (board[boxRow][boxCol] == c)
      return false;
  }
  return true;
}

bool solve(std::vector<std::vector<char>> &board) {
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      if (board[row][col] == '.') { // empty cell
        for (char c = '1'; c <= '9'; c++) {
          if (isSafe(board, row, col, c)) {
            board[row][col] = c; // choose c
            if (solve(board))    // recurse
              return true;
            board[row][col] = '.'; // backtrack
          }
        }
        return false; // no valid number
      }
    }
  }
  return true; // board completely filled
}

void printBoard(std::vector<std::vector<char>> &board) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      std::cout << board[i][j] << " ";
    }
    std::cout << "\n";
  }
}

int main() {

  int n = 3;                      // number of disks
  towerOfHanoi(n, 'A', 'C', 'B'); // A=source, C=destination, B=auxiliary

  std::vector<int> nums = {1, 2, 3};
  std::vector<int> current;
  generateSubsets(nums, 0, current);

  std::vector<int> nums2 = {1, 2, 3};
  generatePermutations(nums2, 0);

  std::vector<int> nums3 = {1, 2, 3, 4};
  std::vector<int> current2;
  int k = 2;
  generateCombinations(nums3, k, 0, current);

  int n2 = 4; // Example: 4-Queens
  auto solutions = solveNQueens(n2);

  for (const auto &board : solutions) {
    for (const auto &row : board) {
      std::cout << row << "\n";
    }
    std::cout << "----\n";
  }

  std::vector<std::vector<int>> maze = {
      {1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};

  int n3 = maze.size();
  std::vector<std::string> paths = findPaths(maze, n3);

  if (paths.empty()) {
    std::cout << "No path found" << std::endl;
  } else {
    for (const auto &p : paths) {
      std::cout << p << std::endl;
    }
  }

  std::vector<std::vector<char>> board = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  std::string word = "ABCCED";

  if (exist(board, word)) {
    std::cout << "Found\n";
  } else {
    std::cout << "Not Found\n";
  }

  std::vector<std::vector<char>> board2 = {
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  if (solve(board2)) {
    std::cout << "Solved Sudoku:\n";
    printBoard(board2);
  } else {
    std::cout << "No solution exists\n";
  }
  return 0;
}
