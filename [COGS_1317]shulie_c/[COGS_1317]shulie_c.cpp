#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
//#define DEBUG

/*
seg_tree :: calculate the sum number
*/

using namespace std;

const int INF = 0;

class Seg_tree_node;
typedef Seg_tree_node *seg_pointer;

class Seg_tree_node
{
  public:
    long long val;
    int left, right;
    bool is_leaf;
    seg_pointer lchild, rchild;
    long long lazy;

    Seg_tree_node() { lazy = 0; } //default constractor
    void create(long long arr[], int left, int right);
    long long query(int l, int r);
    void push_down();
    void wide_modify(int l, int r, long long v);
};

inline long long mselect(const long long a, const long long b)
{
    return a + b;
}

void Seg_tree_node::create(long long arr[], int l, int r)
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

long long Seg_tree_node::query(int ql, int qr)
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
        lchild->val += lazy * (lchild->right - lchild->left + 1); //if the seg_tree type isn't the same,then change this part
        rchild->val += lazy * (rchild->right - rchild->left + 1); //if the seg_tree type isn't the same,then change this part
        lchild->lazy += lazy;
        rchild->lazy += lazy;
    }
    lazy = 0;
}

void Seg_tree_node::wide_modify(int l, int r, long long v)
{
    if (right < l || left > r)
    {
        return;
    }
    if (l <= left && right <= r)
    {
        val += v * (right - left + 1); //if the seg_tree type isn't the same,then change this part
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

const int maxn = 100001;
long long A[maxn];

int main()
{
    freopen("shuliec.in", "r", stdin);
    freopen("shuliec.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> A[i];
    }
    Seg_tree_node root;
    root.create(A, 1, n);
    string mcmd;
    int m;
    cin >> m;
    int s, t, d;
    for (int i = 1; i <= m; ++i)
    {
        cin >> mcmd;
        if (mcmd == "ADD")
        {
            cin >> s >> t >> d;
            root.wide_modify(s, t, d);
        }
        else
        {
            cin >> s >> t;
            cout << root.query(s, t);
        }
    }
    return 0;
}
