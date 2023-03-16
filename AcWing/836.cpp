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
const int maxn = 1e5 + 10;
int n, m, p[maxn], a, b;
char op;
int find(int x) { //返回x的祖宗结点 + 路径压缩
    if(p[x] != x) {
        p[x] = find(p[x]);
    }
    return p[x];
    // 压缩写法:return p[x] == x ? p[x] : p[x] = find(p[x]);
}
void init(int n) {
    for(int i = 0; i <= n; i++) {
        p[i] = i; // 初始化时,每个元素都单独一个集合,其父节点编号为其本身
    }
}
int main(void) {
    IOS
    cin >> n >> m;
    init(n);
    while(m--) {
        cin >> op >> a >> b;
        if(op == 'M') {
            p[find(a)] = find(b); 
        } else {
            if(find(a) == find(b)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    system("pause");
    return 0;
}