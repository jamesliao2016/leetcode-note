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
 *  方法一:
 *      判断一个链表是否是有环，最简单的方法就是使用map来保存已经遍历过的节点
 *
 *  方法二:
 *      快慢指针，一个指针每次走一步，一个指针每次走两步如果在结束前相遇肯定就是有环，否则就是没环了
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *first = head;
        ListNode *second = head;
        int count = 0;
        while(second) {
            second = second->next;
            if(first == second)
                return true;
            ++count;
            if(count == 2) {
                first = first->next;
                count = 0;
            }
        }
        return false;
    }
};

int main()
{

 }
