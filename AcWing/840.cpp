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
const int maxn = 2e5 + 10;
const int mod = 200003;
const int null = 0x3f3f3f3f; // 定义一个无穷大的数  
int n, x, h[2 * maxn];
int find(int x) {
    int k = (x % mod + mod) % mod; // +mod %mod使负数模数转为正数
    while(h[k] != null && h[k] != x) {
        k++;
        if(k == mod) {
            k = 0;
        }
    }
    return k;
    // 如果k在hash表中,则返回其下标;若k不在hash表中,返回k应该所处的位置
}
int main(void) {
    IOS
    char ch;
    memset(h, 0x3f, sizeof(h));
    cin >> n;
    while(n--) {
        cin >> ch >> x;
        int k = find(x);
        if(ch == 'I') {
            h[k] = x;
        } else {
            if(h[k] != null) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    system("pause");
    return 0;
}