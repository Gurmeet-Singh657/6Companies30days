// Question link - https://www.geeksforgeeks.org/distributing-m-items-circle-size-n-starting-k-th-position/

class Solution
{
public:
    int findmthitempersion(int n, int m, int k)
    {
        m = m % n;
        return (m + k - 1);
    }
    int main()
    {
        int n; // Size of Circle
        int m; // No. of items
        int k; // Starting position
        cout << findmthitemperson(n, m, k) << endl;
    }
};