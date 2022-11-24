#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int squareRoot(int key) {
	
	int s = 1;
	int e = key;
	int ans = -1;
	while(s <= e) {
		
		int mid = s + ((e-s) >> 1);
		
		int midSqr = mid * mid ;
		
		if(midSqr == key) {
			ans = mid;
			return ans;
		}
		else if(midSqr > key) {
			e = mid - 1;
		}
		else {
			ans = mid;
			s = mid + 1;
		}
	}
	return ans;
}


int main() {
	
//	int n;
//	cout<<"enter size: "<<endl;
//	cin>>n;
//	int arr[n];
//	cout<<"enter elements of aray :"<<endl;
//	for(int i=0; i<n; i++) {
//		cin>>arr[i];
//	}
//	
	int key ;
	cout<<":enter number  :"<<endl;
	cin>>key;
	
	cout<<"square root of the number is = " <<squareRoot(key);
	
	return 0;
}
