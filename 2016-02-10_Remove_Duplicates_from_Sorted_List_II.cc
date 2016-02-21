#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) { }
};

/*
 *  基本思路很简单:
 *  方法1: 先扫描一遍找到只出现一次的元素位置，然后再遍历一次将这些元素摘取下来链接起来
 *  方法2: 一次遍历即可步骤如下:
 *      对于1 2 2 2 3 4 5 5 6
 *      Setp1: fisrt指向1,last从2开始,flag = 0
 *      Setp2: last != first 并且flag = 0.那么first是一个只出现一次的元素，摘取下来
 *              然后first指向last，last++,flag = 0;重复步骤2,此时first == last
 *              那么last++即可flag=1，直到last指向了3，此时重复步骤２，发现last != first，但是flag=1
 *              因此first指向的元素是出现多次的，因此不用管，重新设置first指向last,last++,flag=0
 *
 *
 *
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
            if(!head || !head->next) return head;
            ListNode dummy(-1);
            ListNode *p_dummy = &dummy;
            ListNode *p_first = head;   //p_first就是步骤中描述的first
            bool flag = false;
            //head就是步骤中的last
            head = head->next;
            while(head) {

                if(head->val != p_first->val) {

                    if(!flag) { //只出现了一次

                        p_dummy->next = p_first;
                        p_dummy = p_first;
                        flag = false;
                        p_first = head;
                        head = head->next;
                        continue;

                    } else {    //出现了多次

                     // delete p_first;
                        p_first = head;
                        flag = false;
                        head = head->next;
                        continue;
                    }

                } else {

                    //释放last所指的元素，继续向后遍历
                    ListNode *tmp = head->next;
                    // delete head;
                    head = tmp;
                    flag = true;
                }
            }

            if(!flag) {

                p_dummy->next = p_first;
                p_dummy->next->next = nullptr;

            } else {

                p_dummy->next = nullptr;

            }

            return dummy.next;
    }
};

int main()
{
    ListNode node(1);
    ListNode node2(2);
    ListNode node3(2);
    node.next = &node2;
    //node.next->next = &node3;
    Solution so;
    ListNode *p = so.deleteDuplicates(&node);
    while(p) {
        cout << p->val << endl;
        p = p->next;
    }
}
