/**
* Copyright(c)
* All rights reserved.
* Author : tiketiskte
* Date : 2023-01-07-09.35.10
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
void merge_sort(vector <int> &arr, int l, int r) {
    vector <int> tmp(maxn);
    if(l >= r) {
        return ;
    }
    int mid = (l + r) >> 1;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while(i <= mid && j <= r) {
        if(arr[i] <= arr[j]) {
            tmp[k++] = arr[i++];
        } else {
            tmp[k++] = arr[j++];
        }
    }
    while(i <= mid) {
        tmp[k++] = arr[i++];
    }
    while(j <= r) {
        tmp[k++] = arr[j++];
    }
    for(int i = l, cnt = 0; i <= r && cnt <= k; i++, cnt++) {
        arr[i] = tmp[cnt];
    }
}
int main(void) {
    IOS
    int n;
    vector <int> a(maxn);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    merge_sort(a, 0, n - 1);
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
