#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n, a[101][101];

void OpenFile() {
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
}

void ReadData() {
    cin >> t >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
}

int degIn[101], degOut[101];
void CalcDegInOut(){
    for (int u = 1; u <= n; u++){
        degIn[u] = 0; 
        degOut[u] = 0;
    }
    
    for (int u = 1; u <= n; u++){
        for (int v = 1; v <= n; v++)  {
            if (a[u][v]) {
                degOut[u]++;
                degIn[v]++;
            }
        }
    }
    
    for (int u = 1; u <= n; u++) 
        cout << degIn[u] << " " << degOut[u] << endl;
}

int adj[101][101];
void AdjList(){
    cout << n << "\n";
    int u, v, t;      
    for (u = 1; u<= n; u++){
        t = 0;
        for (v = 1; v <= n; v++){
            if (a[u][v] > 0){
                t++; adj[u][t] = v;
            }
            adj[u][0] = t;
        }
    } 
    for(u = 1; u <= n; u++){
        cout << adj[u][0] << " ";
        for(v = 1; v <= adj[u][0]; v++){
            cout << adj[u][v] << " ";
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
        AdjList();
    }
    return 0;
}