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
const int maxn = 3e5 + 10;
int n, m;
int a[maxn], s[maxn]; //a存想象的坐标所对应的值,s存想象的坐标所对应的值的前缀和
vector<int> alls; //alls存真实的下标和想象的下标的映射关系
vector<PII> add, query; //add存真实的下标和想象的下标的映射关系,query存真实查询的左右两个端点
int find(int x) {
    int l = 0, r = alls.size() - 1;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(alls[mid] >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return r + 1;
}
int main(void) {
    IOS
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    for(auto item : add) {
        int x = find(item.first);
        a[x] += item.second;
    }
    for (int i = 1; i <= (int)alls.size(); i++) {
        s[i] = s[i - 1] + a[i];
    }
    for(auto item : query) {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }
    system("pause");
    return 0;
}