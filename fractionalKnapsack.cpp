//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static int sortByMaximumValueToWeightRatio(Item a, Item b) {
        if(a.value/(float)a.weight > b.value/(float)b.weight) return 1;
        else return 0;
    }
    
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr+n, sortByMaximumValueToWeightRatio);
        
        double maxValue = 0;
        
        for(int i=0; i<n; i++) {
            int itemWeight = arr[i].weight;
            int itemValue = arr[i].value;
            if(W >= itemWeight) {
                // take complete item
                maxValue += itemValue;
                W -= itemWeight;
            }
            else {
                // take fraction of item
                maxValue += (W*itemValue)/(float)itemWeight;
                break;
            }
        }
        
        return maxValue;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends
