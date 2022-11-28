// generate the anagrams of a given string

// example: 
    // abcd: abcd, abdc, acbd, acdb, adcb, adbc, bacd, badc, ... (24 permutations)

#include <bits/stdc++.h>
using namespace std;


void solve(int indx, string s) {
    if(indx == s.size()) {
        cout << s << ", ";
        return;
    }
    for(int i = indx; i < s.size(); ++i) {
        swap(s[i], s[indx]);
        solve(indx + 1, s);
        swap(s[i], s[indx]);
    }
}
int main()
{
    string str = "abcd";
    solve(0, str);
    return 0;
}
