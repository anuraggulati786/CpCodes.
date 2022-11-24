#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void snakePattern(vector<vector<int>>& arr, int r, int c) {
	 
	for(int row = 0; row < r; row++) {
		if(row % 2 == 0) {
			for(int col = 0; col < c; col++) {
				cout<<arr[row][col]<<" ";
			}
		}
		else {
			for(int col = c-1; col>=0; col--) {
				cout<<arr[row][col]<<" ";
			}
		}
	}
	
}


int main() {
	
	int r;
	cout<<"enter rows: "<<endl;
	cin>>r;
	
	int c;
	cout<<"enter cols: "<<endl;
	cin>>c;
	
	vector<vector<int>> arr;
	cout<<"enter elements of matrix: "<<endl;
	
	for(int i=0; i<r; i++) {
		vector<int> temp;
		for(int j=0; j<c; j++) {
			int t;
			cin>>t;
			temp.push_back(t);
		}
		arr.push_back(temp);
	}
	
	cout<<"Given matrix is looks like : "<<endl;
	
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<"snake patter is :"<<endl;
	
	snakePattern(arr, r, c);

	return 0;
}
