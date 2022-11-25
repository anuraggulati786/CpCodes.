//======= 27. Maximum sum of a subarray

// 			kadanes algorithm [ maximum subarray sum ].... 
//			time : O(n)  ,,  space : O(1)..


#include<bits/stdc++.h>
using namespace std;

int maximumSubarraySum(vector<int>& arr, int n){
	int maxSum = 0;
	int currSum = 0;
	
	for(int i=0; i<n; i++) {
		
		currSum = currSum + arr[i];
		maxSum = max(maxSum,currSum);
		if(currSum < 0) {
			currSum = 0;
		}
	}
	return maxSum;
}

signed main() {
	int n;
	cin>>n;
	
	vector<int> arr;
	for(int i=0; i<n; i++) {
		int t;
		cin>>t;
		arr.push_back(t);
	}
	
	cout<<maximumSubarraySum(arr,n);
	
	return 0;
}
