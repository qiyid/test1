#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"
int help();
int quit();
#define CMD_MAX_LEN   128
#define CMD_NUM       10
#define CMD_DESC      1024
static tDataNode head[] = 
{
{"help","This is help cmd!",help,&head[1]},
{"version","Menu version 1.0 - 2015.10.01",NULL,&head[2]},
{"quit","Quit from meun!",quit,NULL}
};
int main()
{
while(1)
{
    char cmd[CMD_MAX_LEN];
    printf("Input a command:\n");
    scanf("%s",cmd);
    tDataNode* p = FindCmd(head,cmd);
    if( p == NULL)
    {    
        printf("Command not exit!\n");
        continue;
    }
    printf("%s - %s\n",p->cmd,p->desc);
    if( p->handler !=NULL)
    {
        p->handler();
    }  
}
return 0; 
}
int help()
{
ShowAllCmd(head);
return 0;
}
int quit()
{
printf("Bye-bye!\n");
exit(0);
}
