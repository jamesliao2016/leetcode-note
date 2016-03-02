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
 *  找到链表的中间，然后将链表的后半部分逆转，最后将两个部分进行合并
 *  Setp1: 找到中间位置
 *  Setp2: 后半部分头插法逆转
 *  Setp3: 两个部分合并
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        //setp1 快慢指针找到中间，而不是先求长度，在计算中间位置，最后定位到中间
        ListNode *slow = head,*fast = head;
        ListNode *prev_slow = nullptr; //slow指针最终指向mid节点，prev_slow则指向slow的前一个节点
        while(fast && fast->next) {
            prev_slow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if(prev_slow)
            prev_slow->next = nullptr; //设置前半部分的结束标志
        ListNode dummy(-1);
        ListNode *p_dummy = &dummy;

        //Setp2 翻转后半部分
        while(slow) {

            ListNode *tmp = slow->next;
            slow->next = p_dummy->next;
            p_dummy->next = slow;
            slow = tmp;
        }

        //Setp3 合并两个部分
        p_dummy = p_dummy->next;
        ListNode head_dummy(-1);
        ListNode *p_head_dummy = &head_dummy;

        while(head && p_dummy)
        {
            p_head_dummy->next = head;
            p_head_dummy = head;
            head = head->next;

            p_head_dummy->next = p_dummy;
            p_head_dummy = p_dummy;
            p_dummy = p_dummy->next;
        }

        ListNode *end = nullptr;
        if(head) end = head;
        if(p_dummy) end = p_dummy;

        if(end) {
            p_head_dummy->next = end;
            p_head_dummy = end;
            end = end->next;
        }


    }
};

int main()
{
    ListNode node(1),node2(2),node3(3),node4(4);
    node.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    Solution so;
    so.reorderList(&node);
    ListNode *p = &node;
    while(p) {
        cout << p->val << endl;
        p = p->next;
    }
}
