#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
	{
	FILE *fptr1,*fptr2,*fptr3;
	fptr1=fopen("training-shadow.txt","r");
	if(fptr1==NULL)
		{
		printf("OOPS!!!..error in file opening...");
		exit(0);
		}
	fptr2=fopen("training-passwd.txt","r");
	if(fptr2==NULL)
		{
		printf("OOPS!!!..error in file opening...");
		exit(0);
		}
	fptr3=fopen("passwordfile.txt","w");
	if(fptr2==NULL)
		{
		printf("OOPS!!!..error in file creation...");
		exit(0);
		}
	char eachts[1000],eachtp[1000];
	int line=8196;
	while(line>0)
		{
		fgets(eachts,1000,fptr1); 
		char strts[1000];
		strcpy(strts,eachts); 
		char *eachtokents=strtok(strts,":");
		char secondtokents[1000];
		int count=1;
		while(eachtokents!=NULL)
			{
			if(count==2)
				strcpy(secondtokents,eachtokents);
			eachtokents=strtok(NULL,":");
			count++;
			}
		
		fgets(eachtp,1000,fptr2);
		char strtp[1000];
		strcpy(strtp,eachtp);
		char *eachtokentp=strtok(strtp,":");
		char password[1000];
		strcpy(password,"");
		while(eachtokentp!=NULL)
			{
			if(strcmp(eachtokentp,"x")==0)
				{
				strcat(password,secondtokents);
				strcat(password,":");
				}
			else
				{
				strcat(password,eachtokentp);
				strcat(password,":");
				}
			eachtokentp=strtok(NULL,":");
			}
		//printf("%s \n",password);
		fputs(password,fptr3);
		line--;
		}
	fclose(fptr1);
	fclose(fptr2);
	return 0;
	}
