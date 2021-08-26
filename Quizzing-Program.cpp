#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include<process.h>
#include<iomanip.h>
#include<math.h>

char q[20][100],a1[20][40],a2[20][40],a3[20][40],a4[20][40],u[10][20],p[10][20],p1[20];
int i=0,j=0,k=0,l=0,m,n,ch,correct[10],marks[20],marks1[20];
void registration(char u[10][20],char p[10][20])
{int y=0,h;
 for(y=0;y<20;y++)
    {u[i][y]=0;
     p[i][y]=0;
     p1[y]=0;
    }
 int r=0;
 char c;
 u:cout<<"\t\tREGISTRATION\n";
 cout<<"\n\tUSERNAME:";
 gets(u[i]);
 for(h=0;h<i;h++)
    {if(strcmpi(u[h],u[i])==0)
       {cout<<"Username already exists.Please enter another name\n";
	getch();
	clrscr();
	goto u;
       }
    }
 cout<<"\n\tPASSWORD:";
 do
 {c=getch();
     if(int(c)!=13)
       {putchar('*');
	p[i][r]=c;
	r++;
       }
     else
       break;
    }
 while(int(c)!=13);

 x1:r=0;
    cout<<"\n\n\tRE-ENTER PASSWORD:";
    for(y=0;y<20;y++)
    {
     p1[y]=0;
    }

 do
   {c=getch();
     if(int(c)!=13)
       {putchar('*');
	p1[r]=c;
	r++;
       }
     else
       break;
   }
 while(int(c)!=13);
 getch();
 if(strcmp(p1,p[i])!=0)
    {cout<<"\n\tPasswords do not match.";
     cout<<"\n\tPlease re-enter the password";
     getch();
     goto x1;
    }
 ++i;
 clrscr();
}

void instructions()
{
 clrscr();
 cout<<"\n\t\tINSTRUCTIONS\n";
 cout<<"\n\t*The Quiz consists of 2 rounds-Qualifications and Finals\n";
 cout<<"\t*Firstly, the candidate has to register before he/she\n";
 cout<<"\t can take part in the Quiz\n";
 cout<<"\t*The Qualification round consist of 10 Questions \n";
 cout<<"\teach carrying 2 marks\n";
 cout<<"\t*The Finals consist of 8 Questions each carrying 3 marks\n";
 cout<<"\t*A person is needed to get atleast 15 Marks to participate\n";
 cout<<"\t in the finals\n";
 cout<<"\t*The scores will be posted in a separate in tabular column\n";
 getch();
}

