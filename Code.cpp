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

    bool isFull() {
        return enrolledStudents > maxCapacity;
    }

    void displayDetails() {
        cout << "Code: " << courseCode << " --|-- Name: " << courseName 
             << " --|-- Capacity: " << maxCapacity << " --|-- Enrolled: " << enrolledStudents << endl;
    }

    void registerStudent() {
        if (isFull()) {
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
            cout << "6No students currently enrolled in this course." << endl;
        }
    }
};

class RegistrationSystem {
private:
    Course courses[maxCourseSize];
    int courseCount;

public:
    RegistrationSystem() : courseCount(0) {}

    void addCourse() {
        if (courseCount >= maxCourseSize) {
            cout << "System Error: Cannot add more courses (Array Overflow)." << endl;
            return;
        }

        string code, name;
        int cap;
        cout << "Enter Course Code: "; cin >> code;
        cout << "Enter Course Name: "; cin.ignore(); getline(cin, name);
        cout << "Enter Max Capacity of sit: "; cin >> cap;

        courses[courseCount++] = Course(code, name, cap);
        cout << "Course added successfully!" << endl;
    }

    void searchCourse() {
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

    void manageRegistration(bool isRegistering) {
        string code;
        cout << "Enter Course Code: "; cin >> code;
        for (int i = 0; i < courseCount; i++) {
            if (courses[i].getCode() == code) {
                if (isRegistering) courses[i].registerStudent();
                else courses[i].dropStudent();
                return;
            }
        }
        cout << "Invalid Course Code." << endl;
    }

    void generateFullReport() {
        cout << "\n--->> All Courses Report <<---" << endl;
        for (int i = 0; i < courseCount; i++) {
            courses[i].displayDetails();
        }
    }

    void generateFullCapacityReport() {
        cout << "\n--->> Full Courses Only <<---" << endl;
        for (int i = 0; i < courseCount; i++) {
            if (courses[i].isFull()) {
                courses[i].displayDetails();
            }
        }
    }
};

int main() {
    RegistrationSystem system;
    int choice;

    do {
        cout << "\n---> Student Course Registration System <---" << endl;
        cout << "1. Add Course\n2. Register Student\n3. Drop Student\n4. Search Course\n5. Full Course Report\n6. Full Capacity Report\n0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> option;

        switch (option) {
            case 1: system.addCourse(); break;
            case 2: system.manageRegistration(true); break;
            case 3: system.manageRegistration(false); break;
            case 4: system.searchCourse(); break;
            case 5: system.generateFullReport(); break;
            case 6: system.generateFullCapacityReport(); break;
            case 0: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}
