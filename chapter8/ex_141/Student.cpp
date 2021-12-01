//
// Created by liaohui on 2021/11/18.
//
#include<iostream>
using namespace std;

class Student
{
    static int cnt;
    char *num;
    char *name;
    double grade[3];
    static double sum1, sum2, sum3;
public:
    Student(char name[10], char num[12], double grade1, double grade2, double grade3);
    double average1();
    double average2();
    double average3();
    void display();
    Student(char *name, int *num, double grade1, double grade2, double grade3);
    ~Student();
};
int Student:: cnt = 0;
double Student::sum1 = 0;
double Student::sum2 = 0;
double Student::sum3 = 0;
Student::Student(char *name, char *num, double grade1, double grade2, double grade3)
{
    this->name = name;
    this->num = num;
    this->grade[0] = grade1;
    this->grade[1] = grade2;
    this->grade[2] = grade3;
    this->sum1 += grade1;
    this->sum2 += grade2;
    this->sum3 += grade3;
    this->cnt++;
}
double Student:: average1()
{
    return (sum1/cnt);
}
double Student:: average2()
{
    return (sum2/cnt);
}
double Student::average3()
{
    return (sum3 / cnt);
}
void Student::display()
{
    cout << num << ' ' << name << ' ' << grade[0] << ' ' << grade[1] << ' ' << grade[2]<<endl;
}

Student::~Student()
{
}
int main(){
    Student *stu1,*stu2,*stu3;
    char name1[10],name2[10],name3[10];
    char num1[12],num2[12],num3[12];
    int grade1[3],grade2[3],grade3[3];
    cin>>num1>>name1>>grade1[0]>>grade1[1]>>grade1[2];
    cin>>num2>>name2>>grade2[0]>>grade2[1]>>grade2[2];
    cin>>num3>>name3>>grade3[0]>>grade3[1]>>grade3[2];
    stu1 = new Student(name1,num1,grade1[0],grade1[1],grade1[2]);
    stu2 = new Student(name2,num2,grade2[0],grade2[1],grade2[2]);
    stu3 = new Student(name3,num3,grade3[0],grade3[1],grade3[2]);

    stu1->display();
    stu2->display();
    stu3->display();

    cout<<"The average grade of course1:"<<stu2->average1()<<endl;
    cout<<"The average grade of course2:"<<stu2->average2()<<endl;
    cout<<"The average grade of course3:"<<stu2->average3()<<endl;
    return 0;
}