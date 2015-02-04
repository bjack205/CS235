#pragma once
#include <set>

using namespace std;

template<typename ItemType>
class List {
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
			Node* n = new Node();
			n->item = value;
			if (num_items == 0)
				insertHead(value);
			else {
				tail->next = n;
				tail = n;
				num_items++;
			}
		}
	}
	void insertAfter(ItemType value, ItemType insertionNode) {
		if (!InList(value)) {
			Node* n = new Node();
			n->item = value;
			Node* node = head;
			while (node != NULL) {
				if (node->item == insertionNode) {
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
			delete toRemove;
			num_items--;
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
		/*
		while (node->next != NULL) {
			if (node->next->item == value) {
				Node* toRemove = *node->next;
				node->next = toRemove->next;
				if (node->next == NULL) tail = node;
				if (head == toRemove) 
					head = node->next;
				toRemove->next = NULL;
				delete toRemove;
				num_items--;
			}
			node = node->next;
		}
		node = node->next;
		delete node;
		*/
	}
	int size() {
		return num_items;
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