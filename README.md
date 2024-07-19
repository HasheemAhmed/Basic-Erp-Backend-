
# Organization Portal System

📚 This C++ program is a simple organization portal system designed to manage profiles, attendance, and fees for students and teachers. The system uses file handling to store and retrieve data.

## Features

🔹 **Profile Management**: Add, view, and manage profiles for students and teachers.

🔹 **Attendance Management**: Add and view attendance records for various subjects.

🔹 **Fee Management**: Add and view fee status for students across different semesters.

## Classes and Functions

### 🗄️ Classes

- **Files**: Handles basic file operations and paths.
  - Default Constructor: Sets default folder path.
  - Parameterized Constructor: Allows setting custom file and folder paths.
  - Getter and Setter Functions: Access and modify file details.

- **Profile**: Inherits from Files and manages profile information.
  - Default and Parameterized Constructors: Initialize profile details.
  - Getter and Setter Functions: Access and modify profile attributes.

- **Attendance**: Inherits from Files and manages attendance records.
  - Default and Parameterized Constructors: Initialize attendance details.
  - Getter and Setter Functions: Access and modify attendance attributes.

- **AttendanceSheet**: Creates or appends attendance sheets.

- **Fees**: Inherits from Attendance and manages fee status.
  - Default and Parameterized Constructors: Initialize fee status for semesters.
  - Operator Overloading: Allows easy access to semester fee status.
  - Getter and Setter Functions: Access and modify fee details.

### 🗄️ Functions

- **isFileEmpty**: Checks if a file is empty.
- **Exit**: Prompts the user to exit the program.
- **Title**: Displays a title banner.
- **addIDtoSheet**: Adds a student ID to the attendance sheet.
- **addProfile**: Adds a new profile (student/teacher) to the system.
- **viewProfile**: Views a specific profile based on ID.
- **setAttendance**: Records attendance for a specific subject and date.
- **viewAttendance**: Views attendance records for a specific subject and ID.
- **addFees**: Adds fee status for a student for a specific semester.
- **viewFees**: Views fee status for a student for a specific semester.
- **AddAttendance**: Displays menu for adding attendance records.
- **ViewAttendance**: Displays menu for viewing attendance records.
- **login**: Authenticates a user based on ID and password.
- **Organization**: Manages the organization portal, including student and teacher profiles, attendance, and fees.
- **Student**: Manages the student portal, including profile, attendance, and fees.
- **Teacher**: Manages the teacher portal.

## 🗃️ Usage

To use this program, compile and run the C++ code. The main menu provides options to access the organization, student, and teacher portals. Follow the prompts to add or view profiles, attendance, and fee records.

## 🛠️ Contribution

Feel free to contribute to this project by forking the repository and submitting pull requests.

## ✅ License

This project is licensed under the MIT License.

🎉 Enjoy using the Organization Portal System! If you have any questions or need further assistance, feel free to reach out.

---
