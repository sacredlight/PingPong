#include<stdio.h>
#include<malloc.h>
#include<fcntl.h>
#include<string.h>

#define BUF_LEN 1000

char* getPath(char* str)
{
	int pos;
	char *temp;

	//Check if the first three character is GET
	temp=malloc(sizeof(char) * 4);
	strncpy(temp,str,3);
	temp[4]='\0';
	if(!(strcmp(temp,"GET")==0))
	{
		  printf("Violate HTTP Protocol, the first three character is not GET\n");
		  return 0;
	}
	free(temp);

	//Get the path by getting the string after GET and before a space
	str+=4;	  
	pos=strcspn(str," ");
	temp=malloc(sizeof(char) * (pos+1));
	strncpy(temp,str,pos);
	temp[pos+1]='\0';
	return temp;
}

char* getFile(char* root,char* path)
{
	int fd;
	int count;
	char *temp;

	temp=malloc(sizeof(char)*(strlen(root)+strlen(path)));
	strcat(temp,root);
	strcat(temp,path);
	fd = open(temp, O_RDONLY);
	count = read(fd, temp, BUF_LEN);
	temp[count] = '\0';
	return temp;

}

int main()
{

	char *s="GET /index.html HTTP/1.1 \r\n language Chinese \r\n\r\n";
	char *root=".";
	char *path;
	char *file;

	path=getPath(s);
	printf(path);
	printf("\n");
	file=getFile(root,path);
	printf(file);
	return 0;
}