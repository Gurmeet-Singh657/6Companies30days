// Question LInk - https://practice.geeksforgeeks.org/problems/squares-in-nn-chessboard1801/1#
class Solution
{
public:
    long long squaresInChessBoard(long long N)
    {
        // code here
        long long ans = 0;
        for (long long i = 1; i <= N; i++)
        {
            ans += (i * i);
        }
        return ans;
    }
};