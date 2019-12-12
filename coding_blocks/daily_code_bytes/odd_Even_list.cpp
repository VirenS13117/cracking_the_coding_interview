#include <iostream>
using namespace std;
class node{
public:
	int data;
	node* next;
	node(int x){
		data = x;
		next = NULL;
	}
};


node* createList(){
	int n;
	cin>>n;
	int i=0;
	node* head = NULL;
	node* temp = NULL;
	while(i < n){
		int val;
		cin>>val;
		if(i==0){
			head = new node(val);
			temp = head;
		}
		else{
			node* curr = new node(val);
			temp->next = curr;
			temp = temp->next;
		}
		i++;
	}
	return head;
}

void print(node* head){
	if(head==NULL){
		return;
	}
	while(head!=NULL){
		cout<<head->data<<"->";
		head = head->next;
	}
	return;
}

node* seperate(node* head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	node* curr = head;
	int len = 0;
	while(curr->next!=NULL){
		curr = curr->next;
		len++;
	}
	node* tail = curr;
	curr = head;
    node* prev = NULL;
    int flag = 0;
    
	while(len--){//1->2->3->4->5
		cout<<curr->data<<endl;
		if((curr->data)%2==0){
			prev = curr;
			curr = curr->next;
		}
		else{
			if(curr==head){
				tail->next = curr;
				head = head->next;
				tail = curr;
				tail->next = NULL;
				curr=head;
			}
			else{
				prev->next = curr->next;
				tail->next = curr;
				tail = curr;
				tail->next = NULL;
				curr=prev->next;
			}

		}
	}
	return head;

}
int main(int argc, char const *argv[])
{
	node* head = createList();
	print(head);
	cout<<"\n";
	node* head2 = seperate(head);
	print(head2);
	cout<<endl;
	return 0;
}
