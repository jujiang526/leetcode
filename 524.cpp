#include <algorithm>
#include <iostream>
#include <string>	
#include <unordered_map>
#include <unordered_set>	
#include <vector>

using namespace std;
string findLongestWord(const string& s, vector<string> d) {
	sort(d.begin(), d.end(), [](const string& lhs, const string& rhs){
		int s1 = lhs.size();
		int s2 = rhs.size();
		if(s1 == s2){
			return lhs < rhs;
		} else {
			return s1 > s2;
		}
	});

	for(auto&& l: d){
		int i=0, j=0;
		while(i<s.size() && j<l.size()){
			if(s[i] == l[j]){
				++j;
			}
			++i;
		}
		if(j == l.size()){
			return l;
		}
	}

	return "";
}

int main(int argc, char const *argv[])
{
	cout << findLongestWord("abpcplea", {"ale","apple","monkey","plea"}) << endl;
	return 0;
}