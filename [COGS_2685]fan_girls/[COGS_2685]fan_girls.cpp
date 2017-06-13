#include <iostream>
#include <cstdio>
#include <algorithm>
#define DEBUG

using namespace std;

const int INF = 0;

class Seg_tree_node;
typedef Seg_tree_node *seg_pointer;

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
    return a + b;
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
    if (ql <= left && right <= qr)
    {
        return val;
    }
    int m = (ql + qr) / 2;
    return mselect(lchild->query(ql, qr), rchild->query(ql, qr));
}

const int maxn = 100001;
int arr1[maxn];
int arr2[maxn];
int arr3[maxn];

int main()
{
    freopen("fans.in", "r", stdin);
    freopen("fans.out", "w", stdout);
    int n, Q;
    cin >> n >> Q;
    int temp;
    for (int i = 1; i <= n; ++i)
    {
        cin >> temp;
        if (temp == 1)
        {
            ++arr1[i];
        }
        if (temp == 2)
        {
            ++arr2[i];
        }
        if (temp == 3)
        {
            ++arr3[i];
        }
    }
    Seg_tree_node root1, root2, root3;
    root1.create(arr1, 1, n);
    root2.create(arr2, 1, n);
    root3.create(arr3, 1, n);
    int l, r;
    for (int i = 1; i <= Q; ++i)
    {
        cin >> l >> r;
        cout << root1.query(l, r) << " ";
        cout << root2.query(l, r) << " ";
        cout << root3.query(l, r) << " ";
    }
    return 0;
}
