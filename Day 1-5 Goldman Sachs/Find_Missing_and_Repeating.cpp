// Question Link- https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/#
class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        // code here
        int *ans = new int[2];
        // Repeating element
        for (int i = 0; i < n; i++)
        {
            // if element is not visited
            if (arr[abs(arr[i]) - 1] > 0)
            {
                arr[abs(arr[i]) - 1] = -1 * arr[abs(arr[i]) - 1];
            }
            // if element found is already negative this means that element is already visited
            else
            {
                ans[0] = abs(arr[i]);
            }
        }
        // Missing element
        for (int i = 0; i < n; i++)
        {
            // This means that index is not visited
            if (arr[i] > 0)
            {
                ans[1] = i + 1;
                break;
            }
        }
        return ans;
    }
};