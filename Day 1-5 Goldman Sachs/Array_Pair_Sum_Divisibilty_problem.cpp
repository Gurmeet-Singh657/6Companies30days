// Question Link - https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1#
class Solution
{
public:
    bool canPair(vector<int> nums, int k)
    {
        // Code here.
        if (nums.size() % 2 != 0)
            return false;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i] % k]++;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int rem = nums[i] % k;
            if (rem == 0)
            {
                if (map[rem] % 2 != 0)
                    return false;
            }
            else
            {
                int target = k - (nums[i] % k);
                if (rem == target && map[rem] % 2 != 0 || map.find(target) == map.end() || map[target] != map[rem])
                {
                    return false;
                }
            }
        }
        return true;
    }
};