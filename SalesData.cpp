#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

class SALESREC {
  public:
   char     date[12];
	 char     region[12];
	 char     rep[12];
	 char     item[12];
	 int      units;
	 float    unitCost;
	 float    Total;
   void calcTotal(){
     Total = unitCost * units;
   }
};

void simpleSortTotal(SALESREC *x[] , int c)
{
	for (int i=0; i < c; i++)
		for (int j=i; j < c; j++)
		if (x[i] -> Total < x[j] -> Total)
		{
      SALESREC* s = x[i];
      x[i] = x[j];
      x[j] = s;
		}
} 

int main() {
  ifstream infile;
	int i=0;
	char cNum[10] ;
	SALESREC salesArr[40];
	int   salesArrayCount = 0;
	SALESREC* s[40];
  
	infile.open ("SalesDataPt2.csv");
  if (infile.is_open()){
    int c = 0;
    while (infile.good()){
      infile.getline(salesArr[c].date, 256, ',');
      infile.getline(salesArr[c].region,256, ' ');
		  infile.getline(salesArr[c].region, 256, ',');
      infile.getline(salesArr[c].rep,256, ' ');
		  infile.getline(salesArr[c].rep, 256, ',');
      infile.getline(salesArr[c].item,256, ' ');
		  infile.getline(salesArr[c].item, 256, ',');
		  infile.getline(cNum, 256, ',');
      salesArr[c].units = atoi(cNum);
      infile.getline(cNum, 256, '\n');
      salesArr[c].unitCost = atof(cNum);
      salesArr[c].calcTotal();
      c++;
      i++;
    }
    salesArrayCount = c-1;
		infile.close();
  }
  else
	{
		cout << "Error opening file";
	}
	
	// Initialize the sort array pointers
	for (int i=0; i < salesArrayCount; i++)
		s[i] = &salesArr[i];
  
	simpleSortTotal(s, salesArrayCount);

  cout << "OrderDate,Region,Rep,Item,Units,UnitCost,Total" << endl;
  for (int i=0; i < salesArrayCount-1; i++)
		cout << s[i]->date << ',' << s[i]->region << ',' << s[i]->rep << ',' << s[i]->item << ',' << s[i]->units << ',' << s[i]->unitCost << ',' << s[i]->Total << endl;
  
}