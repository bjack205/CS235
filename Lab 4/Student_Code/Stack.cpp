#include <iostream>
#include <string>

#include "Stack.h"

void Stack::push(int item) {
	list.insertTail(item);
}
int Stack::top() {
	return list.getTail();
}
void Stack::pop() {
	list.removeTail();
}
int Stack::size() {
	return list.size();
}
bool Stack::inStack(int item) {
	return list.InList(item);
}
bool Stack::isEmpty() {
	return list.isEmpty();
}
void Stack::clear(){
	list.clear();
}
void Stack::PrintStack() {
	list.PrintList();
}