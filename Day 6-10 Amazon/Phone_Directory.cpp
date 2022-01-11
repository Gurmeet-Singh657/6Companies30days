class Solution
{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        vector<vector<string>> result(s.size());
        vector<string> ans;
        for (int i = 0; i < n; i++)
        {
            ans.push_back(contact[i]);
        }
        sort(ans.begin(), ans.end());
        for (int i = 0; i < s.size(); i++)
        {
            unordered_set<string> set;
            for (string it : ans)
            {
                if (set.find(it) == set.end() && s.substr(0, i + 1) == it.substr(0, i + 1))
                {
                    result[i].push_back(it);
                }
                set.insert(it);
            }
            if (result[i].empty())
            {
                result[i].push_back(to_string(0));
            }
        }
        return result;
    }
};