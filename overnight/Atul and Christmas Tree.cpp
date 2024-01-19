#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
vector<int> adj[N];
int dp[N];

void dfs(int u,int par,int val)
{
    dp[u]=val;
    
    for(int &v:adj[u])
        if(v!=par)
            dfs(v,u,val+1);
    
    return;
}

int main()
{   
    int n ;
    scanf("%d",&n);
    
    for(int i=0, u, v;i<n-1;i++)
    {
        scanf("%d%d",&u,&v);
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    
    dfs(0,-1,1);
    
    double ans=0.0;
    for(int i=0;i<n;i++)
        ans+=(1.0/dp[i]);
    
    printf("%d\n",(int)ans);
    
    return 0;
}
