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
#define SZ(X) (int)X.Size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
typedef long long ll;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <double, double> PDD;
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}
const int maxn = 1e5 + 10;
int n, m, p[maxn], Size[maxn], a, b; // p[x]表示x的父节点 Size[x]表示x所在集合的大小 注意只有根节点的Size有意义
string op;
int find(int x) { //返回x的祖宗结点 + 路径压缩
    return p[x] == x ? p[x] : p[x] = find(p[x]);
}
void unite(int a, int b) {
    Size[find(b)] += Size[find(a)]; // 先累加到树根节点上,再合并 合并后树根相同再累加逻辑错误
    p[find(a)] = find(b); 
}
void init(int n) {
    for(int i = 0; i <= n; i++) {
        p[i] = i; // 初始化时,每个元素都单独一个集合,其父节点编号为其本身
        Size[i] = 1; // 初始化时,每个集合只有一个元素
    }
}
int main(void) {
    IOS
    cin >> n >> m;
    init(n);
    while(m--) {
        cin >> op;
        if(op == "C") {
            cin >> a >> b;
            if(find(a) == find(b)) {
                continue;
            }
            unite(a, b);
        } else if(op == "Q1") {
            cin >>a >> b;
            if(find(a) == find(b)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else {
            cin >> a;
            cout << Size[find(a)] << endl;
        }
    }
    system("pause");
    return 0;
}