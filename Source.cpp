#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
	cout << "\t***************************************************************************\n";
	cout << "\t***\tThis Program helps you in managing Queues for your Workplace!\t***\n";
	cout << "\t***\t       -> You can manage the number of Queues you want!      \t***\n";
	cout << "\t***\t       -> You can easily Add To & Remove From the Queue!     \t***\n";
	cout << "\t***************************************************************************\n\n";
	cout << "\t\tDo you want to use it?\n\t\tPress Y/y for YES or any other character for NO: ";
	char choice;
	cin >> choice;					//asking user whether he/she wants to use program or not
	if (choice == 'y' || choice == 'Y') {			//if yes then performing all the operations
		cout << "\n\t\t\t\tWELCOME!\n";
		int n;
		cout << "\n\t\tEnter number of Queues you want to use: ";
		cin >> n;					//getting number of queues to be managed
		queue<string>* q;			//queue pointer for managing multiple queues
		q = new queue<string>[n];	//pointing to array of queues of size n
		string* name;				//pointer of string  
		name = new string[n];		//pointing to array of strings for saving names of queues
		for (int i = 0; i < n; i++) {			//loop for assigning names to queue
			cout << "\t\tPlease assign name to Queue (" << i + 1 << ") : ";
			cin >> name[i];
		}
		string str;				//variable for getting name of the queue on which user wants to perform operation
		char ch;				//variable for number of times user wants to perform actions
		int op;					//variable for choice of operations
		cout << "\n\t\tDo you want to perform any operation on Queue(s)?\n\t\tPress Y/y for YES or any other character for NO: ";
		cin >> ch;
		while (ch == 'y' || ch == 'Y') {			//looping if user wants
			cout << "\n\t\tOn which Queue do you want to perform the operation?\n\t\tEnter exact name: ";
			cin >> str;				//getting name of desired queue
			int found = 0;			//variable for checking whether desired queue exists or not
			for (int i = 0; i < n; i++) {
				if (str == name[i]) {
					found = 1;		//if exists
					break;
				}
			}
			if (found) {		//if desired queue exists
				cout << "\n\t\tWhich operation do you want to perform?\n";
				cout << "\t\t(1)\tAdd To Queue \n\t\t(2)\tRemove From Queue\n";
				cout << "\n\t\tEnter one of the characters mentioned above:";
				cin >> op;		//getting choice for desired operation 
				for (int i = 0; i < n; i++) {
					if (str == name[i]) {		//if desired queue is found
						string s;		
						switch (op) {		//checking for operation
						case 1:	cout << "\t\tEnter the name you want to Add to Queue:";
							cin >> s; q[i].push(s);	cout << "\t\tAdded Successfully!\n"; break;
						case 2: if (q[i].empty()) {
							cout << "\n\t\tQueue is empty. Cannot remove from empty Queue!\n";
						}
						else {
							q[i].pop();
							cout << "\t\tRemoved Successfully!\n";
						}
							  break;
						default: cout << "\n\t\tYou have entered wrong choice!\n";
						}
						break;
					}
				}
			}
			else {			//if desired queue does not exists
				cout << "\n\t\tNo Queue found, named \"" << str << "\"\n";
			}
			cout << "\n\t\tDo you want to perform another operation?\n\t\tPress Y/y for YES or any other character for NO: ";
			cin >> ch;			//asking for user's choice if he wants to perform another operation
		}
		cout << "\n\t\t\t ***Thanks for Using!***\n";
		cout << "\t\t\t***Program Terminated!***\n";
		exit(1);			//terminating program
	}
	cout << "\n\t\t\t***We respect your choice!***\n";
	cout << "\t\t\t  ***Program Terminated!***\n";
	return 0;
}