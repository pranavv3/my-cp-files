#include <iostream>
#include "../pranav1/StackX.h
using namespace std;


int main()
{
    stackX s1(5);
    for (int count=10; count<20; count++) {
        s1.push(count);
    }
    for (int count=10; count<20; count++) {
        if (!s1.isEmpty()) {
            cout<<"Popped "<<s1.pop()<<"from stack"<<endl;
        }

    }
    return 0;
}

