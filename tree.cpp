#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <limits.h>

using namespace std;

#define SIZE 100
#define ERROR -99999999

struct node {
	int data;
	node *left;
	node *right;
	node *top;
};

node* create_node(int);					// to create a new node with given data
node* insert(node *, int);				// insert data into bst
node* insert_iterative(node *, int);			// iterative version of insert
node* search(node *, int);				// search a given key in bst
node* search_iterative(node *, int);			// iterative version of search

void inorder(node *);					// inorder traversal of bst
void preorder(node *);					// preorder traversal of bst
void postorder(node *);					// postorder traversal of bst
void levelorder(node *);				// level order traversal of bst
void level_print(node *);				// print each level on a new line
void paths(node *, int *, int);				// print all root to leaf paths
void print_at_level(node *, int);			// print all nodes at a particular level

node* minimum(node *);					// find minimum key in bst
node* maximum(node *);					// find maximum key in the bst
int size(node *);					// find total number of nodes
int height(node *);					// find the height of the bst
int max(int, int);					// return the max of the two int
int min(int, int);					// return the min of the two values
int get_level(node *, int);				// to find the level of key in bst

void print_leaf(node *);				// to print all leaf nodes
int no_of_leaf(node *);					// count leaf in the bst
int sum_of_leaf(node *);				// sum of value at leaf node

node* del(node *, int );				// to delete node with given key
node* successor(node *, int);				// find the successor of given key
node* predecessor(node *, int);				// find the predecessor of given data
node* delete_tree(node *);				// delete the whole tree
bool comp(node *, node*);				// comp two trees for equality
node* swap(node*, node*, node*);			// to swap two nodes of given bst

void new_path(node *);					// rjit bst ques
int even_left(node *);
int even_right(node *);

int kth_largest_data(node *, int);			// find the kth largest data in tree
void calc_pre(node *, int *, int *);			// traverse certain number of nodes in order
int closest_leaf(node *);				// to get the closest leaf in bst
void get_all_leaf(node*, node**, int*, int*, int);	// to store distance and address of all leaf nodes

node* mirror(node *);					// generate the mirror tree of a given bst
void print_at_dist_k(node *, int, int);			// to print all nodes at distance k
void print_ansestors(node *, int, int *);		// to print all the ansestors
node* pre_in(int *, int, int, int *, int, int);		// create a tree from given pre and in order
node* post_in(int*, int, int, int*, int, int);		// create a bst from given post and in order
node* delete_leaf(node *);				// to delete all the leaf nodes of bst
node* delete_by_root(node *);				// to delete bst by deleting root node 
bool check_bst(node *, int, int);			// to check a given tree is bst or not
bool check_sum_tree(node *);				// to check a binary tree is a sum tree or not
int find_dist(node *, int, int);			// to get minimum distance between two key
int depth(node *, node *);				// to find the depth of a given node
int print_all(node *, int);				// print data with depth and height
void delete_duplicate(node *);				// to delete all duplicate data in bst
node* common_ansestor(node*, int, int);			// find common ansestor of given data
node* pre_post(int *, int, int, int *, int, int);	// create full bst from pre and post order

