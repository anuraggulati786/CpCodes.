////======= 19. P smooth number : gpf(num) <= p
//   		ex: 2 smooth number : 2 is 2-smooth
//			8 is 2-smooth
//			26 is not 2-smooth (gpf of 26 is 13 i.e. > 2

#include<bits/stdc++.h>
using namespace std;
int greatestPrimeFactors(int n)
{
    int maxPrime = -1;

    while(n % 2 == 0)
    {
        maxPrime = 2;
        n /= 2;
    }

    for(int i = 3; i < (int)(n * 1 / 2 + 1); i = i + 2)
        while(n % i == 0)
        {
            maxPrime = i;
            n = n / i;
        }

    if (n > 2)
        maxPrime = n;
 
    return (int)(maxPrime);
}

bool isPSmooth(int num, int p) {
	
	
	if(greatestPrimeFactors(num) <= p) {
		return true;
	}
	else {
		return false;
	}
		
}

int main() {
	
	int num;
	cin>>num;
	
	int p;
	cin>>p;
	
	if(isPSmooth(num,p) == true) {
		cout<<num<<" is "<<"p"<<" smooth Number ."<<endl;
	}
	else{ 
		cout<<num<<" is not a p smooth number ."<<endl;
	}
}
