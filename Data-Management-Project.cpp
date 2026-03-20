/* Project: C++ Inventory Management System (Structs & Vectors)
    Purpose: Practical demonstration of grouping product data using structures.
    Logic: Implementing a dynamic store database with search and calculation features.
    Author: Ahmed Thamer 
    Language: C++
*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Define a structure to group product information
// تعريف هيكل (struct) لتجميع معلومات المنتج في مكان واحد
struct Product {
    int id;
    string name;
    double price;
    int quantity;
};

int main() {
    int n;
    cout << "Enter the number of products: ";
    cin >> n;

    // Use a vector to store a dynamic list of products based on user input
    // استخدام الـ vector لتخزين قائمة ديناميكية من المنتجات حسب إدخال المستخدم
    vector<Product> inventory(n);
    double totalInventoryValue = 0;

    // 1. Data Input Phase - المرحلة الأولى: إدخال البيانات
    for (int i = 0; i < n; i++) {
        cout << "\n--- Product " << i + 1 << " ---" << endl;
        
        cout << "ID: ";
        cin >> inventory[i].id;
        
        cout << "Name: ";
        cin.ignore(); // Clear the buffer to prevent skipping getline - تنظيف الذاكرة المؤقتة لتجنب تخطي إدخال الاسم
        getline(cin, inventory[i].name);
        
        cout << "Price: $";
        cin >> inventory[i].price;
        
        cout << "Quantity: ";
        cin >> inventory[i].quantity;
        
        // Accumulate the total value of the entire inventory
        // حساب القيمة الإجمالية التراكمية لكل المنتجات في المخزن
        totalInventoryValue += (inventory[i].price * inventory[i].quantity);
    }

    // 2. Data Display Phase - المرحلة الثانية: عرض البيانات في جدول
    cout << "\n" << setbase(10) << "ID\tName\t\tPrice\tQty\tSubtotal" << endl;
    cout << "--------------------------------------------------------" << endl;
    
    // Loop through the inventory to print each item's details
    // المرور على قائمة المخزن لطباعة تفاصيل كل عنصر
    for (const auto& item : inventory) {
        cout << item.id << "\t" 
             << item.name << "\t\t" 
             << item.price << "\t" 
             << item.quantity << "\t"
             << (item.price * item.quantity) << endl;
    }
    
    cout << "--------------------------------------------------------" << endl;
    cout << "Total Store Value: $" << totalInventoryValue << endl;

    // 3. Search Feature - المرحلة الثالثة: ميزة البحث عن منتج
    int searchId;
    cout << "\nEnter Product ID to search: ";
    cin >> searchId;

    bool found = false;
    for (const auto& item : inventory) {
        // Compare the entered ID with stored products IDs
        // مقارنة المعرف المدخل بالمعرفات المخزنة في النظام
        if (item.id == searchId) {
            cout << "Product Found: " << item.name 
                 << " | Stock: " << item.quantity 
                 << " | Price: " << item.price << "$" << endl;
            found = true;
            break; // Stop searching once the item is found - التوقف عن البحث بمجرد العثور على المنتج
        }
    }
    
    if (!found) cout << "Product with ID " << searchId << " not found." << endl;

    return 0;
}

/*Output Example:
Enter the number of products: 3

--- Product 1 ---
ID: 1
Name: Laptop
Price: $800
Quantity: 5

--- Product 2 ---
ID: 2
Name: Mouse
Price: $25
Quantity: 10

--- Product 3 ---
ID: 3
Name: Keyboard
Price: $45
Quantity: 15

ID      Name            Price   Qty     Subtotal
--------------------------------------------------------
1       Laptop          800     5       4000
2       Mouse           25      10      250
3       Keyboard        45      15      675
--------------------------------------------------------
Total Store Value: $4925

Enter Product ID to search: 1
Product Found: Laptop | Stock: 5 | Price: 800$
*/
