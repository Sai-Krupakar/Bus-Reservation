#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
char fun1();
void login();
char admin[9]="TEAM26";
char Apin[5]="1234";
char USERNAME[9];
char PASSWORD[5];
char seat[10][3];
int Date[5]={0,0,0,0},D=0;
int main()
{  FILE*d;
   d=fopen("date.txt","r+");
   int date[6];
   while(fscanf(d,"%d",date)!=EOF)
   {   Date[D]=*date;
       D++; }
   fclose(d);
   login();
   do
    {   system("cls");
        printf("\n\n\t\t\t\t  WELCOME TO SAFE DRIVE TRAVELS");
        printf("\n\n\n\n\t\t\t\t  SEAT STRUCTURE IN OUR BUS\n\n");
        for(int i=0;i<10;i++)
        {   for(int j=0;j<3;j++)
            {   if(j==0)
                {
                    printf("\t\t\t\t|Seat(%d,%d)|    ",i,j);
                }
                else
                {
                    printf("|Seat(%d,%d)|",i,j);
                } }
            printf("\n\n"); }
        printf("\n\n\n\n");
     if(strcmp(USERNAME,admin)==0&&strcmp(PASSWORD,Apin)==0)
     {  printf("\t\t\t\t\t\t0.RESTART\n");
     }
        printf("\t\t\t\t\t\t1.VIEW BUS LIST\n");
        printf("\t\t\t\t\t\t2.BOOK TICKETS\n");
        printf("\t\t\t\t\t\t3.CANCEL TICKETS\n");
        printf("\t\t\t\t\t\t4.LOGOUT\n");
        printf("\t\t\t\t\t\tENTER YOUR CHOICE:");
     int var;
     scanf("%d", & var);
     system("cls");
     switch(var)
     { case 0:
              if(strcmp(USERNAME,admin)==0&&strcmp(PASSWORD,Apin)==0)
              {
                restart();
                break;
              }
              else
              {
                  exit(0);
              }
       case 1:
              buses();
              break;
       case 2:
              booking();
              break;
       case 3:
              cancel();
              break;
       case 4:
              exit(0);
              break;}
       getch();
       if(var==0)
        {
            break;
        }}while(1);
       return 0; }
