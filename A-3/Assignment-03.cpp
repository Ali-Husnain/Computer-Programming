#include <iostream>
using namespace std;

int quickSort(int array[], int i, int j)
{
	if(i == j)
	{
		return 0;
	}
    int q, a = i ,size = j,t = 0, r = 1;
    for(q = 0; q <= size; q++)
    {
        if(i == j)
        {
        	break;
        }
        if(array[i] == array[j])
        {
            j--;
            continue;
        }
        if(array[i]>array[j])
        {
        	swap(array[i],array[j]);
            swap(t ,r);
        }
        if(r == 0)
        {
            i++;
        }
        if(t == 0)
        {
        	j--;
        } 
    }
    if(i == j)
    {
    	i = i-1; j=j+1;
    	if(i>a)
    	{
    		quickSort(array,a,i);
    	}
    	if(j<size)
    	{
    		quickSort(array,j,size);
    	}
    }
    return 0;
}
int main()
{
	int x=0,y;
	cout<<"Enter array size: ";
	cin>>y;
	int array1[y];
	cout<<"Enter integers in array; "<<endl;
	for(int i = 0;i<y; i++)
	{
		cin>>array1[i];
	}
	quickSort(array1,x,y-1);
	cout<<"Sorted array: ";
	for(int i = 0; i<y; i++)
	{
		cout<<array1[i]<<" ";
	}
	cout<<endl;
    return 0; 
}