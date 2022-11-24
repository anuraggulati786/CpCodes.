#include<bits/stdc++.h>
using namespace std;

bool searchElement(int arr[], int n, int key) {
		int s = 0;
		int e = n-1;
		
		while(s <= e) {
			int  mid =  s + ((e-s) >> 1);
			
			if(arr[mid] == key) {
				return true;
			}
			else if(arr[mid] > key) {
				e = mid - 1;
			}
			else {
				s = mid + 1;
			}
		}
		return false;
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
	
	if(searchElement(arr,n,key) == true) {
		cout<<"key is present !"<<endl;
	}
	else {
		cout<<"key is not present !"<<endl;
	}
	
	return 0;
}
