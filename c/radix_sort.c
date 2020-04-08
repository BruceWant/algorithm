#include <stdio.h>

void printArray(int * array, int size){
  
  int i;
  for (i = 0; i < size; i++)
    printf("%-5d ", array[i]);
  printf("\n");
}

int findLargestNum(int * array, int size){
  
  int i;
  int largestNum = array[0];
  
  for(i = 0; i < size; i++){
    if(array[i] > largestNum)
      largestNum = array[i];
  }
  
  return largestNum;
}

void radixSort(int * array, int size){
  
  // Base 10 is used
  int i;
  int semiSorted[size];
  int significantDigit = 1;
  int largestNum = findLargestNum(array, size);
  
  // Loop until we reach the largest significant digit
  while (largestNum / significantDigit > 0){
    int bucket[10] = { 0 };
    
    // Counts the number of "keys" or digits that will go into each bucket
    for (i = 0; i < size; i++)
      bucket[(array[i] / significantDigit) % 10]++;
    
    /**
     * Add the count of the previous buckets,
     * Acquires the indexes after the end of each bucket location in the array
		 * Works similar to the count sort algorithm
     **/
    for (i = 1; i < 10; i++)
      bucket[i] += bucket[i - 1];
    
    // Use the bucket to fill a "semiSorted" array
    for (i = size - 1; i >= 0; i--)
      semiSorted[--bucket[(array[i] / significantDigit) % 10]] = array[i];
    
    
    for (i = 0; i < size; i++)
      array[i] = semiSorted[i];
    
    // Move to next significant digit
    significantDigit *= 10;
  }
}

int main(){
  
  
  int size = 12;
  int list[] = {10, 2, 303, 4021, 293, 1, 0, 429, 480, 92, 2999, 14};
  
  printArray(&list[0], size);
  
  radixSort(&list[0], size);
  
  printArray(&list[0], size);
  
  return 0;
}
