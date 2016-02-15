#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
/*
 *  通用的格式为，找到两个排序好的数组中第K大的元素
 *  在这里使用了一种通用解法，步骤如下:
 *  Setp1: 先判断nums1.size() + nums2.size()的和是奇数还是偶数，计算中间值
 *  Setp2: nums1和nums2进行和合并排序,计算过程如下:
 *      nums1: 1 3 5 7 9　
 *      nums2: 2 4 6 8 10
 *      1和2比，2大，则用2和3比，3大，则用4和3比　依次类推，算法思想就是有序数组的合并
 *      在合并的过程中使用count计数，计算已经排好序的个数，然后和中间值比较
 *  Setp3:
 *      根据奇数还是偶数标志位，来计算最终的结果
 *
 * 算法思想很简单，用的都是通用的算法，但是代码比较长，不易读，最重要的是不能处理好边界条件，边界条件需要单独处理
 * 比如,nums1和nums2其中有一方是元素个数为０，并且下面的代码bug较多，很多边界情况没有考虑进去
 */
class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
                vector<int> nums;
                //排除一些特殊场景，比如nums1或者nums2为０的时候
                //还要考虑nums1.size() + nums2.size()大和是偶数还是奇数
                //如果是偶数则需要区中间两位的均值，否则取中间的数
                if(nums1.size() == 0 || nums2.size() == 0) {
                    if (nums1.size() == 0) {
                        nums.insert(nums.begin(),nums2.begin(),nums2.end());
                    }
                    if (nums2.size() == 0)
                        nums.insert(nums.begin(),nums1.begin(),nums1.end());

                    if ((nums.size() % 2) == 0) {
                            return ((nums[(nums.size()/2)-1] + nums[nums.size()/2])/2.0);
                    } else {
                            return nums[nums.size()/2];
                    }
                }
                int flag = 0;
                int k = (nums1.size() + nums2.size());
                if ((k % 2) == 0) //是偶数
                    flag = 1; //需要计算第k个和第k+1个的和的一半

                //开始统计,累加
                int nums1_count = 0;
                int nums2_count = 0;
                int count = 0;
                int ret = 0;
                while((nums1_count < nums1.size()) && (nums2_count < nums1.size()))
                {
                    if(nums1[nums1_count] >= nums2[nums2_count]){
                            count++;
                            nums2_count++;
                            if (count == k) {
                                ret = nums2[nums2_count];
                                if (!flag)
                                    break;
                            }
                            if (flag == 1 && count == (k+1)) {
                                ret += nums2[nums2_count];
                                break;
                            }
                    } else {
                            count++;
                            nums1_count++;
                            if (count == k) {
                                ret = nums1[nums1_count];
                                if (!flag)
                                    break;
                            }
                            if (flag == 1 && count == (k+1)) {
                                ret += nums1[nums1_count];
                                break;
                            }
                    }
                }
                if (flag == 1)
                    return ret/2.0;
                else
                    return ret;
        }
};

/*
 *  算法思路和上面一样，只不过这里代码比上面的较简洁，做这题的过程中遇到了很多考虑不周到导致错误结果的问题
 *  居然用了这么多的代码量，汗颜啊．，好在思路是我比较熟悉的，自己可以掌控，后面慢慢优化代码吧，感觉代码还是重复率太高了
 *  但是不用考虑一些边界条件了，只要处理好奇偶情况就行，比上面的代码思路更清晰一点，尽管代码量多了一些
 *
 */
class Solution2 {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
                int flag = ((nums1.size() + nums2.size()) % 2)?0:1;  //决定是奇数还是偶数，奇数则是0，偶数是1，偶数需要特殊处理
                int mid_data[2] = {0}; //存放第mid和mid+1
                int mid_count = (nums1.size() + nums2.size()) / 2;
                if (flag)
                    --mid_count;
                int nums1_count = 0;
                int nums2_count = 0;
                int index = -1;
                //上面的一大串都是在处理奇偶的问题，还有设置奇偶标志位，声明一大串辅助变量等等
                while(nums1_count < nums1.size() && nums2_count < nums2.size()) {
                    if (nums1[nums1_count] < nums2[nums2_count]) {
                        ++nums1_count;
                        ++index;
                        if (index == mid_count) {
                                mid_data[0] = nums1[nums1_count - 1];
                                if(flag == 0)
                                    goto end;
                        }

                        if (flag == 1 && index == mid_count+1) {
                                mid_data[1] = nums1[nums1_count - 1];
                                goto end;
                        }
                    } else {
                        ++nums2_count;
                        ++index;
                        if (index == mid_count) {
                                mid_data[0] = nums2[nums2_count - 1];
                                if(flag == 0)
                                    goto end;
                        }
                        if (flag == 1 && index == mid_count+1) {
                                mid_data[1] = nums2[nums2_count - 1];
                                goto end;
                        }
                    }
                }

