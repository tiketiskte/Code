/**
* Copyright(c)
* All rights reserved.
* Author : tiketiskte
* Date : 2023-01-12-15.24.50
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
void solve() {

}
int main(void) {
    IOS
    double n;
    cin >> n;
    double l = -10000.00, r = 10000.00;
    //考虑二次方根,若0.01,则l = 0 r = 0.01 但答案为0.1 不在l~r区间内
    // 因此将区间设置为整个区间 保证答案在区间内
    // 另一种处理方式 将边界取max
    /*
    if(n < 0) { // neg
        swap(l, r);
    }
    if(n > -1 && n < 1) { // 特判
        l = -1, r = 1;
    }
    */
    const double eps = 1e-8;
    while(r - l > eps) {
        double mid = (l + r) / 2;
        if((mid * mid *mid) >= n) {
            r = mid;
        } else {
            l = mid;
        }
    }
    printf("%.6f\n", l);
    system("pause");
    return 0;
}
