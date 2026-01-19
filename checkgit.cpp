#include <chrono>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

const int FETCH_THRESHOLD = 14400; // 4 hours

struct Duration {
  long long h, m, s;
};

Duration get_duration(long long total_seconds) {
  return {total_seconds / 3600, (total_seconds % 3600) / 60,
          total_seconds % 60};
}

void check_upstream() {
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

  // Use Git's internal fetch tracker instead of a custom file
  std::string git_fetch_head = ".git/FETCH_HEAD";

  long long now =
      std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  long long last_time;

  if (fs::exists(git_fetch_head)) {
    // Get the last modification time of the actual git fetch record
    auto ftime = fs::last_write_time(git_fetch_head);
    auto sctp =
        std::chrono::time_point_cast<std::chrono::system_clock::duration>(
            ftime - fs::file_time_type::clock::now() +
            std::chrono::system_clock::now());
    last_time = std::chrono::system_clock::to_time_t(sctp);
  } else {
    // Fallback if no fetch has ever been performed
    last_time = now;
  }

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
      // No need to manually update a file anymore!
      // Git updates .git/FETCH_HEAD for us.
    }
  } else {
    std::cout << "\033[1;32m[i]\033[0m " << d.h << "h " << d.m << "m " << d.s
              << "s since your last git fetch.\n";
  }

  check_upstream();
  return 0;
}
