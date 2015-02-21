#pragma once
#include <iostream>
#include <stdexcept>
#include "LinkedListInterface.h"

using namespace std;

template<typename ItemType>
class List: public LinkedListInterface<ItemType> {
private:
	struct Node {
		ItemType item;
		Node* next;
	};
	int num_items;
	Node* head;
	Node* tail;
public:
	List() : num_items(0), head(NULL), tail(NULL){};
	~List() {
		this->clear();
	}
	void insertHead(ItemType value) {
		if (!InList(value)) {
			Node* n = new Node();
			n->item = value;
			if (num_items == 0)
				tail = n;
			else
				n->next = head;
			head = n;
			num_items++;
		}
	}
	void insertTail(ItemType value) {
		if (!InList(value)) {
			if (num_items == 0)
				insertHead(value);
			else {
				Node* n = new Node();
				n->item = value;
				tail->next = n;
				tail = n;
				num_items++;
			}
		}
	}
	void insertAfter(ItemType value, ItemType insertionNode) {
		if (!InList(value)) {
			Node* node = head;
			while (node != NULL) {
				if (node->item == insertionNode) {
					Node* n = new Node();
					n->item = value;
					n->next = node->next;
					node->next = n;
					if (n->next == NULL)
						tail = n;
					num_items++;
				}
				node = node->next;
			}
		}
	}
	void remove(ItemType value) {
		Node* node = head;
		Node* toRemove;
		Node* prevNode;
		if (head->item == value) {
			toRemove = head;
			head = head->next;
			num_items--;
			if (toRemove == tail)
				tail = NULL;
			delete toRemove;
		}
		else {
			node = node->next;
			prevNode = head;
			while (node != NULL) {
				if (node->item == value) {
					toRemove = node;
					prevNode->next = toRemove->next;
					if (toRemove == tail)
						tail = prevNode;
					delete toRemove;
					num_items--;
					break;
				}
				node = node->next;
				prevNode = prevNode->next;
			}
		}
	}
	int size() {
		return num_items;
	}
	void clear() {
		Node* n;
		while (this->size() > 0) {
			n = head;
			head = head->next;
			delete n;
			num_items--;
		}
		
			
	}
	ItemType at(int index) {
		if (index >= num_items || index < 0) {
			throw out_of_range("out of range");
		}
		else {
			Node* n = head;
			for (int i = 0; i <= index; i++) {
				if (i == index)
					return n->item;
				n = n->next;
			}
		}
	}

	ItemType getHead() {
		if (head != NULL)
			return head->item;
	}
	ItemType getTail() {
		if (tail != NULL)
			return tail->item;
	}
	bool InList(ItemType value) {
		Node* n = head;
		while (n != NULL) {
			if (n->item == value) return true;
			n = n->next;
		}
		return false;
	}
	void PrintList() {
		Node* n = head;
		cout << "Size: " << this->size() << " {";
		while (n != NULL) {
			cout << n->item << " ";
			n = n->next;
		}
		cout << "}" << endl;
	}
};
