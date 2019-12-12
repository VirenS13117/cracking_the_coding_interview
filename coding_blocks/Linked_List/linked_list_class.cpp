#include<iostream>
using namespace std;

class node{
public:
	int data;
	node *next;
	node(int value){
		data = value;
		next = NULL;
	}
};


void print_list(node *head);
int length(node *head);
void insert_at_front(node* &head, node* &tail, int value);
void deletion_at_front(node* &head, node* &tail);
void insert_at_back(node * &head,node* &tail, int value);
void deletion_at_back(node* &head, node* &tail);
void insertAtPos(node* &head, node* &tail, int data, int pos);
void deleteAtPos(node* &head, node* &tail, int data, int pos);
node *find_node_iterative(node* head, int value);
node* bubble_sort(node* head);

void insert_at_front(node* &head, node* &tail, int value){
	if(head==NULL){
		node *n = new node(value);
		head = n;
		tail = n;
		return;
	}
	node *n = new node(value);
	n->next = head;
	head = n;
	return;
}

void deletion_at_front(node* &head, node* &tail){
	if(head==NULL){
		return;
	}
	if(head==tail){
		delete head;
		head = NULL;
		tail = NULL;
		return;
	}
	node *temp = head;
	head = head->next;
	delete temp;
	return;
}

void insert_at_back(node * &head,node* &tail, int value){
	if(head==NULL){
		node *n = new node(value);
		head = n;
		tail = n;
		return;
	}
	node *n = new node(value);
	tail->next = n;
	tail = n;
	return;
}

void deletion_at_back(node* &head, node* &tail){
	if(head==NULL){
		return;
	}
	if(head==tail){
		delete head;
		head = NULL;
		tail = NULL;
		return;
	}
	node *temp = head;
	while(temp->next!=tail){
		temp = temp->next;
	}
	delete tail;
	temp->next = NULL;
	tail = temp;
	return;
}

