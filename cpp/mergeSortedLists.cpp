/*
Merge two sorted linked lists and return it as a new list. 
list 1: 1->3->5->7
list 2: 2->4->6->8
result : 1->2->3->4->5->6->7->8
*/

#include <iostream>
#include <cstddef>

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL){}
};

class Solution{
public:
	ListNode* mergeSortedLists(ListNode* lst1, ListNode* lst2){
		if(lst1 == NULL)
			return lst2;
		if(lst2 == NULL)
			return lst1;
		ListNode* head = NULL;

		if(lst1->val < lst2->val){
			head = lst1;
			head->next = mergeSortedLists(lst1->next, lst2);
		}else{
			head = lst2;
			head->next = mergeSortedLists(lst1, lst2->next);
		}
		return head;
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
	ListNode* head = s.mergeSortedLists(createLinkedList({1,3,5,7}), createLinkedList({2,4,6,8}));
	for (ListNode *cur=head; cur; cur=cur->next)
        std::cout << cur->val << "->";
    std::cout << std::endl;
}

