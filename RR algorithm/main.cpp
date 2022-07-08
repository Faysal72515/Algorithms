#include <iostream>

using namespace std;
                            // -> Operating System Lab
int main()
{
    cout << "************ Round Robin Scheduling Algorithm in cpp ************** " << endl;
    cout << " =================== Faysal Sarder ==============\n";
    cout << " --------------- CSE 3rd year Student------------ "<<endl;
    int i,n, j, q_t, count=0, temp, ex=0, p[100], at[100], bt[100], rem_bt[100], tat[100], wt[100];
    float atat=0, awt=0;
    // ---------------------------------input part----------------
    cout<<" Enter process number : ";
    cin>> n;

    cout<< " Enter process sequence :";
    for(i=0; i<n;i++){
        cin>> p[i];
    }

    cout<< " Enter Arrival time:";
    for(i=0; i<n;i++){
        cin>> at[i];
    }

    cout<< " Enter the Burst time:";
    for(i=0; i<n;i++){
        cin>> bt[i];
        rem_bt[i] = bt[i];
    }

    cout<< "Enter quantum time :";
    cin>> q_t;

    for(i=0; i<n;i++){

        for(j=i+1; j<n ; j++){

            if(at[i] > at[j]){

                temp= bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp= rem_bt[i];
                rem_bt[i] = rem_bt[j];
                rem_bt[j] = temp;

                temp= p[i];
                p[i] = p[j];
                p[j] = temp;

                temp= at[i];
                at[i] = at[j];
                at[j] = temp;

            }
        }
    }

  while (true){                 // for(;;){}

    for(i=0, count=0;i<n;i++){

        temp = q_t;
        if(rem_bt[i] == 0){
            count++;
            continue;
        }

        if (rem_bt[i] > q_t){
            rem_bt[i] = rem_bt[i] - q_t;
        }
        else
        if (rem_bt[i] >= 0){
            temp= rem_bt[i];
            rem_bt[i]=0;
        }
        ex+= temp;
        tat[i] = ex- at[i];
    }
    if (n == count)
        break;

  }

    cout<< "\n process\t   arrival time\t  burst time\t turn around time\t waiting time "<<endl;
    for (i=0; i<n ;i++){
        atat += tat[i];
        wt[i]=tat[i] - bt[i];
        awt += wt[i];
        cout<< "P["<< p[i] <<"]\t\t" << at[i]<<"\t\t"<< bt[i] <<"\t\t"<<tat[i] <<"\t\t"<<wt[i]<<endl;
    }

    atat = atat/n;
    awt = awt/n;

    cout<< "\n Average Turn around time: "<< atat <<endl;
    cout<< "\n Average waiting time: "<< awt <<endl;
    return 0;


}
