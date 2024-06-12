#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Matrix
{
public:
    vector<vector<int>> a;
    void operator=(vector<vector<int>> matrixa)
    {
        this->a = matrixa;
    }
};

vector<vector<int>> operator+(Matrix& M1, Matrix& M2)
{
    vector<vector<int>> retVal;
    vector<vector<int>>::iterator iter1 = M1.a.begin();
    vector<vector<int>>::iterator iter2 = M2.a.begin();
    vector<int>::iterator aiter1;
    vector<int>::iterator aiter2;
    while (iter1 != M1.a.end() && iter2 != M2.a.end()) {
        aiter1 = iter1->begin();
        aiter2 = iter2->begin();
        vector<int> sum;
		// 2d matrix
        while (aiter1 != iter1->end() && aiter2 != iter2->end())
        {
            sum.push_back(*aiter1 + *aiter2);
            aiter1++;
            aiter2++;
        }
        retVal.push_back(sum);
        iter1++;
        iter2++;
    }

    return retVal;
}

int main() {
    int cases, k;
    cin >> cases;
    for (k = 0; k < cases; k++) {
        Matrix x;
        Matrix y;
        Matrix result;
        int n, m, i, j;
        cin >> n >> m;
        for (i = 0; i < n; i++) {
            vector<int> b;
            int num;
            for (j = 0; j < m; j++) {
                cin >> num;
                b.push_back(num);
            }
            x.a.push_back(b);
        }
        for (i = 0; i < n; i++) {
            vector<int> b;
            int num;
            for (j = 0; j < m; j++) {
                cin >> num;
                b.push_back(num);
            }
            y.a.push_back(b);
        }
        x + y;
        result = x + y;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cout << result.a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
