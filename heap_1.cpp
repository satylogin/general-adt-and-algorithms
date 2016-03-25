/* *
 * Code - basic heap functions
 * -----------------------------------------------------------------------
 * The following is i c++ implementation(for c, change cin && cout to
 * printf and scanf statements) of basic heap functions like max_heapify,
 * build heap, heap sort etc.
 * This heap is a max heap (value which are larger have greater priority).
 * -----------------------------------------------------------------------
 */
#include <iostream>
#include <limits.h>
#include <cstdlib>
#include <cstring>

// some constant declarations
#define SIZE 100
#define EMPTY INT_MIN

using namespace std;

// structure of our heap
struct tree {
	int t[SIZE];
	int hs; // for storing heap size
};

struct tree* create_tree();			// function to create a tree and set values to empty.
void display(struct tree *);			// to display data in hirarchical form.
struct tree* insert(struct tree*, int);		// to insert data at the end of the heap.
int left_child(int);				// to return the index of left child of given node.
int right_child(int);				// to return the index of right child of given node.
int get_max(struct tree*, int, int, int);	// to give maximum of 3 possibilities.
void max_heapify(struct tree *, int);		// to make a one error heap a valid heap.
void swap(struct tree*, int, int);		// to swap data at given indexes.
void build_heap(struct tree*);			// to make the whole heap valid.
void display_linear(struct tree*);		// to display data in linear fashion.
void heap_sort(struct tree *);			// to sort the data using heap sort.

int main()
{
	struct tree *tr;
	int data, index, reference;
	char str[30];

	// heap
	tr = create_tree();	

	// driver function
	cin >> str;
	while (strcmp(str, "exit") != 0) {
		if (strcmp(str, "insert") == 0) {
			cin >> data;
			tr = insert(tr, data);
		} else if (strcmp(str, "display") == 0) {
			display(tr);
		} else if (strcmp(str, "max_heapify") == 0) {
			cin >> index;
			max_heapify(tr, index);
		} else if (strcmp(str, "build_heap") == 0) {
			build_heap(tr);
		} else if (strcmp(str, "display_linear") == 0) {
			display_linear(tr);
		} else if (strcmp(str, "heap_sort") == 0) {
			heap_sort(tr);
		}

		cin >> str;
	}

	return 0;
}

/* *
 * create_tree()
 * ------------------------------------------------------------------------------
 * This function creates a new heap and set the value of all nodes as EMPTY.
 * The heap size is initialised to 0.
 */
struct tree* create_tree()
{
	struct tree *p;
	int i;
	p = (struct tree *)malloc(sizeof(struct tree));

	for (i = 0; i < SIZE; i++) {
		p->t[i] = EMPTY;
	}
	p->hs = 0;

	return p;
}

/* *
 * display()
 * --------------------------------------------------------------------------------
 * The following function is used to display the data in hirarchial format.
 */
void display(struct tree *p)
{
	int i, j = 1, count = 0;

	// check if the tree is not empty
	if (p->t[0] == EMPTY) {
		cout << "Empty Tree" << endl;
	} else {
		for (i = 0; i < SIZE; i++) {
			if (p->t[i] != EMPTY) {
				cout << p->t[i] << " ";
				count++;
			}	
			// to decide the no of internal nodes.
			if (count == j) {
				cout << endl;
				j = j * 2 + 1;
			}
		}
	}
	cout << endl;
}

/* *
 * insert()
 * -----------------------------------------------------------------------
 * This function is used to insert the data at the last of the heap.
 */
struct tree* insert(struct tree *root, int data)
{
	if (root->hs < SIZE) {
		root->t[(root->hs)++] = data;
	}

	return root;
		
}

/* *
 * left_child()
 * ------------------------------------------------------------------------
 * This function returns the index of left child of given node.
 */
int left_child(int n)
{
	return (2 * n + 1);
}

/* *
 * right_child()
 * ------------------------------------------------------------------------
 * This function gives the index of the right child of given node.
 */
int right_child(int n)
{
	return (2 * n + 2);
}

/* *
 * get_max()
 * ------------------------------------------------------------------------
 * This function returns the index of the maximum of parent or its two
 * child. It also handles error.
 */
int get_max(struct tree *root, int l, int r, int j)
{
	// if none of the child exist
	if ((l >= root->hs) && (r >= root->hs)) {
		return j;
	} else if (l >= root->hs) {
		// if only right child exist
		if (root->t[r] > root->t[j]) {
			return r;
		} else {
			return j;
		}
	} else if (r >= root->hs) {
		// if only left child exist
		if (root->t[l] > root->t[j]) {
			return l;
		} else {
			return j;
		}
	} else {
		// if both children exist
		int max = j;
		if (root->t[max] < root->t[l]) {
			max = l;
		}
		if (root->t[max] < root->t[r]) {
			max = r;
		}

		return max;
	}
}

/* *
 * max_heapify()
 * ----------------------------------------------------------------
 * This function assumes that there is only one error in the given
 * heap and it corrects that error.
 */
void max_heapify(struct tree *root, int index)
{
	int l, r, max, j;
	
	// if the give index in invalid
	if (index >= root->hs) {
		return;
	}

	j = index;
	while (1) {
		l = left_child(j);	// index of left child
		r = right_child(j);	// index of right child
		max = get_max(root, l, r, j);	
		if (max == j) {
			// if there is no swap then the heap is valid
			return;
		} else {
			swap(root, j, max);
			j = max;
		}
	}
}

/* *
 * swap()
 * ---------------------------------------------------------------------------
 * This function swaps the data at the given two indexes of given heap.
 */
void swap(struct tree *root, int i, int j)
{
	int tmp;
	tmp = root->t[i];
	root->t[i] = root->t[j];
	root->t[j] = tmp;
}

/* *
 * build_heap()
 * -------------------------------------------------------------------------
 * This function is used to make a given heap a valid heap. The approach 
 * used is bottom up approach.
 */
void build_heap(struct tree *root)
{
	int j;
	for (j = (root->hs / 2); j >= 0; j--) {
		max_heapify(root, j);
	}
}

/* *
 * display_linear()
 * -----------------------------------------------------------------------
 * To display data in linear fashion.
 */
void display_linear(struct tree * root)
{
	for (int i = 0; i < root->hs; i++) {
		cout << root->t[i] << " "; 
	}
	cout << endl;
}

/* *
 * heap_sort()
 * -------------------------------------------------------------------------
 * This function is used sort data by using the property of heap. The property
 * used is that the top data of heap is always the maximim data.
 */
void heap_sort(struct tree *root)
{
	int j = root->hs;
	build_heap(root);
	for (int i = 0; i < (j - 1); ++i) {
		max_heapify(root, 0);
		swap(root, 0, --(root->hs));
	}
	root->hs = j;
}
