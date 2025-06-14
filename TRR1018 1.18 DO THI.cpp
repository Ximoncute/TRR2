#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n, adj[101][101];

void OpenFile() {
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
}

void ReadData() {
    cin >> t >> n;
    for(int i = 1; i <= n; i++){
        cin >> adj[i][0];
        for(int v = 1; v <= adj[i][0]; v++){
            cin >> adj[i][v];
        }
    }
}

int degIn[101], degOut[101];
void CalcDegInOut(){
    memset(degIn, 0, sizeof(degIn));
    memset(degOut, 0, sizeof(degOut));
    
    for(int u = 1; u <= n; u++){
        degOut[u] = adj[u][0];  
        for(int j = 1; j <= adj[u][0]; j++) {
            int v = adj[u][j];  
            degIn[v]++;        
        }
    }
    
    for(int u = 1; u <= n; u++){
        cout << degIn[u] << " " << degOut[u] << "\n";
    }         
}


int a[101][101];
void AdjMat(){
    cout << n << "\n";
    int u, v;      
    for (u = 1; u<= n; u++){          
        for (v = 1; v <= adj[u][0]; v++){
            int t = adj[u][v]; 
            a[u][t] = 1;
        }
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