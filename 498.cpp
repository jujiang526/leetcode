#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
vector<int> findDiagonalOrder(const vector<vector<int>>& matrix) {
  vector<int> results;
  int m = matrix.size();
  if (m == 0) {
    return results;
  }
  int n = matrix[0].size();
  int i = 0, j = 0;
  bool up = true;
  int total = m*n;
  while (true) {
    results.push_back(matrix[i][j]);
    //cout << i << ", " << j << endl;

    if (results.size() == total ) {
      break;
    }
    if (up) {
      --i;
      ++j;
    } else {
      ++i;
      --j;
    }
    
    if (i < 0 || i == m || j < 0 || j == n) {
      up = !up;
    }
    if (i < 0 && j == n) {
      i = 1;
      j = n - 1;
    } else if (i == m && j < 0) {
      i = m - 1;
      j = 1;
    } else {
      i = max(i, 0);
      if (i == m) {
        i = m - 1;
        j = j + 2;
      }

      j = max(j, 0);
      if (j == n) {
        j = n - 1;
        i = i + 2;
      }
    }
  }

  return results;
}

int main(int argc, char const* argv[]) {
  for (auto i : findDiagonalOrder({{1}, {2}})) {
    cout << i << endl;
  }
  return 0;
}