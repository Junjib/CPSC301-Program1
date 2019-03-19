// Junji Bressan
// 301 Section 1

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
PERSON * readData(int &N);
void printmenu();

int main()
{
	int N = 0, choice;
  string name;
  float amount = 0.0;
  PERSON *personPtr = nullptr;

  personPtr = readData(N);

  do
{
    printmenu();
    cin >> choice;
    switch(choice)
    {
        case 1:
            // Act on display
            Display(personPtr, N);
            break;

        case 2:
            // Act on deposit
            cin.ignore();
            Deposit(name, personPtr, N, amount);
            break;

        case 3:
            // Act highest balance
            FindRichest(personPtr, N);
            break;

        case 4:
            // Act on update records
            NewCopy("data.txt", personPtr, N);
            break;

        case 5:
            // Must call update records here before exiting the program
            NewCopy("data.txt", personPtr, N);
            break;

        default:
            cout << "Invalid entry" << endl;
            break;
    }
    cout << endl;
} while(choice != 5);
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
  int recordCounter = 0;

  cout << "Enter name: ";
  getline(cin, name);

	for(int i = 0; i < N; i++)
	{
		if(name == a[i].Name)
		{
      cout << "Amount: ";
      cin >> amount;
			a[i].Balance += amount;
			cout << "New balance: " << a[i].Balance << endl;
      recordCounter++;
		}
	}

  if(recordCounter == 0)
  {
    cout << "Record not found\n";
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
  cout << "File Updated...\n";
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

void printmenu()
{
  cout << "Please enter a choice:" << endl;
  cout << "1. Display records"<< endl;
  cout << "2. Deposit funds"<< endl;
  cout << "3. Find Highest Balance" << endl;
  cout << "4. Update records" << endl;
  cout << "5. Exit the program" << endl;
}
