/*
 * Algorithms.c
 *
 *  Created on: Sep 30, 2019
 *      Author: PeterKleber
 */

#include "Algorithms.h"



/*
 * // C code to linearly search x in arr[]. If num
// is present then return its location, otherwise
// return -1

Time Complexity: O(n)
 */
int linear_Search(int num, int array_size, int arr[]) {
	int index = -1; //default return value
	for (int i = 0; i < array_size; i++) {
		if (num == arr[i]) {
			index = i; //if the number is present assign it to the return value and break
			break;
		}
	}

	return index; //return the return value
}

/*
 * Binary Search: Search a sorted array by repeatedly dividing the search interval in half.
 *  Begin with an interval covering the whole array. If the value of the search key is less
 *   than the item in the middle of the interval, narrow the interval to the lower half.
 *   Otherwise narrow it to the upper half. Repeatedly check until the value is found or
 *   the interval is empty.
 *
 *   Time Complexity: O(Logn)
 */

int binary_Search(int num, int array_size, int arr[]) {
	int start = 0; //from the first elemt in the array
	int end = array_size; // to the last element

	while (start <= end) {

		int middle = ((end - start) / 2 + start); // middle value

		if (num == arr[middle]) {

			return middle; // found the number return the index
		}

		else if (num < arr[middle]) { //if the number is smaller than the middle value

			end = middle - 1; // set the end limit to the last index before the middle

		} else {  //if the number is bigger than the middle value
			start = middle + 1; // set the start limit to the first index after the middle

		}
	}

	return -1; // if it cannot find the number
}

//function to swap 2 intgers
void swap(int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
/*
 * Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping
 * the adjacent elements if they are in wrong order.
 * Time Complexity: O(n*n)
 */
int Bubble_Sort(int array_size, int arr[]) {

	for (int i = 0; i < array_size; i++) {
		int swapped = 0;
		for (int j = 0; j < array_size - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				swapped = 1;
			}
		}
		if (swapped == 0) {
			break;
		}
	}

	return 1;
}

/*
 * Insertion sort is a simple sorting algorithm that works the way we sort playing cards
 *  in our hands.
 *  Time Complexity: O(n*2)
 */

int insertion_Sort(int array_size, int arr[]) {
	for (int i = 1; i < array_size; i++) {
		for (int j = i; j > 0; j--) {
			if (arr[j] < arr[j - 1]) {
				swap(&arr[j], &arr[j - 1]);
			}
		}
	}

	return 1;
}

/*Selection Sort
 *The selection sort algorithm sorts an array by repeatedly finding the minimum element
 * (considering ascending order) from unsorted part and putting it at the beginning
 *
 * Time Complexity: O(n2)
 */
void selectionSort(int arr[], int n) {
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n - 1; i++) {
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		// Swap the found minimum element with the first element
		swap(&arr[min_idx], &arr[i]);
	}
}

/*
 * Merge Sort
 Like QuickSort, Merge Sort is a Divide and Conquer algorithm.
 It divides input array in two halves, calls itself for the two halves and
 then merges the two sorted halves

 Time Complexity: O(nlog(n))
 */
void merge_sort(int i, int j, int a[], int aux[]) {
	if (j <= i) {
		return;     // the subsection is empty or a single element
	}
	int mid = (i + j) / 2;

	// left sub-array is a[i .. mid]
	// right sub-array is a[mid + 1 .. j]

	merge_sort(i, mid, a, aux);     // sort the left sub-array recursively
	merge_sort(mid + 1, j, a, aux);     // sort the right sub-array recursively

	int pointer_left = i; // pointer_left points to the beginning of the left sub-array
	int pointer_right = mid + 1; // pointer_right points to the beginning of the right sub-array
	int k;      // k is the loop counter

	// we loop from i to j to fill each element of the final merged array
	for (k = i; k <= j; k++) {
		if (pointer_left == mid + 1) {     // left pointer has reached the limit
			aux[k] = a[pointer_right];
			pointer_right++;
		} else if (pointer_right == j + 1) { // right pointer has reached the limit
			aux[k] = a[pointer_left];
			pointer_left++;
		} else if (a[pointer_left] < a[pointer_right]) { // pointer left points to smaller element
			aux[k] = a[pointer_left];
			pointer_left++;
		} else {        // pointer right points to smaller element
			aux[k] = a[pointer_right];
			pointer_right++;
		}
	}

	for (k = i; k <= j; k++) {      // copy the elements from aux[] to a[]
		a[k] = aux[k];
	}
}

