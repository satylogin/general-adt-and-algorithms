/* *
 * Program- Doubly Link List, Code by- Satyarth Agrahari
 * -----------------------------------------------------------------------------
 * The following is a c++/c implementation of doubly link list. There is an 
 * dynamic driver program associated with it. Root is the main pointer.
 * Function are the adt implementation of the list.
 * For c users- replace node with struct node whereever used.
 * */

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

#define ERROR -99999999

// struct of the data node
struct node {
	int data;
	node *next, *prev;
};

node* new_node(int);				// function to create a new node with a given data value.
bool is_empty(node *);				// function to check whether the list is empty.
void print_all(node *);				// function to print data value in list.
node* insert_beg(node *, int);			// function to add data at the begining of the list.
node* insert_last(node *, int);			// function to add data at the end of the list.
void insert_after(node *, int);			// function to add node after the given node.
node* search(node *, int);			// to search for position of a data in a given list.
node* insert_after_x(node *, int, int);		// to insert data after the given data value.
node* delete_beg(node *);			// to delete the head node.
node* delete_last(node *);			// to delete the last node of the list.
void delete_after(node *);			// to delete node after reference node.
node* delete_after_x(node *, int);		// to delete the node after the node with value x
int size(node *);				// to get the size of the list.
void print_palindrom(node *);			// to print the list in palindromic style.
node* simple_sort(node *);			// to sort data in list.
node* swap(node*, node*, node*);		// to swap nodes.
node* merge_sort(node *);			// sorting data in link list.
node* merge(node *, node *);			// to merge data in sorted order.
node* sorted_insert(node *, node *);		// to insert a node in sorted list.
node* reverse_list(node *);			// to reverse the list.
node* bubble_sort(node *);			// to sort the list using bubble sort algorithm.

// the main program
int main()
{
	node *root;	// main pointer
	root = NULL;	

	char str[30], ch[5];
	int data, index, reference;

	// driver code for doubly linked list
	cin >> str;
	while (strcmp(str, "exit") != 0) {
		if (strcmp(str, "insert_beg") == 0) {
			cin >> data;
			root = insert_beg(root, data);
		} else if (strcmp(str, "print_all") == 0) {
			print_all(root);
		} else if (strcmp(str, "insert_last") == 0) {
			cin >> data;
			root = insert_last(root, data);
		} else if (strcmp(str, "insert_after_x") == 0) {
			cin >> data >> reference;
			root = insert_after_x(root, data, reference);
		} else if (strcmp(str, "delete_beg") == 0) {
			root = delete_beg(root);
		} else if (strcmp(str, "delete_last") == 0) {
			root = delete_last(root);
		} else if (strcmp(str, "delete_after_x") == 0) {
			cin >> reference;
			root = delete_after_x(root, reference);
		} else if (strcmp(str, "size") == 0) {
			cout << "The size of list is " << size(root) << endl;
		} else if (strcmp(str, "print_palindrom") == 0) {
			print_palindrom(root);
		} else if (strcmp(str, "simple_sort") == 0) {
			root = simple_sort(root);
		} else if (strcmp(str, "merge_sort") == 0) {
			root = merge_sort(root);
		} else if (strcmp(str, "reverse_list") == 0) {
			root = reverse_list(root);
		} else if (strcmp(str, "bubble_sort") == 0) {
			root = bubble_sort(root);
		}

		cin >> str;
	}

	return 0;
}

/* *
 * new_node()
 * -------------------------------------------------------------------
 * This function allocated a memory in the head for the data node
 * and sets the value of data provided. Returned node's pointer
 * are pointing to the NULL.
 */
node* new_node(int data)
{
	node *tmp;
	tmp = (node *)malloc(sizeof(node));
	tmp->data = data;
	tmp->next = NULL;
	tmp->prev = NULL;

	return tmp;
}

/* *
 * is_empty()
 * --------------------------------------------------------------------
 * function to check whether the list is empty. Value returned will be
 * true when the list is empty and false otherwise.
 */
bool is_empty(node *root)
{
	return (root == NULL);
}

/* *
 * print()
 * ---------------------------------------------------------------------
 * function to print data value in list. In case of empty list a message 
 * is print on the screen.
 */
void print_all(node *root)
{
	if (root == NULL) {
		cout << "The list is empty" << endl;
	} else {
		while (root != NULL) {
			cout << root->data << " ";
			root = root->next;
		}
		cout << endl;
	}
}

/* *
 * insert_beg()
 * ---------------------------------------------------------------------
 * function to add data the begining of the list. The head pointer to
 * the new node is returned.
 */
node* insert_beg(node *root, int data)
{
	node *tmp;
	tmp = new_node(data);

	if (root != NULL) {
		tmp->next = root;
		root->prev = tmp;
	}

	return tmp;
}

/* *
 * insert_last()
 * -----------------------------------------------------------------------
 * the function to insert data the end of the list. The value returned is 
 * the head address of the new list.
 */
node* insert_last(node *root, int data)
{
	node *tmp, *p;
	tmp = new_node(data);

	if (root == NULL) {
		root = tmp;
	} else {
		p = root;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = tmp;
		tmp->prev = p;
	}

	return root;
}

