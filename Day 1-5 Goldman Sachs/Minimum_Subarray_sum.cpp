// Question Link - https://leetcode.com/problems/minimum-size-subarray-sum/submissions/

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int end = 0;
        int sum = 0;
        int start = 0;
        int minlen = INT_MAX;
        while (end < nums.size())
        {
            sum += nums[end];
            if (sum >= target)
            {

                while (sum >= target)
                {
                    minlen = min(end - start + 1, minlen);
                    sum -= nums[start];
                    start++;
                }
            }
            end++;
        }
        if (minlen == INT_MAX)
            return 0;
        else
            return minlen;
    }
};