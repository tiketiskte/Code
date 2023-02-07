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
int n, l, r;
vector<PII> segs;
void merge(vector<PII> &segs) {
    vector<PII> res;
    sort(segs.begin(), segs.end());
    int st = -2e9, ed = -2e9; //左右端点初始化负无穷
    for(auto seg : segs) {
        if(ed < seg.first) {
            if(st != -2e9) { //初始区间跳过 不能装入
                res.push_back({st, ed});
            }
            st = seg.first, ed = seg.second;
        } else {
            ed = max(ed, seg.second);
        }
    }
    //1:防止n为0，把[-无穷，-无穷]压入,若n>=1，if可以不要
    //2.压入最后一个（也就是当前）的区间
    if(st != -2e9) {
        res.push_back({st, ed});
    }
    segs = res;
}
int main(void) {
    IOS
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> l >> r;
        segs.push_back({l, r});
    }
    merge(segs);
    cout << segs.size() << endl;
    system("pause");
    return 0;
}