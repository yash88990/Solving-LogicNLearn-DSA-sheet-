#include <bits/stdc++.h>
using namespace std;

vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};

void solve(int n, vector<int> &ans) {
    if (n == 0) return;

    // Pick the largest coin <= n
    int coin = 0;
    for (int i = coins.size() - 1; i >= 0; i--) {
        if (coins[i] <= n) {
            coin = coins[i];
            break;
        }
    }

    ans.push_back(coin);
    solve(n - coin, ans);
}

vector<int> MinimumCoins(int n) {
    vector<int> ans;
    solve(n, ans);
    return ans;
}





#include <bits/stdc++.h>
using namespace std;

vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};

// Function returns list of coins for minimum combination
vector<int> solve(int n, unordered_map<int, vector<int>> &dp) {
    if (n == 0) return {};
    if (dp.find(n) != dp.end()) return dp[n];

    vector<int> best;
    int minCount = INT_MAX;

    for (int i = coins.size() - 1; i >= 0; i--) {
        if (coins[i] <= n) {
            vector<int> res = solve(n - coins[i], dp);
            res.push_back(coins[i]);

            if ((int)res.size() < minCount) {
                minCount = res.size();
                best = res;
            }
        }
    }
    return dp[n] = best;
}

vector<int> MinimumCoins(int n) {
    unordered_map<int, vector<int>> dp;
    vector<int> ans = solve(n, dp);

    // Reverse to get decreasing order (largest first)
    sort(ans.rbegin(), ans.rend());
    return ans;
}





