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

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
/*
 *  这题不太好懂，分析如下:
 *  next指针指向
 *  old1->old2->old3->old4
 *  random指针指向
 *  old1->random == old3
 *  old4->random == old2
 *
 *  Setp1: new新节点，并插入原来的节点中间
 *      old1->new1->old2->new2->old3->new3->old4->new4
 *  Setp2:
 *      new1->random = old1->random->next;
 *      因为old1->random是old3,要深度拷贝，因此new->random应该指向new3
 *      而new3正好是old1->random->next
 *
 *  Setp3: 将两个链表拆分
 *      old1->next = old1->next->next;
 *      new1->next = new1->next->next;
 *
 *
 * 方法2: 用hashmap保存新老节点的关系，如下:
 *
 *
 * old1->random = old3
 * Setp1: 建立新老指针的关系
 *  old1和new1  old2和new2  old3和new3
 *  new1->new2->new3
 *
 * Setp2: 建立random关系
 * 查看old1对应的random是哪个，发现是old3
 * 因此只要用old1对应的新节点new1的random指针指向old3对应的新节点即可
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        for(RandomListNode *cur = head; cur != nullptr;) {
            RandomListNode *node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }

        for(RandomListNode *cur = head; cur != nullptr;) {
            if(cur->random != NULL)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        RandomListNode dummy(-1);
        for(RandomListNode *cur = head,*new_cur = &dummy; cur != nullptr;) {
            new_cur->next = cur->next;
            new_cur = new_cur->next;
            cur->next = cur->next->next;
            cur = cur->next;
        }
        return dummy.next;
    }
};

int main()
{

}
