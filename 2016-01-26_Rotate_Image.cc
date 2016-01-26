#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

/*
 *  图片翻转90度，又可称为数组旋转，你可以手动把一个2*2的翻转一下，找到规律就可以了．
 *  通过我翻转后找到的规律发现只要沿着副对角线翻转一次，然后沿着水平线翻转一次就okl了
 *  或者反过来，先水平线翻转，然后主对角线翻转，所以思路还是很简单的
 *  Setp1: 水平翻转
 *  Setp2: 按照主对角线翻转
 *
 *  注: 按照主对角线来做的话更容易做，因为要翻转的元素只要调换i和j即可．因为是关于y = x对称
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
        if(n <= 1) return;
        int i,j;

        //Setp1  水平翻转，也就是翻转n列，也就是需要翻转n次
        for(int k = 0; k < n; ++k) {

            i = 0;
            j = n - 1;

            while(i <= j) {
                swap(matrix[i][k],matrix[j][k]);
                ++i;
                --j;
            }
        }

        //Setp2 按照主对角线翻转
        for(i = 0; i < n;++i)
            for(j = i+1; j < n;++j ) {
                swap(matrix[i][j],matrix[j][i]);
            }
    }
};

int main()
{

}
