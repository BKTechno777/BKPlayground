#include <iostream>

using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     unsigned int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class LinkedList
{
private:
	ListNode* head;

public:
	LinkedList() : head(nullptr)
	{}

	void append(int val)
	{
		ListNode* newNode = new ListNode(val);
		if (!head)
		{
			head = newNode;
			return;
		}

		ListNode* temp = head;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}

	void displayList()
	{
		ListNode* temp = head;
		while (temp)
		{
			cout << temp->val << endl;
			temp = temp->next;
		}
	}

	ListNode* getListNode()
	{
		return head;
	}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		/*unsigned long long int num1 = findListValue(l1);
		cout << num1 << endl;
		unsigned long long int num2 = findListValue(l2);
		unsigned long long int sum = num1 + num2;*/
		ListNode* addedList = createSumListFromLists(l1, l2);
		return addedList;
	}

	unsigned long long int findListValue(ListNode* numList);
	ListNode* createListFromNum(unsigned long long int sum);
	ListNode* createSumListFromLists(ListNode* l1, ListNode* l2);
	ListNode* reverseList(ListNode* myList);
};

void displayListTemp(ListNode* myList)
{
	ListNode* temp = myList;
	while (temp)
	{
		cout << temp->val << endl;
		temp = temp->next;
	}
}


unsigned long long int Solution::findListValue(ListNode* numList)
{
	// Reverse a list

	ListNode* prevNode = nullptr;
	ListNode* currNode = numList;
	ListNode* nextNode = nullptr;

	while (currNode != nullptr)
	{
		nextNode = currNode->next;
		currNode->next = prevNode;
		prevNode = currNode;
		currNode = nextNode;
	}
	
	ListNode* reveseList = prevNode;

	unsigned long long int num = 0;
	unsigned int factor = 10;
	ListNode* temp = reveseList;
	while (temp)
	{
		num = num * factor + temp->val ;
		temp = temp->next;
	}
	return num;
}

ListNode* Solution::createListFromNum(unsigned long long int sum)
{
	unsigned long long int val = sum % 10;
	sum = sum / 10;

	ListNode* head = new ListNode(val);
	ListNode* temp = head;
	while (sum != 0)
	{
		val = sum % 10;
		sum = sum / 10;
		ListNode* newNode = new ListNode(val);
		temp->next = newNode;
		temp = newNode;
	}
	return head;
}

ListNode* Solution::createSumListFromLists(ListNode* l1, ListNode* l2)
{


	ListNode* dummy = new ListNode(0);
	ListNode* current = dummy;
	int carry = 0;

	// Traverse through both the lists
	while (l1 != nullptr || l2 != nullptr || carry != 0)
	{
		int val1 = (l1 != nullptr ? l1->val : 0);
		int val2 = (l2 != nullptr ? l2->val : 0);

		int sum = val1 + val2 + carry;
		carry = sum / 10;
		int newVal = sum % 10;

		current->next = new ListNode(newVal);
		current = current->next;

		if (l1 != nullptr)
		{
			l1 = l1->next;
		}

		if (l2 != nullptr)
		{
			l2 = l2->next;
		}
	}

	return dummy->next;


	//ListNode* l1Revese = reverseList(l1);
	//ListNode* l2Reverse = reverseList(l2);
	/*ListNode* l1Revese = l1;
	ListNode* l2Reverse = l2;
	unsigned int carry = 0;

	ListNode* sumList = nullptr;
	ListNode* temp = nullptr;
	while (l1Revese || l2Reverse)
	{
		unsigned int sumVal = 0;
		if (l1Revese && l2Reverse)
		{
			carry = (l1Revese->val + l2Reverse->val + carry) / 10;
			sumVal = (l1Revese->val + l2Reverse->val + carry) % 10;
			l1Revese = l1Revese->next;
			l2Reverse = l2Reverse->next;
		}
		else if (l1Revese == nullptr && l2Reverse)
		{
			sumVal = (l2Reverse->val + carry) / 10;
			carry = (l2Reverse->val + carry) % 10;
			l2Reverse = l2Reverse->next;
		}
		else
		{
			sumVal = (l1Revese->val + carry) / 10;
			carry = (l1Revese->val + carry) % 10;
			l1Revese = l1Revese->next;
		}

		ListNode* newNode = new ListNode(sumVal);
		if (!sumList)
		{
			sumList = newNode;
			temp = newNode;
		}
		else
		{
			temp->next = newNode;
			temp = newNode;
		}
	}*/

	//return sumList;
}

ListNode* Solution::reverseList(ListNode* myList)
{
	// Reverse a list

	ListNode* prevNode = nullptr;
	ListNode* currNode = myList;
	ListNode* nextNode = nullptr;

	while (currNode != nullptr)
	{
		nextNode = currNode->next;
		currNode->next = prevNode;
		prevNode = currNode;
		currNode = nextNode;
	}
	return prevNode;
}


LinkedList createList(unsigned int arr[], unsigned int size)
{
	LinkedList myList;
	for (unsigned int i = 0; i < size; i++)
	{
		myList.append(arr[i]);
	}
	return myList;
}

#define LIST1_LEN 4
#define LIST2_LEN 3

int main()
{
	/*unsigned int arr[LIST1_LEN] = { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };
	unsigned int arr1[LIST2_LEN] = { 5, 6, 4 };*/
	unsigned int arr[LIST1_LEN] = { 2, 4, 3, 7 };
	unsigned int arr1[LIST2_LEN] = { 5, 6, 4 };
	LinkedList myList1 = createList(arr, LIST1_LEN);
	ListNode* list1 = myList1.getListNode();

	LinkedList myList2 = createList(arr1, LIST2_LEN);
	ListNode * list2 = myList2.getListNode();

	Solution solution;
	ListNode* addedList = solution.addTwoNumbers(list1, list2);

	displayListTemp(addedList);

	return 0;
}