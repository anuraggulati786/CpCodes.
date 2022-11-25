////======= 15. Two sum problem
//			* Brute force approach, O(m*n)
//			* Two pointer approach if arrays are sorted, O(m+n)
//			* Hash map/set , O(nlogm +mlogn)


// we assumed here thet only one pair is exist inside the array and array is not sorted at alll

// if it is given that array is sorted then we can also use two pointer approach inside this :)


#include<iostream>
#include<bits/stdc++.h>
using namespace std;


vector<int> twoSum(vector<int>& nums, int target) {
        // naive solution 
        // time : O(n^2)...
        // space : O(1)...
        // vector<int> res;
        // for(int i=0; i<nums.size(); i++) {
        //     for(int j=i+1; j<nums.size(); j++) {
        //         if(nums[i] + nums[j] == target) {
        //             res.push_back(i);
        //             res.push_back(j);
        //             return res;
        //         }
        //     }
        // }
        // return res;
        
        
 
//        optamized solution using unordered_map...
//        time: O(n)...
//        space : O(n)...
        
        
        vector<int> res;
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++) {
            if(mp.find(target - nums[i]) != mp.end()) {
                res.push_back(mp[target - nums[i]]);
                res.push_back(i);
                return res;
            }
            mp[nums[i]] = i;
        }
        return res;    
		   
}

int main() {
	
	int n;
	cin>>n;
	
	vector<int> arr;
	for(int i=0; i<n; i++) {
		int t;
		cin>>t;
		arr.push_back(t);
	}
	
	int sum;
	cin>>sum;
	
	vector<int> res = twoSum(arr,sum);
	
	cout<<"[";
	for(auto it : res) {
		cout<<it<<" ";
	}
	cout<<"]";
	return 0;
	
}









