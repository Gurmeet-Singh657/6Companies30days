// Question link - https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/
int countSubArrayProductLessThanK(const vector<int> &arr, int n, long long k)
{
    int start = 0, end = 0;
    long long product = 1;
    int count = 0;
    while (end < arr.size())
    {
        product *= arr[end];
        while (product >= k)
        {
            product /= arr[start];
            start++;
        }
        count += end - start + 1;
        end++;
    }
    return count;
}