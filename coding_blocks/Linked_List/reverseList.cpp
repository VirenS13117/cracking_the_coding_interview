#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* next;
	node(int value){
		data = value;
		next = NULL;
	}
};

void insert_at_back(node* &head, int value){
	if(head==NULL){
		node* new_node = new node(value);
		head = new_node;
		return;
	}
	node* temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	node* new_node = new node(value);
	temp->next = new_node;
	return;
}

void printList(node* head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
	return;
}

node* reverseList(node* head){
	if(head==NULL||head->next==NULL){
		return head;
	}
	node* n = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;
	return n;
}

int main(){
	node* head = NULL;
	insert_at_back(head,5);
	insert_at_back(head,4);
	insert_at_back(head,3);
	insert_at_back(head,2);
	insert_at_back(head,1);
	printList(head);
	head = reverseList(head);
	printList(head);
	return 0;
}