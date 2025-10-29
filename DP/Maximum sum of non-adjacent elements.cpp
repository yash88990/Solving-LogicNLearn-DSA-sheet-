#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int n) {
    if (n < 0) return 0;
    if (n == 0) return nums[0];

    int include = solve(nums, n - 2) + nums[n];
    int exclude = solve(nums, n - 1);

    return max(include, exclude);
}

int maximumNonAdjacentSum(vector<int> &nums) {
    int n = nums.size();
    return solve(nums, n - 1);
}








//dp


#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int n, vector<int> &dp) {
    if (n < 0) return 0;
    if (n == 0) return nums[0];

    if (dp[n] != -1) return dp[n];

    int include = solve(nums, n - 2, dp) + nums[n];
    int exclude = solve(nums, n - 1, dp);

    return dp[n] = max(include, exclude);
}

int maximumNonAdjacentSum(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    return solve(nums, n - 1, dp);
}

