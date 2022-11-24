#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void rotateArray(int arr[], int s, int e) {
	
	while(s <= e) {
		swap(arr[s],arr[e]);
		s++;
		e--;
	}
	
}



void rightRotation(int arr[] , int n, int k) {
	
	
	// 1-> rotate 0 to k-1
	rotateArray(arr,0,k-1);
	// 2-> rotate k to n-1
	rotateArray(arr,k,n-1);
	// 3-> rotate 0 to n-1
	rotateArray(arr,0,n-1);

}


int main() {
	
	int n;
	cout<<"enter size: "<<endl;
	cin>>n;
	int arr[n];
	cout<<"enter elements of aray :"<<endl;
	for(int i=0; i<n; i++) {
		cin>>arr[i];
	}
	
	vector<int> arr2(arr,arr+n);
	
	int k;
	cout<<"enter how many times you wants to rotate the array :" <<endl;
	cin>>k;
	
	rightRotation(arr , n ,k);
	
	cout<<"After right rotation array will look like : "<<endl;
	for(auto it : arr) {
		cout<<it<<" ";
	}
	
	return 0;
}
