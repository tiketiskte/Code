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
typedef unsigned long long ULL;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <double, double> PDD;
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}
const int maxn = 1e5 + 10;
const int P = 131;
ULL h[maxn], p[maxn];
int n, m, l1, l2, r1, r2;
char str[maxn];
ULL get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}
int main(void) {
    IOS
    cin >> n >> m >> (str + 1);
    p[0] = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i];
    }
    while(m--) {
        cin >> l1 >> r1 >> l2 >> r2;
        if(get(l1, r1) == get(l2, r2)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    system("pause");
    return 0;
}