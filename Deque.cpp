#include <iostream>
#include <deque> 
#include <algorithm>
using namespace std;

void printKMax(int arr[], int n, int k) {
    deque<int> subArray;
    int counter = 0;
    for (int i = 0; i < k; i++)
    {
        //create initial deque with size of k.
        subArray.push_back(arr[i]);
    }

    // find the max element inside of the deque.
    deque<int>::iterator maxNum = std::max_element(subArray.begin(), subArray.end());
    cout << *maxNum << " ";
    int maxint = *maxNum;
    while (k + counter < n) {
        int temp = *subArray.begin(); // to keep first element in the deque.
        subArray.pop_front(); // first element should be removed.
        subArray.push_back(arr[k + counter]); // new element should be added.
        if (maxint != temp) // if max element is not first element
        {
            if (arr[k + counter] > maxint) // just check with incoming element.
            {
                maxint = arr[k + counter];
            }
        }
        else
        {
            // if we remove the previous max element we have to find it again.
            maxNum = std::max_element(subArray.begin(), subArray.end());
            maxint = *maxNum;
        }
        cout << maxint << " ";
        counter++;
    }
    cout << endl;
}