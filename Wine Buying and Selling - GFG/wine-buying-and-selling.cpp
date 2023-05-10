//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int>& arr, int n){
      //Code here.
      
       long long work =  0;

        int i = 0, j = 0;

        while (i<n) {

        if(arr[i]<=0) i++;

        if(arr[j]>=0) j++;

        if(arr[i]>0&&arr[j]<0){

            int x= min(abs(arr[i]),abs(arr[j]));

            work+= abs(i - j)*x;

            arr[j]+=x;

            arr[i]-=x;

        }

    }

    return work;
  }
};



//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends