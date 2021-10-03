//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<fstream.h>
#include<dos.h>
 
//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************

class product
{
 int pno;
 char name[50];
 float price,qty,tax,dis;
 public:
	void create_product()
	{
	 cout<<"\nEnter the product no. of the product :";
	 cin>>pno;
	 cout<<"\n\nEnter the name of the product :";
	 gets(name);
	 cout<<"\nEnter the price of the product :Rs.";
	 cin>>price;
	 cout<<"\nEnter the discount [%] :";
	 cin>>dis;
	 }

	void show_product()
	{
	 cout<<"\nProduct Number : "<<pno;
	 cout<<"\nName of the product : ";
	 puts(name);
	 cout<<"\nPrice of the product :Rs."<<price;
	 cout<<"\nDiscount [%] : "<<dis;
	 }

  int  retpno()
  {return pno;}

  float retprice()
  {return price;}

  char* retname()
  {return name;}

  int retdis()
  {return dis;}

};         //class ends here

 
//***************************************************************
//    	global declaration for stream object, object
//****************************************************************

 fstream fp;
 product pr;


//***************************************************************
//    	function to write in file
//****************************************************************

void write_product()
   {
    fp.open("Shop.dat",ios::out|ios::app);
    pr.create_product();
    fp.write((char*)&pr,sizeof(product));
    fp.close();
    cout<<"\n\nThe product has been created ";
    getch();
   }


//***************************************************************
//    	function to read all records from file
//****************************************************************


void display_all()
{
    clrscr();
    cout<<"\n\n\n\t\t...DISPLAYING ALL RECORDS...\n\n";
    fp.open("Shop.dat",ios::in);
    while(fp.read((char*)&pr,sizeof(product)))
	{
	 cout<<"\n\n-----------------------------------------------\n";
	 pr.show_product();
	 cout<<"\n\n-----------------------------------------------\n";
	 getch();
	 }
    fp.close();
    getch();
}




 
//***************************************************************
//    	function to read specific record from file
//****************************************************************


void display_sp(int n)
{
    int flag=0;
    fp.open("Shop.dat",ios::in);
    while(fp.read((char*)&pr,sizeof(product)))
	{
	 if(pr.retpno()==n)
		{
		 clrscr();
		 pr.show_product();
		 flag=1;
		}
	}
    fp.close();
if(flag==0)
 cout<<"\n\nRecord does not exist...!!!";
    getch();
}
 
//***************************************************************
//    	function to modify record of file
//****************************************************************


void modify_product()
{
    int no,found=0;
    clrscr();
    cout<<"\n\n\tTo modify :";
    cout<<"\n\n\tEnter the product no. of the product :";
    cin>>no;
    fp.open("Shop.dat",ios::in|ios::out);
    while(fp.read((char*)&pr,sizeof(product)) && found==0)
	   {
	    if(pr.retpno()==no)
		   {
		    pr.show_product();
		    cout<<"\nEnter the new details of product :"<<endl;
		    pr.create_product();
		    int pos=-1*sizeof(pr);
		    fp.seekp(pos,ios::cur);
		    fp.write((char*)&pr,sizeof(product));
		    cout<<"\n\n\tThankyou... Records Updated!!";
		    found=1;
		   }
	     }
    fp.close();
    if(found==0)
    cout<<"\n\n SORRY!! Record Not Found.. ";
    getch();
}

 
//***************************************************************
//    	function to delete record of file
//****************************************************************


void delete_product()
   {
    int no;
    clrscr();
    cout<<"\n\n\nTo Delete Record :";
    cout<<"\n\nEnter the product no. of the product you want to delete : ";
    cin>>no;
    fp.open("Shop.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&pr,sizeof(product)))
	{
	 if(pr.retpno()!=no)
		{
		 fp2.write((char*)&pr,sizeof(product));
		 }
	 }
    fp2.close();
    fp.close();
    remove("Shop.dat");
    rename("Temp.dat","Shop.dat");
    cout<<"\n\n\tRecord Deleted..";
    getch();
    }
 
//***************************************************************
//    	function to display all products price list
//****************************************************************

    void menu()
    {
     clrscr();
     fp.open("Shop.dat",ios::in);
     if(!fp)
     {
       cout<<"ERROR!...FILE COULD NOT BE OPEN!!\n\n\n Go to Admin Menu to create a new file..";
       cout<<"\n\n\n Program is closing...";
       getch();
       exit(0);
     }

     cout<<"\n\n\t\t\t\t...PRODUCT MENU...\n\n";
	  cout<<"====================================================\n";
	  cout<<"P.NO.\t\tNAME\t\tPRICE\n";
	  cout<<"====================================================\n";

      while(fp.read((char*)&pr,sizeof(product)))
	 {
	   cout<<pr.retpno()<<"\t\t"<<pr.retname()<<"\t\t"<<pr.retprice()<<endl;
	}
     fp.close();
}

 
//***************************************************************
//    	function to place order and generating bill for Products
//****************************************************************

   void place_order()
   {
    xyz:
    clrscr();
    int  order_arr[50],quan[50],c=0;
    float amt,damt,total=0;
    char ch='Y';
    menu();
    cout<<"\n\n\n\n\n\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
    cout<<"\n\t\t....PLACE YOUR ORDER....";
    cout<<"\n\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    do{
	 cout<<"\n\n\n\nEnter the product no. of the product : ";
	 cin>>order_arr[c];
	 int flag=0;
	 for(int x=0;x<=c;x++)
	 {
	    fp.open("Shop.dat",ios::in);
	    fp.read((char*)&pr,sizeof(product));
	    while(!fp.eof())
	    {
	      if(pr.retpno()==order_arr[x])
	      {
		 flag=1;
		 cout<<"\n\nProduct present..";
		 break;
	      }
	      fp.read((char*)&pr,sizeof(product));
	    }
	    fp.close();
	 }
	 if(flag==0)
	 {
	   cout<<"\n\nProduct number entered does not exist...\n\n Please try again...";
	   getch();
	   goto xyz;
	 }
	 cout<<"\n\nEnter the quantity in number : ";
	 cin>>quan[c];
	 c++;
	 cout<<"\n\nDo You Want To Order Another Product (Y/N) ? ";
	 cin>>ch;
    }while(ch=='y' ||ch=='Y');
    cout<<"\n\nThank You For Placing The Order...";getch();clrscr();
      cout<<"\n\n******************************** INVOICE ********************************\n";
      cout<<"\n(Pr No.) (Pr. Name) (Quantity) (Price) (Amount) (Amount after discount)\n";
      for(int x=0;x<=c;x++)
	{
		 fp.open("Shop.dat",ios::in);
		 fp.read((char*)&pr,sizeof(product));
		  while(!fp.eof())
			{
			if(pr.retpno()==order_arr[x])
				{
				 amt=pr.retprice()*quan[x];
				 damt=amt-(amt*pr.retdis()/100);
				 cout<<"\n"<<order_arr[x]      <<"\t"<<     pr.retname()         <<"\t\t"<<quan[x]          <<"\t"<<pr.retprice()          <<"\t"<<amt       <<"\t\t"<<damt;
				 total+=damt;
				}
			fp.read((char*)&pr,sizeof(product));
			}

		 fp.close();
	 }
       cout<<"\n\n\t\t\t\t\tTOTAL :Rs."<<total;
    getch();
    }

 
