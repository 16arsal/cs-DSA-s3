#include <iostream>
#include <string>

class Student {
public:
    int studentID;
    std::string name;
    float GPA;
    Student(int id, std::string n, float gpa) : studentID(id), name(n), GPA(gpa) {}

};

class Node {
public:
    Student data;
    Node* next;
    
    Node(Student s) : data(s), next(NULL) {}
};

class StudentLinkedList {
private:
    Node* head;
    
public:
    StudentLinkedList() : head(NULL) {}
    
    void addStudent(Student student) {
        Node* newNode = new Node(student);
        newNode->next = head;
        head = newNode;
    }
    
    bool removeStudent(int studentid) {
        Node* current = head;
        Node* prev = NULL;
        
        while (current!=NULL) {
            if (current->data.studentID == studentid) {
                if (prev!=NULL) {
                    prev->next = current->next;
                } else {
                    head = current->next;
                }
                delete current;
                return true;
            }
            prev = current;
            current = current->next;
        }
        
        return false;
    }
    
    void findStudent(int studentID) {
        Node* current = head;
        while (current) {
            if (current->data.studentID == studentID) {
                std::cout << "Student ID: " << current->data.studentID << std::endl;
                std::cout << "Name: " << current->data.name << std::endl;
                std::cout << "GPA: " << current->data.GPA << std::endl;
                return;
            }
            current = current->next;
        }
        std::cout << "Student not found." << std::endl;
    }
    
    void displayAllStudents() {
        Node* current = head;
        while (current) {
            std::cout << "Student ID: " << current->data.studentID << std::endl;
            std::cout << "Name: " << current->data.name << std::endl;
            std::cout << "GPA: " << current->data.GPA << std::endl;
            std::cout << std::endl;
            current = current->next;
        }
    }
    
    float calculateAverageGPA() {
        float totalGPA = 0.0;
        int studentCount = 0;
        
        Node* current = head;
        while (current) {
            totalGPA += current->data.GPA;
            studentCount++;
            current = current->next;
        }
        if (studentCount > 0 )
        return totalGPA / studentCount;
        else
        return 0;
        //return studentCount > 0 ? totalGPA / studentCount : 0.0;
    }
    
    ~StudentLinkedList() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    StudentLinkedList students;
    
    students.addStudent(Student(101, "Alice", 3.8));
    students.addStudent(Student(102, "Bob", 3.5));
    students.addStudent(Student(103, "Carol", 3.9));
    
    std::cout << "All Students:" << std::endl;
    students.displayAllStudents();
    
    students.findStudent(102);
    
    if (students.removeStudent(102)) {
        std::cout << "Student with ID 102 removed." << std::endl;
    } else {
        std::cout << "Student with ID 102 not found." << std::endl;
    }
        std::cout<<std::endl << "All Students after deletion :" << std::endl;
    students.displayAllStudents();
    
    std::cout << "Average GPA: " << students.calculateAverageGPA() << std::endl;
    
    return 0;
}

