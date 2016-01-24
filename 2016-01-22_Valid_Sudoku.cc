#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

/*
 *  很简单的题，不需要检查数独是否有解，只需要判断数独是否有效即可。
 *  setp1: 判断每行，数字是否唯一
 *  setp2: 判断每列，数字是否唯一
 *  setp3: 判断每个九方格数字是否唯一
 *
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<bool> used(9,false);

        //Setp1
        for(int i = 0; i < 9; ++i) {
            fill(used.begin(),used.end(),false);
            for(int j = 0; j < 9; ++j)
                if(!check_valid(used,board[i][j]))
                    return false;
        }

        //Setp2
        for(int i = 0; i < 9; ++i) {
            fill(used.begin(),used.end(),false);
            for(int j = 0; j < 9;++j) {
                if(!check_valid(used,board[j][i]))
                    return false;
            }
        }

        //Setp3
        for(int k = 0; k < 9; ++k) {
            fill(used.begin(),used.end(),false);
            for(int i = 0; i < 3; ++i) {
                for(int j = 0; j < 3; ++j) {
                    int ik = (k / 3) * 3; //行的因子
                    int jk = (k % 3) * 3;
                    if(!check_valid(used,board[i + ik][j + jk]))
                        return false;
                }
            }
        }

        return true;
    }

private:

    bool check_valid(vector<bool> &used,int num) {
        if(num != '.') {
            if(used[num - '1'])
                return false;
            else
                used[num - '1'] = true;
            return true;
        } else {

            return true;
        }
    }
};

int main()
{
    vector<vector<char>> data;
    Solution so;
    so.isValidSudoku(data);
}
