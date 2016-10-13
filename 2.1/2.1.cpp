#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){};
};

void removeDup(ListNode *linklist)
{
	unordered_set<int> S;
	ListNode *cur = linklist;
	while (linklist)
	{
		if (S.find(linklist->val) != S.end()) //找到了，则删除该节点
		{
			cur = linklist->next;
			delete linklist;
		}
		else
		{
			S.insert(linklist->val);
			linklist = linklist->next;
		}
	}
}

int main()
{
	cout << "please input a list to construct linklist,split by blank." << endl;
	int val;
	ListNode *head = new ListNode(0);
	ListNode *cur = head;
	while (cin >> val)
	{
		ListNode *tmp = new ListNode(val);
		cur->next=tmp;
		cur = cur->next;
	}
	ListNode *it = head->next;
	while (it!=NULL)
	{
		int v = it->val;
		cout << v << "->";
		it = it->next;
	}

	removeDup(head->next);
	cout << "after remove:" << endl;
	ListNode *it1 = head;
	while (!it1->next)
	{
		cout << it1->val << "->";
		it1 = it1->next;
	}

	return 0;
}
