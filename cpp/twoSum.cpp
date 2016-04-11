#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution{
public:
	vector<int> twoSum(vector<int>& arr, int target){
		unordered_map<int, int> mapping;
		vector<int> ret;

		for(int i=0; i<arr.size(); i++)
			mapping[arr[i]] = i;

		for(int i=i; i<arr.size(); i++){
			const int gap = target - arr[i];
			if(mapping.find(gap) != mapping.end()){
				ret.push_back(i+1);
				ret.push_back(mapping[gap]+1);
				break;
			}
		}

		return ret;

	}
};


int main(){

	//c++ 11
	vector<int> arr_vec = {2,7,11,15};
	Solution s;

	int target = 9;
	vector<int> idxs = s.twoSum(arr_vec, target);
	for (int i=0; i<idxs.size(); i++){
		cout << idxs[i] << endl;
	}

}