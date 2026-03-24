/* Project: Smart Clinic Appointment System
   Purpose: Organizing patient visits and status.
   Author: Ahmed Thamer
   Language: C++
   Date: March 2026
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// structure for each patient info
struct Appointment {
    string name;
    string time;
    string status; // Emergency or Normal
};

int main() {
    vector<Appointment> list;
    int op;

    cout << "--- Baghdad Medical System ---\n";

    while (true) {
        cout << "\n1- Add Appointment\n2- Show All\n3- Exit\nChoice: ";
        cin >> op;

        if (op == 1) {
            Appointment p;
            cout << "Enter Patient Name: ";
            cin.ignore();
            getline(cin, p.name);
            
            cout << "Enter Time (ex: 5:00 PM): ";
            getline(cin, p.time);
            
            cout << "Case Status (Emergency or Normal): ";
            getline(cin, p.status);

            list.push_back(p);
            cout << "Done! saved successfully.\n";

        } 
        
        else if (op == 2) {
            if (list.size() == 0) {
                cout << "The list is empty now.\n";
            } 
            else {
                cout << "\n--- Today's List ---\n";
                for (int i = 0; i < list.size(); i++) {
                    cout << i + 1 << ". " << list[i].name << " | Time: " 
                         << list[i].time << " | Case: " << list[i].status << endl;
                }
            }
        } 
        else if (op == 3) {
            cout << "Closing system...\n";
            break;
        }
        else {
            cout << "Wrong input! try again.\n";
        }
    }

    return 0;
}

/*output:
--- Baghdad Medical System ---

1- Add Appointment
2- Show All
3- Exit
Choice: 1
Enter Patient Name: Ahmed Thamer
Enter Time (ex: 5:00 PM): 10:00 AM
Case Status (Emergency or Normal): Normal
Done! saved successfully.

1- Add Appointment
2- Show All
3- Exit
Choice: 1
Enter Patient Name: Ali Omar
Enter Time (ex: 5:00 PM): 6:00 PM
Case Status (Emergency or Normal): Emergency
Done! saved successfully.

1- Add Appointment
2- Show All
3- Exit
Choice: 1
Enter Patient Name: Noor Ahmed
Enter Time (ex: 5:00 PM): 4:30 PM
Case Status (Emergency or Normal): Normal
Done! saved successfully.

1- Add Appointment
2- Show All
3- Exit
Choice: 2

--- Today's List ---
1. Ahmed Thamer | Time: 10:00 AM | Case: Normal
2. Ali Omar | Time: 6:00 PM | Case: Emergency
3. Noor Ahmed | Time: 4:30 PM | Case: Normal

1- Add Appointment
2- Show All
3- Exit
Choice: 4
Wrong input! try again.

1- Add Appointment
2- Show All
3- Exit
Choice: 3
Closing system...
*/
