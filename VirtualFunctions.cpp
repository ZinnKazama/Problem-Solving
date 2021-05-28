#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person{
    public:
        string name;
        int age;
        
        virtual void getdata(){
            cin >> this->name >> this->age;
        }
        
        virtual void putdata(){
            cout << this->name << " " << this->age;
        }
};

class Professor : public Person{
    public:
    
        Professor(){
            this->cur_id = ++id;
        }
        int publications;
        static int id;
        int cur_id;
        
        
        virtual void getdata(){
            cin >> this->name >> this->age >> this->publications;
        }
        virtual void putdata(){
            cout << this->name << " " << this->age << " " << this->publications << " " << this->cur_id << endl;
        }
};

int Professor::id = 0;
class Student : public Person{
    public:
        Student(){
            this->cur_id = ++id;
        }
        int cur_id;
        static int id;
        int marks[6];
        
        virtual void getdata(){
            cin >> this->name >> this->age;
            for(int i=0; i<6; i++){
                cin >> marks[i];
            }
        }
        
        virtual void putdata(){
            int marksSum = 0;
            for(int j=0; j<6; j++){
                marksSum += marks[j];
            }
            
            cout << this->name << " " << this->age << " " << marksSum << " " << this->cur_id << endl;
        }
};

int Student::id = 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
