#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n, adj[101][101];
int deg[101];

void OpenFile() {
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
}

void ReadData() {
    cin >> t >> n;
	for (int u = 1; u <= n; u++){
        cin >> adj[u][0];
	    for (int v = 1; v <= adj[u][0]; v++)
	         cin >> adj[u][v];
    }
}

void CalcDeg() {
    int u;
    for (u = 1; u<= n; u++)
        deg[u] = adj[u][0];
    for (u = 1; u <= n; u++) 
        cout << deg[u] << " ";
}

int m, sp[10000], ep[10000];
void AdjMat(){
    int u, v, t, m = 0;
    for(u = 1; u <= n; u++){
        for(v = 1; v <= adj[u][0]; v++){
            t = adj[u][v];
            if(u < t){
                m++;
                sp[m] = u;
                ep[m] = t;
            }
        }
    }
    cout << n << " " << m << "\n";
    for(t = 1; t <= m; t++){
        cout << sp[t] << " " << ep[t] << "\n"; 
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    OpenFile(); 
    ReadData();
    if (t == 1) {
        CalcDeg();
    } else {
        AdjMat();
    }
    return 0;
}
