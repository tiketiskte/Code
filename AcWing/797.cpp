/**
* Copyright(c)
* All rights reserved.
* Author : tiketiskte
* Date : 2023-01-13-23.22.29
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
const int maxn = 100000 + 5;
int a[maxn], b[maxn];
int n, m, l, r, c;
void insert(int l, int r, int c) {
    b[l] += c;
    b[r + 1] -= c;
}
int main(void) {
    IOS
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        insert(i, i, a[i]);
    }
    while(m--) {
        cin >> l >> r >> c;
        insert(l, r, c);
    }
    for(int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + b[i];
    }
    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
