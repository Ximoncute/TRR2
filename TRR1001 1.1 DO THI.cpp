#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t,n, a[101][101];

 void OpenFile() {
     freopen("DT.INP", "r", stdin);
     freopen("DT.OUT", "w", stdout);
 }

void ReadData() {	
    cin >> t;
    cin >> n;
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            cin >> a[u][v];	     
}

int deg[101];

void CalcDeg() {
    for (int u = 1; u <= n; u++) {
        deg[u] = 0;
        for (int v = 1; v <= n; v++) 
            deg[u] += a[u][v]; 
    }
    for (int u = 1; u <= n; u++) 
        cout << deg[u] << " ";
    cout << endl;
}

int m, sp[10000], ep[10000];

void EgList() {
    vector<pair<int, int>> edges;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i][j]) {
                edges.emplace_back(i, j);
            }
        }
    }
    sort(edges.begin(), edges.end());

    int m = edges.size();
    cout << n << " " << m << "\n";
    for (auto [u, v] : edges)
        cout << u << " " << v << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     OpenFile();
    ReadData();
    if(t == 1){
        CalcDeg();
    }
    else EgList();
    return 0;
}
