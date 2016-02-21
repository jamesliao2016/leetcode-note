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
 *  两个指针一次遍历,first指针和last指针相差n，
 *  需要处理好n=0还有head为空，以及n等于链表长度的时候这几种特殊情况
 *
 *
 */
class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            if(!head || !n) return head; //特殊情况
            ListNode *first = head;
            ListNode *last = head;

            while(n-- && last) {
                last = last->next;
            }

            if(!last) return head->next; //特殊情况

            while(last->next) {
                last = last->next;
                first = first->next;
            }
            ListNode *tmp = first->next;
            first->next = last->next;
            delete tmp;
            return head;
        }
};

int main()
{

}
