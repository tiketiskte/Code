/**
* Copyright(c)
* All rights reserved.
* Author : tiketiskte
* Date : 2023-01-12-18.08.49
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
const int maxn = 1000000 + 5;
//C = A + B  &使得不需要复制数组
vector<int> add(vector<int> &A, vector<int> &B) {
    vector<int> C;
    int t = 0; // 进位
    for(int i = 0; i < A.size() || i < B.size(); i++) {
        if(i < A.size()) {
            t += A[i];
        }
        if(i < B.size()) {
            t += B[i];
        }
        C.push_back(t%10);
        t /= 10;
    }
    if(t) { // 最高位存在进位
        C.push_back(1);
    }
    return C;
}
int main(void) {
    IOS
    vector<int> A, B;
    string a, b;
    cin >> a >> b; // a = "123456"
    for(int i = a.size() - 1; i >= 0; i--) {
        A.push_back(a[i] - '0');
    } // A = [6, 5, 4, 3, 2, 1]
    for(int i = b.size() - 1; i >= 0; i--) {
        B.push_back(b[i] - '0');
    }
    vector<int> ans = add(A, B);
    for(int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
