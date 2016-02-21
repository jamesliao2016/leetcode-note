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
 *  这题难度也不大，利用两个指针即可
 *
 *  对于1 2 3 4 5  k=2 来说，最终的结果是4 5 1 2 3
 *  Setp1: first指向1,last指向3，两者之间的差就是k
 *  Setp2: ++fisrt ++last,直到last==null为止，此时fisrt指向4,
 *  Setp4: 利用head链接4 5,然后head遍历到4 5的尾部，然后将尾部重新指向 1 2 3的头即可
 *  需要处理k=5和k=0这两种特殊场景
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return head;
        if(!k) return head;
        ListNode dummy(-1);
        ListNode *p_dummy = &dummy;
        ListNode *p_first = head;
        ListNode *p_prev = p_first;
        ListNode *p_last = head;
        ListNode *p_last_prev = p_last;

        while(k-- && !p_last) {
            p_last_prev = p_last;
            p_last = p_last->next;
        }

        if(!p_last) return head;
        while(p_last) {
            p_prev = p_first;
            p_first = p_first->next;
            p_last_prev = p_last;
            p_last = p_last->next;
        }
        //此时p_first指向要翻转到头部的那个部分的第一个元素
        p_prev->next = nullptr;
        p_last_prev->next = head;

        return p_first;
    }
};

/*
 *  解法一是不正确的，没有考虑到k会大于链表长度，并且题目要求是循环翻转
 *  对于1 2 k=3来说，结果是 2 1因此需要将链表连接成一个环形，然后向后遍历len - k步就可以了
 *  k需要 k %= len
 *
 *
 *
 */
class Solution2 {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || !head) return head;
        int len = 1;
        ListNode *p_head = head;
        ListNode *p_prev = head;

        while(p_head->next) {
            p_head = p_head->next;
            ++len;
        }
        p_head->next = head; //链接成环型
        k %= len;
        k = len - k;
        while(k--) {
            p_head = p_head->next;
        }

        ListNode *ret = p_head->next;
        p_head->next = nullptr;
        return ret;


    }
};

int main()
{
    ListNode node(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    node.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    Solution2 so;
    ListNode *ret = so.rotateRight(&node,6);
    while(ret) {
        cout << ret->val << endl;
        ret = ret->next;
    }
}