//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************

void intro()
{
 clrscr();
	 cout<<"\t@@      @@      ";
       cout<<"\n\t@@      @@  @@@@@@@  @@       @@@@@@   @@@@@@   @@@@   @@@@ @@@@@@@";
       cout<<"\n\t@@      @@  @@       @@       @@      @@    @@  @@  @@@  @@ @@      ";
       cout<<"\n\t@@  @@  @@  @@@@@    @@       @@      @@    @@  @@  @@@  @@ @@@@@      ";
       cout<<"\n\t@@  @@  @@  @@       @@       @@      @@    @@  @@       @@ @@           ";
       cout<<"\t@@@@@@@@@@  @@@@@@@  @@@@@@@  @@@@@@   @@@@@@   @@       @@ @@@@@@@     ";


       cout<<"\n\n\n\t\t\t        @@@@@@@@  @@@@@       ";
	 cout<<"\n\t\t\t           @@     @   @      ";
	 cout<<"\n\t\t\t           @@     @   @       ";
	 cout<<"\n\t\t\t           @@     @@@@@    ";

      
       cout<<"\n\n\t\t\t\t      MADE BY : bkoder";
		 
		
       cout<<"\nPress any key to continue....\n";

 getch();

}

 
//***************************************************************
//    	ADMINSTRATOR MENU FUNCTION
//****************************************************************
void admin_menu()
{
  clrscr();
  char ch2;
  cout<<"\n\n\n\t\t\t\t...ADMIN MENU...";
  cout<<"\n\n\n\t1.CREATE PRODUCT";
  cout<<"\n\n\t2.DISPLAY ALL PRODUCTS";
  cout<<"\n\n\t3.QUERY ";
  cout<<"\n\n\t4.MODIFY PRODUCT";
  cout<<"\n\n\t5.DELETE PRODUCT";
  cout<<"\n\n\t6.VIEW PRODUCT MENU";
  cout<<"\n\n\t7.BACK TO MAIN MENU";
  cout<<"\n\n\tPlease Enter Your Choice [1-7] : ";
  ch2=getche();
  switch(ch2)
  {
    case '1': getch();
	      clrscr();
	      write_product();
	      break;

    case '2': getch();
	      display_all();
	      break;

    case '3': getch();int num;
	      clrscr();
	      cout<<"\n\n\tPlease Enter The Product No. : ";
	      cin>>num;
	      display_sp(num);
	      break;

    case '4': getch();modify_product();
	      break;

    case '5': getch();delete_product();
	      break;

    case '6': getch();menu();
	      getch();

    case '7': getch();break;

    default:cout<<"\a";admin_menu();
   }
}

 
//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************


void main()
{
  char ch;
  intro();
  do
    {
	  clrscr();
	  cout<<"\n\n\n\n\t\t\t\t...MAIN MENU...";
	  cout<<"\n\n\n\t01. CUSTOMER";
	  cout<<"\n\n\t02. ADMINISTRATOR";
	  cout<<"\n\n\t03. EXIT";
	  cout<<"\n\n\tPlease Select Your Option [1-3] : ";
	  ch=getche();
	  switch(ch)
	  {
		 case '1': getch();clrscr();
			   place_order();
			   getch();
			   break;
		 case '2': getch();admin_menu();
			    break;
		 case '3': getch();
			   clrscr();
			   gotoxy(20,24);
			   cout<<"\n Please wait...\n Program is closing down!!";
			   delay(1500);
			   clrscr();
			   gotoxy(20,24);
			   cout<<"\nThank you........"<<endl; cout<<"________________________________________________________________________"<<endl;
			   delay(1500);
			   exit(0);
			   break;

		 default : getch();
			   clrscr();
			   gotoxy(20,24);
			   cout<<"\nSORRY!! This is an INVALID OPTION.... \n\n\tTry Again!";
			   getch();
			   break;
	}
    }while(ch!='3');
}

//***************************************************************
//    			END OF PROJECT
//***************************************************************
