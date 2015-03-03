#include "link.h"


int
input (char name1[M], char number2[M])
{

        int i;
        int x;
        PHONE *list, * tlist, *temp;
        tlist = (PHONE *)malloc(sizeof(PHONE));
        strcpy (tlist->name, name1);
        strcpy (tlist->number, number2);


        for(i=0; i<26; i++)
        {
                list=head[i];
        }

        x=tlist->name[0]-'a';
        list=head[x];

        if(head[x]==NULL)
        {
                head[x]=tlist;
                return;
        }
        while (list!=NULL)
        {
                if (strcmp(tlist->name, list->name)==0)
                {
                        printf("No Duplicates Allowed\n");
                        return;
                }

                else if (strcmp(tlist->name, list->name)<0)
                        break;
                temp=list;
                list=list->next;
        }
        if (list==head[x])
        {
                tlist->next=head[x];
                head[x]=tlist;
        }
        else if(list==NULL)
        {
                temp->next=tlist;
                tlist->next=NULL;
                //tail2=tlist;
        }
        else
        {
                temp->next=tlist;
                tlist->next=list;
        }
}


int
delete()
{
        PHONE *xprev;
        PHONE *xnext;
        PHONE *xname;
        int x;

        xname=(PHONE *)malloc(sizeof(PHONE));

        printf("What name would you like to delete? \n");
        scanf("%s", xname->name);

        x=xname->name[0]-'a';
        xname=head[x];

        if(head==NULL)
        {
                printf("You have no friends. \n");
                return;
        }
        if (strcmp(head[x]->name, xname->name)==0)
        {
                head[x] = head[x]->next;
                return;
        }
        xprev=head[x];
        xnext=head[x]->next;

        while(xnext!=NULL)
        {
                if(strcmp(xnext->name, xname->name)==0)
                {
                        xprev->next=xnext->next;
                        return;
                }
                xprev=xnext;
                xnext=xnext->next;
        }
        if(xnext == NULL)
                printf("No Such name found!\n");
}


int
show()
{
        PHONE *p;
        int k;

        for(k=0; k<26; k++)
        {
                p=head[k];
                while(p!=NULL)
                {
                        printf("%s %s\n", p->name, p->number);
                        p = p->next;
                }
        }
}

int
letter()
{
        PHONE *p;
        char y;
        int z;
        printf("What letter would you like to display?\n");
        scanf("%c", &y);
        scanf("%c", &y);
        z=y-'a';
        p=head[z];
        while(p!=NULL)
        {
                printf("%s %s \n", p->name, p->number);
                p = p->next;
        }
}

void
bin_read(char *binbook)
{
        FILE *fp;
        PHONE temp;
        int i;

        fp=fopen("binbook", "rb");

        if(fp==NULL)
        {
                printf("Error with file \n");
                return;
        }

        while((fread(&temp, sizeof(PHONE),1,fp))>0)
        {
                printf("%s  %s \n", temp.name, temp.number);
        }

        fclose(fp);
        return;
}



