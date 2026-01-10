#include <chrono>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

// Configuration: 4 hours threshold (14400 seconds)
const int FETCH_THRESHOLD = 14400;

struct Duration {
  long long h, m, s;
};

Duration get_duration(long long total_seconds) {
  return {total_seconds / 3600, (total_seconds % 3600) / 60,
          total_seconds % 60};
}

void check_upstream() {
  // Redirect stderr to null to avoid seeing errors if no upstream is set
  int status = std::system(
      "git rev-list --count HEAD..@{u} > .git_behind_count 2>/dev/null");

  std::ifstream file(".git_behind_count");
  std::string count;
  if (file >> count && count != "0") {
    std::cout
        << "\033[1;33m[!] Pull available:\033[0m Your branch is behind by "
        << count << " commit(s).\n";
  }
  file.close();
  fs::remove(".git_behind_count");
}

int main() {
  if (!fs::exists(".git"))
    return 0;

  std::string timestamp_file = ".git/last_fetch_check";
  long long now =
      std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  long long last_time = now;

  if (fs::exists(timestamp_file)) {
    std::ifstream file(timestamp_file);
    file >> last_time;
    file.close();

    long long diff = now - last_time;
    Duration d = get_duration(diff);

    if (diff > FETCH_THRESHOLD) {
      std::cout << "\033[1;31m[!] It has been " << d.h << "h " << d.m << "m "
                << d.s << "s since your last git fetch.\033[0m\n";
      std::cout << "Run git fetch now? [y/n]: ";
      char response;
      std::cin >> response;
      if (response == 'y' || response == 'Y') {
        std::system("git fetch");
        // Update timestamp after successful fetch
        std::ofstream out(timestamp_file);
        out << std::chrono::system_clock::to_time_t(
            std::chrono::system_clock::now());
        out.close();
      }
    } else {
      std::cout << "\033[1;32m[i]\033[0m " << d.h << "h " << d.m << "m " << d.s
                << "s since your last git fetch.\n";
    }
  } else {
    // Initialize for new repo
    std::ofstream out(timestamp_file);
    out << now;
  }

  check_upstream();
  return 0;
}
