#include <bits/stdc++.h>
using namespace std;

int getMinCoins(int indx, int amount, int count, vector<int> &coins) {
    if(indx == coins.size() || amount < 0) return INT_MAX;
    if(amount == 0) return count;
    
    
    int pick = getMinCoins(indx, amount - coins[indx], count+1, coins);
    int notPick = getMinCoins(indx + 1, amount, count, coins);

    return min(pick, notPick);
}


int getMinCoinsDp(int indx, int amount, int count, vector<int> &coins, vector<vector<int>> &dp) {
    if(indx == coins.size() || amount < 0) return INT_MAX;
    if(amount == 0) {
        return dp[indx][amount] = count;
    }
    
    if(dp[indx][amount] != -1) 
        return dp[indx][amount];
    int pick = getMinCoinsDp(indx, amount - coins[indx], count+1, coins, dp);
    int notPick = getMinCoinsDp(indx + 1, amount, count, coins, dp);
    return dp[indx][amount] = min(pick, notPick);
}

int main()
{
    vector<int> coins {2,5,6};
    int amount = 7;

    // cout << getMinCoins(0, target, 0, coins) << endl;

    vector<vector<int>> dp(coins.size() +1, vector<int> (amount + 1, -1));
    // coins, amount

    cout << getMinCoinsDp(0, amount, 0, coins, dp) << endl;
    for(auto r : dp) {
        for(auto c : r) cout << c << ", ";
        cout <<endl;
    }
    return 0;
}

// DYNAMIC PROGRAMMING

// Tabulation
//   0 1 2 3 4 5 6 7 8
//   -----------------
// 0|0 I I I I I I I I| 0
// 2|0 I 1 I 2 I 3 I 4| 1
// 5|0 I 1 I 2 1 3 2 4| 2
// 6|0 i 1 I 2 1 1 2 2| 3
//   ------------------
// Formula Derived - min(case1,case2+1)
