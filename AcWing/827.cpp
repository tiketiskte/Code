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

const int maxn = 100000 + 10;
int e[maxn], l[maxn], r[maxn], idx;
void init() {
    r[0] = 1, l[1] = 0, idx = 2;
}
void add(int k, int x) {
    e[idx] = x, r[idx] = r[k], l[idx] = k, l[r[k]] = idx, r[k] = idx, idx++;
}
void remove(int k) {
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}
int main(void) {
    IOS
    int m, x, k;
    string ch;
    init();
    cin >> m;
    while(m--) {
        cin >> ch;
        if(ch == "L") {
            cin >> x;
            add(0, x);
        } else if(ch == "R") {
            cin >> x;
            add(l[1], x);
        } else if(ch == "D") {
            cin >> k;
            remove(k + 1);
        } else if (ch == "IL") {
            cin >> k >> x;
            add(l[k + 1], x); //第k个插入的数 idx为 k + 1 在前面插add(l[k + 1], x)
        } else {
            cin >> k >> x;
            add(k + 1, x); //第k个插入的数 idx为 k + 1 在后面插add(k + 1, x)
        }
    }
    for (int i = r[0]; i != 1; i = r[i]) {
        cout << e[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}