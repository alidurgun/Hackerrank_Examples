#include <iostream>
#include <sstream>
using namespace std;

class Box {
private:
    int l; // length
    int b; // breadth 
    int h; // height
public:
    Box()
    {
        this->l = 0;
        this->b = 0;
        this->h = 0;
    }
    Box(int length, int breadth, int height) : l(length), b(breadth), h(height)
    {
    }
    Box(Box& B)
    {
        this->l = B.l;
        this->b = B.b;
        this->h = B.h;
    }
    int getLength()
    {
        return this->l;
    }
    int getBreadth()
    {
        return this->b;
    }
    int getHeight()
    {
        return this->h;
    }
    long long CalculateVolume()
    {
        return static_cast<long long>(this->l) * this->b * this->h;
    }
};

bool operator<(Box& A, Box& B)
{
    if (A.getLength() != B.getLength())
        return A.getLength() < B.getLength();
    if (A.getBreadth() != B.getBreadth())
        return A.getBreadth() < B.getBreadth();
    return A.getHeight() < B.getHeight();
}
ostream& operator<<(ostream& out, Box& B)
{
    out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
    return out;
}