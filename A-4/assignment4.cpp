#include <iostream>
#include <stdlib.h>
#include <cstdio>
using namespace std;

 class DateandTime 
 {
 	private:
 		int hr, mi , se, dd,mm,yy;
 		char c,d,e,f;
 		int integerNumberLength(int num)
		{
			static int count = 0;
			int n = num/10;
			if(n == 0)
			{
				int count2 = count;
				count2++;
				count = 0;
//				cout<<"length of integer = "<<count<<endl;
				return count2;
			}
			
			else
			{
				count++;
				return integerNumberLength(n);
			}
		}
		void checkDate(int d)
 		{
 			if (!(d >=1 && d<=31))
 			{
 				cout<<"\nPlease enter correct day: ";
 				cin>>dd;
 				checkDate(dd);
			 }
		}
 		void checkDate(int d, int m)
 		{
 			checkDate(d);
 			if(!(m>=1 && m<=12))
 			{
 				cout<<"\nPlease enter correct month: ";
 				cin>>mm;
 				checkDate(dd,mm);
			 }
			 
		 }
		 void checkDate(int d, int m,int y)
		 {
		 	int l,temp = yy;
		 	l=integerNumberLength(temp);
		 	// cout<<l<<endl;
		 	checkDate(d,m);
		 	if (l != 4)
		 	{
		 		cout<<"\nYou entered wrong year format.\nPlease enter year (YYYY e.g 2018): ";
		 		cin>>yy;
		 		checkDate(dd,mm,yy);
			 }
			else
			{
				return;}
		 }
		 void checkDate2(int d, int m, int y)
		 {
		 	int n = 1996; 
		 	n = abs(n-y);
		 	if(n%4 == 0)
			 {		
			 	if (m == 2)
			 	{
			 		if(d>29)
			 		{
			 			cout<<"\nWrong date.\nBecause it is February.\n";
			 			getDate();
			 		}
			 	}
			} 
			else
			{
				if( m==2)
				{
					if(d>28)
					{
						cout<<"W\nrong date.\nBecause it is February.\n";
						getDate();
					}
				}
				if( m == 4 || m==6 || m==9 ||m==11)
				{
					if(d >30)
					{
						cout<<"\nWrong date.\nBecause it is 30 days month.\n";
						getDate();
					}
				}
			}				
		}
		void checkTime(int h)
 		{
 			if(!(h>=1 && h<=12))
 			{
 				cout<<"\nPlease enter hour in 12hr format: ";
 				cin>>hr;
 				checkTime(hr);
			}	 
		}
		void checkTime(int h, int m)
		{
			checkTime(h);
			if(!(m>=0 && m<=59))
			{
				cout<<"\nPlease enter correct minutes: ";
				cin>>mi;
				checkTime(hr,mi);
			}
		}
		void checkTime(int h, int m, int s)
		{
			checkTime(h,m);
			if(!(s>=0 && s<=59))
			{
				cout<<"\nPlease enter correct seconds: ";
				cin>>se;
				checkTime(hr,mi,se);
			}
		}		
 	public:
 		void englishDate() const
 		{
 			string mon[] = {"","January","February","March","April","May","June","July","August","September","October","November","December"};
 			cout<<endl;
 			for(int i = 1; i<=12; i++)
 			{
 				if(i == mm)
 				{
 					if(dd == 1 || dd==21 )
 					{
 						cout<<dd<<"st "<<mon[i]<<","<<yy<<endl;
 						break;
 					}
 					if(dd == 2 || dd==22 )
 					{
 						cout<<dd<<"nd "<<mon[i]<<","<<yy<<endl;
 						break;
 					}
 					if(dd == 3 || dd==23 )
 					{
 						cout<<dd<<"rd "<<mon[i]<<","<<yy<<endl;
 						break;
 					}
 					else
 					{
 						cout<<dd<<"th "<<mon[i]<<","<<yy<<endl;
 					}
 					break;
				}
			}
		 }
		void showDate() const
		{
			cout<<endl;
			if(dd >= 1 && dd<= 9)
			{
				if(mm >= 1 && mm<=9)
					cout<<"Date: "<<"0"<<dd<<"-"<<"0"<<mm<<"-"<<yy<<endl;
				else
					cout<<"Date: "<<"0"<<dd<<"-"<<mm<<"-"<<yy<<endl;	
			}
			else
			{
				if(mm>=1 && mm<=9)
					cout<<"Date: "<<dd<<"-"<<"0"<<mm<<"-"<<yy<<endl;
				else
					cout<<"Date: "<<dd<<"-"<<mm<<"-"<<yy<<endl;
			}
			cout<<endl;
		}
		void showTime() const
		{
			cout<<"Time: ";
			if(hr >= 1 && hr<=9)
				cout<<"0"<<hr<<":";
			else
				cout<<hr<<":";
			if(mi >= 1 && mi<=9)
				cout<<"0"<<mi<<":";
			else
				cout<<mi<<":";
			if(se >= 1 && se<=9)
				cout<<"0"<<se<<" AM"<<endl;
			else
				cout<<se<<" AM"<<endl;
			
		}
 		void showDateTime() const
 		{
 			cout<<"\nDATE & TIME.\n ";
 			cout<<endl;
 			showTime();
 			showDate();
		 }
		 void getTime() 
		 {
			cout<<"\nEnter Time(Hr:min:sec)...\nTime: ";
		 	scanf("%d %c %d %c %d",&hr,&c,&mi,&d,&se);
		 	checkTime(hr);
		 	checkTime(hr,mi);
		 	checkTime(hr,mi,se);		 	
		 }
		 void getDate()
		 {
			cout<<"Enter Date(DD-MM-YYYY)... \nDate: ";
		 	scanf("%d %c %d %c %d",&dd,&e,&mm,&f,&yy);
		 	checkDate(dd);
		 	checkDate(dd,mm);
		 	checkDate(dd,mm,yy);
		 	checkDate2(dd,mm,yy);		 	
		 }
		 void updateHour()
		 {
		 	cout<<"Enter Hour: ";
		 	cin>>hr;
		 	checkTime(hr);
		 }
		 void updateMinute()
		 {
		 	cout<<"Enter minutes: ";
		 	cin>>mi;
		 	checkTime(hr,mi);
		 }
		 void updateSeconds()
		 {
		 	cout<<"Enter seconds: ";
		 	cin>>se;
		 	checkTime(hr,mi,se);
		 }
		 void updateDay()
		 {
		 	cout<<"Enter day: ";
		 	cin>>dd;
		 	checkDate(dd);
		 	checkDate2(dd,mm,yy);
		 }
		 void updateMonth()
		 {
		 	cout<<"Enter Month: ";
		 	cin>>mm;
		 	checkDate(dd,mm);
		 	checkDate2(dd,mm,yy);
		 }
		 void updateYear()
		 {
		 	cout<<"Enter year: ";
		 	cin>>yy;
		 	checkDate(dd,mm,yy);
		 	checkDate2(dd,mm,yy);
		 }
		 void updateTime()
		 {
		 	int o;
		 	cout<<"What do you want to update?\n1. Hour.\n2. Minutes.\n3. Seconds.\n4. Hour and minutes.\n5. Minutes and seconds.\n6. Hour and seconds.\n7. Hour, minute and seconds.\n8. exit\nChoice: ";
		 	cin>>o;
		 	if(o == 1)
		 	{
		 		updateHour();
		 	}
		 	if(o == 2)
		 	{
		 		updateMinute();
		 	}
		 	if( o == 3)
		 	{
		 		updateSeconds();
		 	}
		 	if (o == 4)
		 	{
		 		updateHour();
		 		updateMinute();
		 	}
		 	if(o==5)
		 	{
		 		updateMinute();
		 		updateSeconds();
		 	}
		 	if( o==6)
		 	{
		 		updateHour();
		 		updateSeconds();
		 	}
		 	if(o==7)
		 	{
		 		updateHour();
		 		updateMinute();
		 		updateSeconds();
		 	}
		 }
		 void updateDate()
		 {
		 	int o;
		 	cout<<"What do you want to update?\n1. Day\n2. Month\n3. Year\n4. Day and month\n5. Month and year\n6. Day and year\n7. Day,month and year\n8. exit\nChoice: ";
		 	cin>>o;
		 	if(o == 1)
		 	{
		 		updateDay();
		 	}
		 	if(o == 2)
		 	{
		 		updateMonth();
		 	}
		 	if( o == 3)
		 	{
		 		updateYear();
		 	}
		 	if (o == 4)
		 	{
		 		updateDay();
		 		updateMonth();
		 	}
		 	if(o==5)
		 	{
		 		updateMonth();
		 		updateYear();
		 	}
		 	if( o==6)
		 	{
		 		updateDay();
		 		updateYear();
		 	}
		 	if(o == 7)
		 	{
		 		updateDay();
		 		updateMonth();
		 		updateYear();
		 	}

		 }

	 	DateandTime()
	 	{

			getDate();
			getTime();
	 	}
	 	~DateandTime()
	 	{
	 		int o;
	 		cout<<"Do you want to update?\n1. Time\n2. Date\n3. Both\n4. exit\nChoice: ";
	 		cin>>o;
	 		if(o == 1)
	 		{
	 			updateTime();
	 		}
	 		if(o == 2)
	 		{
	 			updateDate();
	 		}
	 		if( o == 3)
	 		{ 
	 			cout<<"\nYou are updating time...\n";
	 			updateTime();
	 			cout<<"\nYou are updating Date...\n";
	 			updateDate();
	 		}
	 		if( o >=1 && o<=3)
	 		{
	 			showDateTime();
	 		}
	 		cout<<" \nTHANK YOU.\n";
	 		dd = 0; mm= 0; yy=0; hr=0; mi=0; se=0;
	 	}	
 };
 int main()
 {
 	DateandTime d;
 	d.showDate();
 	d.showTime();
 	d.showDateTime();
	d.englishDate();
 	return 0;
}