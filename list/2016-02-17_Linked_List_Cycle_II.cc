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
 *  此题有一定难度，需要推导:
 *  当fast和slow相遇时，slow肯定没有遍历完链表，而fast已经在环内循环了n圈，
 *  假设slow走了s步，而fast走了2s步 等于s+n*r n是跑了n圈,r是环长，
 *  2s = s + nr
 *  s = nr
 *  假设整个链表长l,环入口点到相遇点距离为a，起点到环入口点距离为x,则
 *  x + a = nr =(n-1)r + r = (n-1)r + L -x
 *  x = (n-1)r + (l-x -a)
 *  l-x-a为相遇点到环入口点的距离，由此可知，链表头到环入口点等于n-1圈+相遇点到环入口点
 *  于是可以从head开始另设一个指针slow2，两个指针每次前进异步，两个一定会再环入口点相遇
 *
 *
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                ListNode *slow2 = head;
                while(slow2 != slow) {
                    slow2 = slow2->next;
                    slow = slow->next;
                }
                return slow2;
            }
        }
        return nullptr;
    }
};

int main()
{

}
