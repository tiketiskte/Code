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

const int maxn = 1e6 + 10;
int n, k, a[maxn];
int main(void) {
    IOS
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    deque<int> dq;
    for(int i = 0; i < n; i++) {
        while(!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }
        while(!dq.empty() && a[dq.back()] >= a[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if(i >= k - 1) {
            cout << a[dq.front()] << " ";
        }
    }
    cout << endl;
    dq.clear();
    for(int i = 0; i < n; i++) {
        while(!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }
        while(!dq.empty() && a[dq.back()] <= a[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if(i >= k - 1) {
            cout << a[dq.front()] << " ";
        }
    }
    cout << endl;
    system("pause");
    return 0;
}