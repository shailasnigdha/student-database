#include<iostream>
using namespace std;
class DataBase;
class ShowData;
class AddData;
class EditData;           //5 class has been declared
class DeleteData;
string password="000";
void pass()//change password
{
    system("cls");
    int temp=4;
    string newpass,oldpass;
    while(temp--)
    {
        cout<<"\n\tEnter old password: ";
        cin>>oldpass;
        fflush(stdin);
        if(temp==1)
        {
            system("cls");
            cout<<"\n\n\tYou enter wrong password too many time.\n\tTry again later."<<endl;
            getchar();
            return;

        }
        if(oldpass==password)
            break;
        else
            cout<<"\n\tWrong password. Try again.";
            }
    cout<<"\tEnter new password: ";
    cin>>newpass;
    fflush(stdin);
    password=newpass;
    cout<<"\tYour new password is :"<<password<<endl<<endl;
    }
bool roll_valid(string troll)
{
    if(troll.size()>7|| troll.size()<7)
    {
        cout << "Invalid roll number. \nEnter a number of 7 digits" << endl;
        return 0;
    }
    else if(troll == "")
    {
        cout << "Invalid mobile no.\nMobile"
		"no cannot be blank" << endl;
        return 0;
    }
    else
        return 1;
}
static int count = 0; //to use as a friend class
class  DataBase
{
public:
    string name,num,dept,batch,email,roll;
    DataBase(): name(""), num(""), dept(""), batch(""), roll(""),email("") {}
    void setData(string new_name, string new_num, string new_dept,string new_batch,string new_roll,string emmail)
    {
        name=new_name;
        num= new_num;
        dept=new_dept;
        batch=new_batch;
        roll=new_roll;
        email= emmail;
    }
    friend   class showData;
    void display();
    friend class EditData;
    friend class ShowData;
};
void DataBase:: display()
{
    cout << name << "\t" << num << "\t" << dept <<"\t\t" <<batch<<"\t" <<roll<<"\t "<<email<< endl;
}
class AddData
{
public:

