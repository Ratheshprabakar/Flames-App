#include<stdio.h>
char string1[100];
char string2[100];
char flames_string[]="flames";
int find_count();
char flames(int name_length);
int min_length,name_length;
int count=0,x;
char remaining_character;
int length_of_string1,length_of_string2;
int main()
{
	printf("Enter the first name\t");
	gets(string1);
	printf("\nEnter the second name\t");
	gets(string2);	
	remaining_character=flames(find_count());
	switch(remaining_character)
	{
		case 'f':
			printf("\n\n\nFRIENDS\n\n\n");
			break;
		case 'l':
			printf("\n\n\nLOVE\n\n\n");
			break;
		case 'a':
			printf("\n\n\nAFFECTION\n\n\n");
			break;
		case 'm':
			printf("\n\n\nMARRIAGE\n\n\n");
			break;
		case 'e':
			printf("\n\n\nENEMY\n\n\n");
			break;
		case 's':
			printf("\n\n\nSISTER\n\n\n");
			break;
	}
	
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
	if((length_of_string1+length_of_string2)-(2*count)!=0)
		return (length_of_string1+length_of_string2)-(2*count);
	else
	{
		printf("Unable to calculate FLAMES!!!");
		exit(1);
	}
}
char flames(int name_length)
{
	int flames_length=6;
	int i=1,j=0,k;
	while(flames_length>1)
	{
		if(name_length==i)
		{
			for(k=j;k<flames_length-1;k++)
			{
				flames_string[k]=flames_string[k+1];
			}
			flames_string[flames_length-1]='\0';
			flames_length--;
			i=0;
			j--;			
		}
		j++;
		if(j==flames_length)
		{
			j=0;
		}
		i++;
	}
	return flames_string[0];
}
