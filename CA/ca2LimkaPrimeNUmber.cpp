// The problem is given a range of numbers display all numbers which have 
// exactly two unique prime factors between the left and right endpoints(inclusive) of the given range



#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int countFactors(int num)
{
    set<int> s;
    while (num % 2 == 0){
        s.insert(2);
        num /=2;
    }
    for (int i = 3; i <= sqrt(num); i = i + 2){
        while (num % i == 0){
            s.insert(i);
            num = num / i;
        }
    }
    if(num > 2) s.insert(num);
    return s.size();
}
signed main(){
    
    int num1,num2;
    cin>>num1>>num2;
    for(int i=num1; i<=num2; i++){
        if(countFactors(i) == 2) {
            cout<< i <<" ";
        }
    }
}
