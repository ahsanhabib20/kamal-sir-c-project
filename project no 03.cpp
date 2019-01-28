#include<bits/stdc++.h>
using namespace std;
class Person
{
    string name,birthday;

public:
    Person() {};
    Person(string name,string birthday)
    {
        this->name=name;
        this->birthday=birthday;
    }
    void viewPerson();
};
 void Person :: viewPerson()
    {
        cout<<"Member Name : "<<this->name<<endl;
        cout<<"Birthday : "<<this->birthday<<endl;
    }
class Department
{
    string department_name;
public:
    Department() {};
    Department(string department_name)
    {
        this->department_name=department_name;
    }
    void view_Department();
};
inline void Department :: view_Department()
    {
        cout<<"Department : "<<this->department_name<<endl;
    }
class Student_Information : public Person
{
    int roll;
    Department department;
public:
    Student_Information() {};
    Student_Information(int roll ,Department dept) {
      this->roll=roll;
        department=dept;
    };
     Student_Information(string name,string birthday,int roll,Department dept) : Person(name,birthday)
    {
        this->roll=roll;
        department=dept;
    }
    Person doc1;
    void getdata1(Person INFO,int roll,Department dept)
    {
        this->roll=roll;
        doc1=INFO;
        department=dept;
    }
    void viewStudent();
};
void Student_Information :: viewStudent()
    {
        viewPerson();
        department.view_Department();
        cout<<"Roll NO. : "<<this->roll<<endl;
    }
class Teacher_Information : public Person
{
    int teacher_id;
public:
    Teacher_Information() {};
    Person doc;
    Department department;
    void getdata(Person data,int teacher_id,Department dept);
};
 void Teacher_Information :: getdata(Person data,int teacher_id,Department dept)
    {
        doc=data;
        this->teacher_id=teacher_id;
        department=dept;
    }
class Society_member : public Student_Information,public Person
{
    string designation;
public:
    Society_member() {};
   Society_member(string name,string birthday,int roll,Department department,string deisgnation): Student_Information(name,birthday,roll,department)
    {
        this->designation=designation;
    }
    void view_memberInfo();
};
 void Society_member :: view_memberInfo()
    {
        cout<<"Society Member Information : "<<endl;
        viewStudent();
        cout<<"Designation : "<<this->designation<<endl;
    }
int main()
{
    Department department("Computer_Science_&_Engineering");
    Teacher_Information object[5];
        object[0].getdata(Person("Kamal Hossain Chowdhury","03-05-1978"),2,department);
        object[1].getdata(Person("Partha Chakraborthy","04-02-1977"),2,department);
        object[2].getdata(Person("Hasan Hafizur Rahman","20-02-1975"),1,department);
        object[3].getdata(Person("Faisal Bin Abdul Aziz","11-02-1982"),3,department);
        object[4].getdata(Person("Mahmudul Hasan","11-11-1979"),3,department);

    Student_Information object1[10];
        object1[0].getdata1(Person("Ahsan Habib ","24-03-1997"),11708011,department);
        object1[1].getdata1(Person("Samiul Romel","01-10-1996"),11708001,department);
        object1[2].getdata1(Person("Rakibul Hasan","16-03-1997"),11708020,department);
        object1[3].getdata1(Person("Mehedi Hasan","12-07-1996"),11708041,department);
        object1[4].getdata1(Person("Mahmudul Nahid","11-05-1997"),11708032,department);
        object1[5].getdata1(Person("Helal Khan","08-08-1997"),11708007,department);
        object1[6].getdata1(Person("Asif Sayed","03-03-1998"),11708009,department);
        object1[7].getdata1(Person("Tahseen Sweety","06-06-1998"),11708045,department);
        object1[8].getdata1(Person("Jannat Rinky","11-11-1997"),11708046,department);
        object1[9].getdata1(Person("Rakib Rayans","12-12-1996"),11708016,department);
    Society_member *members[5]=
    {
        new Society_member("Dipto Das","11-02-1992",11508012,department,"Member"),
        new Society_member("Umme Fomey","13-11-1996",11608011,department,"Member"),
        new Society_member("Ahsan Habib","24-03-1997",11708011,department,"Member"),
        new Society_member("Jawad Shafi","17-01-1997",11708029,department,"Member"),
        new Society_member("Mamunur Rahman","15-11-1997",11708042,department,"Member")
    };
    int teacherskill[3][2]= {(2,3),(3,3),(2,4)};
    int studentpoint[3][2]= {(2,2),(3,2),(3,3)};
    int finalresult[2];
    for(int i=0; i<2; i++)
    {
        int sum=0;
        for(int j=0; j<3; j++)
        {
            sum+=teacherskill[j][i]+studentpoint[j][i];
        }
        finalresult[i]=sum;
    }
    cout<<"Best Member In CSE Society :"<<endl;
    cout<<endl;
    for(int i=0; i<5; i++)
    {
        members[i]->viewStudent();
        cout<<endl;
    }
    return 0;
}

/*Sample Output :
Best Member In CSE Society :

Member Name : Rajib Paul
Birthday : 11-02-1992
Department : Computer_Science_&_Engineering
Roll NO. : 11508012

Member Name : Mohibur Rahman
Birthday : 13-11-1996
Department : Computer_Science_&_Engineering
Roll NO. : 11608011

Member Name : Saiful Alam
Birthday : 18-11-1998
Department : Computer_Science_&_Engineering
Roll NO. : 11708041

Member Name : Ifat Hossain Rony
Birthday : 17-01-1997
Department : Computer_Science_&_Engineering
Roll NO. : 11708029

Member Name : Afzal Hossain Rony
Birthday : 15-11-1997
Department : Computer_Science_&_Engineering
Roll NO. : 11708042
*/

