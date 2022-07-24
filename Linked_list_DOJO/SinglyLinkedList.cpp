#include "SinglyLinkedList.h"
#include <iostream>

SinglyLinkedList::SinglyLinkedList()
{
	/*head = new Node(); //since head is just a pointer to the first
					   //Node, it will initialized at the class init*/
	head = nullptr;
	last = nullptr;
	temp = nullptr;
	curr = nullptr;
	length = 0;
}

SinglyLinkedList::~SinglyLinkedList()
{

}

int SinglyLinkedList::getHead()
{

	return 0;
}

int SinglyLinkedList::getLength()
{
	return 0;
}

SinglyLinkedList SinglyLinkedList::getTail()
{
	return SinglyLinkedList();
}

void SinglyLinkedList::insertAtTheFront(int newData)
{
	Node* newNodePtr = createNewNode(newData);
	if (head == nullptr) {
		head = newNodePtr;
	}
	else {
		newNodePtr->nextNode = head;
		head = newNodePtr;
	}
}

void SinglyLinkedList::insertAtTheEnd(int newData)
{
	Node* newNodePtr = createNewNode(newData);
	if (head == nullptr) {
		head = newNodePtr;
	}
	else {
		last = head;
		while (last->nextNode != nullptr) {
			last = last->nextNode;
		}
		last->nextNode = newNodePtr;
	}
}

void SinglyLinkedList::insertAfterNthNode(int newData, int afterThisNthNode)
{
	if (head != nullptr) {

		temp = getNthNodeAddress(afterThisNthNode);
		if (temp == nullptr) {
			std::cout << "List is too short to find you element\n";
		}
		else {
			insertAfterAddress(newData, temp);
		}
		
		//temp = head;
		//int iter = { 1 };
		
		//while (temp != nullptr) {
		//	if (iter == afterThisNthNode) {
		//		insertAfterAddress(newData, temp);
		//		iter = 0;
		//		break;
		//	}
		//	temp = temp->nextNode;
		//	iter++;
		//}
		//if (iter != 0) {
		//	std::cout << "There are not enough Nodes in the List\n";
		//}
	}
	else {
		std::cout << "The list was empty, newData was inserted as a first and only element!" << std::endl;
		insertAtTheFront(newData);
	}
}


void SinglyLinkedList::remove(int index)
{
	Node* deleteMe = getNthNodeAddress(index);
	if (deleteMe != nullptr) {
		temp = getNthNodeAddress(index - 1);
		temp->nextNode = deleteMe->nextNode;
		delete deleteMe;
		length--;
	}
}

void SinglyLinkedList::printList()
{
	std::cout << "Printing list elements, line by line." << std::endl;
	temp = head;
	int iter = { 1 };
	while (temp != nullptr) {
		std::cout << "Element #" << iter << " is: " << temp->data << std::endl;
		temp = temp->nextNode;
		iter++;
	}
	getLastNodeAndCountLen();
	std::cout << "Reached end of the list. Found " << length << " Nodes.\nBye bye." << std::endl;
	
}

SinglyLinkedList::Node* SinglyLinkedList::createNewNode(int newData)
{
	Node* newNodePtr = new Node();
	newNodePtr->data = newData;
	newNodePtr->nextNode = nullptr;
	return newNodePtr;
}

SinglyLinkedList::Node* SinglyLinkedList::nextNode(Node* currentNode)
{
	return nullptr;
}

void SinglyLinkedList::insertAfterAddress(int newData, Node* afterThis)
{
	if (afterThis == nullptr) {
		std::cout << "Cannot insert Node after unknown Node (got null pointer!)" << std::endl;
	}
	Node* newNodePtr = createNewNode(newData);
	newNodePtr->nextNode = afterThis->nextNode;
	afterThis->nextNode = newNodePtr;
	length++;
}

SinglyLinkedList::Node* SinglyLinkedList::getNthNodeAddress(int thisNthNode)
{
	temp = head;
	int iter = { 1 };
	while (temp != nullptr) {
		if (iter == thisNthNode) {
			return temp;
		}
		temp = temp->nextNode;
		iter++;
	}
	return nullptr;
}

SinglyLinkedList::Node* SinglyLinkedList::getLastNodeAndCountLen()
{
	length = 0;
	temp = head;
	while (temp != nullptr) {
		length++;
		temp = temp->nextNode;
	}
	return temp;
}
