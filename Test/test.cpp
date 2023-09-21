#include <bits/stdc++.h>

using namespace std;
const int maxn = 100000 + 10;
int n, k, a[maxn];
int solve(int l, int r, int k) {
    if(l == r) {
        return a[l];
    }
    int i = l - 1, j = r + 1, mid = a[(l + r) >> 1];
    while(i < j) {
        do {
            i++;
        } while(a[i] < mid);
        do {
            j--;
        } while(a[j] > mid);
        if(a[i] < a[j]) {
            swap(a[i], a[j]);
        }
    }
    int s_l = j - l + 1;
    if(k <= s_l) {
        return solve(l, j, k);
    } else {
        return solve(j + 1, r, k - s_l);
    }
}
int main(void) {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(0, n - 1, k) << endl;
    system("pause");
    return 0;
}