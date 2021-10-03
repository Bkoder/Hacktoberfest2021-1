
 //*******************************************
                 
 //*******************************************

 //*******************************************
 //   INCLUDED HEADER FILES                  
 //*******************************************

   #include<iostream.h>
   #include<fstream.h>
   #include<process.h>
   #include<string.h>
   #include<stdlib.h>
   #include<stdio.h>
   #include<ctype.h>
   #include<conio.h>
   #include<dos.h>

 //*******************************************
 //      THIS CLASS CONTAINS ALL             *
 //      THE DRAWINNG FUNCTIONS              *
 //*******************************************
 class LINES
  {
    public:
	   void LINE_HOR(int,int,int,char);
	   void LINE_VER(int,int,int,char);
	   void BOX(int,int,int,int,char);
	   void CLEARUP(void);
	   void CLEARDOWN(void);
   };

 //*******************************************
 //      THIS CLASS CONTROLS ALL             *
 //      THE FUNCTIONS IN THE MENU           *
 //*******************************************
 class MENU
  {
    private:
	   void EDIT_MENU(void);
	   void INTRODUCTION(void);
    public:
	   void MAIN_MENU(void);
  };
 //*******************************************
 //    THIS CLASS CONTROLS ALL               *
 //    THE FUNCTIONS RELATED TO EMPLOYEE     *
 //*******************************************
 class EMPLOYEE
  {
    private:
	   void ADD_RECORD(int,char[],char[],char[],int,int,int,
	   char[],char,char,char,float,float);
	   void MODIFY_RECORD(int,char[],char[],char[],char[],char,
	   char,char,float,float);
	   void DELETE_RECORD(int);
	   int LASTCODE(void);
	   int CODEFOUND(int);
	   int RECORDNO(int);
	   int FOUND_CODE(int);
	   void DISPLAY_RECORD(int);
	   int VALID_DATE(int,int,int);
	   int code,dd,mm,yy;
	   char name[26],address[31],phone[10],desig[16];
	   char grade,house,convense;
	   float loan,basic;
    public:
	   void NEW_EMPLOYEE(void);
	   void MODIFICATION(void);
	   void DELETION(void);
	   void DISPLAY(void);
	   void LIST(void);
	   void SALARY_SLIP(void);

  };
 //*******************************************
 //    THIS FUNCTION CONTROLS ALL            *
 //    THE FUNCTIONS IN THE MAIN MENU        *
 //*******************************************
 void MENU::MAIN_MENU(void)
  {
    char ch;
    LINES L;
    L.CLEARUP();
    while(1)
     {
      clrscr();
      L.BOX(28,7,51,9,218);
      L.BOX(10,5,71,21,218);
      L.BOX(11,6,70,20,219);
      gotoxy(29,8);
      cout<<"EDVIS PVT.LTD.";
      gotoxy(30,11);
      cout<<"1:NEW EMPLOYEE";
      gotoxy(30,12);
      cout<<"2:DISPLAY EMPLOYEE";
      gotoxy (30,13);
      cout<<"3:LIST OF EMPLOYEES";
      gotoxy(30,14);
      cout<<"4:SALARY SLIP";
      gotoxy(30,15);
      cout<<"5:EDIT";
      gotoxy(30,16);
      cout<<"0:QUIT";
      gotoxy(30,18);
      cout<<"ENTER YOUR CHOICE:";
      ch = getch();
      if (ch == 27 || ch == '0')
	break;
      else
	if(ch == '1')
	 {
	   EMPLOYEE E;
	   E.NEW_EMPLOYEE();
	 }//end of if
	else
	   if(ch == '2')
	    {
	      EMPLOYEE E;
	      E.DISPLAY();
	    }//end of if
	   else
	    if (ch == '3')
	     {
	       EMPLOYEE E;
	       E.LIST();
	     }//end of if
	    else
	     if (ch == '4')
	      {
		EMPLOYEE E;
		E.SALARY_SLIP();
	      }//end of if
	     else
	      if (ch == '5')
		EDIT_MENU();
     }//end of while
    L.CLEARUP();
  }
 //*******************************************
 //    THIS FUNCTION CONTROLS ALL            *
 //    THE  FUNCTIONS IN THE EDIT MENU       *
 //*******************************************
 void MENU :: EDIT_MENU(void)
  {
    char ch;
    LINES L;
    L.CLEARDOWN();
    while (1)
     {
       clrscr();
       L.BOX(28,4,49,10,218);
       L.BOX(10,5,71,21,218);
       L.BOX(11,6,70,20,219);
       gotoxy(31,9);
       cout<<"E D I T   M E N U";
       gotoxy(30,13);
       cout<<"1: DELETE RECORD";
       gotoxy(30,14);
       cout<<"2: MODIFY RECORD";
       gotoxy(30,15);
       cout<<"0: EXIT";
       gotoxy(30,17);
       cout<<"ENTER YOUR CHOICE:";
       ch = getch();
       if (ch == 27 || ch == '0')
	 break;
       else
	if  (ch == '1')
	 {
	   EMPLOYEE E;
	   E.DELETION();
	 }
	else
	 if(ch == '2')
	  {
	    EMPLOYEE E;
	    E.MODIFICATION();
	  }
     }//end of while
    L.CLEARDOWN();
  }
 //*******************************************
 //    THIS FUNCTION DRAWS                   *
 //    THE HORIZONTAL LINE                   *
 //*******************************************
 void LINES ::LINE_HOR(int column1, int column2, int row, char c)
  {
   for(column1; column1<=column2; column1++)
    {
     gotoxy(column1,row);
     cout<<c;
    }//end of for
  }
 //*******************************************
 //    THIS FUNCTION DRAWS                   *
 //    THE VERTICAL LINE                     *
 //*******************************************
 void LINES ::LINE_VER(int row1, int row2, int column, char c)
  {
    for(row1; row1<=row2; row1++)
     {
      gotoxy(column,row1);
      cout<<c;
     }//end of for
  }
 //*******************************************
 //    THIS FUNCTION DRAWS                   *
 //    THE BOX                               *
 //*******************************************
 void LINES ::BOX(int column1, int row1,int column2, int row2, char c)
  {
    char ch=218;
    char c1, c2, c3, c4;
    char l1=196, l2=179;
    if(c == ch)
     {
       c1=218;
       c2=191;
       c3=192;
       c4=217;
       l1 = 196;
       l2 = 179;
     }//end of if
    else
     {
       c1=c;
       c2=c;
       c3=c;
       c4=c;
       l1 = c;
       l2 = c;
     }//end of else
    gotoxy(column1,row1);
    cout<<c1;
    gotoxy(column2,row1);
    cout<<c2;
    gotoxy(column1,row2);
    cout<<c3;
    gotoxy(column2,row2);
    cout<<c4;
    column1++;
    column2--;
    LINE_HOR(column1,column2,row1,l1);
    LINE_HOR(column1,column2,row2,l1);
    column1--;
    column2++;
    row1++;
    row2--;
    LINE_VER(row1,row2,column1,l2);
    LINE_VER(row1,row2,column2,l2);
  }
 //********************************************
 //     THIS FUNCTION CLEARS                  *
 //     THE SCREEN LINE BY LINE UPWARD        *
 //********************************************
 void LINES::CLEARUP(void)
  {
    for (int i=25;i>=1; i--)
     {
       delay(20);
       gotoxy(1,i); clreol();
     }//end of for
  }
 //********************************************
 //     THIS FUNCTION CLEARS THE              *
 //     SCREEN LINE BY LINE DOWNWORD          *
 //********************************************
 void LINES :: CLEARDOWN(void)
  {
    for (int i=1; i<=25; i++)
     {
       delay(20);
       gotoxy(1,i); clreol();
     } //end of for
  }
 //*******************************************
 //    THIS FUNCTION ADDS THE                *
 //    GIVEN DATA IN THE EMPLOYEE'S FILE     *
 //*******************************************
 void EMPLOYEE::ADD_RECORD(int ecode, char ename[26],
 char eaddress[31], char ephone[10],int d, int m,int y,
 char edesig[16],char egrade, char ehouse,char econv,
 float eloan, float ebasic)
  {
    fstream file;
    file.open("EMPLOYEE.DAT",ios::app);
    code=ecode;
    strcpy(name,ename);
    strcpy(address,eaddress);
    strcpy(phone,ephone);
    dd=d;
    mm=m;
    yy=y;
    strcpy(desig,edesig);
    grade=egrade;
    house=ehouse;
    convense=econv;
    loan=eloan;
    basic=ebasic;
    file.write((char*)this,sizeof(EMPLOYEE));
    file.close();
  }
 //*******************************************
 //    THIS FUNCTION MODIFIES THE            *
 //    GIVEN DATA IN THE EMPLOYEE'S FILE     *
 //*******************************************

 void EMPLOYEE::MODIFY_RECORD(int ecode, char ename[26],
 char eaddress[31],char ephone[10],  char edesig[16],
 char egrade,char ehouse,char econv,float eloan,
 float ebasic)
  {
    int recno;
    recno=RECORDNO(ecode);
    fstream file;
    file.open("EMPLOYEE.DAT",ios::out | ios::ate);
    strcpy(name,ename);
    strcpy(address,eaddress);
    strcpy(phone,ephone);
    strcpy(desig,edesig);
    grade=egrade;
    house=ehouse;
    convense=econv;
    loan=eloan;
    basic=ebasic;
    int location;
    location=(recno-1) * sizeof(EMPLOYEE);
    file.seekp(location);
    file.write((char*) this,sizeof(EMPLOYEE));
    file.close();
  }
 //*******************************************
 // THIS FUNCTION DELETES THE RECORD         *
 // IN THE EMPLOYEE FILE FOR                 *
 // THE GIVEN EMPLOYEE CODE                  *
 //*******************************************
 void EMPLOYEE::DELETE_RECORD(int ecode)
  {
    fstream file;
    file.open("EMPLOYEE.DAT",ios::in);
    fstream temp;
    temp.open("temp.dat",ios::out);
    file.seekg(0,ios::beg);
    while (!file.eof())
     {
       file.read((char *)this, sizeof(EMPLOYEE));
       if (file.eof())
       break;
       if (code !=ecode)
       temp.write((char *) this, sizeof(EMPLOYEE));
     }
    file.close();
    temp.close();
    file.open("EMPLOYEE.DAT", ios::out);
    temp.open("temp.dat",ios::in);
    temp.seekg(0,ios::beg);
    while (!temp.eof())
     {
       temp.read((char *) this, sizeof(EMPLOYEE));
       if (temp.eof())
       break;
       file.write((char *) this, sizeof(EMPLOYEE));
     }
    file.close();
    temp.close();
  }
 //*******************************************
 //    THIS FUNCTION RETURNS THE             *
 //    LAST EMPLOYEE'S CODE                  *
 //*******************************************
 int EMPLOYEE :: LASTCODE(void)
  {
    fstream file;
    file.open("EMPLOYEE.DAT", ios::in);
    file.seekg(0,ios::beg);
    int count=0;
    while (file.read((char*) this, sizeof(EMPLOYEE)))
      count = code;
    file.close();
    return count;
  }

 //*******************************************
 //    THIS FUNCTION RETURNS 0               *
 //    IF THE GIVEN CODE NOT FOUND           *
 //*******************************************
 int EMPLOYEE:: FOUND_CODE(int ecode)
  {
    fstream file;
    file.open("EMPLOYEE.DAT", ios::in);
    file.seekg(0,ios::beg);
    int found=0;
    while (file.read((char *) this, sizeof(EMPLOYEE)))
     {
       if (code == ecode)
	{
	  found =1;
	  break;
	}
     }
    file.close();
    return found;
  }

 //*******************************************
 //    THIS FUNCTION RETURNS                 *
 //    RECORD NO. OF THE GIVEN CODE          *
 //*******************************************
 int EMPLOYEE:: RECORDNO(int ecode)
  {
    fstream file;
    file.open("EMPLOYEE.DAT" , ios::in);
    file.seekg(0,ios::beg);
    int recno=0;
    while (file.read((char *) this, sizeof(EMPLOYEE)))
     {
       recno++;
       if (code == ecode)
       break;
     }
    file.close();
    return recno;
  }

 //*******************************************
 //    THIS FUNCTION DISPLAYS                *
 //    THE LIST OF THE EMPLOYEES             *
 //*******************************************
 void EMPLOYEE :: LIST(void)
  {
    clrscr();
    int row = 6, found=0, flag=0;
    char ch;
    gotoxy(31,2);
    cout<<"LIST OF EMPLOYEES";
    gotoxy(30,3);
    cout<<"~~~~~~~~~~~~~~~~~";
    gotoxy(1,4);
    cout<<"CODE  NAME                 PHONE NUMBER    DATE  DESIGNATION    GRADE  SALARY";
    gotoxy(1,5);
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    fstream file;
    file.open("EMPLOYEE.DAT" ,  ios::in);
    file.seekg(0,ios::beg);
    while (file.read((char *) this ,sizeof (EMPLOYEE)))
     {
       flag = 0;
       delay(20);
       found = 1;
       gotoxy(2,row);
       cout<<code;
       gotoxy(6,row);
       cout<<name;
       gotoxy(31,row);
       cout<<phone;
       gotoxy(40,row);
       cout<<dd <<"/" <<mm <<"/" <<yy;
       gotoxy(52,row);
       cout<<desig;
       gotoxy(69,row);
       cout<<grade;
       if (grade != 'E')
	{
	   gotoxy(74,row);
	   cout<<basic;
	}
       else
	{
	   gotoxy(76,row);
	   cout<<"-";
	}
       if (row == 23)
	 {
	   flag = 1;
	   row = 6;
	   gotoxy(1,25);
	   cout<<"Press any key to continue or <ESC> to enter";
	   ch = getch();
	   if (ch == 27)
	   break;
	   clrscr();
	   gotoxy(31,2);
	   cout<<"LIST OF EMPLOYEES";
	   gotoxy(30,3);
	   cout<<"~~~~~~~~~~~~~~~~~~~~";
	   gotoxy(1,4);
	   cout<<"    CODE NAME        PHONE DOJ		 DESIGNATION   GRADE SALARY";
	   gotoxy(1,5);
	   cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	 }
	else
	row++;
     }
    if (!found)
     {
       gotoxy(5,10);
       cout<<"\7Records not found";
     }
    if (!flag)
     {
       gotoxy(1,25);
       cout<<"Press any key to continue....";
       getche();
     }
    file.close ();
  }
 //*******************************************
 //    THIS FUNCTION DISPLAYS THE            *
 //    RECORD OF THE EMPLOYEES               *
 //*******************************************
 void EMPLOYEE :: DISPLAY_RECORD(int ecode)
  {
    fstream file;
    file.open("EMPLOYEE.DAT",  ios::in);
    file.seekg(0,ios::beg);
    while (file.read((char *) this, sizeof(EMPLOYEE)))
     {
       if (code == ecode)
	{
	  gotoxy(5,5);
	  cout<<"EMPLOYEE CODE #" <<code;
	  gotoxy(5,6);
	  cout<<"~~~~~~~~~~~~~~~~~~~~";
	  gotoxy(5,7);
	  cout<<"NAME       :"<<name;
	  gotoxy(5,8);
	  cout<<"ADDRESS    :"<<address;
	  gotoxy(5,9);
	  cout<<"PHONE NO.  :"<<phone;
	  gotoxy(5,11);
	  cout<<"JOINING DATE  :";
	  gotoxy(5,12);
	  cout<<"~~~~~~~~~~~~~";
	  gotoxy(5,13);
	  cout<<"DAY  :"<<dd;
	  gotoxy(5,14);
	  cout<<"MONTH  :"<<mm;
	  gotoxy(5,15);
	  cout<<"YEAR  :"<<yy;
	  gotoxy(5,17);
	  cout<<" DESIGNATION  :"<<desig;
	  gotoxy(5,18);
	  cout<<"GRADE     :"<<grade;
	  if (grade != 'E')
	   {
	    gotoxy(5,19);
	    cout<<"HOUSE LOAN ALLOWANCE  (Y/N) :"<<house;
	    gotoxy(5,20);
	    cout<<"CONVEYANCE LOAN ALLOWANCE (Y/N) :"<<convense;
	    gotoxy(5,22);
	    cout<<"BASIC SALARY   :"<<basic;
	   }
	  gotoxy(5,21);
	  cout<<"LOAN   :"<<loan;
	}
     }
    file.close();
  }
 //*******************************************
 //    THIS FUNCTION GIVES THE               *
 //    DATA TO ADD IN THE FILE               *
 //*******************************************
 void EMPLOYEE ::NEW_EMPLOYEE(void)
  {
    clrscr();
    char ch, egrade, ehouse='N', econv='N';
    char ename[26], eaddress[31], ephone[10];
    char edesig[16], t1[10];
    float t2=0.0, eloan=0.0, ebasic=0.0;
    int d, m, y, ecode, valid;
    gotoxy(72,2);
    cout<<"<0>=EXIT";
    gotoxy(28,3);
    cout<<"ADDITION OF NEW EMPLOYEE";
    gotoxy(5,5);
    cout<<"EMPLOYEE CODE #";
    gotoxy(5,6);
    cout<<"~~~~~~~~~~~~~~~~~~";
    gotoxy(5,7);
    cout<<"NAME     :";
    gotoxy(5,8);
    cout<<"ADDRESS  :";
    gotoxy(5,9);
    cout<<"PHONE NO.:";
    gotoxy(5,11);
    cout<<"JOINING DATE";
    gotoxy(5,12);
    cout<<"~~~~~~~~~~~~~~";
    gotoxy(5,13);
    cout<<"DAY    :";
    gotoxy(5,14);
    cout<<"MONTH  :";
    gotoxy(5,15);
    cout<<"YEAR   :";
    gotoxy(5,17);
    cout<<"DESIGNATION   :" ;
    gotoxy(5,18);
    cout<<"GRADE     :";
    gotoxy(5,21);
    cout<<"LOAN     :";
    ecode = LASTCODE() + 1;
 /*   if(ecode==1)
     {
       ADD_RECORD(ecode, "NULL", "NULL", "NULL",
       0, 0, 0, "NULL", 'n', 'n','n',0.0, 0.0);
       DELETE_RECORD(ecode);
     }*/
    gotoxy(21,5);
    cout<<ecode;
    do
     {
       valid = 1;
       gotoxy(5,25); clreol();
       cout<<"ENTER THE NAME OF THE EMPLOYEES: ";
       gotoxy(20,7); clreol();
       gets(ename);
       strupr(ename);
       if (ename[0] == '0')
	  return;
       if (strlen(ename) <1 || strlen(ename) > 25)
	{
	  valid = 0;
	  gotoxy(5,25); clreol();
	  cout<<"\7 ENTER CORRECTLY (RANGE: 1..25)";
	  getch();
	} //end of if
     } while (!valid);         //end of lst while
    do
     {
       valid = 1;
       gotoxy(5,25); clreol();
       cout<<"ENTER ADDRESS OF THE EMPLOYEE";
       gotoxy(20,8);
       clreol();
       gets(eaddress);
       strupr(eaddress);
       if (eaddress[0] == '0')
       return;
       if(strlen(eaddress) < 1 || strlen(eaddress) > 40)
	{
	  valid = 0;
	  gotoxy(5,25); clreol();
	  cout<<"\7 Enter correctly (Range :1..40)";
	  getch();
	}
     } while(!valid) ;
    do
     {
       valid=1 ;
       gotoxy(5,25);
       clreol();
       cout<<"ENTER THE PHONE NO. OF THE EMPLOYEE OR PRESS <ENTER> FOR NO CHANGE";
       gotoxy(20,9);clreol();
       gets(ephone) ;
       if(ephone[0]=='0')
	  return ;
       if((strlen(ephone)  < 7&& strlen(ephone)  >0)|| (strlen(ephone) >9))
	{
	  valid =0;
	  gotoxy(5,25);
	  clreol();
	  cout<<"\7Enter correctly";
	  getch();
	}//END OF IF
     } while (!valid);//end of 2nd while
    if (strlen (ephone) == 0)
	strcpy(ephone, "-");
    char tday[3], tmonth[3], tyear[5];
    int td,tm;
    do
     {
       valid = 1;
       do
	{
	  gotoxy(5,25); clreol();
	  cout<<"ENTER DATE OF JOINING";
	  gotoxy(13,13); clreol();
	  gets(tday);
	  td = atoi(tday);
	  d = td;
	  if (tday[0] == '0')
	     return;
	} while (d == 0); // end of 3rd while
       do
	{
	  gotoxy(5,25); clreol;
	  cout<<"ENTER MONTH OF JOINING";
	  gotoxy(13,14); clreol;
	  gets (tmonth);
	  tm = atoi(tmonth);
	  m = tm;
	  if (tmonth[0] == '0')
	     return;
	} while (m == 0);// end of 4th while
       do
	{
	  gotoxy(5,25); clreol();
	  cout<<"ENTER YEAR OF JOINING";
	  gotoxy(13,15); clreol();
	  gets(tyear);
	  td = atoi(tyear);
	  y = td;
	  if(tyear[0] == '0')
	  return;
	} while (y == 0); //end of 5th while
       if(d>31 || d<1)
	valid = 0;
       else
	if (((y%4) !=0 && m==2 && d>28) || ((y%4) ==0 && m==2 && d>29))
	 valid =0;
	else
	 if((m==4 || m==6 || m==9 ||m==11) && (d>30))
	  valid =0;
	 else
	  if(y<1970 || y>2020)
	   valid=0;
	  if (!valid)
	   {
	    valid = 0;
	    gotoxy(5,25);
	    clreol();
	    cout<<"\7 ENTER CORRECTLY";
	    getch();
	    gotoxy(13,14); clreol();
	    gotoxy(13,15); clreol();
	   }
     } while (!valid);
    do
     {
       valid = 1;
       gotoxy(5,25); clreol();
       cout<<"ENTER DESIGNATION OF THE EMPLOYEE";
       gotoxy(20,17); clreol();
       gets(edesig);
       strupr(edesig);
       if (edesig[0] == '0')
	 return;
       if (strlen(edesig) < 1 || strlen(edesig) >25)
	{
	  valid = 0;
	  gotoxy(5,25); clreol();
	  cout<<"\7ENTER CORRECTLY (RANGE: 1...25)";
	  getch();
	 }
     } while (!valid);
    do
     {
       gotoxy(5,25); clreol ();
       cout<<"ENTER GRADE OF THE EMPLOYEE (A,B,C,D,E)";
       gotoxy(20,18); clreol();
       egrade = getche();
       egrade = toupper(egrade);
       if (egrade == '0')
	return;
     } while (egrade < 'A' || egrade > 'E');
    if (egrade != 'E')
     {
       gotoxy(5,19);
       cout<<"HOUSE LOAN (Y/N) :";
       gotoxy(5,20);
       cout<<"CONVEYANCE LOAN (Y/N)  :";
       gotoxy(5,22);
       cout<<"BASIC SALARY  :";
       do
	{
	  gotoxy(5,25);clreol();
	  cout<<"ENTER IF HOUSE ALLOWANCE IS";
	  cout<<"ALLOTED TO EMPLOYEE OR NOT: ";
	  gotoxy(22,19); clreol();
	  ehouse = getche();
	  ehouse = toupper(ehouse);
	  if (ehouse  == '0')
	     return;
	} while (ehouse != 'Y' && ehouse != 'N');
       do
	{
	  gotoxy(5,25); clreol();
	  cout<<"ENTER IF CONVEYANCE ALLOWANCE IS";
	  cout<<"ALLOTED TO EMPLOYEE OR NOT";
	  gotoxy(22,20); clreol();
	  econv = getche();
	  econv = toupper(econv);
	  if (econv == '0')
	    return;
	} while (econv != 'Y' && econv != 'N');
     }//end of if
    do
     {
       valid = 1;
       gotoxy(5,25); clreol();
       cout<<"ENTER LOAN AMOUNT IF ISSUED";
       gotoxy(22,21); clreol();
       gets(t1);
       t2 = atof(t1);
       eloan =t2;
       if (eloan > 50000)
	{
	  valid = 0;
	  gotoxy(5,25); clreol();
	  cout<<"\7SHOULD NOT GREATER THAN 50000";
	  getch();
	}
     } while (!valid);
    if (egrade != 'E')
     {
      do
       {
	  valid = 1;
	  gotoxy(5,25); clreol();
	  cout<<"ENTER BASIC SALARY OF THE EMPLOYEE";
	  gotoxy(22,22); clreol();
	  gets(t1);
	  t2 = atof(t1);
	  ebasic =t2;
	  if (t1[0] == '0')
	    return;
	  if (ebasic > 50000)
	   {
	    valid = 0;
	    gotoxy(5,25); clreol();
	    cout<<"\7 SHOULD NOT GREATER THAN 50000";
	    getch();
	   }
       } while (!valid);
     }
    gotoxy(5,25); clreol();
    do
     {
      gotoxy(5,24); clreol();
      cout<<"DO YOU WANT TO SAVE (Y/N)";
      ch = getche();
      ch = toupper(ch);
      if (ch == '0')
       return ;
     } while (ch != 'Y' && ch != 'N');
    if( ch == 'N')
       return;
    ADD_RECORD(ecode, ename, eaddress, ephone, d,
    m, y, edesig,egrade, ehouse, econv, eloan, ebasic);
  }

 //*******************************************
 //    THIS FUNCTION GIVES THE CODE          *
 //    FOR THE DISPLAY OF THE RECORD         *
 //*******************************************
 void EMPLOYEE :: DISPLAY(void)
  {
    clrscr();
    char t1[10];
    int t2, ecode;
    gotoxy(72,2);
    cout<<"<0>=EXIT";
    gotoxy(5,5);
    cout<<"ENTER CODE OF THE EMPLOYEE :";
    gets(t1);
    t2 = atoi(t1);
    ecode = t2;
    if (ecode == 0)
      return;
    clrscr();
    if (!FOUND_CODE(ecode))
     {
      gotoxy(5,5);
      cout<<"\7******RECORD NOT FOUND******";
      getch();
      return;
     }
    DISPLAY_RECORD(ecode);
    gotoxy(5,25);
    cout<<"PRESS ANY KEY TO CONTINUE....";
    getch();
}

 //*******************************************
 //    THIS FUNCTION GIVES THE DATA FOR THE  *
 //    MODIFICATION OF THE EMPLOYEE RECORD   *
 //*******************************************
 void EMPLOYEE :: MODIFICATION(void)
  {
    clrscr();
    char ch, egrade, ehouse='N', econv='N';
    char ename[26], eaddress[31], ephone[10];
    char edesig[16], t1[10];
    float t2=0.0, eloan=0.0, ebasic=0.0;
    int ecode, valid;
    gotoxy(72,2);
    cout<<"<0>=EXIT";
    gotoxy(5,5);
    cout<<"ENTER CODE OF THE EMPLOYEES";
    gets(t1);
    t2 = atoi(t1);
    ecode = t2;
    if (ecode == 0)
      return;
    clrscr();
    if(!FOUND_CODE(ecode))
     {
      gotoxy(72,2);
      cout<<"\7RECORD NOT FOUND";
      getch();
      return;
     }
    gotoxy(72,2);
    cout<<"<0>=EXIT";
    gotoxy(22,3);
    cout<<"MODIFICATION OF THE EMPLOYEE RECORD";
    DISPLAY_RECORD(ecode);
    do
     {
      gotoxy(5,24); clreol();
      cout<<"DO YOU WANT TO MODIFY THIS RECORD (Y/N)";
      ch = getche();
      ch = toupper(ch);
      if (ch == '0')
       return;
     } while (ch != 'Y' && ch !=  'N');
    if (ch == 'N')
      return;
    clrscr();
    fstream file;
    file.open("EMPLOYEE.DAT", ios::in);
    file.seekg(0,ios::beg);
    while (file.read ((char *) this, sizeof(EMPLOYEE)))
     {
       if (code == ecode)
	  break;
     }
    file.close();
    gotoxy(5,5);
    cout<<"EMPLOYEE CODE #"<<ecode;
    gotoxy(5,6);
    cout<<"~~~~~~~~~~~~~~~~~~~~";
    gotoxy(40,5);
    cout<<"JOINING DATE:";
    gotoxy(40,6);
    cout<<"~~~~~~~~~~~~~~~~~";
    gotoxy(55,5);
    cout<<dd <<"/"<<mm <<"/" <<yy;
    gotoxy(5,7);
    cout<<"NAME:";
    gotoxy(5,8);
    cout<<"ADDRESS:";
    gotoxy(5,9);
    cout<<"PHONE NO.:";
    gotoxy(5,10);
    cout<<"DESIGNATION:";
    gotoxy(5,11);
    cout<<"GRADE:";
    gotoxy(5,14);
    cout<<"LOAN:";
    do
     {
       valid = 1;
       gotoxy(5,25); clreol();
       cout<<"ENTER THE NAME OF THE EMPLOYEES ";
       cout<<"OR <ENTER> FOR NO CHANGE:";
       gotoxy(20,7); clreol();
       gets(ename);
       strupr(ename);
       if (ename[0] == '0')
	 return;
       if (strlen(ename) > 25)
	 {
	   valid = 0;
	   gotoxy(5,25); clreol();
	   cout<<"\7ENTER CORRECTLY (RANGE: 1..25)";
	   getch();
	 }
     } while (!valid);
    if(strlen(ename) == 0)
     {
       strcpy(ename,name);
       gotoxy(20,7);
       cout<<ename;
     }
    do
     {
       valid = 1;
       gotoxy(5,25); clreol();
       cout<<"ENTER ADDRESS OF THE EMPLOYEE";
       cout<<" OR <ENTER> FOR NO CHANGE:";
       gotoxy(20,8); clreol();
       gets(eaddress);
       strupr(eaddress);
       if (eaddress[0] == '0')
	 return;
       if (strlen(eaddress) > 40)
	 {
	   valid = 0;
	   gotoxy(5,25); clreol();
	   cout<<"\nENTER CORRECTLY (RANGE:1..40)";
	   getch();
	 }
     } while (!valid);
    if(strlen(eaddress) == 0)
     {
       strcpy(eaddress,address);
       gotoxy(20,8);
       cout<<eaddress;
     }
    do
     {
       valid = 1;
       gotoxy(5,25); clreol();
       cout<<"ENTER PHONE NO. OF THE EMPLOYEES";
       cout<<"OR <ENTER> FOR NO CHANGE:";
       gotoxy(20,9); clreol();
       gets(ephone);
       if(ephone[0] == '0')
	  return;
       if ((strlen(ephone) < 7 && strlen(ephone) >0)
	   && strlen(ephone) > 9)
	{
	  valid = 0;
	  gotoxy(5,25); clreol();
	  cout<<"\7ENTER CORRECTLY";
	  getch();
	}
     } while (!valid);
    if(strlen(ephone) == 0)
     {
       strcpy(ephone,phone);
       gotoxy(20,9);
       cout<<ephone;
     }
    do
     {
       valid = 1;
       gotoxy(5,25); clreol();
       cout<<"ENTER DESIGNATION OF THE EMPLOYEES";
       cout<<" OR <ENTER> FOR NO CHANGE";
       gotoxy(20,10); clreol();
       gets(edesig);
       strupr(edesig);
       if(edesig[0] == '0')
	return;
       if(strlen(edesig) > 25)
	{
	  valid = 0;
	  gotoxy(5,25); clreol();
	  cout<<"\7ENTER CORRECTLY (RANGE: 1..25)";
	  getch();
	}
     } while (!valid);
    if (strlen(edesig) == 0)
     {
       strcpy(edesig,desig);
       gotoxy(20,10);
       cout<<edesig;
     }
    do
     {
       gotoxy(5,25); clreol();
       cout<<"ENTER GRADE OF THE EMPLOYEE (A,B,C,D,E)";
       cout<<" OR <ENTER> FOR NO CHANGE";
       gotoxy(20,11); clreol();
       egrade = getche();
       egrade = toupper(egrade);
       if (egrade == 0)
	  return;
       if (egrade == 13)
	{
	  egrade = grade;
	  gotoxy(20,11);
	  cout<<grade;
	}
     } while (egrade < 'A' ||  egrade > 'E');
    if (egrade  != 'E')
     {
       gotoxy(5,12);
       cout<<"HOUSE LOAN (Y/N):";
       gotoxy(5,13);
       cout<<"CONVEYANCE LOAN (Y/N):";
       gotoxy(5,15);
       cout<<"BASIC SALARY:";
       do
	{
	  gotoxy(5,25); clreol();
	  cout<<"ALLOTED HOUSE ALLOWANCE ? ";
	  cout<<"OR <ENTER> FOR NO CHANGE";
	  gotoxy(22,12); clreol();
	  ehouse = getche();
	  ehouse = toupper(ehouse);
	  if(ehouse == '0')
	    return;
	  if (ehouse == 13)
	   {
	      ehouse = house;
	      gotoxy(22,12);
	      cout<<ehouse;
	   }
	} while( ehouse != 'Y'&& ehouse != 'N');
       do
	{
	  gotoxy(5,25); clreol();
	  cout<<"ALLOTED CONVEYANCE ALLOWANCE";
	  cout<<" OR <ENTER> FOR NO CHANGE";
	  gotoxy(5,25); clreol();
	  econv = getche();
	  econv = toupper(econv);
	  if(econv == '0')
	     return;
	  if (econv == 13)
	   {
	     econv = convense;
	     gotoxy(22,13);
	     cout<<econv;
	   }
	} while (econv != 'Y' && econv != 'N');
     }//end of if
    do
     {
       valid = 1;
       gotoxy(5,25); clreol();
       cout<<"ENTER LOAN AMOUNT OR";
       cout<<" <ENTER> FOR NO CHANGE";
       gotoxy(22,14); clreol();
       gets(t1);
       t2 = atoi(t1);
       eloan = t2;
       if(eloan > 50000)
	{
	  valid = 0;
	  gotoxy(5,25); clreol();
	  cout<<"\7SHOULD NOT GREATER THAN 50000";
	  getch();
	}
     } while (!valid);
    if (strlen(t1) == 0)
     {
       ebasic = basic;
       gotoxy(22,15);
       cout<<ebasic;
     }
    gotoxy(5,25); clreol();
    do
     {
       gotoxy(5,18); clreol();
       cout<<"DO YOU WANT TO SAVE (Y/N)";
       ch = getche();
       ch = toupper(ch);
       if (ch == '0')
	  return;
     } while (ch != 'Y' && ch != 'N');
    if (ch == 'N')
      return;
    MODIFY_RECORD(ecode,ename,eaddress,ephone,
    edesig,egrade,ehouse,econv,eloan,ebasic);
    gotoxy(5,23);
    cout<<"\n\t\t RECORD MODIFIED";
    gotoxy(5,25);
    cout<<"PRESS ANY KEY TO CONTINUE...";
    getch();
  }
 //*******************************************
 //    THIS FUNCTION GIVES THE CODE NO. FOR  *
 //    THE DELETION OF THE EMPLOYEE RECORD   *
 //*******************************************
 void EMPLOYEE :: DELETION(void)
  {
    clrscr();
    char t1[10], ch;
    int t2, ecode;
    gotoxy(72,2);
    cout<<"<0>=EXIT";
    gotoxy(5,5);
    cout<<"ENTER CODE OF THE EMPLOYEE";
    gets(t1);
    t2 = atoi(t1);
    ecode = t2;
    if (ecode == 0)
      return;
    clrscr();
    if (! FOUND_CODE(ecode))
     {
       gotoxy(5,5);
       cout<<"\7 RECORD NOT FOUND";
       getch();
       return;
     }
    gotoxy(72,2);
    cout<<"<0>=EXIT";
    gotoxy(24,3);
    cout<<"DELETION OF THE EMPLOYEE RECORD";
    DISPLAY_RECORD(ecode);
    gotoxy(5,24); clreol();
    do
     {
       gotoxy(5,24); clreol();
       cout<<"DO YOU WANT TO DELETE THIS RECORD (Y/N)";
       ch = getche();
       ch = toupper(ch);
       if (ch == '0')
	 return;
     } while (ch != 'Y' && ch != 'N');
    if (ch == 'N')
      return;
    DELETE_RECORD(ecode);
    LINES L;
    L.CLEARDOWN();
    gotoxy(5,23);
    cout<<"PRESS ANY KEY TO CONTINUE.....";
    getch();
  }
 //*******************************************
 //    THIS FUNCTION RETURNS 0               *
 //    IF THE GIVEN DATE IS INVALID          *
 //*******************************************
 int EMPLOYEE :: VALID_DATE (int d1, int m1, int y1)
  {
    int valid = 1;
    if (d1 > 31 || d1 < 1)
     valid = 0;
    else
     if (((y1%4) !=0 && d1>28) || ((y1%4)==0
	 && m1==2 && d1>29))
	 valid = 0;
     else
	if ((m1==4 || m1==6 || m1==9 || m1==11)
	    && d1>30)
	    valid = 0;
	    return valid;
  }

 //*******************************************
 //    THIS FUNCTION PRINTS THE              *
 //    SALARY SLIP FOR THE EMPLOYEE          *
 //*******************************************
 void EMPLOYEE :: SALARY_SLIP(void)
  {
    clrscr();
    char t1[10];
    int t2, ecode, valid;
    gotoxy(72,2);
    cout<<"<0>=EXIT";
    gotoxy(5,5);
    cout<<"ENTER CODE OF THE EMPLOYEE";
    gets(t1);
    t2 = atoi(t1);
    ecode = t2;
    if (ecode == 0)
      return;
    clrscr();
    if(!FOUND_CODE(ecode))
     {
       gotoxy(5,5);
       cout<<"\7RECORD NOT FOUND";
       getch();
       return;
     }
    fstream file ;
    file.open("EMPLOYEE.DAT",ios::in);
    file.seekg(0,ios::beg);
    while (file.read((char*)this, sizeof(EMPLOYEE)))
     {
       if (code == ecode)
	  break;
     }
    file.close();
    int d1, m1, y1;
    struct date d;
    getdate(&d);
    d1 = d.da_day;
    m1 = d.da_mon;
    y1 = d.da_year;
    char *mon[12]={"January","February","March",
		   "April","May","June","July",
		   "August","September","October",
		   "November","December"
		  };
    LINES L;
    L.BOX(2,1,79,25,219);
    gotoxy(31,2);
    cout<<"NIDHI & PRIYA PVT. LTD.";
    L.LINE_HOR(3,78,3,196);
    gotoxy(34,4);
    cout<<"SALARY SLIP";
    gotoxy(60,4);
    cout<<"Date:"<<d1 <<"/" <<m1 <<"/" <<y1;
    gotoxy(34,5);
    cout<<mon[m1-1] <<"," <<y1;
    L.LINE_HOR(3,78,6,196);
    gotoxy(6,7);
    cout<<"Employee Name :"<<name;
    gotoxy(6,8);
    cout<<"Designation :"<<desig;
    gotoxy(67,8);
    cout<<"Grade :"<<grade;
    L.BOX(6,9,75,22,218);
    L.LINE_HOR(10,71,20,196);
    int days, hours;
    if (grade == 'E')
     {
       do
	 {
	  valid = 1;
	  gotoxy(10,21);
	  cout<<"ENTER NO. OF DAYS WORKED IN THE MONTH";
	  gotoxy(10,11);
	  cout<<"No. of Days :";
	  gets(t1);
	  t2 = atof(t1);
	  days = t2;
	  if (!VALID_DATE(days,m1,y1))
	   {
	     valid = 0;
	     gotoxy(10,21);
	     cout<<"\7ENTER CORRECTLY";
	     getch();
	     gotoxy(10,11);
	     cout<<"               ";
	   }
	 } while (!valid);
       do
	 {
	  valid = 1;
	  gotoxy(10,21);
	  cout<<"ENTER NO. OF HOURS WORKED OVER TIME";
	  gotoxy(10,13);
	  cout<<"NO.OF HOURS :";
	  gets(t1);
	  t2 = atof(t1);
	  hours = t2;
	  if (hours > 8 || hours < 0)
	   {
	     valid = 0;
	     gotoxy(10,21);
	     cout<<"\7ENTER CORRECTLY";
	     getch();
	     gotoxy(10,13);
	     cout<<"              ";
	   }
	 }  while (!valid);
       gotoxy(10,21);
       cout<<"                ";
       gotoxy(10,11);
       cout<<"                 ";
       gotoxy(10,13);
       cout<<"              ";
     }//end of if
    gotoxy(10,10);
    cout<<"Basic salary";
    gotoxy(10,12);
    cout<<"ALLOWANCE";
    if (grade != 'E')
     {
       gotoxy(12,13);
       cout<<"HRA   :Rs.";
       gotoxy(12,14);
       cout<<"CA    :Rs.";
       gotoxy(12,15);
       cout<<"DA    :Rs.";
     }
    else
     {
       gotoxy(12,13);
       cout<<"OT    :Rs.";
     }
    gotoxy(10,17);
    cout<<"DEDUCTIONS";
    gotoxy(12,18);
    cout<<"LD     :Rs.";
    if (grade != 'E')
     {
       gotoxy(12,19);
       cout<<"PF    :Rs.";
     }
    gotoxy(10,21);
    cout<<"NET SALARY      :Rs.";
    gotoxy(6,24);
    cout<<"CASHIER";
    gotoxy(68,24);
    cout<<"EMPLOYEE";
    float HRA=0.0, CA=0.0, DA=0.0, PF=0.0, LD=0.0,
	  OT=0.0,allowance,deduction,netsalary;
    if (grade != 'E')
     {
       if (house =='Y')
	 HRA = (5*basic)/100;
       if (convense == 'Y')
	 PF = (2*basic)/100;
	 DA = (5*basic)/100;
	 LD = (15*loan)/100;
	 allowance = HRA+CA+DA;
	 deduction =PF+LD;
     }
    else
     {
       basic = days * 30;
       LD = (15*loan)/100;
       OT = hours * 10;
       allowance = OT;
       deduction = LD;
     }
    netsalary = (basic+allowance)-deduction;
    gotoxy(36,10);
    cout<<basic;
    if (grade != 'E')
     {
       gotoxy(22,13);
       cout<<HRA;
       gotoxy(22,14);
       cout<<CA;
       gotoxy(22,15);
       cout<<DA;
       gotoxy(22,19);
       cout<<PF;
     }
    else
     {
       gotoxy(22,13);
       cout<<OT;
     }
    gotoxy(22,18);
    cout<<LD;
    gotoxy(33,15);
    cout<<"Rs."<<allowance;
    gotoxy(33,19);
    cout<<"Rs."<<deduction;
    gotoxy(36,21);
    cout<<netsalary;
    gotoxy(2,1);
    getch();
  }
 //*******************************************
 //      MAIN FUNCTION CALLING               *
 //      MAIN MENU                           *
 //*******************************************

 void main(void)
  {
    MENU menu;
    menu.MAIN_MENU();
  }
