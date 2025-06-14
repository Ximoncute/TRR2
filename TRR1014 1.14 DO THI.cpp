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

int im[101][10001];  // Increased size to handle more edges
void IncMat(){
    int m = 0;
    // Count total edges first
    for (int u = 1; u <= n; u++){
        for (int v = 1; v <= n; v++){
            if (u != v) {  // Typically don't count self-loops unless specified
                m += a[u][v];
            }
        }
    }
    
    // Fill incidence matrix
    int edge = 1;
    for (int u = 1; u <= n; u++){
        for (int v = 1; v <= n; v++){
            for (int t = 1; t <= a[u][v]; t++){
                if (u != v) {  // Skip self-loops
                    // Initialize current edge column to 0
                    for (int k = 1; k <= n; k++) {
                        im[k][edge] = 0;
                    }
                    im[u][edge] = 1;
                    im[v][edge] = -1;
                    edge++;
                }
            }
        }
    }
    
    cout << n << " " << m << "\n";
    for(int u = 1; u <= n; u++){
        for(int v = 1; v <= m; v++){
            cout << im[u][v] << " ";
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