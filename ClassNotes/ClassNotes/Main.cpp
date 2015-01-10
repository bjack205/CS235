#include <iostream>
#include <vector>
#include <algorithm>
#include "Book.h"

using namespace std;

int main()
{
	Book BoM("Book of Mormon", "God");
	Book Infinite("Infiniate Atonement", "Callister");
	Book Hunger("Hunger Games", "Collins");
	
	cout << BoM.toString() << endl;

	vector<Book> list;
	list.push_back(BoM);
	list.push_back(Infinite);

	system("pause");
	return 0;
}