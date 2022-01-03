// Question Link - https://practice.geeksforgeeks.org/problems/overlapping-rectangles1924/1/

class Solution
{
public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[])
    {
        // code here
        // for rectangle left or right other with no overlapping
        if (L1[0] > R2[0] || L2[0] > R1[0])
            return false;
        // for rectangle top or below other with no overlapping
        if (R2[1] > L1[1] || R1[1] > L2[1])
            return false;
        return true;
    }
};