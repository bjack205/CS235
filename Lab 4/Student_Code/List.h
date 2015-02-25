#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

template<typename ItemType>
class List {
private:
	struct Node {
		ItemType item;
		Node* next;
		Node* prev;
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
			else {
				head->prev = n;
				n->next = head;
			}
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
				n->prev = tail;
				tail = n;
				num_items++;
			}
		}
	}
	ItemType getHead() {
		if (head != NULL)
			return head->item;
		//else
			//return NULL;
	}
	ItemType getTail() {
		if (tail != NULL)
			return tail->item;
		//else
			//return NULL;
	}
	void removeHead() {
		if (!isEmpty()) {
			Node* n = head;
			if (num_items == 1) {
				head = NULL;
				tail = NULL;
			}
			else {
				head = head->next;
				head->prev = NULL;
			}
			num_items--;
			delete n;
		}
	}
	void removeTail() {
		if (!isEmpty()) {
			if (num_items == 1)
				removeHead();
			else {
				Node* n = tail;
				tail = tail->prev;
				tail->next = NULL;
				num_items--;
				delete n;
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
					if (node == NULL) {
						tail = n;
						n->next = NULL;
					}
					else {
						n->next = node->next;
						node->next->prev = n;
					}
					n->prev = node;
					node->next = n;
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
			head->prev = NULL;
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
					toRemove->next->prev = prevNode;
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

	bool isEmpty() {
		if (num_items == 0)
			return true;
		else
			return false;
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
