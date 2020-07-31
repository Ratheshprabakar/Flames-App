#include<stdio.h>
char string1[100];
char string2[100];
char flames_string[100]="flames";
int find_count();
int min_length;
int count=0,x;
int length_of_string1,length_of_string2;
int main()
{
	printf("Enter the first name\t");
	gets(string1);
	printf("\nEnter the second name\t");
	gets(string2);	
	x=find_count();
	printf("\nTotal Number of Unique Characters are \t%d",x);
	
}
int find_count()
{
	int i,j;
	count=0;
	length_of_string1=strlen(string1);
	length_of_string2=strlen(string2);
	if(length_of_string1<=length_of_string2)
		min_length=length_of_string1;
	else		
		min_length=length_of_string2;
	for(i=0;i<min_length;i++)
	{
		for(j=0;j<(length_of_string1+length_of_string2)-min_length;j++)
		{
			if((string1[i]==string2[j]) && (string1[i]!='-1'&& string2[j]!='-1'))
			{
				count++;
				string1[i]=string2[j]='-1';
				break;
			}		
		}
	}
	return (length_of_string1+length_of_string2)-(2*count);
}
