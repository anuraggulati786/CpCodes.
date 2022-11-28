// anagram: string = abcd; print all anagrams of it.
// anagram: two strings with same length and containing same characters, occurring with same frequency, and in any order

// just print the permutations of it.
// abcd, acbd, ... so on

// if duplicates are there, like abbcd;
// same here; print all permutations.


// how to identify two strings are anagram ?
// Approach b. use a bool array, to mark the elements that are present (of first string, in second)

// Approach 1: use approach a but instead of boolean array, use a var, and modify second string by '#' (Not Applicable; single variable won't work, as it can't count frequency)
// Approach 2. sort both strings and check if both same
// Approach 3: using hashmap/unordered map;       [how to implement hashmap/unordered map, open previous notes (DSA ones; end side notes)]
//           using an integer array of size [26]

#include <iostream>
#include <algorithm>
using namespace std;

// TC: O(n^2);   SC: O(1)
bool approach1(string first, string second) {
    // if strings' size is different, then not anagram
    if(first.size() != second.size())
        return false;
    
    for(int i = 0; i < first.size(); ++i) {
        char c = first[i];
        bool found = false;
        // for every character of first string, check if it exists in second  
        for(int j = 0; j < second.size(); ++j) {
            if(second[j] == c) {
                second[j] = '#';
                found = true;
                break;
            }
        }
        // if this character 'c' is not found in second string, then this is not anagram, return right now
        if(!found) return false;
    }
    // if all characters matched & string size is surely equal we checked in starting, then return true
    return true;
}


// TC: O(nlogn);   SC: O(1)
bool approach2(string first, string second) {
    // sort and match the strings, if un-matches anywhere, not an anagram then.
    if(first.length() != second.length())
        return false;
    
    sort(first.begin(), first.end());
    // first.begin(): iterator to the beginning of string
    // first.end()  : iterator after the the end of string (after last character)
    sort(second.begin(), second.end());
    
    for(int i = 0; i < first.length(); ++i) {
        if(first[i] != second[i]) return false;
    }
    return true;
}


// TC: O(n);   SC: O(1)
bool approach3(string first, string second) {
    if(first.length() != second.length()) 
        return false;
    
    int hashing[26] = {};
    for(int i = 0; i < first.length(); ++i) {
        hashing[first[i] - 'a']++;
        hashing[second[i] - 'a']--;
    }

    for(int i = 0; i < 26; ++i) {
        if(hashing[i] != 0) return false;
    }
    return true;
}

int main()
{
    string first = "abcd", second = "dcba";
    first = "klsdjf"; second = "lsdjfk";
    cout << approach1(first, second) << endl;
    first = "klsdjf"; second = "lsdjfk";
    cout << approach2(first, second) << endl;

    first = "klsdjf"; second = "lsdjfk";
    cout << approach3(first, second) << endl;
    return 0;
}

// if both case alphabets are present in string, then make 2 arrays of size 26 each.
// and use approach3

