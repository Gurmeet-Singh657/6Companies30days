// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int k)
    {
        // Your code goes here
        int n = arr.size();
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && arr[i] == arr[i - 1])
                continue;
            for (int j = i + 1; j < n - 2; j++)
            {
                if (j > i + 1 && arr[j] == arr[j - 1])
                    continue;
                int low = j + 1;
                int high = n - 1;
                while (low < high)
                {
                    int sum = arr[i] + arr[j] + arr[low] + arr[high];
                    if (sum == k)
                    {
                        res.push_back({arr[i], arr[j], arr[low], arr[high]});
                        low++;
                        high--;
                        while (low < high && arr[low] == arr[low - 1])
                            low++;
                        while (high > low && arr[high] == arr[high + 1])
                            high--;
                    }
                    if (sum < k)
                    {
                        low++;
                    }
                    else if (sum > k)
                    {
                        high--;
                    }
                }
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int>> ans = ob.fourSum(a, k);
        for (auto &v : ans)
        {
            for (int &u : v)
            {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty())
        {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends