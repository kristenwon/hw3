#include "heap.h"
#include <functional>
#include <iostream>
using namespace std;

int main(){
    
    // testing default values binary min-heap
    Heap<int> test;
    test.push(3);
    test.push(10);
    // test.push(3);
    // test.push(11);
    // test.push(6);
    // test.push(8);
    // test.push(9);

    // test push
    cout << "Top: " << test.top() << endl;
    cout << "Popped!" << endl;
    test.pop();
    cout << "Top: " << test.top() << endl;
    // cout << "Popped!" << endl;
    // test.pop();
    // cout << "Top: " << test.top() << endl;
    // cout << "Popped!" << endl;
    // test.pop();
    // cout << "Top: " << test.top() << endl;
    // cout << "Popped!" << endl;
    // test.pop();
    // cout << "Top: " << test.top() << endl;
    // cout << "Popped!" << endl;
    // test.pop();
    // cout << "Top: " << test.top() << endl;
    // test.pop();
    // cout << "Top: " << test.top() << endl;
}