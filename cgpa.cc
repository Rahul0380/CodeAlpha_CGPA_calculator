#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
class subject
{
    public:
    string subjectname;
    int credit;
    float gradepoints;
    //constructor
    subject(string name,int cr,float gp){
        subjectname=name;
        credit=cr;
        gradepoints=gp;
    }
};
class student
{
    public:
    string name;
    vector<subject>subjects;
    //constructor
    student(string studentname){
        name=studentname;
    }
    void addsubject(string subjectname,int credit,float gradepoint)
    {
        subject newsubject(subjectname,credit,gradepoint);
        subjects.push_back(newsubject);
    }
    float calculatecgpa()
    {
        int totalcredit=0;
        float weightgradepoint=0;
        for(const subject & subject:subjects)
        {
            totalcredit += subject.credit;
            weightgradepoint += subject.credit*subject.gradepoints;

        }
        return(totalcredit>0)?(weightgradepoint/totalcredit):0;
    }
    void displaycgpa()
    {
        cout<<"student name :"<<name<<endl;
        float cgpa=calculatecgpa();
        cout<<"CGPA"<<cgpa<<endl;
    }
    //void addsubject(string subjectname,int credit,float gradepoint);
};

int main(){
    string studentname;
    int numsub;

    cout<<"Enter Student's name : ";
    getline(cin,studentname);

    cout<<"Enter the number of subjects :  ";
    cin>>numsub;
    student student(studentname);

    for(int i=0;i<numsub;i++)
    {
        string subjectname;
        int credit;
        float gradepoints;

        cout<<"Enter the subject's name : ";
        cin.ignore();
        getline(cin,subjectname);

        cout<<"Enter the credit : ";
        cin>>credit;

        cout<<"Enter a gradepoint : ";
        cin>>gradepoints;
        student.addsubject(subjectname,credit,gradepoints);
       
    }
    student.displaycgpa();
    return 0;
}