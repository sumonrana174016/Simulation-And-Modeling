#include<bits/stdc++.h>
using namespace std;
int main()
{
    int work_time[100],i,start_time,finish_time,cumulative_time=0,flag;
    int N;
    cout << "Enter number of job : ";
    cin >> N;
    for(i=0;i<N;i++)
    {
        cout << "Enter work_time for job " << i+1 << " : ";
        cin >> work_time[i];

    }

    cout << "Document No\t" << "Start Time\t" << "Work Time\t" << "Finish Time\t";
    cout << "Cumulative Time\t" << "Break Flag\t" << "No of Job Rem." << endl;

    start_time = 0;

    for(i=0;i<N;i++)
    {
        flag = 0;
        finish_time = start_time + work_time[i];
        cumulative_time += work_time[i];

        if(cumulative_time>=60)
            flag = 1;

        cout << "\t" << i+1 << "\t\t" << start_time << "\t\t" << work_time[i] << "\t\t";
        cout << finish_time << "\t\t" << cumulative_time << "\t\t" << flag << "\t\t" << N-(i+1) << endl;

        start_time = finish_time;
        if(flag == 1)
        {
            cumulative_time = 0;
            start_time += 5;
        }
    }

    return 0;
}
