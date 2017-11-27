#include <fstream>

using namespace std;

ifstream fin("confuse.in");
ofstream fout("confuse.out");

int main()
{
    long long n;
    fin>>n;
    n%=998244353;
    n=n*n;
    n%=998244353;
    fout<<n<<endl;
    return 0;
}
