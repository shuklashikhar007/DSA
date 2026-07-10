#include <iostream>
using namespace std;

//=========================================================
// 1. Static Global Variable
//=========================================================

static int globalStatic = 100; // Visible only in this source file

//=========================================================
// 2. Static Global Function
//=========================================================

static void globalFunction() {
    cout << "Static Global Function Called\n";
}

//=========================================================
// 3. Static Local Variable
//=========================================================

void counter() {
    static int cnt = 0;   // Initialized only once
    cnt++;

    cout << "Counter = " << cnt << endl;
}

//=========================================================
// 4. Static Data Member & Static Member Function
//=========================================================

class Student {
private:
    int id;

public:
    // Shared by all Student objects
    static int totalStudents;

    Student(int id) {
        this->id = id;
        totalStudents++;
    }

    void display() {
        cout << "Student ID = " << id << endl;
    }

    static void showCount() {
        cout << "Total Students = "
             << totalStudents << endl;

        // ERROR:
        // cout << id;
        // Static functions cannot access non-static members.
    }
};

// Definition of static member
int Student::totalStudents = 0;

//=========================================================
// Main
//=========================================================

int main() {

    cout << "=========== Static Global Variable ===========" << endl;
    cout << globalStatic << endl;

    cout << "\n=========== Static Global Function ===========" << endl;
    globalFunction();

    cout << "\n=========== Static Local Variable ===========" << endl;

    counter();
    counter();
    counter();

    cout << "\n=========== Static Data Member ===========" << endl;

    Student s1(101);
    Student s2(102);
    Student s3(103);

    s1.display();
    s2.display();
    s3.display();

    cout << "\nAccess through class:" << endl;
    cout << Student::totalStudents << endl;

    cout << "\nAccess through object:" << endl;
    cout << s1.totalStudents << endl;

    cout << "\n=========== Static Member Function ===========" << endl;

    Student::showCount();

    return 0;
}