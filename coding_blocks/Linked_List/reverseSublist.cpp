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

node* reverseSubList(node* &head, int start, int finish){
	if(head==NULL){
		return head;
	}
	node* s = head;
	int count = 1;
	while(count<start){
		s = s->next;
		count++;
	}
	node* f = s;
	while(count<finish){
		f = f->next;
		count++;
	}
	cout<<f->data<<" "<<s->data<<endl;
	node* curr = s->next;
	node* next_node = curr->next;
	while(start++<finish){
		next_node = curr->next;
		curr->next = curr->next->next;
		next_node->next = s->next;
		s->next = next_node;
		// next_node = curr->next;
		// curr->next = next_node->next;
		// next_node->next = s->next;
		// s->next = next_node;
	}
}

int main(){
	node* head = NULL;
	insert_at_back(head,10);
	insert_at_back(head,9);
	insert_at_back(head,8);
	insert_at_back(head,7);
	insert_at_back(head,6);
	insert_at_back(head,5);
	insert_at_back(head,4);
	insert_at_back(head,3);
	insert_at_back(head,2);
	insert_at_back(head,1);
	printList(head);
	reverseSubList(head,2,7);
	printList(head);
	return 0;
}