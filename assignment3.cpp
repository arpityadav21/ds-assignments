#include <iostream>
using namespace std;
// int stack[100];
// int top =-1;
// int n;
// void push(int item) {
//     if (top == n - 1) {
//         cout << "Stack is full " << item << endl;
//     }
//     else {
//         stack[++top] = item;
//         cout <<"pushed :"<< item << endl;
//     }
// }
// void pop() {
//     if (top == -1) {
//         cout << "Stack is empty" << endl;
//     }
//     else {
//         cout << "Popped element: " << stack[top--] << endl;
//     }
// }
// void display() {
//     if (top == -1) {
//         cout << "Stack is empty" << endl;
//     } else {
//         cout << "Stack elements:" << endl;
//         for (int i = top; i >= 0; i--) {
//             cout << stack[i] << endl;
//         }
//     }
// }

// int main()
// {
//     int item;
//     int choice;
//     cout<<"enter the size of stack: ";
//     cin>>n;
//     for(int i=0; i<n;i++){
//         cout<<"enter the elements of the stack: ";
//         cin>>stack[i];
//     }
//         cout << "1. Push\n";
//         cout << "2. Pop\n";
//         cout << "3. Display\n";
//         cout << "4. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;
//     switch (choice) {
//             case 1:
//                 cout << "Enter element to push: ";
//                 cin >> item;
//                 push(item);
//                 break;
//             case 2:
//                 pop();
//                 break;
//             case 3:
//                 display();
//                 break;
//                 case 4:
//                 cout << "Exiting program...\n";
//                 return 0;

//             default:
//                 cout << "Invalid choice please try again " << endl;
//         }
    
//     return 0;
// }


//1.
// #include <iostream>
// using namespace std;
// int top = -1; 
// bool isEmpty() {
//     return (top == -1);
// }
// bool isFull(int size) {
//     return (top == size - 1);
// }
// void push(int stack[], int size, int value) {
//     if (isFull(size)) {
//         cout << "Stack if full can't push " << value << endl;
//     }
//     else {
//        top = top + 1;          
//        stack[top] = value;   
//        cout << value << " pushed to stack at position " << top;
//     }
// }
// void pop(int stack[]) {
//     if (isEmpty()) {
//         cout << "Can't pop \n";
//     }
//     else {
//         cout << stack[top--] << " popped from stack.\n";
//     }
// }
// void peek(int stack[]) {
//     if (isEmpty()) {
//         cout << "Stack is empty, nothing to peek.\n";
//     } 
//     else {
//         cout << "Top element: " << stack[top] << endl;
//     }
// }
// void display(int stack[]) {
//     if (isEmpty()) {
//         cout << "Stack is empty.\n";
//     } 
//     else {
//         cout << "Stack elements: ";
//         for (int i = top; i >= 0; i--) {
//             cout << stack[i] << " ";
//         }
//         cout << endl;
//     }
// }
// int main() {
//     int size;
//     cout << "Enter size of stack: ";
//     cin >> size;
//     int stack[size]; 
//     int choice, value;
//     do {
//         cout << "1. Push\n";
//         cout << "2. Pop\n";
//         cout << "3. Check isEmpty\n";
//         cout << "4. Check isFull\n";
//         cout << "5. Display\n";
//         cout << "6. Peek\n";
//         cout << "7. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;
//         switch (choice) {
//             case 1:
//                 cout << "Enter value to push: ";
//                 cin >> value;
//                 push(stack, size, value);
//                 break;
//             case 2:
//                 pop(stack);
//                 break;
//             case 3:
//                 cout << (isEmpty() ? "Stack is Empty.\n" : "Stack is NOT Empty.\n");
//                 break;
//             case 4:
//                 cout << (isFull(size) ? "Stack is Full.\n" : "Stack is NOT Full.\n");
//                 break;
//             case 5:
//                 display(stack);
//                 break;
//             case 6:
//                 peek(stack);
//                 break;
//             case 7:
//                 cout << "Exiting program...\n";
//                 break;
//             default:
//                 cout << "Invalid choice! Try again.\n";
//         }
//     } while (choice != 7);
//     return 0;
// }


//2.
// #include <iostream>
// #include <string>
// using namespace std;
// const int MAX = 100;   
// char stackArr[100];
// int top = -1;
// void push(char c) {
//     if (top == MAX - 1) {
//         cout << "Stack Overflow \n";
//     } else {
//         stackArr[++top] = c;
//     }
// }
// char pop() {
//     if (top == -1) {
//         cout << "Stack Underflow!\n";
//         return '\0';
//     } else {
//         return stackArr[top--];
//     }
// }
// int main() {
//     string str;
//     cout << "Enter a string: ";
//     cin >> str;   
//     for (int i = 0; i < str.length(); i++) {
//         push(str[i]);
//     }
//     cout << "Reversed string: ";
//     while (top != -1) {
//         cout << pop();
//     }
//     cout << endl;
//     return 0;
// }



