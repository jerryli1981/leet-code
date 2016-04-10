#import <iostream>
#import <cstddef>

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL){}
};

class Solution{
public:
	ListNode* findFirstCommonNode(ListNode* listA, ListNode* listB){

		int lengthA = getListLength(listA);
		int lengthB = getListLength(listB);

		int lengthDif = lengthA - lengthB;
		ListNode* listLong = listA;
		ListNode* listShort = listB;

		if (lengthB > lengthA){
			listLong = listB;
			listShort = listA;
			lengthDif = lengthB - lengthA;
		}

		for(int i=0; i<lengthDif; i++)
			listLong = listLong->next;

		while(listLong != NULL && listShort != NULL && listLong != listShort){

			listLong = listLong->next;
			listShort = listShort->next;
		}

		return listLong;
	}

private:
	int getListLength(ListNode* head){
		int length = 0;
		ListNode* pNode = head;
		while(pNode != NULL){
			length++;
			pNode = pNode->next;
		}
		return length;
	}
};


int main(){

    Solution s;

    ListNode* listA = new ListNode(1);
    ListNode* listA_1 = new ListNode(2);
    ListNode* listA_2 = new ListNode(3);

    listA->next = listA_1;
    listA_1->next = listA_2;

    ListNode* listB = new ListNode(9);
    listB->next = listA_1;

    ListNode* commonNode = s.findFirstCommonNode(listA, listB);
    std::cout << commonNode->val << std::endl;
}