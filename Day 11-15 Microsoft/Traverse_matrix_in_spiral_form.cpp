// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
    {
        vector<int> ans;
        // code here
        int cnt = 0;
        int tne = r * c;
        int minrow = 0, maxrow = r - 1, mincol = 0, maxcol = c - 1;
        while (cnt < tne)
        {
            for (int i = mincol; i <= maxcol && cnt < tne; i++)
            {
                ans.push_back(matrix[minrow][i]);
                cnt++;
            }
            minrow++;
            for (int i = minrow; i <= maxrow && cnt < tne; i++)
            {
                ans.push_back(matrix[i][maxcol]);
                cnt++;
            }
            maxcol--;
            for (int i = maxcol; i >= mincol && cnt < tne; i--)
            {
                ans.push_back(matrix[maxrow][i]);
                cnt++;
            }
            maxrow--;
            for (int i = maxrow; i >= minrow && cnt < tne; i--)
            {
                ans.push_back(matrix[i][mincol]);
                cnt++;
            }
            mincol++;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends