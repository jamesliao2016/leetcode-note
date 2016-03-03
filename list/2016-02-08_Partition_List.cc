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
 *
 *  两个指针，一个指针负责连接左边部分，另一个指针负责连接右边部分
 *
 *
 *
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode first(0);
        ListNode end(0);
        ListNode *p_first = &first;
        ListNode *p_end = &end;

        while(head) {

            if(head->val < x) {
                //小于x的部分
                p_first->next = head;
                p_first = head;

            } else {
                //大于等于x的部分
                p_end->next = head;
                p_end = head;
            }

            head = head->next;
        }

        //连接左右两个部分
        p_end->next = nullptr;
        p_first->next = end.next;
        return first.next;
    }
};
int main()
{
    ListNode node(3);
    ListNode node2(2);
    node.next = &node2;

    Solution so;
    ListNode *ret = so.partition(&node,2);
    while(ret) {
        cout << ret->val << endl;
        ret = ret->next;
    }
}
