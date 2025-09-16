//1.
// #include <iostream>
// using namespace std;
// #define SIZE 5 
// class Queue {
//     int arr[SIZE];
//     int front, rear;
// public:
//     Queue() {
//         front = -1;
//         rear = -1;
//     }
//     bool isEmpty() {
//         return (front == -1);
//     }
//     bool isFull() {
//         return (rear == SIZE - 1);
//     }
//     void enqueue(int value) {
//         if (isFull()) {
//             cout << "Queue is Full, Cannot enqueue " << value << endl;
//             return;
//         }
//         if (front == -1) front = 0; 
//         arr[++rear] = value;
//         cout << value << " enqueued into the queue" << endl;
//     }
//     void dequeue() {
//         if (isEmpty()) {
//             cout << "Queue is Empty! Cannot dequeue." << endl;
//             return;
//         }
//         cout << arr[front] << " dequeued from the queue." << endl;
//         if (front == rear) { 
//             front = rear = -1;
//         } else {
//             front++;
//         }
//     }
//     void peek() {
//         if (isEmpty()) {
//             cout << "Queue is Empty!" << endl;
//         } else {
//             cout << "Front element: " << arr[front] << endl;
//         }
//     }
//     void display() {
//         if (isEmpty()) {
//             cout << "Queue is Empty!" << endl;
//         } else {
//             cout << "Queue elements: ";
//             for (int i = front; i <= rear; i++) {
//                 cout << arr[i] << " ";
//             }
//             cout << endl;
//         }
//     }
// };
// int main() {
//     Queue q;
//     int choice, value;
//     do {
//         cout << "1. Enqueue" << endl;
//         cout << "2. Dequeue" << endl;
//         cout << "3. Peek" << endl;
//         cout << "4. Display" << endl;
//         cout << "5. Check if Empty" << endl;
//         cout << "6. Check if Full" << endl;
//         cout << "0. Exit" << endl;
//         cout << "Enter your choice: ";
//         cin >> choice;
//         switch (choice) {
//         case 1:
//             cout << "Enter value to enqueue: ";
//             cin >> value;
//             q.enqueue(value);
//             break;
//         case 2:
//             q.dequeue();
//             break;
//         case 3:
//             q.peek();
//             break;
//         case 4:
//             q.display();
//             break;
//         case 5:
//             cout << (q.isEmpty() ? "Queue is Empty" : "Queue is not Empty") << endl;
//             break;
//         case 6:
//             cout << (q.isFull() ? "Queue is Full" : "Queue is not Full") << endl;
//             break;
//         case 0:
//             cout << "Exiting program..." << endl;
//             break;
//         default:
//             cout << "Invalid choice! Try again." << endl;
//         }
//     } while (choice != 0);
//     return 0;
// }


//2.
// #include <iostream>
// using namespace std;
// #define SIZE 5
// class CircularQueue {
//     int arr[SIZE];
//     int front, rear;
// public:
//     CircularQueue() {
//         front = -1;
//         rear = -1;
//     }
//     bool isEmpty() {
//         return (front == -1);
//     }
//     bool isFull() {
//         return ((rear + 1) % SIZE == front);
//     }
//     void enqueue(int value) {
//         if (isFull()) {
//             cout << "Queue is Full! Cannot enqueue " << value << endl;
//             return;
//         }
//         if (isEmpty()) {
//             front = rear = 0;
//         } else {
//             rear = (rear + 1) % SIZE;
//         }
//         arr[rear] = value;
//         cout << value << " enqueued into the queue." << endl;
//     }
//     void dequeue() {
//         if (isEmpty()) {
//             cout << "Queue is Empty! Cannot dequeue." << endl;
//             return;
//         }
//         cout << arr[front] << " dequeued from the queue." << endl;
//         if (front == rear) {
//             front = rear = -1;
//         } else {
//             front = (front + 1) % SIZE;
//         }
//     }
//     void peek() {
//         if (isEmpty()) {
//             cout << "Queue is Empty!" << endl;
//         } else {
//             cout << "Front element: " << arr[front] << endl;
//         }
//     }
//     void display() {
//         if (isEmpty()) {
//             cout << "Queue is Empty!" << endl;
//             return;
//         }
//         cout << "Queue elements: ";
//         int i = front;
//         while (true) {
//             cout << arr[i] << " ";
//             if (i == rear) break;
//             i = (i + 1) % SIZE;
//         }
//         cout << endl;
//     }
// };

// int main() {
//     CircularQueue q;
//     int choice, value;
//     do {
//         cout << "1. Enqueue" << endl;
//         cout << "2. Dequeue" << endl;
//         cout << "3. Peek" << endl;
//         cout << "4. Display" << endl;
//         cout << "5. Check if Empty" << endl;
//         cout << "6. Check if Full" << endl;
//         cout << "0. Exit" << endl;
//         cout << "Enter your choice: ";
//         cin >> choice;
//         switch (choice) {
//         case 1:
//             cout << "Enter value to enqueue: ";
//             cin >> value;
//             q.enqueue(value);
//             break;
//         case 2:
//             q.dequeue();
//             break;
//         case 3:
//             q.peek();
//             break;
//         case 4:
//             q.display();
//             break;
//         case 5:
//             cout << (q.isEmpty() ? "Queue is Empty" : "Queue is not Empty") << endl;
//             break;
//         case 6:
//             cout << (q.isFull() ? "Queue is Full" : "Queue is not Full") << endl;
//             break;
//         case 0:
//             cout << "Exiting program..." << endl;
//             break;
//         default:
//             cout << "Invalid choice! Try again." << endl;
//         }
//     } while (choice != 0);
//     return 0;
// }


