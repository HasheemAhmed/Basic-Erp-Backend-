#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>

/* -----  Organization Portal Password ----- */

string OrgPassword = "superior";

/* -----  File Handling class ----- */

class Files
{
	string FileName;
	string FolderPath;
	string FilePath;

public:

	/* ----- Default Constructor ----- */

	Files()
	{
		FolderPath = "Temp";
		FilePath = FolderPath + "/" + FileName + ".txt";
	}

	/* -----  Parameterized Constructor ----- */

	Files(string FileName, string FolderPath, string FilePath)
	{
		this->FileName = FileName;
		this->FolderPath = FolderPath;
		this->FilePath = FilePath;
	}

	/* ----- Getter Functions ----- */

	string getFileName()
	{
		return FileName;
	}
	string getFilePath()
	{
		return FilePath;
	}
	string getFolderPath()
	{
		return FolderPath;
	}

	/* -----  Setter Functions ----- */

	void setFileName(string FileName)
	{
		this->FileName = FileName;
	}

	void setFolderPath(string FolderPath)
	{
		this->FolderPath = FolderPath;
		this->FilePath = FolderPath + "/" + FileName + ".txt";
	}


};

/* -----  File Handling Empty Function ----- */

bool isFileEmpty(ifstream& filename, string folder, string name)
{
	Files obj;
	obj.setFileName(name);
	obj.setFolderPath(folder);

	string length;
	filename.open(obj.getFilePath(), ios::in);

	while (filename.good())
	{
		if (filename.is_open())
		{
			getline(filename, length);
		}
		else
		{
			cout << "Error in opening file : ";
		}
	}

	if (length.length() == 0)
	{

		return true;
	}
	else
	{
		return false;
	}
	filename.close();
}

/* -----  Profile Class ----- */

class Profile : public Files
{
	string Name;
	string Id;
	string Password;
	string Email;
	string Phone;

public:

	/* -----  Default Class ----- */

	Profile()
	{
		Name = Id = Password = Email = Phone = "";
	}

	/* -----  Parameterized Class ----- */

	Profile(string Name, string Id, string Password, string Email, string Phone)
	{
		this->Name = Name;
		this->Id = Id;
		this->Password = Password;
		this->Email = Email;
		this->Phone = Phone;
	}

	/* -----  Setter Function ----- */

	void setName(string Name)
	{
		this->Name = Name;
	}
	void setId(string Id)
	{
		this->Id = Id;
	}
	void setPassword(string Password)
	{
		this->Password = Password;
	}
	void setEmail(string Email)
	{
		this->Email = Email;
	}
	void setPhone(string Phone)
	{
		this->Phone = Phone;
	}

	/* -----  Getter Function ----- */
	
	string getName()
	{
		return Name;
	}
	string getId()
	{
		return Id;
	}
	string getPassword()
	{
		return Password;
	}
	string getEmail()
	{
		return Email;
	}
	string getPhone()
	{
		return Phone;
	}
};

/* -----  Attendence Class Inherited from Files Class ----- */

class Attendence :public Files
{
	string ID;
	string Attend;

public:

	/* -----  Default Constructor ----- */

	Attendence()
	{
		ID = Attend = "";
	}

	/* -----  Parameterized Constructor ----- */

	Attendence(string ID, string Filename)
	{
		this->ID = ID;
		this->Attend = Attend;
	}

	/* -----  Parameterized Constructor ----- */

	Attendence(string ID, string Filename, string Attend, string FolderPath, string FilePath) :Files(Filename, FolderPath, FilePath)
	{
		this->ID = ID;
		this->Attend = Attend;
	}

	/* -----  Setter Functions ----- */

	void setID(string ID)
	{
		this->ID = ID;
	}
	void setAttend(string Attend)
	{
		this->Attend = Attend;
	}

	/* -----  Getter Functions ----- */

	string getID()
	{
		return ID;
	}
	string getAttend()
	{
		return Attend;
	}


	/* ----- File Handling Attendence Sheet Function ----- */

	void AttendenceSheet(string subject)
	{
		string Path = "Attendence/" + subject + "/Sheet.txt";
		ofstream save(Path, ios::app);
		ifstream check(Path, ios::in);

		save.close();
		check.close();

		string name = "Attendence/" + subject;
		if (!(isFileEmpty(check, name, "Sheet")))
		{
			save.open(Path, ios::app);
			save << endl;
			save.close();
		}
		save.open(Path, ios::app);
		save << getFileName();
		save.close();
	}
};

/* -----  Fees Class ----- */

