
//recc

class Solution {
public:
    int solve(string& a , string& b , int i , int j){
        //base case
        if( i == a.length() || j == b.length())return 0;
        int count = 0;
        if(a[i] == b[j])count = 1 + solve(a, b , i+ 1 , j+1);
        else count = max(solve(a ,b, i+1 , j) , solve( a , b , i  ,j+1));
        return count;
    }
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin() , s2.end());
        return solve(s , s2 , 0 , 0);
        
    }
};



//recc + memo
class Solution {
public:
    int solve(string& a , string& b , int i , int j , vector<vector<int>>&dp){
        //base case
        if( i == a.length() || j == b.length())return 0;
        int count = 0;
        if(dp[i][j] != -1)return dp[i][j];
        if(a[i] == b[j])count = 1 + solve(a, b , i+ 1 , j+1 , dp);
        else count = max(solve(a ,b, i+1 , j , dp) , solve( a , b , i  ,j+1 , dp));
        return dp[i][j] = count;
    }
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin() , s2.end());

        vector<vector<int>>dp(s.length() , vector<int>(s.length() , -1));
        return solve(s , s2 , 0 , 0 , dp);
        
    }
};


//tabulation

class Solution {
public:
    int solve(string& a , string& b){
        vector<vector<int>>dp(a.length() + 1  , vector<int>(a.length() + 1  , 0));
        for(int i = a.length() - 1 ; i >= 0 ; i--){
            for(int j = b.length() - 1 ; j >= 0 ; j--){
                int ans = 0;
                if(a[i] == b[j])ans = 1 + dp[i+1][j+1];
                else ans = max(dp[i+1][j] , dp[i][j+1]);
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
        
    }
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin() , s2.end());
        return solve(s , s2 );
        
    }
};



//space optimization

class Solution {
public:
    int solve(string& a ,  string &b){
        //step1 
        vector<int> curr(b.length() + 1 , 0);
        vector<int> next(b.length() + 1 , 0);
        for(int i = a.length() - 1 ; i >= 0 ; i--){
            for(int j = b.length() - 1 ; j >= 0 ; j--){
                int ans = 0;
                if(a[i] == b[j])ans = 1 + next[j+1];
                else ans = max(next[j] , curr[j+1]);
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];

    }
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin() , s2.end());
        return solve(s , s2 );
        
    }
};


