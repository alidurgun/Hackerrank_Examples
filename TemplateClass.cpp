#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

template <class T>
class AddElements {
    T element;
public:
    AddElements(T elem)
    {
        element = elem;
    }

    T add(T secondElem)
    {
        return element + secondElem;
    }

    T concatenate(T elem)
    {
        return element + elem;
    }
};

class Integer {
private:
    int* mp;
public:
    Integer(int* a) : mp(a) {}
    // pre inc
    Integer& operator++()
    {
        ++(*mp);
        return *this;
    }
    // post inc
    Integer operator++(int)
    {
        Integer temp(*this);
        ++(*mp);
        return temp;
    }
};

template <typename T>
T Add(T x, T y) {
    return x + y;
}
template <typename T, typename S>
T ArraySum(T* pArr, S arrSize)
{
    T sum = 0;
    for (int i = 0; i < arrSize; i++) {
        sum += pArr[i];
    }
    return sum;
}
template <typename T, typename S>
T Max(T* pArr, S arrSize)
{
    return std::max_element(pArr, pArr + arrSize);
}
template <typename T, typename S>
std::pair<T, T> MinMax(T* pArr, S arrSize)
{
    return std::minmax_element(pArr, pArr+arrSize);
}
