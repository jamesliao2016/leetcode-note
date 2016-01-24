#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
using namespace std;

/*
 *  可以调用next_permulation，调用k-1次就ok了,但是效率明显不高．
 *  这里使用康托编码的逆运算来实现，举例说明:
 *   1 2 3 4 5，求全排列的第16个
 *   Step1: 16 - 1 = 15
 *   Setp2: 15 / 4! == > 0 余数是15
 *   Setp3: 15 / 3! == > 2 余数是3
 *   Setp4: 3 / 2! ==> 1余数是1
 *   Setp5: 1 / 1! ==> 1余数是0
 *  0就是前面只有0个数比他大，那就是1，
 *  2就是前面有两个比他小，那就是4，因为1已经有了
 *  1 那就是3
 *  1 那就是5
 *  最后一个只能是2了。
 *
 * 2 / 2 ==> 1 余数0
 */
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<char> data;
        for(int i = 1;i <= n;++i) {
            data.push_back(i + '0');
        }
        int map_k[n - 1];

        //SETP1
        int kth = k - 1;
        int N = 0;
        //SETP2 ~ SETP5
        int dataN = n-1;
        int count = 0;
        while(dataN > 0) {
            N = getN(dataN--);
            map_k[count++] = kth / N;
            kth = kth % N;
        }
        //map_k[count] = kth / N; //save last one

        //Last Setp
        string result;
        for(auto num : map_k) {
            result.append(1,data[num]);
            data.erase(data.begin()+num);
        }
        //append last one
        result.append(1,data[0]);
        cout << result << endl;
        return result;
    }

private:
    unsigned int getN(int n) {
        if(n == 1  || n == 2)
            return n;
        else
            return n * getN(n - 1);
    }
};

int main()
{
    Solution so;
    so.getPermutation(3,3);
}
