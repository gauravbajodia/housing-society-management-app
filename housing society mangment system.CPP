#include "fstream.h"
#include "string.h"
#include "stdio.h"
#include "process.h"
#include "conio.h"



class Society {                           
	protected :
		char option;
	public :
		virtual void search () = 0;         
		void seclogin ();
		void secmenu ();
		void reslogin ();
		void resmenu (int );
};




class Resident : virtual public Society {      
		int id;		
		char name [16];
		int r_phone;
	public :
		void search ();
		void search (int );
	
		void res_menu ();
		void getvalues ();
		void printvalues ();
		int retid () {return id;}
		
}ft;

void exitscreen () {
	clrscr ();
	cout<<"\n\n\t\t***************************************"
		<<"\n\n\t\t\tTHANKYOU FOR VISITING US"
		<<"\n\n\t\t***************************************";
	getch ();
	exit (0);
}



void Resident :: getvalues () {
	clrscr ();
	cout<<"\n\n\t\t***************************************"
		<<"\n\n\t\t\tNEW RESIDENT REGISTERATION"
		<<"\n\n\t\t***************************************"
		<<"\n\n\t\tEnter Id : ";cin>>id;
	cout<<"\n\t\tEnter Name : ";cin>>name;
	cout<<"\n\t\tEnter Phone no. : ";cin>>r_phone;
	ifstream check ("resident.DAT",ios::binary);
	while (check.read ((char *)&ft,sizeof (ft)))
		if (ft.retid () == id) {
			cout<<"\n\n\t\t\tID Already Exist\'s !!!";
			getch ();
			getvalues ();
		}
}



void Resident :: printvalues () {
	cout<<"\n\n\t\t***************************************"
		<<"\n\n\t\t\t Resident DETAILS"
		<<"\n\n\t\t***************************************"
		<<"\n\n\t\tId : "<<id
		<<"\n\n\t\tName : "<<name
		<<"\n\n\t\tPhone no.: "<<r_phone
		<<"\n\n\t\t***************************************";
}



class Maintanance : virtual public Society {      
		int id;
		char name [16];
		char password [16];
		char mt_money [16];
	
		void personaldetails ();
	public :
		void search ();                     
		void search (int );
	
		void mt_menu ();
		void getvalues ();
		void printvalues ();
		void printdetails (int );
		char* retpassword () {return password;}
		
		int retid () {return id;}
}fs;



void Maintanance :: getvalues () {
	clrscr ();
	int i=-1;
	char ch;
	cout<<"\n\n\t\t***************************************"
		<<"\n\n\t\t\tNEW MAINTANANCE ENTRY"
		<<"\n\n\t\t***************************************"
		<<"\n\n\t\tEnter Id : ";cin>>id;
	cout<<"\n\t\tEnter Name : ";cin>>name;
	cout<<"\n\t\tEnter amount : ";cin>>mt_money;
	cout<<"\n\t\tEnter Password : ";
	strcpy (password,"");
	do {
		i++;                           
		ch = getch ();
		if (ch != 13) {
			password [i] = ch;
			cout<<'*';
		}
	} while (ch != 13);
	password [i] = '\0';
	ifstream check ("Maintanance.DAT",ios::binary);
	while (check.read ((char *)&fs,sizeof (fs)))
		if (fs.retid () == id) {
			cout<<"\n\n\t\t\tID Already Exist\'s !!!";
			getch ();
			getvalues ();
		}

}



void Maintanance :: printvalues () {
	cout<<"\n\n\t\t***************************************"
		<<"\n\n\t\t\t Maintanance DETAILS"
		<<"\n\n\t\t***************************************"
		<<"\n\n\t\tId : "<<id
		<<"\n\n\t\tName : "<<name
		<<"\n\n\t\tMaintenance Money : "<<mt_money
		<<"\n\n\t\t***************************************";
}



class Main_1 : public Resident , public Maintanance
{

	public :
		Main_1 ();                            

		~Main_1 ();                           
}m;



Main_1 :: Main_1 () {



	clrscr ();
	cout<<"\n\n\t\t***************************************"
		<<"\n\n\t\t  WELCOME TO SOCIETY MANAGEMENT SYTEM"
		<<"\n\n\t\t***************************************"
		<<"\n\n\t\t\t1.Secretary Login"
		<<"\n\n\t\t\t2.Resident login"

		<<"\n\n\t\t\t0.Exit"
		<<"\n\n\t\t***************************************"
		<<"\n\n\t\t\tEnter option : ";

	option = getch ();

	switch (option) {
		case '1' :
		
			seclogin ();
			break;

		case '2' :
		
			reslogin ();
			break;



		case '0' :
		
			exitscreen ();
	}
	Main_1 ();
}