//3.
// #include <iostream>
// using namespace std;
// #define SIZE 100
// class Queue {
//     int arr[SIZE];
//     int front, rear;
// public:
//     Queue() { front = -1; rear = -1; }
//     bool isEmpty() { return front == -1; }
//     bool isFull() { return rear == SIZE - 1; }
//     void enqueue(int x) {
//         if (isFull()) return;
//         if (isEmpty()) front = 0;
//         arr[++rear] = x;
//     }
//     int dequeue() {
//         if (isEmpty()) return -1;
//         int val = arr[front];
//         if (front == rear) { front = rear = -1; }
//         else front++;
//         return val;
//     }
//     int peek() {
//         if (isEmpty()) return -1;
//         return arr[front];
//     }
//     int size() {
//         if (isEmpty()) return 0;
//         return rear - front + 1;
//     }
//     void display() {
//         if (isEmpty()) { cout << "Queue is empty" << endl; return; }
//         for (int i = front; i <= rear; i++) cout << arr[i] << " ";
//         cout << endl;
//     }
// };
// void interleaveQueue(Queue &q) {
//     int n = q.size();
//     if (n % 2 != 0) {
//         cout << "Queue size must be even to interleave!" << endl;
//         return;
//     }
//     int half = n / 2;
//     Queue firstHalf;
//     for (int i = 0; i < half; i++) {
//         firstHalf.enqueue(q.dequeue());
//     }
//     while (!firstHalf.isEmpty()) {
//         q.enqueue(firstHalf.dequeue());
//         q.enqueue(q.dequeue());
//     }
// }
// int main() {
//     Queue q;
//     int n, val;
//     cout << "Enter number of elements (even): ";
//     cin >> n;
//     cout << "Enter elements: ";
//     for (int i = 0; i < n; i++) {
//         cin >> val;
//         q.enqueue(val);
//     }
//     cout << "Original Queue: ";
//     q.display();
//     interleaveQueue(q);
//     cout << "Interleaved Queue: ";
//     q.display();
//     return 0;
// }


//4.
// #include <iostream>
// using namespace std;
// #define SIZE 100
// class Queue {
//     char arr[SIZE];
//     int front, rear;
// public:
//     Queue() { front = -1; rear = -1; }
//     bool isEmpty() { return front == -1; }
//     bool isFull() { return rear == SIZE - 1; }
//     void enqueue(char x) {
//         if (isFull()) return;
//         if (isEmpty()) front = 0;
//         arr[++rear] = x;
//     }
//     char dequeue() {
//         if (isEmpty()) return '\0';
//         char val = arr[front];
//         if (front == rear) { front = rear = -1; }
//         else front++;
//         return val;
//     }
//     char peek() {
//         if (isEmpty()) return '\0';
//         return arr[front];
//     }
// };
// void firstNonRepeating(string s) {
//     Queue q;
//     int freq[256] = {0};
//     for (int i = 0; i < s.length(); i++) {
//         char ch = s[i];
//         if (ch == ' ') continue;  
//         freq[ch]++;
//         q.enqueue(ch);
//         while (!q.isEmpty() && freq[q.peek()] > 1) {
//             q.dequeue();
//         }
//         if (q.isEmpty()) cout << -1 << " ";
//         else cout << q.peek() << " ";
//     }
//     cout << endl;
// }
// int main() {
//     string input;
//     cout << "Enter string: ";
//     getline(cin, input);
//     cout << "Output: ";
//     firstNonRepeating(input);
//     return 0;
// }


//5.
// #include <iostream>
// using namespace std;
// #define SIZE 100
// class Queue {
//     int arr[SIZE];
//     int front, rear;
// public:
//     Queue() { front = -1; rear = -1; }
//     bool isEmpty() { return front == -1; }
//     bool isFull() { return rear == SIZE - 1; }
//     void enqueue(int x) {
//         if (isFull()) return;
//         if (isEmpty()) front = 0;
//         arr[++rear] = x;
//     }
//     int dequeue() {
//         if (isEmpty()) return -1;
//         int val = arr[front];
//         if (front == rear) front = rear = -1;
//         else front++;
//         return val;
//     }
//     int peek() {
//         if (isEmpty()) return -1;
//         return arr[front];
//     }
//     int size() {
//         if (isEmpty()) return 0;
//         return rear - front + 1;
//     }
// };

// class StackOneQueue {
//     Queue q;
// public:
//     void push(int x) {
//         q.enqueue(x);
//         int sz = q.size();
//         for (int i = 0; i < sz - 1; i++) {
//             q.enqueue(q.dequeue());
//         }
//     }
//     int pop() {
//         if (q.isEmpty()) return -1;
//         return q.dequeue();
//     }
//     int top() {
//         if (q.isEmpty()) return -1;
//         return q.peek();
//     }
//     bool isEmpty() { return q.isEmpty(); }
// };

// class StackTwoQueues {
//     Queue q1, q2;
// public:
//     void push(int x) { q1.enqueue(x); }
//     int pop() {
//         if (q1.isEmpty()) return -1;
//         while (q1.size() > 1) q2.enqueue(q1.dequeue());
//         int val = q1.dequeue();
//         Queue temp = q1; q1 = q2; q2 = temp;
//         return val;
//     }
//     int top() {
//         if (q1.isEmpty()) return -1;
//         while (q1.size() > 1) q2.enqueue(q1.dequeue());
//         int val = q1.peek();
//         q2.enqueue(q1.dequeue());
//         Queue temp = q1; q1 = q2; q2 = temp;
//         return val;
//     }
//     bool isEmpty() { return q1.isEmpty(); }
// };
