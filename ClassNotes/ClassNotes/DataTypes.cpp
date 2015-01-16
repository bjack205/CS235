/*
Data Types:
	Lists
		1. a container that holds objects
		2. each object has an index or position
		3. objects are kpt in the order given by the user
		vector is an example of a list
		Operations
			size();
			append(item);
			remove(item);
			insert(index,item);
			get(index);
			set(index, item);

			What does the program print?

			List L1;
			L1.append(1);
			L1.append(2);
			L1.append(4);
			print(L1);
			1 2 4

			List L2;
			for (int i = 0; i < L1.size(); i++)
			L2.insert(0, L1.get(i));
			print(L2);
			4 2 1

			for (int i = 0; i < L1.size(); i++)
			L2.insert(2*i, L1.get(i));
			print(L2);
			1 4 2 2 4 1

			for (int i = 0; i < L1.size(); i++)
			L2.set(i, L1.get(i));
			print(L2);
			1 2 4 2 4 1

			for (int i = 0; i < L2.size(); i++)
			L2.remove(i);
			print(L2);
			2 2 1

	Vectors:
		size_t size() const;
		void push_back( const ItemType& item);
		iterator erase (iterator index);
		iterator insert (iterator index, const ItemType& item)
		ItemType& at (int index);
		ItemType& operator[] (int index);

	List:
		size_t size() const;
		void push_back ( const ItemType& item );
		iterator erase ( iterator index );
		iterator insert ( iterator index, const ItemType& item );


*/