Main_1 :: ~Main_1 () {
	clrscr ();
	cout<<"\n\n\t\t***************************************"
		<<"\n\n\t\t\tTHANKYOU FOR VISITING US"
		<<"\n\n\t\t***************************************";
	exit (0);
}



void Society :: seclogin () {
	clrscr ();
	char pass [20],user [20];               
	int i=-1;
	static int attempt=0;
	cout<<"\n\n\t\t***************************************"
		<<"\n\n\t\t\tPASSWORD PROTECTED"
		<<"\n\n\t\t***************************************"
		<<"\n\n\t\tEnter Username : ";
	cin>>user;
	cout<<"\n\t\tEnter Password : ";
	attempt++;
	do {
		i++;
		pass [i] = getch ();
		if (pass [i] != 13)
			cout<<'*';
	} while (pass [i] != 13);

	if (strcmp (user,"secretary") == 0 && strcmp (pass,"123") == 13)
		secmenu ();
		else {
			cout<<"\n\n\n\t\t\t INVALID CREDENTIALS !!!";
			getch ();
			Main_1 ();
		}

}



void Society :: secmenu () {
	clrscr ();
	cout<<"\n\n\t\t***************************************"
		<<"\n\n\t\t  WELCOME TO SECRETARY MENU"
		<<"\n\n\t\t***************************************"
		<<"\n\n\t\t\t1.Resident Menu"
		<<"\n\n\t\t\t2.Maintainance Menu"
		<<"\n\n\t\t\t9.Previous Menu"
		<<"\n\n\t\t\t0.Exit"
		<<"\n\n\t\t***************************************"
		<<"\n\n\t\t\tEnter option : ";
	option = getch ();


	switch (option) {
		case '1' :
		
			ft.res_menu ();
			break;

		case '2' :
			
			fs.mt_menu ();
			break;

		case '9' :
			
			Main_1 ();
			break;

		case '0' :
		
			exitscreen ();
			break;
	}
	secmenu ();
}



void Society :: reslogin () {
	clrscr ();
	Maintanance s;
	char pass [20],spass [20];
	int id,sid;
	int i=-1;
	static int attempt=0;
	cout<<"\n\n\t\t***************************************"
		<<"\n\n\t\t\tPASSWORD PROTECTED"
		<<"\n\n\t\t***************************************"
		<<"\n\n\t\tEnter ID : ";
	cin>>id;
	cout<<"\n\t\tEnter Password : ";
	attempt++;
	do {
		i++;
		pass [i] = getch ();
		if (pass [i] != 13)
			cout<<'*';
	} while (pass [i] != 13);

	ifstream search ("Maintanance.DAT",ios::binary);
	while (search.read ((char *)&s,sizeof (s)))
		if (s.retid () == id) {
			strcpy (spass,s.retpassword ());
			sid = s.retid ();
		}

	if (id == sid && strcmp (pass,"spass") == 13)
		resmenu (sid);
		else {
			cout<<"\n\n\n\t\t\wrong password";
			getch ();
			Main_1();
		}

}



void Resident :: res_menu () {
	clrscr ();
	cout<<"\n\n\t\t***************************************"
	<<"\n\n\t\t  Resident MENU"
	<<"\n\n\t\t***************************************"
	<<"\n\n\t\t\t1.Add Resident"
	<<"\n\n\t\t\t2.Search Resident"
	<<"\n\n\t\t\t3.Delete Resident"
	<<"\n\n\t\t\t4.Print all"
	<<"\n\n\t\t\t9.Previous Menu"
	<<"\n\n\t\t\t0.Exit"
	<<"\n\n\t\t***************************************"
	<<"\n\n\t\t\tEnter option : ";option = getch ();

	switch (option) {
		case '1' :
		
		{
			Resident* t = new Resident;           
			ofstream add ("resident.DAT",ios::binary|ios::app);
			(*t).getvalues ();
			add.write ((char *)&(*t),sizeof ((*t)));
			cout<<"\n\n\t\t\tRecord Added Successfully !!!";
			getch ();
			add.close ();
			delete t;                       
			break;
		}

		case '2' :
		
			search ();
			break;

		case '3' :
			
		{
			Resident t;
			int o=0,f=0,n;
			clrscr ();
			cout<<"\n\n\t\t***************************************";
			cout<<"\n\n\n\t\t\tEnter ID to Search : ";
			cin>>n;
			ifstream msearch ("resident.DAT",ios::binary);
			while (msearch.read ((char *)&t,sizeof (t))) {
				if (t.retid () == n)
				{
					t.printvalues ();
					cout<<"\n\n\t\tAre you sure you want to delete this Resident (1/0) : ";
					cin>>o;
					if (o == 1)
					{
						ifstream search ("resident.DAT",ios::binary);
						ofstream newfile ("TEMP.DAT",ios::binary);
						while (search.read ((char *)&t,sizeof (t)))
							if (t.retid () != n)
								newfile.write ((char *)&t,sizeof (t));
						cout<<"\n\n\t\tRecord Deleted Succesfull !!!";
						remove ("Resident.DAT");
						rename ("TEMP.DAT","Resident.DAT");
						search.close ();
						newfile.close ();
					}
					else
					{
						res_menu ();
					}
					getch ();
					f++;
				}
			}
			if (f==0)
			{
				cout<<"\n\n\n\t\t\tID NOT FOUND !!!";
				getch ();
				res_menu ();
			}
			cout<<"\n\n\t\t***************************************";
			break;
		}

		case '4' :
			
		{
			Resident t;
			clrscr ();
			cout<<"\n\n\t\t***************************************"
			<<"\n\n\t\t\t\tALL RESIDENTS"
			<<"\n\n\t\t***************************************";
			ifstream print ("resident.DAT",ios::binary);
			print.seekg (0,ios::end);
			if (print.tellg () == 0)
			{
		cout<<"\n\n\t\t\tNo Record found !!!";
		getch ();
		res_menu ();
            }
            print.seekg (0,ios::beg);
            cout<<"\n\n\nID\tNAME\t\tPHONE NO.\n";
            while (print.read ((char *)&t,sizeof (t))) {
                cout<<"\n"<<t.id<<"\t"<<t.name<<"\t\t"<<"\t\t"<<t.r_phone;
            }
            print.close ();
            getch ();
            break;
        }
            
        case '9' :
          
            secmenu ();
            break;
            
        case '0' :
         
            exitscreen ();
            break;
    }
    res_menu ();
}



