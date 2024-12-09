# include <iostream>
#include <cstdlib>
using namespace std;

struct Student{
    int sID;
    Student *next;
};

struct Course{
    int CID;
    Course *Cnext;
    Student *Studenthead;
};
Course *Chead=NULL;

void AddCourse( int ID){
    Course *newNode=(Course*)malloc(sizeof(Course));
    newNode->CID=ID;
    newNode->Studenthead=NULL;
    
    if(Chead==NULL){
        Chead=newNode;
    }
    else{
        Course *temp=Chead;
        while(temp->Cnext!=NULL){
            temp=temp->Cnext;  
         }
        temp->Cnext=newNode;
}
}
void printCourse(){
    if(Chead==NULL){
        cout<<"NO COURSES FOUND"<<endl;
        return;
    }
    cout<<"THE COURSES ARE: "<<endl;
    Course *temp=Chead;
    while(temp!=NULL){
        cout<<temp->CID<<" ";
        temp=temp->Cnext;
    }
    cout<<endl;
}

void searchCourse(int courseID){
    if(Chead==NULL){
        cout<<"NO COURSES EXIST"<<endl;
        return;
        
    }
    Course *temp=Chead;
    while(temp!=NULL){
        if(temp->CID==courseID){
            cout<<"COURSE FOUND"<<endl;
            return;
        }
        else{
            temp=temp->Cnext;
        }
    }
    cout<<"NOT FOUND "<<endl;
    return;
}

void deleteCourse(int courseID){
    if(Chead==NULL){
        cout<<"EMPTY COURSE LIST"<<endl;
        return;
    }
    Course *temp=Chead;
    Course *prev=NULL;
    if(Chead->CID==courseID){
        cout<<"FOUND AT HEAD"<<endl;
        Chead=temp->Cnext;
        delete temp;
        return;
    }
    else{
        while(temp!=NULL){
             prev=temp;
             temp=temp->Cnext;
             if(temp->CID==courseID && temp->Cnext!=NULL){
                cout<<"FOUND AND DELETED IN MIDDLE"<<endl;
                prev->Cnext=temp->Cnext;
                delete temp;
                return;
            }
            if(temp->CID==courseID && temp->Cnext==NULL){
                cout<<"FOUND AND DELETED at last"<<endl;
                prev->Cnext=NULL;
                delete temp;
                return;
            }
            
        }
    }
    cout<<"NOT FOUND"<<endl;
}

void insertStudent(int courseId,int studentId,Student *&head){
    //---------------creating student node-----------------
    Student *studentNode=(Student*)malloc(sizeof(Student));
    studentNode->sID=studentId;
    studentNode->next=NULL;
    //-----------------creating temp pointer--------------
    Course *Ctemp=Chead;
    while(Ctemp!=NULL){
        if(Ctemp->CID==courseId){
            //-------------------if course found--------------
            cout<<"course found"<<endl;
            //------------------if head is NULL-------------
            if(Ctemp->Studenthead==NULL){
                Ctemp->Studenthead=studentNode;
                return;
            }
            //----------------if student head is not NULL-------------
            else{
                Student *temp=Ctemp->Studenthead;
                while(temp->next!=NULL){
                     temp=temp->next;
                }
                temp->next=studentNode;
                return;
            }
        }
    }
    cout<<"COURSE NOT FOUND"<<endl;
}

void printstudent(int courseID, Student *Shead){
    Course *Ctemp=Chead;
    while(Ctemp!=NULL){
        if(Chead->CID==courseID){
            cout<<"COURSE FOUND and STUDENT ADDED"<<endl;
            Student *temp=Ctemp->Studenthead;
            cout<<"STUDENTS IN COURSE: "<<courseID<<endl;
            while(temp!=NULL){
                cout<<temp->sID<<" ";
                temp=temp->next;
            }
            cout<<endl;
            return;
        }
       Ctemp=Ctemp->Cnext;
    }
    cout<<"COURSE NOT FOUND"<<endl;
    return;
}


int main(){
    Student *Shead=NULL;
    int score=-1;
    int  courseID;
    int searchcourseID;
    int coursedelete;
    int studentroll;
    while(score!=0){
        cout<<"Enter 1 to insert course and 2 to print course and 3 to search course and 4 to delete course and 5 to insert student and 6 to print student"<<endl;
        cin>>score;
        switch(score){
            case 1:
                cout<<"ENTER COURSE ID: "<<endl;
                cin>>courseID;
                AddCourse(courseID);
                break;
            case 2:
                printCourse();
                break;
            case 3:
                cout<<"Enter Course to search"<<endl;
                cin>>searchcourseID;
                searchCourse(searchcourseID);
                break;
            case 4:
                cout<<"ENTER COURSE TO DELETE: "<<endl;
                cin>>coursedelete;
                deleteCourse(coursedelete);
                break;
            case 5:
                cout<<"Enter COURSE TP ENROLL IN: "<<endl;
                cin>>searchcourseID;
                cout<<"ENTER STUDENT ID: "<<endl;
                cin>>studentroll;
                insertStudent(searchcourseID,studentroll,Shead);
                break;
            case 6:
                cout<<"ENTER COURSE TO FIND STUDENTS IN: "<<endl;
                cin>>courseID;
                printstudent(courseID,Shead);
                break;
        }
    }
}