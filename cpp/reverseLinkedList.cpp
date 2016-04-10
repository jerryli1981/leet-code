#include <iostream>
#include <cstddef>

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode* reverseList(ListNode* pHead){
        ListNode* pReversedHead = NULL;
        ListNode* pNode = pHead;
        ListNode* pPrev = NULL;

        while(pNode != NULL){

            // prevent 
            ListNode* pNext = pNode->next;

            if(pNext == NULL) 
                pReversedHead = pNode;

            //assign
            pNode->next = pPrev;

            //move pointer
            pPrev = pNode;
            pNode = pNext;
        }

        return pReversedHead;
    }

};


ListNode* createLinkedList(std::initializer_list<int> lst){
    auto iter = lst.begin();
    ListNode *head = lst.size() ? new ListNode(*iter++) : NULL;
    for (ListNode *cur=head; iter != lst.end(); cur=cur->next)
        cur->next = new ListNode(*iter++);
    return head;
}


int main(){

    Solution s;
    ListNode *head = s.reverseList(createLinkedList({1,2,3,4,5}));
    for (ListNode *cur=head; cur; cur=cur->next)
        std::cout << cur->val << "->";
    std::cout << "\b\b  " << std::endl;   
}