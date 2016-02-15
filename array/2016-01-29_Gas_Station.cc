#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;


/*
 *  很自然的解法就是o(n^2),针对每一个点都模拟一遍,第二种解法很简单,但是不好理解:
 *  例如:从数组下标0开始,累加,如果出现和小于0的,那么就从下一个位置开始从头计数.为什么不从下标1开始呢(也就是0下标的下一个位置)?
 *  首先明确一点就是下标0处gas-cost肯定是大于0,否则就没法继续走下去了,所以,如果从下标1开始,那么下标1到上次结束的位置肯定是小于0的,因为0~上次结束的位置和为sum1
 *  下标1到上次结束的位置和为sum2那么sum1 - 下标0(gas - cost) = sum1 肯定小于0的,所以从下标1的位置继续遍历没有意义了,同理也可以推到出不能从下标2.3..上次结束位置作为
 *  下次遍历的开始位置都是无意义的.因此下次遍历应该从上次结束位置的下一个开始.
 *
 */
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int j = -1;
        int sum = 0;
        for(int i = 0;i < gas.size(); ++i) {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i]; //统计总和,确定是否有解
            if(sum < 0) {
                sum = 0;
                j = i;
            }
        }

        return total >= 0 ? j + 1: -1;
    }
};

int main()
{

}
