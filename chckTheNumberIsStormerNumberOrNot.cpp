//A Stormer Number is a positive integer ‘i’ such that the greatest prime factor of the term i*i + 1  is greater than or equal to 2*i  . 
//For example, 5 is a Stormer number because the greatest prime factor of 26(i.e 5*5 + 1) is 13 which is greater than or equal to 10(i.e 2*5) 


//======= 17. stormer numbers : for a number i : -> gpf(i*i+1) >= 2*i
// ====== find the first n stormer number

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 int maxPrimeFactors(int n) // gpf function :)
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


void checkStormerOrNot(int n) {

    int i = n;
    bool temp = false;
        int t = i * i + 1;
        if (maxPrimeFactors(t) >= 2 * i)
        {
            temp = true;
        }
        if(temp == true) {
        	cout<<"Yes "<<n<<" is a stormer number :"<<endl;
		}
		else {
        	cout<<"No "<<n<<" is a not a stormer number :"<<endl;
		}
    return;
}

int main() {
	
	int n;
	cin>>n;
	
	checkStormerOrNot(n);	
	
	return 0;
}
