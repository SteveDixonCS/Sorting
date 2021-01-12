#ifndef SRC_SORTING_H_
#define SRC_SORTING_H_

class Sorting{

	public:
		//insertion sort operations
			void insertionSort(int array[], int arraySize);
		//merge sort operations
			//added function to help mergeSort
			void merge(int array[], int leftFirst, int leftLast, int rightFirst, int rightLast, int tempArray[]);
			void mergeSort(int array[], int first, int last, int tempArray[]);
		//heap sort operations
			//added function to help Heap Sort
			void makeHeap(int array[], int n, int i);
			void heapSort(int array[], int arraySize);
		//quick sort operations
		int quickHelper (int array[], int first, int arraySize);
		void quickSort(int array[], int first, int arraySize);
		//member functions
		int getComparisons();
		void setComparisons(int i);

	private:
		int comparisons;
};



#endif /* SRC_SORTING_H_ */
