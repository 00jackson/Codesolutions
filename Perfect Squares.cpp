// Given an integer n, return the least number of perfect square numbers that sum to n.

// A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

 

// Example 1:

// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.
// Example 2:

// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.


// Solution:
// Cpp

class Solution {
public:
int solveMemo(int n, vector<int>&dp){
    //base case
    if(n == 0)
    return 0;
    if(dp[n] != -1)
    return dp[n];
    int ans = n;
    for(int i=1; i*i<=n; i++){
        int temp = i*i; //code quality
        ans = min(ans,1+solveMemo(n-temp,dp)); // 1+ cause we need to include the subproblem while returning to n.
    }
    dp[n] = ans;
    return dp[n];
}
//another bottom up approach(Tabulation) below
int solveTab(int n){
    vector<int> dp(n+1, INT_MAX); //see when we need to find minimum of something we use INT_MAX and vice-versa.
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j*j<=n; j++){
            int temp=j*j; 
            if(i-temp>=0)
            dp[i] = min(dp[i], 1+dp[i-temp]);
        }       
    }
    return dp[n];
}
    int numSquares(int n) {
        //below lines for memo func
    //   vector<int> dp(n+1, -1);
        // return solveMemo(n, dp);

        return solveTab(n);
    }
}; ///use the either or approach 
