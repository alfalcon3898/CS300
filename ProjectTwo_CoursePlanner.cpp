/*
CS 300 Project Two - Allen Falcon

- zyBook references:
  - Structs, Loops, Vectors, File Input, String Parsing
  - Binary Search Trees and In-order Traversal
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Struct to hold course information
struct Course {
    string courseNumber;
    string courseTitle;
    vector<string> prerequisites;
};

// Node for the Binary Search Tree
struct Node {
    Course course;
    Node* left;
    Node* right;

    Node(Course c) : course(c), left(nullptr), right(nullptr) {}
};

class CourseBST {
private:
    Node* root;

    Node* insert(Node* node, Course course) {
        if (!node) return new Node(course);
        if (course.courseNumber < node->course.courseNumber) {
            node->left = insert(node->left, course);
        } else {
            node->right = insert(node->right, course);
        }
        return node;
    }

    void inOrder(Node* node) {
        if (!node) return;
        inOrder(node->left);
        cout << node->course.courseNumber << ", " << node->course.courseTitle << endl;
        inOrder(node->right);
    }

    Node* search(Node* node, string courseNumber) {
        if (!node || node->course.courseNumber == courseNumber) return node;
        if (courseNumber < node->course.courseNumber) return search(node->left, courseNumber);
        return search(node->right, courseNumber);
    }

public:
    CourseBST() : root(nullptr) {}

    void insert(Course course) {
        root = insert(root, course);
    }

    void printInOrder() {
        inOrder(root);
    }

    Course* find(string courseNumber) {
        Node* found = search(root, courseNumber);
        return found ? &found->course : nullptr;
    }
};

void loadCourses(string filename, CourseBST& bst) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open file." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;

        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() >= 2) {
            Course course;
            course.courseNumber = tokens[0];
            course.courseTitle = tokens[1];
            for (size_t i = 2; i < tokens.size(); ++i) {
                course.prerequisites.push_back(tokens[i]);
            }
            bst.insert(course);
        }
    }
    file.close();
    cout << "Courses loaded successfully." << endl;
}

void printCourseInfo(CourseBST& bst) {
    cout << "\nWhat course do you want to know about? ";
    string input;
    cin >> input;
    transform(input.begin(), input.end(), input.begin(), ::toupper);

    Course* course = bst.find(input);
    if (course) {
        cout << course->courseNumber << ", " << course->courseTitle << endl;
        if (!course->prerequisites.empty()) {
            cout << "Prerequisites: ";
            for (size_t i = 0; i < course->prerequisites.size(); ++i) {
                cout << course->prerequisites[i];
                if (i < course->prerequisites.size() - 1) cout << ", ";
            }
            cout << endl;
        }
    } else {
        cout << "Course not found." << endl;
    }
}

int main() {
    CourseBST bst;
    int choice = 0;

    cout << "Welcome to the course planner.\n";

    while (choice != 9) {
        cout << "\n1. Load Data Structure.\n";
        cout << "2. Print Course List.\n";
        cout << "3. Print Course.\n";
        cout << "9. Exit\n\n";
        cout << "What would you like to do? ";
        cin >> choice;

        switch (choice) {
        case 1:
            loadCourses("CS 300 ABCU_Advising_Program_Input.csv", bst);
            break;
        case 2:
            cout << "\nHere is a sample schedule:\n" << endl;
            bst.printInOrder();
            break;
        case 3:
            printCourseInfo(bst);
            break;
        case 9:
            cout << "Thank you for using the course planner!" << endl;
            break;
        default:
            cout << "\n" << choice << " is not a valid option." << endl;
            break;
        }
    }
    return 0;
}
