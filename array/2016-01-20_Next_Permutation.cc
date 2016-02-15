#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

/*
 *  给出按照字典序生成给定序列的下一个较大的排列，可以直接用STL提供的next_permutation算法来完成，也可以自己来实现
 *  July的编程之法这本书中详细的讲到如何来实现
 *
 *  Setp1: 找到排列中最后一个升序的首位位置i
 *  Setp2: 找到排列中第i位右边最后一个比data[i]大的位置j
 *  Setp3: 交换i和j位置的元素
 *  Setp4: 把i+1位置到最后的部分进行翻转
 *
 *  例子: 2 1 5 4 3
 *  Setp1: i = 1
 *  Setp2: j = 4
 *  Setp3: data[i] 和 data[j] 交换
 *  Setp4: 翻转5 4 1变成 1 4 5
 *  最终结果就是2 3 1 4 5
 *
 *  上面的算法并不难，难在为何像上面一样做后就可以了，下面是算法的解释，先想一下，对于一组数的全排列来说有起点和终点一说嘛?有的
 *  例如: 1 2 3 4 5就是起点，5 4 3 2 1就是终点，那么很显然对于一个全排列来说，最小的就是升序，最大的就是降序．
 *
 *  假设字符串AxB 的下一个排列是AyB'，其中A,B,B'是字符串,x和y是字符.前缀相同，并且一定是x > y，还有一点肯定的就是
 *  A应该尽可能的长，长到什么时候为止呢，长到可以找到一个x大于y，也就是说，x的右边应该是可以找到比它大的数，并且A足够长，因为得出Setp1:
 *  找到最后一个右边有比它大的数的位置．例如2 1 5 4 3，我们从右边开始找，3不行，4不行,5不行,只能是1了.举个例子,如果x是4那么A是2 1 5，好吧
 *  你举得y有可能比x大吗?不可能了，这从另一个方面也验证了Setp1的由来，那么x现在确定了，y是什么呢,很显然只能是x右边的那些数字了，那么到底是哪个呢
 *  肯定是最小的那个了并且大于x，最小的那个是哪个?，你可以一个个比较找到最小的那个，但是其实是不需要的，根据Setp1很显然会得出一个结论，就是x右边的都是降序的
 *  为什么呢?如果不是降序，那么我肯定能在右边再找到一个x啊(x就是右边有比它大的数存在)，既然是降序那就从右边开始找，是不是有点迷惑了，慢慢理清下思路．
 *  那么Step2就完成了，Setp3则顺理成章，那么Setp4是怎么来的呢.举个例子: 199的下一个是200，1相当于x，y相当于2，99应该是两位数中的最大的了,00应该是最小的了，对应到全排列
 *  B和B'的关系应该就是最大和最小的关系，B很显然是最大的，因为B是降序的，因为B'只能用B中的几个数进行组合，并且还要做小，那么B'只需要升序即可．
 *  对应到第四不就是将B反向翻转即可．到此为止解释完毕．
 *
 */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
            //Setp1:
            int x = -1;
            for(int i = nums.size() - 2; i >= 0; --i) {
                    if(nums[i] < nums[i + 1]) { //从倒数第二个开始找，完成Setp1
                      x = i;
                      break;
                    }
            }
            if(x == -1) {
                reverse(nums.begin(),nums.end());
                return;
            }

            //Setp2
            int y = nums.size() - 1; //最后一个元素的位置，完成Setp2
            for(int i = nums.size() - 1; i > 0; --i) {
                if(nums[x] < nums[i]) {
                    y = i;
                    break;
                }
            }
            //Setp3
            swap(nums[x],nums[y]); //x和y交换,完成setp3

            //Setp4
            reverse(nums.begin() + x + 1,nums.end()); //从x+1处开始翻转，完成Setp4
    }
};

/*
 * 利用STL已经写好的算法来完成,和上述算法的效率基本一样
 *
 *
 */
class Solution2 {
public:
    void nextPermutation(vector<int>& nums) {
       next_permutation(nums.begin(),nums.end());
       //还支持prev_permutation
       return;
    }
};


int main()
{
    vector<int> data = {3,2,1};
    Solution2 so;
    so.nextPermutation(data);

    for(auto num : data)
        cout << num << "|";
}
