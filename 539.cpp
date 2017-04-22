#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
int getDifference(const string& s1, const string& s2){
	int h1 = stoi(s1.substr(0, 2)), h2 = stoi(s2.substr(0, 2));
	int m1 = stoi(s1.substr(3)), m2 = stoi(s2.substr(3));
	int forward = (h2-h1)*60+(m2-m1);
	int backward = (h1+24-h2)*60+(m1-m2);
	return min(forward, backward);
}

int findMinDifference(vector<string> timePoints) {
  int size = timePoints.size();
  //assert(size>1);
  sort(timePoints.begin(), timePoints.end());
  int diff = getDifference(timePoints[0], timePoints[size-1]);
  for(int i=1, size = timePoints.size(); i<size; ++i){
  	diff = min(diff, getDifference(timePoints[i-1], timePoints[i]));
  }

  return diff;
}

int main(int argc, char const* argv[]) {
  cout << findMinDifference({"23:59", "00:00"}) << endl;
  return 0;
}