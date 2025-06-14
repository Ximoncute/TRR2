#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n, m, sp[105], ep[5000];
int deg[101];
int a[101][10000];

void OpenFile() {
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
}

void ReadData() {
    cin >> t >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> sp[i] >> ep[i];
    }
}

void CalcDeg() {
    int u, v, t;
    for(u = 1; u <= n; u++){
        deg[u] = 0;
    }
    for(t = 1; t <= m; t++){
        u = sp[t];
        v = ep[t];
        deg[u]++;
        deg[v]++;
    }
    for(u = 1; u <= n; u++){
        cout << deg[u] << " ";
    }
}

void AdjMat(){
    cout << n << " " << m << "\n";
    int u,v,t;
    for(t = 1; t <= m; t++){
        u = sp[t]; a[u][t] = 1;
        v = ep[t]; a[v][t] = 1;
    }
    for(u = 1; u <= n; u++){
        for(v = 1; v <= m; v++){
            cout << a[u][v] << " ";
        }
        cout << "\n";
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
