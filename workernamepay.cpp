#include <iostream>
#include <string>

using namespace std;

class Person 
{
    public:
        Person(const string name, const string birthday)
            : name(name), birthday(birthday) {}
    
        void print() const 
        {
            cout<<"This person's name is: " <<name<< " and their birthday is: "<<birthday;
        }

private:
    string name;
    string birthday;
};

class Student : public Person 
{
public:
    Student(const string& name, const string& birthday, const string& major)
        : Person(name, birthday), major(major) {}

    void print() const 
    {
        Person::print();
        cout << " and the student's major is: " <<major<<endl;
    }

private:
    string major;
};

class Instructor : public Person 
{
public:
    Instructor(const string& name, const string& birthday, double salary)
        : Person(name, birthday), salary(salary) {}
    void print() const 
    {
        Person::print();
        cout << " and the instructor's salary is: "<<salary<<endl;
    }

private:
    double salary;
};

class Worker 
{
public:
    Worker(const string& name, double salaryrate)
        : name(name), salaryrate(salaryrate) {}
        
    virtual double compute_pay(int hours) const = 0;
    
    string getName() const 
    {
        return name;
    }
    
protected:
    string name;
    double salaryrate;
};

class HourlyWorker : public Worker 
{
public:
    HourlyWorker(const string& name, double hourlyrate)
        : Worker(name, hourlyrate) {}

    double compute_pay(int hours) const override 
    {
        if (hours <= 40) 
        {
            double finalpay = hours * salaryrate;
            return finalpay;
        } 
        else 
        {
            double regularpay = 40 * salaryrate;
            double overtimepay = (hours - 40) * 1.5 * salaryrate;
            double finalpay = regularpay + overtimepay;
            return finalpay;
        }
    }
};

class SalariedWorker : public Worker 
{
public:
    SalariedWorker(const string& name, double weeklysalary)
        : Worker(name, weeklysalary / 40) {}  
        
    double compute_pay(int hours) const override 
    {
        double salary = salaryrate*40;
        return salary;
    }
};

int main() 
{
    Student student("Aldair Perez", "10 24 05", "Computer Science");
    Instructor instructor("John Doe", "01 01 90", 90000);

    student.print();
    cout << "\n--------------------------------------------------------------------------------------------------------------\n\n";
    instructor.print();

    HourlyWorker hourlyworker("Summrs", 67);
    SalariedWorker salariedworker("Autumn", 4000);

    cout << "\nThe weekly pay for hourly worker "<<hourlyworker.getName()<<" is "<<hourlyworker.compute_pay(55)<<endl;
    cout << "\n-------------------------------------------------\n\n";
    cout << "The weekly pay for salaried worker "<<salariedworker.getName()<<" is "<<salariedworker.compute_pay(20)<<endl;

    return 0;
}

