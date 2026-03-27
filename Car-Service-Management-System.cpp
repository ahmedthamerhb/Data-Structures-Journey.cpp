/*
 Project:    Car Service & Maintenance Tracker
 Author:     Ahmed Thamer
 Concept:    Structs for Service Management (Practical SQL-like Logic)
 Description: A real-world system to track car repairs and costs.
*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// 1. Structure for Car & Service data | هيكل بيانات السيارة والخدمة
struct ServiceTask {
    string carModel;      // Car Model (e.g. BYD Seagull) | نوع السيارة
    string plateNumber;   // License Plate | رقم اللوحة
    string issue;         // Service Required | العطل أو الخدمة المطلوبة
    double partCost;      // Price of spare parts | سعر القطع
    double laborFee;      // Mechanic's fee | أجرة اليد
    double totalBill;     // Total Calculation | المجموع الكلي
};

int main() {
    vector<ServiceTask> records; // Daily Service List | قائمة الحجوزات اليومية
    int menuChoice;

    cout << "=== [ Garage Maintenance System ] ===\n";

    do {
        // Main Menu | القائمة الرئيسية
        cout << "\n1. Register New Car\n";
        cout << "2. View All Records\n";
        cout << "3. Exit \n";
        cout << "Enter Choice: ";
        cin >> menuChoice;

        if (menuChoice == 1) {
            ServiceTask task;
            
            cout << "\n--- New Job Card ---\n";
            cout << "Car Model: ";
            cin.ignore(); // Clean buffer | تنظيف الذاكرة المؤقتة
            getline(cin, task.carModel);
            
            cout << "Plate Number: ";
            getline(cin, task.plateNumber);
            
            cout << "Description of Issue: ";
            getline(cin, task.issue);
            
            cout << "Parts Cost ($): ";
            cin >> task.partCost;
            
            cout << "Labor Fee ($): ";
            cin >> task.laborFee;

            // Auto-calculate the total | حساب المجموع تلقائياً
            task.totalBill = task.partCost + task.laborFee;
            
            records.push_back(task); // Save to list | حفظ في القائمة
            cout << "\n>>> Car Registered Successfully!<<<\n";
        } 
        else if (menuChoice == 2) {
            // Check if list is empty | التأكد من وجود بيانات
            if (records.empty()) {
                cout << "\nNo records found!\n";
            } else {
                // Table Header | رأس الجدول
                cout << "\n" << left << setw(15) << "Car" << setw(12) << "Plate" << setw(20) << "Issue" << "Total Bill" << endl;
                cout << "------------------------------------------------------------\n";
                
                // Displaying data | عرض البيانات المخزونة
                for (const auto& r : records) {
                    cout << left << setw(15) << r.carModel 
                         << setw(12) << r.plateNumber 
                         << setw(20) << r.issue 
                         << "$" << r.totalBill << endl;
                }
            }
        }

    } while (menuChoice != 3);

    cout << "\nSystem shutdown. Data cleared.\n";
    
    return 0;
}

/*output:
=== [ Garage Maintenance System ] ===

1. Register New Car
2. View All Records
3. Exit 
Enter Choice: 1

--- New Job Card ---
Car Model: BYD Seagull
Plate Number: 
Description of Issue: Brake Pad Change
Parts Cost ($): 45
Labor Fee ($): 15

>>> Car Registered Successfully!<<<

1. Register New Car
2. View All Records
3. Exit
Enter Choice: 2

Car            Plate       Issue               Total Bill
------------------------------------------------------------
BYD Seagull                Brake Pad Change    $60

1. Register New Car
2. View All Records
3. Exit
Enter Choice: 3

System shutdown. Data cleared.
*/
