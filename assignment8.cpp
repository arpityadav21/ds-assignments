//1.
// #include <iostream>
// using namespace std;
// struct Node {
//     int data;
//     Node* left;
//     Node* right;
//     Node(int value) {
//         data = value;
//         left = right = nullptr;
//     }
// };

// void preorder(Node* root) {
//     if (root == nullptr)
//         return;
//     cout << root->data << " ";
//     preorder(root->left);
//     preorder(root->right);
// }

// void inorder(Node* root) {
//     if (root == nullptr)
//         return;
//     inorder(root->left);
//     cout << root->data << " ";
//     inorder(root->right);
// }

// void postorder(Node* root) {
//     if (root == nullptr)
//         return;
//     postorder(root->left);
//     postorder(root->right);
//     cout << root->data << " ";
// }

// int main() {
//     Node* root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
//     root->left->left = new Node(4);
//     root->left->right = new Node(5);
//     cout << "Preorder traversal: ";
//     preorder(root);
//     cout << endl;
//     cout << "Inorder traversal: ";
//     inorder(root);
//     cout << endl;
//     cout << "Postorder traversal: ";
//     postorder(root);
//     cout << endl;
//     return 0;
// }


//2.
// #include <iostream>
// using namespace std;
// struct Node {
//     int data;
//     Node* left;
//     Node* right;
//     Node(int value) {
//         data = value;
//         left = right = nullptr;
//     }
// };
// Node* insert(Node* root, int value) {
//     if (root == nullptr)
//         return new Node(value);
//     if (value < root->data)
//         root->left = insert(root->left, value);
//     else if (value > root->data)
//         root->right = insert(root->right, value);
//     return root;
// }
// Node* findMin(Node* root) {
//     while (root && root->left != nullptr)
//         root = root->left;
//     return root;
// }
// Node* findMax(Node* root) {
//     while (root && root->right != nullptr)
//         root = root->right;
//     return root;
// }
// void PS(Node* root, int key, Node*& predecessor, Node*& successor) {
//     if (root == nullptr)
//         return;
//     if (root->data == key) {
//         if (root->left)
//             predecessor = findMax(root->left);
//         if (root->right)
//             successor = findMin(root->right);
//         return;
//     }
//     if (key < root->data) {
//         successor = root;
//         PS(root->left, key, predecessor, successor);
//     } else {
//         predecessor = root;
//         PS(root->right, key, predecessor, successor);
//     }
// }
// int main(){
//     Node*root=nullptr;
//     int el[]={10,40,60,80,30,20};
//     for(int i=0;i<6;i++){
//         root=insert(root,el[i]);
//     }
//     int key;
//     cout<<"enter the element : ";
//     cin>>key;
//     Node*pre=NULL;
//     Node*suc=NULL;
//     PS(root,key,pre,suc);
//     if (pre) cout << "Predecessor: " << pre->data << endl;
//     else cout << "No predecessor\n";
//     if (suc) cout << "Successor: " << suc->data << endl;
//     else cout << "No successor\n";
//     return 0;
// }


//3.
// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* left;
//     Node* right;
// };

// Node* createNode(int v) {
//     Node* n = new Node;
//     n->data = v;
//     n->left = n->right = nullptr;
//     return n;
// }

// Node* insert(Node* root, int v) {
//     if (root == nullptr) return createNode(v);
//     if (v < root->data) root->left = insert(root->left, v);
//     else if (v > root->data) root->right = insert(root->right, v);
//     return root;
// }

// Node* findMin(Node* root) {
//     while (root->left != nullptr) root = root->left;
//     return root;
// }

// Node* deleteNode(Node* root, int v) {
//     if (root == nullptr) return root;
//     if (v < root->data) root->left = deleteNode(root->left, v);
//     else if (v > root->data) root->right = deleteNode(root->right, v);
//     else {
//         if (root->left == nullptr) {
//             Node* t = root->right;
//             delete root;
//             return t;
//         }
//         else if (root->right == nullptr) {
//             Node* t = root->left;
//             delete root;
//             return t;
//         }
//         Node* t = findMin(root->right);
//         root->data = t->data;
//         root->right = deleteNode(root->right, t->data);
//     }
//     return root;
// }

// int maxDepth(Node* root) {
//     if (root == nullptr) return 0;
//     int l = maxDepth(root->left);
//     int r = maxDepth(root->right);
//     return (l > r ? l : r) + 1;
// }

// int minDepth(Node* root) {
//     if (root == nullptr) return 0;
//     int l = minDepth(root->left);
//     int r = minDepth(root->right);
//     if (l == 0 || r == 0) return l + r + 1;
//     return (l < r ? l : r) + 1;
// }

// void inorder(Node* root) {
//     if (root == nullptr) return;
//     inorder(root->left);
//     cout << root->data << " ";
//     inorder(root->right);
// }

