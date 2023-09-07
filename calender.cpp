#include <iostream>
#define True 1
#define False 0
using namespace std;
int days_in_months[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
const char* months[]=
{
    " ",
    "\n\n\nJanuary", 
    "\n\n\nFebruary",
    "\n\n\nMarch",
    "\n\n\nApril",
    "\n\n\nMay",
    "\n\n\nJune",
    "\n\n\nJuly",
    "\n\n\nAugust",
    "\n\n\nSeptember",
    "\n\n\nOctober",
    "\n\n\nNovember",
    "\n\n\nDecember"
};
int inputyear(void)
{
    int year;
    cout<<"Please enter a year : ";
    cin>>year;
    return year;
}
int determinedaycode(int year)
{
    int daycode;
    int d1, d2, d3;
    d1= (year - 1.)/4.0;
    d2 = (year - 1.)/100.0;
    d3=(year - 1.)/400.0;
    daycode =(year + d1 - d2 + d3)%7;
    return daycode;
}
int determineleapyear(int year)
{
    if (year% 4== False && year%100  != False|| year%400 == False)
    {
        days_in_months[2]=29;
        return True;
    }
    else
    {
        days_in_months[2]=28;
        return False;
    }
}
void calender(int year,int daycode)
{
  int month, day;
  for (month=1; month <= 12; month++)
  {
    cout<<months[month];
    cout<<"\n\n\nSun  Mon  Tes  Wed  Thu  Fri  Sat\n";
    for (day=1; day<=1 + daycode*5; day++)
    {
        cout<<" ";
    }
  
    for( day=1; day<=days_in_months[month]; day++)
    {
        printf("%2d",day);

        if ((day + daycode)% 7>0)
            cout<<"   ";
        else
            cout<<"\n";
    }
        daycode = ( daycode + days_in_months[month] )% 7;
  }
    
}
int main(void)
{
    int year ,daycode ,leapyear;
    year=inputyear();
    daycode= determinedaycode(year);
    determineleapyear(year);
    calender(year,daycode);
    cout<<"\n";
}
