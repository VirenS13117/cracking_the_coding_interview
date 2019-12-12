#include<iostream>
#include "node.h"
using namespace std;

template<typename T>
class LinkedList{
public:
	node<T>* head;
	node<T>* tail;
	int len;
	LinkedList(){
		head = NULL;
		tail = NULL;
		len = 0;
	}
	void insertAtFront(T value){
		if(head == NULL){
			node<T>* new_node = new node<T>(value);
			head = new_node;
			tail = new_node;
			len++;
		}
		else{
			node<T>* new_node = new node<T>(value);
			new_node->next = head;
			head = new_node;
			len++;
		}
		return;
	}
	void insertAtEnd(T value){
		if(head==NULL){
			node<T>* new_node = new node<T>(value);
			head = new_node;
			tail = new_node;
			len++;
		}
		else{
			node<T>* new_node = new node<T>(value);
			tail->next = new_node;
			tail = new_node;
			len++;
		}
		return;
	}
	void deleteFromFront(){
		if(head==NULL){
			return;
		}
		else{
			node<T>* temp = head;
			head = head->next;
			delete temp;
		}
		len--;
	}
	void deleteFromEnd(){
		if(head==NULL){
			return;
		}
		else{
			node<T>* temp = head;
			while(temp->next!=tail){
				temp = temp->next;
			}
			tail = temp;
			temp = tail->next;
			tail->next = NULL;
			delete temp;
		}
		len--;
	}
	void print(){
		if(head==NULL){
			return;
		}
		node<T>* temp = head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
		return;
	}
	void insertAtPos(T value, int pos){
		if(pos==0){
			insertAtFront(value);
		}
		else if(pos==len-1){
			insertAtEnd(value);
		}
		else{
			node<T>* temp = head;
			int count = 1;
			while(count<pos){
				temp = temp->next;
				count++;
			}
			node<T>* new_node = new node<T>(value);
			new_node->next = temp->next;
			temp->next = new_node;
		}
		len++;
	}
	void deleteFromPos(int pos){
		if(pos==0){
			deleteFromFront();
		}
		else if(pos==len){
			deleteFromEnd();
		}
		else{
			node<T>* temp = head;
			int count = 1;
			while(count<pos){
				temp = temp->next;
				count++;
			}
			node<T>* nodeToDelete = temp->next;
			temp->next = nodeToDelete->next;
			delete nodeToDelete;
		}
		len--;
	}
	int length(){
		return len;
	}
};