#include <stdio.h>
#include <iostream>
#include<vector>
#include <stdlib.h>
using namespace std;

//g++ -std=c++11 FindKthToTail.cpp -o FindKthToTail
// test.cpp : 定义控制台应用程序的入口点。
//
#include <exception>
using namespace std;

//树定义
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
	if (pCurrent == nullptr)
	{
		printf("Error to connect two nodes.\n");
		exit(1);
	}

	pCurrent->next = pNext;
}

void PrintListNode(ListNode* pNode)
{
	if (pNode == nullptr)
	{
		printf("The node is nullptr\n");
	}
	else
	{
		printf("The key in node is %d.\n", pNode->val);
	}
}

void PrintList(ListNode* pHead)
{
	printf("PrintList starts.\n");

	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		printf("%d\t", pNode->val);
		pNode = pNode->next;
	}

	printf("\nPrintList ends.\n");
}

void DestroyList(ListNode* pHead)
{
	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		pHead = pHead->next;
		delete pNode;
		pNode = pHead;
	}
}

//void AddToTail(ListNode** pHead, int value)
//{
//	ListNode* pNew = new ListNode();
//	pNew->val = value;
//	pNew->next = nullptr;
//
//	if (*pHead == nullptr)
//	{
//		*pHead = pNew;
//	}
//	else
//	{
//		ListNode* pNode = *pHead;
//		while (pNode->next != nullptr)
//			pNode = pNode->next;
//
//		pNode->next = pNew;
//	}
//}

void RemoveNode(ListNode** pHead, int value)
{
	if (pHead == nullptr || *pHead == nullptr)
		return;

	ListNode* pToBeDeleted = nullptr;
	if ((*pHead)->val == value)
	{
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->next;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->next != nullptr && pNode->next->val != value)
			pNode = pNode->next;

		if (pNode->next != nullptr && pNode->next->val == value)
		{
			pToBeDeleted = pNode->next;
			pNode->next = pNode->next->next;
		}
	}

	if (pToBeDeleted != nullptr)
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}

//--------------------------分割线----------------------------------------//

class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) 
	{
		if (pListHead == nullptr || k == 0)
			return nullptr;

		ListNode *pAhead = pListHead;//设置两个指针
		ListNode *pBehind = nullptr;

		for (unsigned int i = 0; i < k - 1; ++i)
		{
			if (pAhead->next != nullptr)
				pAhead = pAhead->next;
			else
			{
				return nullptr;
			}
		}
		pBehind = pListHead;
		while (pAhead->next != nullptr)
		{
			pAhead = pAhead->next;
			pBehind = pBehind->next;
		}
		return pBehind;
	}
};

int main(int argc, char* argv[])
{
	Solution so;
	printf("=====Test1 starts:=====\n");
	ListNode* pNode1 = new ListNode(1);
	ListNode* pNode2 = new ListNode(2);
	ListNode* pNode3 = new ListNode(3);
	ListNode* pNode4 = new ListNode(4);
	ListNode* pNode5 = new ListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	printf("expected result: 4.\n");
	ListNode* pNode = so.FindKthToTail(pNode1, 2);
	PrintListNode(pNode);
	getchar();
}