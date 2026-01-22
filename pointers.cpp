#include <iostream>
using namespace std;
void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // int x = 10, y = 50;
    // int *p = &x;
    // int **pp = &p;
    // cout << x << " " << y << endl;
    // x = 15;
    // cout << x << " " << y << endl;
    // *p = 20;
    // cout << x << " " << y << endl;
    // **pp = 25;
    // cout << x << " " << y << endl;
    // p = &y;
    // cout << x << " " << y << endl;
    // *p = 55;
    // cout << x << " " << y << endl;
    // **pp = 60;
    // cout << x << " " << y << endl;
    // (*p)++;

    // cout << x << " " << y << endl;
    // (**pp)--;
    // cout << x << " " << y << endl;
    // p--;
    // cout << p << " " << *p << endl;

    // cout << x << " " << y << endl;
    // *pp = &x;

    // cout << x << " " << y << endl;
    // x = x + **pp + *p;
    // cout << x << " " << y << endl;
    int arr[5] = {1, 2, 3, 4, 5};
    cout << arr << endl;
    cout << &arr[0] << endl;
    cout << (*arr)++;
    print(arr, 5);
    cout << *(arr + 4) << endl;
    print(arr, 5);
    cout << *(arr) * *(arr + 3) << endl;
    print(arr, 5);
    cout << ((*(arr + 1))-- + *(arr) * *(arr) ^ 5) << endl;
    // *(arr + 1)-- gives error (read Lvalues and Rvalues)

    return 0;
}