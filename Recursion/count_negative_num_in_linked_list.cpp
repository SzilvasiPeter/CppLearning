#include <iostream>
using namespace std;

struct listNode{
	int data;
	listNode* next;
};
typedef listNode* listPtr;

int countNegative(listPtr head){
	if(head == NULL) return 0;
	int listCount = countNegative(head->next);
	if(head->data < 0) listCount++;

	return listCount;
}

void displayForwardsRecursion(listPtr head){
	if(head != NULL){
		cout << head->data << "\n";
		displayForwardsRecursion(head->next);
	}
}

void displayBackwardsRecursion(listPtr head){
	if(head != NULL){
		displayBackwardsRecursion(head->next);
		cout << head->data << "\n";
	}
}

void displayListForwardIterative(listPtr head){
	for(listPtr current = head; current != NULL; current = current->next){
		cout << current->data << "\n";
	}
}

void displayLitBackwardIterative(listPtr head){
	stack<listPtr> nodes;
	for(listPtr current = head; current != NULL; current = current->next)
		nodes.push(current);
	while(!nodes.empty()){
		listPtr current = nodes.top();
		nodes.pop();
		cout << current->data << "\n";
	}
}