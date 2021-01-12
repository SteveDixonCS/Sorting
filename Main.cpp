#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Sorting.h"

using namespace std;

int main(int argc, char* argv[])
{
	//create objects
	int arraySize = 10001;
	Sorting chooseSort;
	fstream fs;
	int input;
	int index;
	int array[arraySize];

	//read argument for filename and opens
	ifstream fin(argv[1]);
	if(fin.is_open())
	{
		while (fin >> input)
		{
		array[index] = input;
		index++;
		}
		fin.close();
	}
	else {//error has occurred
		cout << "Failed to open the input file" << endl;
		exit(1);
	}
	//print list of commands
	cout<<"COMMANDS: insertion-sort (i), merge-sort (m), heap-sort (h), quick-sort(q), bonus-sort(b)"
	<<endl<<endl;

	cout<<"Enter the algorithm: ";
	char command;
	cin>>command;

	 if(command == 'i' ||command == 'I')//insertion sort
	 {
		 chooseSort.insertionSort(array,arraySize);
		 exit(0);
	 }
	 else if(command == 'm' ||command == 'M')//merge sort
	 {
		 chooseSort.setComparisons(0);
		 int tempArray[arraySize];
		 chooseSort. mergeSort(array, 0, arraySize , tempArray);
		 exit(0);
	 }
	 else if(command == 'h' ||command == 'H')//heap sort
	 {
		 chooseSort.heapSort(array, arraySize);
		 exit(0);
	 }
	 else if(command == 'q' ||command == 'Q')//quick sort
		{
		 	 chooseSort.quickSort(array, 0, arraySize);
			 exit(0);
		}
	 else if(command == 'b' ||command == 'B')//BONUS
	{
		 cout<<"HAS NOT BEEN IMPLEMENTED "<<endl;
		 exit(0);
	}
	 else
	     {
	       cout<<endl<<"COMMAND NOT RECOGNISED. TRY AGAIN."<<endl<<endl;
	       exit(0);
	     }
}


