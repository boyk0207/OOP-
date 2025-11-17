#include "include/circle.h"
#include "include/triangle.h"
#include "include/square.h"
#include "include/LinkedList.h"
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int main() {
    srand(time(0));

    // 20-30 орчим шугаман санамсаргүй тооны дүрсүүдийг үүсгэх
    int n = 20 + rand() % 11; // 20-30 үнэ цэнэ
    
    cout << "== LinkedList Template test ==" << endl;
    cout << "Niit uusgesen object: " << n << endl << endl;

    // LinkedList объект үүсгэх - twod* зүйлүүдийг хадгалах
    LinkedList<twod*> shapes;

    // Үйлчилгээ: санамсаргүй дүрсүүдийг үүсгэж LinkedList-д нэмэх
    for (int i = 0; i < n; i++) {
        int shapeType = rand() % 3; // 0-Circle, 1-Square, 2-Triangle
        float randomSide = 5.0f + (rand() % 20); // 5-24 хоорондох санамсаргүй урт

        twod* shape = nullptr;

        if (shapeType == 0) {
            shape = new circle(randomSide);
        } else if (shapeType == 1) {
            shape = new square(randomSide);
        } else {
            shape = new triangle(randomSide);
        }

        shapes.add(shape);
    }

    cout << "LinkedList length: " << shapes.length() << endl << endl;

    // Бүх объектыг хэвлэх
    cout << "== Uusgesen buh dursee (nemsen daraalaa) ==" << endl;
    for (int i = 0; i < shapes.length(); i++) {
        cout << "[" << i << "] " << shapes[i]->name 
             << " - Area: " << shapes[i]->area() 
             << " - Perimeter: " << shapes[i]->perimeter() << endl;
    }

    // LinkedList-д хадгалагдсан дүрсүүдийг талбайгаар нь эрмбэлэх (Bubble Sort)
    cout << "\n== Talbaigaar erembelsen (osohoor) ==" << endl;
    for (int i = 0; i < shapes.length() - 1; i++) {
        for (int j = 0; j < shapes.length() - i - 1; j++) {
            if (shapes[j]->area() > shapes[j + 1]->area()) {
                // Swap
                twod* temp = shapes[j];
                shapes[j] = shapes[j + 1];
                shapes[j + 1] = temp;
            }
        }
    }

    // Эрэмбэлсэн дүрсүүдийг хэвлэх
    for (int i = 0; i < shapes.length(); i++) {
        cout << "[" << i << "] " << shapes[i]->name 
             << " - Area: " << shapes[i]->area() 
             << " - Perimeter: " << shapes[i]->perimeter() << endl;
    }

    cout << "\n== Niit uusgesen object: " << shape::count_ret() << " ==" << endl;

    // LinkedList ба санах ойг цэвэрлэх
    for (int i = 0; i < shapes.length(); i++) {
        delete shapes[i];
    }

    return 0;
}
