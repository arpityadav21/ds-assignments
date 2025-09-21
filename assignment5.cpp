//1.
#include<iostream>
using namespace std;
    class node{
    public:
    int data;
    node* next;
    public:
    node(int data1,node* next1){
        data=data1;
        next=next1;
    }
    public:
    node(int data1){
        data=data1;
        next=nullptr;
    }
};
node* convertArrToLL(int arr[],int n){
    node* head= new node(arr[0]);
    node* mover =head;
    for(int i=1;i<n;i++){
        node* temp= new node(arr[i]);
        mover->next = temp;
        mover= temp;
    }
    return head;
}
void print(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }   
    cout<<endl;
}

node* insertHead(node* head,int val){
    return new node(val,head);
}

node* insertTail(node* head,int val){
    if(head==NULL) return new node(val);
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    node* newnode= new node(val);
    temp->next=newnode;
    return head;
}

node* insertBeforeVal(node* head, int el, int val) {
    if (head == NULL) return NULL;
    if (head->data==val) {
        return new node(el, head);
    }
    node* temp = head;
    while (temp->next != NULL) {
        if (temp->next->data==val) {
            node* x = new node(el, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

node* removehead(node* head){
    if(head==NULL) return head;
    node* temp=head;
    head=head->next;
    delete temp;
    return head;
}

node* removetail(node* head){
    if(head==NULL || head->next==NULL) return NULL;
    node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;
}

node* removeParticularEl(node* head, int el) {
    if (head == NULL) return head;
    if (head->data==el) {
        node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    node* temp = head;
    node* prev = NULL;
    while (temp != NULL) {
        if (temp->data == el) {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

void search(node* head, int val) {
    int pos = 1;
    while (head != NULL) {
        if (head->data == val) {
            cout << "Found " << val << " at position " << pos << endl;
            return;
        }
        head = head->next;
        pos++;
    }
    cout << val << " not found in the list." << endl;
}

int main() {
    node* head = NULL;
    int choice, value, target;
    do {
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before a node\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete a specific node\n";
        cout << "7. Search for a node\n";
        cout << "8. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                head = insertHead(head, value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                head = insertTail(head, value);
                break;
            case 3:
                cout << "Enter target node value: ";
                cin >> target;
                cout << "Enter new value to insert: ";
                cin >> value;
                head = insertBeforeVal(head, value, target);
                break;
            case 4:
                head = removehead(head);
                break;
            case 5:
                head = removetail(head);
                break;
            case 6:
                cout << "Enter value to delete: ";
                cin >> value;
                head = removeParticularEl(head, value);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                search(head, value);
                break;
            case 8:
                print(head);
                break;
            case 0:
                cout << "Exit" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);
    return 0;
}



//2.
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};
Node* insertTail(Node* head, int val) {
    Node* newNode = new Node(val);
    if (!head) return newNode;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}
void printList(Node* head) {
    if (!head) {
        cout << "List is empty" << endl;
        return;
    }
    while (head) {
        cout << head->data;
        if (head->next) cout<<" ";
        head = head->next;
    }
    cout << endl;
}
Node* Delete(Node* head, int key, int &count) {
    count = 0;
    while (head && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }
    Node* curr = head;
    while (curr && curr->next) {
        if (curr->next->data == key) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            count++;
        } else {
            curr = curr->next;
        }
    }
    return head;
}
int main() {
    int n, val, key;
    Node* head = nullptr;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        head = insertTail(head, val);
    }
    cout << "Original List: ";
    printList(head);
    cout << "Enter key to delete: ";
    cin >> key;
    int count = 0;
    head = Delete(head, key, count);
    cout << "Count: " << count << endl;
    cout << "Updated List: ";
    printList(head);
    return 0;
}



//3.
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};
Node* insertTail(Node* head, int val) {
    Node* newNode = new Node(val);
    if (!head) return newNode;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}
Node* findMiddle(Node* head) {
    if (!head) return nullptr;
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main() {
    int n, val;
    Node* head = nullptr;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        head = insertTail(head, val);
    }
    cout << "Linked List: ";
    printList(head);
    Node* mid = findMiddle(head);
    if (mid) {
        cout << "Middle element: " << mid->data << endl;
    } else {
        cout << "List is empty" << endl;
    }
    return 0;
}



//4.
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};
Node* insertTail(Node* head, int val) {
    Node* newNode = new Node(val);
    if (!head) return newNode;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " ";
        head = head->next;
    }
cout<<endl;
}
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
int main() {
    int n, val;
    Node* head = nullptr;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        head = insertTail(head, val);
    }
    cout << "Original List: ";
    printList(head);
    head = reverseList(head);
    cout << "Reversed List: ";
    printList(head);
    return 0;
}
