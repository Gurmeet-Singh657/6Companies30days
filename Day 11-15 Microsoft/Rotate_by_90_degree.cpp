// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>> &matrix);

// } Driver Code Ends
// User function template for C++

/* matrix : given input matrix, you are require
 to change it in place without using extra space */
void rotate(vector<vector<int>> &matrix)
{
    // Getting transpose of matrix
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = i; j < matrix.size(); j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    // Reverse column one by one
    for (int i = 0; i < matrix.size(); i++)
    {
        int start = 0;
        int end = matrix.size() - 1;
        while (start <= end)
        {
            swap(matrix[start][i], matrix[end][i]);
            start++;
            end--;
        }
    }
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n);
        for (int i = 0; i < n; i++)
        {
            matrix[i].resize(n);
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; j++)
                cout << matrix[i][j] << " ";
            cout << "\n";
        }
    }
    return 0;
}

// } Driver Code Ends