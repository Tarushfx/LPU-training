#include <bits/stdc++.h>
using namespace std;

void abc(char s[])
{
    if (s[0] == '\0')
        return;

    abc(s + 1);
    abc(s + 1);
    cout << s[0];
}

int fun(int count)
{
    cout << count << endl;
    if (count < 3)
    {
        fun(fun(fun(++count)));
    }
    return count;
}
int main()
{
    abc("xyz");
    fun(1);
    return 0;
}