#include<bits/stdc++.h>
using namespace std;
int length,flag,i;
int X[100005],O[12];
double R[100005];

void LCG(int a,int c,int m)
{
    i = 1;
    flag = 0;
    length = 0;

    R[0] = double(X[0])/m;

    cout<< R[0] << endl;

    while(flag == 0)
    {
        X[i] = (a*X[i-1] + c) % m;
        length++;
        for(int j=0; j<i; j++)
        {
            if(X[i] == X[j])
                flag=1;
        }
        if(flag==0)
        {
            R[i] = double(X[i])/m;
            cout<< R[i] << endl;
        }
        i++;
    }
    cout<<endl<<"Cycle Length is = "<<length<<endl << endl;
}

void chiSquareTest(int m)
{
    float chi_squre = 12.6;
    for(i = 1;i<=10;i++)
        O[i] = 0;
    for(i=0;i<length;i++)
    {
        if(R[i] >= 0.0 && R[i]<= 0.1)
            O[1] = O[1] + 1;
        else if(R[i]>0.1 && R[i] <= 0.2)
            O[2] = O[2] + 1;
        else if(R[i]>0.2 && R[i] <= 0.3)
            O[3] = O[3] + 1;
        else if(R[i]>0.3 && R[i] <= 0.4)
            O[4] = O[4] + 1;
        else if(R[i]>0.4 && R[i] <= 0.5)
            O[5] = O[5] + 1;
        else if(R[i]>0.5 && R[i] <= 0.6)
            O[6] = O[6] + 1;
        else if(R[i]>0.6 && R[i] <= 0.7)
            O[7] = O[7] + 1;
        else if(R[i]>0.7 && R[i] <= 0.8)
            O[8] = O[8] + 1;
        else if(R[i]>0.8 && R[i] <= 0.9)
            O[9] = O[9] + 1;
        else
            O[10] = O[10] + 1;

    }

    for(i=1;i<=10;i++)
        cout << "Class " << i << " : " << O[i] << endl;

    double X0 = 0.0;

    for(i=1;i<=10;i++)
    {
        int ei = m/10;
        X0 = X0 + pow((O[i] - ei),2) / ei;
    }

    cout << endl << "Total value of Chi_Square test, X0 = " << X0 << endl << endl;

    if(chi_squre >= X0)
    {
        cout << "This method is satisfied uniformity test." << endl;
    }
    else
     cout << "This method is not satisfied uniformity test." << endl;



}

int main()
{
    int n,a,c,m;

    cout << "Enter the value of a : ";
    cin >> a;
    cout << "Enter the value of c : ";
    cin >> c;
    cout << "Enter the value of m : ";
    cin >> m;
    cout << "Enter the value of X[0]: ";
    cin >> X[0];

    LCG(a,c,m);

    chiSquareTest(m);

    cout << endl << endl;


    return 0;
}
