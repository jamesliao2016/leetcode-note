#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cassert>

using namespace std;
/*
 *  这种解法太过繁琐，群举了很多中情况，其实在这些情况中又很多可以合并。
 *
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
    	int begin = 0;
    	int end = nums.size();
    	int mid = 0;
    	//对于0 1 2 3 4 5 6
    	//四种情况:
    	//第一种: 4 5 6 0 1 2 3
    	//第二种: 3 4 5 6 0 1 2
    	//第三种: 2 3 4 5 6 0 1
    	//第四种: 0 1 2 3 4 5 6
    	//第五种: 5 6 0 1 2 3 4
    	//第一种情况begin > mid,其余都是behin < mid，所以又分成了两种情况，一个就是begin > mid和begin < mid
    	//对于begin > mid的情形来说:mid右侧的最后一个元素是小于mid左侧第一个元素的。
    	//对于第二种情形来说 begin < mid:右侧有可能又大于mid的元素,左侧都是小于mid的元素
    	while(begin != end)
    	{
    		mid = (begin + end) / 2;
    		if (target == nums[mid])
    			return mid;
    		if (nums[begin] > nums[mid]) {//begin > mid的情形
    			if (target > nums[mid] && target > nums[end-1]) {//说明元素在左侧,否则在右侧
    				end = mid;
    			    continue;
    			}

    			if (target > nums[mid] && target <= nums[end -1]){
    				begin = mid+1;
    				continue;
    			}

    			if (target < nums[mid])
    			    end = mid;

    		} else { //begin < mid的情形
    			if (target > nums[mid] && nums[mid] < nums[mid+1]){ //右侧是大于target的元素
    				begin = mid+1;
    				continue;
    			}

    			if (target > nums[mid] && nums[mid] > nums[mid+1]) { //右侧没有比mid大的元素了,所以找不到了
    				return -1;
    			}

    			if (target < nums[mid] && target < nums[begin]) //出现在左侧但是比begin小，那么就出现在右侧
    				begin = mid+1;
    			else //出现在左侧
    				end = mid;
    		}
    	}
    	return -1;
    }
};

/*
 *  对于解法1中的多种情况进行合并处理，使代码更易读
 *  首先对于这样的旋转数组来说，根据mid和first的关系可以分成两种，按照mid分割后，肯定是有一侧是连续的，另一侧则不是
 *  所以按照first和mid的关系可以分成两种，一种是左侧连续，右侧不连续，另外一种是右侧连续，左侧不连续
 *
 * 1.对于左侧连续，右侧不连续来说:(例: 7 8 9 10 11 1 2) 因为10大于7，所以左侧连续，右侧不连续
 *      Setp1:判断target和mid的关系，如果小于mid，并且大于first，那么就在左侧，否则在右侧(利用现有的事实(左侧连续的事实)来判断)
 *          而第一种解法没有基于前面推到出来的结果来判断而是穷举所有可能情况
 *      Setp2:如果target大于mid，很显然就在右侧
 *      Setp3:再次递归
 * 2.对于右侧连续，左侧不连续来说:(例: 7 8 1 2 3 4 5)，因为2小雨7，所以左侧不连续，右侧连续
 *      Setp1: 判断target和mid的关系，如果大于mid，并且小于last，那么就在右侧
 *      Setp2: 如果target 小于 mid很显然就在左侧
 *      Setp3: 再次递归
 *
 * 下面算法存在一个bug，
 */


class Solution2 {
    public:
        int search(vector<int>& nums, int target) {
            int first = 0;
            int last = nums.size();
            int mid = 0;
            while(first != last) {
                mid = (first + last) / 2;
                if (nums[mid] >= nums[first]) {  //左侧连续，右侧不连续的情况
                    if (target < nums[mid] && target >= nums[first]) //因为左侧连续，那么就基于这个事实来判断，如果target小于mid，并且大于等于first，就在左侧
                        last = mid;
                    else
                        first = mid + 1;
                } else {
                    if (target > nums[mid] && target <= nums[last - 1]) //因为右侧连续，那么如果target大于last，并且小于等于end-1，那么就在右侧
                        first = mid + 1;
                    else
                        last = mid;
                }
            }
            return -1;
        }

};


int main()
{
    Solution so;
    Solution so2;
    vector<int> num;
    num.push_back(7);
    num.push_back(8);
    num.push_back(9);
    num.push_back(10);
    num.push_back(11);
    num.push_back(12);
    num.push_back(4);
    num.push_back(5);
    num.push_back(6);

    vector<int> num2;
    num2.push_back(1);
    num2.push_back(3);

    assert(so.search(num,4) == 6);
    cout << so2.search(num2,1) << endl;
}
