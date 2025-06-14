#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n, a[101][101];
int deg[101];
int im[101][10000];

void OpenFile() {
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
}

void ReadData() {
    cin >> t >> n;
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            cin >> a[u][v];
        }
    }
}

void CalcDeg() {
    for (int u = 1; u <= n; u++) {
        deg[u] = 0;
        for (int v = 1; v <= n; v++) {
            deg[u] += a[u][v];
        }
    }

    for (int u = 1; u <= n; u++) {
        cout << deg[u] << " ";
    }
    cout << '\n';
}

void IncMat() {
    int m = 0; 

    for (int u = 1; u <= n - 1; u++) {
        for (int v = u + 1; v <= n; v++) {
            for (int t = 1; t <= a[u][v]; t++) {
                m++;
                im[u][m] = 1;
                im[v][m] = 1;
            }
        }
    }
    cout << n << " " << m << "\n";

    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= m; v++) {
            cout << im[u][v] << " ";
        }
        cout << '\n';
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
        IncMat();
    }
    return 0;
}
