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

const int maxn_n = 1e5 + 10, maxn_m = 1e6 + 10;
int n, m, ne[maxn_n];
char p[maxn_n], s[maxn_m];
int main(void) {
    IOS
    cin >> n >> p + 1 >> m >> s + 1;
    // ne[1] = 0;
    for(int i = 2, j = 0; i <= m; i++) {
        while(j != 0 && p[i] != p[j + 1]) {
            j = ne[j];
        }
        if(p[i] == p[j + 1]) {
            j++;
        }
        ne[i] = j;
    }
    for(int i = 1, j = 0; i <= m; i++) {
        while(j != 0 && s[i] != p[j + 1]) {
            j = ne[j];
        }
        //如果j有对应p串的元素,且s[i] != p[j+1],则失配,移动p串
        //用while是由于移动后可能仍然失配,所以要继续移动直到匹配或整个p串移到后面(j = 0)
        if(s[i] == p[j + 1]) {
            j++;
        }
        if(j == n) {
            //print
            cout << i - n << " ";
            j = ne[j]; // 继续匹配下一个子串
        }
    }
    cout << endl;
    system("pause");
    return 0;
}