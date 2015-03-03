//Karan Daryanani, S Figueira, Lab 9, 2:15 Wednesday, Coen 11, 

#include "link.h"

int
main (int argc, char *argv[])
{
        int i;
        char zed[M];
        int y;
        char name3[M];
        char number3[M];

        for(i=0; i<26; i++)
        {
                head[i]=NULL;
        }

        if(argc == 1)
        {
                printf("No Such File.\n");
                return;
        }

        else
        {
                read_insert(argv[1]);
        }

        pthread_t thr;
        pthread_mutex_init(&mutex, NULL);
        pthread_create(&thr, NULL, bin_save, (void *) 5);

        for( ; ; )
        {


        printf("Welcome to your Phone Book. \n Press 1 to add a contact. \n Press 2 to delete a contact. \n Press 3 to list all entries. \n Press 4 to list all entries under a certain letter. \n Press 5 to close your Phone book. \n Press 6 to read binary file \n");

        scanf("%d", &y);

        switch(y)
        {
                case 1:
                        {
                                printf("Please enter the name \n");
                                scanf("%s", name3);

                                printf("Please enter the number\n");
                                scanf("%s", number3);
                                pthread_mutex_lock(&mutex);
                                input(name3, number3);
                                pthread_mutex_unlock(&mutex);
                                break;
                        }

                case 2:
                        {
                                pthread_mutex_lock(&mutex);
                                delete();
                                pthread_mutex_unlock(&mutex);
                                break;
                        }

                case 3: show();
                        break;

                case 4: letter();
                        break;

                case 5:
                        {
                                printf("Saving File.\n");
                                pthread_mutex_lock(&mutex);
                                save_file(argv[1]);
                                pthread_mutex_unlock(&mutex);
                                printf("Saved.\n");
                                return 0;
                        }

                case 6:
                        {
                                printf("Reading Binary File\n");
                                pthread_mutex_lock(&mutex);
                                bin_read(argv[2]);
                                pthread_mutex_unlock(&mutex);
                                break;

                        }
                default: return 0;
        }
        }
}