int main()
{
    node *root, *tmp;
	root = NULL;

	int data, arr[SIZE], index, i, j;
	char str[30];

	// temp driver program
	root = insert(root, 6);
	root = insert(root, 3);
	root = insert(root, 9);
	root = insert(root, 2);
	root = insert(root, 4);
	root = insert(root, 7);
	root = insert(root, 10);
	root = insert(root, 6);

	cin >> str;
	while (strcmp(str, "exit") != 0) {
		if (strcmp(str, "insert") == 0) {
			cin >> data;
			root = insert(root, data);
		} else if (strcmp(str, "search") == 0) {
			cin >> data;
			if (search(root, data)) {
				cout << "The data is in the bst" << endl;
			} else {
				cout << "The data is not in the bst" << endl;
			}
		} else if (strcmp(str, "insert_iterative") == 0) {
			root = insert_iterative(root, data);
		} else if (strcmp(str, "search_iterative") == 0) {
			cin >> data;
			if (search_iterative(root, data)) {
				cout << "The data found in the bst" << endl;
			} else {
				cout << "The data is not in the bst" << endl;
			}
		} else if (strcmp(str, "preorder") == 0) {
			preorder(root);
			cout << endl;
		} else if (strcmp(str, "postorder") == 0) {
			postorder(root);
			cout << endl;
		} else if (strcmp(str, "inorder") == 0) {
			inorder(root);
			cout << endl;
		} else if (strcmp(str, "minimum") == 0) {
			tmp = minimum(root);
			if (tmp) {
				cout << "The minimum value in bst is " << tmp->data << endl;
			} else {
				cout << "The bst is empty" << endl;
			}
		} else if (strcmp(str, "maximum") == 0) {
			tmp = maximum(root);
			if (tmp) {
				cout << "The maximum value in bst is " << tmp->data << endl;
			} else {
				cout << "The bst is empty" << endl;
			}
		} else if (strcmp(str, "levelorder") == 0) {
			levelorder(root);
			cout << endl;
		} else if (strcmp(str, "level_print") == 0) {
			level_print(root);
		} else if (strcmp(str, "print_leaf") == 0) {
			print_leaf(root);
			cout << endl;
		} else if (strcmp(str, "no_of_leaf") == 0) {
			cout << "The number of leaf nodes are " << no_of_leaf(root) << endl;
		} else if (strcmp(str, "delete") == 0) {
			cin >> data;
			root = del(root, data);
		} else if (strcmp(str, "successor") == 0) {
			cin >> data;
			tmp = successor(root, data);
			if (tmp) {
				cout << "The successor of " << data << " is " << tmp->data << endl;
			} else {
				cout << "No successor exist" << endl;
			}
		} else if (strcmp(str, "predecessor") == 0) {
			cin >> data;
			tmp = predecessor(root, data);
			if (tmp) {
				cout << "The predecessor of " << data << " is " << tmp->data << endl;
			} else {
				cout << "No predecessor exist" << endl;
			}
		} else if (strcmp(str, "sum_of_leaf") == 0) {
			cout << "The sum of leaf keys is " << sum_of_leaf(root) << endl;
		} else if (strcmp(str, "size") == 0) {
			cout << "The size of the bst is " << size(root) << endl;
		} else if (strcmp(str, "height") == 0) {
			cout << "The height of the bst is " << height(root) << endl;
		} else if (strcmp(str, "paths") == 0) {
			paths(root, arr, 0);
		} else if (strcmp(str, "delete_tree") == 0) {
			root = delete_tree(root);
			cout << endl;
		} else if (strcmp(str, "print_at_level") == 0) {
			cin >> data;
			print_at_level(root, data);
		} else if (strcmp(str, "get_level") == 0) {
			cin >> data;
			index = get_level(root, data);
			if (index >= 0) {
				cout << "index is " << index << endl;
			} else {
				cout << "data not found" << endl;
			}
		} else if (strcmp(str, "kth_largest_data") == 0) {
			cin >> index;
			cout << "The data is " << kth_largest_data(root, index) << endl;
		} else if (strcmp(str, "mirror") == 0) {
			tmp = mirror(root);
			levelorder(root);
		} else if (strcmp(str, "closest_leaf") == 0) {
			data = closest_leaf(root);
			if (data == ERROR) {
				cout << "Tree is empty" << endl;
			} else {
				cout << "least dist leaf is " << data << endl;
			}
		} else if (strcmp(str, "print_at_dist_k") == 0) {
			cin >> index;
			print_at_dist_k(root, index, 0);
			cout << endl;
		} else if (strcmp(str, "print_ansestors") == 0) {
			cin >> data;
			i = 0;
			print_ansestors(root, data, &i);
			cout << endl;
		} else if (strcmp(str, "pre_in") == 0) {
			int i, n;
			cin >> n;
			int pre[n], in[n];
			for (i = 0; i < n; ++i) cin >> pre[i];
			for (i = 0; i < n; ++i) cin >> in[i];
			tmp = pre_in(pre, 0, n-1, in, 0, n-1);
			level_print(tmp);
		} else if (strcmp(str, "post_in") == 0) {
			int i, n;
			cin >> n;
			int post[n], in[n];
			for (i = 0; i < n; ++i) cin >> post[i];
			for (i = 0; i < n; ++i) cin >> in[i];
			tmp = post_in(post, 0, n-1, in, 0, n-1);
			level_print(tmp);
		} else if (strcmp(str, "delete_leaf") == 0) {
			root = delete_leaf(root);
		} else if (strcmp(str, "delete_by_root") == 0) {
			root = delete_by_root(root);
		} else if (strcmp(str, "check_bst") == 0) {
			if (check_bst(root, INT_MIN, INT_MAX)) {
				cout << "The tree is bst" << endl;
			} else {
				cout << "The tree is not bst" << endl;
			}
		} else if (strcmp(str, "check_sum_tree") == 0) {
			if (check_sum_tree(root)) {
				cout << "The tree is a sum tree" << endl;
			} else {
				cout << "The tree is not a sum tree" << endl;
			}
		} else if (strcmp(str, "find_distance") == 0) {
			int a, b;
			cin >> a >> b;
			int dist = find_dist(root, a, b);
			if (dist == ERROR) {
				cout << "Please enter valid keys" << endl;
			} else {
				cout << "The dist is " << dist << endl;
			}
		} else if (strcmp(str, "print_all") == 0) {
			print_all(root, 0);
		} else if (strcmp(str, "delete_duplicate") == 0) {
			delete_duplicate(root);
		} else if (strcmp(str, "common_ansestor") == 0) {
			int a, b;
			cin >> a >> b;
			tmp = common_ansestor(root, a, b);
			if (tmp) {
				cout << "Common ansestor is " << tmp->data << endl;
			} else {
				cout << "enter valid key nodes" << endl;
			}
		} else if (strcmp(str, "pre_post") == 0) {
			int n, i;
			cin >> n;
			int pre[n], post[n];
			for (i = 0; i < n; ++i) cin >> pre[i];
			for (i = 0; i < n; ++i) cin >> post[i];
			tmp = pre_post(pre, 0, n-1, post, 0, n-1);
			level_print(tmp);
		} else if (strcmp(str, "check_complete") == 0) {
			if (check_complete(root) == 0) {
				cout << "complete" << endl;
			} else {
				cout << "not complete" << endl;
			}
		}

		cin >> str;
	}

	return 0;
}

