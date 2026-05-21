/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }

        ListNode* midNode = mid(head);
        ListNode* rightPart = midNode->next;
        midNode->next = nullptr;

        ListNode* leftSorted = sortList(head);
        ListNode* rightSorted = sortList(rightPart);

        return mergeTwoLists(leftSorted, rightSorted);
    }
private:
    ListNode* mid(ListNode* head){
      ListNode* slow = head;
      ListNode* fast = head->next;
      while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
      }
      return slow;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* answ = new ListNode(0);
        ListNode* dummy = answ;
        while(list1 && list2){
            if(list1->val < list2->val){
                dummy->next = list1;
                list1 = list1->next;
            }else{
                dummy->next = list2;
                list2 = list2->next;
            }
            dummy = dummy->next;
        }
        dummy->next = list1 ? list1 : list2;
        return answ->next;
    }

};

