//recc

class Solution {
public:
    int minCost(vector<int>& cost, int i) {
        if (i < 0) return 0;
        if (i == 0 || i == 1) return cost[i];
        
        return cost[i] + min(minCost(cost, i - 1), minCost(cost, i - 2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return min(minCost(cost, n - 1), minCost(cost, n - 2));
    }
};


// recc + memo

class Solution {
public:
    int minCost(vector<int>& cost, int i , vector<int>&dp) {
        if (i < 0) return 0;
        if (i == 0 || i == 1) return cost[i];
        if (dp[i] != -1) return dp[i];
        
        return dp[i] = cost[i] + min(minCost(cost, i - 1 , dp), minCost(cost, i - 2 , dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1 , -1);
        return min(minCost(cost, n - 1 , dp), minCost(cost, n - 2 , dp));
    }
};


//tabulation

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 0) return 0;
        if (n == 1) return cost[0];
        
        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for (int i = 2; i < n; ++i) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        
        return min(dp[n - 1], dp[n - 2]);
    }
};

//space optimization

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 0) return 0;
        if (n == 1) return cost[0];
        
        int prev2 = cost[0];
        int prev1 = cost[1];
        
        for (int i = 2; i < n; ++i) {
            int current = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = current;
        }
        
        return min(prev1, prev2);
    }
};
