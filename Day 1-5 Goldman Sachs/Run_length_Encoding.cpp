// Question Link - https: // practice.geeksforgeeks.org/problems/run-length-encoding/1/
string encode(string src)
{
    // Your code here
    char ch = src[0];
    int count = 1;
    string ans = "";
    for (int i = 1; i < src.length(); i++)
    {
        if (src[i] == ch)
        {
            count++;
        }
        else
        {
            ans += ch;
            ans += to_string(count);
            count = 1;
            ch = src[i];
        }
    }
    ans += ch;
    ans += to_string(count);
    return ans;
}