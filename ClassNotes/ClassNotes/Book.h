
#include <iostream>
#include <string>

using std::string;

class Book {
public:
	string title;
	string author;

	//Constructor
	Book(string t, string a) :title(t), author(a){}

	//Operator
	bool operator < (Book b) const{
		return this->title < b.title;
	}
	
	//Getters
	//const mondifier keeps it from changing the class
	string getTitle() const { return title; }
	string getAuthor() const { return author; }
	
	//Setters
	void setTitle(string title);
	void setAuthor(string author);
	string toString() const;
};