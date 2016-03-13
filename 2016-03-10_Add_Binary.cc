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

        int str_size = (a.size() > b.size())?(a.size()+1):(b.size()+1);
        string ret(str_size,'0');

        int aindex = a.size() - 1;
        int bindex = b.size() - 1;
        int flag = 0;
        int count = str_size-1;

        while(aindex >= 0 && bindex >= 0) {

            int sum = a[aindex]-'0' + b[bindex]-'0';
            ret[count--] = (sum + flag) % 2 + '0';

            if(sum+flag >= 2)
                flag = 1;

            --aindex;
            --bindex;
        }

        while(aindex >= 0) {
            int sum = a[aindex] - '0' + flag;
            if(sum >= 2)
                flag = 1;
            else
                flag = 0;
            ret[count--] = sum % 2 + '0';
            --aindex;
        }

        while(bindex >= 0) {
            int sum = a[aindex] - '0' + flag;
            if(sum >= 2)
                flag = 1;
            else
                flag = 0;
            ret[count--] = sum % 2 + '0';
            --bindex;
        }

        if(flag)
            ret[count--] = '1';

        if(ret[0] == '0')
            return string(ret.begin()+1,ret.end());
        return ret;
    }
};

/*
 *  别人的代码写的写舒服,
 *
 *
 */
class Solution {
public:
	string addBinary(string a, string b) {
		string result;
		const size_t n = a.size() > b.size() ? a.size() : b.size();
        //考虑到了
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int carry = 0;
        //确定遍历的次数
		for (size_t i = 0; i < n; i++) {
				const int ai = i < a.size() ? a[i] - '0' : 0;
				const int bi = i < b.size() ? b[i] - '0' : 0;
				const int val = (ai + bi + carry) % 2;
				carry = (ai + bi + carry) / 2;
				result.insert(result.begin(), val + '0');
		}
		if (carry == 1) {
			result.insert(result.begin(), '1');
		}
		return result;
	}
};

int main()
{
    string a = "101111";
    string b = "10";
    Solution so;
    cout << so.addBinary(a,b) << endl;
}
