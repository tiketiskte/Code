/**
* Copyright(c)
* All rights reserved.
* Author : tiketiskte
* Date : 2023-01-13-20.03.01
* Description : Algorithm
*/
#include <bits/stdc++.h>
using namespace std;
#define IOS {ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);}
#define rep(i, a, n) for(int i = a; i < n; i++)
#define per(i, a, n) for(int i = n - 1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sqr(x) (x) * (x)
#define SZ(X) (int)X.size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
typedef long long ll;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <double, double> PDD;

ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}

const int maxn = 1000 + 10;
int main(void) {
    IOS
    int n, m, q;
    int a[maxn][maxn], s[maxn][maxn];
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j<= m; j++) {
            cin >> s[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j<= m; j++) {
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    while(q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1] << endl;
    }
    return 0;
}
