#include <iostream>
#include<iomanip>
const int s = 5;
using namespace std;
struct Data {
    int day;
    int month;
    int year;
};
struct student {
    char RegNo[50];
    char name[50];
    Data dob;
    int marks[s];
};
void menue();
void read(student**, const int&);
void add(student**, int&);
void Delete(student**, int&);
void modify(student**, const int&);
void sort(student**, const int&);
void show(student**, const int&);
int main()
{
    int n;
    char menueCh;
    cout << "Enter the number of students : ";
    cin >> n;
    student** students = new student * [n];
    for (int i = 0; i < n; i++) {
        students[i] = new student;
    }
    read(students, n);
    do {
        int nA;
        menue();
        cout << "Enter your choice from menu :";
        cin >> menueCh;
        while (menueCh != 'A' && menueCh != 'a' && menueCh != 'D' && menueCh != 'd' && menueCh != 'M' && menueCh != 'm' && menueCh != 'F' && menueCh != 'f' && menueCh != 'S' && menueCh != 's' && menueCh != 'P' && menueCh != 'p' && menueCh != 'Q' && menueCh != 'q') {
            cout << "Your entered choise is invalid please enter from the manue :";
            cin >> menueCh;
        }
        //------------------------------------------
        if (menueCh == 'A' || menueCh == 'a') {
            nA = n + 1;
            for (int i = n; i < nA; i++) {
                students[i] = new student;
            }
            add(students, n);
        }
        //------------------------------------------
        if (menueCh == 'D' || menueCh == 'd') {
            Delete(students, n);
        }
        //------------------------------------------
        if (menueCh == 'M' || menueCh == 'm') {
            modify(students, n);
        }
        //------------------------------------------
        if (menueCh == 's' || menueCh == 'S') {
            sort(students, n);
        }
        //----------------------------------------
        if (menueCh == 'p' || menueCh == 'P') {
            show(students, n);
        }
        //-----------------------------------------
        if (menueCh == 'Q' || menueCh == 'q') {
            for (int i = 0; i < n; i++) {
                delete students[i];
            }
            delete[] students;
            break;
        }
    } while (menueCh != 'Q' || menueCh != 'q');
}

