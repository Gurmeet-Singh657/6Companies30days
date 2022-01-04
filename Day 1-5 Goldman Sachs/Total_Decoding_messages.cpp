// Question Link - https://practice.geeksforgeeks.org/problems/total-decoding-messages1235/1/#

class Solution
{
public:
    int CountWays(string str)
    {
        // Code here
        if (str.length() == 0 || str[0] == '0')
            return 0;
        int dp[str.length()];
        dp[0] = 1;
        for (int i = 1; i < str.length(); i++)
        {
            if (str[i] == '0' && str[i - 1] == '0')
            {
                dp[i] = 0;
            }
            else if (str[i] == '0' && str[i - 1] != '0')
            {
                if (str[i - 1] == '1' || str[i - 1] == '2')
                    dp[i] = (i >= 2 ? dp[i - 2] : 1) % 1000000007;
                else
                    dp[i] = 0;
            }
            else if (str[i] != '0' && str[i - 1] == '0')
            {
                dp[i] = dp[i - 1] % 1000000007;
            }
            else
            {
                if (stoi(str.substr(i - 1, 2)) <= 26)
                    dp[i] = (dp[i - 1] + (i >= 2 ? dp[i - 2] : 1)) % 1000000007;
                else
                    dp[i] = dp[i - 1] % 1000000007;
            }
        }
        return dp[str.length() - 1];
    }
};