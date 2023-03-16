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
int n, k, x, h[maxn], ph[maxn], hp[maxn], Size;
string str;
//小根堆
void heap_swap(int a, int b) {
    swap(h[a], h[b]);
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
}
void down(int u) {
    int t = u; // t用来表示父节点和两个子结点中的最小结点
    if(2 * u <= Size && h[2 * u] < h[t]) {
        t = 2 * u;
    }
    if(2 * u + 1 <= Size && h[2 * u + 1] < h[t]) {
        t = 2 * u + 1;
    }
    if(u != t) {
        heap_swap(u, t);
        down(t);
    }
}
void up(int u) {
    while(u / 2 && h[u] < h[u / 2]) { // 迭代上移 直到根节点
        heap_swap(u / 2, u);
        u /= 2;
    }
}
int main(void) {
    // IOS
    int m = 0; // 记录当前第几个插入的数
    cin >> n;
    while(n--) {
        cin >> str;
        if(str == "I") {
            cin >> x;
            Size++;
            h[Size] = x;
            m++;
            ph[m] = Size;
            hp[Size] = m;
            up(Size);
        } else if(str == "PM") {
            cout << h[1] << endl;
        } else if(str == "DM") {
            heap_swap(1, Size);
            Size--;
            down(1);
        } else if(str == "D") {
            cin >> k;
            k = ph[k];
            heap_swap(k, Size);
            Size--;
            up(k), down(k);
        } else {
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            up(k), down(k);
        }
    }
    system("pause");
    return 0;
}