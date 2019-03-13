//
// Created by marvinle on 2018/11/16 7:57 PM.
//

/**
 * 题目描述: 86
 * 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
 * 你应当保留两个分区中每个节点的初始相对位置。
 */

/**
 * 输入: head = 1->4->3->2->5->2, x = 3
 * 输出: 1->2->2->4->3->5
 */

#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // 思路双指针
        ListNode *slow = nullptr;
        ListNode *fast = head;
        ListNode *pre = nullptr;

        while(fast != nullptr)
        {
            ListNode *temp = fast->next;
            if(fast->val < x)
            {
                // 连接fast前后
                if(pre != nullptr)
                {
                    pre->next = fast->next;
                }
                // 插到头上
                if(slow == nullptr){
                    if(fast == head) {
                        slow = fast;
                    }  else {
                        slow = fast;
                        slow->next = head;
                        head = slow;
                    }
                } else {
                    // 避免slow和fast相邻时导致的环
                    if(slow->next != fast){
                        fast->next = slow->next;
                    }
                    slow->next = fast;
                    slow = fast;
                }

            } else {
                pre = fast;
            }
            fast = temp;
        }
        return head;
    }
    // 看起来更简介的解法还有用vector存起来，分为两个vector。最后再连接

    ListNode* partition2(ListNode* head, int x) {
        if(head == nullptr)
            return head;

        vector<ListNode*> pre;
        vector<ListNode*> aft;
        while(head != nullptr)
        {
            if(head->val < x)
            {
                pre.push_back(head);
            } else {
                aft.push_back(head);
            }
            head = head->next;
        }
        bool firstIsAft = false;

        if(!pre.empty()) {
            head = pre.front();
        }
        if(head == nullptr){
            head = aft.front();
            firstIsAft = true;
        }
        ListNode *temp = head;

        vector<ListNode*>::iterator it = pre.begin();
        if(!firstIsAft)
            ++it;
        for(;it != pre.end(); it++)
        {
            temp->next = *it;
            temp = *it;
        }
        it = aft.begin();
        if(firstIsAft)
            ++it;

        for(;it != aft.end(); it++)
        {
            temp->next = *it;
            temp = *it;
        }
        temp->next = nullptr;
        return head;

    }
};

int main()
{
    Solution solution;
    ListNode *node = new ListNode(1);
    node = solution.partition2(node, 1);
    while(node != nullptr)
    {
        cout << node->val << endl;
        node = node->next;
    }
}

