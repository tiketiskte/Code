#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;
int n, a[maxn];
queue<int> q1, q2; // q1 A q2 B
int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        if(a[i] % 2) {
            q1.push(a[i]);
        } else {
            q2.push(a[i]);
        }
    }
    int b[maxn], cnt = 0;
    while(!q1.empty() && !q2.empty()) {
            b[cnt++] = q1.front();
            q1.pop();
            if(!q1.empty()) {
                b[cnt++] = q1.front();
                q1.pop();
            }
            b[cnt++] = q2.front();
            q2.pop();
            
    }
    while(!q1.empty()) {
        b[cnt++] = q1.front();
        q1.pop();
    }
    while(!q2.empty()) {
        b[cnt++] = q2.front();
        q2.pop();
    }
    for(int i = 0; i < n - 1; i++) {
        cout << b[i] << " ";
    }
    cout << b[n - 1] << endl;
    system("pause");
    return 0;
}