class Fees : public Attendence
{
	string Semester[8];

public:

	/* -----  Default Counstructor ----- */

	Fees()
	{
		for (int i = 0; i < 8; i++)
		{
			Semester[i] = "UnPaid";
		};
	}

	/* -----  Parameterized Constructor ----- */

	Fees(string s1, string s2, string s3, string s4, string s5, string s6, string s7, string s8)
	{
		Semester[0] = s1;
		Semester[1] = s2;
		Semester[2] = s3;
		Semester[3] = s4;
		Semester[4] = s5;
		Semester[5] = s6;
		Semester[6] = s7;
		Semester[7] = s8;
	}

	/* -----  Fees Operator Overloading ----- */

	string& operator [](int index)
	{
		if (index - 1 >= 8)
		{
			cout << "Only 8 Semesters limits." << endl;
		}
		else
		{
			return Semester[index - 1];
		}
	}

	/* -----  Setter Function ----- */

	void setFees(int index, char ch)
	{
		if (ch == 'y' || ch == 'Y')
		{
			Semester[index - 1] = "Paid";
		}
		else if (ch == 'n' || ch == 'N')
		{
			Semester[index - 1] = "UnPaid";
		}
		else
		{
			cout << "Invalid Input." << endl;
		}
	}

	/* -----  Getter Function ----- */

	string getFees(int index)
	{
		return Semester[index - 1];
	}
};

/* -----  Exit Function ----- */

void Exit()
{
	string exit;
	cout << "Enter any key to exit : ";
	cin >> exit;

}

/* -----  Title Function ----- */

void Title(string name)
{
	cout << setfill('*') << setw(50) << "*" << endl;
	cout << "|" << setfill(' ') << setw(29) << name << setw(20) << "|" << endl;
	cout << setfill('*') << setw(50) << "*" << endl << endl;
}

/* -----  Student ID Sheet ----- */

void addIDtoSheet(string folder , string id)
{
	Files obj;

	obj.setFileName("ID");
	obj.setFolderPath(folder);

	ofstream Write(obj.getFilePath(), ios::app);
	ifstream Check(obj.getFilePath(), ios::in);
	Write.close();
	Check.close();

	if (!(isFileEmpty(Check,obj.getFolderPath(),obj.getFileName())))
	{
		Write.open(obj.getFilePath() , ios ::app);
		Write << endl;
		Write.close();
	}
	Write.open(obj.getFilePath(), ios::app);
	Write << id;
	Write.close();
}

/* -----  Add Student Function ----- */

void addProfile(string folder)
{
	system("cls");
	Title("Add Profile");
	char choice;
	do
	{
		Profile obj;
		string name, id, password, email, phone;

		cout << "Enter the Name : ";
		cin.ignore();
		getline(cin, name);
		cout << "Enter the ID : ";
		cin >> id;
		cout << "Enter the Password : ";
		cin >> password;
		cout << "Enter the Email : ";
		cin >> email;
		cout << "Enter the Phone : ";
		cin >> phone;

		if (folder != "Teacher")
		{
			addIDtoSheet("Attendence", id);
		}
		

		obj.setName(name);
		obj.setId(id);
		obj.setPassword(password);
		obj.setEmail(email);
		obj.setPhone(phone);
		obj.setFileName("Profile");
		obj.setFolderPath(folder);

		ofstream Write(obj.getFilePath(), ios::app);
		ifstream Check(obj.getFilePath(), ios::in);
		Write.close();
		Check.close();

		if (!isFileEmpty(Check, obj.getFolderPath(), obj.getFileName()))
		{
			Write.open(obj.getFilePath(), ios::app);
			Write << endl;
			Write.close();
		}

		Write.open(obj.getFilePath(), ios::app);
		Write << obj.getName() << endl;
		Write << obj.getId() << endl;
		Write << obj.getPassword() << endl;
		Write << obj.getEmail() << endl;
		Write << obj.getPhone();
		Write.close();

		cout << "\nDo you want add more Profile (y/n) : ";
		cin >> choice;

	}while (choice == 'y' || choice == 'Y');
}

/* ----- View Profile Function ----- */

