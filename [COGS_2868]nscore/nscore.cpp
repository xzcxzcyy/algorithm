#include <fstream>

using namespace std;

ifstream fin("nscore.in");
ofstream fout("nscore.out");

int main()
{
    int a,b,c;
    fin>>a>>b>>c;
    fout<<a*0.2+b*0.3+c*0.5;
    return 0;
}
