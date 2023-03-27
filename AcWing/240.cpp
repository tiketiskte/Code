/**
* Copyright(c)
* Author : tiketiskte
**/
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
const int maxn = 5e4 + 10;
int n, k, op, x, y, p[maxn], d[maxn];
void init(int n) {
    for(int i = 0; i <= n; i++) {
        p[i] = i;
    }
}
int find(int x) {
    if(p[x] != x) {
        int u  = find(p[x]);
        d[x] += d[p[x]];
        p[x] = u;
    }
    return p[x];
}
int main(void) {
    // IOS
    cin >> n >> k;
    init(n);
    int ans = 0;
    while(k--) {
        cin >> op >> x >> y;
        if(x > n || y > n) {
            ans++;
        } else {
            int px = find(x), py = find(y);
            if(op == 1) {
                if(px == py && (d[x] - d[y]) % 3) {
                    ans++;
                } else if(px != py) {
                    p[px] = py;
                    d[px] = d[y] - d[x];
                }
            } else {
                if(px == py && (d[x] - d[y] - 1) % 3) {
                    ans++;
                } else if(px != py) {
                    p[px] = py;
                    d[px] = d[y] + 1 - d[x];
                }
            }
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}