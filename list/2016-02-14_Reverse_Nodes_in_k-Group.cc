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
 *  相比与swap node pair来说难度大了，要根据给定的k来进行翻转
 *
 *
 *
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1)return head;
        ListNode dummy(-1);
        ListNode *p_dummy = &dummy;
        int count=0;
        ListNode *first = head;
        ListNode *end = nullptr;
        ListNode *prev = nullptr;
        while(head) {
            ++count;
            prev = head;
            ListNode *tmp = head->next;
            if(count % k == 0) {
                end = head;
                p_dummy->next = reverse(first,end);
                p_dummy = first; //此时的first是逆转后的最后一个元素;
                first = tmp;
                head = tmp;

            } else {
                head = tmp;
            }
        }

        if(count % k == 0) {
            p_dummy->next = nullptr; //设置结束标志
        }

        p_dummy->next = first;

        return dummy.next;

    }

private:
    //逆转给定区间的几个节点
    ListNode* reverse(ListNode *first,ListNode *end) {

        ListNode dummy(-1);
        ListNode *p_dummy = &dummy;

        while(first != end) {

            ListNode *tmp = first->next;
            first->next = p_dummy->next;
            p_dummy->next = first;
            first = tmp;
        }
        first->next = p_dummy->next;
        p_dummy->next = first;
        return dummy.next;
    }
};

int main()
{

}
