class Solution {
public
    bool isValidSudoku(vectorvectorchar& board) {
        return checkColumn(board)&&checkRow(board)&&checkBlock(board);
    }
    bool checkColumn(vectorvectorchar& board){
        for(int i=0;i9;i++)
        {
            unordered_setchar set;
            for(int j=0;j9;j++)
            {
                if(board[i][j]=='.')
                    continue;
                else if (set.find(board[i][j])!=set.end())
                {
                    coutcheckColumn false!ii jjendl;
                    return false;
                }
                else
                    set.insert(board[i][j]);
            }
        }
        return true;
    }
    bool checkRow(vectorvectorchar& board){
        for(int j=0;j9;j++)
        {
            unordered_setchar set;
            for(int i=0;i9;i++)
            {
                if(board[i][j]=='.')
                    continue;
                else if (set.find(board[i][j])!=set.end())
                {
                    coutcheckRow false!ii jjendl;
                    return false;
                }
                else
                    set.insert(board[i][j]);
            }
        }
        return true;
    }
    bool checkBlock(vectorvectorchar& board){
        for(int i=0;i9;i+=3)
        {
            for(int j=0;j9;j+=3)
            {
                unordered_setchar set;
                for(int k=0;k3;k++)
                {
                    for(int l=0;l3;l++)
                    {
                        if(board[i+k][j+l]=='.')
                            continue;
                        else if (set.find(board[i+k][j+l])!=set.end())
                        {
                            coutcheckBlock false!ii jj kk llendl;
                            return false;
                        }
                        else
                            set.insert(board[i+k][j+l]);
                    }
                }
            }
        }
        return true;
    }
};