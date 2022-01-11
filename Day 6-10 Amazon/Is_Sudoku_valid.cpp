class Solution
{
public:
    int isValid(vector<vector<int>> mat)
    {
        // code here
        // checking row
        for (int i = 0; i < 9; i++)
        {
            vector<int> rows(9, 0);
            vector<int> cols(9, 0);
            for (int j = 0; j < 9; j++)
            {
                // check whether column has no duplicates
                if (mat[i][j] != 0)
                {
                    if (cols[mat[i][j] - 1] == 0)
                        cols[mat[i][j] - 1] = 1;
                    else
                        return 0;
                }
                // check whether rows has no duplicates
                if (mat[j][i] != 0)
                {
                    if (rows[mat[j][i] - 1] == 0)
                        rows[mat[j][i] - 1] = 1;
                    else
                        return 0;
                }
                // check for diagonals
                if (i % 3 == 0 && j % 3 == 0)
                {
                    vector<int> boxs(9, 0);
                    for (int k = i; k < i + 3; k++)
                    {
                        for (int l = j; l < j + 3; l++)
                        {
                            if (mat[k][l] != 0)
                            {
                                if (boxs[mat[k][l] - 1] == 0)
                                    boxs[mat[k][l] - 1] = 1;
                                else
                                    return 0;
                            }
                        }
                    }
                }
            }
        }
        return 1;
    }
};