#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
int main()
{
    int str,i,number;
    bool flag;
    //cin >> str;
    ofstream inputs("abt.in");
    cin >> number;
    inputs << number;
    inputs.close();
    ifstream fin("abt.in");
    fin >> str;
    fin.close();
    flag=false;
    i=0;
    while ((flag==false)&&(i<=str))
    {
        if (i*(i+1)==str)
        {
            flag=true;
            break;
        }
        i+=1;
    }
    ofstream fout("abt.out");
    if (flag==true)
        fout << i << " " << i+1;
    else
        fout << "-1" << " " << "-1";
    fout.close();
    return 0;
}