void login()
{   FILE*ud;
    FILE*pd;
    ud=fopen("USERNAMES.txt","r+");
    pd=fopen("PASSWORDS.txt","r+");
    int ex;
    char newuser[9],newpass[5];
    system("cls");
    printf("\n\n\t\t\t\t\t\t1.NEW USER");
    printf("\n\t\t\t\t\t\t2.EXISTING USER");
    printf("\n\n\t\t\t\t\t\tENTER YOUR CHOICE:");
    scanf("%d",&ex);
    system("cls");
    switch(ex)
    { case 1:
        printf("\n\n\n\t\t\t\t\tCREATE YOUR LOGIN CREDENTIALS");
        printf("\n\n\t\t\t\t(USERNAME SHOULD BE MAXIMUM OF 8 CHARACTERS)");
        printf("\n\n\t\t\t\t\t\tUSERNAME:");
        scanf("%s",newuser);
        printf("\n\t\t\t\t(PASSWORD SHOULD CONTAIN 4 CHARACTERS)");
        printf("\n\n\t\t\t\t\t\tPASSWORD:");
        scanf("%s",newpass);
        FILE*nu;
        nu=fopen("USERNAMES.txt","a");
        fprintf(nu," %s",newuser);
        FILE*np;
        np=fopen("PASSWORDS.txt","a");
        fprintf(np," %s",newpass);
        fclose(np);
        fclose(nu);
        FILE*date;
        date=fopen("date.txt","r+");
        {
            fseek(date,10,SEEK_SET);
            fprintf(date,"%d",--Date[3]);
        }
        fclose(date);
       case 2:
          while(1)
          { rewind(ud);
            rewind(pd);
            system("cls");
            int u=Date[3];
            printf("\n\n\t\t\t\t                WELCOME \n\n");
            printf("\t\t\t\t  PLEASE ENTER YOUR LOGIN CREDENTIALS");
            printf("\n\n\n\t\t\t\t\tUSERNAME:");
            scanf("%s",USERNAME);
            printf("\n\t\t\t\t\tPASSWORD:");
            scanf("%s",PASSWORD);
            char tmp[12],tmpp[5];
            USERNAME[9]='\0';
            PASSWORD[4]='\0';
            if(strcmp(USERNAME,admin)==0&&strcmp(PASSWORD,Apin)==0)
            {    printf("\n\n\n\t\t\t\tYOUR LOGIN IS SUCCESSFUL");
                 printf("\n\n\t\t\t\tpress any key to continue....");
                 getch();
                 break;}
            else
            {    while(fscanf(ud,"%s",tmp)!=EOF && fscanf(pd,"%s",tmpp)!=EOF)
                 {   if(strcmp(USERNAME,tmp)==0&&strcmp(PASSWORD,tmpp)==0)
                     {   printf("\n\n\n\t\t\t\t\tYOUR LOGIN IS SUCCESSFUL");
                         printf("\n\n\t\t\t\t\tpress any key to continue....");
                         getch();
                         break;}
                     else
                    {
                     u=u+1;
                    } } }
    if(u>3)
    {   printf("\n\n\n\t\t\t\t\tLOGIN IS UNSUCCESSFUL\n\n");
        printf("\t\t\t\t   INCORRECT USERNAME OR PASSWORD\n\n");
        printf("\t\t\t\t\tPLEASE TRY AGAIN\n");
        getch();
        system("cls");}
    else
    {
        break;
    } }
    fclose(ud);
    fclose(pd);
    return; } }
void buses()
{   printf("\n\n\n\t\t\t\t\t'DHARWAD EXPRESS'");
    printf("\n\n\t\t\t\t\t  FROM-CHENNAI");
    printf("\n\t\t\t\t\t  TO-DHARWAD");
    printf("\n\n\t\t\t\t\tARRIVAL TIME-9:00");
    printf("\n\t\t\t\t\tDEPARTURE TIME-9:25");  }
