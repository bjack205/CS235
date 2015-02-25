#include "Queue.h"

void Queue::push(int item) {
	list.insertHead(item);
}
int Queue::top() {
	return list.getTail();
}
void Queue::pop() {
	list.removeTail();
}
int Queue::size() {
	return list.size();
}
bool Queue::inQueue(int item) {
	return list.InList(item);
}
bool Queue::isEmpty() {
	return list.isEmpty();
}
void Queue::clear(){
	list.clear();
}
void Queue::PrintQueue() {
	list.PrintList();
}