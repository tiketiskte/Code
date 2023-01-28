/**
* Copyright(c)
* All rights reserved.
* Author : tiketiskte
* Date : 2023-01-14-17.52.09
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
int a[maxn];
int solve(int l, int r, int k) {
    if(l == r) {
        return a[l];
    }
    int x = a[(l + r) >> 1], i = l - 1, j = r + 1;
    while(i < j) {
        do {
            i++;
        } while(a[i] < x);
        do {
            j--;
        } while(a[j] > x);
        if(i < j) {
            swap(a[i], a[j]);
        }
    }
    int sl = j - l + 1;
    if(k <= sl) {
        return solve(l, j, k);
    } else {
        return solve(j + 1, r, k - sl);
    }
}
int main(void) {
    IOS
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(0, n - 1, k) << endl;
    system("pause");
    return 0;
}