void viewProfile(string folder, string ID)
{
	Profile obj;
	bool found = false;
	string exit;

	system("cls");
	Title("View Profile");

	if (ID == OrgPassword)
	{
		cout << "Enter the Id : ";
		cin >> ID;
	}
	obj.setFileName("Profile");
	obj.setFolderPath(folder);

	ifstream Read(obj.getFilePath(), ios::in);

	while (!Read.eof())
	{
		string name, id, password, email, phone;
		getline(Read, name);
		getline(Read, id);
		getline(Read,password );
		getline(Read, email);
		getline(Read, phone);

		obj.setName(name);
		obj.setId(id);
		obj.setPassword(password);
		obj.setEmail(email);
		obj.setPhone(phone);

		if (ID == id)
		{
			cout << "Name     : " << obj.getName() << endl;
			cout << "ID       : " << obj.getId() << endl;
			cout << "Password : " << obj.getPassword() << endl;
			cout << "Email    : " << obj.getEmail() << endl;
			cout << "Phone    : " << obj.getPhone() << endl <<endl;
			
			
			found = true;
			Exit();
		}
	}
	Read.close();

	if (found == false)
	{
		cout << "No Record Found." << endl;
		Exit();
	}
}

/* -----  Add Attendence Function ----- */

void setAttendence(string subject)
{
	system("cls");
	Title("Add Attendence");

	Attendence obj;

	cout << "Enter the Date : ";
	string date;
	cin >> date;
	obj.setFileName(date);

	string name = "Attendence/" + subject;
	obj.setFolderPath(name);

	obj.AttendenceSheet(subject);

	ofstream Write(obj.getFilePath(), ios::app);
	ifstream Read("Attendence/ID.txt", ios::in);
	ifstream file(obj.getFilePath(), ios::in);

	while (!Read.eof())
	{
		string Id, Attend;
		getline(Read, Id);

		obj.setID(Id);

		cout << obj.getID() << " : ";
		cin >> Attend;
		obj.setAttend(Attend);

		if ((isFileEmpty(file, name ,date)))
		{
			Write.open(obj.getFilePath(), ios::app);
			Write << endl;
			Write.close();
		}
		

		Write.open(obj.getFilePath(), ios::app);

		Write << obj.getID() << endl;
		Write << obj.getAttend();

		Write.close();
	}

	Read.close();

	Exit();
}

/* -----  View Attendence Function ----- */

void viewAttendence(string subject,string id)
{
	system("cls");
	Title("View Attendence");

	Attendence obj;

	if(id == OrgPassword)
	{
		cout << "Enter the id : ";
		cin >> id;
	}

	obj.setID(id);

	string Path = "Attendence/" + subject + "/Sheet.txt";

	ifstream Read(Path, ios::in);

	while (!Read.eof())
	{
		string Date;
		getline(Read, Date);
		
		obj.setFileName(Date);

		string name = "Attendence/" + subject;
		obj.setFolderPath(name);

		ifstream Check(obj.getFilePath(), ios::in);
		
		while (!Check.eof())
		{
			string id, attend;

			getline(Check, id);
			getline(Check, attend);

			if (id == obj.getID())
			{
				cout << obj.getFileName() << " : " << attend << endl;
			}
		}

		Check.close();
	}
	Read.close();

	Exit();
}

/* -----  Add Fee Function ----- */

void addfees()
{
	system("cls");
	Title("Add Fees");

	Fees obj;

	string sem,name,id,status;

	cout << "Enter ID : ";
	cin >> id;
	cout << "Enter Semester : ";
	cin >> sem;
	cout << "Enter Fee status (Paid/Unpaid) : ";
	cin >> status;

	name = "Semester" + sem;
	obj.setID(id);
	obj.setFileName(name);
	obj.setFolderPath("Fees");
	obj.setAttend(status);

	ofstream Write(obj.getFilePath() , ios ::app);
	ifstream checkin(obj.getFilePath(), ios::in);
	Write.close();
	checkin.close();

	if (!(isFileEmpty(checkin , "Fees" , name)))
	{
		Write.open(obj.getFilePath(), ios::app);
		Write << endl;
		Write.close();
	}

	Write.open(obj.getFilePath(), ios::app);
	Write << obj.getID() << endl;
	Write << obj.getAttend();

	Write.close();

	Exit();
}

/* -----  View Fee Function ----- */

void viewFees(string id)
{
	system("cls");
	Title("View Fees");

	bool found = false;

	Fees obj;
	string sem;
	if(id == OrgPassword)
	{
		cout << "Enter the id : " << endl;
		cin >> id;
	}
	cout << "Enter the Semester : ";
	cin >> sem;

	string name = "Semester" + sem;
	obj.setFileName(name);
	obj.setID(id);
	obj.setFolderPath("Fees");

	ifstream Read(obj.getFilePath(), ios::in);

	while (!Read.eof())
	{
		string id, status;
		
		getline(Read, id);
		getline(Read, status);
		
		if (id == obj.getID())
		{
			found = true;
			cout << "ID     : " << id << endl;
			cout << "Status : " << status << endl;
		}
	}
	Read.close();

	if (found == false)
	{
		cout << "No Record Found." << endl;
	}
	Exit();
}

