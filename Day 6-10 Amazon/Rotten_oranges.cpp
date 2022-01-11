class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (n == 0)
            return 0;
        int row = grid.size();
        int col = grid[0].size();
        int cnt = 0;
        int empty = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 0)
                    empty++;
            }
        }
        int xdiff[] = {-1, 0, 0, +1}; // left up down right
        int ydiff[] = {0, -1, +1, 0};
        int days = 0;
        while (!q.empty())
        {
            int k = q.size();
            cnt += k;
            while (k > 0)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int tempx = x + xdiff[i];
                    int tempy = y + ydiff[i];
                    if (tempx < 0 || tempy < 0 || tempx >= row || tempy >= col || grid[tempx][tempy] != 1)
                        continue;
                    grid[tempx][tempy] = 2; // means now it is rotten
                    q.push({tempx, tempy});
                }

                k--;
            }
            if (!q.empty())
                days++;
        }
        int size = row * col;
        return cnt + empty == size ? days : -1;
    }
};