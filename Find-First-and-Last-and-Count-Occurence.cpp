#include<iostream>
using namespace std;
int first(int arr[], int n, int key)
{
	int s=0;
	int e=n-1;
	int mid = (s+e)/2;
	int res = -1;
	
	while(s<=e)
	{
		if(arr[mid] == key)
		{
			res = mid;
			e = mid-1;
		}
		else if(key>arr[mid]) //right
		{
			s=mid+1;
		}
		else           //left
		{
			e=mid-1;
		}
		
		mid=(s+e)/2;
	}
	return res;
}

int last(int arr[], int n, int key)
{
	int s=0;
	int e=n-1;
	int mid = (s+e)/2;
	int las = -1;
	
	while(s<=e)
	{
		if(arr[mid] == key)
		{
			las = mid;
			s = mid+1;
		}
		else if(key>arr[mid]) //right
		{
			s=mid+1;
		}
		else           //left
		{
			e=mid-1;
		}
		
		mid=(s+e)/2;
	}
	return las;
}

int count(int arr[], int n, int x) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {

        // counting the occurrences:
        if (arr[i] == x) cnt++;
    }
    return cnt;
    
}

int main()
{
	int max[5] = {1,2,3,3,4};
	cout<<"First occurencce of 3 is -> "<<first(max,5,3)<<endl;
	cout<<"Lastt occurencce of 3 is -> "<<last(max,5,3)<<endl;
	cout<<"Total Occurence of 3 is -> "<<count(max,5,3)<<endl;
	return 0;
}
