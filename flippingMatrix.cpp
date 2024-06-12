#include <iostream>
#include <vector>

using namespace std;


/*
 * Complete the 'flippingMatrix' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY matrix as parameter.
 */

int flippingMatrix(vector<vector<int>> matrix)
{
    const int n = matrix.size() / 2, endIndex = matrix.size () - 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            int tempMax1 = max(matrix[i][j], matrix[endIndex - i][j]);
            int tempMax2 = max(matrix[i][endIndex - j], matrix[endIndex - i][endIndex - j]);
            sum += max(tempMax1, tempMax2);
        }
    }
    return sum;
}