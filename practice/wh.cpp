#include <iostream>
using namespace std;
int main()
{
    int num=1000;
    int * ptr;
    ptr= & num;
    cout<<*ptr+5;
}