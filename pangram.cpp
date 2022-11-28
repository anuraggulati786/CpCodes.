// pangram: if a string contains all the alphabets atleast once, then its pangram, else not

#include <iostream>
using namespace std;

// TC: O(n)
bool pangram1(string s) {
    if(s.length() < 26) 
        return false;
    for(char c = 'a'; c <= 'z'; ++c) {
        bool found = false;
        for(int i = 0; i < s.length(); ++i) {
            if(c == s[i]) {
                found = true;
                break;
            }
        }
        if(!found) return false;
    }
    return true;
}

// TC: O(n), SC: O(1) : better by constant factor 
bool pangram2(string s) {
    bool hashing[26] {};

    // mark the characters that are present in the string as true in hashing array
    for(int i = 0; i < s.length(); ++i) {
        hashing[s[i] - 'a'] = true;
    }
    // check if any character is missing (i.e. false) then it is not pangram
    for(int i = 0; i < 26; ++i) {
        if(!hashing[i]) return false;
    }
    return true;
}
// if uppercase alphabets are also there, then use 2 arrays for that.
// if language is different say hindi, then use all the characters of hindi, to check if it is pangram.

int main() {
    string s = "abcdefghijklmnopqrstuvwxyz";
    cout << pangram1(s) << endl;
    cout << pangram2(s) << endl;
    return 0;
}

