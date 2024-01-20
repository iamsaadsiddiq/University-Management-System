#include <iostream>
#include <fstream>
using namespace std;
const int MAX_COURSES = 5;
const int MAX_COURSE_CODE_LENGTH = 10;
const int MAX_STUDENTS = 100;

void printString(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
         cout << str[i];
    }
}

bool compareStrings(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    return (str1[i] == '\0' && str2[i] == '\0');
}

void loadCoursesFromFile(const char* filename, char courses[][MAX_COURSE_CODE_LENGTH], int* creditHours) {
    ifstream file(filename);
    if (!file) {
        cout << "Failed to open file: " << filename << endl;
        return;
    }

    for (int i = 0; i < MAX_COURSES; i++) {
        file.getline(courses[i], MAX_COURSE_CODE_LENGTH);
        file >> creditHours[i];
        file.ignore(); // Ignore the newline character

        if (!file) {
            cout << "" << endl;
            return;
        }
    }

    file.close();
}
void enrollStudent(char enrollments[][5][MAX_COURSE_CODE_LENGTH], int& numEnrollments, const char courses[][MAX_COURSE_CODE_LENGTH], const int* creditHours) {
    if (numEnrollments == MAX_STUDENTS) {
         cout << "Maximum number of students reached.\n";
        return;
    }

    int studentId;
     cout << "Enter student ID: ";
     cin >> studentId;

    // Check if the student is already enrolled in any course
    for (int i = 0; i < numEnrollments; i++) {
        if (enrollments[i][0][0] == studentId) {
             cout << "Student is already enrolled in a course.\n";
            return;
        }
    }

     cout << "Available courses:\n";
    for (int i = 0; i < MAX_COURSES; i++) {
         cout << i + 1 << ". ";
        printString(courses[i]);
         cout << " (" << creditHours[i] << " credit hours)\n";
    }

    int courseChoice;
     cout << "Choose a course: ";
     cin >> courseChoice;
    courseChoice--;  // Adjusting for array index

    if (courseChoice < 0 || courseChoice >= MAX_COURSES) {
         cout << "Invalid course choice.\n";
        return;
    }

    // Check if the course is already enrolled by another student
    for (int i = 0; i < numEnrollments; i++) {
        if (compareStrings(enrollments[i][1], courses[courseChoice])) {
             cout << "Course is already enrolled by another student.\n";
            return;
        }
    }

    int sectionChoice;
     cout << "Choose a section (A, B, C, D, E): " << endl;
    cout << "Press 0 for Section A" << endl;
    cout << "Press 1 for Section B" << endl;
    cout << "Press 2 for Section C" << endl;
    cout << "Press 3 for Section D" << endl;
    cout << "Press 4 for Section E" << endl;

     cin >> sectionChoice;

    if (sectionChoice < 0 || sectionChoice >= 5) {
         cout << "Invalid section choice.\n";
        return;
    }

    char section = 'A' + sectionChoice;

    // Save enrollment information
    enrollments[numEnrollments][0][0] = studentId;
    for (int i = 0; i < MAX_COURSE_CODE_LENGTH; i++) {
        enrollments[numEnrollments][1][i] = courses[courseChoice][i];
    }
    enrollments[numEnrollments][2][0] = creditHours[courseChoice] + '0';
    enrollments[numEnrollments][3][0] = section;
    enrollments[numEnrollments][4][0] = '\0';

    numEnrollments++;

     cout << "Student enrolled successfully.\n";
}

void dropCourse(char enrollments[][5][MAX_COURSE_CODE_LENGTH], int& numEnrollments) {
    if (numEnrollments == 0) {
         cout << "No students are currently enrolled.\n";
        return;
    }

    int studentId;
     cout << "Enter student ID: ";
     cin >> studentId;

    bool found = false;
    for (int i = 0; i < numEnrollments; i++) {
        if (enrollments[i][0][0] == studentId) {
            // Delete the enrollment record by shifting the remaining records
            for (int j = i; j < numEnrollments - 1; j++) {
                for (int k = 0; k < 5; k++) {
                    for (int l = 0; l < MAX_COURSE_CODE_LENGTH; l++) {
                        enrollments[j][k][l] = enrollments[j + 1][k][l];
                    }
                }
            }
            found = true;
            numEnrollments--;
            break;
        }
    }

    if (found) {
         cout << "Course dropped successfully.\n";
    }
    else {
         cout << "Student not found or not enrolled in any course.\n";
    }
}

void listEnrolledCourses(const char enrollments[][5][MAX_COURSE_CODE_LENGTH], int numEnrollments, int studentId) {
    bool found = false;
     cout << "Enrolled courses for student ID " << studentId << ":\n";
    for (int i = 0; i < numEnrollments; i++) {
        if (enrollments[i][0][0] == studentId) {
            found = true;
            printString(enrollments[i][1]);
             cout << " (" << enrollments[i][2][0] << " credit hours, Section " << enrollments[i][3][0] << ")\n";
        }
    }
    if (!found) {
         cout << "Student not found or not enrolled in any course.\n";
    }
}

