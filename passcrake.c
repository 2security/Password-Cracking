#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<crypt.h>
#include<time.h>
int main()
	{
	clock_t start, end;
     	double time_used;
     
     	start = clock();
     	
	FILE *fptr1,*fptr2,*fptr3,*fptr4;
	fptr1=fopen("top250.txt","r");
	if(fptr1==NULL)
		{
		printf("OOPS!!!..error in file opening...");
		exit(0);
		}
	fptr2=fopen("hashedfile.txt","w");
	fptr3=fopen("allcrackpasswd.txt","w");
	if(fptr2==NULL||fptr3==NULL)
		{
		printf("OOPS!!!..error in file creation...");
		exit(0);
		}
	char eachrwtop[1000],eachpswd[1000],*hash;
	int time=0;
	while(fgets(eachrwtop,1000,fptr1))
		{
		char eachstr[1000],password[100];
		//printf("%s",eachrwtop);
		strcpy(eachstr,eachrwtop);
		int t=1;
		char *eachtoken=strtok(eachstr,"\t\n");
		while(eachtoken!=NULL)
			{
			if(t==4)
				{
				strcpy(password,eachtoken);
				//printf("%s",eachtoken);
				}
			eachtoken=strtok(NULL,"\t\n");
			t++;
			}
		hash=crypt(password,"$1$GC");
		fputs(hash,fptr2);
		fputs("\n",fptr2);		
		fptr4=fopen("passwordfile.txt","r");	 	
		if(fptr4==NULL)
			{
			printf("OOPS!!!..error in file opening...");
			exit(0);
			}
		while(fgets(eachpswd,1000,fptr4))
			{
			char temp[1000],strusername[1000],strtemp[1000];
			int count=1;
			strcpy(temp,eachpswd);
			char *eachtokenpswd=strtok(temp,":");
			while(eachtokenpswd!=NULL)
				{
				if(count==1)
					strcpy(strusername,eachtokenpswd);
				if(count==2)
					strcpy(strtemp,eachtokenpswd);
				eachtokenpswd=strtok(NULL,":");
				count++;
				}
			if(strcmp(strtemp,hash)==0)
				{
				printf("No-%d :Username-%s:Password-%s\n",time++,strusername,password);
				fputs(strusername,fptr3);
				fputs(":",fptr3);
				fputs(password,fptr3);
				fputs("\n",fptr3);
				}
			}
		//fclose(fptr1);
		fclose(fptr4);
		}
	end = clock();
     	time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
     	printf("Time taken:%f seconds",time_used);
	return 0;
	}

