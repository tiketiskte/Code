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

const int maxn = 100000 + 10;
//head表示头结点的下标
//e[i]表示结点i的值 ne[i]表示结点i的next指针是多少
//idx存储当前已经用到了哪个点
int head, e[maxn], ne[maxn], idx;
void init() { //初始化
    head = -1; //-1表示空链表
    idx = 0;
}
void add_to_head(int x) { //将x插到头结点
    e[idx] = x, ne[idx] = head, head = idx, idx++;
}
void add(int k, int x) { //将x插到下标为k的结点后
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx, idx++;
}
void remove(int k) { //将下标是k的结点后面的结点删除
    ne[k] = ne[ne[k]];
}
int main(void) {
    IOS
    char op;
    int m, k, x;
    init();
    cin >> m;
    while(m--) {
        cin >> op;
        if(op == 'H') {
            cin >> x;
            add_to_head(x);
        } else if(op == 'D') {
            cin >> k;
            if(k == 0) { //特判删除k=0时,删除头结点(即head指向的结点,令head指向头结点的下一个结点)
                head = ne[head];
            }
            remove(k - 1);
        } else {
            cin >> k >> x;
            add(k - 1, x);
        }
    }
    for (int i = head; i != -1; i = ne[i]){
        cout << e[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}