#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

class Seg_tree_node;
typedef Seg_tree_node * seg_pointer;

class Seg_tree_node
{
  public:
    int val;
    int left, right;
    bool is_leaf;
    seg_pointer lchild, rchild;

    void create(int arr[], int left, int right);
};

inline int mselect(const Seg_tree_node *a, const Seg_tree_node *b)
{
    return min(a->val, b->val);
}

void Seg_tree_node::create(int arr[], int l, int r)
{
    if (l == r)//leaf node
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
		val = mselect(lchild, rchild);
	}
}

int main()
{
	int arr[7] = { 0,1, 2, 3, 4, 5, 6 };
    Seg_tree_node root;
    root.create(arr,0,6);
    cout<<"done"<<endl;
    return 0;
}
