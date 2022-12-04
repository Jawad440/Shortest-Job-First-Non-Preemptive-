#include<iostream>
using namespace std;

/*  tt = Total Time.
    min = minimum
    atat = Average Turn Around Time.
    awt = Average Waiting Time.
    stat = Sum Of Turn Around Time.
    swt = Sum of Waiting Time.  
		*/
		
int main()
{
      int n=6, tt = 0, min, d, i, j;
      float atat = 0, awt = 0, stat = 0, swt = 0;
      int p[n] = {1,2,3,4,5,6};    // Array Storing Process number Values of processes.
      int a[n] = {1,6,0,2,5,4};    // Array Storing Arival Time Values of processes.
	  int b[n] = {15,3,7,5,1,2};	// Array Storing Burst Time Values of processes.
	  
	  int ct[n],    //Array storing Completion Time of each process.
	      tat[n], 	 //Array storing Turnaround-Time of each process.
	      wt[n],	//Array storing waiting time of each process.
		  rb[n];	
	
      for(i=0;i<n;i++)
      {
         for(j=i+1;j<n;j++)
          {
                if(b[i]>b[j])
                {
                	swap(a[i],a[j]);
                     
                    swap(b[i],b[j]);
                    
                    swap(p[i], p[j]);
                }
          }
      }
      min = a[0];
       for(i=0;i<n;i++)
       {
       	  rb[i] = b[i];
	   }
      for(i=0; i<n; i++)
      {
            if(min > a[i])
            {
                  min=a[i];
                  d=i;
            }
            
      }
      
      tt = min;
      ct[d] = tt + b[d];
      
      tt = ct[d];

      for(i=0; i<n; i++)
      {
            if(a[i] != min)
            {
                  ct[i] = b[i]+tt;
                  tt = ct[i];
            }
      }
      //calculating Waiting time And Turn Around Time.
      for(i=0; i<n; i++)
      {

            tat[i] = ct[i] - a[i];
            stat = stat + tat[i];
            wt[i] = tat[i] - b[i];
            swt = swt + wt[i];
      }
      //calculating Average Waiting time And Average Turn Around Time.
      atat = stat/n;
      awt = swt/n;
      
      cout<<endl;
      cout<<"Process\tAT\tBT\tWT\tTAT\n";

    for(i=0;i<n;i++)
    {
    cout<<" "<<p[i]<<"\t"<<a[i]<<"\t"<<b[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<endl;
    }
    cout<<endl;
    cout<<"Average Waiting Time = "<<awt<<endl<<"\nAverage Turn Around Time = "<<atat;  //average waiting time and turn around time
    cout<<endl<<"\nThroughput : "<< n /(float) (ct[n-1] - a[0])<<" Per unit time";
    
    for(int i=0;i<n;i++)
      {
         for(int j=i+1;j<n;j++)
          {
                if(ct[i]>ct[j])
                {
                    swap(p[i], p[j]);
                }
          }
      }
      
     cout<<"\n\nOrder In which Process Get Completed : \n\n";
   for (int i=0; i<n; i++)
        {
        	cout<<"P"<<p[i]<<" ";
		}
    
	return 0;
}