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
 *  链表逆置是比较简单的,可以利用头插法来做,每摘入一个节点就头插法插入
 *
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *tmp_head = head;
        ListNode *tmp_next = NULL;
        ListNode *tmp_root = new ListNode(0);
        tmp_root->next = NULL;
        while(tmp_head)
        {
            tmp_next = tmp_head->next; //临时保存下一个元素

            //头插法
            tmp_head->next = tmp_root->next;
            tmp_root->next = tmp_head;

            //遍历下一个元素
            tmp_head = tmp_next;
        }
        tmp_head = tmp_root->next;
        delete tmp_root;
        return tmp_head;
    }
};


int main()
{

}
