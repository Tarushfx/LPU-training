#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int a, b;
    cin >> a >> b;
    cout << (a & b) << endl;  // AND
    cout << (a | b) << endl;  // OR
    cout << (a ^ b) << endl;  // XOR
    cout << (~a) << endl;     // NOT
    cout << (a << 2) << endl; // LEFT SHIFT
    cout << (a >> 3) << endl; // RIGHT SHIFT
}