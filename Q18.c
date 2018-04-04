#include<stdio.h>
#include<stdlib.h>
struct student
{
	char p_id;
	int status;
	int arr_time;
	int no_of_gift;
	int burst_time;
}s[10];
void sort(struct student p[],int n)
{
	int i,j;
	struct student temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].arr_time>p[j+1].arr_time)
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;	
			}
			if(p[j].arr_time==p[j+1].arr_time)
			{
			if(p[j].no_of_gift>p[j+1].no_of_gift)
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;	
			}
		}
		}
	}
}
int main()
{
	int n=10,i=0,timer=0,j,q,p,temp;
	int arr_queue[10];
	for(i=0;i<n;i++)
	{
		printf("Enter the time the student %d reaches at billing counter\n",i+1);
		s[i].p_id=i+97;
		scanf("%d",&s[i].arr_time);
		printf("Enter the number of gift bought by student %d\n",i+1);
		scanf("%d",&s[i].no_of_gift);
		s[i].burst_time=s[i].no_of_gift*1;
		s[i].status=0;
	}
	printf("Student\tArrival time\tNo of gift(Priority)\tTime required for billing(Burst Time)\n");
	for(i=0;i<n;i++)
	{
		printf("%c\t%d\t%d\t%d\n",s[i].p_id,s[i].arr_time,s[i].no_of_gift,s[i].burst_time);
	}
	sort(s,n);
	printf("\n\n");
	int x,flag;
	while(1)//loop variable x,flag variable 
	{
		for(i=0;i<n;i++)
		{
			if(s[i].burst_time==0)
			continue;
			if(s[i].arr_time<=timer&&s[i].status==0)
			{
				arr_queue[j]=s[i].p_id;
				s[i].status=0;
				j++;
				for(q=0;q<j-1;q++)
				{
					for(p=0;p<j-q-1;p++)
					{
						if(s[arr_queue[p]-97].no_of_gift>s[arr_queue[p]-97].no_of_gift)
						{
							temp=arr_queue[p];
							arr_queue[p]=arr_queue[p+1];
							arr_queue[p+1]=temp;
						}
					}
				}
			}
			timer=timer+s[arr_queue[0]-97].burst_time;
			printf("\n%dTimer%d",s[arr_queue[0]-97].burst_time);
			printf("Student %c\n",s[0].p_id);
			s[arr_queue[0]-97].burst_time=0;
			if(j==1)
			{
				j--;
			}
			for(p=0;p<j-1;p++)
			{
				arr_queue[p]=arr_queue[p+1];
			}
			j--;
		}
		flag=0;
		for(x=0;x<10;x++)
		{
			if(s[x].burst_time!=0)
			flag++;
		}
		break;
	}
	/*for(i=0;i<n;i++)
	{
		printf("%c\t%d\t%d\t%d\n",s[i].p_id,s[i].arr_time,s[i].no_of_gift,s[i].burst_time);
	}*/
}
