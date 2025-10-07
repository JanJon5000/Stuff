int climbStairs(int n) {
    int ans = -1;
    for(int i=n;i>0;i--)
        ans+=i;
    return ans;
}