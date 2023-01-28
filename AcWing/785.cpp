/**
* Copyright(c)
* All rights reserved.
* Author : tiketiskte
* Date : 2023-01-06-22.59.02
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
void quick_sort(vector <int> &arr, int l, int r) {
    if(l >= r) {
        return;
    }
    int x = arr[(l + r) >> 1], i = l - 1, j = r + 1;
    while(i < j) {
        do {
            i++;
        } while(arr[i] < x);
        do {
            j--;
        } while(arr[j] > x);
        if(i < j) {
            swap(arr[i], arr[j]);
        }
    }
    quick_sort(arr, l, j);
    quick_sort(arr, j + 1, r);
}
int main(void) {
    IOS
    int n;
    cin >> n;
    vector <int> a(maxn);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    quick_sort(a, 0, n - 1);
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
