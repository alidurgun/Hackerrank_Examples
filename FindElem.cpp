#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int counter;
    vector<long long> numbers;
    int operationNumber;
    long long number;
    cin >> counter;
    for (int i = 0; i < counter; i++)
    {
        cin >> number;
        numbers.push_back(number);
    }
    cin >> operationNumber;
    for (int i = 0; i < operationNumber; i++)
    {
        cin >> number;
        std::vector<long long>::iterator low;
        low = std::lower_bound(numbers.begin(), numbers.end(), number);
        auto index = (low - numbers.begin());
        if (numbers.at(index) == number)
        {
            cout << "Yes " << index + 1 << endl;
        }
        else
        {
            cout << "No " << index + 1 << endl;
        }
    }
    return 0;
}
