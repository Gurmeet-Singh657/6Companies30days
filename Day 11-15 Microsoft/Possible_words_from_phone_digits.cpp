// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<string> user = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    // Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        // Your code here
        return phone(a, N, 0);
    }
    vector<string> phone(int a[], int N, int k)
    {
        if (k == N)
        {
            vector<string> ans;
            ans.push_back("");
            return ans;
        }
        vector<string> final = phone(a, N, k + 1);
        vector<string> making;
        string ans = user[a[k]];
        for (int i = 0; i < ans.length(); i++)
        {
            for (int j = 0; j < final.size(); j++)
            {
                making.push_back(ans[i] + final[j]);
            }
        }
        return making;
    }
};

// { Driver Code Starts.

int main()
{

    int T;

    cin >> T; // testcases

    while (T--)
    { // while testcases exist
        int N;

        cin >> N; // input size of array

        int a[N]; // declare the array

        for (int i = 0; i < N; i++)
        {
            cin >> a[i]; // input the elements of array that are keys to be pressed
        }

        Solution obj;

        vector<string> res = obj.possibleWords(a, N);
        for (string i : res)
            cout << i << " ";
        cout << endl;
    }

    return 0;
} // } Driver Code Ends