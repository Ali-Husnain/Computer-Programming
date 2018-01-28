#include <iostream>
#include <stdio.h>
using namespace std;
char encode(char wd[][2] ,char cd[5][5],int ee)
{
    int aa,bb,cc,dd;
    char encoded[ee][2],l1,l2,k1,k2,zz,yy;
      
    for(int qq = 0; qq < ee;qq++)
    {
        l1 = wd[qq][0];
        l2 = wd[qq][1];
        
        
        //cout << l1<<" "<<l2<<" ";
        for(int ww = 0; ww < 5; ww++)
        {   
            
            for(int hh = 0; hh < 5; hh++)
            {
            
                
                if(l1 == cd[ww][hh])
                {    
                    aa = ww;
                    bb = hh;
                    //cout<<aa<<" "<<bb<<endl;
                }   
                else if(l2 == cd[ww][hh])
                {  
                    cc = ww;
                    dd = hh;
                    //cout<<cc<<" "<<dd<<endl;
                }
            }
        }

        if(l1 != l2)
        {


        if(aa != cc && bb != dd)
        {
            encoded[qq][0] = cd[cc][bb];
            encoded[qq][1] = cd[aa][dd];        
        }
        if(aa == cc && bb != dd)
        {
            if(bb == 4 && dd != 4)
            {
                encoded[qq][0] = cd[aa][0];
                encoded[qq][1] = cd[aa][dd+1];              
            }
            else if(dd == 4 && bb != 4)
            {
                encoded[qq][0] = cd[aa][bb+1];
                encoded[qq][1] = cd[aa][0];             
            }
            else
            {
                encoded[qq][0] = cd[aa][bb+1];
                encoded[qq][1] = cd[aa][dd+1];
            }
        }
        if(aa != cc && bb == dd)
        {
             if(aa == 4 && cc != 4)
            {
                encoded[qq][0] = cd[0][bb];
                encoded[qq][1] = cd[cc+1][dd];              
            }
            else if(cc == 4 && aa != 4)
            {
                encoded[qq][0] = cd[aa+1][bb];
                encoded[qq][1] = cd[0][dd];             
            }
            else
            {
                encoded[qq][0] = cd[aa+1][bb];
                encoded[qq][1] = cd[cc+1][dd];
            }
        }           
        }

        if(l1 == l2)
        {
            if( bb == 3)
            {
                encoded[qq][0] = cd[aa][4];
                encoded[qq][1] = cd[aa][0];             
            }
            if( bb == 4 )
            {
                encoded[qq][0] = cd[aa][0];
                encoded[qq][1] = cd[aa][1];
            }
            if(bb == 0 || bb == 1 || bb == 2)
            {
                encoded[qq][0] = cd[aa][bb+1];
                encoded[qq][1] = cd[aa][bb+2];
            }       
        }
    }
    //cout << endl;
    for(int pp = 0; pp < ee; pp++)
    {
        yy = encoded[pp][0];
        zz = encoded[pp][1];
        cout <<yy<<zz;
        
    }
    cout<<endl;
    return encoded[ee][2];
    
}

string rmch(string line1)
{
    ////// remove extra characters    /// data for decrpyt
    for(int i = 0; i < line1.size(); ++i)
    {
        if (!((line1[i] >= 'a' && line1[i]<='z') || (line1[i] >= 'A' && line1[i]<='Z')))
        {
            line1[i] = '\0';
        }
    }

    //cout << "Output String: " << line1<<endl;   
    return line1;
}

string upcs(string line2)
{
    /// upper case     ////// data for decrypt
    for(int k = 0; k < line2.size(); k++)
    {
        if (line2[k] >= 'a' && line2[k] <= 'z')
        {
            line2[k] = line2[k] - 32;
        }
    }
    //cout << "upper: "<<line2 << endl;
    return line2;
}
string rpch(string line)
{
    ///remove repeated char        ///// data for decrpyt
    string str;
    for(int j = 0; j < line.size(); j++ )
    {
        for(int jj = j+1; jj < line.size(); jj++ )
        {
            if(line[j] == line[jj])
            {
                line[jj] = '\0';
            }
        }
        if(j == 0 )
        {
            str = line[j];
        }
        else if(line[j] != '\0')
        {
            str+=line[j];
        }
    }
    return str;
}

