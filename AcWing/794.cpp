/**
* Copyright(c)
* All rights reserved.
* Author : tiketiskte
* Date : 2023-01-13-10.52.12
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
// A / b  商为C 余数为r
vector<int> div(vector<int> &A, int b, int &r) {  //r作为余数
    vector<int> C;
    for(int i = A.size() - 1; i >= 0; i--) {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
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
    int r = 0;
    vector<int> C = div(A, b, r);
    for(int i = C.size() - 1; i >= 0; i--) {
        cout << C[i];
    }
    cout << endl << r << endl;
    return 0;
}
