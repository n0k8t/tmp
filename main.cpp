#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool check(string const & a, string const & b){
    fstream f(a, fstream::in);
    string b1;
    while (!f.eof()){
        getline(f, b1);
        if ( b == b1 ) return false;
    }
    return true;
}
void print(string const & a, string const & b){
    fstream f1(a, fstream::in), f2(b, fstream::in);
    string str;
    int n = 1;
    while (!f1.eof()){
        getline(f1, str);
        if(check(b, str))
            cout << a << " " << str << " " << n << endl;
        n++;
    }
}

int main()
{
    string fn1 = "someFile";
    string fn2 = "someOtherFile";

    print(fn1, fn2);
    print (fn2, fn1);

    system ("pause");
    return 0;
}