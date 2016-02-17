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
                ListNode node(0);
                ListNode *p_node = &node;
                if(!head) return nullptr;
                p_node->next = head;
                p_node = head;
                head = head->next;

                while(head) {

                    if(head->val == p_node->val) {
                        ListNode *tmp = head->next;
                        delete head;
                        head = head->next;
                        continue;
                    }

                    p_node->next = head;
                    p_node = head;
                    head = head->next;
                }
                p_node->next = nullptr;

                return node.next;
        }
};
int main()
{

}
