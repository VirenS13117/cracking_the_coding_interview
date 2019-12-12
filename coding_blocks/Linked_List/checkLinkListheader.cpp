#include<iostream>
#include "LinkedList.h"
using namespace std;

int main(){
	LinkedList<int>L1;
	for (int i = 0; i < 10; i++)
	{
		L1.insertAtFront(i);
	}
	L1.print();
	for (int i = 11; i < 20; i++)
	{
		L1.insertAtEnd(i);
	}
	L1.print();
	L1.deleteFromFront();
	L1.print();
	L1.deleteFromEnd();
	L1.print();
	cout<<"length : "<<L1.length()<<endl;
	L1.deleteFromPos(5);
	L1.print();
	cout<<"length : "<<L1.length()<<endl;
	L1.insertAtPos(20,7);
	L1.print();
	cout<<"length : "<<L1.length()<<endl;
	return 0;
}