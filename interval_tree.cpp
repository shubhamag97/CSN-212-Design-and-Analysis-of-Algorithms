#include <bits/stdc++.h>
using namespace std;

struct interval
{
	int low, high;
};


struct node
{
	interval *a; 
	int max;
	node *left, *right;
};
node *newNode(interval a)
{
	node *temp = new node;
	temp->a = new interval(a);
	temp->max = a.high;
	temp->left = temp->right = NULL;
};

node *insert(node *root, interval a)
{
	if (root == NULL)
		return newNode(a);

	int l = root->a->low;

	if (a.low < l)
		root->left = insert(root->left, a);

	else
		root->right = insert(root->right, a);

	if (root->max < a.high)
		root->max = a.high;

	return root;
}

bool overlap(interval a1, interval a2)
{
	if (a1.low <= a2.high && a2.low <= a1.high)
		return true;
	return false;
}

interval *overlapSearch(node *root, interval a)
{
	if (root == NULL) return NULL;

	if (overlap(*(root->a), a))
		return root->a;

	if (root->left != NULL && root->left->max >= a.low)
		return overlapSearch(root->left, a);

	return overlapSearch(root->right, a);
}

void inorder(node *root)
{
	if (root == NULL) return;

	inorder(root->left);

	cout << "[" << root->a->low << ", " << root->a->high << "]"
		<< " max = " << root->max << endl;

	inorder(root->right);
}

struct node * minValueNode(struct node* node)
{
    struct node* current = node;
 
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
// Assuming max is non-repeating.
struct node *deleteNode(struct node *root, int max)
{

    if (root == NULL) return root;
 
    if (max < root->max)
        root->left = deleteNode(root->left, max);
 
    else if (max > root->max)
        root->right = deleteNode(root->right, max);
 
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
 
        struct node *temp = minValueNode(root->right);
 
        root->max = temp->max;
 
        root->right = deleteNode(root->right, temp->max);
    }
    return root;
}

int main()
{
	interval ints[] = {{15, 20}, {10, 30}, {17, 19},
		{5, 20}, {12, 15}, {30, 40}
	};
	int n = sizeof(ints)/sizeof(ints[0]);
	node *root = NULL;
	for (int i = 0; i < n; i++)
		root = insert(root, ints[i]);



	interval x = {14, 16}, y= {21, 23};

	cout << "\nSearching for interval [" << x.low << "," << x.high << "]";
	interval *res = overlapSearch(root, x);
	if (res == NULL)
		cout << "\nno overlap";
	else
		cout << "\noverlap with [" << res->low << ", " << res->high << "]";
	cout << "\nSearching for interval [" << y.low << "," << y.high << "]";
	res = overlapSearch(root, y);
	if (res == NULL)
		cout << "\nno overlap";
	else
		cout << "\noverlap with [" << res->low << ", " << res->high << "]";
	return 0;
}
