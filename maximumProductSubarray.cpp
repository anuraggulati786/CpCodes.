//======= 26. Maximum product of a subarray

#include<iostream>
#include<vector>
using namespace std;


long long maxProduct(vector<int> arr, int n) {
        
        long long mx = 1 , mn = 1;
        long long ans = INT_MIN;
        
        for(int i=0 ; i<n ;i++){
            if(arr[i]<0)
                swap(mx , mn);
            
            long long num = (long long)arr[i];
            
            mx = max(num , mx*num);
            mn = min(num , mn*num);
            
            ans= max(ans , mx);
            
        }
        
        return ans;
        
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
	
	cout<<maxProduct(arr,n);
	
	return 0;
	
}
