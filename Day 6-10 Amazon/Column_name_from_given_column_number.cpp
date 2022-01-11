class Solution
{
public:
    string colName(long long int n)
    {
        // your code here
        string ans = "";
        while (n > 0)
        {
            n--;
            int ans1 = n % 26;
            char ch = (char)(ans1 + 'A');
            ans = ch + ans;
            n = n / 26;
        }
        return ans;
    }
};