#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};
class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** syafrizal, Node** muh);
	bool listEmpty();
	bool delNode();
	void traverse();
};
void CircularLinkedList::addNode() { 
	int rn;//Memasukan data dengan nama variabel rn
	string nm;//Membuat tipe data dengan  nama variabel nm
	cout << "\nEnter the roll number : ";
	cin >> rn; //Memanggil atau memasukan data roll number
	cout << "\nEnter the name : ";
	cin.ignore();
	getline(cin, nm);
	Node* newNode = new Node();
	newNode->rollNumber = rn;
	newNode->name = nm;

	if (LAST == NULL || rn <= LAST->rollNumber) {
		if (LAST != NULL && rn <= LAST->rollNumber) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
	}
}
bool CircularLinkedList::search(int rollno, Node** syafrizal, Node** muh) {
	*syafrizal = LAST->next;
	*muh = LAST->next;
	while (*muh != LAST) {
		if (rollno == (*muh)->rollNumber) {
			return true;
		}
		*syafrizal = *muh;
		*muh = (*muh)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}
bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}
bool CircularLinkedList::delNode() {
	if (listEmpty()) {
		cout << "List is empty" << endl;
		return false;
	}

	if (LAST->next == LAST) {
		delete LAST;
		LAST = NULL;
	}
	else {
		Node* muh = LAST->next;
		LAST->next = muh->next;
		delete muh;
	}
};

void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* muhNode = LAST->next;
		while (muhNode != LAST) {
			cout << muhNode->rollNumber << " " << muhNode->name << endl;
			muhNode = muhNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}
int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
				obj.addNode();
				break;
			}
			case '2': {
				obj.delNode();
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}