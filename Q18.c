/*Program ask user to enter the arrival time of all the students and number of gifts purchased by them
The time for billing for each student is 1 sec per gift i.e if number of gift purchased by student are 5
then time taken for his/her billing is 5*1 sec*/
#include<stdio.h>
#include<stdlib.h>
struct student
{
	char p_id;
	int arr_time;
	int no_of_gift;
	int burst_time;	
}s[11];
int main()
{
	int n=10,i=0,timer=0,running;
	printf("Enter the time student reached at counter and number of gifts purchased by the student\n");
	for(i=0;i<n;i++)
	{
		printf("For student %d	",i+1);
		s[i].p_id=i;
		scanf("%d",&s[i].arr_time);
		scanf("%d",&s[i].no_of_gift);
		if(s[i].no_of_gift<=0)
		{
			printf("Enter Valid number of gifts.\n");
			printf("Enter the number of gift bought by student %d\n",i+1);
			scanf("%d",&s[i].no_of_gift);
		}
		s[i].burst_time=s[i].no_of_gift*1;
	}
	s[10].p_id=-1;s[10].arr_time=-1;s[10].no_of_gift=-1;s[10].burst_time=-1;
	printf("Student\tArrival time\tNo of gift\tTime required for billing\n");
	for(i=0;i<n;i++)
	{
		printf(" %c\t\t%d\t\t%d\t\t%d\n",s[i].p_id+97,s[i].arr_time,s[i].no_of_gift,s[i].burst_time);
	}
	printf("\n\n");
	printf("--------------------------------------\n");
	printf("Billing order of Students is \n");
	printf("--------------------------------------\n");
	int x=10;
	timer=0;
	while(x!=0) 
	{
		running=10;
		for(i=0;i<n;i++)
		{
			if(s[i].arr_time<=timer&&s[i].no_of_gift>s[running].no_of_gift&&s[i].burst_time!=0)
			{
				running=i;
			}
		}
			if(running!=10)
			{
			printf("Billing of process %c started at %d and finished at ",s[running].p_id+97,timer);
			timer=timer+s[running].burst_time;
			printf("%d\n",timer);
			s[running].burst_time=0;
			x--;
			}
			else
			timer=timer+1;
	}
}
