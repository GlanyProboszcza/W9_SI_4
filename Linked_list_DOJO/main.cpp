#include <iostream>
#include "SinglyLinkedList.h"

int main()
{
	SinglyLinkedList mojaLista;
	mojaLista.insertAtTheFront(23);
	mojaLista.insertAtTheEnd(88);
	mojaLista.insertAtTheEnd(99);
	mojaLista.insertAfterNthNode(90, 2);
	mojaLista.insertAfterNthNode(90, 6);

	mojaLista.printList();
	mojaLista.remove(4);
	mojaLista.printList();



	
}
