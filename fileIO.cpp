#include <iostream>
#include <fstream>

using namespace std;

struct PERSON
{
  char Name[20];
  float Balance;
};

void Display(PERSON a[], int N);

int main()
{



  return 0;
}

void Display(PERSON a[], int N)
{
  ifstream readData;
  readData.open("data.txt");

}
