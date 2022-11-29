//You are required to print a count of the numbers which are both P smooth and
// P jagged with in such a range. In case there are no such numbers in a range then print -1.
//
//NNote: Here p smooth numbers are those whose largest prime factor <= p and p jagged numbers are those whose smallest prime factor <= p.




#include<bits/stdc++.h>
using namespace std;

long long GreatestPrime(int num) {
   long long res = -1;
   while (num % 2 == 0) {
      res = 2;
      num /= 2;
   }
   for (int i = 3; i <= sqrt(num); i += 2){
      while (num % i == 0) {
         res = i;
         num = num / i;
      }
   }
   if (num > 2)
   res = num;
   return res;
}

long long isjagged(int n) {
    
    if(n%2==0)  return 2;
    for(int i=3; i<=sqrt(n); i+=2){
        if(n%i==0)  return i;
    }   
    return n;
    
}
signed main(){

    int GPF[100001]={};
    
    int JAG[100001]={};

    for(int i=1;i<=100000; i++){
        GPF[i]=GreatestPrime(i);
    }
    for(int i=1;i<=100000; i++){
        JAG[i]=isjagged(i);
    }
    int tc;  
    cin>>tc;
    while(tc--) {
        int sp,ep,p;  
        cin>>sp>>ep>>p;
        int count=0;
        for(int i=sp; i<=ep; i++){
            if(GPF[i]<=p && JAG[i]<=p) count++;
        }
        if(count!=0)    
            cout<<count<<endl;
        else            
            cout<<-1<<endl;
    }
    return 0;

}
