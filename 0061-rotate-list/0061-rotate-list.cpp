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
    ListNode* rotateRight(ListNode* head, int k) {
        //edge case
        if(head == NULL || head->next == NULL || k==0)
            return head;
        
        //find length and last node
        int len =1;
        ListNode* tail = head;

        while(tail->next != NULL){
            tail = tail->next;
            len++;
        }

        //reduce unnecessary rotations
        k = k%len;

        if(k==0){
            return head;
        }
        //make circular linked list
        tail->next = head;

        //find new tail
        int steps = len-k;
        ListNode* newtail = head;

        for(int i=1;i<steps;i++){
            newtail = newtail->next;
        }

        //new head
        ListNode* newhead = newtail->next;

        //break circle 
        newtail->next = NULL;

        return newhead;        
    }
};