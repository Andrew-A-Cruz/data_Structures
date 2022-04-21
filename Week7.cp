//============================================================================
// Name        : Week7.cpp
// Author      : Andrew Cruz
// Version     : 1.0
// Description : Week 7 project
//============================================================================
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;
int menuInput = 0;
string courseInput;


void printLocal(string loc) {
    cout << loc;
}

int main() {
    //printing "welcome to course planner"
    cout << "Welcome to the course planner." << endl;

    //defining data structure for course
    struct course {
        string courseID;
        string courseName;
        string preReq1;
        string preReq2;
    };

    //opening file
    ifstream myfile;
    myfile.open("csv.txt");

    string line;
    vector <course> courseList;
    int i = 0;
    string temp;


    // while loop that runs menu
    while (true) {
        cout << "1. Load Data Structure." << endl;
        cout << "2. Print Course List." << endl;
        cout << "3. Print Course." << endl;
        cout << "9. Exit" << endl;
        cout << endl;
        cin >> menuInput;

        if (menuInput == 1) {
            cout << "Loading Data Structure..." << endl;
            cout << endl;

            // reading file and storing it in a vector <course>
            for (int i = 0; i < 8; i++) {

                //create new element in vector courseList
                courseList.push_back(course());

                //reads file and puts into courseList
                getline(myfile, line);
                stringstream mystream(line);
                getline(mystream, courseList[i].courseID, ',');
                getline(mystream, courseList[i].courseName, ',');
                getline(mystream, courseList[i].preReq1, ',');
                getline(mystream, courseList[i].preReq2, ',');
            }

            //close file
            myfile.close();
        }

        //printing all course IDs and Course names as a sample
        else if (menuInput == 2) {
            cout << "Here is a sample schedule:" << endl;
            cout << courseList[0].courseID << ", " << courseList[0].courseName << endl;
            cout << courseList[1].courseID << ", " << courseList[1].courseName << endl;
            cout << courseList[2].courseID << ", " << courseList[2].courseName << endl;
            cout << courseList[3].courseID << ", " << courseList[3].courseName << endl;
            cout << courseList[4].courseID << ", " << courseList[4].courseName << endl;
            cout << courseList[5].courseID << ", " << courseList[5].courseName << endl;
            cout << courseList[6].courseID << ", " << courseList[6].courseName << endl;
            cout << courseList[7].courseID << ", " << courseList[7].courseName << endl;
            cout << endl;
        }
        else if (menuInput == 3) {
            cout << "What course do you want to know about?" << endl;
            cin >> courseInput;

            //searches for course
            for (i = 0; i <= courseList.size() - 1; i++) {

                //when it finds course ID, prints Course info
                if (courseList[i].courseID == courseInput) {
                    cout << courseList[i].courseID << " , " << courseList[i].courseName << endl;
                    cout << "Prerequesites: ";
                    cout << courseList[i].preReq1 << " " << courseList[i].preReq2 << endl;
                }

            }


            cout << endl;
        }


        
        else if(menuInput == 9) {
            break;
        }
        else{
            cout << "Invalid input." << endl;
        }
    
    }
    cout << "Thank you for using the course planner!" << endl;


}
  
  