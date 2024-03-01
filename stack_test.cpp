#include "stack.h"
#include <iostream>
using namespace std;

int main(){
    Stack<int> test;
    test.push(1);
    test.push(2);
    test.push(3);
    test.push(4);
    test.push(5);
    test.push(6);

    cout << "Top: " << test.top() << endl;
    cout << "Popped!" << endl;
    test.pop();
    cout << "Top: " << test.top() << endl;
    cout << "Popped!" << endl;
    test.pop();
    cout << "Top: " << test.top() << endl;
    cout << "Popped!" << endl;
    test.pop();
    cout << "Top: " << test.top() << endl;
    cout << "Popped!" << endl;
    test.pop();
    cout << "Top: " << test.top() << endl;
    cout << "Popped!" << endl;
    test.pop();
    cout << "Top: " << test.top() << endl;
    cout << "Pushed 16" << endl;
    test.push(16);
    cout << "Top: " << test.top() << endl;
}