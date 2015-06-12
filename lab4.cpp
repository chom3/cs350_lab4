#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int main(){
    
    typedef struct student {
    char name[32];
    char phone[16];
    char address[128];
    int ID;
    } student_t;
    
    //initialize some variables
    int IDinput; //for the input of ID
    bool loopCheck = true; //future while loop checker for when to quit (y/n)
    //the plan is to find every line that contains each string, and store the ID along with its record
    //into a vector, where we search the vector based on ID and print out everything.
    string line;
    string name = "Name >>";
    string phone = "Phone >>";
    string address = "Address >>";
    string record = "Record Created with id: >>";
    int TSid;
    vector<student> records;
    student_t pushInfo;
    //open the students file to be read
    ifstream myfile ("students");
    /**
     * Basically we're going to read each line
     * Name >>
     * Phone >>
     * Address >>
     * Record Created with id: >>
     * Will all be searched for. Whatever is after those lines will be stored in a student struct
     * and be pushed into a vector.
     * So now we have a vector that has the name/phone/address/ID.
     * Search for the ID and all the information from the vector will be displayed. 
     */
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            if (line.find(name) != string::npos)
            {
                string subname = line.substr(8, line.size());
                //cout << subname << endl;
                strcpy(pushInfo.name, subname.c_str());
                //cout << TSname << endl;
                getline(myfile, line);
                if (line.find(phone) != string::npos)
                {
                    string subphone = line.substr(9, line.size());
                    strcpy(pushInfo.phone, subphone.c_str());
                    //cout << TSphone << endl;
                    getline(myfile, line);
                    if (line.find(address) != string::npos)
                    {
                        string subadd = line.substr(11, line.size());
                        strcpy(pushInfo.address, subadd.c_str());
                        //cout << TSaddress << endl;
                        getline(myfile, line);
                        if (line.find(record) != string::npos)
                        {
                            string subrec = line.substr(27, line.size());
                            TSid = atoi(subrec.c_str());
                            //cout << TSid << endl;
                            pushInfo.ID = TSid;
                            records.push_back(pushInfo);
                        }
                    }
                }
            }
          
        }
        //this is the actual loop
        //we use a for loop to iterate through the vector for the ID input
        //if found, we print out the information
        //a quit prompt will appear after every output
        while (loopCheck)
            {
                int notFound = 0;
                cout << "ID >>";
                cin >> IDinput;
                cin.clear();
                cin.ignore(10000,'\n');
                for (unsigned int i = 0; i < records.size(); i++)
                {
                    if (records[i].ID == IDinput)
                    {
                        notFound++;
                        cout << "ID >> " << IDinput << endl;
                        cout << "Record: " << records[i].name << ", " << records[i].phone << ", " << records[i].address << endl;
                    }
                }
                if (notFound == 0)
                {
                    cout << "Does not exist!" << endl;
                }
                //QUIT PROMPT
                char quitInput[32];
                cout << "Quit(y/n)? >> ";
                if (fgets(quitInput, 32, stdin)){
                    quitInput[strlen(quitInput) -1] = '\0';
                }
                if (quitInput[0] == 'y')
                {
                    loopCheck = false;
                }
                //Clear the input so that we can go again if you choose to do so.
                cin.sync();
            }
    myfile.close();
    }
    
}