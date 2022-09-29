class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {

        for (int i = 0; i < 9; i++)
        {
            set<char> row;
            set<char> col;
            int cntRow = 0, cntCol = 0;
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    row.insert(board[i][j]);
                    cntRow++;
                }

                if (board[j][i] != '.')
                {
                    cntCol++;
                    col.insert(board[j][i]);
                };
            }

            // cout<<endl;

            if (row.size() != cntRow || col.size() != cntCol)
            {
                return false;
            }
        }

        // 0,0 0,1 0,2   0,3 0,4 0,5  0,6 0,7 0,8
        // 1,0 1,1 1,2   1,3 1,4 1,5  1,6 1,7 1,8
        // 2,0 2,1 2,2   2,3 2,4 2,5  2,6 2,7 2,8

        for (int i = 0; i < 9; i++)
        {

            for (int j = 0; j < 9; j++)
            {

                set<char> s;
                int cnt = 0;
                int indexI = (i / 3) * 3;
                int indexJ = (j / 3) * 3;
                for (int ii = indexI; ii < indexI + 3; ii++)
                {
                    for (int jj = indexJ; jj < indexJ + 3; jj++)
                    {
                        if (board[ii][jj] != '.')
                        {
                            s.insert(board[ii][jj]);
                            cnt++;
                        }
                    }
                }
                if (cnt != s.size())
                    return false;
            }
        }
        return true;
    }
};