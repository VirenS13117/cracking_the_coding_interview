#include<iostream>
using namespace std;

template<typename T>
class node{
public:
	int data;
	node<T>* next;
	node(int value):data(value),next(NULL)
	{}
};