void menue() {
    cout << "                  STRUCTURES                    " << endl;
    cout << "*******************************************" << endl;
    cout << "Add a student record" << setw(5) << ":" << setw(5) << "A/a" << endl;
    cout << "Delete record" << setw(12) << ":" << setw(5) << "D/d" << endl;
    cout << "Modify record" << setw(12) << ":" << setw(5) << "M/m" << endl;
    cout << "Find a student record" << setw(4) << ":" << setw(5) << "F/f" << endl;
    cout << "Sort record w.r.t RegNo" << setw(2) << ":" << setw(5) << "S/s" << endl;
    cout << "Print" << setw(20) << ":" << setw(5) << "P/p" << endl;
    cout << "Quit" << setw(21) << ":" << setw(5) << "Q/q" << endl;
    cout << "*******************************************" << endl;
}
void read(student** students, const int& n) {
    for (int i = 0; i < n; i++) {
        cout << "-------------------------------------------" << endl;
        cout << "Enter the data of student " << i + 1 << endl;
        cout << endl;
        cout << "Enter the Registration number of student " << i + 1 << " : ";
        cin.ignore(50, '\n');
        cin.getline(students[i]->RegNo, 50);
        for (int x = 0; x < strlen(students[i]->RegNo); x++) {
            while (!isdigit(students[i]->RegNo[x])) {
                cout << "Your input string is invalid, please enter only digit : ";
                cin.getline(students[i]->RegNo, 50);
            }
        }
        for (int b = 0; b < i; b++) {
            while (strcmp(students[i]->RegNo, students[b]->RegNo) == 0) {
                cout << "No two registration number are same, please enter another registration number : ";
                cin.getline(students[i]->RegNo, 50);
            }
        }
        cout << "Enter the Name of student " << i + 1 << " : ";
        cin.getline(students[i]->name, 50);
        for (int x = 0; x < strlen(students[i]->name); x++) {
            while (!isalpha(students[i]->name[x])) {
                cout << "Your input string is invalid, please enter only alphabet : ";
                cin.getline(students[i]->name, 50);
            }
        }
        cout << endl;
        cout << "Enter the Date Of Birth of student " << i + 1 << endl;
        cout << endl;
        cout << "Enter the day of student " << i + 1 << " : ";
        cin >> students[i]->dob.day;
        while (students[i]->dob.day < 1 || students[i]->dob.day>31) {
            cout << "Your input day is invalid, please enter again between range(1-31) : ";
            cin >> students[i]->dob.day;
        }
        cout << "Enter the month of student " << i + 1 << " : ";
        cin >> students[i]->dob.month;
        while (students[i]->dob.month < 1 || students[i]->dob.month>12) {
            cout << "Your input month is invalid, please enter again between range(1-12) : ";
            cin >> students[i]->dob.month;
        }
        cout << "Enter the year of student " << i + 1 << " : ";
        cin >> students[i]->dob.year;
        while (students[i]->dob.year < 1995 || students[i]->dob.year>2007) {
            cout << "Your input year is invalid, please enter again between range(1995-2007) : ";
            cin >> students[i]->dob.year;
        }
        cout << endl;
        cout << "Enter the marks of student " << i + 1 << " : " << endl;
        cout << endl;
        for (int j = 0; j < s; j++) {
            cout << "Enter the Subject " << j + 1 << " marks : ";
            cin >> students[i]->marks[j];
            while (students[i]->marks[j] < 0 || students[i]->marks[j]>100) {
                cout << "Your input marks is invalid, please enter again between range(1-100) : ";
                cin >> students[i]->marks[j];
            }
        }
        cout << endl;
        cout << "-------------------------------------------" << endl;
    }
}
void add(student** students, int& n) {
    cout << "-------------------------------------------" << endl;
    cout << "Enter the data of student " << n + 1 << endl;
    cout << endl;
    cout << "Enter the Registration number of student " << n + 1 << " : ";
    cin.ignore(50, '\n');
    cin.getline(students[n]->RegNo, 50);
    for (int x = 0; x < strlen(students[n]->RegNo); x++) {
        while (!isdigit(students[n]->RegNo[x])) {
            cout << "Your input string is invalid, please enter only digit : ";
            cin.getline(students[n]->RegNo, 50);
        }
    }
    for (int b = 0; b < n; b++) {
        while (strcmp(students[n]->RegNo, students[b]->RegNo) == 0) {
            cout << "No two registration number are same, please enter another registration number : ";
            cin.getline(students[n]->RegNo, 50);
        }
    }
    cout << "Enter the Name of student " << n + 1 << " : ";
    cin.getline(students[n]->name, 50);
    for (int x = 0; x < strlen(students[n]->name); x++) {
        while (!isalpha(students[n]->name[x])) {
            cout << "Your input string is invalid, please enter only alphabet : ";
            cin.getline(students[n]->name, 50);
        }
    }
    cout << endl;
    cout << "Enter the Date Of Birth of student " << n + 1 << endl;
    cout << endl;
    cout << "Enter the day of student " << n + 1 << " : ";
    cin >> students[n]->dob.day;
    while (students[n]->dob.day < 1 || students[n]->dob.day>31) {
        cout << "Your input day is invalid, please enter again between range(1-31) : ";
        cin >> students[n]->dob.day;
    }
    cout << "Enter the month of student " << n + 1 << " : ";
    cin >> students[n]->dob.month;
    while (students[n]->dob.month < 1 || students[n]->dob.month>12) {
        cout << "Your input month is invalid, please enter again between range(1-12) : ";
        cin >> students[n]->dob.month;
    }
    cout << "Enter the year of student " << n + 1 << " : ";
    cin >> students[n]->dob.year;
    while (students[n]->dob.year < 1995 || students[n]->dob.year>2007) {
        cout << "Your input year is invalid, please enter again between range(1995-2007) : ";
        cin >> students[n]->dob.year;
    }
    cout << endl;
    cout << "Enter the marks of student " << n + 1 << " : " << endl;
    cout << endl;
    for (int j = 0; j < s; j++) {
        cout << "Enter the Subject " << j + 1 << " marks : ";
        cin >> students[n]->marks[j];
        while (students[n]->marks[j] < 0 || students[n]->marks[j]>100) {
            cout << "Your input marks is invalid, please enter again between range(1-100) : ";
            cin >> students[n]->marks[j];
        }
    }
    cout << endl;
    cout << "-------------------------------------------" << endl;
    n++;
}
void Delete(student** students, int& n) {
    char reg_no[50];
    if (n != 0) {
        cout << "Enter the student registration number : ";
        cin.ignore(50, '\n');
        cin.getline(reg_no, 50);
        for (int i = 0; i < n; i++) {
            while (strcmp(students[i]->RegNo, reg_no) != 0) {
                cout << "Your enter registration number is not found, please enter again : ";
                cin.getline(reg_no, 50);
            }
            if (strcmp(reg_no, students[i]->RegNo) == 0) {
                for (int j = i; j < n - 1; j++) {
                    strcpy_s(students[j]->RegNo, students[j + 1]->RegNo);
                    strcpy_s(students[j]->name, students[j + 1]->name);
                    students[j]->dob.day = students[j + 1]->dob.day;
                    students[j]->dob.month = students[j + 1]->dob.month;
                    students[j]->dob.year = students[j + 1]->dob.year;
                    for (int k = 0; k < 5; k++) {
                        students[j]->marks[k] = students[j + 1]->marks[k];
                    }
                }
            }
        }
        cout << endl;
        cout << "-------------------------------------------" << endl;
        n--;
    }
    else {
        cout << "The array is alredy empty : " << endl;
    }
}
void modify(student** students, const int& n) {
    char reg_no[50], option, op;
    int number;
    cout << "Enter the student registration number : ";
    cin.ignore(50, '\n');
    cin.getline(reg_no, 50);
    for (int i = 0; i < n; i++) {
        while (strcmp(students[i]->RegNo, reg_no) != 0) {
            cout << "Your enter registration number is not found, please enter again : ";
            cin.getline(reg_no, 50);
        }
        if (strcmp(students[i]->RegNo, reg_no) == 0) {
            do {
                cout << "Modify Name" << setw(11) << ":" << setw(5) << "N/n" << endl;
                cout << "Modify Date of Birth" << setw(2) << ":" << setw(5) << "D/d" << endl;
                cout << "Modify Marks" << setw(10) << ":" << setw(5) << "M/m" << endl;
                cout << "Enter choice from menue:";
                cin >> option;
                while (option != 'N' && option != 'n' && option != 'D' && option != 'd' && option != 'M' && option != 'm') {
                    cout << "Your entered choise is invalid, please enter from the manue : ";
                    cin >> option;
                }
                if (option == 'n' || option == 'N') {
                    cout << "Enter new Name of student : ";
                    cin.ignore(50, '\n');
                    cin.getline(students[i]->name, 50);
                    for (int x = 0; x < strlen(students[i]->name); x++) {
                        while (!isalpha(students[i]->name[x])) {
                            cout << "Your input string is invalid, please enter only alphabet : ";
                            cin.getline(students[i]->name, 50);
                        }
                    }
                }
                if (option == 'D' || option == 'd') {
                    cout << "Enter the new Date of Birth of student : " << endl;
                    cout << "Enter the day of student " << i << " : ";
                    cin >> students[i]->dob.day;
                    while (students[i]->dob.day < 1 || students[i]->dob.day>31) {
                        cout << "Your input day is invalid, please enter again between range(1-31) : ";
                        cin >> students[i]->dob.day;
                    }
                    cout << "Enter the month of student " << i << " : ";
                    cin >> students[i]->dob.month;
                    while (students[i]->dob.month < 1 || students[i]->dob.month>12) {
                        cout << "Your input month is invalid, please enter again between range(1-12) : ";
                        cin >> students[i]->dob.month;
                    }
                    cout << "Enter the year of student " << i << " : ";
                    cin >> students[i]->dob.year;
                    while (students[i]->dob.year < 1995 || students[i]->dob.year>2007) {
                        cout << "Your input year is invalid, please enter again between range(1995-2007) : ";
                        cin >> students[i]->dob.year;
                    }
                }
                if (option == 'M' || option == 'm') {
                    cout << "Which subject marks do you want to change : " << endl;
                    cout << "Enter number between range (0-5) : ";
                    cin >> number;
                    for (int j = 0; j < 5; j++) {
                        if (number == j) {
                            cout << "Enter New Marks of subject " << j << " : ";
                            cin >> students[i]->marks[j];
                            while (students[i]->marks[j] < 0 || students[i]->marks[j]>100) {
                                cout << "Your input marks is invalid, please enter again between range(1-100) : ";
                                cin >> students[i]->marks[j];
                            }
                        }
                    }
                }
                cout << "Do you want to modify another record : ";
                cin >> op;
            } while (op == 'y' || op == 'Y');
        }
    }
}
void sort(student** students, const int& n) {
    int i, j, maxIndex, tempDay, tempMonth, tempYear, tempMarks;
    char temp[50], tempNam[50];
    for (i = n - 1; i >= 0; i--) {
        maxIndex = i;
        for (j = i - 1; j >= 0; j--) {
            if (strcmp(students[j]->RegNo, students[maxIndex]->RegNo) > 0) {
                maxIndex = j;
            }
        }
        if (i != maxIndex) {
            strcpy_s(temp, students[i]->RegNo);
            strcpy_s(students[i]->RegNo, students[maxIndex]->RegNo);
            strcpy_s(students[maxIndex]->RegNo, temp);

            strcpy_s(tempNam, students[i]->name);
            strcpy_s(students[i]->name, students[maxIndex]->name);
            strcpy_s(students[maxIndex]->name, tempNam);

            tempDay = students[i]->dob.day;
            students[i]->dob.day = students[maxIndex]->dob.day;
            students[maxIndex]->dob.day = tempDay;

            tempMonth = students[i]->dob.month;
            students[i]->dob.month = students[maxIndex]->dob.month;
            students[maxIndex]->dob.month = tempMonth;

            tempYear = students[i]->dob.year;
            students[i]->dob.year = students[maxIndex]->dob.year;
            students[maxIndex]->dob.year = tempYear;

            for (int k = 0; k < 5; k++) {
                tempMarks = students[i]->marks[k];
                students[i]->marks[k] = students[maxIndex]->marks[k];
                students[maxIndex]->marks[k] = tempMarks;
            }
        }
    }
}
void show(student** students, const int& n) {
    for (int i = 0; i < n; i++) {
        cout << "-------------------------------------------" << endl;
        cout << "The data of student " << i + 1 << " is :" << endl;
        cout << endl;
        cout << "The Registration number of student " << i + 1 << " is : " << students[i]->RegNo << endl;
        cout << "The Name of student " << i + 1 << " is : " << students[i]->name << endl;
        cout << "The Date Of Birth of student " << i + 1 << " is : " << students[i]->dob.day << "/" << students[i]->dob.month << "/" << students[i]->dob.year << endl;
        cout << "The marks of student " << i + 1 << " is : " << endl;
        for (int j = 0; j < s; j++) {
            cout << "Subject " << j + 1 << " : " << students[i]->marks[j] << "\t";
        }
        cout << endl;
        cout << "-------------------------------------------" << endl;
    }
}
