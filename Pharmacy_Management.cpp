/* Project: Mini Pharmacy Management System
   Purpose: Managing medicine inventory using C++ Structs.
   Logic: Monitoring stock levels and business rules.
   Author: Ahmed Thamer 
   Language: C++
*/

#include <iostream>
#include <string> // For handling text data | للتعامل مع النصوص

using namespace std;

// 1. Defining the Medicine Structure | تعريف هيكل الدواء
struct Medicine {
    string name;          // Medicine Name | اسم الدواء
    string category;      // Category (e.g., Antibiotic) | الفئة (مثلاً: مضاد حيوي)
    int quantity;         // Stock Quantity | الكمية المتوفرة في المخزن
    float price;          // Price per unit | سعر الوحدة الواحدة
    string expiryDate;    // Expiry Date (YYYY-MM) | تاريخ الصلاحية
};

int main() {
    // 2. Creating an instance of the struct | إنشاء نسخة من الهيكل
    Medicine med1;

    // 3. Assigning data to the medicine object | إسناد البيانات لغرض الدواء
    med1.name = "Panadol Advance";
    med1.category = "Analgesic";
    med1.quantity = 8;         // Example of low stock | مثال على كمية منخفضة
    med1.price = 3.50;
    med1.expiryDate = "2027-06";

    // 4. Logic: Checking for low stock levels | منطق العمل: فحص مستويات المخزن
    cout << "--- Pharmacy Inventory Management ---" << endl;
    cout << "Medicine Name: " << med1.name << endl;
    cout << "Category: " << med1.category << endl;
    cout << "Current Stock: " << med1.quantity << " units" << endl;

    // Business Rule: Alert if quantity is less than 10
    // قاعدة عمل: تنبيه إذا كانت الكمية أقل من 10 قطع
    if (med1.quantity < 10) {
        cout << "\n[!] ALERT: Stock is low! Please reorder soon." << endl;
    }

    cout << "--------------------------------------" << endl;
    cout << "Unit Price: $" << med1.price << endl;
    cout << "Expiry Date: " << med1.expiryDate << endl;

    return 0; 
}

/*output:
--- Pharmacy Inventory Management ---
Medicine Name: Panadol Advance
Category: Analgesic
Current Stock: 8 units

[!] ALERT: Stock is low! Please reorder soon.
--------------------------------------
Unit Price: $3.5
Expiry Date: 2027-06
*/
