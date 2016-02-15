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


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flag = 0;
        ListNode *head = l1;
        ListNode *prev;
        while(l1->next && l2->next) {
            l1->val = l1->val + l2->val + flag;
            l1->val = l1->val >= 10 ? (flag = 1,l1->val - 10) : (flag=0,l1->val);
            l1 = l1->next;
            l2 = l2->next;
        }

        if(!l1->next && !l2->next) {
            l1->val = l1->val + l2->val + flag;
            l1->val = l1->val >= 10 ? (flag = 1,l1->val - 10) : (flag=0,l1->val);
            prev = l1;
            l1 = l1->next;
            goto end;
        }

        if(!l1->next) {
            l1->val = l1->val + l2->val + flag;
            l1->val = l1->val >= 10 ? (flag = 1,l1->val - 10) : (flag=0,l1->val);
            l2 = l2->next;
            while(l2) {
                ListNode *new_node = new ListNode(l2->val + flag);
                new_node->val = new_node->val >= 10 ? (flag = 1,new_node->val - 10) : (flag=0,new_node->val);
                l1->next = new_node;
                l1 = new_node;
                prev = l1;
                l2 = l2->next;
            }
            goto end;
        }

        if(!l2->next) {
            l1->val = l1->val + l2->val + flag;
            l1->val = l1->val >= 10 ? (flag = 1,l1->val - 10) : (flag = 0,l1->val);
            l1 = l1->next;
            while(flag && l1) {
                l1->val = l1->val + flag;
                l1->val = (l1->val >= 10) ? (flag = 1,l1->val - 10) : (flag=0,l1->val);
                prev = l1;
                l1 = l1->next;
            }
        }

    end:
        if(flag && !l1) {
            ListNode *new_node = new ListNode(1);
            prev->next = new_node;
        }
        return head;
    }
};

int main()
{

}
