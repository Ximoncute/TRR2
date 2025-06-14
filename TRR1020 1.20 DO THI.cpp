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
        for(int j = 1; j <= adj[i][0]; j++){
            cin >> adj[i][j];  
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

int m, im[101][10001];  
void IncMat(){
    m = 0;
    memset(im, 0, sizeof(im));  
    
    for(int u = 1; u <= n; u++) {
        for(int j = 1; j <= adj[u][0]; j++) {
            int v = adj[u][j];
            m++; 
            im[u][m] = 1;       
            im[v][m] = -1;     
        }
    }
    
    cout << n << " " << m << "\n";
    for(int u = 1; u <= n; u++) {
        for(int e = 1; e <= m; e++) {
            cout << im[u][e] << " ";
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
        IncMat();
    }
    return 0;
}