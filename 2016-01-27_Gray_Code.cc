#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <bitset>

using namespace std;

/*  格雷码，一组数的编码中，任意两个相邻的代码只有一位二进制数不同，则这种编码为格雷码．另外
 *  由于最大数字和最小数也仅一位数不同，即"首位相连"　因此又称循环码或反射码
 *
 *  利用格雷码是反射码的事实，可以利用下面的规则来构造:
 *
 *  1.1位格雷码有两个码子
 *  2.(n+1)位格雷码中的前2^n个码子等于n位格雷码的码子，按顺序书写，加前缀0
 *  3.(n+1)位格雷码中的后2^n个码子等于n位格雷码的码子，按逆序书写，加前缀1
 *
 *  例如:
 *      1位，格雷码是0,1
 *      2位格雷码就是 在0和1的前面加0也就是00,和01，然后再给1,0加前缀1，也就是11,10，综合来说，2位格雷码就是00,01,11,10
 *
 *  Setp1: 初始化1位格雷码
 *  Setp2: 根据1位格雷码求2位格雷码,一直求到n位格雷码的情况下
 *  Setp3: 二进制字符串转十进制
 *
 *  上面这个方法超时了，格雷码还有另外
 */


class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        //setp1 初始化1位的格雷码
        vector<string> data = {"0","1"};

        //setp2 生成n位的格雷码
        while(n - 1) { //进行n-1次迭代

            gen_graycode(data);
            --n;
        }
        //Setp3 转换为十进制
        for(auto number : data) {
            bitset<100> binstr(number);
            ret.push_back(binstr.to_ulong());
        }
        return ret;
    }
private:
    void gen_graycode(vector<string>& code) {
        int N = code.size();
        for(int i = N-1; i >= 0; --i) {

            code[i].insert(code[i].begin(),'1');
            code.push_back(code[i]);
            code[i][0] = '0';
        }
    }
};


/*
 *  解法一效率太低，字符串每次插入的时候都会导致后面的字符整体向后移动
 *  因此有了解法二，和解法三
 *
 *  解法三
 *
 *  解法
 *
 *
 *
 */
class Solution {
    public:
            vector<int> grayCode(int n) {
            }
};

int main()
{
    Solution so;
    vector<int> ret = so.grayCode(2);
    for(auto num : ret)
        cout << num << endl;
}
