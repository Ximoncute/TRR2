#include<bits/stdc++.h>
using namespace std;

#define cin in
#define cout out

ifstream in ("TK.INP");
ofstream out ("TK.OUT");

int n;
bool vs[1005];
vector<vector<int>> adj(1005);
vector<pair<int, int>> edge;
vector<pair<int, int>> ans;

void dfs(int u, int s=-1, int t=-1){
    vs[u]=true;
    for (int v : adj[u]){
        if ((u==s && v==t) || (u==t && v==s)) continue;
        if (!vs[v]) dfs(v,s,t);
    }
}

int tplt(int s=-1, int t=-1){
    int cnt=0;
    memset(vs, false, sizeof(vs));
    for (int i=1; i<=n; ++i){
        if (!vs[i]){
            ++cnt;
            dfs(i,s,t);
        }
    }
    return cnt;
}

void canhcau(){
    int cc=tplt();
    for (auto e : edge){
        int s=e.first, t=e.second;
        int newcc=tplt(s,t);
        if (newcc>cc){
            if (s>t) swap(s,t);
            ans.push_back({s,t});
        }
    }
}

int main(){
    cin>>n;
    for (int i=1; i<=n; ++i){
        for (int j=1; j<=n; ++j){
            int x;
            cin>>x;
            if (x && i<j){
                adj[i].push_back(j);
                adj[j].push_back(i);
                edge.push_back({i,j});
            }
        }
    }
    canhcau();
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    for (auto x: ans) cout<<x.first<<" "<<x.second<<endl;
}