void booking()
{   char mob[11];
    char c;
    int v=0,r=0,b=0;
    char seat[10][3];
    int i=0,j=0;
    FILE*f1;
    f1=fopen("bus.txt","r+");
    do
    { c=getc(f1);
      putchar(c);
      if(c == 86)
      {  seat[i][j]='V';
         v=v+1;
         if(j==0||j==1)
         {
           j++;
         }
         else if(j==2&&i<9)
         {
           i++;
           j=j-2;
         } }
      else if(c == 66)
      {  seat[i][j]='B';
         b=b+1;
         if(j==0||j==1)
         {
           j++;
         }
         else if(j==2&&i<9)
         {
           i++;
           j=j-2;
         } }
      else if(c==82)
      {  seat[i][j]='R';
         r=r+1;
         if(j==0||j==1)
         {
           j++;
         }
         else if(j==2&&i<9)
         {
           i++;
           j=j-2;
         } } }while(c!=EOF);
    fclose(f1);
    printf("\n\n\t\t\t\t\tNUMBER OF VACANT SEATS:%d\n",v);
    printf("\n\t\t\t\t\tNUMBER OF BOOKED SEATS:%d\n",b);
    printf("\n\t\t\t\t\tNUMBER OF RESERVED SEATS:%d\n\n",r);
    printf("\t\t\t\t\tpress any key to continue....\n");
    getch();
    printf("\n\n\n\t\t\t\t\tPLEASE ENTER YOUR MOBILE NUMBER:");
    scanf("%s",mob);
    int k,sn[k][2];
    printf("\n\t\t\t\t\t\tSELECT NUMBER OF SEATS :");//k = number of seats //
    scanf("%d", &k);
    while(1)
    {    int w=0,p,q;
         printf("\n\n\t\t\tSELECT SEAT NUMBERS(in format [first number(space)second number]) :\n");
        for(int l=1;l<k+1;l++)
        {  printf("\n\t\t\t\t\t\tSELECT SEAT FOR PERSON %d :", l);
           scanf("%d", &p);
           scanf("%d", &q);
           printf("\n\t\t\t\t\t\tSELECTED SEAT FOR PERSON %d : (%d,%d) ", l, p, q);
           if(seat[p][q]=='V')
           {  sn[l-1][0]= p;
              sn[l-1][1]= q;
              seat[p][q]= 'B'; }
           else
           { if(seat[p][q]=='B')
             {  printf("\n\n\t\t\t\t\tTHE SEAT SELECTED BY YOU IS ALREADY BOOKED");
                printf("\n\n\t\t\t\t\t\tPLEASE BOOK VACANT SEATS ONLY");
                printf("\n\n\t\t\t\t\t\t\tTRY AGAIN");
                if(l>1)
                 {
                   for(int i=0;i<l-1;i++)
                   {
                    seat[sn[i][0]][sn[i][1]] ='V';
                   } }
         w=w+1;
         break; }
             else
             { printf("\n\n\t\t\t\t\tTHE SEAT SELECTED BY YOU IS ALREADY RESERVED");
               printf("\n\n\t\t\t\t\t\tPLEASE BOOK VACANT SEATS ONLY");
               printf("\n\n\t\t\t\t\t\t\tTRY AGAIN");
               if(l>1)
               { for(int i=0;i<l-1;i++)
                 {
                   seat[sn[i][0]][sn[i][1]] ='V';
                 } }
          w=w+1;
          break; } }
    printf("\n\n"); }
    if(w==0)
    {
     break;
    } }
    printf("\n\n\t\t\t\tYOUR SEAT SELECTION IS SUCCESSFULLY COMPLETED\n");
    printf("\n\n\t\t\t\t\t\t1.CONFIRM");
    printf("\n\n\t\t\t\t\t\t2.CANCEL");
    printf("\n\n\t\t\t\tPRESS '1' TO CONFIRM YOUR SEAT OR '2' TO CANCEL YOUR SEAT:");
    int t;
    scanf("%d",&t);
    switch(t)
    { case 1:
         printf("\n\n\t\t\t\t\tYOUR SEAT BOOKING IS CONFIRMED");
         getch();
         break;
      case 2:
         exit(0); }
    system("cls");
    printf("\n\n\n\t\t\t\tYOUR SEAT INFO IS HERE =>\n\n");
    printf("\t\t\t\tNAME                :%s\n",USERNAME);
    printf("\t\t\t\tDATE OF JOURNEY     :%d/%d/%d\n",Date[0],Date[1],Date[2]);
    printf("\t\t\t\tFROM                :CHENNAI\n\t\t\t\tTO                  :DHARWAD\n");
    printf("\t\t\t\tARRIVAL TIME        :9:00\n\t\t\t\tDEPARTURE TIME      :9:25\n");
    printf("\t\t\t\tSEAT NUMBERS        :");
    for(int i=0;i<k;i++)
    {
     printf("(%d,%d)",sn[i][0],sn[i][1]);
    }
    printf("\n\t\t\t\tMOBILE              :%s\n",mob);
    printf("\t\t\t\tTOTAL BOOKING AMOUNT:%d\n\n\n\n",200*k);
    printf("\t\t\t\tTHANK YOU FOR CHOOSING US");
    FILE*F;
    F=fopen("bus.txt","w+");
    for(int i=0;i<10;i++)
    { for(int j=0;j<3;j++)
      { if(j==0)
        {
          fprintf(F,"\t\t\t\t|Seat(%d,%d)..%c|     ",i,j,seat[i][j]);
        }
        else
        {
          fprintf(F,"|Seat(%d,%d)..%c|",i,j,seat[i][j]);
        } }
     fprintf(F,"\n\n"); }
    fclose(F);
    FILE*fp;
    int s;
    char temp[20];
    fp=fopen("seatdata.txt","a");
    fprintf(fp,"%s ",USERNAME);
    for(int i=0;i<k;i++)
    {
     fprintf(fp," %d %d",sn[i][0],sn[i][1]);
    }
    fprintf(fp,",\n");
    fclose(fp);
 return; }
