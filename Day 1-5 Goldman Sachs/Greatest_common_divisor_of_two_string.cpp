// Question Link - https://leetcode.com/problems/greatest-common-divisor-of-strings/submissions/

class Solution
{
public:
    int gcd(int a, int b)
    {

        while (a % b != 0)
        {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return b;
    }
    string gcdOfStrings(string str1, string str2)
    {
        if (str1 + str2 == str2 + str1)
            return str1.substr(0, gcd(str1.length(), str2.length()));
        else
            return "";
    }
};