string rpij(string line3)
{
    //replace i with j ////data

    for(int l = 0; l < line3.size(); l++)
    {
        if(line3[l] == 'J')
        {
            line3[l] = 'I';
        }
    }
    return line3;
}
int null(string str1,string f)
{

    int z = f.size(),ff,t,n = 0,mm = 0,y = 0,ss,v;
    int sz = str1.size(),count = 0,count1,count2,o=0;
    //cout << "sz "<<sz<<endl;
    char pltxt1[sz] ,chr;
    str1.copy(pltxt1 , sz);
    for( int ii = 0; ii<sz; ii++)
    {
        if(pltxt1[ii] >= 'A' && pltxt1[ii]<='Z')
        {
        count+=1;}
    }
    cout <<endl;
    count1 = count;
    if(count%2 != 0)
    {
        count+=1;
    }
    count2 = count;
    char pltxt[count2];
    if(count2>count1)
    {
        pltxt[count1] = 'X';
    }
    for( int jj = 0; jj < sz; jj++)
    { chr = pltxt1[jj];
        if(chr >= 'A' && chr<='Z')
        {
            pltxt[o] = chr;
            o+=1;
        }
    }
    // for( int kk = 0; kk<count2; kk++)
    // {

    //     cout<<pltxt[kk];
    // }
    // cout<<endl;

    char upalpha[25-z],alpha[25],code[5][5];
    v = 0;
    ff = count2/2;
    //cout<<ff<<endl;
    char wrd[ff][2];
    for(int u = 0; u < ff; u++)
        {   
            wrd[u][0] = pltxt[v];
            wrd[u][1] = pltxt[v+1];
            v+=2;
        }
    for(int m = 0; m < 25; m++)
    {
        if(!(m + 'A' >= 'J'))
        {
            alpha[m] = m + 'A';
        }
        else
        {
            alpha[m] = (m +1) + 'A';
        }
    }
    
    for(int p = 0; p < z; p++)
    {
        for(int q = 0; q < 25; q++)
        {
            if(f[p] == alpha[q])
            {
                alpha[q] = ' ';
            }
        }
    }
    
    for(int t = 0; t < 25; t++)
    {
        if (alpha[t] != ' ')
        {
            upalpha[y] = alpha[t];
            y+=1;
        }
    }
        
    // for (int n = 0; n < ff; n++)
    // {
    //     cout << wrd[n][0]<<"  "<<wrd[n][1]<< endl;
    // }


    for(int row = 0; row < 5; row++)
    {
        for(int col = 0; col < 5; col++)
        {
            if(n < f.length())
            {
                code[row][col] = f[n];
                n+=1;
            } 
            else
            {
                code[row][col] = upalpha[mm];
                mm+=1;
            }
        }
    }
    for(int rw = 0; rw<5; rw++)
    {
        for (int cl = 0; cl < 5; cl++){
            cout << code[rw][cl]<<" ";
        }
        cout << endl;
    }
    cout<<endl;
    encode(wrd,code,ff);
    return 0;

}

int main() {
    string str, plaintxt ,key,a,b,c,d,e,f,gg,g,h,x;
    cout << "Enter Message: ";
    getline(cin, plaintxt);
    cout << "Enter Key: ";
    getline(cin, key);
    a = rmch(plaintxt);
    b = rmch(key);
    c = upcs(a);
    d = upcs(b);
    e = rpch(d);
    x = rpij(e);
    h = rpch(x); //key
    g = rpij(c);
    null(g,h);
    return 0;
}