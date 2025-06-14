#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n, m, sp[10000], ep[10000];

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

int degIn[101], degOut[101];
void CalcDegInOut(){
    memset(degIn, 0, sizeof(degIn));
    memset(degOut, 0, sizeof(degOut));
    for(int i = 1; i <= m; i++){
        int u = sp[i];
        int v = ep[i];
        degOut[u]++;
        degIn[v]++;
    }
    for(int u = 1; u <= n; u++){
        cout << degIn[u] << " " << degOut[u] << "\n";
    }
}

int a[101][101];
void AdjMat(){
    cout << n << "\n";
    int u,v,t;
    for(t = 1; t <= m; t++){
        u = sp[t]; v = ep[t];
        a[u][v]++;
    }
    for(u = 1; u <= n; u++){
        for(v = 1; v <= n; v++){
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
        CalcDegInOut();
    } else {
        AdjMat();
    }
    return 0;
}