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
    ListNode* deleteDuplicates(ListNode* head) {
            ListNode dummy(-1);
            ListNode *p_dummy = &dummy;
            ListNode *p_first = head;

            head = head->next;
            while(head) {
                if(head->val == p_first->val) {
                    //连续两者相同
                    if(head->next)
                        p_first = head->next;
                }
            }
    }
};

int main()
{

}
