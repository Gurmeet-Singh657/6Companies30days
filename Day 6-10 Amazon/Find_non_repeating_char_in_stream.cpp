class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        // Code here
        string ans = "";
        vector<char> v;
        vector<int> visited(26, 0);
        for (int i = 0; i < A.length(); i++)
        {
            if (!visited[A[i] - 'a'])
            {
                v.push_back(A[i]);
            }
            visited[A[i] - 'a']++;
            int m = v.size();
            bool flag = false;
            for (int j = 0; j < m; j++)
            {
                if (visited[v[j] - 'a'] == 1)
                {
                    ans += v[j];
                    flag = true;
                    break;
                }
            }
            if (!flag)
                ans += '#';
        }
        return ans;
    }
};