/* -----  AddAttendence Function ----- */

void AddAttendence()
{
	int choice;

	do
	{
		system("cls");
		Title("Add Attendence");

		cout << "1. Object Oriented Programming    ( Theory )." << endl;
		cout << "2. Digital Logic design           ( Theory )." << endl;
		cout << "3. Discrete Structure             ( Theory )." << endl;
		cout << "4. Communication & Presentation   ( Theory )." << endl;
		cout << "5. Calculas & Analytical Geometry ( Theory )." << endl;
		cout << "6. Object Oriented Programming    ( Lab )." << endl;
		cout << "7. Digital Logic Design           ( Lab )." << endl;
		cout << "8. Exit." << endl << endl;


		cout << "Enter your Choice : ";
		cin >> choice;

		switch (choice)
		{
		case 1:setAttendence("OOP"); break;
		case 2:setAttendence("DLD"); break;
		case 3:setAttendence("DS"); break;
		case 4:setAttendence("CMP"); break;
		case 5:setAttendence("CALCULAS"); break;
		case 6:setAttendence("OOPLAB"); break;
		case 7:setAttendence("DLDLAB"); break;
		case 8:break;
		default: cout << "Invalid Choice.";
		}
	} while (choice != 8);
}

/* -----  View Attendence Function ----- */

void ViewAttendence(string id)
{
	int choice;

	do
	{
		system("cls");
		Title("View Attendence");

		cout << "1. Object Oriented Programming    ( Theory )." << endl;
		cout << "2. Digital Logic design           ( Theory )." << endl;
		cout << "3. Discrete Structure             ( Theory )." << endl;
		cout << "4. Communication & Presentation   ( Theory )." << endl;
		cout << "5. Calculas & Analytical Geometry ( Theory )." << endl;
		cout << "6. Object Oriented Programming    ( Lab )." << endl;
		cout << "7. Digital Logic Design           ( Lab )." << endl;
		cout << "8. Exit." << endl << endl;


		cout << "Enter your Choice : ";
		cin >> choice;

		switch (choice)
		{
		case 1:viewAttendence("OOP",id); break;
		case 2:viewAttendence("DLD",id); break;
		case 3:viewAttendence("DS",id); break;
		case 4:viewAttendence("CMP",id); break;
		case 5:viewAttendence("CALCULAS",id); break;
		case 6:viewAttendence("OOPLAB",id); break;
		case 7:viewAttendence("DLDLAB",id); break;
		case 8:break;
		default: cout << "Invalid Choice.";
		}
	} while (choice != 8);
}

/* -----  Login Function ----- */