/* *
 * insert_after()
 * -------------------------------------------------------------------------
 * this function insert a given node after the node referred by the pointer.
 * in case of reference node is NULL, no change happens.
 */
void insert_after(node *p, int data)
{
	if (p != NULL) {
		node *q, *tmp;
		tmp = new_node(data);

		q = p->next;
		if (q == NULL) {
			p->next = tmp;
			tmp->prev = p;
		} else {
			p->next = tmp;
			tmp->prev = p;
			tmp->next = q;
			q->prev = tmp;
		}
	}
}

/* *
 * search()
 * ---------------------------------------------------------------------------
 * the following function search for the first occurance of the data and then
 * return the pointer to that location. In case there is no mathching data,
 * NULL is returned.
 */
node* search(node *p, int data)
{
	while (p != NULL) {
		if (p->data == data) {
			break;
		}
		p = p->next;
	}

	return p;
}

/* *
 * insert_after_x()
 * ---------------------------------------------------------------------------
 * The following function is used to insert data after a given data value.
 * first argument is the start position of list, second is the value to
 * enter in list, third argumenet the value after which we have to insert.
 * in case of the unsuccessful search, list is not modified.
 */
node* insert_after_x(node *root, int data, int x)
{
	node *tmp, *p, *q;
	p = search(root, x);
	if (p != NULL) {
		tmp = new_node(data);
		q = p->next;

		if (q == NULL) {
			p->next = tmp;
			tmp->prev = p;
		} else {
			p->next = tmp;
			q->prev = tmp;
			tmp->next = q;
			tmp->prev = p;
		}
	}

	return root;
}

/* *
 * delete_beg()
 * -----------------------------------------------------------------------------
 * the following function deletes the head node and return the pointer to head
 * of new list. In case of deleting empty list, error message is printed on screen.
 */
node* delete_beg(node *root)
{
	if (root == NULL) {
		cout << "Cannot delete from an empty list" << endl;
	} else {
		node *p;
		p = root;
		root = root->next;
		if (root != NULL) {
			root->prev = NULL;
		}
		cout << "The value deleted is " << p->data << endl;
		free(p);
	}

	return root;
}

/* *
 * delete_last()
 * -----------------------------------------------------------------------------
 * the following function is used to delete the last node of the list. The value
 * returned is the poineter to the head of the new list. In case of deleting
 * from an empty list, an error message is printed on the screen.
 */
node* delete_last(node *root)
{
	node *p, *q;
	p = root;
	if (p == NULL) {
		cout << "Cannot delete from an empty list" << endl;
	} else if (p->next == NULL) {
		cout << "The data deleted is " << p->data << endl;
		root = NULL;
		free(p);
	} else {
		while (p->next != NULL) {
			q = p;
			p = p->next;
		}	
		q->next = NULL;
		cout << "The data deleted is " << p->data << endl;
		free(p);
	}

	return root;
}

/* *
 * delete_after()
 * ---------------------------------------------------------------------------
 * this function deletes the node after given reference node.
 */
void delete_after(node *p)
{
	if ((p != NULL) && (p->next != NULL)) {
		node *q;
		q = p->next;
		p->next = q->next;
		free(q);
		q = p->next;
		if (q != NULL) {
			q->prev = p;
		}
	}
}

/* *
 * delete_after_x()
 * ------------------------------------------------------------------------------
 * This function is used to delete the node after the first node with value x.
 * the value returned is the head pointer to the new list.
 */
node* delete_after_x(node *root, int data)
{
	node *p, *q;
	p = search(root, data);
	
	if ((p != NULL) && (p->next != NULL)) {
		q = p->next;
		cout << "Data deleted is " << q->data << endl;
		p->next = q->next;
		free(q);
		q = p->next;
		if (q != NULL) {
			q->prev = p;
		}
	}

	return root;
}

/* *
 * size()
 * -------------------------------------------------------------------------------
 * this function is used to get the size of the list.
 */
int size(node *p) 
{
	int count = 0;
	while (p != NULL) {
		count++;	
		p = p->next;
	}

	return count;
}

/* *
 * print_palindrom()
 * --------------------------------------------------------------------------------
 * the following function is used to print the data of the list int palindromic
 * style.
 */
void print_palindrom(node *root)
{
	if (root == NULL) {
		cout << "The list is empty" << endl;
	} else {
		while (root->next != NULL) {
			cout << root->data << " ";
			root = root->next;
		}
		while (root->prev != NULL) {
			cout << root->data << " ";
			root = root->prev;
		}
		cout << root->data << endl;
	}
}

/* *
 * simple_sort()
 * ---------------------------------------------------------------------------
 * this is a simple insertion sort algorithm for sorting link list.
 */
node* simple_sort(node *root)
{
	if (root != NULL) {
		node *tmp = NULL, *p;
		while (root != NULL) {
			p = root;
			root = root->next;

			tmp = sorted_insert(tmp, p);
		}
		root = tmp;
	}

	return root;
}