void Resident :: search () {
    clrscr ();
    cout<<"\n\n\t\t***************************************"
    <<"\n\n\t\t  SELECT SEARCH METHOD"
	<<"\n\n\t\t***************************************"
	<<"\n\n\t\t\t1.Search by ID"
	<<"\n\n\t\t\t9.Previous Menu"
	<<"\n\n\t\t\t0.Exit"
	<<"\n\n\t\t***************************************"
	<<"\n\n\t\t\tEnter Option : ";
	option = getch ();

	switch (option) {

		case '1' :
			/*Search by Id*/
			int n;
			clrscr ();
			cout<<"\n\n\t\t***************************************"
			<<"\n\n\t\tEnter ID to Search : ";
			cin>>n;
			search (n);
			break;

		case '9' :
			/*Resident Menu*/
			res_menu ();
			break;

		case '0' :
			/*Exit Screen*/
			exitscreen ();
			break;
	}
	search ();
}



void Resident :: search (int n) 
{
	Resident t;
	int f=0;
	ifstream search ("resident.DAT",ios::binary);
	while (search.read ((char *)&t,sizeof (t))) {
		if (t.retid () == n) {
			clrscr ();
			t.printvalues ();
			getch ();
			f++;
		}	}
	if (f==0) {
		cout<<"\n\n\n\t\t\tID NOT FOUND !!!";
		getch ();
		res_menu ();
	}
}