void qualification(char q[20][100],char a1[20][40],char a2[20][40],char a3[20][40],char a4[20][40],int marks[20])
{int flag=0,a,e=0,z=0;
 char name[20],password[20],d;
 cout<<"\t\tQUALIFICATION ROUND\n\n";
 cout<<"\t\tLOGIN\n";
 x:for( z=0;z<20;z++)
      {name[z]=0;
       password[z]=0;
      }
 cout<<"\n\tUSERNAME:";
 gets(name);
 cout<<"\n\tPASSWORD:";
 e=0;
 do
    {d=getch();
     if(int(d)!=13)
       {putchar('*');
	password[e]=d;
	e++;
       }
     else
       break;
    }
 while(int(d)!=13);

 for(k=0;(k<i)&&(flag==0);++k)
    {if((strcmpi(name,u[k])==0)&&(strcmp(password,p[k])==0))
	{flag=1;
	 a=k;
	}
    }
 if(flag==0)
   {cout<<"Username or Password Invalid\n";
    getch();
    clrscr();
    goto x;
   }
 clrscr();

 for(k=0;k<10;++k)
    {b:cout<<"\n\n\t\tQUESTION NO:"<<k+1<<endl;
     cout<<"\n\t";
     puts(q[k]);
     cout<<"\tThe Options are:\n";
     cout<<"1)  ";puts(a1[k]);
     cout<<"2)  ";puts(a2[k]);
     cout<<"3)  ";puts(a3[k]);
     cout<<"4)  ";puts(a4[k]);
     cout<<"\tEnter your choice:";
     cin>>n;
     if((n>4)||(n<1))
       {cout<<"\n\tInvalid choice\n";
	getch();
	clrscr();
	goto b;
       }
     if(n==(correct[k]))
       {marks[a]+=2;
       }
     getch();
     clrscr();
    }
 if(marks[a]>=15)
   {marks[a]-=2;
    cout<<"\n\n\n\tYour marks:"<<marks[a]<<endl;
    cout<<"    Congratulations,You are selected for Finals\n";
   }
 else
   {cout<<"Your marks:"<<marks[a]<<endl;
    cout<<"Sorry,you are not selected for the Finals\n";
   }
 getch();
}
void finals(char q[20][100],char a1[20][40],char a2[20][40],char a3[20][40],char a4[20][40],int marks[20])
{int flag=0,a,e=0,z=0;
 char name[20],password[20],d;
 cout<<"\t\tTHE GRAND FINALS\n\n";
 cout<<"\t\tLOGIN\n";
 x:for( z=0;z<20;z++)
      {name[z]=0;
       password[z]=0;
      }
 cout<<"\n\tUSERNAME:";
 gets(name);
 cout<<"\n\tPASSWORD:";
 e=0;
 do
    {d=getch();
     if(int(d)!=13)
       {putchar('*');
	password[e]=d;
	e++;
       }
     else
       break;
    }
 while(int(d)!=13);
 for(k=0;(k<i)&&(flag==0);++k)
    {if((strcmpi(name,u[k])==0)&&(strcmp(password,p[k])==0))
	{flag=1;
	 a=k;
	 getch();
	}
    }
 if(flag==0)
   {cout<<"Username or Password Invalid\n";
    getch();
    clrscr();
    goto x;
   }
 if(marks[a]<15)
   {cout<<"\n\tYour Qualification Round Score:"<<marks[a]<<endl;
    cout<<"\n\tSorry ,You are not eligible to participate in the finals\n";
    getch();
   }
 else
   {clrscr();
    for(k=10;k<18;++k)
       {b:cout<<"\n\n\t\tQUESTION NO:"<<k-10+1<<endl;
	cout<<"\n\t";
	puts(q[k]);
	cout<<"\tThe Options are:\n";
	cout<<"1)  ";puts(a1[k]);
	cout<<"2)  ";puts(a2[k]);
	cout<<"3)  ";puts(a3[k]);
	cout<<"4)  ";puts(a4[k]);
	cout<<"\tEnter your choice:";
	cin>>n;
	if((n>4)||(n<1))
	{cout<<"\n\tInvalid choice\n";
	 getch();
	 clrscr();
	 goto b;
	}
	if(n==(correct[k]))
	  {marks1[a]+=3;
	  }
	getch();
	clrscr();
       }
    clrscr();
    marks1[a]+=3;
    cout<<"\n\n\n\tYour Grand Finals Marks:"<<marks1[a]<<endl;
    getch();
    if(marks1[a]<10)
      {cout<<"Your performance is Satisfactory.\n";
       cout<<"Better luck next time\n";
       getch();
      }
    else if((marks1[a]>=10)&&(marks1[a]<20))
	   {cout<<"You have done exceedingly well!!\n";
	    getch();
	   }
    else
	{cout<<"Excellent performance.\nKeep it up\n";
	 getch();
	}
   }
}
void score(char u[10][20],int marks[20],int marks1[20])
{cout<<"\n\tSCORES\n";
 cout<<"S.No.\tUsername\tQualification Scores\tFinal scores\n";
 for(j=0;j<i;++j)
    {cout<<j+1<<"\t";
     cout<<u[j]<<"\t\t\t";
     cout<<marks[j]<<"\t\t\t";
     if(marks[j]>=15)
       cout<<marks1[j];
     else
       cout<<"N.A";
     cout<<endl;
    }
 getch();
}
void main()
{clrscr();
 for(m=0;m<20;m++)
    {marks1[m]=0;
     marks[m]=0;
    }
 strcpy(q[0],"What is the botanical name of wheat?");
 strcpy(q[1],"What is the official language of Algeria?");
 strcpy(q[2],"What is the national sport of Croatia?");
 strcpy(q[3],"Which is capital city of South Africa?");
 strcpy(q[4],"Who is called the \" Frontier Gandhi \"?");
 strcpy(q[5],"Who was the 41st president of United States of America?");
 strcpy(q[6],"Who started Google?");
 strcpy(q[7],"Which is the Asian equivalent of Nobel Prize?");
 strcpy(q[8],"What is the basic monomer of Polythene?");
 strcpy(q[9],"Name the largest freshwater lake in the world?");
 strcpy(q[10],"Where would you find the sea of tranquillity?");
 strcpy(q[11],"What is the another name for lexicon?");
 strcpy(q[12],"Give the alternate name for a mountain ash tree");
 strcpy(q[13],"In Football who was nicknamed \'the divine ponytail\'?");
 strcpy(q[14],"What is John Leach famous for making?");
 strcpy(q[15],"When did the Vietnam war end?");
 strcpy(q[16],"Name the greatest reducing agent in inorganic reactions?");
 strcpy(q[17],"How many inches make up a foot?");
 strcpy(a1[0],"Triticum aestivum");
 strcpy(a2[0],"Oryza sativa");
 strcpy(a3[0],"Mangifera indica");
 strcpy(a4[0],"Psidium guajava");
 strcpy(a1[1],"English");
 strcpy(a2[1],"Persian");
 strcpy(a3[1],"Arabic");
 strcpy(a4[1],"Berber");
 strcpy(a1[2],"Volleyball");
 strcpy(a2[2],"Futsal");
 strcpy(a3[2],"Football");
 strcpy(a4[2],"Boxing");
 strcpy(a1[3],"Pretoria");
 strcpy(a2[3],"Bloemfontein");
 strcpy(a3[3],"Cape Town");
 strcpy(a4[3],"All of the above");
 strcpy(a1[4],"Khan Abdul Ghaffar Khan");
 strcpy(a2[4],"Maulana Abul Kalam Azad");
 strcpy(a3[4],"Mohammad Ali Jinnah");
 strcpy(a4[4],"Jawaharlal Nehru");
 strcpy(a1[5],"Ronald Reagan");
 strcpy(a2[5],"George H.W. Bush");
 strcpy(a3[5],"George W. Bush");
 strcpy(a4[5],"Bill Clinton");
 strcpy(a1[6],"Larry Page & Sergey Brin");
 strcpy(a2[6],"Eric Schmidt & John Battelle");
 strcpy(a3[6],"Sergey Brin & Eric Schmidt");
 strcpy(a4[6],"Andy Rubin & Vic Gundotra");
 strcpy(a1[7],"Ramon Magsaysay Award");
 strcpy(a2[7],"Pulitzer Prize");
 strcpy(a3[7],"International Gandhi Peace Prize");
 strcpy(a4[7],"Shanti Swarup Bhatnagar");
 strcpy(a1[8],"Methane");
 strcpy(a2[8],"Ethane");
 strcpy(a3[8],"Ethene");
 strcpy(a4[8],"Ethoxy Ethene");
 strcpy(a1[9],"Lake Superior");
 strcpy(a2[9],"Dal lake");
 strcpy(a3[9],"Lake Michigan");
 strcpy(a4[9],"Lake Ontario");
 strcpy(a1[10],"The earth");
 strcpy(a2[10],"The moon");
 strcpy(a3[10],"The mars");
 strcpy(a4[10],"The venus");
 strcpy(a1[11],"Dictionary");
 strcpy(a2[11],"Telegram");
 strcpy(a3[11],"Telephone");
 strcpy(a4[11],"Paper");
 strcpy(a1[12],"Tulpis");
 strcpy(a2[12],"Rowan");
 strcpy(a3[12],"Flowerdew");
 strcpy(a4[12],"Mundi");
 strcpy(a1[13],"Peter Beardsley");
 strcpy(a2[13],"Roberto Baggio");
 strcpy(a3[13],"Rocky Marciano");
 strcpy(a4[13],"Rudolf Nureyev");
 strcpy(a1[14],"Pottery");
 strcpy(a2[14],"Sculptures");
 strcpy(a3[14],"Tempera");
 strcpy(a4[14],"Colours");
 strcpy(a1[15],"1979");
 strcpy(a2[15],"1975");
 strcpy(a3[15],"1990");
 strcpy(a4[15],"1989");
 strcpy(a1[16],"Lithium");
 strcpy(a2[16],"Potassium");
 strcpy(a3[16],"Caesium");
 strcpy(a4[16],"Rubidium");
 strcpy(a1[17],"12");
 strcpy(a2[17],"13");
 strcpy(a3[17],"10");
 strcpy(a4[17],"8");
 correct[0]=1;
 correct[1]=3;
 correct[2]=3;
 correct[3]=4;
 correct[4]=1;
 correct[5]=2;
 correct[6]=1;
 correct[7]=1;
 correct[8]=3;
 correct[9]=1;
 correct[10]=2;
 correct[11]=1;
 correct[12]=2;
 correct[13]=2;
 correct[14]=1;
 correct[15]=2;
 correct[16]=1;
 correct[17]=1;
 a:clrscr();
 cout<<"\n\t\t\t NATIONAL QUIZ CHALLENGE   \n";
 cout<<"\t\t\t         DASHBOARD       \n";
 cout<<"\n\n\t\t1.INSTRUCTIONS    \n";
 cout<<"\t\t2.REGISTRATION\n";
 cout<<"\t\t3.QUALIFICATION\n";
 cout<<"\t\t4.FINALS\n";
 cout<<"\t\t5.SCORES\n";
 cout<<"\t\t6.EXIT THE DASHBOARD\n";
 cout<<"\n\nEnter the choice\n";
 cin>>ch;
 clrscr();
 switch(ch)
       {case 1:{instructions();
		getch();
		goto a;
	       }
	case 2:{ registration(u,p);
		 goto a;
	       }
	case 3:{ qualification(q,a1,a2,a3,a4,marks);
		 goto a;
	       }
	case 4:{ finals(q,a1,a2,a3,a4,marks);
		 goto a;
	       }
	case 5:{ score(u,marks,marks1);
		 goto a;
	       }
	case 6:{ exit(0);
		 getch();
	       }
	default:{cout<<"Please enter a valid choice\n";
		 goto a;
		}
       }
}



