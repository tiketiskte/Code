#include <bits/stdc++.h>

using namespace std;
stack<int> s;
int n, x;
int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        cout << "##" << s.top() << "##" << endl;
        while(!s.empty() && s.top() >= x) {
            s.pop();
        }
        if(!s.empty()) {
            cout << s.top() << " ";
        } else {
            cout << -1 << " ";
        }
        s.push(x);
    }
    system("pause");
    return 0;
}