void cancel()
{  int P=0,Q=0,y=0,z=0;
   char un[20],temp[9];
   char c,ch;
   int s[30][2];
   FILE*user;
   user=fopen("seatdata.txt","r+");
   while(fscanf(user,"%s",un)!=EOF)
     {  if(strcmp(un,USERNAME)== 0)
         {   do
              { c=getc(user);
                if(c!=32)
                 {  if(Q==0&&c!=44)
                    {
                        s[P][Q]=c;
                        Q++;
                    }
                    else if(Q==1&&c!=44)
                    {
                         s[P][Q]=c;
                         P++;
                         Q--;
                    }
                 } }while(c!=44); } }
    fclose(user);
    for(int i=0;i<P;i++)
      {
        s[i][0]=s[i][0]-48;
        s[i][1]=s[i][1]-48;
      }
    int cs[30][2],s1[30][2],N,W=0,IN=0;
    printf("\n\n\n\t\t\tSELECT NUMBER OF SEATS THAT YOU WANT TO CANCEL:");
    scanf("%d",&N);
    printf("\n\n\t\t\tSELEECT THE SEAT NUMBERS THAT YOU WANT TO CANCEL:");
    for(int i=0;i<N;i++)
    {  scanf("%d%d",&cs[i][0],&cs[i][1]);
       for(int j=0;j<P;j++)
       {  if(cs[i][0]==s[j][0]&&cs[i][1]==s[j][1])
          {
             cs[i][0]=s[j][0];
             cs[i][1]=s[j][1];
             W++;
          } } }
    if(s[0][0]=='\0')
    {
      printf("\n\n\n\t\t\t\t\tYOU HAVE NOT BOOKED ANY SEAT");
    }
    else if(W<N)
    {
        printf("\n\n\n\t\t\t\t\tYOU HAVE NOT BOOKED THESE SEATS");
    }
    else if(W==N)
    { FILE*canc;
      canc=fopen("seatdata cancelled.txt","r+");
      while(fscanf(canc,"%s",temp)!=EOF)
      { if(strcmp(temp,USERNAME)==0)
        { do
         { ch=getc(canc);
           if(ch!=32)
           {  if(z==0&&ch!=44)
              {
               s1[y][z]=ch;
               z++;
              }
              else if(z==1&&ch!=44)
              {
                s1[y][z]=ch;
                y++;
                z++;
              }}}while(ch!=44);}}
              fclose(canc);
    for(int i=0;i<y;i++)
    {
      s1[i][0]=s1[i][0]-48;
      s1[i][1]=s1[i][1]-48;
    }
    for(int i=0;i<N;i++)
    { for(int j=0;j<y;j++)
       { if(s1[j][0]==cs[i][0]&&s1[j][1]==cs[i][1])
          { printf("\n\n\t\t\t\tYOU HAVE NOT BOOKED THESE SEATS");
            IN++;
          } }
          if(IN==1)
          {
              break;
          } }
    if(IN==0)
    { printf("\t\t\t\tNAME                :%s\n",USERNAME);
      printf("\t\t\t\tDATE OF JOURNEY     :%d/%d/%d\n",Date[0],Date[1],Date[2]);
      printf("\t\t\t\tFROM                :CHENNAI\n\t\t\t\tTO                  :DHARWAD\n");
      printf("\t\t\t\tARRIVAL TIME        :9:00\n\t\t\t\tDEPARTURE TIME      :9:25\n");
      printf("\t\t\t\tCANCELLED SEATS     :");
      for(int i=0;i<N;i++)
      {
        printf("(%d,%d) ",cs[i][0],cs[i][1]);
      }
      printf("\n\t\t\t\tAMOUNT REFUNDED     :%d\n\n\n\n",150*N);
      printf("\t\t\t\tSELECTED SEATS HAVE BEEN CANCELLED SUCCESSFULLY");
      FILE*canc;
      canc=fopen("seatdata cancelled.txt","a");
      fprintf(canc," %s ",USERNAME);
      for(int i=0;i<N;i++)
      {
        fprintf(canc,"%d %d ",cs[i][0],cs[i][1]);
      }
      fprintf(canc,",");
      fclose(canc);
      fun1(seat,cs,N); }}
      return; }
