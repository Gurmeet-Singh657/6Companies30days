class Solution
{
public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        deque<int> dq;
        vector<int> val;
        for (int i = 0; i < k; i++)
        {
            while (!dq.empty() && arr[i] >= arr[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        for (int i = k; i < n; i++)
        {
            val.push_back(arr[dq.front()]);
            if (dq.front() == i - k)
                dq.pop_front();

            while (!dq.empty() && arr[i] >= arr[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        val.push_back(arr[dq.front()]);
        return val;
    }
};