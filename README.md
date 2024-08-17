# University Management System

## Description

The **University Management System** is a simple application designed to manage university operations related to student enrollment and course management. This system provides users with a menu-driven interface to perform various tasks, including enrolling students in courses, dropping courses, listing enrolled courses, updating course sections, and displaying statistics about enrolled students.

## Key Features

### 1. **Course Management**
- **Course Information:** Reads course details such as course codes and credit hours from a file named `Courses.txt`.
- **Course Storage:** Uses arrays to store and manage course data efficiently.

### 2. **Student Enrollment**
- **Enrollment Process:** Allows users to enroll students in available courses by specifying the course code, section, and student ID.
- **Enrollment Records:** Maintains records of student enrollments, updating them dynamically as students enroll in or drop courses.

### 3. **Dropping Courses**
- **Course Dropping:** Enables students to drop courses they are enrolled in.
- **Record Adjustment:** Updates enrollment records to reflect dropped courses and adjusts the available slots accordingly.

### 4. **Listing Enrolled Courses**
- **Student Enrollment View:** Provides functionality to list all courses in which a specific student is currently enrolled.
- **Course Details:** Displays detailed information about the enrolled courses, including course codes and sections.

### 5. **Updating Course Section**
- **Section Updates:** Allows users to update the section of a specific course for a particular student.
- **Record Management:** Ensures that the section change is reflected in the enrollment records.

### 6. **Displaying Total Enrolled Students**
- **Enrollment Statistics:** Users can input a course code to retrieve the total number of students currently enrolled in that course.
- **Statistical Reporting:** Provides quick insights into course popularity and student distribution.

### 7. **Displaying Courses Not Enrolled**
- **Unenrolled Courses:** Lists all courses that have no current student enrollments.
- **Course Availability:** Helps in identifying courses that may need promotion or additional enrollment efforts.

### 8. **Searching for Minimum Courses Registered**
- **Student Enrollment Analysis:** Identifies and displays the student with the minimum number of courses registered.
- **Data Insights:** Provides insights into student engagement and course registration patterns.

## Implementation Notes

- **Data Storage:** The system uses arrays to store course information, student enrollments, and related data.
- **Modular Design:** Functions are defined to handle specific tasks, promoting modularity and readability of the code.
- **Menu-Driven Interface:** Provides a user-friendly menu-driven interface for selecting and executing various operations.

## Potential Enhancements

- **Data Validation:** Incorporate validation and error handling to manage incorrect user inputs and improve system robustness.
- **Advanced Features:** Expand functionality to include features such as grade tracking, attendance management, and academic performance analysis.
- **Persistent Storage:** Implement persistent storage solutions (e.g., databases) to maintain enrollment records and course information beyond application sessions.
- **Enhanced User Interface:** Improve the user interface for a more intuitive and user-friendly experience, possibly integrating graphical or web-based interfaces.

## Getting Started

To get started with the University Management System:

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/iamsaadsiddiq/university-management-system.git
   ```

2. **Build and Run:**

   - Follow the build instructions specific to your development environment.
   - Execute the program and interact with the menu-driven interface to explore the system’s features.

3. **Configuration:**

   - Ensure the `Courses.txt` file is properly formatted and located in the same directory as the executable.

## Contributing

Contributions to the University Management System are welcome! To contribute:

1. Fork the repository.
2. Create a new branch for your feature or fix.
3. Commit your changes and push to your fork.
4. Open a pull request.

Please adhere to the project's coding standards and guidelines when contributing.

## Contact

For any inquiries or issues, please contact [musaad03@gmail.com](mailto:musaad03@gmail.com).
