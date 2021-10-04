#include <stdio.h>
#include <stdlib.h>

int get_1st_weekDay(int year){
	int day;
	day=(((year-1)*365)+((year-1)/4)-((year-1)/100)+((year)/400)+1)%7;
	return day;
	
}
int main(){
	system("Color 3F");
	int year, month,day,daysInMonth,weekDay=0,startingday;
	printf("\nEnter Your Desired Year: ");
	scanf("%d",&year);
	const char *months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	int monthDay[]={31,28,31,30,31,30,31,31,30,31,30,31};
	if((year%4== 0&& year%100!=0)||year%400==0)
	    monthDay[1]=29;
	     
    startingday=get_1st_weekDay(year);
	for(month=0;month<12;month++){
		daysInMonth=monthDay[month];
		printf("\n\n_________________________%s_________________________\n",months[month]);
		printf("\n    Sun    Mon    Tue    Wed    Thur    Fri    Sat\n");
		
		for(weekDay=0;weekDay<startingday;weekDay++)
		    printf("       ");
		    
		for(day=1;day<=daysInMonth;day++){
			printf("%7d",day);
			
			if(++weekDay>6){
				printf("\n");
				weekDay=0;
			}
			startingday=weekDay;
		}
	}
	return 0;
}

