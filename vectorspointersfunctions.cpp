#include <iostream>
#include <vector> 

using namespace std;


void display()
{
    cout<<"1. Scalar Product of two vectors\n";
    cout<<"2. Predicate Function to check elements and order\n";
    cout<<"3. Average Value of arry of floating point data\n";
    cout<<"4. Function that returns pointer to maximum value\n";
}


double scalar_product(vector<double> a, vector<double> b)
{
    double scalar = 0;
    for (int i = 0; i <= a.size()-1; i++)
    {
        scalar = scalar + (a[i])*(b[i]);
    }
    return scalar;
}

bool equals(vector<double> a, vector<double> b)
{
    bool facts = true;
    for (int i = 0; i <= a.size()-1; i++)
    {
        if(a[i]!=b[i])
        {
            facts=false;
        }
    }
    return facts;
}

double average(double* a, int a_size)
{
    double total = 0;
    for (int count = 0; count < a_size; count++)
    {
        total = total + *(a++);
    }
    total = total/a_size;
    return total;
}

double* maximum(double a[], int a_size)
{
    double* pointermax = a; 
    for(int i = 1; i < a_size; i++)
    {
        if(a[i] > *pointermax)
        {
            *pointermax = a[i];
        }
    }
    return pointermax;
}


int main()
{
    bool fact;
    int choice;
    const int size_a = 4;
    double number[] = {6,7,2,12};
    double* a = number;
    vector<double> aa = {3,5,9};
    vector<double> bb = {3,5,9};
    double scal;
    
    caseselect:
    cout<<"\nChoose the function you want to run!\n";
    display ();
    cin>>choice;
    switch(choice)
    {
        case 1:
        {
            cout<<"Here is vector 1: |";
            for(int x = 0; x<aa.size(); x++)
            {
                cout<<aa[x]<<"| ";
            }
            cout<<"\nHere is vector 2: |";
            for(int c = 0; c<bb.size(); c++)
            {
                cout<<bb[c]<<"| ";
            }
            scal = scalar_product(aa,bb);
            cout<<"\nScalar is "<<scal<<".\n";
            goto caseselect;
            break;
        }
        case 2:
        {
            cout<<"Here is vector 1: |";
            for(int x = 0; x<aa.size(); x++)
            {
                cout<<aa[x]<<"| ";
            }
            cout<<"\nHere is vector 2: |";
            for(int c = 0; c<bb.size(); c++)
            {
                cout<<bb[c]<<"| ";
            }
            fact= equals(aa,bb);
            if(fact == true)
            {
                cout<<"The vectors have same elements in same order.\n";
            }
            if(fact == false)
            {
                cout<<"The vectors do not have same elements in same order.\n";
            }
            goto caseselect;
            break;
        }
        case 3:
        {
            cout<<"\nThe numbers being averaged are: |";
            for(int e = 0; e<size_a; e++)
            {
                cout<<number[e]<<"| ";
            }
            cout<<"\nThe average of the numbers is "<<average(a,size_a)<<endl;
            goto caseselect;
            break;
        }
        case 4:
        {
            cout<<"\nThe list of numbers is: |";
            for(int z = 0; z<size_a; z++)
            {
                cout<<number[z]<<"| ";
            }
            double* max = maximum(number,size_a);
            cout<<"\nThe pointer to the number in the array with the highest value is: "<<*max<<" and its position is "<<max<<endl;
            goto caseselect;
            break;
        }
    }


    return 0;
}
