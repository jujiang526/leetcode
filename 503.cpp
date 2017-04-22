#include <algorithm>
#include <iostream>
#include <string>	
#include <unordered_map>
#include <unordered_set>	
#include <vector>
#include <stack>

using namespace std;
vector<int> nextGreaterElements(const vector<int>& nums) {
	int size = nums.size();
	vector<int> results(size, -1);
	stack<int> s;

	for(int i=2*size-1; i>=0; --i){
		int index = (i>=size ? i-size : i);
		while(!s.empty() && s.top()<= nums[index]){
			s.pop();
		}
		if(!s.empty()){
			results[index] = s.top();
		} 
		s.emplace(nums[index]);
		
	}

	return results;
}

int main(int argc, char const *argv[])
{
	for(auto i: nextGreaterElements({3,4,3,2,2,1})){
		cout << i << endl;
	}
	return 0;
}