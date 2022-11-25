// greatest prime factor:

#include<bits/stdc++.h>
using namespace std;

int gpf(int num){
	int max = num;
		if(num % 2 == 0){
			max = 2;
			num = num/2;
		}
		for(int i = 3; i*i<=num ; i = i+2){
			while(num % i == 0){
				max = i;
				num = num / i;
			}
		}
		if(num > 1)
			max = num;
	return max;
}

signed main() {
	int num;
	cin>>num;
	
	cout<<gpf(num);
	
	return 0;
}
