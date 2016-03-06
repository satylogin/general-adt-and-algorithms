/* *
 * Code - Merge Sort Implementation
 * ---------------------------------------------
 * The folowing is a c implementation of popular
 * divide and conquer sorting technique called 
 * merge-sort. Its code is used to solve other 
 * problems like counting inversions by doing 
 * certain modifications
 *----------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *, int);		// The code use to sort. To sort an array, use this function
void sort(int *, int *, int, int);	// called by merge_sort 
void merge(int *, int*, int, int, int);	// called by sort 

int main()
{
	//driver program
	int n, i;
	//number of elements to be sorted
	scanf("%d", &n);
	int arr[n];

	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	//to sort the array aquired
	merge_sort(arr, n);

	//printing the sorted value
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

/* *
 * merge_sort()
 * ----------------------------------------------------
 * It creates a temporary array to store the values of
 * sorted data during time of sorting process
 */
void merge_sort(int arr[], int size)
{
	// creating an auxilary array to store sorted data
	int *tmp = (int *)malloc(sizeof(int) * size);
	
	//calling the function to sort data
	sort(arr, tmp, 0, size - 1);
}

/* *
 * sort()
 * ----------------------------------------------------
 * It divides the problem into subproblem and then 
 * solve the subproblems seperately. Finally it combines
 * the data of two subproblem by calling merge().
 */
void sort(int arr[], int tmp[], int start, int end)
{
	// atleast have 2 elements so that it can be 
	// divided into subproblem
	if (start < end) {
		int mid;
		// calculating the mid vaue
		mid = start + (end - start) / 2;

		//sorting part 1
		sort(arr, tmp, start, mid);

		//sorting part 2
		sort(arr, tmp, mid + 1, end);

		//combining the two sorted parts
		merge(arr, tmp, start, mid+1, end);
	}
}

/* *
 * merge()
 * ----------------------------------------------------
 * It combines the two subproblems. It is the conquer
 * part of divide and conquer algorithm
 */
void merge(int arr[], int tmp[], int start, int mid, int end)
{
	int i, j, k;
	i = start;	// to trace first subpart
	j = mid;	// to trace second subpart
	k = start;	// to trace temporary array

	// runs till one of the subarray gets exhausted
	while ((i < mid) && (j <= end)) {
		if (arr[i] <= arr[j]) {
			tmp[k++] = arr[i++];
		} else {
			tmp[k++] = arr[j++];
		}
	}

	// if j was exhausted, (j > end), elements
	// are still left in first half.
	while (i < mid) {
		tmp[k++] = arr[i++];
	}

	// if i was exhausted, (i == mid), elements
 	// are still left in second half
	while (j <= end) {
		tmp[k++] = arr[j++];
	}

	//copying back the sorted data into main array
	for (i = start; i <= end; i++) {
		arr[i] = tmp[i];
	}
}
