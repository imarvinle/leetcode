//
// Created by marvinle on 2018/10/25 下午11:47.
//

// 题号:142

#include <set>
#include <vector>
#include <string>


struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 可以存储指向每个节点的节点个数，个数为2的就是环的入口点
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast, *slow;
        set<ListNode*> st;

        bool has_cycle = false;
        if (head == NULL)
            return NULL;
        fast = head;
        slow = head;
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
            {
                has_cycle = true;
                break;
            }
        }
        if(has_cycle)
        {
            slow = head;
            while(st.count(slow) == 0)
            {
                st.insert(slow);
                slow = slow->next;
            }
            return slow;
        } else
        {
            return NULL;
        }
    }
};
