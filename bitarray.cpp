#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;


int main() {
    int N, S, P, Q;
    cin >> N >> S >> P >> Q;
    vector<int> myVector(N);
    int lastElem = S % INT_MAX;
    myVector[0] = lastElem;
    for (int i = 1; i < N; i++) {
        // because of the some overflow numbers I have used bit comp in here.
        lastElem = (lastElem * P + Q) & INT_MAX;
        myVector[i] = lastElem;
    }
    auto it = std::unique(myVector.begin(), myVector.end());
    std::cout << std::distance(myVector.begin(), it);
    return 0;
}