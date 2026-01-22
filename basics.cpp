
#include <iostream>
// /preprocessing directives
using namespace std;
// /namespace resolution
int x = 1;
int temp()
{
    int y = 9;
    return 0;
}
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    double avg = (double)(a + b + c) / 3; // double int
    cout << avg;
    temp();
    return 0;
}

// machine code 111000101010 lowest
// assembly
//     INC 10101
// cpp
// python highest

// q1 input 3 marks and find avg
// q2 is a triangle valid;
