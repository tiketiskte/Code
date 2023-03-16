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
const int maxn =1e5 + 10;
int n, m, h[maxn], Size;
//小根堆
void down(int u) {
    int t = u; // t用来表示父节点和两个子结点中的最小结点
    if(2 * u <= Size && h[2 * u] < h[t]) {
        t = 2 * u;
    }
    if(2 * u + 1 <= Size && h[2 * u + 1] < h[t]) {
        t = 2 * u + 1;
    }
    if(u != t) {
        swap(h[u], h[t]);
        down(t);
    }
}
void up(int u) {
    while(u / 2 && h[u] < h[u / 2]) { // 迭代上移 直到根节点
        swap(h[u / 2], h[u]);
        u /= 2;
    }
} 
int main(void) {
    // IOS
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    Size = n;
    for(int i = n / 2; i > 0; i--) {
        down(i);
    }
    while(m--) {
        cout << h[1] << " ";
        h[1] = h[Size];
        Size--;
        down(1);
    }
    system("pause");
    return 0;
}