#include <iostream>
#include <cstdio>
#include <algorithm>
#define DEBUG

/*
seg_tree :: calculate the min number
*/

using namespace std;

const int INF = 20000000;

class Seg_tree_node;
typedef Seg_tree_node * seg_pointer;

class Seg_tree_node
{
  public:
	int val;
	int left, right;
	bool is_leaf;
	seg_pointer lchild, rchild;
	int lazy;

	Seg_tree_node() { lazy = 0; } //default constractor
	void create(int arr[], int left, int right);
	int query(int l, int r);
	void push_down();
	void wide_modify(int l, int r, int val);
};

inline int mselect(const int a, const int b)
{
	return min(a, b);
}

void Seg_tree_node::create(int arr[], int l, int r)
{
	if (l == r) //leaf node
	{
		val = arr[l];
		left = right = l;
		is_leaf = true;
		lchild = rchild = NULL;
		return;
	}
	else
	{
		left = l;
		right = r;
		int m = (left + right) / 2;
		is_leaf = false;
		lchild = new Seg_tree_node;
		rchild = new Seg_tree_node;
		lchild->create(arr, left, m);
		rchild->create(arr, m + 1, right);
		val = mselect(lchild->val, rchild->val);
	}
}

int Seg_tree_node::query(int ql, int qr)
{
	if (qr < left || ql > right)
	{
		return INF;
	}

	if (lazy != 0)
	{
		push_down();
	}
	if (ql <= left && right <= qr)
	{
		return val;
	}
	int m = (ql + qr) / 2;
	return mselect(lchild->query(ql, qr), rchild->query(ql, qr));
}

void Seg_tree_node::push_down()
{
#ifdef DEBUG
	if (lazy == 0)
	{
		cout << "err push down:lazy_tag is 0" << endl;
		return;
	}
#endif // DEBUG

	if (!is_leaf)
	{
		lchild->val += lazy;
		rchild->val += lazy;
		lchild->lazy += lazy;
		rchild->lazy += lazy;
	}
	lazy = 0;
}

void Seg_tree_node::wide_modify(int l, int r, int v)
{
	if (right < l || left > r)
	{
		return;
	}
	if (l <= left && right <= r)
	{
		val += v; //if the seg_tree type isn't the same,then change this part
		lazy += v;
		return;
	}
	if (!is_leaf)
	{
		if (lazy != 0)
		{
			push_down();
		}
		lchild->wide_modify(l, r, v);
		rchild->wide_modify(l, r, v);
		val = mselect(lchild->val, rchild->val);
	}
}

int main()
{
	int arr[6] = {2, 5, 1, 4, 9, 3};
	Seg_tree_node root;
	root.create(arr, 0, 5);
	cout << "query1:" << endl;
	cout << root.query(0, 5) << endl;

	cout << "modify:" << endl;
	root.wide_modify(0, 5, 100);
	cout << "query2:" << endl;
	cout << root.query(0, 5) << endl;
	return 0;
}
