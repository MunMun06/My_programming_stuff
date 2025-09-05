#include <cctype>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

// hash map
// when iterating
// name.first for value of key
// name.second for value of value
// name[key] for accessing the value using key
// name[key]++ increment the value at key

void countFrequency(const std::string &s) {
  std::unordered_map<char, int> freq;

  for (char c : s) {
    freq[c]++;
  }

  // pair is of type std::pair<const char, int>
  // auto and auto& give different order
  // unordered map order come from internal hashing not insertion order or key
  // order. if you want order use std::map
  for (auto pair : freq) {
    std::cout << pair.first << ": " << pair.second << "\n";
  }
}

bool isAnagram(const std::string &s1, const std::string &s2) {
  if (s1.length() != s2.length())
    return false;

  std::unordered_map<char, int> count;

  for (char c : s1) {
    count[c]++;
  }

  for (char c : s2) {
    count[c]--;
    if (count[c] < 0)
      return false;
    // if,for and while can have no braces if it contains one statement.
  }

  return true;
}

bool isAnagramIgnoreCase(const std::string &s1, const std::string &s2) {
  if (s1.length() != s2.length())
    return false;

  std::unordered_map<char, int> count;

  for (char c : s1) {
    count[std::tolower(c)]++;
  }

  for (char c : s2) {
    count[std::tolower(c)]--;
    if (count[std::tolower(c)] < 0)
      return false;
  }

  return true;
}

bool isAnagramIgnoreCaseAndSpaces(const std::string &s1,
                                  const std::string &s2) {
  std::unordered_map<char, int> count;

  for (char c : s1) {
    if (c != ' ')
      count[std::tolower(c)]++;
  }

  for (char c : s2) {
    if (c != ' ') {
      count[std::tolower(c)]--;
      if (count[std::tolower(c)] < 0)
        return false;
    }
  }

  // Optional: check all counts are 0 (in case s2 missed any)
  for (const auto &pair : count) {
    if (pair.second != 0)
      return false;
  }

  return true;
}

int lengthOfLongestSubstring(const std::string &s) {
  std::unordered_map<char, int> seen;
  int left = 0, maxLen = 0;

  for (int right = 0; right < s.length(); ++right) {
    char c = s[right];

    // If we've seen the character and it's inside the current window
    if (seen.count(c) && seen[c] >= left) {
      left = seen[c] + 1; // move the left end of the window
    }

    seen[c] = right; // update the latest index of character
    maxLen = std::max(maxLen, right - left + 1);
  }

  return maxLen;
}

// hast set
// insert(x) add x to the set
// count(x) check if x is in the set (1 if yes, 0 if no)
// erase(x) remove x if it exist in the set

int longestConsecutive(int arr[], int n) {
  std::unordered_set<int> numSet;

  // Add all elements to the set
  for (int i = 0; i < n; i++) {
    numSet.insert(arr[i]);
  }

  int maxLen = 0;

  for (int i = 0; i < n; i++) {
    int num = arr[i];

    // Check if it's the start of a sequence
    if (numSet.count(num - 1) == 0) {
      int current = num;
      int length = 1;

      while (numSet.count(current + 1)) {
        current++;
        length++;
      }

      maxLen = std::max(maxLen, length);
    }
  }

  return maxLen;
}

int getNext(int n) {
  int sum = 0;
  while (n > 0) {
    int digit = n % 10;
    sum += digit * digit;
    n /= 10;
  }
  return sum;
}

bool isHappy(int n) {
  std::unordered_set<int> seen;

  while (n != 1 && !seen.count(n)) {
    seen.insert(n);
    n = getNext(n);
  }

  return n == 1;
}

int main() {

  std::string str = "banana";
  countFrequency(str);

  std::string a = "Listen";
  std::string b = "Silent";

  std::cout << a << " and " << b << " are ";

  if (isAnagramIgnoreCase(a, b)) {
    std::cout << "anagrams!\n";
  } else {
    std::cout << "not anagrams.\n";
  }

  std::cout << "(Conversation) and (Voices rant on) are ";

  if (isAnagramIgnoreCaseAndSpaces("Conversation", "Voices rant on")) {
    std::cout << "anagrams!\n";
  } else {
    std::cout << "not anagrams.\n";
  }

  std::string s = "abcabcbb";
  std::cout << "Length of longest substring of " << s << " : "
            << lengthOfLongestSubstring(s) << '\n';

  return 0;
}