    DataBase *data1=new DataBase[count];
    void add();
    friend class EditData;
    friend class ShowData;
    friend  class showData;
    void displayA();
    void show(AddData &data,string search_term);
    void erase(AddData &data,string search_roll);
    void edit(AddData & data,string serial);
};
void AddData::displayA()
{
    for(int i = 0; i<count; i++)
    {
        data1[i].display();
    }
}
void AddData:: show(AddData &data,string search_term)
{
    for (int i = 0; i < count; i++)
    {
        if(search_term==data.data1[i].name || search_term==data.data1[i].dept || search_term==data.data1[i].batch
           || search_term==data.data1[i].roll)
        {
            cout << "NAME" << "\t" << "MOBILE NUMBER" << "\t" << "DEPARTMENT" <<"\t" << "BATCH" <<"\t" << "ROLL" <<
                "\t " << "EMAIL" << endl;
            cout << data.data1[i].name << "\t" << data.data1[i].num <<"\t"<<data.data1[i].dept<<"\t\t"<<
            data.data1[i].batch<<"\t"<<data.data1[i].roll<<"\t"<<data.data1[i].email<< endl;

        }
    }
}
void AddData::add()
{
    cout<<"how may student do you want to add in the database?"<<endl;
    int n;
    cin>>n;
    DataBase *temp = new DataBase[count];
    copy(data1,data1+count,temp);
    delete [] data1;
    data1 = new DataBase[n+count];
    copy(temp,temp+count,data1);
    delete [] temp;
    for(int i = count; i<n+count; i++)
    {
        string name,num,dept,batch,roll,email;
        cin.ignore();
        cout << "Enter Student name:" << endl;
        getline(cin, name);
        cout << "Enter Student number:" << endl;
        getline(cin,num);
        cout << "Enter department:" << endl;
        getline(cin, dept);
        cout << "Enter Student batch:" << endl;
        getline(cin, batch);
        cout << "Enter Student email:" << endl;
        getline(cin, email);
        do
        {
        cout << "Enter Student roll:" << endl;
        getline(cin,roll);
    }
    while(!roll_valid(roll));
    data1[i].setData(name,num,dept,batch,roll,email);
    }
count+=n;
};
class ShowData
{
public:
    friend class AddData;
};
class EditData
{
  void  edit(AddData & data,string serial);
};
void AddData:: edit(AddData & data,string serial)
{
    string new_name,new_num,new_dept,new_batch,new_roll,new_email;
    int t=0;
    string s="skip",p;
    for (int i = 0; i < count; i++)
    {
        if(data.data1[i].roll==serial)
        {
            system("cls");
            data.show( data,serial);
            cout<<"What do you want to edit?"<<endl;
            cout << "1.Edit name" << endl;
            cout << "2.Edit number" << endl;
            cout << "3.Edit department" << endl;
            cout <<"4.Edit batch"<<endl;
            cout << "5.Edit roll" << endl;
            cout << "6.Edit email" << endl;
            int p;
            cin>>p;
            switch(p)
        {case 1:
            cout << "Enter new name: ";
            cin >> new_name;
            data.data1[i].name = new_name;
            break;
        case 2:
            cout << "Enter new number: ";
            cin >> new_num;
            data.data1[i].num = new_num;
            break;
        case 3:
            cout << "Enter new department: ";
            cin >> new_dept;
            data.data1[i].dept = new_dept;
            break;
        case 4:
            cout << "Enter new batch: ";
            cin >> new_batch;
            data.data1[i].batch = new_batch;
            break;
        case 5:
            cout << "Enter new roll: ";
            cin >> new_roll;
            data.data1[i].roll = new_roll;
            break;
        case 6:
            cout << "Enter new email: ";
            cin >> new_email;
            data.data1[i].email = new_email;
            break;}
            t=1;
        }
        system("cls");
    }

    if(t)
    {
        cout << "Edited Successfully!" << endl;
    }
    else cout<<"wrong input!!!";

}
class DeleteData
{
    friend erase(AddData &data,string search_roll) ;
};
void AddData::erase(AddData &data,string search_roll)
{
    int g=0;
    for (int i = 0; i < count; i++)
    {
        if(data.data1[i].roll==search_roll)

        {
            data.data1[i].name = " ";
            data.data1[i].num=" ";
            data.data1[i].dept = " ";
            data.data1[i].batch=" ";
            data.data1[i].roll=" ";
            data.data1[i].email=" ";
            cout<<"delete successful!"<<endl;
            g=1;
            break;
        }
        if(g==0)
            cout<<"wrong roll number"<<endl;
    }

}
int main()
{
    AddData data;
    int choice;
    cout<<"Please enter the database INFOBOOK password"<<endl;
    string p;
    int nul=3;
    while(nul--)
    {
        getline(cin,p);
        if(password==p)
        {
            system("cls");
            do
            {
                cout << "\n\t\t\t\t\tDatabase Of KUET students\n\n" << endl;
                cout << "1.Add Data" << endl;
                cout << "2.Show Data" << endl;
                cout << "3.Edit Data" << endl;
                cout <<"4.Search Data"<<endl;
                cout << "5.Delete Data" << endl;
                cout<<"6.Change Password"<<endl;
                cout << "0.Exit" << endl;
                cin >> choice;
                if(choice==1)
                {
                    data.add();
                    system("cls");
                }
                else if (choice==2)
                {
                    system("cls");
                    cout<<"Database of total..." <<count<<" student"<<endl;
                    cout << "NAME" << "\t" << "MOBILE NUMBER" << "\t" << "DEPARTMENT" <<"\t" << "BATCH" <<
                    "\t" << "ROLL" <<"\t " << "EMAIL" << endl;
                    data.displayA( );
                }
                else if(choice==3)
                {
                    system("cls");
                    string search_term;
                    cout << "Enter the roll to edit:";
                    cin >>search_term;
                    data.edit( data,search_term);
                }
                else if(choice==4)
                {
                    system("cls");
                    cout<<"search by name/department/batch/roll "<<endl;
                    string search_term;
                    cin>>search_term;
                    data.show(data,search_term);
                }
                else if(choice==5)
                {
                    system("cls");
                    cout<<"delete by roll"<<endl;
                    string search_roll;
                    cout<<"roll:";
                    cin>>search_roll;
                    data.erase(data,search_roll);
                }
                else if(choice==6)
                {
                    pass();
                }
                else if(choice==0)
                {
                    return 0;
                    break;
                }
                else
                {
                    cout<<"Please,enter valid option."<<endl;
                }
            }
            while(choice!=0) ;
        }
        else
        {
            cout<<"Wrong password"<<endl;
            return 0;
            break;
            }
        }
    return 0;
    }
