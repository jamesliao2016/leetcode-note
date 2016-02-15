#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

/*
 *  这一题比较好玩，主要是因为题目挺有意思，题目给出一组数字，每个数字代表一个柱子的高度，
 *  问这个柱子之间可以存放多少雨水．这题的解法很多:
 *
 *  解法1,对于每一个柱子来说,能存放多少水,取决于这个柱子左侧的最高柱子,和这个柱子的右侧最高柱子两者的最小值
 *  很显然你会得到一个结论就是这个柱子上面可以存放的雨水,取决于左侧和右侧柱子的最小值,这个结论还是很容易得出来的.
 *  所以对于每个柱子来说可以存放的雨水的大小为min(leftmax,rightmax) - height(柱子自身的高度)
 *
 *  Setp1: 从左往右 求每一个柱子的左侧最大值
 *  Setp2: 从右往左,求每一个柱子的右侧的最大值
 *  Setp3: 从左往右计算每一个柱子的可以存放的雨水大小
 *
 *  求最大值算法需要使用DP算法,否则AC过不了
 */

class Solution {
public:
    int trap(vector<int>& height) {
        int size = 0;
        if(height.size() <= 2) return size;
        vector<int> left(height.size());
        vector<int> right(height.size());

        //Setp1 and Setp2  DP解法
        for(int i = 1; i < height.size(); ++i) {
            //一个算法的的左侧最大值是它前一个元素的最大值和它前一个元素本身的值的两者最大者
            left[i] = max(left[i - 1],height[i - 1]);
            //一个算法的右侧最大值,是这个元素的右侧前一个元素的最大值和右侧前一个元素本身的最大值两者最大
            right[height.size() - 1 - i] = max(right[height.size() - i],height[height.size() - i]);
        }

//非DP解法
/*
        //Setp1,第一个柱子不用考虑,因为第一个柱子是无法存放水的
        for(int i = 1; i < height.size() - 1; ++i) {
            left[i] = *max_element(height.begin(),height.begin() + i);
            //cout << "left" << left[i] << endl;
        }

        //Setp2,最后一个柱子也不用考虑,因为最后一个柱子无发
        for(int i = height.size() - 2; i > 0; --i) {
            right[i] = *max_element(height.begin() + i,height.end());
        }
*/
        //Setp3
        for(int i = 0; i < height.size();++i) {
            int result = min(left[i],right[i]);
            result = result < height[i] ? 0 : (result - height[i]);
            size += result;
        }
        return size;
    }
};

/*
 *  算法二,
 *  找到最大的柱子，然后从最大柱子开始向两侧前进
 *  Setp1: find max element position
 *  Setp2:每遍历一个柱子和钱一个柱子的高度比较，如果大于前一个柱子，说明这个柱子肯定不能装水，那么就更新前一个柱子的高度
 *  否则就用一个柱子的高度减去当前柱子的高度就是这个柱子能存放的水量，其实本质上和解法一是一样的，只不过这里省去了min,求左边最大值和右边最大值的min
 *  因为右侧最大值总是最大的．
 */

class Solution2 {
public:
    int trap(vector<int>& height) {
        int max = 0;
        //Setp1
        for(int i = 0; i < n; i++)
            if(height[i] > height[max]) max = i;

        int water = 0;
        //动态规划
        for(int i = 0,peak = 0; i < max;++i)
            if(height[i] > peak) peak = height[i];
            else water += peak - height[i];

        for(int i = n - 1,top = 0;i > max;--i)
            if(height[i] > top) top = height[i];
            else water += top - height[i];

        return water;
    }
};

/*
 *  算法三
 *  用一个栈辅助完成，小于栈顶的元素压入，大于等于栈顶就把栈里所有小雨或等于当前值的元素出堆栈处理掉
 *  这样可以保证一个前提就是栈里面放的始终是每个柱子的左边最大值.
 *
 */



class Solution3 {
public:
    int trap(vector<int>& height) {
        stack<pair<int,int>> s;
        int water = 0;
        for(int i = 0; i < n; ++i) {
            int Height = 0;
            while(!s.empty()) {
                int bar = s.top().first;
                int pos = s.top().second;
                //这一步没搞懂
                water += (min(bar,height[i]) - Height) * (i - pos - 1)
                Height = bar;
            }
            s.push(make_pair(height[i],i));
        }
    }
};


int main()
{
    vector<int> data = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution so;
    cout << so.trap(data);
}
