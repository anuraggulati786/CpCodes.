#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int searchInsortedAndRotatedArray(int arr[] , int key, int n) {
	
	int s = 0;
	int e = n-1;
	
	while(s <= e) {
		
		int mid = s + ((e-s) >> 1);
		
		if(arr[mid] == key) {
			return mid;
		}
		else if(arr[mid] > arr[s]) {
			if(key >= arr[s] and key < arr[mid]) {
				e = mid - 1;
			}
			else {
				s = mid + 1;
			}
		}
		else {
			if(key <= arr[e] and key > arr[mid]) {
				s = mid + 1;
			}
			else {
				e = mid - 1;
			}
		}
	
	}
	return -1;
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
	
	int key ;
	cout<<":entyer key to search :"<<endl;
	cin>>key;
	
	cout<<"the given key is at = " <<searchInsortedAndRotatedArray(arr,key,n)<<" Index .";
	
	return 0;
}
