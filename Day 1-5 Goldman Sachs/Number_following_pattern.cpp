// Question Link -https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1#
class Solution
{
public:
    string printMinNumberForPattern(string S)
    {
        // code here
        int arr[S.length() + 1];
        int count = 1;
        for (int i = 0; i <= S.length(); i++)
        {
            if (i == S.length() || S[i] == 'I')
            {
                arr[i] = count;
                count++;
                for (int j = i - 1; j >= 0 && S[j] == 'D'; j--)
                {
                    arr[j] = count;
                    count++;
                }
            }
        }
        string ans = "";
        for (int i = 0; i <= S.length(); i++)
            ans += (arr[i] + 48);
        return ans;
    }
};