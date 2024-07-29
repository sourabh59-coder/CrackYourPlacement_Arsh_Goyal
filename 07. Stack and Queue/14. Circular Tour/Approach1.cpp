//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump v[],int n)
    {
       //Your code here
    //   int i = 0, j = 0;
       int fuel = 0;
       int ans = -1;
       
       for(int i=0;i<2*n;i++)
       {
          int ind = i % n;
          fuel += v[ind].petrol;
          if(fuel >= v[ind].distance)
          {
              fuel -= v[ind].distance;
              if(ans==-1)   ans = i;
          }
          else
          {
              ans = -1;
              fuel = 0;
          }
       }
       
       if(ans!=-1 && ans<n) return ans;
       return -1;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends
