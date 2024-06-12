#include <string>
#include <iostream>

using namespace std;

int superDigit(string n, int k) {
    int sum = 0;
    for (int i = 0; i < n.length(); i++)
    {
        sum += (n[i] - '0');
        if (sum > 9)
        {
            int temp = sum / 10;
            sum %= 10;
            sum += temp;
        }
    }
    sum *= k;
    while (sum > 9)
    {
        int temp = sum / 10;
        sum %= 10;
        sum += temp;
    }
    return sum;
}