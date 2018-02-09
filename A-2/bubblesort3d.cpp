#include <iostream>
using namespace std;

int input(int a[2][2][5])
{
	for(int i = 0; i<2;i++)
	{
		for(int j = 0; j<2; j++)
		{
			cout<< "Enter elements; "<<endl;
			for(int k = 0; k<5; k++)
			{
				cin >> a[i][j][k];
			}
		}
		cout<<endl;
	}
	return 0;
}

int sorting(int b[2][2][5])
{
	int row, col, ele,R,C,E, x, y, z;
    for(int i = 0; i<20; i++)
    {
        x = 0; y = 0; z = 0; row = 0; col = 0; ele = 0; R = 0; C = 0; E = 1;
        for(int j = 0; j<19; j++)
        { 
        	x = b[row][col][ele]; 
            y = b[R][C][E];
            if(ele == 4)
            {
                E = 0; C++;
                if(C == 2)
                {
                    C = 0; R++;
                    if(x>y)
                    {
                        z = x;
                        b[row][col][ele] = b[R][C][E];
                        b[R][C][E] = z;
                    }
                    ele = 0; row++; col = 0;E++;
                }
                else
                {
                    if(x>y)
                    {
                        z = x;
                        b[row][col][ele] = b[R][C][E];
                        b[R][C][E] = z;
                    }
                     ele = 0; col++;E++;
                }
            }
            else
            {
                if(x>y)
                {
                    z = x;
                    b[row][col][ele] = b[R][C][E];
                    b[R][C][E] = z;
                }
                ele++;E++;
            }  
        }
    }
    return 0;
}

int output(int c[2][2][5])
{
	cout<< "output value; "<<endl;
	for(int i = 0; i<2;i++)
    {
    	
    	for(int j = 0; j<2; j++)
        {
            for(int k = 0; k<5; k++)
            {
                cout << c[i][j][k]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}

int main()
{
	int array[2][2][5];
	input(array);
    //int array[2][2][5]={{{3,17,6,13,8},{5,14,19,4,7}},{{9,20,10,18,16},{15,11,1,12,2}}};
    sorting(array);
    output(array);
    return 0;
}