void restart()
{   system("cls");
    Date[0]=Date[0]+1;
    printf("\n\n\n\t\t\t\t\tRESTART COMPLETED");
    FILE*r;
    r=fopen("bus.txt","w+");
    for(int i=0;i<10;i++)
    { for(int j=0;j<3;j++)
      { if((i==0&&j==0)||(i==0&&j==1)||(i==0&&j==2)||(i==1&&j==0))
        { if(j==0)
          {
           fprintf(r,"\t\t\t\t|Seat(%d,%d)..%c|     ", i, j,'R');
          }
          else
          {
           fprintf(r,"|Seat(%d,%d)..%c|",i,j,'R');
          } }
        else
        {
          if(j==0)
          {
            fprintf(r,"\t\t\t\t|Seat(%d,%d)..%c|     ", i, j,'V');
          }
          else
          {
            fprintf(r,"|Seat(%d,%d)..%c|",i,j,'V');
          } } }
    fprintf(r,"\n\n"); }
    fclose(r);
    FILE*R;
    R=fopen("seatdata.txt","w");
    fclose(R);
    FILE*R1;
    R1=fopen("seatdata cancelled.txt","w+");
    fclose(R1);
    FILE*D;
    D=fopen("date.txt","w+");
    {
       fprintf(D,"%d %d %d %d",Date[0],Date[1],Date[2],Date[3]);
    } }
 char fun1(char *SEAT,int *S,int P)
{   char c;
    int i=0,j=0;
    FILE*f1;
    f1=fopen("bus.txt","r+");
    do
    {  c=getc(f1);
       if(c == 86)
       {  seat[i][j]='V';
          if(j==0||j==1)
          {
            j++;
          }
          else if(j==2&&i<9)
          {
            i++;
            j=j-2;
          } }
       else if(c == 66)
       {  int K=0;
          for(int C=0;C<2*P;C=C+2)
          { if(i == S[C]&&j==S[C+1])
            { K++;
              seat[i][j]='V';
              if(j==0||j==1)
              {
                j++;
              }
              else if(j==2&&i<9)
              {
                i++;
                j=j-2;
              } } }
          if(K==0)
          {
            seat[i][j]='B';
            if(j==0||j==1)
            {
              j++;
            }
            else if(j==2&&i<9)
            {
              i++;
              j=j-2;
            } } }
       else if(c==82)
       {  seat[i][j]='R';
          if(j==0||j==1)
          {
            j++;
          }
          else if(j==2&&i<9)
          {
            i++;
            j=j-2;
          } } }while(c!=EOF);
    fclose(f1);
    FILE*FP;
    FP=fopen("bus.txt","w+");
    for(int i=0;i<10;i++)
    { for(int j=0;j<3;j++)
      { if(j==0)
        {
          fprintf(FP,"\t\t\t\t|Seat(%d,%d)..%c|     ",i,j,seat[i][j]);
        }
        else
        {
          fprintf(FP,"|Seat(%d,%d)..%c|",i,j,seat[i][j]);
        } }
    fprintf(FP,"\n\n"); }
    fclose(FP);
}
