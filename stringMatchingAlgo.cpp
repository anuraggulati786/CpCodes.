// s = "Working hard is better than working smart";
// p = "hard"

#include <iostream>
using namespace std;

// TC: O(m * n)
int naiveSearch(string s, string p) {
    if(p.length() > s.length()) return -1;

    int i = 0;
    while(i < s.length()) {
        int j = 0;      // j is index in p
        int k = i;
        while(j < p.length() && k < s.length() && s[k] == p[j]) {
            k++;
            j++;
        }
        if(j == p.length()) {
            return i;
        }
        i++;
    }
    return -1;
}

// XOR(4x - 1) = 0

int main()
{
    // string s = "Working hard is better than working smart";
    // string p = "hard";
    string s = "abccccddddabcccddddd";
    string p = "abcccddddd";
    cout << naiveSearch(s, p) << endl;
    return 0;
}
