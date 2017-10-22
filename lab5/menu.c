int SearchCondition(tLinkTableNode * pLinkTableNode,char * cmd)
{
    tDataNode * pNode = (tDataNode *)pLinkTableNode;
    printf("%s\n",pNode->cmd);
    if(strcmp(pNode->cmd, cmd) == 0)
    {
    printf("cmd is ok!\n");
        return  SUCCESS;  
    }
    printf("cmd is fault!\n");
    return FAILURE;           
}

/* find a cmd in the linklist and return the datanode pointer */
tDataNode* FindCmd(tLinkTable * head, char * cmd)
{
    return  (tDataNode*)SearchLinkTableNode(head,SearchCondition,cmd);
}

/* menu program */
tLinkTable * head = NULL;
int main()
{
    InitMenuData(&head); 
   /* cmd line begins */
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a cmd number > ");
        scanf("%s", cmd);
        tDataNode *p = FindCmd(head, cmd);
        if( p == NULL)
        {
            printf("This is a wrong cmd!\n ");
            continue;
        }
        printf("%s - %s\n", p->cmd, p->desc); 
        if(p->handler != NULL) 
        { 
            p->handler();
        }

    }
}
