// euclid algo...
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int euclidAlgo(int a, int b) {
	
	// base case 
	if(b == 0) {
		return a;
	}
	
	return euclidAlgo(b,a%b);
	
}

int main() {
	
	int a;
	cin>>a;
	
	int b;
	cin>>b;
	
//	cout<<"original gcd : "<<__gcd(a,b)<<endl;

	cout<<euclidAlgo(a,b);	
	
	return 0;
}
