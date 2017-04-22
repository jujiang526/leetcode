#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int findMaxLength(const vector<int>& nums) {
  int diff = 0;
  int max_length = 0;
  unordered_map<int, int> differences;
  for (int i = 0, size = nums.size(); i < size; ++i) {
    if (nums[i] == 1) {
      ++diff;
    } else {
      --diff;
    }
    if (diff == 0) {
      max_length = i + 1;
    } else {
      auto it = differences.find(diff);
      if (it != differences.end()) {
        max_length = max(max_length, i - it->second);
      }
    }

    if (differences.find(diff) == differences.end()) {
      differences.emplace(diff, i);
    }
  }
  
  return max_length;
}
int main(int argc, char const* argv[]) {
  cout << findMaxLength({0, 0, 1, 0, 0, 0, 1, 1}) << endl;
  return 0;
}