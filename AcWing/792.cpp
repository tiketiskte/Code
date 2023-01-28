/**
* Copyright(c)
* All rights reserved.
* Author : tiketiskte
* Date : 2023-01-12-20.51.20
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
bool cmp(vector<int> &A, vector<int> & B) { //A >= B -> True
    if(A.size() != B.size()) {
        return A.size() > B.size();
    }
    for(int i = A.size() - 1; i >= 0; i--) {
        if(A[i] != B[i]) {
            return A[i] > B[i];
        }
    }
    return true;
}
// C = A - B
vector<int> sub(vector<int> &A, vector<int> &B) {
    vector<int> C;
    for(int i = 0, t = 0; i < A.size(); i++) {
        t = A[i] - t;
        if(i < B.size()) {
            t -= B[i];
        }
        // t>=0 -> t t < 0 -> t + 10
        C.push_back((t + 10) % 10);
        if(t < 0) {
            t = 1;
        } else {
            t = 0;
        }
    }
    //去除前导零
    while(C.size() > 1 && C.back() == 0) {
        C.pop_back();
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
    if(cmp(A, B)) {
        vector<int> ans = sub(A, B);
        for(int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i];
        }
        cout << endl;
    } else {
        vector<int> ans = sub(B, A);
        cout << "-";
        for(int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
