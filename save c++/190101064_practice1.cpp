#include <iostream>
using namespace std;

class ArrayADT1
{
    public:
        ArrayADT1();
        ArrayADT1(int );
        virtual ~ArrayADT1();
        bool setElement(int, int);
        int getElement(int);

    private:
        int* elements;
        int capacity;
};
    ArrayADT1::ArrayADT1(){
        capacity=0;
    }


    ArrayADT1::ArrayADT1(int arraySize){
        elements=new int[arraySize];
        capacity=arraySize;
    }

    bool ArrayADT1::setElement(int index, int val){
        elements[index]= val;
        return(true);
    }

    int ArrayADT1::getElement(int index){
        return(elements[index]);
    }


    ArrayADT1::~ArrayADT1(){
        delete[] elements;
    }

int main()
{

    ArrayADT1 a(5);

    for(int i=0; i<5; i++){
        a.setElement(i, i*100);
        cout<<"Index value, "<<i<<" is "<<a.getElement(i)<<endl;
    }
    return 0;
}

