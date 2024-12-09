#include <iostream>
using namespace std;

struct SNode {
    int sID;
    SNode *next;
};

struct CNode {
    int cID;
    SNode *stuHead;
    CNode *next;
};
CNode *head = nullptr;

void insertCourse (int ID) {
    CNode *ptr = (CNode*) malloc (sizeof(CNode));
    ptr->cID = ID;
    ptr-> stuHead = nullptr;
    ptr -> next = nullptr;

    if (head == nullptr) {
        head = ptr;
        return;
    }
    else {
        CNode* curr = head;
        while (curr -> next != nullptr) {
            curr = curr -> next;
        }
        curr -> next = ptr;
    }
}

void searchCourse (int ID) {
    int flag = 0;
    if (head == nullptr) {
        return;
    }
    if (head -> cID == ID) {
        cout << "Course found" << endl;
        return;
    }
    else {
        CNode *curr = head;
        while (curr != nullptr) {
            if (curr -> cID == ID) {
                cout << "Course found" << endl;
                flag = 1;
                break;
            }
            curr = curr -> next;
        }
        if (flag == 0) {
            cout << "Course not found." << endl;
        }
        return;
    }
}

void printCourses () {
    if (head == nullptr) {
        return;
    }
    CNode* curr = head;
    while (curr != nullptr) {
        cout << curr -> cID << " ";
        curr = curr -> next;
    }
}

void deleteCourse (int ID) {
    CNode* curr = head;
    if (head -> cID == ID) {
        head = head -> next;
        free (curr);
        return;
    }
    else {
        CNode *prev;
        while (curr != nullptr) {
            if (curr -> cID == ID) {
                prev -> next = curr -> next;
                free (curr);
                return;
            }
            prev = curr;
            curr = curr -> next;
        }
        cout << endl;

    }
}
void insertStudent(int CID, int SID) {
    SNode *ptr = new SNode;
    ptr->sID = SID;
    ptr->next = nullptr;

    CNode *curr = head;
    while (curr != nullptr) {
        if (curr->cID == CID) {
            if (curr->stuHead == nullptr) {
                curr->stuHead = ptr;
            } else {
                SNode *currStu = curr->stuHead;
                while (currStu->next != nullptr) {
                    currStu = currStu->next;
                }
                currStu->next = ptr;
            }
            cout << "Student added to course " << CID << "." << endl;
            return;
        }
        curr = curr->next;
    }
    cout << "Course not found." << endl;
}


void searchStudent(int CID, int SID) {
    CNode *curr = head;
    while (curr != nullptr) {
        if (curr->cID == CID) {
            SNode *currStu = curr->stuHead;
            while (currStu != nullptr) {
                if (currStu->sID == SID) {
                    cout << "Student found." << endl;
                    return;
                }
                currStu = currStu->next;
            }
            cout << "Student not found in this course." << endl;
            return;
        }
        curr = curr->next;
    }
    cout << "Course not found." << endl;
}

void printStudents(int CID) {
    CNode *curr = head;
    while (curr != nullptr) {
        if (curr->cID == CID) {
            SNode *currStu = curr->stuHead;
            cout << "Students in course " << CID << ":" << endl;
            while (currStu != nullptr) {
                cout << currStu->sID << " ";
                currStu = currStu->next;
            }
            cout << endl;
            return;
        }
        curr = curr->next;
    }
    cout << "Course not found." << endl;
}

void deleteStudentFromCourse(int CID, int SID) {
    CNode *curr = head;
    while (curr != nullptr) {
        if (curr->cID == CID) {
            SNode *prevStu = nullptr;
            SNode *currStu = curr->stuHead;
            while (currStu != nullptr) {
                if (currStu->sID == SID) {
                    if (prevStu == nullptr) {
                        // If the student to be deleted is the head
                        curr->stuHead = currStu->next;
                    } else {
                        // If the student to be deleted is not the head
                        prevStu->next = currStu->next;
                    }
                    delete currStu; // Free the memory
                    cout << "Student deleted from course " << CID << "." << endl;
                    return;
                }
                prevStu = currStu;
                currStu = currStu->next;
            }
            cout << "Student not found in this course." << endl;
            return;
        }
        curr = curr->next;
    }
    cout << "Course not found." << endl;
}

int main () {
    int val = 1, cid, sid, point;
    while (val != 0) {
        cout << "Insert? 1. Search? 2. Print? 3. Delete? 4." << endl;
        cin >> val;
        switch (val) {
            case 0:
                break;
            case 1:
                cout << "Insert Course? 1. Insert Student? 2." << endl;
                cin >> point;
                
                if (point == 1) {
                    cout << "Enter Course ID: " << endl;
                    cin >> cid;
                    insertCourse (cid);
                    break;
                }
                if (point == 2) {
                    cout << "Enter Course ID: " << endl;
                    cin >> cid;
                    cout << "Enter Student ID: " << endl;
                    cin >> sid;
                    insertStudent (cid, sid);
                    break;
                }
                else {
                    cout << "Invalid" << endl;
                    break;
                }

            case 2:
                cout << "Search Course? 1. Search Student? 2." << endl;
                cin >> point;
                
                if (point == 1) {
                    cout << "Enter Course ID: " << endl;
                    cin >> cid;
                    searchCourse (cid);
                    break;
                }
                if (point == 2) {
                    cout << "Enter Course ID: " << endl;
                    cin >> cid;
                    cout << "Enter Student ID: " << endl;
                    cin >> sid;
                    searchStudent (cid, sid);
                    break;
                }
                else {
                    cout << "Invalid" << endl;
                    break;
                }

            case 3:
                cout << "Print Course? 1. Print Student? 2." << endl;
                cin >> point;
                
                if (point == 1) {
                    printCourses ();
                    break;
                }
                if (point == 2) {
                    cout << "Enter Course ID: " << endl;
                    cin >> cid;
                    printStudents (cid);
                    break;
                }
                else {
                    cout << "Invalid" << endl;
                    break;
                }

            case 4:
                cout << "Delete Course? 1. Delete Student? 2." << endl;
                cin >> point;
                
                if (point == 1) {
                    cout << "Enter Course ID: " << endl;
                    cin >> cid;
                    deleteCourse (cid);
                    break;
                }
                if (point == 2) {
                    cout << "Enter Course ID: " << endl;
                    cin >> cid;
                    cout << "Enter Student ID: " << endl;
                    cin >> sid;
                    deleteStudentFromCourse (cid, sid);
                    break;
                }
                else {
                    cout << "Invalid" << endl;
                    break;
                }
            
            default:
                cout << "Invalid" << endl;
                break;
                
            
        
    }
}
}