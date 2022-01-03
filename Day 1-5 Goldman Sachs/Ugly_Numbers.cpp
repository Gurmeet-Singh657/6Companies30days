// Question Link - https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1/#

#define ull unsigned long long
ull getNthUglyNo(int n)
{
    // code here
    ull arr[n];
    arr[0] = 1;
    ull pointer1 = 0, pointer2 = 0, pointer3 = 0, value1 = 2, value2 = 3, value3 = 5, curr = 1;
    for (int i = 1; i < n; i++)
    {
        curr = min(value1, min(value2, value3));
        arr[i] = curr;
        if (curr == value1)
        {
            pointer1++;
            value1 = arr[pointer1] * 2;
        }
        if (curr == value2)
        {
            pointer2++;
            value2 = arr[pointer2] * 3;
        }
        if (curr == value3)
        {
            pointer3++;
            value3 = arr[pointer3] * 5;
        }
    }
    return curr;
}