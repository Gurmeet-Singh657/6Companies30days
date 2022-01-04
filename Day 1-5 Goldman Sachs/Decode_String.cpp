// Question Link - https://practice.geeksforgeeks.org/problems/decode-the-string2444/1#
class Solution
{
public:
    string decodedstring(string s, int &i)
    {
        string result;
        while (i < s.length() && s[i] != ']')
        {
            if (isdigit(s[i]))
            {
                int digit = 0;
                while (i < s.length() && isdigit(s[i]))
                {
                    digit = digit * 10 + s[i] - '0';
                    i++;
                }
                i++; // for skipping '['
                string r = decodedstring(s, i);
                while (digit > 0)
                {
                    result += r;
                    digit--;
                }
                i++; // for skipping ']'
            }
            else
                result += s[i++];
        }
        return result;
    }
    string decodedString(string s)
    {
        // code here
        int i = 0;
        return decodedstring(s, i);
    }
};