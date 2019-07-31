#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

const int MAX = 1000;

/*
    线性表，整型数据，递增排列
*/

class LList
{
  private:
    int *data;
    int last;
    int Lmax;

  public:
    LList(int maxnum);
    LList();
    void EditSize(int maxnum);
    int FindElementByPosition(int pos);
    int FindPositionByValue(int value);
    int operator[](int pos);
    void Insert(int value); ///插入元素value到适当位置
    void Delete(int pos);
    int GetLength();
};

LList::LList(int maxnum) ///create an empty Linear List
{
    data = new int[maxnum];
    last = -1;
    Lmax = maxnum;
}

LList::LList()
{
    data = new int[MAX];
    last = -1;
    Lmax = MAX;
}

void LList::EditSize(int maxnum)
{
    if (maxnum == Lmax)
        return;
    if (last == -1)
    {
        int *p = new int[maxnum];
        delete[] data;
        data = p;
        Lmax = maxnum;
        return;
    }
    else
    {
        int end = min(last, (maxnum - 1));
        int *p = new int[maxnum];
        for (int i = 0; i <= end; ++i)
        {
            p[i] = data[i];
        }
        delete[] data;
        data = p;
    }
}

int LList::FindElementByPosition(int pos)
{
    return data[pos];
}

int LList::FindPositionByValue(int value)
{
    
}

int main()
{
    return 0;
}