bool login(string folder, string ID, string Password)
{
	Files obj;

	obj.setFileName("Profile");
	obj.setFolderPath(folder);

	ifstream Check(obj.getFilePath(), ios::in);

	while (!Check.eof())
	{
		string name, id, password, email, phone;

		getline(Check, name);
		getline(Check, id);
		getline(Check, password);
		getline(Check, email);
		getline(Check, phone);

		if (ID == id && Password == password)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
}

/* -----  Organization Portal ----- */

void Organization()
{
	int choice;
	string pass;
	
	system("cls");
	Title("Organization Portal");;

	do
	{
		cout << "Enter the Password : ";
		cin >> pass;

		if (pass == OrgPassword)
		{
			do
			{
				system("cls");

				Title("Organization Portal");

				cout << "1.Create Account of Student." << endl;
				cout << "2.Create Account Of Teacher." << endl;
				cout << "3.View Student Profile." << endl;
				cout << "4.View Teacher Profile." << endl;
				cout << "5.Add Attendence." << endl;
				cout << "6.View Attendnce." << endl;
				cout << "7.Add Fee." << endl;
				cout << "8.View Fee" << endl;
				cout << "9.Exit" << endl;

				cout << "Enter Your Choice : ";
				cin >> choice;

				switch (choice)
				{
				case 1:addProfile("Student"); break;
				case 2:addProfile("Teacher"); break;
				case 3:viewProfile("Student",OrgPassword); break;
				case 4:viewProfile("Teacher",OrgPassword); break;
				case 5:AddAttendence(); break;
				case 6:ViewAttendence(OrgPassword); break;
				case 7:addfees(); break;
				case 8:viewFees(OrgPassword); break;
				case 9:break;
				default: cout << "Invalid Choice.";
				}

			} while (choice != 9);
		}
		else
		{
			cout << "Invalid Password." <<endl;
		}
	} while (pass != OrgPassword);
}

/* -----  Student Portal ----- */

void Student()
{
	int choice,exit=0;
	string id, pass;

	system("cls");
	Title("Student Portal");


	do
	{
	
	cout << "Enter Id       : ";
	cin >> id;
	cout << "Enter Password : ";
	cin >> pass;

		/*system("cls");
		Title("Student Portal");*/

		if (login("Student", id, pass))
		{
			do
			{
				system("cls");

				Title("Student Portal");
				cout << "1. Profile. " << endl;
				cout << "2. Attendence. " << endl;
				cout << "3. Fees. " << endl;
				cout << "4.Exit" << endl << endl;
				cout << "Enter your choice : ";
				cin >> choice;

				switch (choice)
				{
				case 1:viewProfile("Student", id); break;
				case 2:ViewAttendence(id); break;
				case 3:viewFees(id); break;
				case 4:break;
				default:cout << "Invalid input." << endl;
				}
			} while (choice != 4);
		}
		else
		{
			int choose;
			cout << "Invalid ID or Password" <<endl;
			cout << "1.Try Again" << endl;
			cout << "2.Exit" << endl;
			cout << "Enter your choicce : ";
			cin >> choose;

			switch (choose)
			{
			case 1:exit = 1;break;
			case 2:exit = 2;break;
			default: cout << "Invalid Input." << endl;
			}
		}
	} while (!login("Student", id, pass) &&  exit !=2);
}

/* -----  Teacher Portal ----- */

void Teacher()
{
	int choice, exit = 0;
	string id, pass;

	system("cls");
	Title("Teacher Portal");


	do
	{

	cout << "Enter Id       : ";
	cin >> id;
	cout << "Enter Password : ";
	cin >> pass;

		/*system("cls");
		Title("Teacher Portal");*/

		if (login("Teacher", id, pass))
		{
			do {

				system("cls");

				Title("Teacher Portal");
				cout << "1. Profile. " << endl;
				cout << "2. Add Attendence. " << endl;
				cout << "3. View Attendence. " << endl;
				cout << "4. Exit." << endl << endl;

				cout << "Enter your choice : ";
				cin >> choice;

				switch (choice)
				{
				case 1:viewProfile("Teacher", id); break;
				case 2:AddAttendence(); break;
				case 3:ViewAttendence(id); break;
				case 4:break;
				default:cout << "Invalid input." << endl;
				}
			} while (choice != 4);
		}
		else
		{
			int choose;
			cout << "Invalid ID or Password" << endl;
			cout << "1.Try Again" << endl;
			cout << "2.Exit" << endl;
			cout << "Enter your choicce : ";
			cin >> choose;

			switch (choose)
			{
			case 1:exit = 1;break;
			case 2:exit = 2;break;
			default: cout << "Invalid Input." << endl;
			}
		}
	} while (!login("Teacher", id, pass) && exit != 2);
}

/* -----  Main Function ----- */

int main()
{
	int choice;

	do
	{
		system("cls");

		Title("Erp      ");
		cout << "1.Organization Portal." << endl;
		cout << "2.Sudent Portal." << endl;
		cout << "3.Teacher Portal." << endl;
		cout << "4.exit" << endl << endl;

		cout << "Enter Your Choice : ";
		cin >> choice;

		switch (choice)
		{
		case 1:Organization(); break;
		case 2:Student(); break;
		case 3:Teacher(); break;
		case 4:break;
		default: cout << "Invalid Choice.";
		}

	} while (choice!=4);
	
	return 0;
}

/* 
Line 10  -  Organization Portal Password
Line 14  -  Files Class
Line 72  -  IsFileEmpty Function
Line 107 -  Profile Class
Line 184 -  Attendence Class
Line 263 -  Fee Class 
Line 335 -  Exit Function
Line 345 -  Title Function
Line 354 -  AddIdtoSheet Function
Line 379 -  AddProfile Function
Line 443 -  ViewProfile Function
Line 501 -  AddAttendence Function
Line 556 -  viewAttendence Function
Line 609 -  AddFees Function
Line 654 -  viewFees Function
Line 703 -  AddAttendence Function Switch
Line 742 -  ViewAttendence Function Switch
Line 781 -  Login Function
Line 814 -  Organization Portal Function
Line 873 -  Student Portal Function
Line 919 -  Teacher Portal Function
Line 965 -  Main Function
*/