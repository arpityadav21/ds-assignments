//1.
#include <iostream>
using namespace std;
class node {
public:
    int data;
    node* next;
    node* prev; 
    node(int data1) {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};
class DoublyLinkedList {
public:
    node* head;
    DoublyLinkedList() { head = nullptr; }
    void insertAtHead(int val) {
        node* newNode = new node(val);
        if (head != nullptr) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }
    void insertAtTail(int val) {
        node* newNode = new node(val);
        if (!head) {
            head = newNode;
            return;
        }
        node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    void insertAfter(int target, int val) {
        node* temp = head;
        while (temp && temp->data != target)
            temp = temp->next;
        if (!temp) {
            cout << "Target not found\n";
            return;
        }
        node* newNode = new node(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
    }
    void insertBefore(int target, int val) {
        node* temp = head;
        while (temp && temp->data != target)
            temp = temp->next;
        if (!temp) {
            cout << "Target not found\n";
            return;
        }
        node* newNode = new node(val);
        newNode->next = temp;
        newNode->prev = temp->prev;
        if (temp->prev)
            temp->prev->next = newNode;
        else
            head = newNode;
        temp->prev = newNode;
    }
    void deleteNode(int val) {
        node* temp = head;
        while (temp && temp->data != val)
            temp = temp->next;
        if (!temp) {
            cout << "Node not found\n";
            return;
        }
        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
        delete temp;
        cout << "Deleted node " << val << endl;
    }
    void search(int val) {
        node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == val) {
                cout << "Found " << val << " at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node not found\n";
    }
    void print() {
        node* temp = head;
        cout << "Doubly Linked List: ";
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
class CircularLinkedList {
public:
    node* head;
    CircularLinkedList() { head = nullptr; }

    void insertAtHead(int val) {
        node* newNode = new node(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    void insertAtTail(int val) {
        node* newNode = new node(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void insertAfter(int target, int val) {
        if (!head) {
            cout << "List empty!\n";
            return;
        }
        node* temp = head;
        do {
            if (temp->data == target) {
                node* newNode = new node(val);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Target not found!\n";
    }

    void insertBefore(int target, int val) {
        if (!head) {
            cout << "List empty!\n";
            return;
        }
        node* temp = head;
        node* prev = nullptr;
        do {
            if (temp->data == target) {
                node* newNode = new node(val);
                newNode->next = temp;
                if (prev)
                    prev->next = newNode;
                else {
                    node* last = head;
                    while (last->next != head)
                        last = last->next;
                    last->next = newNode;
                    head = newNode;
                }
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
        cout << "Target not found!\n";
    }

    void deleteNode(int val) {
        if (!head) {
            cout << "List empty!\n";
            return;
        }
        node *temp = head, *prev = nullptr;
        do {
            if (temp->data == val) {
                if (prev)
                    prev->next = temp->next;
                else {
                    node* last = head;
                    while (last->next != head)
                        last = last->next;
                    if (head == head->next)
                        head = nullptr;
                    else {
                        last->next = head->next;
                        head = head->next;
                    }
                }
                delete temp;
                cout << "Deleted node " << val << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
        cout << "Node not found!\n";
    }

    void search(int val) {
        if (!head) {
            cout << "List empty!\n";
            return;
        }
        node* temp = head;
        int pos = 1;
        do {
            if (temp->data == val) {
                cout << "Found " << val << " at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Node not found.\n";
    }

    void print() {
        if (!head) {
            cout << "Circular Linked List is empty.\n";
            return;
        }
        node* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(Back to Head)\n";
    }
};

int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int listType, choice, val, target;

    do {
        cout << "\n1. Doubly Linked List\n";
        cout << "2. Circular Linked List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> listType;

        if (listType == 1 || listType == 2) {
            do {
                cout << "\n--- " << (listType == 1 ? "Doubly" : "Circular") << " Linked List Menu ---\n";
                cout << "1. Insert at beginning\n";
                cout << "2. Insert at end\n";
                cout << "3. Insert after a node\n";
                cout << "4. Insert before a node\n";
                cout << "5. Delete a node\n";
                cout << "6. Search for a node\n";
                cout << "7. Display list\n";
                cout << "8. Back to main menu\n";
                cout << "Enter choice: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        cout << "Enter value: ";
                        cin >> val;
                        (listType == 1 ? dll.insertAtHead(val) : cll.insertAtHead(val));
                        break;
                    case 2:
                        cout << "Enter value: ";
                        cin >> val;
                        (listType == 1 ? dll.insertAtTail(val) : cll.insertAtTail(val));
                        break;
                    case 3:
                        cout << "Enter target: ";
                        cin >> target;
                        cout << "Enter new value: ";
                        cin >> val;
                        (listType == 1 ? dll.insertAfter(target, val) : cll.insertAfter(target, val));
                        break;
                    case 4:
                        cout << "Enter target: ";
                        cin >> target;
                        cout << "Enter new value: ";
                        cin >> val;
                        (listType == 1 ? dll.insertBefore(target, val) : cll.insertBefore(target, val));
                        break;
                    case 5:
                        cout << "Enter value to delete: ";
                        cin >> val;
                        (listType == 1 ? dll.deleteNode(val) : cll.deleteNode(val));
                        break;
                    case 6:
                        cout << "Enter value to search: ";
                        cin >> val;
                        (listType == 1 ? dll.search(val) : cll.search(val));
                        break;
                    case 7:
                        (listType == 1 ? dll.print() : cll.print());
                        break;
                    case 8:
                        cout << "Returning to main menu...\n";
                        break;
                    default:
                        cout << "Invalid choice!\n";
                }
            } while (choice != 8);
        }
    } while (listType != 0);
    cout << "Exiting\n";
    return 0;
}


//2.
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
void display(Node* head) {
    if (head == nullptr) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data;
}
int main() {
    Node* head = new Node{20, nullptr};
    Node* second = new Node{100, nullptr};
    Node* third = new Node{40, nullptr};
    Node* fourth = new Node{80, nullptr};
    Node* fifth = new Node{60, nullptr};
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = head;
    display(head);
    return 0;
}


//3.
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
};
Node* insertDoubly(Node* head, int value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (head == nullptr) return newNode;
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}
Node* insertCircular(Node* head, int value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (head == nullptr) {
        newNode->next = newNode;
        return newNode;
    }
    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
    return head;
}
int sizeOfDoubly(Node* head) {
    int count = 0;
    while (head != nullptr) {
        count++;
        head = head->next;
    }
    return count;
}
int sizeOfCircular(Node* head) {
    if (head == nullptr) return 0;
    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}
int main() {
    Node* doublyHead = nullptr;
    Node* circularHead = nullptr;
    int n, value;
    cout << "Enter number of nodes for Doubly Linked List: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> value;
        doublyHead = insertDoubly(doublyHead, value);
    }
    cout << "Enter number of nodes for Circular Linked List: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> value;
        circularHead = insertCircular(circularHead, value);
    }
    cout << "Size of Doubly Linked List: " << sizeOfDoubly(doublyHead) << endl;
    cout << "Size of Circular Linked List: " << sizeOfCircular(circularHead) << endl;
    return 0;
}


//4.
#include <iostream>
using namespace std;
struct Node {
    char data;
    Node* next;
    Node* prev;
};

Node* insert(Node* head, char value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (head == nullptr) return newNode;

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

bool isPalindrome(Node* head) {
    if (head == nullptr) return true;

    Node* left = head;
    Node* right = head;

    while (right->next != nullptr)
        right = right->next;

    while (left != right && right->next != left) {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }

    return true;
}

int main() {
    Node* head = nullptr;
    string s;

    cout << "Enter characters: ";
    cin >> s;

    for (char c : s)
        head = insert(head, c);

    if (isPalindrome(head))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}


//5.
#include <iostream>
using namespace std;
struct Node{int data;Node* next;};
Node* insert(Node* head,int v){
    Node* n=new Node{v,nullptr};
    if(head==nullptr) return n;
    Node* t=head;
    while(t->next!=nullptr) t=t->next;
    t->next=n;
    return head;
}
bool isCircular(Node* head){
    if(head==nullptr) return false;
    Node* t=head->next;
    while(t!=nullptr && t!=head) t=t->next;
    return t==head;
}
int main(){
    int n,v;
    cin>>n;
    Node* head=nullptr;
    for(int i=0;i<n;i++){cin>>v;head=insert(head,v);}
    int idx;
    cin>>idx;
    if(head!=nullptr){
        Node* last=head;
        while(last->next!=nullptr) last=last->next;
        if(idx==-1) last->next=nullptr;
        else{
            Node* t=head;
            for(int i=0;i<idx;i++) t=t->next;
            last->next=t;
        }
    }
    if(isCircular(head)) cout<<"Circular Linked List";
    else cout<<"Not Circular";
    return 0;
}

