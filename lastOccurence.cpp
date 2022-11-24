#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lastOccurence(int arr[] , int key, int siz) {
	
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
			if(mid == siz-1 || arr[mid + 1] != arr[mid]) {
			    return mid;
		   }
		   else {
		   	s = mid  + 1;
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
	
	cout<<"last occurence of key given is at = " <<lastOccurence(arr,key,n)<<" Index .";
	
	return 0;
}