// int main() {
//     Node* root = nullptr;
//     int choice, value;

//     while (true) {
//         cin >> choice;
//         if (choice == 1) {
//             cin >> value;
//             root = insert(root, value);
//         }
//         else if (choice == 2) {
//             cin >> value;
//             root = deleteNode(root, value);
//         }
//         else if (choice == 3) {
//             cout << maxDepth(root) << endl;
//         }
//         else if (choice == 4) {
//             cout << minDepth(root) << endl;
//         }
//         else if (choice == 5) {
//             inorder(root);
//             cout << endl;
//         }
//         else if (choice == 0) break;
//     }

//     return 0;
// }


//4.
// #include <iostream>
// #include <queue>
// using namespace std;

// struct Node{
//     int data;
//     Node* left;
//     Node* right;
// };

// Node* newNode(int v){
//     Node* n=new Node;
//     n->data=v;
//     n->left=n->right=nullptr;
//     return n;
// }

// Node* buildTree(){
//     int x;
//     cin>>x;
//     if(x==-1) return nullptr;
//     Node* root=newNode(x);
//     queue<Node*> q;
//     q.push(root);
//     while(!q.empty()){
//         Node* t=q.front();
//         q.pop();
//         cin>>x;
//         if(x!=-1){
//             t->left=newNode(x);
//             q.push(t->left);
//         }
//         cin>>x;
//         if(x!=-1){
//             t->right=newNode(x);
//             q.push(t->right);
//         }
//     }
//     return root;
// }

// bool check(Node* root,long long minv,long long maxv){
//     if(root==nullptr) return true;
//     if(root->data<=minv || root->data>=maxv) return false;
//     return check(root->left,minv,root->data) && check(root->right,root->data,maxv);
// }

// int main(){
//     Node* root=buildTree();
//     if(check(root,-1e18,1e18)) cout<<"BST";
//     else cout<<"Not BST";
//     return 0;
// }


//5.
// #include <iostream>
// using namespace std;

// void heapify(int a[],int n,int i,bool inc){
//     int p=i;
//     int l=2*i+1;
//     int r=2*i+2;
//     if(inc){
//         if(l<n && a[l]>a[p]) p=l;
//         if(r<n && a[r]>a[p]) p=r;
//     }else{
//         if(l<n && a[l]<a[p]) p=l;
//         if(r<n && a[r]<a[p]) p=r;
//     }
//     if(p!=i){
//         int t=a[p];
//         a[p]=a[i];
//         a[i]=t;
//         heapify(a,n,p,inc);
//     }
// }

// void heapsort(int a[],int n,bool inc){
//     for(int i=n/2-1;i>=0;i--) heapify(a,n,i,inc);
//     for(int i=n-1;i>=0;i--){
//         int t=a[0];
//         a[0]=a[i];
//         a[i]=t;
//         heapify(a,i,0,inc);
//     }
// }

// int main(){
//     int n;
//     cin>>n;
//     int a[n];
//     for(int i=0;i<n;i++) cin>>a[i];
//     int c;
//     cin>>c;
//     bool inc=(c==1);
//     heapsort(a,n,inc);
//     for(int i=0;i<n;i++) cout<<a[i]<<" ";
//     return 0;
// }


//6.
// #include <iostream>
// using namespace std;

// void heapify(int a[],int n,int i){
//     int p=i,l=2*i+1,r=2*i+2;
//     if(l<n && a[l]>a[p]) p=l;
//     if(r<n && a[r]>a[p]) p=r;
//     if(p!=i){
//         int t=a[p]; a[p]=a[i]; a[i]=t;
//         heapify(a,n,p);
//     }
// }

// void insertPQ(int a[],int& n,int v){
//     a[n]=v;
//     int i=n;
//     n++;
//     while(i>0){
//         int p=(i-1)/2;
//         if(a[p]<a[i]){
//             int t=a[p]; a[p]=a[i]; a[i]=t;
//             i=p;
//         } else break;
//     }
// }

// int deleteMax(int a[],int& n){
//     if(n==0) return -1;
//     int mx=a[0];
//     a[0]=a[n-1];
//     n--;
//     heapify(a,n,0);
//     return mx;
// }

// void display(int a[],int n){
//     for(int i=0;i<n;i++) cout<<a[i]<<" ";
//     cout<<endl;
// }

// int main(){
//     int a[100],n=0,ch,v;
//     while(true){
//         cin>>ch;
//         if(ch==1){cin>>v; insertPQ(a,n,v);}
//         else if(ch==2){cout<<deleteMax(a,n)<<endl;}
//         else if(ch==3){display(a,n);}
//         else if(ch==4) break;
//     }
//     return 0;
// }


