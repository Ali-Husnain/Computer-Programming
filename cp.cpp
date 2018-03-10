#include <iostream>
 using namespace std;
 //// 3rd 2nd ... and febrary, 31 30
 class DateandTime 
 {
 	private:
 		int hr, mi , se, dd,mm,yy;
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
 				cout<<"You entered wrong day.\nPlease enter correct day: ";
 				cin>>dd;
 				checkDate(dd);
			 }
		}
 		void checkDate(int d, int m)
 		{
 			checkDate(d);
 			if(!(m>=1 && m<=12))
 			{
 				cout<<"You entered wrong month,\nPlease enter correct month: ";
 				cin>>mm;
 				checkDate(dd,mm);
			 }
			 
		 }
		 void checkDate(int d, int m,int y)
		 {
		 	int l,temp = yy;
		 	l=integerNumberLength(temp);
		 	cout<<l<<endl;
		 	checkDate(d,m);
		 	if (l != 4)
		 	{
		 		cout<<"\nYou entered wrong year format.\nPlease enter year (YYYY e.g 2017): ";
		 		cin>>yy;
		 		checkDate(dd,mm,yy);
			 }
			else
			{
				return;}
		 }
		void checkTime(int h)
 		{
 			if(!(h>=1 && h<=12))
 			{
 				cout<<"\nYou entered wrong hour.\nPlease enter hour in 12hr format: ";
 				cin>>hr;
 				checkTime(hr);
			}	 
		}
		void checkTime(int h, int m)
		{
			checkTime(h);
			if(!(m>=0 && m<=59))
			{
				cout<<"\nYou entered wrong minute.\nPlease enter correct minutes: ";
				cin>>mi;
				checkTime(hr,mi);
			}
		}
		void checkTime(int h, int m, int s)
		{
			checkTime(h,m);
			if(!(s>=0 && s<=59))
			{
				cout<<"\nYou entered wrong seconds.\nPlease enter correct seconds: ";
				cin>>se;
				checkTime(hr,mi,se);
			}
		}		
 	public:
 		void englishDate()
 		{
 			string mon[] = {"","January","February","March","April","May","June","July","August","September","October","November","December"};
 			for(int i = 1; i<=12; i++)
 			{
 				if(i == mm)
 				{
 					cout<<dd<<"th "<<mon[i]<<","<<yy<<endl;
				 }
			 }
		 }
		void showDate()
		{
			cout<<"\nDate: "<<dd<<"-"<<mm<<"-"<<yy<<endl;
		}
		void showTime()
		{
			cout<<"\nTime: "<<hr<<":"<<mi<<":"<<se<<"AM"<<endl;
		}
 		void showDateTime()
 		{
 			cout<<"\nDate & Time: "<<dd<<"-"<<mm<<"-"<<yy;
 			cout<<" "<<hr<<":"<<mi<<":"<<se<<"AM"<<endl;
		 }
		 void getTime()
		 {
			cout<<"\nEnter Time(Hr:min:sec)...\nHour: ";
		 	cin>>hr;
		 	checkTime(hr);
		 	cout<<"Minutes: ";
		 	cin>>mi;
		 	checkTime(hr,mi);
		 	cout<<"Seconds: ";
		 	cin>>se;
		 	checkTime(hr,mi,se);		 	
		 }
		 void getDate()
		 {
			cout<<"Enter Date(DD-MM-YYYY)... \nDay: ";
		 	cin>>dd;
		 	checkDate(dd);
		 	cout<<"Month: ";
		 	cin>>mm;
		 	checkDate(dd,mm);
		 	cout<<"Year: ";
		 	cin>>yy;
		 	checkDate(dd,mm,yy);		 	
		 }
	 	DateandTime()
	 	{
			getDate();
			getTime();
	 	}
	 	~DateandTime()
	 	{	 }	
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
