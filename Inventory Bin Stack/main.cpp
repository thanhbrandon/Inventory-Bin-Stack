#include "DynamicStack.h"
#include "InventoryPart.h"
using namespace std;

bool reRun(); // function prototype for reRun function
void pushItem(DynamicStack &);
void popItem(DynamicStack& stack);

int main() {

	DynamicStack stack;

	bool programOn = true;
	do {
		int choice = -1;
		cout << "This program allows you to add a parts serial\n";
		cout << " number and the date that it was made.\n";
		cout << "The program also allows you to remove those parts\n";
		cout << " as well deleting the first one in the line of the list\n\n\n";
		cout << "------ Inventory Menu --------\n\n";
		cout << "1.    Enter a part into the inventory.\n";
		cout << "2.    Take a part from the inventory.\n";
		cout << "3.    View last item entered.\n";
		cout << "4.    Quit.\n\n\n";
		cout << "Please make a choice: ";
		cin >> choice;

		switch (choice) {
			case 1 :
				pushItem(stack);
				break;
			case 2 :
				popItem(stack);
				break;
			case 3 :
				stack.peek();
				break;
			case 4 :
				break;
			default :
				cout << "Invalid Choice!";
		}

		programOn = reRun(); // Asks user if they want to run the program again
	} while (programOn == true);
	return 0;
}

bool reRun()
{
	bool result; 	// true to end program, false to run again
	char runAgain;	// prompt for re-running program

	// prompt to run program again
	cout << "\n\nWould you like to run program again (Y/N) ? ";
	cin >> runAgain;

	// validate input for Y, y, N, or n
	while (toupper(runAgain) != 'Y' && toupper(runAgain) != 'N')
	{
		cout << "\n **  Invalid entry  **  Please enter 'Y' or 'N'\n\n";
		cout << "Would you like to run program again (Y/N) ? ";
		cin.ignore();  // clear keybard cache
		cin >> runAgain;
	}

	if (toupper(runAgain) == 'Y')
	{
		result = true;
		system("CLS"); // Clears console
	}
	else
		result = false;

	return result;
}

void pushItem(DynamicStack& stack) {
	int serialNum;
	string manufactDate;
	int lotNum;

	cout << "Enter serial number: ";
	cin >> serialNum;
	cout << "Enter the date the part was manufactured:";
	cin >> manufactDate;
	cout << "Enter lot number: ";
	cin >> lotNum;

	InventoryPart item = InventoryPart(serialNum, manufactDate, lotNum);

	stack.push(item);
};

void popItem(DynamicStack& stack) {
	InventoryPart item= InventoryPart(0, "", 0);

	// Pop the item
	stack.pop(item);
};