void print_list(node *head){
	while(head!=NULL){
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<"NULL"<<endl;
	return;
}

void insertAtPos(node* &head, node* &tail, int data, int pos){
	if(pos==0){
		insert_at_front(head,tail,data);
		return;
	}
	if(pos>=length(head)){
		insert_at_back(head,tail,data);
		return;
	}
	node *temp = head;
	int p = 1;
	while(p<pos){
		temp = temp->next;
		p++;
	}
	node *n = new node(data);
	n->next = temp->next;
	temp->next = n;
	return;
}

void deleteAtPos(node* &head, node* &tail, int pos){
	if(pos==0){
		deletion_at_front(head,tail);
		return;
	}
	if(pos>=length(head)-1){
		deletion_at_back(head,tail);
		return;
	}
	node *prev = head;
	int p = 1;
	while(p<pos){
		prev = prev->next;
		p++;
	}
	node *temp = prev->next;
	prev->next = prev->next->next;
	delete temp;
	return;
}

node *find_node_iterative(node* head, int value){
	while(head!=NULL){
		if(head->data == value){
			return head;
		}
		head = head->next;
	}
	return NULL;
}

node* find_node_recursive(node* head, int value){
	if(head==NULL){
		return NULL;
	}
	else if(head->data==value){
		return head;
	}
	else{
		return find_node_recursive(head->next,value);
	}
}

node* find_mid_point(node* head){
	if(head==NULL){
		return NULL;
	}
	node *slow = head;
	node *fast = head->next;
	while((fast!=NULL)&&(fast->next!=NULL)){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

node* merge_lists(node* head1, node* head2){
	if(head1==NULL){
		return head2;
	}
	if(head2==NULL){
		return head1;
	}
	node *n;
	if(head1->data <= head2->data){
		n = head1;
		n->next = merge_lists(head1->next,head2);
	}
	else{
		n = head2;
		n->next = merge_lists(head1,head2->next);
	}
	return n;
}

node* merge_sort(node*head){
	if(head->next==NULL || head==NULL){
		return head;
	}
	node *mid = find_mid_point(head);
	node *L1 = head;
	node *L2 = mid->next;
	mid->next = NULL;
	L1 = merge_sort(L1);
	L2 = merge_sort(L2);
	return merge_lists(L1,L2);
}

node* bubbleSort(node* &head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	int len = length(head);
	node* current = head;
	node* previous = NULL;
	node* next_node = NULL;
	for (int i = 0; i < len-1; i++)
	{
		previous = NULL;
		current = head;
		while(current!=NULL && current->next!=NULL){
			next_node = current->next;
			if(current->data > current->next->data){
				if(previous==NULL){
					current->next = next_node->next;
					next_node->next = current;
					head = next_node;
					previous = head;
				}
				else{
					current->next = next_node->next;
					next_node->next = current;
					previous->next = next_node;
					previous = next_node;
				}
			}
			else{
				previous = current;
				current = current->next;
			}			
		}
	}
}

node* reverseLinkedList(node* head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	node* current = head;
	node* next_node = reverseLinkedList(head->next);
	node* temp = next_node;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = current;
	current->next = NULL;
	return next_node;
}

bool isCyclic(node* head){
	node* slow = head;
	node* fast = head;
	while(fast){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast){
			return true;
		}
	}
	return false;
}

void createCycle(node* &head, node* &tail){
	node* temp = head;
	while(temp!= tail){
		temp = temp->next;
	}
	temp->next = head->next->next;
}

void reverseListIteratively(node* &head){
	node* current = head;
	node* previous = NULL;
	node* next_node = NULL;
	while(current!=NULL){
		next_node = current->next;
		current->next = previous;
		previous = current;
		current = next_node;
	}
	head = previous;
	return;
}

void breakCycle(node* &head){
	node* slow = head;
	node* fast = head;
	while(fast){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast){
			break;
		}
	}
	node* prev = head;
	while(prev->next!=fast){
		prev = prev->next;
	}
	node* start = head;
	while(start != fast){
		prev = fast;
		fast = fast->next;
		start = start->next;
	}
	prev->next = NULL;
}

int length(node *head){
	int len = 0;
	while(head!=NULL){
		len++;
		head = head->next;
	}
	return len;
}

int main(){
	node *head = NULL;
	node *tail = NULL;

	/*
	//Insert a node at front
	int N;
	cin>>N;

	// for (int i = 0; i < N; i++)
	// {
	// 	insert_at_front(head,tail,i+1);
	// }
	for (int i = 0; i < N; i++)
	{
		insert_at_back(head,tail,i+1);
	}
	
	//print the list
	print_list(head);
	cout<<"length of the list is : "<<length(head)<<endl;
	cout<<"enter node to insert : "<<endl;

	// insert nodes at ith position
	int new_value, new_position;
	cin>>new_value;
	cout<<"enter index at which to insert : "<<endl;
	cin>>new_position;
	insertAtPos(head,tail,new_value,new_position);
	print_list(head);

	//deletion from front
	deletion_at_front(head,tail);
	cout<<"list after deletion from front: "<<endl;
	print_list(head);

	//deletion from back
	deletion_at_back(head,tail);
	cout<<"list after deletion from back: "<<endl;
	print_list(head);	

	// delete nodes at ith position
	cout<<"enter index at which to delete : "<<endl;
	cin>>new_position;
	deleteAtPos(head,tail,new_position);
	print_list(head);

	// find a node iteratively
	cout<<"enter node value which to find : "<<endl;
	cin>>new_value;
	node* found = find_node_iterative(head,new_value);
	if(found==NULL){
		cout<<"Node not found\n";
	}
	else{
		cout<<"Node found "<<found->data<<endl;
	}
	print_list(head);

	// find a node recursively
	cout<<"enter node value which to find : "<<endl;
	cin>>new_value;
	found = find_node_recursive(head,new_value);
	if(found==NULL){
		cout<<"Node not found\n";
	}
	else{
		cout<<"Node found "<<found->data<<endl;
	}
	print_list(head);

	//find mid point of linked list
	found = find_mid_point(head);
	cout<<"Mid point value is : "<<found->data<<endl;

	*/

	//Merge two sorted lists
	node *L1 = NULL;
	node *T1 = NULL;
	node *L2 = NULL;
	node *T2 = NULL;
	insert_at_back(L1,T1,2);
	insert_at_back(L1,T1,3);
	insert_at_back(L1,T1,6);
	insert_at_back(L1,T1,8);
	insert_at_back(L1,T1,10);

	insert_at_back(L2,T2,1);
	insert_at_back(L2,T2,4);
	insert_at_back(L2,T2,5);
	insert_at_back(L2,T2,9);
	insert_at_back(L2,T2,12);

	node *merged = merge_lists(L1, L2);
	cout<<"lists merged : "<<endl;
	print_list(merged);

	node *L3 = NULL;
	node *T3 = NULL;
	insert_at_back(L3,T3,5);
	insert_at_back(L3,T3,4);
	insert_at_back(L3,T3,3);
	insert_at_back(L3,T3,2);
	insert_at_back(L3,T3,1);
	node *sorted = merge_sort(L3);
	cout<<"list sorted : "<<endl;
	print_list(sorted);

	//bubble sort
	node* L4 = NULL;
	node* T4 = NULL;
	insert_at_back(L4,T4,5);
	insert_at_back(L4,T4,4);
	insert_at_back(L4,T4,3);
	insert_at_back(L4,T4,2);
	insert_at_back(L4,T4,1);
	bubbleSort(L4);
	cout<<"list sorted : "<<endl;
	print_list(L4);

	//reverse a linked list
	node* rev = reverseLinkedList(L4);
	cout<<"reversed\n";
	print_list(rev);

	//reverse a linked list iteratively
	reverseListIteratively(rev);
	cout<<"reversed\n";
	print_list(rev);

	node* cyclic_list_head = NULL;
	node* cyclic_list_tail = NULL;
	insert_at_back(cyclic_list_head,cyclic_list_tail,1);
	insert_at_back(cyclic_list_head,cyclic_list_tail,2);
	insert_at_back(cyclic_list_head,cyclic_list_tail,3);
	insert_at_back(cyclic_list_head,cyclic_list_tail,4);
	insert_at_back(cyclic_list_head,cyclic_list_tail,5);
	insert_at_back(cyclic_list_head,cyclic_list_tail,6);
	insert_at_back(cyclic_list_head,cyclic_list_tail,7);
	cout<<isCyclic(cyclic_list_head)<<endl;
	print_list(cyclic_list_head);
	createCycle(cyclic_list_head,cyclic_list_tail);
	cout<<isCyclic(cyclic_list_head)<<endl;
	if(isCyclic(cyclic_list_head)){
		breakCycle(cyclic_list_head);
	}
	print_list(cyclic_list_head);
	return 0;
}