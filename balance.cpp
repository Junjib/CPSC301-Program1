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
void Deposit(string name, PERSON a[], int N, float amount);
void NewCopy(string file, PERSON a[], int N);
int Counter(string file);
void BuildArray(int N, PERSON a[], string file);
PERSON * readData(int &N);

int main()
{
	int N = 0;
  string name;
  float amount = 0.0;
  PERSON *personPtr = nullptr;

  personPtr = readData(N);

  Display(personPtr, N);
  FindRichest(personPtr, N);
  Deposit(name, personPtr, N, amount);

  //BuildArray(N, arr, "data.txt");

	// ===================================================
	// Menu for selecting which function to execute
	/*do
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
			getline(cin, fullName);
			Deposit(fullName, arr, N);
			NewCopy("data.txt", arr, N);
			break;
		case -1:
			cout << "Exiting.\n";
		}

	}while(choice != -1);*/

	return 0;
}

void Display(PERSON a[], int N)
{
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
  cout << "Highest Balance: " << richest.Name << endl << endl;
}

void Deposit(string name, PERSON a[], int N, float amount)
{
  cout << "Enter name: ";
  cin.ignore();
  getline(cin, name);
  cout << name << endl;

  cout << "Amount: ";
  cin >> amount;

	for(int i = 0; i < N; i++)
	{
		if(name == a[i].Name)
		{
			a[i].Balance += amount;
			cout << "New balance: " << a[i].Balance << endl;
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

int Counter(string file)
{
  int N = 0;
  string readLine;
  ifstream readData2;
  readData2.open(file);
  while(readData2)
  {
    getline(readData2, readLine);
    N++;
  }
  N--;
  readData2.close();
  return N;
}

void BuildArray(int N, PERSON a[], string file)
{
  PERSON obj;
  string fName, lName, name;
  ifstream readData;
  readData.open("data.txt");

  // Checks if file successfully opens
  if(readData.fail())
  {
    cout << "Error\n";
  }

  // Stores PERSON obj into the PERSON array
  for(int i = 0; i < N; i++)
  {
    readData >> fName;
    readData >> lName;
    readData >> obj.Balance;
    name = fName + " " + lName;
    strcpy(obj.Name, name.c_str());
    a[i] = obj;
  }
  readData.close();
}

PERSON * readData(int &N)
{
  PERSON *personPtr = nullptr;
  ifstream readFile;
  string fullName, firstName, lastName;
  float balance;

  N = Counter("data.txt");
  personPtr = new PERSON[N];

  readFile.open("data.txt");

  for(int i = 0; i < N; i++)
  {
    readFile >> firstName;
    readFile >> lastName;
    readFile >> balance;
    personPtr[i].Balance = balance;

    if(firstName.size() > 9)
    {
      firstName.resize(9);
    }
    if(lastName.size() > 10)
    {
      lastName.resize(10);
    }

    fullName = firstName + " " + lastName;
    strcpy(personPtr[i].Name, fullName.c_str());
  }

  return personPtr;
}
