This project implements a simple University Management System, providing functionalities for student enrollment, course management, and enrollment-related queries. The system allows users to interact with a menu-driven interface to perform various tasks, such as enrolling students in courses, dropping courses, listing enrolled courses for a student, updating course sections, and displaying statistics about enrolled students.

Key Features:
1. **Course Management:** The program reads course information, including course codes and credit hours, from a file ("Courses.txt").
2. **Student Enrollment:** Users can enroll students in available courses, specifying the course, section, and student ID.
3. **Dropping Courses:** Students can drop enrolled courses, and the program adjusts the enrollment records accordingly.
4. **Listing Enrolled Courses:** Users can view the list of courses in which a specific student is enrolled.
5. **Updating Course Section:** The program allows users to update the section of a course for a particular student.
6. **Displaying Total Enrolled Students:** Users can input a course code, and the system will provide the total number of students enrolled in that course.
7. **Displaying Courses Not Enrolled:** The program lists courses that no student has enrolled in.
8. **Searching for Minimum Courses Registered:** The system identifies and displays the student with the minimum number of courses registered.

**Implementation Notes:**
- The program uses arrays to store course information, student enrollments, and other relevant data.
- Functions are defined to handle specific tasks, enhancing modularity and readability.
- A menu-driven approach is adopted, allowing users to choose from various options.

**Potential Enhancements:**
- Incorporating data validation and error handling for user inputs.
- Expanding functionality to include more advanced features such as grade tracking, attendance management, etc.
- Implementing persistent storage for enrollment records.
- Enhancing the user interface for a more user-friendly experience.

