#include "Sorting.h"
#include <iostream>


void Sorting::insertionSort(int array[], int arraySize)
{
	comparisons = 0;
	//sort list
	int i, j ,temp;
	 for (i = 1; i < arraySize; i++)
	 {
		 j = i;
			 while (j > 0 && array[j - 1] > array[j])
			 {
				 Sorting::setComparisons(comparisons + 1);
				 temp = array[j];
				 array[j] = array[j - 1];
				 array[j - 1] = temp;
				 j--;
			 }//while
	 }//for

	//Print list
	for (int k=0; k < arraySize; k++)
	{
		std::cout <<" "<< array[k];
	}//for
	std::cout<<std::endl<<
	"#Insertion-sort comparison: "<< comparisons<<std::endl;
}//insertion sort

void Sorting::merge(int array[], int leftFirst, int leftLast, int rightFirst, int rightLast, int tempArray[])
{
	int index = leftFirst;
	int saveFirst = leftFirst;
	while ((leftFirst <= leftLast) && (rightFirst <= rightLast))
	{
		if(array[leftFirst] < array[rightFirst])
		{
			tempArray[index] = array[leftFirst];
			leftFirst++;
		}//if
		else
		{
			tempArray[index] = array[rightFirst];
			rightFirst++;
		}//else
		index++;
	}//while
	while(leftFirst <= leftLast)
	{
		comparisons++;
		tempArray[index] = array[leftFirst];
		leftFirst++;
		index++;
	}//while
	while(rightFirst <= rightLast)
	{
		comparisons++;
		tempArray[index] = array[rightFirst];
		rightFirst++;
		index++;
	}//while
	for(index = saveFirst; index <= rightLast; index++)
		array[index] = tempArray[index];
}

void Sorting::mergeSort(int array[], int first, int last, int tempArray[])
{
	if(first < last)
	{
		int middle = (first + last)/2;
		Sorting::mergeSort(array,first, middle, tempArray);
		Sorting::mergeSort(array, middle+1, last, tempArray);
		Sorting::merge(array, first, middle,middle +1, last, tempArray);
	}//if
	//Print list
		for (int k=0; k < last; k++)
		{
			std::cout <<" "<< array[k];
		}//for
		std::cout<<std::endl<<
		"#Merge-sort comparison: "<< comparisons<<std::endl;

}
void Sorting::makeHeap(int array[], int arraySize, int i)
{
    int greatest = i; // Initialize greatest as root
    int left = 2*i + 1; // left = 2*i + 1
    int right = 2*i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < arraySize && array[left] > array[greatest])
        greatest = left;

    // If right child is larger than greatest so far
    if (right < arraySize && array[right] > array[greatest])
        greatest = right;

    // If greatest is not root
    if (greatest != i)
    {
        //swap
    	int temp;
    	temp = array[i];
    	array[i] = array[greatest];
    	array[greatest] = temp;

    	//recursive call
        makeHeap(array, arraySize, greatest);
    }
}

void Sorting::heapSort(int array[], int arraySize)
{
	comparisons = 0;
	 // Build heap (rearrange array)
	    for (int i =  arraySize / 2 - 1; i >= 0; i--)
	    {
	        makeHeap(array,  arraySize, i);
	        comparisons++;
	    }
	    // One by one extract an element from heap
	    for (int i=arraySize-1; i>=0; i--)
	    {
	        // Move current root to end
	        	//swap
	           	int temp;
	           	temp = array[i];
	           	array[i] = array[0];
	           	array[0] = temp;

	        makeHeap(array, i, 0);
	    }//for

	    //Print list
	    	for (int k=0; k < arraySize; k++)
	    	{
	    		std::cout <<" "<< array[k];
	    	}//for
	    	std::cout<<std::endl<<
	    	"#Heap -sort comparison: "<< comparisons<<std::endl;
}
int Sorting::quickHelper (int array[], int first, int arraySize)
{
	int temp;
    int lastIndex = array[arraySize];
    int start = (first - 1);  //

    for (int j = first; j < arraySize- 1; j++)
    {
        if (array[j] <= lastIndex)
        {
        	comparisons++;
            start++;
          //swap
            temp = array[start];
            array[start] = array[j];
			array[j] = temp;
        }
    }
    //swap
    temp = array[start + 1];
    array[start + 1] = array[arraySize];
   	array[arraySize] = temp;

   	return (start + 1);
}

void Sorting::quickSort(int array[], int first, int arraySize)
{
	if (first < arraySize)
	    {
	        int index = quickHelper(array, first, arraySize);
	        quickSort(array, first, index - 1);
	        quickSort(array, index + 1, arraySize);
	    }//if

	 //Print list
		    	for (int k=0; k < arraySize; k++)
		    	{
		    		std::cout <<" "<< array[k];
		    	}//for
		    	std::cout<<std::endl<<
		    	"#Heap -sort comparison: "<< comparisons<<std::endl;
}

int Sorting::getComparisons()
{
	return comparisons;
}

void Sorting::setComparisons(int i)
{
	comparisons = i;
}
