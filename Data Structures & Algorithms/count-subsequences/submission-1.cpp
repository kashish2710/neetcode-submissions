class Solution {
public:
int solve(int i,int j,string& s,string &t,int m,int n){
    if(j==n)return 1;
    if(i==m)return 0;
    if(s[i]==t[j])return solve(i+1,j+1,s,t,m,n) + solve(i+1,j,s,t,m,n);
    else return solve(i+1,j,s,t,m,n);
}
    int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();
        // return solve(0,0,s,t,m,n);
vector<vector<int>>dp(m+1,vector<int>(n+1,0));
for(int i=0;i<m;i++){
    dp[i][0]=1;
}
for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
        if(s[i-1]==t[j-1]){
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
        }
        else dp[i][j]=dp[i-1][j];
    }
}
return dp[m][n];
    }
};
