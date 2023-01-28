/**
* Copyright(c)
* All rights reserved.
* Author : tiketiskte
* Date : 2023-01-12-14.37.53
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
int n, q;
int arr[maxn];
void solve(int k) {
    int l = 0, r = n - 1;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(arr[mid] >= k) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if(arr[l] != k) { // 二分起始位置 若不存在答案 则二分结果为左边界
        cout << "-1 -1" << endl;
    } else {
        cout << l << " ";
        int l = 0, r = n - 1;
        while(l < r) {
            int mid = (l + r + 1) >> 1; //模板2
            if(arr[mid] <= k) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        cout << r << endl;
    }
}
int main(void) {
    IOS
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    while(q--) {
        int k;
        cin >> k;
        solve(k);
    }
    return 0;
}
