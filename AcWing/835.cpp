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
int son[maxn][26], cnt[maxn], idx;
// son存Trie树中所有节点的儿子 cnt存Trie树中以当前结点为结尾的单词个数 idx存当前用到的结点下标
// 下标为0的点既是根节点,又是空结点
void insert(char str[]) {
    int p =  0;
    for(int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if(!son[p][u]) {
            son[p][u] = ++idx;
        }
        p = son[p][u];
    }
    cnt[p]++;
}
int query(char str[]) {
    int p =  0;
    for(int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if(!son[p][u]) {
            return 0;
        }
        p = son[p][u];
    }
    return cnt[p];
}
int main(void) {
    IOS

    system("pause");
    return 0;
}