// create a new node with given data
node* create_node(int data)
{
	node *p;
	p = (node *)malloc(sizeof(node));
	p->data = data;
	p->left = p->right = p->top = NULL;

	return p;
}

// insert node int bst
node* insert(node *root, int data)
{
	if (root == NULL) {
		return create_node(data);
	}

	if (data <= root->data) {
		root->left = insert(root->left, data);
		root->left->top = root;
	} else {
		root->right = insert(root->right, data);
		root->right->top = root;
	}

	return root;
}

// iterative method of insert function
node* insert_iterative(node *root, int data)
{
	if (root == NULL) {
		return create_node(data);
	} else {
		node *p = root;
		while (1) {
			if (data <= p->data) {
				if (p->left == NULL) {
					p->left = create_node(data);
					p->left->top = p;
					break;
				} else {
					p = p->left;
				}
			} else {
				if (p->right == NULL) {
					p->right = create_node(data);
					p->right->top = p;
					break;
				} else {
					p = p->right;
				}
			}
		}

		return root;
	}
}

// search a key in bst
node* search(node *root, int data)
{
	if (root != NULL) {
		if (data == root->data) {
			return root;
		} else if (data < root->data) {
			return search(root->left, data);
		} else {
			return search(root->right, data);
		}
	}

	return root;
}

// iterative version of search
node* search_iterative(node *root, int data)
{
	while (root != NULL) {
		if (data == root->data) {
			break;
		} else if (data < root->data) {
			root = root->left;
		} else {
			root = root->right;
		}
	}

	return root;
}