                //如果上面没有找到，那就处理剩余未比较的元素吧
                //这里可以合并代码处理
                if(nums1_count >= nums1.size()) {  //说明nums1_count已经比较完了
                    while(nums2_count < nums2.size()) {
                        ++nums2_count;
                        ++index;
                        if(index == mid_count) {
                            mid_data[0] = nums2[nums2_count - 1];
                            if(flag == 0)
                                goto end;
                        }
                        if(flag == 1 && index == mid_count +1) {
                            mid_data[1] = nums2[nums2_count - 1];
                            goto end;
                        }
                    }
                }
                else if(nums2_count >= nums2.size()) {
                    while(nums1_count < nums1.size()) {
                        ++nums1_count;
                        ++index;
                        if (index == mid_count) {
                            mid_data[0] = nums1[nums1_count - 1];
                            if(flag == 0)
                                goto end;
                        }
                        if (flag == 1 && index == mid_count+1) {
                            mid_data[1] = nums1[nums1_count - 1];
                                goto end;
                        }
                    }
                }
                //对上面的代码进行合并处理
                /*
                vector<int> &nums = nums1;
                int nums_count = nums1_count;
                if(nums1_count >= nums1.size()) {
                        nums = nums2;
                        nums_count = nums2_count;
                }
                while(nums_count < nums.size()) {
                        ++nums_count;
                        ++index;
                        if (index == mid_count) {
                            mid_data[0] = nums[nums_count - 1];
                            if(flag == 0)
                                goto end;
                        }
                        if (flag == 1 && index == mid_count+1) {
                            mid_data[1] = nums[nums_count - 1];
                               goto end;
                        }
                }
                */
        end:
                if(flag == 0 && index == mid_count)
                    return mid_data[0];
                if (flag == 1 && index == mid_count + 1)
                    return (mid_data[0] + mid_data[1]) / 2.0;
        }
};

/*
 *  更简单的算法，利用了二分查找和数组有序这个条件，可以拿nums1的第2/k个元素,再拿nums2的第2/k个元素(这里假设k是偶数)
 *  比较的结果有三种:
 *  第一: 相等，那么很自然，这就是第k个元素(为什么这么说呢?参见下文的分析)
 *  第二: nums1[k/2-1] < nums2[k/2-1] 那么第k个元素肯定不在nums1[0] ~ nums1[k/2-1]
 *  第三: nums2[k/2-1] < nums1[k/2-1] 那么第k个元素肯定不在nums2[0] ~ nums2[k/2-1]
 *
 *  为什么会得出上面的结论呢，举个例子: nums=1 3 5 7 9 nums2= 2 4 6 8 10，总共有十个元素，那么中间元素就是第五个
 *  均匀的分成两半，nums1取第2个元素，nums2取第三个元素进行比较(为什么要均匀分呢？,因为只有平均分成两半的时候当没有找到第k个元素的情况下
 *  就可以最多的排除掉一半的元素了。)，拿3和6比，因为3小于6，那么可以肯定一件事就是在nums1和nums2合并后，1 3肯定在第k个元素的左边部分，
 *  因为6大于2 4大于1,3,所以6可能是第k，或者是第k+n个元素。3的位置肯定小于k，那么这个时候可以很轻松排除掉1 3然后，再次用同样的方法查找，这个时候只要查找
 *  第5-2个元素即可，因为前k个元素已经去除了2个了。
 *
 *  如此递归查找，那么何时结束呢?
 *  当nums1或nums2有一方为空，那么很自然，第k个元素就是另一方的下标是k-1的元素
 *  当nums1[k/2-1] == nums[k/2-1] 相等的时候
 *  当k=1的时候返回nums1[0]和nums2[0]中最小的那个即可
 */
class Solution3 {
    typedef vector<int>::iterator Iter;
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int total = nums1.size() + nums2.size();
            if(total & 0x01) { //是奇数

                return find_kth(nums1.begin(),nums1.size(),nums2.begin(),nums2.size(),total / 2 + 1);

            } else {

                return (find_kth(nums1.begin(),nums1.size(),nums2.begin(),nums2.size(),total / 2) +
                        find_kth(nums1.begin(),nums1.size(),nums2.begin(),nums2.size(),total / 2 + 1)) / 2.0;

            }
        }
    private:
        /* find kth */
        int find_kth(Iter nums1,int m,Iter nums2,int n,int k) {

            if(m > n) //始终保证m是较小的
                return find_kth(nums2,n,nums1,m,k);

            if(m == 0)
                return nums2[k - 1];

            if(k == 1)
                return *nums1 > *nums2 ? *nums2 : *nums1;
            //均分
            int l1 = min(k / 2,m);
            int l2 = k - l1;
            if (nums1[l1 - 1] == nums2[l2 - 1]) //第一种情况
                return nums1[l1 - 1];

            if(nums1[l1 - 1] < nums2[l2 - 1]) //第二种情况
                return find_kth(nums1 + l1,m - l1,nums2,n,k - l1);

            if(nums2[l2 - 1] < nums1[l1 - 1]) //第三种情况
                return find_kth(nums1,m,nums2 + l2,n - l2,k - l2);
        }
};


int main()
{
    Solution2 so;
    Solution3 so3;
    vector<int>nums1 = {3};
    vector<int>nums2 = {1,2,4};
 //   cout << so.findMedianSortedArrays(nums1,nums2) << endl;
    cout << so3.findMedianSortedArrays(nums1,nums2) << endl;
}
