#include <iostream>
using namespace std;

const int maxCourseSize = 50;

class Course {
private:
    string courseCode;
    string courseName;
    int maxCapacity;
    int enrolledStudents;

public:

    Course() {
    courseCode = "";
    courseName = "";
    maxCapacity = 0;
    enrolledStudents = 0;
}

    Course(string code, string name, int capacity) {
        courseCode = code;
        courseName = name;
        maxCapacity = capacity;
        enrolledStudents = 0;
    }

    
    string getCode() { return courseCode; }
    string getName() { return courseName; }

    bool sizeCheck (){
        if (enrolledStudents >= maxCapacity){
            return true;
        }
        else {
            return false;
        }
    }  

    void displayDetails() {
        cout << " " << endl << "> Course-Code: " << courseCode << endl << " " << endl << "> Course-Name: " << courseName << endl << " " << endl << "> Sit-Capacity: " << maxCapacity << endl << " " << endl << "> Enrolled-student: " << enrolledStudents << endl << "============" << endl;
    }

    void registerStudent() {
        if (sizeCheck()) {
            cout << " Course is full! You can't enrol." << endl;
        } else {
            enrolledStudents++;
            cout << "Registration successful." << endl;
        }
    }

    void dropStudent() {
        if (enrolledStudents > 0) {
            enrolledStudents--;
            cout << "Student dropped successfull." << endl;
        } else {
            cout << "No students currently enrolled in this course." << endl;
        }
    }
};

class RegistrationSystem {
private:
Course courses[maxCourseSize];

int courseCount;

public:
    RegistrationSystem() {
        courseCount = 0;
    }

    void creatCourses() {
        if (courseCount >= maxCourseSize) {
            cout << "System Error: Cannot add more courses (Array Overflow)." << endl;
            return;
        }

        string code, name;

        int cap;

        cout << "Enter Course Code: "; 
        cin >> code;
        cout << "Enter Course Name: "; 
        cin.ignore(); 
        getline(cin, name);
        cout << "Enter Max Capacity of sit: "; 
        cin >> cap;

        for (int i = 0; i < courseCount; i++) {
           if(courses[i].getName() == name && courses[i].getCode() == code){
            cout << "==================" << endl;
            cout << "Course can't be copyed or duplicate";
            return;
           }
       }
        courses[courseCount++] = Course(code, name, cap);

        cout << "Course added successfully!" << endl;
        
        cout << "Total course: " << courseCount << endl;
    }

    void search() {
        string query;
        cout << "Enter Course Code or Name to search: ";
        cin >> query;
        bool found = false;
        for (int i = 0; i < courseCount; i++) {
            if (courses[i].getCode() == query || courses[i].getName() == query) {
                courses[i].displayDetails();
                found = true;
            }
        }
        if (!found) cout << "Course not found." << endl;
    }

    void courseDrop(){
        
        if(courseCount <= 0){
             cout << "Courses are not added yet! Please add course first " << endl;
             return;
        }

        string code;
        cout << "Enter Course Code: "; cin >> code;
        for (int i = 0; i < courseCount; i++) {
            if (courses[i].getCode() == code) {
                courses[i].dropStudent();
                return;
            }
        }
        cout << "Invalid Course Code." << endl;
    }

    
    void courseRegister(){

                if(courseCount <= 0){
             cout << "Courses are not added yet! Please add course first " << endl;
             return;
        }

        string code;
        cout << "Enter Course Code: "; cin >> code;
        for (int i = 0; i < courseCount; i++) {
            if (courses[i].getCode() == code) {
                courses[i].registerStudent();
                return;
            }
        }
        cout << "Invalid Course Code." << endl;
    }

    void generateFullReport() {
        cout << "\n>> All Courses Report <<" << endl;
        for (int i = 0; i < courseCount; i++) {
            courses[i].displayDetails();
        }
        cout << "Total course: " << courseCount << endl;
    }

    void generateFullCapacityReport() {
        cout << "\n>> Full Courses Only <<" << endl;
        for (int i = 0; i < courseCount; i++) {
            if (courses[i].sizeCheck()) {
                courses[i].displayDetails();
            }
        }

        if(courseCount <= 0){
             cout << "Courses are not added yet! Please add course first " << endl;
        }
    }
};

int main() {
    RegistrationSystem system;
    int option;

    do {
        cout << "\n---> Student Course Registration System <---" << endl;
        cout << "1. Add Course" << endl;
        cout << "2. Register Student" << endl;
        cout << "3. Drop Student" << endl;
        cout << "4. Search Course" << endl;
        cout << "5. Full Course Report" << endl;
        cout << "6. Full Capacity Report" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter the menu number: ";

        cin >> option;

        switch (option) {
            case 1: system.creatCourses(); break;
            case 2: system.courseRegister(); break;
            case 3: system.courseDrop(); break;
            case 4: system.search(); break;
            case 5: system.generateFullReport(); break;
            case 6: system.generateFullCapacityReport(); break;
            case 0: cout << ">> Exiting <<" << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    } while (option != 0);

    return 0;
}
