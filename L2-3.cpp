#include <iostream>
#include <cctype>

using namespace std;

int phoneDigit(char letter);

int main()
{
	char response;		//Yes/No response

	char 
		numOne,			//Character one storage
		numTwo,			//Character two storage
		numThree,		//Character three storage
		numFour,		//Character four storage
		numFive,		//Character five storage
		numSix,			//Character six storage
		numSeven;		//Character seven storage

	bool error;			//Throw a error

	char q;

	cout << "Anthony Cantu\t" << "L2-3\t" << "L2-3.exe";

	cout << endl; //Line Break;

	cout << "Enter Y/y to convert a telephone number from letters to digits." << endl
		<< "Enter any other letter to terminate the program." << endl;

	cin >> response;
	while (response == 'y' || response == 'Y')
	{
		error = false; //Clear any errors

		cout << "Enter a telephone number using 7 or more letters" << endl
			<< "for Prefix and number, only the first 7 letters are used" << endl
			<< "and dashes '-' are ZEROES, underscores '_' are ONES" << endl
			<< "ALL OTHER SYMBOLS ARE ignored." << endl
			<< "-->: ";

		cin.ignore(1, ' ');
		for (int i = 0; i < 7; i++)
		{
			if (cin.peek() == ' ')
			{
				cin.ignore();
				i = i - 1;
			}
			else if (islower(cin.peek()) || isupper(cin.peek()) ||
				cin.peek() == '-' || cin.peek() == '_')
			{
				switch (i)
				{
				case 0:
					cin.get(numOne);
					break;
				case 1:
					cin.get(numTwo);
					break;
				case 2:
					cin.get(numThree);
					break;
				case 3:
					cin.get(numFour);
					break;
				case 4:
					cin.get(numFive);
					break;
				case 5:
					cin.get(numSix);
					break;
				case 6:
					cin.get(numSeven);
					break;
				}
			}
			else
			{
				error = true; //Throw an error
				break;
			}
		}

		cout << endl;

		if (error == false)
		{
			cout << "The corresponding telephone number is:" << endl;
			cout << phoneDigit(numOne) << phoneDigit(numTwo) << phoneDigit(numThree)
				<< "-" << phoneDigit(numFour) << phoneDigit(numFive) << phoneDigit(numSix)
				<< phoneDigit(numSeven);

			cout << endl << endl; //Line Break

			cin.clear();
			cin.ignore(200, '\n');

			cout << "To process another telephone number, enter Y/y" << endl;
			cout << "Enter any other letter to terminate the program." << endl;
			cin >> response;

			cout << endl;
		}
		else
		{
			cin.clear();
			cin.ignore(200, '\n');

			cout << "ERROR: Invalid entry. Please only use the following characters:" << endl
				<< "A - Z, a - z, '-', '_'" << endl << endl;
			cout << "Please enter Y/y if you wish to continue." << endl
				<< "Enter any other letter to terminate the program." << endl;
			cin >> response;
			cout << endl;
		}
		
	}

	cout << "The program has been terminated." << endl
		<< "Press enter to exit.";

	cin.ignore(2, '\n');
	cin.get(q);

	return 0;
}

int phoneDigit(char letter)
{
	int num, digit;

	if (letter == '-')
	{
		return digit = 0;
	}
	else if (letter == '_')
	{
		return digit = 1;
	}

	if (islower(letter))
	{
		num = static_cast<int>(letter)
			- static_cast<int>('a');
	}
	else
	{
		num = static_cast<int>(letter)
			- static_cast<int>('A');
	}

	if (0 <= num && num < 26)
	{
		digit = (num / 3) + 2;

		if (((num / 3 == 6) || (num / 3 == 7))
			&& (num % 3 == 0))
			digit = digit - 1;

		if (digit > 9)
			digit = 9;

		return digit;
	}
	else
	{
		/*
			Should not reach this point with the
			other error checks.
		*/
		cout << "Invalid input." << endl;
	}
}