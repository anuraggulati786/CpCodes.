//Andrew likes the topic of Smooth Numbers and recently came across a rather straightforward problem. 
//In the problem he was given a list of numbers and he was supposed to find the largest number out of this list which is a P smooth number. 
//He was then supposed to find the nearest prime number to this largest P smooth number. Since Andrew is busy preparing for ICPC, please help him by writing code to solve the problem.
//
//Note: In case there are no P smooth numbers, he should print 0 as the answer. 
//In case two numbers are equally close to each other, print the smaller out of them.
//
//Note: A P-smooth number is an integer whose largest prime factor is less than or equal to P.


//Author - Siddhant Arya
#include<bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

bool myfunc(pair<int,int> a, pair<int,int> b){
    return a.second<b.second;
}

int main(){
    fast;
    system("cls");

    int n;  cin>>n;
    int start[n]={};
    int end[n]={};

    for(int i=0; i<n; i++)  cin>>start[i];
    for(int i=0; i<n; i++)  cin>>end[i];

    if(n==0)    cout<<0<<endl;
    else{
        vector<pair<int,int>> times(n);
        for(int i=0; i<n; i++){
            times[i] = make_pair(start[i],end[i]);
        }

        sort(times.begin(),times.end(), myfunc);

        int last = times[0].second;
        int count=1;

        for(int i=1; i<n; i++){
            if(times[i].first>=last){
                count++;
                last = times[i].second;
            }
        }
        cout<<count<<endl;
    }
}
