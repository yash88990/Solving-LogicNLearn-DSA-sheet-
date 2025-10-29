#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int solve(int n) {
        if (n == 0) return 0;
        
        int ans = INT_MAX;
        for (int i = 1; i * i <= n; i++) {
            ans = min(ans, 1 + solve(n - i * i));
        }
        return ans;
    }

    int MinSquares(int n) {
        return solve(n);
    }
};





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int solve(int n, vector<int> &dp) {
        if (n == 0) return 0;
        if (dp[n] != -1) return dp[n];
        
        int ans = INT_MAX;
        for (int i = 1; i * i <= n; i++) {
            ans = min(ans, 1 + solve(n - i * i, dp));
        }
        return dp[n] = ans;
    }

    int MinSquares(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};
