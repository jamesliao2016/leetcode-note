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
 *  类似与Reverse Single List
 *
 *
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *first = head;
        ListNode *prev = nullptr;
        int reverse_number =  n - m + 1;
        while(--m) {
            prev = first;
            first = first->next; //定位到第一个要逆转的元素
        }
        ListNode *first_head = new ListNode(0); //临时的链表头
        ListNode *next = first->next;
        ListNode *first_end = first;
        while(reverse_number-- && first) {
            next = first->next; //保存尾部的第一个元素

            first->next = first_head->next;
            first_head->next = first;

            first = next;
        }
        //逆转部分和开始结尾部分合并
        if(prev)
            prev->next = first_head->next; //头部和逆转部分合并了
        else
            head = first_head->next;

        delete first_head;
        first_end->next = next;        //逆转部分的结尾节点和整个链表的结尾部分首节点合并
        return head;
    }
};

int main()
{
    ListNode node(3);
    ListNode node2(5);
    node.next = &node2;
    Solution so;
    ListNode *ret = so.reverseBetween(&node,1,2);
    while(ret) {
        cout << ret->val << endl;
        ret = ret->next;
    }
}
