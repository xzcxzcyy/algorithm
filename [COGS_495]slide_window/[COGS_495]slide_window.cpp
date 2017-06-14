#include <iostream>
#include <cstdio>
#include <algorithm>
//#define DEBUG

using namespace std;

const int INF_1 = 20000000;  //INF for min
const int INF_2 = -20000000; //INF for max

class Seg_tree_node;
typedef Seg_tree_node *seg_pointer;

class Seg_tree_node
{
  public:
    int val;
    int left, right;
    bool is_leaf;
    seg_pointer lchild, rchild;

    void create(int arr[], int left, int right, int (*mselect)(const int a, const int b));
    int query(int ql, int qr, int (*mselect)(const int a, const int b), const int INF);
};

int mselect_1(const int a, const int b)
{
    return min(a, b);
}
int mselect_2(const int a, const int b)
{
    return max(a, b);
}

void Seg_tree_node::create(int arr[], int l, int r, int (*mselect)(const int a, const int b))
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
        lchild->create(arr, left, m, mselect);
        rchild->create(arr, m + 1, right, mselect);
        val = mselect(lchild->val, rchild->val);
    }
}

int Seg_tree_node::query(int ql, int qr, int (*mselect)(const int a, const int b), const int INF)
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
    return mselect(lchild->query(ql, qr, mselect, INF), rchild->query(ql, qr, mselect, INF));
}

const int maxn = 1000001;
int arr[maxn];
int main()
{
#ifndef DEBUG
    freopen("window.in", "r", stdin);
    freopen("window.out", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }
    Seg_tree_node root1, root2;
    root1.create(arr, 1, n, mselect_1);
    root2.create(arr, 1, n, mselect_2);
    int l = 1, r = l + k - 1;
    for (; r <= n; ++l, ++r)
    {
        cout << root1.query(l, r, mselect_1, INF_1) << " ";
    }
    cout << endl;
    l = 1, r = l + k - 1;
    for (; r <= n; ++l, ++r)
    {
        cout << root2.query(l, r, mselect_2, INF_2) << " ";
    }
    cout << endl;
    return 0;
}
