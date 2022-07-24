#pragma once
#include <iostream>

class SinglyLinkedList
{
private:
	struct Node {
		int data;
		Node* nextNode;
	};
	int length = { 0 };
	Node* head;
	Node* last;
	Node* temp;
	Node* curr;
	Node* createNewNode(int newNumber);
	Node* nextNode(Node* currentNode);
	void insertAfterAddress(int newData, Node* afterThis);
	Node* getNthNodeAddress(int thisNthNode); //this method returns address (pointer) to the N-th Node
	Node* getLastNodeAndCountLen(); // tail = last node

public:
	SinglyLinkedList();
	~SinglyLinkedList();
	int getHead();
	int getLength();
	SinglyLinkedList getTail();
	void insertAtTheFront(int newData);
	void insertAtTheEnd(int newData);
	void insertAfterNthNode(int newData, int afterThisNthNode);
	void remove(int index);
	void printList();

};

