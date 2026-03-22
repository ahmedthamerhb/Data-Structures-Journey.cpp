/* Project: Electronic Component Quality Control (QC)
   Purpose: Testing hardware components using technical thresholds.
   Logic: Using Structs to store sensor data and validate product safety.
   Author: Ahmed Thamer 
   Language: C++
*/

#include <iostream>
#include <string>

using namespace std;

// 1. Defining the Component Structure | تعريف هيكل القطعة الإلكترونية
struct ElectronicComponent {
    string modelName;      // Model name (e.g., CPU-X1) | اسم الموديل
    float temperature;     // Current temperature in Celsius | درجة الحرارة الحالية
    float voltage;         // Operating voltage | جهد التشغيل
    bool isFunctional;     // Overall hardware status | الحالة التشغيلية العامة
};

int main() {
    // 2. Creating an instance for testing | إنشاء نسخة للفحص
    ElectronicComponent processor;

    // 3. Assigning Test Data | إسناد بيانات الفحص
    processor.modelName = "Snapdragon 8 Gen 3";
    processor.temperature = 42.5; // Degree Celsius | درجة سيليزية
    processor.voltage = 1.2;      // Volts | فولت
    processor.isFunctional = true;

    // 4. QC Logic: Decision Making | منطق فحص الجودة: اتخاذ القرار
    cout << "--- Hardware Quality Control Report ---" << endl;
    cout << "Model: " << processor.modelName << endl;
    cout << "Temp: " << processor.temperature << " C" << endl;

    // Logic: If temperature is > 45C, it fails the safety test
    // منطق: إذا كانت الحرارة أعلى من 45، تفشل القطعة في اختبار الأمان
    bool passedSafety = (processor.temperature <= 45.0) && processor.isFunctional;

    cout << "---------------------------------------" << endl;
    if (passedSafety) {
        cout << "STATUS: [PASS] - Component is safe for shipping." << endl;
    } else {
        cout << "STATUS: [FAIL] - Overheating or Hardware Fault detected!" << endl;
    }

    return 0;
}

/*outout:
--- Hardware Quality Control Report ---
Model: Snapdragon 8 Gen 3
Temp: 42.5 C
---------------------------------------
STATUS: [PASS] - Component is safe for shipping.


*/
