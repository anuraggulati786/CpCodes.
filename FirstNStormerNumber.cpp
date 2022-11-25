//======= 17. stormer numbers : for a number i : -> gpf(i*i+1) >= 2*i
// ====== find the first n stormer number

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxPrimeFactors(int n)
{
    int maxPrime = -1;

    while(n % 2 == 0)
    {
        maxPrime = 2;
        n /= 2;
    }
    // n must be odd at this
    // point, thus skip the
    // even numbers and iterate
    // only for odd integers
    for(int i = 3; i < (int)(n * 1 / 2 + 1); i = i + 2)
        while(n % i == 0)
        {
            maxPrime = i;
            n = n / i;
        }
 
    // to handle
    // the case when n is a prime
    // number greater than 2
    if (n > 2)
        maxPrime = n;
 
    return (int)(maxPrime);
}


void firstNStormetrNumber(int n) {

    int i = 1;
    int count = 0;
    while(count < n)
    {
        int t = i * i + 1;
        if (maxPrimeFactors(t) >= 2 * i)
        {
            cout << i ;
            cout <<" ";
            count = count + 1;
        }
        i = i + 1;
    }
    return;
}

signed main() {
	
	int n;
	cin>>n;
	
	firstNStormetrNumber(n);	
	
	return 0;
}
