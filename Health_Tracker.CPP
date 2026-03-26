/*
 Project:    Health Tracker: Patient Body Mass Index (BMI) Analyzer
 Concept:    Data Structs for Mathematical Calculations & Data Processing
 Author:     Ahmed Thamer
 Description: A C++ program to manage multiple patients using structs,
            calculating BMI to categorize health status.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 1. Structure for Athlete data | هيكل بيانات المتدرب
struct Athlete {
    string fullName;     // User Name | اسم المتدرب
    double weight;       // Weight in kg | الوزن بالكيلو
    double height;       // Height in meters | الطول بالمتر
    double bmiResult;    // Result of BMI | نتيجة مؤشر الكتلة
};

int main() {
    int membersCount;
    vector<Athlete> gymMembers; // List to store everyone | قائمة لخزن المتدربين

    cout << "=== Welcome to My Fitness Tracker ===\n";
    cout << "How many members to check?";
    cin >> membersCount;

    // Loop to collect data | حلقة لإدخال البيانات
    for (int i = 0; i < membersCount; i++) {
        Athlete person;
        
        cout << "\nSetting up Member #" << i + 1 << " details:" << endl;
        
        cout << "Full Name: ";
        cin.ignore();
        getline(cin, person.fullName);
        
        cout << "Weight (kg): ";
        cin >> person.weight;
        
        cout << "Height (175cm): ";
        cin >> person.height;

        // Simple Math: BMI = weight / (height * height) | معادلة الحساب
        person.bmiResult = person.weight / (person.height * person.height);
        
        // Add to our list | إضافة الشخص للقائمة
        gymMembers.push_back(person);
    }

    // Showing the Final Report | عرض التقرير النهائي
    cout << "\n--- [ Gym Members Health Report ] ---\n";
    
    for (int i = 0; i < gymMembers.size(); i++) {
        cout << "Name: " << gymMembers[i].fullName << endl;
        cout << "BMI Score: " << gymMembers[i].bmiResult << " | ";
        
        // Logical check for health status | فحص الحالة الصحية
        if (gymMembers[i].bmiResult < 18.5) {
            cout << "Status: Underweight" << endl;
        } 
        else if (gymMembers[i].bmiResult >= 18.5 && gymMembers[i].bmiResult <= 25) {
            cout << "Status: Healthy" << endl;
        } 
        else {
            cout << "Status: Overweight" << endl;
        }
        cout << "------------------------------------" << endl;
    }

    cout << "Work Done! Stay fit." << endl;

    return 0;
}

/*output
=== Welcome to My Fitness Tracker ===
How many members to check? 2

Setting up Member #1 details:
Full Name: Ahmed Thamer
Weight (kg): 75
Height (175cm): 1.80

Setting up Member #2 details:
Full Name: Mohammed Ali
Weight (kg): 100
Height (175cm): 1.70

--- [ Gym Members Health Report ] ---
Name: Ahmed Thamer
BMI Score: 23.1481 | Status: Healthy
------------------------------------
Name: Mohammed Ali
BMI Score: 34.6021 | Status: Overweight
------------------------------------
Work Done! Stay fit.
*/
