#include "link.h"

void* bin_save(void* x)
{
        FILE *fp;
        PHONE *p;
        int i;

        while (1)
        {
                sleep(5);

                fp=fopen("binbook", "wb");
                for(i=0; i<26; i++)
                {
                        p=head[i];
                        while(p!=NULL)
                        {
                                fwrite(p, sizeof(PHONE), 1, fp);
                                p=p->next;
                        }
                }

                fclose(fp);
        }
}

void
save_file(char *book)
{
        FILE *fp;
        PHONE *p;
        int i;

        fp=fopen(book, "w");

        if(fp==NULL)
        {
                printf("Error with file \n");
                return;
        }

        fprintf(fp, "Name    Number\n");

        for(i=0; i<26; i++)
        {
                p=head[i];

                while(p!=NULL)
                {
                        fprintf(fp, "%s  %s \n", p->name, p->number);
                        p=p->next;
                }
        }
        fclose(fp);

        return;
}

void
read_insert(char *book)
{
        FILE *fp;
        char number5[M];
        char name5[M];

        fp=fopen(book, "r");

        if(fp==NULL)
        {
                printf("Error with file \n");
                return;
        }
        fseek(fp, 14, SEEK_SET);
        while(fscanf(fp, "%s  %s", name5, number5)==2)
        {
                input(name5, number5);
        }
        fclose(fp);
        return;
}

