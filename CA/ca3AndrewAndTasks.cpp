//Andrew likes programming a lot and tries to practice as many problems as he could. Recently, 
//while practicing he came across a rather straightforward problem but as he is busy on account of his exams, 
//please help him in solving this question. The problem is given N tasks with start and finish times, help him decide how he can complete maximum of these tasks. 
//Only one person is required to work on these tasks and he can work on one single task at one time.


//Author - Siddhant Arya
#include<bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

bool isPrime(ll n) {

    if (n == 1) {
        return false;
    }

    for (ll i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }

    return true;
}

bool gpf(ll n, ll p) {

    while (n % 2 == 0) {
        n /= 2;
    }
    for (ll i = 3; i <= sqrt(n); i += 2){
        while (n % i == 0) { 
            if(i>p) return false;
            n = n / i;
        }
    }
    if (n > 2){
        if(n>p) return false;
    }
    return true;
}

int main(){
    fast;
    system("cls");

    ll n;  cin>>n;
    ll arr[n]={};
    for(ll i=0; i<n; i++)  cin>>arr[i];

    ll p;  cin>>p;
    ll greatest_p=0;
    for(ll i=0; i<n; i++){
        if(gpf(arr[i],p)){
            greatest_p = max(greatest_p, arr[i]);
        }
    }
    if(greatest_p==0)   cout<<0<<endl;
    else{
        ll close_back=LONG_MIN;
        for(ll i=1; i<=greatest_p; i++){
            if(isPrime(i)){
                close_back=i;
            }
        }
        ll close_front=LONG_MAX;
        for(ll i=greatest_p; ;i++){
            if(isPrime(i)){
                close_front = i;
                break;
            }
        }

        if(abs(greatest_p-close_back)<=abs(greatest_p-close_front)) cout<<close_back;
        else        cout<<close_front;
    }
}
