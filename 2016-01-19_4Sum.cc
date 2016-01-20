#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

/*  先排序，然后左右夹逼,思路和3SUM都是一样的，只不过这里是四个数,先确定两个数然后，再使用两个指针开始
 *  左右进行逼近
 *
 *
 *
 */
class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            vector<vector<int>> data;
            if(nums.size() < 4)
                return data; //直接返回
            sort(nums.begin(),nums.end());
            for(int i = 0; i < nums.size() - 3;++i)
                for(int j = i + 1; j < nums.size() - 2;++j) {
                    int first = j + 1;
                    int last = nums.size() - 1;
                    while(first < last){
                        int dest = target - (nums[i] + nums[j] + nums[first] + nums[last]);
                        if(dest > 0) {//说明还差target一段,需要增加数字的大小
                            ++first;
                        }else if(dest < 0) { //说明已经超过target
                            --last;
                        }else {
                            data.push_back({nums[i],nums[j],nums[first],nums[last]});
                            ++first;
                            --last;
                        }
                    }
                }
            sort(data.begin(),data.end());
            data.erase(unique(data.begin(),data.end()),data.end());
            return data;
        }
};

/*
 *  思路二，仍然是先排序，然后左右夹逼，只不过这里加入了一些限制条件，优化求解过程。
 *  上面的思路是用双重循环，固定前两个数，然后利用左右夹逼来确定最后两个数字，解法二，则是利用map保存前两个数子的和的所有情况。
 *  然后二重循环遍历后两个数，然后target - 后两个数的和，去map查找。
 *
 *  因为可能会出现多对数字的和是相同的，所以map是key=int,value是一个vector<pair<int,int>>类型。这里也可以换成是multimap来做
 *
 */
class Solution2 {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            vector<vector<int>> data;
            if(nums.size() < 4)
                return data; //直接返回
            unordered_map<int,vector<pair<int,int> > > sum_map;
            sort(nums.begin(),nums.end());
            for(size_t i = 0; i < nums.size() - 3; ++i) {
                for(size_t j = i + 1; j < nums.size() - 2; ++j) {
                    sum_map[nums[i] + nums[j]].push_back(pair<int,int>(i,j));
                }
            }

            for(size_t i = 0; i < nums.size();++i) {
                for(size_t j = i + 1;j < nums.size();++j) {
                    const int key = target - nums[i] - nums[j];
                    if(sum_map.find(key) == sum_map.end()) continue; //没找到

                    const auto& vec = sum_map[key];
                    for(size_t k = 0; k < vec.size();++k) {
                        if(i <= vec[k].second)
                            continue; //有重叠
                        //cout << vec[k].first << "|" << vec[k].second << "|" << i << "|" << j << endl;
                        data.push_back({nums[vec[k].first],nums[vec[k].second],nums[i],nums[j]});
                    }
                }
            }
            sort(data.begin(),data.end());
            data.erase(unique(data.begin(),data.end()),data.end());
            return data;
        }
};

int main()
{
    Solution2 so;
    vector<int> data = {1,0,-1,0,-2,2};
    auto ret = so.fourSum(data,0);
    for(auto num : ret) {
        for(auto inetrn_num : num)
            cout << inetrn_num << "|";
    cout << endl;
    }
}
