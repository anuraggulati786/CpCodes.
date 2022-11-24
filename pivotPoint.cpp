#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int pivotElement(int arr[] , int n) {
	
	int s = 0;
	int e = n-1;
	
	if(n == 0) {
		return -1;
	}
	
	if(arr[s] > arr[e]) {
		return e;
	}
	if(arr[s] < arr[e]) {
		return s;
	}
		
	while(s <= e) {
		
		int mid = s + ((e-s) >> 1);
		
		if (mid < n-1 && arr[mid] > arr[mid+1]) {
                return (mid + 1);
        }
		else if(arr[mid] >= arr[s]) {
			s = mid + 1;
		}
		else {
			e = mid - 1;
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
	
	cout<<"the pivot element is at = " <<pivotElement(arr , n)<<" Index .";
	
	return 0;
}
