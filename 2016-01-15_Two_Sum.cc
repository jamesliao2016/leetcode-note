#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;


/*  思路比较简单:
 *  先保存每一个元素值及其对应的下标存放在map中
 *  然后遍历，判断target - num是否在map中．具体过程如下:
 *  nums = {2,7,11,5} target = 13
 *
 *  Step1: 建立map关系
 *      2:1
 *      7:2
 *      11:3
 *      15:4
 *  Setp2:
 *      顺序遍历
 *      遍历2，计算target - 2是否在map中，发现13 - 2 = 11在map中，记录key=11的value值
 *
 *  Setp3:
 *      构造vector返回
 *
 *  需要考虑重复元素的处理，下面这种方法，存在一个很明显的bug，就是不允许重复
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> store;
        int count = 1;
        vector<int> ret;
        for(auto num : nums) store[num] = count++;

        for(auto num : nums) {
            if(store.find(target - num) != store.end() && (target - num) != num) {
                ret.push_back(store[num]);
                ret.push_back(store[target - num]);
                break;
            }
        }
        return ret;
    }
};

/*
 *  思路１和解法１类似，都是利用了,map来实现的，只不过这个解法是允许元素重复的．
 *  遍历每个元素，查看这个元素是否在map中，如果不存在就保存target - num(遍历的这个元素值)的结果到map中
 *  否则记录下标返回结果．例子:
 *  -1 4 1 3 0 2
 *  对于target = 0来说:
 *      遍历-1 不在map中，记录key=1,value=1(元素的位置)
 *      遍历4  不在map中，记录key=-4,value=2
 *      遍历1  在map中，返回结果
 *
 *
 *
 */
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
                    vector<int> result;
                    unordered_map<int,int> tempdata;
                    int index1 = 0;
                    int index2 = 1;
                    pair<map<int,int>::iterator,bool> ret;
                    unordered_map<int,int>::iterator itmap;
                    vector<int>::iterator it = nums.begin();
                    for(int i =0;it != nums.end();it++,i++)
                    {
                        itmap=tempdata.find(*it);
                        if (itmap != tempdata.end()) {  //存在
                            result.push_back(tempdata[*it]);
                            result.push_back(i+1);
                            return result;
                        }
                        tempdata.insert(make_pair<int,int>(target-(*it),i+1));
                    }
    }
};

int main()
{
    vector<int> num = {0,4,3,0};
    Solution so;
    vector<int> ret = so.twoSum(num,6);
    for(auto num : ret) cout << num << endl;
}
