#include <iostream>
#include <cstdio>
#include <algorithm>

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

    void create(int arr[], int left, int right);
	int query(int l, int r);
};

inline int mselect(const int a, const int b)
{
	return min(a, b);
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
		val = mselect(lchild->val, rchild->val);
	}
}

int Seg_tree_node::query(int ql, int qr)
{
	if (qr<left || ql>right)
	{
		return INF;
	}
	if (ql<=left && right<=qr)
	{
		return val;
	}
	int m = (ql + qr) / 2;
	return mselect(lchild->query(ql, qr), rchild->query(ql, qr));
}

int main()
{
	int arr[6] = { 2, 5, 1, 4, 9, 3 };
    Seg_tree_node root;
    root.create(arr,0,5);
	cout << root.query(0, 2);
    cout<<"done"<<endl;
    return 0;
}


