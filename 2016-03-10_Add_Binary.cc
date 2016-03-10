#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <bitset>

using namespace std;

/*
 *  如果大小固定,可以使用bitset来做,很方便,只是这里并非是固定大小的
 *  因此可以采用如下两种方法:
 *  方法1: 人工模拟加法
 *  方法2: 先转换为10进制然后相加最后转换为二进制输出即可
 *
 *
 *
 */
class Solution {
public:
    string addBinary(string a, string b) {
        const int asize = a.size();
        const int bsize = b.size();
        const int retsize = asize > bsize ? : asize+1: bsize+1
        bitset<asize> aset(a);
        bitset<bsize> bset(b);
        bitset<retsize> ret = a + b;
        return ret.to_string();
    }
};

int main()
{
    string a = "11";
    string b = "1";
    Solution so;
    cout << so.addBinary(a,b) << endl;
}
