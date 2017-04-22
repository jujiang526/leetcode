#include <algorithm>
#include <iostream>
#include <string>	
#include <unordered_map>
#include <unordered_set>	
#include <vector>

using namespace std;

class UnionFind{
private:
	vector<int> parents_;
	vector<int> sizes_;
	int n_;
	int count_;

public:
	UnionFind(int n):
		n_(n), count_(n), parents_(n), sizes_(n, 1){
		for(int i=0; i<n; i++){
			parents_[i] = i;
		}
	}

	void connect(int i, int j){
		
		if(i<0 || i>=n_ || j<0 || j>= n_ ){
			return;
		}
		int p = find(i);
		int q = find(j);
		//cout << i << ", " << j << endl;
		if(p == q){
			return;
		}

		if(sizes_[p]<sizes_[q]){
			parents_[p] = q;
			sizes_[q] += sizes_[p];
		} else {
			parents_[q] = p;
			sizes_[p] += sizes_[q];
		}

		--count_;
	}

	int find(int i){
		if(i<0 || i>=n_){
			return -1;
		} else {
			while(i != parents_[i]){
				i = parents_[i];
			}
			return i;
		}
	}

	int count() const {
		return count_;
	}
};

int findCircleNum(const vector<vector<int>>& M) {
	int n = M.size();
	if(n == 0){
		return 0;
	}

	UnionFind uf{n};
	for(int i=0; i<n; ++i){
		for(int j=i+1; j<n; ++j){
			if(M[i][j] == 1){
				uf.connect(i, j);
			}
		}
	}

	return uf.count();
}

int main(int argc, char const *argv[])
{
	cout << findCircleNum({{1,1,0},{1,1,1},{0,1,1}}) << endl;
	return 0;
}