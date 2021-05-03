/*noa zwebner 324989714*/
#include "RoundList.h"
#include "List.h"
#include<iostream>
#include<string>
#include<cstring>
#pragma warning (disable:4996)
using namespace std;
bool RoundList::isEmpty() const
{
	// test to see if the List is empty
	// List is empty if the pointer to the head
	// Link is null
	return head == NULL;
}
RoundList::RoundList() {     //default constractor
	
}
void RoundList:: add(int value) {     //add an element to the top of the list
	List::add(value);   
	Link* trg = head;
	if (trg->next == NULL) {       //if there us only one element
		trg->next = head;
	}
	while (trg->next->next != head->next) {    //moving to the last element
		trg = trg->next;       
	}
	trg->next->next = head;      //the last elements points to the head

}
void RoundList::removeFirst() { //removing the first element
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	if (head->next == head) {
		head = NULL;
	}
	else {
		Link* trg = head;
		while (trg->next != head) {
			trg = trg->next;
		}
		trg->next = head->next;       //the last element points to the new head

		List::removeFirst();       //calling the father's method
	}
}
RoundList::RoundList(const RoundList&l) {      //copy-constractor
	{
		Link* src, * trg;
		if (l.head == NULL)
			head = NULL;
		else
		{
			head = new Link((l.head)->value, head);
			src = l.head;
			trg = head;
			while (src->next != l.head)
			{
				trg->next = new Link((src->next)->value, head);
				src = src->next;
				trg = trg->next;
			}
		}
	}

}
void RoundList::clear()      //clear the list
{
	if (isEmpty())
		return;
	else {
		Link* theNext;
		for (Link* p = head->next; p != head; p = theNext) {   //as long as we did not get to the last element
			theNext = p->next;
			p->next = NULL;
			delete p;
		}
		// mark that the List contains no elements
		delete head;
		head = NULL;
	}
}

RoundList::~RoundList() {
	clear();
}
void RoundList::addToEnd(int val) {     //add to the last of the list
	if (isEmpty()) {     //if the list is empty, call the father's method
		add(val);
	}
	else {
		Link* trg;
		trg = head;
		while (trg->next != head) {     //moving to the last
			trg = trg->next;
		}
		trg->next = new Link(val, head);    //the new last elements points to the head
	}
}
int RoundList::search(int n) {    //searching to the value in the n's place
	Link* trg = head;
	int p = n;
	while (p > 0) {        //keep moving
		trg = trg->next;
		p--;
	}

	return trg->value;     



}