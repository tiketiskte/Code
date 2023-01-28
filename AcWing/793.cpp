/**
* Copyright(c)
* All rights reserved.
* Author : tiketiskte
* Date : 2023-01-12-22.02.05
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
vector<int> mul(vector<int> &A, int b) {
    vector<int> C;
    int t = 0; //进位
    for(int i = 0; i < A.size() || t; i++) {
        if(i < A.size()) {
            t += A[i] * b;
        }
        C.push_back(t%10);
        t /= 10;
    }
    while(C.size() > 1 && C.back() == 0) {
        C.pop_back();
    }
    return C;
}
int main(void) {
    IOS
    string a;
    int b;
    vector<int> A;
    cin >> a >> b;
    for(int i = a.size() - 1; i >= 0; i--) {
        A.push_back(a[i] - '0');
    }
    vector<int> C = mul(A, b);
    for(int i = C.size() - 1; i >= 0; i--) {
        cout << C[i];
    }
    cout << endl;
    return 0;
}
