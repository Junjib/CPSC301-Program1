#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;

struct PERSON
{
  char Name[20];
  float Balance;
};

void Display(PERSON a[], int N);
void FindRichest(PERSON a[], int N);
void Deposit(string name, PERSON a[], int N);
void NewCopy(string file, PERSON a[], int N);

int main()
{
	int N = 6;
	int choice = 0;
	PERSON arr[6];
	PERSON obj;
	string fName, lName, name;
	ifstream readData;
	readData.open("data.txt");

	// Checks if file successfully opens
	if(readData.fail())
	{
		cout << "Error\n";
		return 1;
	}

	// Stores PERSON obj into the PERSON array
	for(int i = 0; i < 6; i++)
	{
		readData >> fName;
		readData >> lName;
		readData >> obj.Balance;
		name = fName + " " + lName;
		strcpy(obj.Name, name.c_str());
		arr[i] = obj;
	}
	readData.close();
	// ===================================================
	// Menu for selecting which function to execute
	do
	{
		cout << "What would you like to do?\n";
		cout << "Enter 1 to display the file.\n";
		cout << "Enter 2 to find the richest.\n";
		cout << "Enter 3 to deposit money into an account.\n";
		cout << "Enter -1 to exit.\n";
		cout << "Enter your choice: ";
		cin >> choice;
		cout << endl << endl;

		switch(choice)
		{
		case 1:
			Display(arr, N);
			break;
		case 2:
			FindRichest(arr, N);
			break;
		case 3:
			cout << "Enter your full name to deposit money: ";
			cin.ignore();
			getline(cin, name);
			Deposit(name, arr, N);
			NewCopy("data.txt", arr, N);
			break;
		case -1:
			cout << "Exiting.\n";
		}

	}while(choice != -1);

	return 0;
}

void Display(PERSON a[], int N)
{
	cout << "Name		Balance\n";
	cout << "----------------------------\n";
	for(int i = 0; i < N; i++)
	{
		cout << a[i].Name << " " << fixed << setprecision(2) << a[i].Balance << endl;
	}
	cout << endl;
}

void FindRichest(PERSON a[], int N)
{
  PERSON richest, temp1, temp2;

  richest.Balance = 0;

  for(int i = 0; i < N; i++)
  {
    temp1.Balance = a[i].Balance;
    strcpy(temp1.Name, a[i].Name);
    temp2.Balance = a[i + 1].Balance;
    strcpy(temp2.Name, a[i + 1].Name);

    if(temp1.Balance > temp2.Balance)
    {
      if(richest.Balance > temp1.Balance)
      {
        richest.Balance = richest.Balance;
        strcpy(richest.Name, richest.Name);
      }
      else
      {
        strcpy(richest.Name, temp1.Name);
        richest.Balance = temp1.Balance;
      }
    }
    if(temp2.Balance > temp1.Balance)
    {
      if(richest.Balance > temp2.Balance)
      {
        richest.Balance = richest.Balance;
        strcpy(richest.Name, richest.Name);
      }
      else
      {
        strcpy(richest.Name, temp2.Name);
        richest.Balance = temp2.Balance;
      }
    }

  }
  cout << "The customer with maximum balance is " << richest.Name << endl << endl;
}

void Deposit(string name, PERSON a[], int N)
{
	float deposit;

	cout << name << ", how much would you like to deposit? ";
	cin >> deposit;

	for(int i = 0; i < N; i++)
	{
		if(name == a[i].Name)
		{
			a[i].Balance += deposit;
			cout << "Your new balance is: " << a[i].Balance << endl;
		}
	}
	cout << endl;
}

void NewCopy(string file, PERSON a[], int N)
{
	ofstream writeData;
	writeData.open(file);

	for(int i = 0; i < N; i++)
	{
		writeData << a[i].Name << " " << fixed << setprecision(2) << a[i].Balance << endl;
	}

	writeData.close();
}
