// -----------------------------------------------------------------------
// cgpa, coding round, resume, (ds, algo, database, os), projects

// ||-> [competitive coding <-- the MOST important]  <-||

// contributing to open source
// hackathons
// industry certifications
// -----------------------------------------------------------------------


// given string,
// may / may not have duplicates;
// return the string with no same characters together, if not possible, then return ""


// inp: aaabc 
// out: abaca

// inp: aaaa
// out: 

// inp: aaabb
// out: ababa

// inp: abcc
// out: cacb


// inp: abbcc
// out: abcbc   OR   cbabc

// inp: abbbc
// out: bcbab

#include <iostream>
#include <vector>
using namespace std;


string approach1(string s) {
    if(s.size() == 1) {
        return s;
    } else if(s.size() == 2) {
        if(s[0] == s[1]) {
            return "";
        } 
        return s;
    }

    string result = "";
    result += s[0];
    int i = 1;
    s[0] = '#';

    int unHashed = 0, prevUnHashed = 0;
    while(true) {
        // cout << result << ":";
        if(i == s.size()) {
            if(result.size() == s.size()) 
                return result;
            else {
                if(!prevUnHashed) {
                    prevUnHashed = unHashed;
                    unHashed = 0;
                } else if(prevUnHashed && (prevUnHashed == unHashed)) {
                    return "Not Possible";
                }
                // cannot put it in else, if control reaches here, then need to reset i
                i = 0;
            }
        }
        while(i < s.size() && s[i] == '#') i++;
        if(i == s.size()) continue;

        char c = s[i];
        if(result[0] != c) {
            result = c + result;
            s[i] = '#';
            i++;
            continue;
        }
        else if(result[result.size() -1] != c) {
            result = result + c;
            s[i] = '#';
            i++;
            continue;
        }
        else {
            bool isFound = false;
            for(int j = 1; j < result.size() -1; ++j) {
                if(c != result[j] && c != result[j + 1]) {
                    result = result.substr(0, j+1) + c + result.substr(j+1, result.size());
                    isFound = true;
                    s[i] = '#';
                    i++;
                    break;
                }
            }
            if(isFound) continue;

            // if could not add at beginning, neither at end, nor in between, ignore all upcoming same characters
            while(s[i] == s[i + 1]) {
                i++;
                unHashed++;
            }
        }
        i++;
        unHashed++;
    }
    // aaabb ;     ababa::   abbba; babab   :::  aaaaab; aba
}

// TC: O(n)
void approach2(string s) {
    int freq[26] = {};
    int max = 0;
    char c = '#';

    for(int i = 0; i < s.length(); ++i) {
        freq[s[i] - 'a']++;
        if(freq[s[i] - 'a'] > max) {
            max = freq[s[i] - 'a'];
            c = s[i];
        }
    }
    if(max > (s.size() + 1) / 2) {
        cout << "Not possible\n";
        return;
    }

    string result = s;
    // fill at even indices
    for(int i = 0; i < result.size(); i += 2) {
        result[i] = c;
        freq[c - 'a']--;
        if(freq[c - 'a'] == 0) {
            for(int j = 0; j < 26; ++j) {
                if(freq[j] != 0) {
                    c = j + 'a';
                    break;
                }
            }
        }
    }

    // fill at odd indices
    for(int i = 1; i < result.size(); i += 2) {
        result[i] = c;
        freq[c - 'a']--;
        if(freq[c - 'a'] == 0) {
            for(int j = 0; j < 26; ++j) {
                if(freq[j] != 0) {
                    c = j + 'a';
                    break;
                }
            }
        }
    }
    cout << result << "\n";
}


int main() {
    vector<string> s = {"aabbbc", "abbcaabc", "abbba", "caaabbc", "abbc", "abbbbc", "aaaa", "aaabbccc", "aaaaabbccc", "aabaaabaabccc", "aaaaaaabbc"};

    for(int i = 0; i < s.size(); ++i) {
        // cout << "input string: " << s[i] << "\n";
        // cout << "output string: " << approach1(s[i]) << "\n\n";
        cout << s[i] << "\t";
        approach2(s[i]);
    }

    return 0;
}

// string s = "abbba";
    // s = "caaabbc";
    // s = "aaabb";
    // s = "abbc";
    // s = "aaaa";
    // s = "abbbbc";
    // s = "aaabbccc";
    // s = "aaaaabbccc";
    // s = "aabaaabaabccc";
    // s = "aaaaaaabbc";

// aabbbc: ababcb

// abbccdddd: a b d c d b d c d ; but ans is: a b d b d c d c d
// aabcdd : a b a d c d

