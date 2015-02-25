#include "Deque.h"

void Deque::addLeft(int item) {
	list.insertHead(item);
}
void Deque::addRight(int item) {
	list.insertTail(item);
}
void Deque::removeLeft() {
	list.removeHead();
}
void Deque::removeRight() {
	list.removeTail();
}
int Deque::getLeft() {
	return list.getHead();
}
int Deque::getRight() {
	return list.getTail();
}
int Deque::size() {
	return list.size();
}
bool Deque::inDeque(int item) {
	return list.InList(item);
}
bool Deque::isEmpty() {
	return list.isEmpty();
}
void Deque::clear(){
	list.clear();
}
void Deque::PrintDeque() {
	list.PrintList();
}