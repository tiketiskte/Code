/**
* Copyright(c)
* All rights reserved.
* Author : tiketiskte
* Date : 2023-01-13-17.23.15
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
const int maxn = 100000 + 10;
int main(void) {
    IOS
    int a[maxn], s[maxn];
    int n, m, l, r;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    s[0] = 0;
    for(int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    while(m--) {
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}
