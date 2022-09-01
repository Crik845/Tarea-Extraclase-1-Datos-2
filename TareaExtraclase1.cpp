// Quick sort in C++

#include <iostream>
using namespace std;

// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to print the array
void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

// function to rearrange array (find the partition point)
int partition(int array[], int low, int high) {

  // select the rightmost element as pivot
  int pivot = array[high];

  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {

      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;

      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap pivot with the greater element at i
  swap(&array[i + 1], &array[high]);

  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {

    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on righ of pivot
    int pi = partition(array, low, high);

    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);

    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}// Selection sort in C++


void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {

      // To sort in descending order, change > to < in this line.
      // Select the minimum element in each loop.
      if (array[i] < array[min_idx])
        min_idx = i;
    }

    // put min at the correct position
    swap(&array[min_idx], &array[step]);
  }
}

// Insertion sort in C++

void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}



// Driver code
int main() {

  int data1[] = {8, 7, 6, 1, 0, 9, 2, 77, 4};
  int data2[] = {20, 12, 10, 15, 2, 87, 9};
  int data3[] = {9, 5, 1, 4, 3, 28, 45, 75};

  int n1 = sizeof(data1) / sizeof(data1[10]);
  int n2 = sizeof(data2) / sizeof(data2[10]);
  int n3= sizeof(data3) / sizeof(data3[10]);

  selectionSort(data1, n1);
  cout << "Sorted array selectionSort in acsending Order:\n";
  cout<<"\n";
  printArray(data1, n1);
  cout<<"\n";


  insertionSort(data2, n2);
  cout << "Sorted array insertionSort in ascending order:\n";
  cout<<"\n";
  printArray(data2, n2);
  cout<<"\n";


  quickSort(data3, 0, n3 - 1);
  cout << "Sorted array quickSort in ascending order: \n";
  cout<<"\n";
  printArray(data3, n3);
  cout<<"\n";
}
