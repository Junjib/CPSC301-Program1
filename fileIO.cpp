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

int main()
{
	int N = 6;
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

	cout << endl;
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
	// ===================================================
	readData.close();
	Display(arr, N);
  cout << endl;
  FindRichest(arr, N);

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
}

void FindRichest(PERSON a[], int N)
{
  PERSON richest, temp1, temp2;

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

  cout << "The customer with maximum balance is " << richest.Name << endl;

}
