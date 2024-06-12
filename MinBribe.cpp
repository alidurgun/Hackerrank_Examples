#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void minimumBribes(vector<int> q) {
    vector<int> bribes(q.size() + 1, 0);
    while (!is_sorted(q.begin(), q.end()))
    {
        for (int i = 0; i < q.size() - 1; i++)
        {
            if (q[i] > q[i + 1])
            {
                bribes[q[i]]++;
				// if move greater than 2 it's too chaotic.
                if (bribes[q[i]] > 2)
                {
                    cout << "Too chaotic" << endl;
                    return;
                }
                int temp = q[i];
                q[i] = q[i + 1];
                q[i + 1] = temp;
            }
        }
    }

    int total = 0;
    vector<int>::iterator iter;
    for (iter = bribes.begin(); iter != bribes.end(); iter++)
    {
        total += (*iter);
    }
    cout << total << endl;
}