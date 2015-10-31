#include <iostream>
#include <cmath>
#include <fstream>
const int MAX=100;
char desceme (char[]);
using namespace std;
int main()
{
    char ch[MAX], newCh[MAX];
    bool flag=true;
    int i;
    ofstream inputs("berg.in");
    cin >> ch;
    inputs << ch;
    inputs.close();
    ifstream fin("berg.in");
    fin >> newCh;
    fin.close();
    while ((!fin.eof()) && (flag=true))
    {
        if (isspace(newCh[i]))
            flag=false;
        if (islower(newCh[i]))
            flag=false;
        if (!((newCh[i]=='a') && (i/2=0)))
            flag=false;
        i++;
    }
    ofstream fout("berg.out");
    if (flag==false)
        fout << "Suspicious!";
    else
        fout << newCh;
    fout.close();
    return 0;
}