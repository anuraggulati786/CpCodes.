#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int firstOccurence(int arr[] , int key, int siz) {
	
	int s = 0;
	int e = siz-1;
	
	while(s <= e) {
		
		int mid = s + ((e-s) >> 1);
		
		if(arr[mid] > key) {
			e = mid - 1;
		}
		else if(arr[mid] < key){
			s =  mid + 1;
		}
		else {
			if(mid == 0 || arr[mid - 1] != arr[mid]) {
			    return mid;
		   }
		   else {
		   	e = mid  - 1;
		   }
		}
	
	}

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
	
	cout<<"first occurence of key given is at = " <<firstOccurence(arr,key,n)<<" Index .";
	
	return 0;
}
