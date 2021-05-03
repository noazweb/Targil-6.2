/*noa zwebner 324989714
implementation of a circular list*/
#include "RoundList.h"
#include <iostream>
#include<string>
#include<cstring>
#pragma warning (disable:4996)
using namespace std;

enum CHOICES {
	EXIT, ADD, ADD_TO_END, REMOVE_FIRST, SEARCH, CLEAR, EMPTY
};






int main() {
	try {
		RoundList ls1;
		int choice;
		cout << "Enter your choice: ";
		cin >> choice;
		while (choice != EXIT)
		{
			int num;
			switch (choice) {
			case ADD: 	cout << "Enter 5 numbers: ";
				for (int i = 0; i < 5; i++)
				{
					cin >> num;
					ls1.add(num);
				}
				break;

			case ADD_TO_END:cout << "Enter 5 numbers: ";
				for (int i = 0; i < 5; i++)
				{
					cin >> num;
					ls1.addToEnd(num);
				}
				break;

			case REMOVE_FIRST: ls1.removeFirst();
				break;

			case SEARCH: cout << "Enter a number: ";
				cin >> num;
				cout << ls1.search(num) << endl;
				break;
			case CLEAR: ls1.clear();
				break;

			case EMPTY: if (ls1.isEmpty())
				cout << "Empty" << endl;
					  else
				cout << "Not empty" << endl;
				break;

			default: cout << "ERROR!" << endl;
			}
			cout << "Enter your choice: ";
			cin >> choice;

		}
	}
	catch (const char* msg) {
		cout << msg << endl;
	}
		return 0;
	
	
}

