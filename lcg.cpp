#include<bits/stdc++.h>
using namespace std;

int length,i,flag;
int X[100005],O[12];
double R[100005];

/*Declare variable globally for easy uses purpose
Here,
length = length of cycle/number of random value generated
X[] = Xi
O[] = to store the number of observe value in every class
as i use 10 class so i declare a array with size 12
R[] = Array of random variable*/

void LCG(int a, int c, int m)
{
    i = 1;
    flag = 0;
    length = 0;
    R[0] = double(X[0]) / m;     /// Calculate first Random variable.
    cout << R[0] << endl;

    while(flag == 0)
    {
        X[i] = (a*X[i-1] + c)% m;
        length++;
        for(int j=0;j<i;j++)
        {
            if(X[i] == X[j])        /// Check that the generation of repetition number.
                flag = 1;
        }
        if(flag == 0)
        {
            R[i] = double(X[i])/m;     /// Convert Xi into Ri.
            cout << R[i] << endl;
        }

        i++;

    }
    cout << endl <<  "Cycle length is : " << length << endl << endl;
}

void chiSquareTest(int m)
{
    float chi = 16.5;
    for(i=1;i<=10;i++)
        O[i] = 0;

    for(i=0;i<length; i++)      /// Count how many random number is generate in every class. And i assume that there is 10 class
    {
        if(R[i] >= 0.0 && R[i] <= 0.1)
            O[1] += 1;
        else if(R[i]>0.1 && R[i] <= 0.2)
            O[2]+= 1;
        else if(R[i] > 0.2 && R[i] <= 0.3)
            O[3] += 1;
        else if(R[i] > 0.3 && R[i] <= 0.4)
            O[4] += 1;
        else if(R[i] > 0.4 && R[i] <= 0.5)
            O[5] += 1;
        else if(R[i] > 0.5 && R[i] <= 0.6)
            O[6] += 1;
        else if(R[i] > 0.6 && R[i] <= 0.7)
            O[7] += 1;
        else if(R[i] > 0.7 && R[i] <= 0.8)
            O[8] += 1;
        else if(R[i] > 0.8 && R[i] <= 0.9)
            O[9] += 1;
        else
            O[10] += 1;

    }
    for(i=1;i<=10;i++)
    {
        cout << "Total Random Number in Class " << i << " : " << O[i] << endl;
    }
    double x0 = 0.0;
    int ei = m/10;

    for(i=1;i<=10;i++)
    {
        x0 = x0 + pow((O[i] - ei),2)/ ei;          /// Calculate total chi square value.
    }
    cout << "Total value of Chi-Square Test : " << x0 << endl << endl;

    if(x0 < chi)
        cout << "This method is satisfied uniformity test." << endl;
    else
        cout << "This method is not satisfied uniformity test." << endl;

}


int main()
{
    int a, m,c;
    cout << "Enter the value of a : ";
    cin >> a;
    cout << "Enter the value of c : ";
    cin >> c;
    cout << "Enter the value of m : ";
    cin >> m;
    cout << "Enter the value of X0 : ";
    cin >> X[0];

    LCG(a,c,m);

    chiSquareTest(m);


    return 0;
}
