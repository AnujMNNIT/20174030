#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

void radixsort(int a[],int n)
{
	int i,j,b[n],c[10],dp;//digit position 
	for(dp=0;dp<9;dp++)
	{
		for(i=0;i<=9;i++)
			c[i]=0;
		for(i=0;i<n;i++)
			c[(a[i]/(int)pow(10,dp))%10]++;
		for(i=1;i<10;i++)
			c[i]=c[i]+c[i-1];
		for(i=n-1;i>=0;i--)
		{
			b[(c[(a[i]/(int)pow(10,dp))%10]--)-1]=a[i];	
		}
		for(i=0;i<n;i++)
		{
			a[i]=b[i];
		}
	}
}

main()
{
	int i,n,t;
	printf("Enter the no. of test cases: ");
	scanf("%d",&t);
	FILE *fp=fopen("radix.txt","w");
	
	while(t--)
	{
		//scanf("%d",&n);
		n=10000*(10-t);
		int arr1[n],arr2[n],arr3[n],num;
		clock_t end,start;
		double clock_time1,clock_time2,clock_time3;
		FILE *fp1=fopen("avgradix.txt","w");
		FILE *fp2=fopen("bestradix.txt","w");
		FILE *fp3=fopen("worstradix.txt","w");
	
		for(i=0;i<n;i++)
		{
			num=rand();
			fprintf(fp1,"%d ",num);
		}
		fclose(fp1);
		fp1=fopen("avgradix.txt","r");
		for(i=0;i<n;i++)
		{
			fscanf(fp1,"%d ",&arr1[i]);
		}
		
		for(i=0;i<n;i++)
		{
			fprintf(fp2,"%d ",i);
		}
		fclose(fp2);
		fp2=fopen("bestradix.txt","r");
		for(i=0;i<n;i++)
		{
			fscanf(fp2,"%d ",&arr2[i]);
		}
		
		for(i=0;i<n;i++)
		{
			fprintf(fp3,"%d ",n-i);
		}
		fclose(fp3);
		fp3=fopen("worstradix.txt","r");
		for(i=0;i<n;i++)
		{
			fscanf(fp3,"%d ",&arr3[i]);
		}
		
		start=clock();
		radixsort(arr1,n);
		end=clock();
		clock_time1=((double)(end-start))/CLOCKS_PER_SEC;

		start=clock();
		radixsort(arr2,n);
		end=clock();
		clock_time2=((double)(end-start))/CLOCKS_PER_SEC;
		
		start=clock();
		radixsort(arr3,n);
		end=clock();
		clock_time3=((double)(end-start))/CLOCKS_PER_SEC;

    	fprintf(fp,"%d %lf %lf %lf\n",n,clock_time1,clock_time2,clock_time3);
        printf("%d %lf %lf %lf\n",n,clock_time1,clock_time2,clock_time3);
	}
}
