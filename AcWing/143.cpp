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
int n, a[maxn], son[31 * maxn][2], idx; // 可能有31 * 1e5 个结点(存储每一个bit位)
void insert(int x) {
    int p = 0;
    for(int i = 30; i >= 0; i--) {
        int u = (x >> i) & 1; 
        if(!son[p][u]) {
            son[p][u] = ++idx;
        }
        p = son[p][u];
    }
}
int query(int x) {
    int p = 0, res = 0;
    // res用来记录从根节点到叶结点表示的数
    for(int i = 30; i >= 0; i--) { // 从最高位(第30位)一直到最低位(第0位)
        int u = (x >> i) & 1;
        if(son[p][!u]) {
            p = son[p][!u];
            res = (res << 1) + (!u);
        } else {
            p = son[p][u];
            res = (res << 1) + u;
        }
    }
    return res;
}
int main(void) {
    IOS
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++){ // 处理边界,先插入再查询 起初为空树
        insert(a[i]);
        int tmp = query(a[i]);
        ans = max(ans, a[i] ^ tmp);
    }
    cout << ans << endl;
    system("pause");
    return 0;
}