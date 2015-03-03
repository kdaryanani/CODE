#include<fstream>
#include<stdio>
#include<ctype>
#include<string>
#include<iostream>
#include<conio>
void main()
{
              char c,u;
              char fname[10];
              clrscr();
              ofstream out;
              cin>>GettysburgAddress.txt;
              out.open(GettysburgAddress.txt);
              cout<<"Enter the text(Enter # at end)\n";   //write contents to file
              while((c=getchar())!='#')
              {
                            u=c-32;
                            out<<u;
              }
              out.close();
              ifstream in(fname);        //read the contents of file
              cout<<"\n\n\t\tThe File contains\n\n";
              while(in.eof()==0)
              {
                            in.get(c);
                            cout<<c;
              }
              getch();
 
}