/* *
 * swap()
 * --------------------------------------------------------------------------
 * this function is used to swap node a with node b, third agrument is head
 * node of the list.
 */
node* swap(node *a, node *b, node *root)
{
	if ((a != NULL) && (b != NULL)) {
		node *p;
		p = new_node(ERROR);

		p->prev = b->prev;
		if (b->prev != NULL) b->prev->next = p;
		p->next = b->next;
		if (b->next != NULL) b->next->prev = p;

		b->prev = a->prev;
		if (a->prev != NULL) a->prev->next = b;
		b->next = a->next;
		if (a->next != NULL) a->next->prev = b;

		a->prev = p->prev;
		if (p->prev != NULL) p->prev->next = a;
		a->next = p->next;
		if (p->next != NULL) p->next->prev = a;

		free(p);

		if (a == root) {
			return b;
		}
	}
	return root;
}

/* *
 * merge_sort()
 * -------------------------------------------------------------------------
 * this is divide part of divivde and conquer algorithm. we divide the list
 * continuously into two parts and then merge them back in sorted order.
 */
node* merge_sort(node *root)
{
	if ((root != NULL) && (root->next != NULL)) {
		node *a, *b;
		a = root;
		b = root->next;

		// break the list into two parts
		while ((b != NULL) && (b->next != NULL)) {
			a = a->next;
			b = b->next;
			if (b != NULL) {
				b = b->next;
			} else {
				break;
			}
		}
		b = a->next;
		a->next = NULL;
		b->prev = NULL;
		a = root;

		// call merge_sort
		a = merge_sort(a);
		b = merge_sort(b);

		// merge the sorted part
		root = merge(a, b);
	}

	return root;
}
/* *
 * merge()
 * ----------------------------------------------------------------------------
 * this function combines two sorted array in sorted order.
 */
node* merge(node *a, node *b)
{
	node *root, *p;
	if (a == NULL) {
		return b;
	} else if (b == NULL) {
		return a;
	} else {
		// checking for the first data
		if (a->data <= b->data) {
			root = a;
			a = a->next;
			p = root;
			if (a != NULL) {
				a->prev = NULL;
			}
			root->next = NULL;
		} else {
			root = b;
			b = b->next;
			p = root;
			if (b != NULL) {
				b->prev = NULL;
			}
			root->next = NULL;
		}	

		// filling in the other values
		while ((a != NULL) && (b != NULL)) {
			if (a->data <= b->data) {
				p->next = a;
				a->prev = p;
				a = a->next;
			} else {
				p->next = b;
				b->prev = p;
				b = b->next;
			}
			p = p->next;
		}

		// search for the node that is non empty
		if (a == NULL) {
			p->next = b;
			if (b != NULL) {
				b->prev = p;
			}
		} else if (b == NULL) {
			p->next = a;
			if (a  != NULL) {
				a->prev = p;
			}
		}

		return root;
	}
}

/* *
 * sorted_insert()
 * ----------------------------------------------------------------------
 * this function inserts the node in the list maintining sorted property 
 * of the list.
 */
node* sorted_insert(node *root, node *tmp)
{
	if (root == NULL) {
		tmp->next = NULL;
		tmp->prev = NULL;
		return tmp;
	} else {
		if (tmp->data <= root->data) {
			tmp->next = root;
			root->prev = tmp;
			tmp->prev = NULL;
			return tmp;
		} else {
			node *p;
			p = root;
			while ((p->next != NULL) && (p->data <= tmp->data)) {
				p = p->next;
			}
			if (p->next == NULL) {
				if (p->data > tmp->data) {
					p = p->prev;
					tmp->next = p->next;
					tmp->prev = p;
					p->next = tmp;
					tmp->next->prev = tmp;
				} else {
					p->next = tmp;
					tmp->prev = p;
					tmp->next = NULL;
				}
			} else {
				p = p->prev;
				tmp->next = p->next;
				tmp->prev = p;
				p->next = tmp;
				tmp->next->prev = tmp;
			}
		}
		return root;
	}
}

/* *
 * reverse_list()
 * ----------------------------------------------------------------------------
 * this function is used to reverse the list.
 */
node* reverse_list(node *root)
{
	if ((root == NULL) || (root->next == NULL)) {
		return root;
	}

	node *p, *q;
	p = root->next;
	q = NULL;
	while (root != NULL) {
		root->next = q;
		root->prev = p;
		q = root;
		root = p;
		if (p != NULL) {
			p = p->next;	
		}
	}
	root = q;

	return root;
}

/* *
 * bubble_sort()
 * -----------------------------------------------------------------------------
 * the following function is used to sort the doubly link list using bubble
 * sort algorithm.
 */
node* bubble_sort(node *root)
{
	node *p, *q, *tmp, *aux;
	p = root;
	while (p != NULL) {
		q = p->next;
		while (q != NULL) {
			if (p->data > q->data) {
				root = swap(p, q, root);
				tmp = p;
				p = q;
				q = tmp;
			}
			q = q->next;
		}
		p = p->next;
	}

	return root;
}