void Maintanance :: mt_menu () {
	clrscr ();
	cout<<"\n\n\t\t***************************************"
	<<"\n\n\t\t  Maintanance MENU"
	<<"\n\n\t\t***************************************"
	<<"\n\n\t\t\t1.Add Maintanance"
	<<"\n\n\t\t\t2.Search Maintanance"
	<<"\n\n\t\t\t3.Delete Maintanance"
	<<"\n\n\t\t\t4.Print all"
	<<"\n\n\t\t\t9.Previous Menu"
	<<"\n\n\t\t\t0.Exit"
	<<"\n\n\t\t***************************************"
	<<"\n\n\t\t\tEnter option : ";
	option = getch ();

	switch (option) {
		case '1' :
			
		{
			Maintanance* s = new Maintanance;
			ofstream add ("Maintanance.DAT",ios::binary|ios::app);
			(*s).getvalues ();
			add.write ((char *)&(*s),sizeof ((*s)));
			cout<<"\n\n\t\t\tRecord Added Successfully !!!";
			getch ();
			add.close ();
			break;
		}

		case '2' :
			
			search ();
			break;

		case '3' :
			
		{
			Maintanance s;
			int o=0,f=0,n;
			clrscr ();
			cout<<"\n\n\t\t***************************************";
			cout<<"\n\n\n\t\t\tEnter ID to Search : ";
			cin>>n;
			ifstream msearch ("Maintanance.DAT",ios::binary);
			while (msearch.read ((char *)&s,sizeof (s))) 
			{
				if (s.retid () == n) 
				{
					s.printvalues ();
					cout<<"\n\n\t\tARE you sure you want to delete this Maintanance (1/0) : ";cin>>o;
					if (o == 1) {
						ifstream search ("Maintanance.DAT",ios::binary);
						ofstream newfile ("TEMP.DAT",ios::binary);
						while (search.read ((char *)&s,sizeof (s)))
							if (s.retid () != n)
								newfile.write ((char *)&s,sizeof (s));
						cout<<"\n\n\t\tRecord Deleted Succesfull !!!";
						remove ("Maintanance.DAT");
						rename ("TEMP.DAT","Maintanance.DAT");
						search.close ();
						newfile.close ();
					}
					else 
					{
						mt_menu ();
					}
					getch ();
					f++;
				}
			}
			if (f==0) {
				cout<<"\n\n\n\t\t\tID NOT FOUND !!!";
				getch ();
				mt_menu ();
			}
			cout<<"\n\n\t\t***************************************";
			break;
		}

		case '4' :
		
		{
			Maintanance s;
			clrscr ();
            cout<<"\n\n\t\t***************************************"
            <<"\n\n\t\t\t\tALL MAINTENANCE DETAILS"
            <<"\n\n\t\t***************************************";
            ifstream print ("Maintanance.DAT",ios::binary);
            print.seekg (0,ios::end);
            if (print.tellg () == 0) 
			{
                cout<<"\n\n\t\t\tNo Record found !!!";
                getch ();
                mt_menu ();
            }
            print.seekg (0,ios::beg);
            cout<<"\n\n\nID\tNAME\t\tMAINTENANCE MONEY\n";
            while (print.read ((char *)&s,sizeof (s))) 
			{
                cout<<"\n"<<s.id<<"\t"<<s.name<<"\t\t"<<s.mt_money;
            }
            print.close ();
            getch ();
            break;
        }
            
        case '9' :
          
			secmenu ();
            break;
            
        case '0' :
           
            exitscreen ();
            break;
            
    }
    mt_menu ();
}



void Maintanance :: search () {
	clrscr ();
	cout<<"\n\n\t\t***************************************"
	    <<"\n\n\t\t  SELECT SEARCH METHOD"
		<<"\n\n\t\t***************************************"
		<<"\n\n\t\t\t1.Search by ID"
		<<"\n\n\t\t\t9.Previous Menu"
		<<"\n\n\t\t\t0.Exit"
		<<"\n\n\t\t***************************************"
		<<"\n\n\t\t\tEnter Option : ";
		option = getch ();

	switch (option) {

		case '1' :
		
			int n;
			clrscr ();
			cout<<"\n\n\t\t***************************************"
			<<"\n\n\t\tEnter ID to Search : ";cin>>n;
			search (n);
			break;


		case '9' :
			
			mt_menu ();
			break;

		case '0' :
			
			exitscreen ();
			break;

	}
	search ();
}



void Maintanance :: search (int n) 
{
	Maintanance s;
	int f=0;
	ifstream search ("Maintanance.DAT",ios::binary);
	while (search.read ((char *)&s,sizeof (s))) {
		if (s.retid () == n) {
			clrscr ();
			s.printvalues ();
			getch ();
			f++;
		}
	}
	if (f==0) {
		cout<<"\n\n\n\t\t\tID NOT FOUND !!!";
		getch ();
		mt_menu ();
	}
}


void Society :: resmenu (int id) {
	clrscr ();
	cout<<"\n\n\t\t***************************************"
		<<"\n\n\t\t  WELCOME TO USER MENU"
		<<"\n\n\t\t***************************************"
		<<"\n\n\t\t\t1.Personal Details"
		<<"\n\n\t\t\t9.Previous Menu"
		<<"\n\n\t\t\t0.Exit"
		<<"\n\n\t\t***************************************"
		<<"\n\n\t\t\tEnter option : ";option = getch ();

	switch (option) {
		case '1' :
	
			fs.printdetails (id);
			break;

		case '9' :
			/*Home Screen*/
			Main_1 ();
			break;

		case '0' :
			/*Exit Screen*/
			exitscreen ();
			break;
	}
	Main_1 ();
}



void Maintanance :: printdetails (int id) {
	clrscr ();
	Maintanance s;
	ifstream search ("Maintanance.DAT",ios::binary);
	while (search.read ((char *)&s,sizeof (s)))
		if (s.retid () == id) 
		{
			cout<<"\n\n\t\t***************************************"
				<<"\n\n\t\t\t PERSONAL DETAILS"
				<<"\n\n\t\t***************************************"
				<<"\n\n\t\tId : "<<s.id
				<<"\n\n\t\tName : "<<s.name
				<<"\n\n\t\tMaintenance Money : "<<s.mt_money
				<<"\n\n\t\t***************************************";
		}
	getch ();
	resmenu (id);
}

int main () {

}


