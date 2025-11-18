#include <iostream>
#include <bits/stdc++.h>
#include <windows.h>

using namespace std;
using namespace std::chrono;

void clearScreen() {
    for (int i = 0; i < 5; ++i)
        cout << "\n";
}

void menu();

void bubbleSort(int oNumbers[], int n) {
    auto numbers = oNumbers;
    auto start = steady_clock::now();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; ++j) {
            if (numbers[i] < numbers[j]) {
                int temp = numbers[j];
                numbers[j] = numbers[i];
                numbers[i] = temp;
            }
        }
    }
    auto end = steady_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start).count();

    cout << "Result: ";
    for (int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl << "Duration: " << duration << " nanosecond" << endl;
}

void insertionSort(int numbers[], int n) {
    auto start = steady_clock::now();
    for (int i = 1; i < n; i++) {
        int x = numbers[i];
        int j = i - 1;
        while (j >= 0 && x < numbers[j]) {
            numbers[j + 1] = numbers[j];
            j--;
        }

        numbers[j + 1] = x;
    }
    auto end = steady_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start).count();

    cout << "Result: ";
    for (int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl << "Duration: " << duration << " nanosecond" << endl;
}

void Q1() {
    int n, numbersForBubble[100] = {0}, numbersForInsertion[100];
    cout << "Enter the list size: ";
    cin >> n;
    cout << "Enter numbers: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        numbersForBubble[i] = x;
        numbersForInsertion[i] = x;
    }
    cout << endl << "bubble sort:" << endl;
    bubbleSort(numbersForBubble, n);

    cout << endl << "insertion sort:" << endl;
    insertionSort(numbersForInsertion, n);

    menu();
}

struct Node {
    int data;
    Node *nextNode;
};

void Q2() {
    int n, data;
    Node *start = nullptr, *current, *prev = nullptr, *next = nullptr, *p;
    cout << "Enter the list size: ";
    cin >> n;
    cout << "Enter numbers: ";

    for (int i = 0; i < n; i++) {
        current = new Node();
        cin >> data;
        current->data = data;
        current->nextNode = nullptr;
        if (prev != nullptr) {
            prev->nextNode = current;
            if (start == nullptr) start = prev;
        }
        prev = current;
    }

    current = start;
    prev = nullptr;
    while (current != nullptr){
        next = current->nextNode;
        current->nextNode = prev;
        prev = current;
        current = next;
    }

    start = prev;
    p = start;

    cout << "Result: ";
    while (p != nullptr){
        cout << p->data;
        p = p->nextNode;
    }

}

void Q3(){
    int n1,n2, data;
    Node *start1 = nullptr,*start2 = nullptr, *current1, *current2, *prev1 = nullptr, *prev2 = nullptr, *p;
    cout << "Enter the first list size: ";
    cin >> n1;
    cout << "Enter the first lists numbers: ";

    for (int i = 0; i < n1; i++) {
        current1 = new Node();
        cin >> data;
        current1->data = data;
        current1->nextNode = nullptr;
        if (prev1 != nullptr) {
            prev1->nextNode = current1;
            if (start1 == nullptr) start1 = prev1;
        }
        prev1 = current1;
    }

    cout << "Enter the second list size: ";
    cin >> n2;
    cout << "Enter the second lists numbers: ";

    for (int i = 0; i < n2; i++) {
        current2 = new Node();
        cin >> data;
        current2->data = data;
        current2->nextNode = nullptr;
        if (prev2 != nullptr) {
            prev2->nextNode = current2;
            if (start2 == nullptr) start2 = prev2;
        }
        prev2 = current2;
    }

    p = start1;
    while (p->nextNode != nullptr){
        p = p->nextNode;
    }
    p->nextNode = start2;
    p = start1;
    cout << "Result: ";
    while (p != nullptr){
        cout << p->data;
        p = p->nextNode;
    }
}

void Q4() {
    int n,k,index =1, data;
    Node *start = nullptr, *current, *prev = nullptr, *p;
    cout << "Enter the list size: ";
    cin >> n;
    cout << "Enter the Josephus number: ";
    cin >> k;
    cout << "Enter numbers: ";

    for (int i = 0; i < n; i++) {
        current = new Node();
        cin >> data;
        current->data = data;
        current->nextNode = nullptr;
        if (prev != nullptr) {
            prev->nextNode = current;
            if (start == nullptr) start = prev;
        }
        prev = current;
    }
    current->nextNode = start;

    p = start;
    cout << "Result: ";
    while (p != p->nextNode){
        if (index % (k-1) == 0){
            p->nextNode = p->nextNode->nextNode;
            p = p->nextNode;
        }else{
            p = p->nextNode;
        }
        index++;
    }
    cout << p->data;

}

void Q5() {
    int n, data;
    Node *start = nullptr, *current, *prev = nullptr, *next = nullptr, *p;
    cout << "Enter the list size: ";
    cin >> n;
    cout << "Enter numbers: ";

    for (int i = 0; i < n; i++) {
        current = new Node();
        cin >> data;
        current->data = data;
        current->nextNode = nullptr;
        if (prev != nullptr) {
            prev->nextNode = current;
            if (start == nullptr) start = prev;
        }
        prev = current;
    }

    current = start;
    prev = nullptr;
    while (current != nullptr){
        next = current->nextNode;
        current->nextNode = prev;
        prev = current;
        current = next;
    }
    start->nextNode = prev;
    start = prev;
    p = start;

    cout << "Result: ";
    cout << p->data;
    p = p->nextNode;
    while (p != start){
        cout << p->data;
        p = p->nextNode;
    }

}

void menu() {

    cout << endl << " 1. Q1 => BubbleSort & InsertionSort" << endl;
    cout << " 2. Q2 => Reverse linked list" << endl;
    cout << " 3. Q3 => Merging two linked lists" << endl;
    cout << " 4. Q4 => The Josephus Problem" << endl;
    cout << " 5. Q5 => Reverse circular linked list" << endl;
    cout << " 6. Q6 => Stack using linked list" << endl;

    cout << endl << "Witch question do you wanna run?";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            Q1();
            break;
        case 2:
            Q2();
            break;
        case 3:
            Q3();
            break;
        case 4:
//            Q4();
            break;
        case 5:
//            Q5();
            break;
        case 6:
            break;
        default:
            clearScreen();
            menu();
    }
}

int main() {
    menu();
}
