#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n, adj[101][101];
int deg[101];

// void OpenFile() {
//     freopen("DT.INP", "r", stdin);
//     freopen("DT.OUT", "w", stdout);
// }

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

int m, im[101][10000];
void IncMat(){
    int u,v;
    m = 0;
    for(u = 1; u <= n; u++){
        for(v = 1; v <= adj[u][0]; v++){
            int t = adj[u][v];
            if(u < t){
                m++;
                im[u][m] = 1;
                im[t][m] = 1;
            }
        }
    }
    cout << n << " " << m << "\n";
    for(u = 1; u <= n; u++){
        for(v = 1; v <= m; v++){
            cout << im[u][v] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // OpenFile(); 
    ReadData();
    if (t == 1) {
        CalcDeg();
    } else {
        IncMat();
    }
    return 0;
}