void updateCourseSection(char enrollments[][5][MAX_COURSE_CODE_LENGTH], int numEnrollments) {
    if (numEnrollments == 0) {
         cout << "No students are currently enrolled.\n";
        return;
    }

    int studentId;
     cout << "Enter student ID: ";
     cin >> studentId;

    bool found = false;
    for (int i = 0; i < numEnrollments; i++) {
        if (enrollments[i][0][0] == studentId) {
             cout << "Current course section: " << enrollments[i][3][0] <<  endl;

            int sectionChoice;
             cout << "Choose a section (A, B, C, D, E): " << endl;
            cout << "Press 0 for Section A" << endl;
            cout << "Press 1 for Section B" << endl;
            cout << "Press 2 for Section C" << endl;
            cout << "Press 3 for Section D" << endl;
            cout << "Press 4 for Section E" << endl;
             cin >> sectionChoice;

            if (sectionChoice < 0 || sectionChoice >= 5) {
                 cout << "Invalid section choice.\n";
                return;
            }

            char newSection = 'A' + sectionChoice;
            enrollments[i][3][0] = newSection;
            found = true;
            break;
        }
    }

    if (found) {
         cout << "Course section updated successfully.\n";
    }
    else {
         cout << "Student not found or not enrolled in any course.\n";
    }
}

void displayTotalEnrolledStudents(const char enrollments[][5][MAX_COURSE_CODE_LENGTH], int numEnrollments, const char* courseCode) {
    int count = 0;
    for (int i = 0; i < numEnrollments; i++) {
        if (compareStrings(enrollments[i][1], courseCode)) {
            count++;
        }
    }
     cout << "Total enrolled students in course " << courseCode << ": " << count <<  endl;
}

void displayUnenrolledCourses(const char enrollments[][5][MAX_COURSE_CODE_LENGTH], int numEnrollments, const char courses[][MAX_COURSE_CODE_LENGTH]) {
    bool enrolled[MAX_COURSES] = { false };

    for (int i = 0; i < numEnrollments; i++) {
        for (int j = 0; j < MAX_COURSES; j++) {
            if (compareStrings(enrollments[i][1], courses[j])) {
                enrolled[j] = true;
                break;
            }
        }
    }

     cout << "Courses not enrolled by any student:\n";
    for (int i = 0; i < MAX_COURSES; i++) {
        if (!enrolled[i]) {
            printString(courses[i]);
             cout <<  endl;
        }
    }
}

int getNumCoursesEnrolled(const char enrollments[][5][MAX_COURSE_CODE_LENGTH], int numEnrollments, int studentId) {
    int count = 0;
    for (int i = 0; i < numEnrollments; i++) {
        if (enrollments[i][0][0] == studentId) {
            count++;
        }
    }
    return count;
}

void searchMinCoursesRegistered(const char enrollments[][5][MAX_COURSE_CODE_LENGTH], int numEnrollments) {
    int minCourses = MAX_COURSES;
    int studentId = -1;

    for (int i = 0; i < numEnrollments; i++) {
        int numCourses = 0;
        int j = 0;
        while (enrollments[i][j][0] != '\0') {
            if (enrollments[i][j][0] >= '0' && enrollments[i][j][0] <= '9') {
                numCourses++;
            }
            j++;
        }

        if (numCourses < minCourses) {
            minCourses = numCourses;
            studentId = enrollments[i][0][0];
        }
    }

    if (studentId != -1) {
        cout << "Student with minimum courses registered: " << studentId << endl;
    }
    else {
        cout << "No students are currently enrolled.\n";
    }
}


int main() {
    char courses[MAX_COURSES][MAX_COURSE_CODE_LENGTH];
    int creditHours[MAX_COURSES] = { 4, 3, 3, 3, 3 };
    char enrollments[MAX_STUDENTS][5][MAX_COURSE_CODE_LENGTH];
    int numEnrollments = 0;
    int choice;
    loadCoursesFromFile("Courses.txt", courses, creditHours);
   

    do {
         cout << "---------------------------------------\n";
         cout << "University Management System\n";
         cout << "---------------------------------------\n";
         cout << "1. Enroll a student\n";
         cout << "2. Drop a course\n";
         cout << "3. List enrolled courses of a student\n";
         cout << "4. Update course section\n";
         cout << "5. Display total enrolled students in a course\n";
         cout << "6. Display courses not enrolled by any student\n";
         cout << "7. Search student with minimum courses registered\n";
         cout << "8. Exit\n";
         cout << "---------------------------------------\n";
         cout << "Enter your choice: ";
         cin >> choice;
         cout << "---------------------------------------\n";

        switch (choice) {
        case 1:
            enrollStudent(enrollments, numEnrollments, courses, creditHours);
            break;
        case 2:
            dropCourse(enrollments, numEnrollments);
            break;
        case 3:
            int studentId;
             cout << "Enter student ID: ";
             cin >> studentId;
            listEnrolledCourses(enrollments, numEnrollments, studentId);
            break;
        case 4:
            updateCourseSection(enrollments, numEnrollments);
            break;
        case 5:
            char courseCode[MAX_COURSE_CODE_LENGTH];
             cout << "Enter course code: ";
             cin >> courseCode;
            displayTotalEnrolledStudents(enrollments, numEnrollments, courseCode);
            break;
        case 6:
            displayUnenrolledCourses(enrollments, numEnrollments, courses);
            break;
        case 7:
            searchMinCoursesRegistered(enrollments, numEnrollments);
            break;
        case 8:
             cout << "Exiting the program.\n";
            break;
        default:
             cout << "Invalid choice.\n";
        }

         cout << "---------------------------------------\n";
    } while (choice != 8);

    return 0;
}
