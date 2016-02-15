#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
            int count = 0;
            for(size_t i = 0; i < nums.size(); i++) {
                if(nums[i] == val)
                    continue;
                else
                    nums[count++] = nums[i];
            }

            return count;
    }
};

class Solution2 {
public:
    int removeElement(vector<int>& nums, int val) {
        return distance(nums.begin(),remove(nums.begin(),nums.end(),val));
    }
};

int main()
{
    vector<int> data = {1,2,3,4,5,1,23,4,5,6,1,1,1,2};
    Solution2 so;
    cout << so.removeElement(data,1) << endl;
}
