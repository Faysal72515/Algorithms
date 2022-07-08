#include<iostream>

using namespace std;
int main()
{
      cout<< "----------------------> Shortest Job First Scheduling Algorithm <----------------------\n"<<endl
          << "Name: Faysal Sarder\n"
          << "\n"
          << "--------------------\n"<<endl;;
      int n,temp,tt=0,min,d,i,j;
      float avg_tat=0,avg_wt=0,t_tat=0,t_wt=0;
      cout<<"Enter number of processes: ";
      cin>>n;
      int p[n], a[n], b[n], c[n], tat[n], wt[n];
      cout<<"Enter the processes sequence: ";       //input
      for(i=0;i<n;i++)
      {
            cin>>p[i];
      }
      cout<<"Enter the arrival time: ";       //input
      for(i=0;i<n;i++)
      {
            cin>>a[i];
      }
      cout<<"Enter the brust time: ";      //input
      for(i=0;i<n;i++)
      {
            cin>>b[i];
      }
      for(i=0;i<n;i++)
      {
         for(j=i+1;j<n;j++)
          {
                if(b[i]>b[j])
                {
                      temp=p[i];
                      p[i]=p[j];
                      p[j]=temp;

                      temp=a[i];
                      a[i]=a[j];
                      a[j]=temp;

                      temp=b[i];
                      b[i]=b[j];
                      b[j]=temp;
                }
          }
      }
      min=a[0];
      for(i=0;i<n;i++)
      {
            if(min>a[i])
            {
                  min=a[i];
                  d=i;
            }
      }
      tt=min;
      c[d]=tt+b[d];
      tt=c[d];

      for(i=0;i<n;i++)
      {
            if(a[i]!=min)
            {
                  c[i]=b[i]+tt;
                  tt=c[i];
                 // cout<<"CT "<< tt<<endl;
            }
            //cout<<"CT "<< tt<<endl;
      }
      //cout<< tt<<endl;
      for(i=0;i<n;i++)
      {

            tat[i]=c[i]-a[i];
            t_tat=t_tat+tat[i];
            wt[i]=tat[i]-b[i];
            t_wt=t_wt+wt[i];
      }
     // cout<< t_tat<<endl;
     // cout<< t_wt<< endl;
      avg_tat=t_tat/n;
      avg_wt=t_wt/n;
      cout<<endl;
      cout<<"Process  Arrival-time(s)  Burst-time(s)  Waiting-time(s)  Turnaround-time(s)\n";

    for(i=0;i<n;i++)
    {
    cout<<"P"<<p[i]<<"              "<<a[i]<<"                "<<b[i]<<"                  "<<wt[i]<<"               "<<tat[i]<<endl;
    }
    cout<<endl;
    cout<<"Average Waiting Time: "<<avg_wt<<endl;
    cout<<"Average Turnaround Time: "<<avg_tat<<endl;  //average waiting time and turn around time
}
