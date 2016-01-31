#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

/*
 *  简单一点的做法就是利用辅助空间来做,再一个二维数组中扫描,然后把扫描到的结果存放在另外一个二维数组中
 *  这无疑是最简单的,但是可能是最差的需要o(m * n)空间,第二种解法则是用一个M行的数组保存哪些行要被置0,然后再用一个N列的数组保存
 *  哪些列要被设置为0,然后统一进行设置,这需要o(m + n)的空间,但这还不是最好的.最好的算法应该是常量的复杂度.
 *
 *
 */
//解法1,空间复杂度o(m + n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> zerol(matrix.size(),false);
        vector<bool> zeror(matrix[0].size(),false);

        for(int i = 0; i < zerol.size(); ++i) {
            for(int j = 0; j < zeror.size();++j) {
                if(matrix[i][j] == 0) {
                    zerol[i] = true;
                    zeror[j] = true;
                }
            }
        }

        //行清0
        for(int i = 0; i < zerol.size(); ++i) {
            if(zerol[i])
                fill(matrix[i].begin(),matrix[i].end(),0);
        }

        //列清0
        for(int j = 0; j < zeror.size(); ++j) {
            if(zeror[j]) {
                for(int i = 0; i < zerol.size();++i)
                    matrix[i][j] = 0;
            }
        }
    }
};

/*
 *  解法二,只需要o(1)的空间即可,起算法思想就是复用第一行和第一列,,如果某行不为0,那么第一列上肯定不为0,同理,如果某列不为0,那么第一行上肯定不为0
 *
 *
 *
 */

class Solution2 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int l = matrix.size();       //行数
        int r = matrix[0].size();    //列数

        //用来表明,第一行和第一列自身是否为0
        bool lzero = false;
        bool rzero = false;

        for(int i = 0; i < l; ++i)
            if(!matrix[i][0]) {
                rzero = true; //第0列要设置为0
                break;
            }

        for(int i = 0; i < r; ++i) {
            if(!matrix[0][i]) {
                lzero = true;
                break;
            }
        }


        //省略到第1行,和第一列
        for(int i = 1; i < l; ++i) {
            for(int j = 1; j < r;++j) {
                if(!matrix[i][j]) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }


        //如果第0行和第0列有0元素,则需要设置对应的行和列为0
        for(int i = 1; i < l;++i) {
            for(int j = 1; j < r;++j) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        //根据lzero和rzero的结果来设置0行,0列的zero
        if(lzero) {
            fill(matrix[0].begin(),matrix[0].end(),0);
        }

        if(rzero) {
            for(int j = 0; j < l;++j)
                matrix[j][0] = 0;
        }
    }
};


int main()
{

}
