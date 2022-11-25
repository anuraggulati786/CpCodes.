// sieve of eratosthenes  O(n* log (log(n))

#include<bits/stdc++.h>
using namespace std;


void sieve(int n) {
	
	
	vector<int>temp(n,true);
	temp[0] = temp[1] = false;
	for(int i=2; i*i <= n; i++) {
		if(temp[i] == true) {
			for(int j = i*i; j<=n; j += i) {
				temp[j] = false;
			}
		}
	}
	
	for(int i=0; i<n; i++) {
		if(temp[i] == true) {
			cout<<i<<" ";
		}
	}
}

signed main() {
	
	int n;
	cin>>n;
	
	sieve(n);
	
	return 0;
	
}
