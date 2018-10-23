//
// Created by marvinle on 2018/10/12.
//

#include <vector>
using namespace std;

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 思路: 二分递归分别排序
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return nullptr;
        if(lists.size() == 1)
            return lists[0];
        return division(lists, 0, lists.size()-1);
    }

private:

    ListNode* division(vector<ListNode*>& list, int begin, int end){
        if(begin == end)
            return list[begin];
        if((end - begin) == 1)
            return mergeTwoLists(list[begin],list[end]);
        int mid = begin+(end-begin)/2;
        ListNode* list1 = division(list, begin, mid);
        ListNode* list2 = division(list, mid+1, end);
        return mergeTwoLists(list1, list2);
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *cur1, *cur2, *newList, *newcur, *temp;
        // 带头节点链表
        newList = new ListNode(0);
        newList->next = nullptr;
        newcur = newList;
        cur1 = l1;
        cur2 = l2;
        while(cur1 != nullptr && cur2 != nullptr){
            if(cur1->val < cur2->val){
                temp = cur1->next;
                cur1->next = nullptr;
                newcur->next = cur1;
                cur1 = temp;
            } else {
                temp = cur2->next;
                cur2->next = nullptr;
                newcur->next = cur2;
                cur2 = temp;
            }
            newcur = newcur->next;
        }
        if (cur1 != nullptr)
            newcur->next = cur1;
        if (cur2 != nullptr)
            newcur->next = cur2;
        return newList->next;
    }
};