// inorder traversal
void inorder(node *root)
{
	if (root != NULL) {
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

// preorder traversal
void preorder(node *root)
{
	if (root != NULL) {
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

// postorder traversal
void postorder(node *root)
{
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
	}
}

// level order traversal of bst
void levelorder(node *root)
{
	if (root != NULL) {
		queue <node *> q;
		node *p;
		q.push(root);

		while (!q.empty()) {
			p = q.front();
			q.pop();
			if (p->left) {
				q.push(p->left);
			}
			if (p->right) {
				q.push(p->right);
			}

			cout << p->data << " ";
		}

	} else {
		cout << "Empty bst";
	}
}

// print each level on a new line
void level_print(node *root)
{
	if (root != NULL) {
		queue <node *> q;
		node *p;
		int x;
		q.push(root);

		while (!q.empty()) {
			x = q.size();
			while (x--) {
				p = q.front();
				q.pop();
				if (p->left) {
					q.push(p->left);
				}
				if (p->right) {
					q.push(p->right);
				}

				cout << p->data << " ";
			}	
			cout << endl;
		}

	} else {
		cout << "Empty bst" << endl;
	}
}

// print all root to leaf paths
void paths(node *root, int arr[], int i)
{
	if (root != NULL) {
		arr[i] = root->data;
		if (root->left == NULL && root->right == NULL) {
			for (int j = 0; j <= i; ++j) {
				cout << arr[j] << " ";
			}
			cout << endl;
		}

		if (root->left != NULL) {
			paths(root->left, arr, i+1);
		}

		if (root->right != NULL) {
			paths(root->right, arr, i+1);
		}
	}
}

// print all the nodes at a particular level
void print_at_level(node *root, int level)
{
	if (root == NULL) {
		cout << "Empty bst" << endl;
	} else {
		node *p;
		int x = 0, y, flag = 0;
		queue <node *> q;
		q.push(root);
		while (!q.empty()) {
			y = q.size();
			if (x == level) {
				flag = 1;
				while (y--) {
					p = q.front();
					q.pop();
					cout << p->data << " ";
				}
				cout << endl;
			} else {
				while (y--) {
					p = q.front();
					q.pop();
					if (p->left) q.push(p->left);
					if (p->right) q.push(p->right);	
				}	
				x++;
			}
		}
		if (flag == 0) {
			cout << "Error" << endl;
		}
	}
}

// find minimum is bst
node* minimum(node *root)
{
	if (root != NULL) {
		while (root->left != NULL) {
			root = root->left;
		}
	}

	return root;
}

// find the maximum in bst
node* maximum(node *root)
{
	if (root != NULL) {
		while (root->right != NULL) {
			root = root->right;
		}
	}

	return root;
}

// find total number of nodes in bst
int size(node *root) 
{
	int count = 0;
	if (root != NULL) {
		return (size(root->left) + size(root->right) + 1);
	}
	return count;
}

// find the height of the tree
int height(node *root)
{
	if (root == NULL) {
		return -1;
	} else {
		return (max(height(root->left), height(root->right)) + 1);
	}
}

// return max of two int
int max(int a, int b)
{
	if (a > b) return a;
	return b;
}

// return min of two int
int min(int x, int y)
{
	if (x < y) return x;
	return y;
}

// to get the level of a key in bst
int get_level(node *root, int data)
{
	if (root != NULL) {
		if (data == root->data) {
			return 0;
		} else if (data <= root->data) {
			return (1 + get_level(root->left, data));
		} else {
			return (1 + get_level(root->right, data));
		}
	}
	return -999999999;
}

// print all leaf nodes
void print_leaf(node *root)
{
	if (root != NULL) {
		if (root->left == NULL && root->right == NULL) {
			cout << root->data << " ";
		} else {
			if (root->left) {
				print_leaf(root->left);
			}
	
			if (root->right) {
				print_leaf(root->right);
			}
		}
	}
}

// count number of leaf nodes
int no_of_leaf(node *root)
{
	int count = 0;
	if (root != NULL) {
		if (root->left == NULL && root->right == NULL) {
			return 1;
		}

		if (root->left) {
			count += no_of_leaf(root->left);
		}

		if (root->right) {
			count += no_of_leaf(root->right);
		}
	}

	return count;
}

// get sum of key values of leaf node
int sum_of_leaf(node *root)
{
	int count = 0;
	if (root != NULL) {
		if (root->left == NULL && root->right == NULL) {
			return root->data;
		} 

		if (root->left != NULL) {
			count += sum_of_leaf(root->left);
		}

		if (root->right != NULL) {
			count += sum_of_leaf(root->right);
		}
	}

	return count;
}

// delete node with given key value
node* del(node *root, int data)
{
	if (root == NULL) {
		return root;
	} else if (data < root->data) {
		root->left = del(root->left, data);
		if (root->left) {
			root->left->top = root;
		}
		return root;
	} else if (data > root->data) {
		root->right = del(root->right, data);
		if (root->right) {
			root->right->top = root;
		}
		return root;
	} else {
		node *p, *q;
		if (root->left == NULL && root->right == NULL) {
			free(root);
			return NULL;
		} else if (root->left == NULL) {
			p = root->right;
			free(root);
			return p;
		} else if (root->right == NULL) {
			p = root->left;
			free(root);
			return p;
		} else {
			p = successor(root, data);
			root->data = p->data;
			root->right = del(root->right, p->data);
			return root;
		}
	}
}

// find successor of a key
node* successor(node *root, int data)
{
	node *p = search(root, data);

	if (p != NULL) {
		if (p->right == NULL) {
			while (p->top != NULL && p->top->right == p) {
				p = p->top;
			}
			p = p->top;
		} else {
			p = p->right;
			while (p->left != NULL) {
				p = p->left;
			}
		}
	}

	return p;
}

// find predecessor of a key
node* predecessor(node *root, int data)
{
	node *p = search(root, data);

	if (p != NULL) {
		if (p->left == NULL) {
			while (p->top != NULL && p->top->left == p) {
				p = p->top;
			}
			p = p->top;
		} else {
			p = p->left;
			while (p->right != NULL) {
				p = p->right;
			}
		}
	}

	return p;
}

// to delete the whole tree
node* delete_tree(node *root)
{
	if (root != NULL) {
		if (root->left) root->left = delete_tree(root->left);
		if (root->right) root->right = delete_tree(root->right);
		cout << root->data << " ";
		free(root);
		return NULL;
	}
}

// to compare two bst for equality
bool comp(node *root1, node *root2)
{
	if (root1 == NULL && root2 == NULL) {
		return true;
	} else if (root1 != NULL && root2 != NULL) {
		return (
			root1->data == root2->data 
			&& comp(root1->left, root2->left) 
			&& comp(root1->right, root2->right)
		);
	} else {
		return false;
	}
}

// to swap two given nodes of bst
node* swap(node *root, node *p, node *q)
{
	if (root == NULL || p == NULL || q == NULL) {
		return root;
	} else {
		node *r = create_node(ERROR);
		r->top = p->top;
		r->left = p->left;
		r->right = p->right;
		if (r->top && r->top->left == p) {
			r->top->left = r;
		} else if (r->top) {
			r->top->right = r;
		}
		if (r->left) r->left->top = r;
		if (r->right) r->right->top = r;

		p->top = q->top;
		p->left = q->left;
		p->right = q->right;
		if (p->top && p->top->left == q) {
			p->top->left = p;
		} else if (p->top) {
			p->top->right = p;
		}
		if (p->left) p->left->top = p;
		if (p->right) p->right->top = p;

		q->top = r->top;
		q->left = r->left;
		q->right = r->right;
		if (q->top && q->top->left == r) {
			q->top->left = q;
		} else if (q->top) {
			q->top->right = q;
		}
		if (q->left) q->left->top = q;
		if (q->right) q->right->top = q;		

		if (root == p) {
			return q;
		} else {
			return root;
		}
	}
}

// new path is a problem in which we have to print path of 
// between smallest even and largest even number in tree
void new_path(node *root)
{
	int arr1[SIZE], arr2[SIZE], i, x, j;
	i = 0;
	node *p = root;
	x = even_left(root);

	while (p != NULL) {
		if (x == p->data) {
			arr1[i++] = p->data;
			break;
		} else if (x < p->data) {
			arr1[i++] = p->data;
			p = p->left;
		} else {
			arr1[i++] = p->data;
			p = p->right;
		}
	}

	x = even_right(root);
	p = root;
	j = 0;
	while (p != NULL) {
		if (x == p->data) {
			if (p != root) arr2[j++] = p->data;
			break;
		} else if (x < p->data) {
			if (p != root) arr2[j++] = p->data;
			p = p->left;
		} else {
			if (p != root) arr2[j++] = p->data;
			p = p->right;
		}
	}

	i--;
	for (; i >= 0; --i) {
		cout << arr1[i] << " ";
	}
	for (i = 0; i < j; ++i) {
		cout << arr2[i] << " ";
	}
	cout << endl;
}

//to get least even number in left sub tree
int even_left(node *root)
{
	node *p = minimum(root);
	while ((p->data % 2) == 1) {
		p = successor(root, p->data);
	}
	return p->data; 
}

// to get the greatest number in right sub tree
int even_right(node *root)
{
	node *p = maximum(root);
	while ((p->data % 2) == 1) {
		p = predecessor(root, p->data);
	}
	return p->data;
}

// for finding current largest data
int kth_largest_data(node *root, int k)
{
	// calc the total no of nodes
	int sz = size(root);

	// if it is more than number of nodes simply return -1
	if (k > sz) {
		return -1;
	} else {
		int count = sz - k + 1, ans;
		calc_pre(root, &count, &ans);
		return ans;
	}
}

// to return cth node from front in preorder
void calc_pre(node *root, int *c, int *ans)
{
	if (root != NULL && (*c != 0)) {
		calc_pre(root->left, c, ans);
		*c = *c - 1; // decrease as we trace a node
		if (*c == 0) {
			*ans = root->data;
			return;
		}
		calc_pre(root->right, c, ans);
	}
}

// to get the closest leaf
int closest_leaf(node *root)
{
	if (root != NULL) {
		node *leaf[100];
		int i = 0, dist[100], index = 0, j;
		get_all_leaf(root, leaf, dist, &i, 0);
		for (j = 1; j < i; ++j) {
			if (dist[j] < dist[index]) {
				index = j;
			}
		}
		return leaf[index]->data;
	} else {
		return ERROR;
	}
}

// store all leaf nodes and their distance
void get_all_leaf(node *root, node *leaf[], int dist[], int *i, int d)
{
	if (root != NULL) {
		if (root->left == NULL && root->right == NULL) {
			leaf[*i] = root;
			dist[(*i)++] = d + 1;
		} else if (root->left == NULL) {
			get_all_leaf(root->right, leaf, dist, i, d + 1);
		} else if (root->right == NULL) {
			get_all_leaf(root->left, leaf, dist, i, d + 1);
		} else {
			get_all_leaf(root->left, leaf, dist, i, d + 1);
			get_all_leaf(root->right, leaf, dist, i, d + 1);
		}
	}
}

// to generate mirror of a given tree
node* mirror(node *root)
{
	if (root != NULL) {
		node *tmp = create_node(root->data);
		tmp->left = mirror(root->right);
		if (tmp->left) tmp->left->top = tmp;
		tmp->right = mirror(root->left);
		if (tmp->right) tmp->right->top = tmp;
		return tmp;
	}
}

// to print all nodes at dist k
void print_at_dist_k(node *root, int k, int i)
{
	if (root != NULL) {
		if (i == k) {
			cout << root->data << " ";
		} else {
			print_at_dist_k(root->left, k, i+1);
			print_at_dist_k(root->right, k, i+1);
		}
	}
}

// to print ansestors of given node
void print_ansestors(node *root, int data, int *i)
{
	if (root != NULL) {
		if (data == root->data) {
			*i = 1;
		} else if (data < root->data) {
			print_ansestors(root->left, data, i);
			if (*i == 1) {
				cout << root->data << " ";
			}
		} else if (data > root->data) {
			print_ansestors(root->right, data, i);
			if (*i == 1) {
				cout << root->data << " ";
			}
		}
	}
}

// to create a bst from given pre and in order
node* pre_in(int pre[], int sp, int ep, int in[], int si, int ei)
{
	int i, j;
	node *tmp = create_node(pre[sp]);

	for (i = si; in[i] != pre[sp]; ++i);

	if (i > si && i < ei) {
		for (j = sp; pre[j] != in[i-1]; ++j);

		tmp->left = pre_in(pre, sp+1, j, in, si, i-1);
		tmp->right = pre_in(pre, j+1, ep, in, i+1, ei);

		tmp->left->top = tmp;
		tmp->right->top = tmp;
	} else if (i > si) {
		tmp->left = pre_in(pre, sp+1, ep, in, si, i-1);

		tmp->left->top = tmp;
	} else if (i < ei) {
		tmp->right = pre_in(pre, sp+1, ep, in, i+1, ei);

		tmp->right->top = tmp;
	}

	return tmp;
}

// to create a bst from fiven post and in order
node* post_in(int post[], int sp, int ep, int in[], int si, int ei)
{
	int i, j;
	node *tmp = create_node(post[ep]);

	for (i = si; in[i] != post[ep]; ++i);

	if (i > si && i < ei) {
		for (j = sp; post[j] != in[i+1];  ++j);

		tmp->left = post_in(post, sp, j-1, in, si, i-1);
		tmp->right = post_in(post, j, ep-1, in, i+1, ei);

		tmp->left->top = tmp;
		tmp->right->top = tmp;
	} else if (i > si) {
		tmp->left = post_in(post, sp, ep-1, in, si, i-1);

		tmp->left->top = tmp;
	} else if (i < ei) {
		tmp->right = post_in(post, sp, ep-1, in, i+1, ei);

		tmp->right->top = tmp;
	}

	return tmp;
}

// to delete all the leaf nodes of given bst
node* delete_leaf(node *root)
{
	if (root != NULL) {
		if (root->left == NULL && root->right == NULL) {
			free(root);
			return NULL;
		} else {
			root->left = delete_leaf(root->left);
			root->right = delete_leaf(root->right);
		}
	}

	return root;
}

// to delete a bst by repeatdly deleting root node
node* delete_by_root(node *root)
{
	inorder(root);
	cout << endl;
	while (root != NULL) {
		root = del(root, root->data);
		inorder(root);
		cout << endl;
	}

	return root;
}

// check whether a given tree is bst or not
bool check_bst(node *root, int min, int max)
{
	if (root != NULL) {
		if (root->data >= min && root->data <= max && 
			check_bst(root->left, min, root->data) && check_bst(root->right, root->data, max)) {
			return true;
		} else {
			return false;
		}
	} else {
		return true;
	}
}

// to check a given tree is sum tree or not
bool check_sum_tree(node *root)
{
	bool z;
	if (root == NULL) {
		return true;
	}  else {
		z = check_sum_tree(root->left) && check_sum_tree(root->right);
	}

	if (z == false) {
		return false;
	}

	if (root->left == NULL && root->right == NULL) {
		return true;
	} else {
		int x, y;
		if (root->left == NULL) {
			x = 0;
		} else if (root->left->left == NULL && root->left->right == NULL) {
			x = root->left->data;
		} else {
			x = 2 * root->left->data;
		}

		if (root->right == NULL) {
			y = 0;
		} else if (root->right->left == NULL && root->right->right == NULL) {
			y = root->right->data;
		} else {
			y = root->right->data * 2;
		}

		if (root->data == x + y) {
			return true;
		} else {
			return false;
		}
	}
}

// to find the distance between given two keys
// provided the keys are unique
int find_dist(node *root, int x, int y)
{
	node *p, *q, *r;
	if (x < y) {
		p = search(root, x);
		q = search(root, y);
	} else {
		p = search(root, y);
		q = search(root, x);
	}

	if (p == NULL || q == NULL) {
		return ERROR;
	} else {
		r = root;
		while (1) {
			if (p->data < r->data && q->data < r->data) {
				r = r->left;
			} else if (p->data > r->data && q->data > r->data) {
				r = r->right;
			} else {
				break;
			}
		}

		int a, b, c;
		a = depth(root, p);
		b = depth(root, q);
		c = depth(root, r);

		return (a + b - c - c);
	}
}

// to find the depth of a given node
// provided the keys are unique
int depth(node *root, node *x)
{
	if (root == x) {
		return 0;
	} else if (x->data < root->data) {
		return (1 + depth(root->left, x));
	} else {
		return (1 + depth(root->right, x));
	}
}

// get depth and height of all node 
int print_all(node *root, int i)
{
	if (root != NULL) {
		if (root->left == NULL && root->right == NULL) {
			cout << "depth " << i << " height 0 data " << root->data << endl;
			return 0;
		} else {
			int a = max(print_all(root->left, i + 1), print_all(root->right, i + 1)) + 1;
			cout << "depth " << i << " height " << a << " data " << root->data << endl;
			return a;
		}
	} else {
		return -1;
	}
}

// delete duplicate values in tree
void delete_duplicate(node *root)
{
	if (root != NULL) {
		while (search(root->left, root->data)) {
			root->left = del(root->left, root->data);
		} 
		delete_duplicate(root->left);
		delete_duplicate(root->right);
	}
}

// to find the common ansestor
node* common_ansestor(node *root, int a, int b)
{
	if (root == NULL) return root;
	if (a < root->data && b < root->data) {
		return common_ansestor(root->left, a, b);
	} else if (a > root->data && b > root->data) {
		return common_ansestor(root->right, a, b);
	} else {
		return root;
	}
}

// create a bst from given pre order and post order ( full bst )
node* pre_post(int pre[], int s1, int e1, int post[], int s2, int e2)
{
	int i, j;
	node *tmp = create_node(pre[s1]);
	for (i = s1; pre[i] != post[e2-1]; ++i);

	if (i > s1 && i <= e1) {
		for (j = s2; post[j] != pre[s1+1]; ++j);
		tmp->left = pre_post(pre, s1+1, i-1, post, s2, j);
		if (tmp->left) tmp->left->top = tmp;
		tmp->right = pre_post(pre, i, e1, post, j+1, e2-1);
		if (tmp->right) tmp->right->top = tmp;
	}

	return tmp;
}
