#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;
/*
 *
 *  实现起来难度不大,但是需要考虑正负数,还需要考虑是否超过精度(这点实现起来不是很容易)
 *  sum = 0;
 *  Setp1:略去开头的空格
 *  Setp2:判断是否带有+或-号标志位,设置正负标志位
 *  Setp3:判断正负号后是否是数字,如果是就继续,否则return 0,标志no vaild
 *  Setp4:取出一个数字和sum 乘以10的结果相加,然后再取出一个和sum乘以10的结果累加,以此类推,最后就可以得到结果了
 *
 *  但是在Setp4中还忽略了一个细节,就是没有考虑是否溢出,先判断sum和INT_MAX / 10谁大谁小,如果前者大,那么说明会溢出
 *  如果相等那么就判断取出的这个数字和 INT_MAX / 10的结果谁大,谁小了.
 *
 *
 */
class Solution {
    public:
        int myAtoi(string str) {
        }
};

int main()
{

}
