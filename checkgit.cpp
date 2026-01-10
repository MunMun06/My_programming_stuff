#include <chrono>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

// Configuration: 4 hours threshold (14400 seconds)
const int FETCH_THRESHOLD = 14400;

bool is_git_repo() { return fs::exists(".git"); }

void check_upstream() {
  // Check if local branch is behind upstream
  int status = std::system(
      "git rev-list --count HEAD..@{u} > .git_behind_count 2>/dev/null");

  std::ifstream file(".git_behind_count");
  std::string count;
  if (file >> count && count != "0") {
    std::cout
        << "\033[1;33m[!] Pull available:\033[0m Your branch is behind by "
        << count << " commit(s).\n";
  }
  fs::remove(".git_behind_count");
}

void check_last_fetch() {
  std::string timestamp_file = ".git/last_fetch_check";
  long long now =
      std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

  if (fs::exists(timestamp_file)) {
    std::ifstream file(timestamp_file);
    long long last_time;
    file >> last_time;

    if (now - last_time > FETCH_THRESHOLD) {
      std::cout << "\033[1;36m[i] Reminder:\033[0m It has been a while since "
                   "your last fetch. Run 'git fetch'!\n";
      // Update timestamp
      std::ofstream out(timestamp_file);
      out << now;
    }
  } else {
    // First time running in this repo
    std::ofstream out(timestamp_file);
    out << now;
  }
}

int main() {
  if (!is_git_repo())
    return 0;

  check_last_fetch();
  check_upstream();

  return 0;
}
