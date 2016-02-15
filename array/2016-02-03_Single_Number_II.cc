#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <bitset>
#include <unordered_map>

using namespace std;

/*
 * 和Single Number类似，只不过这里是数字出现三次，只有一个数字出现一次，那么就没办法用异或来做了．
 * 基于排序和map的方法这里就不说了，思想都和Single Number基本一样．这里谈一谈另外一种算法
 * 用一个sizeof(int) * 8大小的数组来存放一个int数的每一位1出现的次数，如果出现三次就清0，最后将这个数字转换为十进制即可
 *
 *
 *
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        vector<int> data(sizeof(int) * 8);
        int bits = 0;
        for(auto num : nums) {
            bits = sizeof(int) * 8;
            while(bits--) {
                if((num >> bits) & 1)
                    if(++data[bits] == 3)
                        data[bits] = 0;
            }
        }
        int result = 0;
        for(int i = 0; i < sizeof(int) * 8;++i) {
            result += (data[i] << i);
        }
        return result;
        //return convert_decimal<vector<int>::iterator>(data.begin(),data.end());

    }

/*
private:
    template<typename Iterator>
    int convert_decimal(Iterator begin,Iterator end) {
        int i = 0;
        int ret = 0;
        for(;begin != end;++begin) {
                ret = ret + *begin * pow(2,i);
                ++i;
        }
        return ret;
    }
*/
};

int main()
{
    Solution so;
    vector<int> data = {-2,-2,1,1,-3,1,-3,-3,-4,-2};
    cout << so.singleNumber(data) << endl;
}
