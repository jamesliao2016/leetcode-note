#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) { }
};

/*
 *  每两个元素之间进行位置调换，一次遍历完成，实现起来还是很容易的
 *  头插法，每插入两个元素就将指针移动到最后一次插入的位置例如:
 *
 *
 *
 *
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(-1);
        ListNode *p_dummy = &dummy;
        int count = 0;

        while(head) {
            ++count;
            ListNode *tmp = head->next;
            if(count % 2 != 0) {

                head->next = p_dummy->next;
                p_dummy->next = head;
                head = tmp;

            } else {

                head->next = p_dummy->next;
                p_dummy->next = head;
                p_dummy = head->next; //向前移动
                head = tmp;
            }
        }

        return dummy.next;
    }
};

int main()
{

}
