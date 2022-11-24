#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void spiralPattern(vector<vector<int>>& arr, int r, int c) {
	 
	// 1)-> print first row...
	// 2)-> print last column
	// 3)-> print last row in reverse order
	// 4)-> print first column in reverse order
	
	int left = 0, right = c-1; // for columns
	int top = 0, bottom = r-1; // for rows
	
	while(top <= bottom and left<= right) {
		
		//1)->
		for(int i=left; i<=right; i++) {
			cout<<arr[top][i]<<" "; 
		}
		top++;
		
		//2)->
		for(int i = top; i <= bottom; i++) {
			cout<<arr[i][right]<<" ";
		}
		right--;
		
		//3)->
		if(top <= bottom) { // check the boundary is crossed or not 
			for(int i = right; i >= left; i--) {
				cout<<arr[bottom][i]<<" ";
			}
			bottom--;
		}
		
		//4)->
		if(left <= right) {
			for(int i=bottom; i>=top; i--) {
				cout<<arr[i][left]<<" ";
			}
			left++;
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
	
	cout<<"spiral pattern is :"<<endl;
	
	spiralPattern(arr, r, c);

	return 0;
}
