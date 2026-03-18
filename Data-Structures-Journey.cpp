/* Project: C++ Data Structures (Structs)
    Purpose: Detailed demonstration of grouping different data types.
    Logic: Mapping real-world Social Media variables into a single Object.
    Author: Ahmed Thamer 
    Language: C++
*/

#include <iostream>
#include <string> // Essential for string data type | ضرورية لنوع البيانات النصية

using namespace std;

// Defining the Structure | تعريف الهيكل
struct facebook_post { 
    string name;           // Author's name | اسم الكاتب
    string text;           // Post content | محتوى المنشور
    int likes;             // Number of likes | عدد الإعجابات
    float engagementrate;  // Engagement percentage | نسبة التفاعل
}; // Don't forget the semicolon here | لا تنسَ الفارزة المنقوطة هنا

int main () {

    // Creating an instance of the struct | إنشاء نسخة من الهيكل
    facebook_post mypost; 
  
    // Assigning values to members | إسناد القيم للعناصر
    mypost.name = "Ahmed Thamer";
    mypost.text = "This is my first post using Structs in C++! #Programming #Tech";
    mypost.likes = 150;
    mypost.engagementrate = 12.5;

    // Printing the details | طباعة التفاصيل
    cout << "--- Post Details ---" << endl;
    
    // Using the dot operator (.) to access data | استخدام النقطة للوصول للبيانات
    cout << "Author: " << mypost.name << endl;
    cout << "Post: " << mypost.text << endl;
    cout << "Likes: " << mypost.likes << endl;
    cout << "Engagement Rate: " << mypost.engagementrate << "%" << endl;

    return 0;
}

/*Output:
--- Post Details ---
Author: Ahmed Thamer
Post: This is my first post using Structs in C++! #Programming #Tech
Likes: 150
Engagement Rate: 12.5%
*/
