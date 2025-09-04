// //1.
// #include <iostream>
// using namespace std;
// int arr[100];
// int ub;  
// void createarray() {
//     cout << "Enter the size of the array: ";
//     cin >> ub;
//     for (int i = 0; i < ub; i++) {
//         cout << "Enter element " << i + 1 << ": ";
//         cin >> arr[i];
//     }
//     cout << "Array elements are:\n";
//     for (int i = 0; i < ub; i++) {
//         cout << arr[i] << endl;
//     }
// }
// void insertarray() {
//     int element, pos;
//     cout << "Enter the element you want to insert: ";
//     cin >> element;
//     cout << "Enter the position (1-based index): ";
//     cin >> pos;
//     for (int i = ub - 1; i >= pos - 1; i--) {
//         arr[i + 1] = arr[i];
//     }
//     arr[pos - 1] = element;
//     ub++;
//     cout << "Array after insertion:\n";
//     for (int i = 0; i < ub; i++) {
//         cout << arr[i] << endl;
//     }
// }
// void displayarray() {
//     if (ub == 0) {
//         cout << "Array is empty!\n";
//         return;
//     }
//     cout << "Array elements are:\n";
//     for (int i = 0; i < ub; i++) {
//         cout << arr[i] << endl;
//     }
// }
// void deletearray() {
//     int element, i;
//     cout << "Enter the element you want to delete: ";
//     cin >> element;
//     for (i = 0; i < ub; i++) {
//         if (arr[i] == element) {
//             for (int j = i; j < ub - 1; j++) {
//                 arr[j] = arr[j + 1];
//             }
//             ub--;
//             cout << "Element deleted.\n";
//             displayarray();
//             return;
//         }
//     }
//     cout << "Element not found!\n";
// }
// void linearsearch() {
//     int element;
//     cout << "Enter the element to search: ";
//     cin >> element;
//     for (int i = 0; i < ub; i++) {
//         if (arr[i] == element) {
//             cout << "Element found at position " << i + 1 << endl;
//             return;
//         }
//     }
//     cout << "Element not found!\n";
// }
// int main() {
//     int choice;
//     do {
//         cout << "\n—— MENU ——\n";
//         cout << "1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT\n";
//         cout << "Enter your choice: ";
//         cin >> choice;
//         switch (choice) {
//             case 1: createarray(); break;
//             case 2: displayarray(); break;
//             case 3: insertarray(); break;
//             case 4: deletearray(); break;
//             case 5: linearsearch(); break;
//             case 6: cout << "Exiting program...\n"; break;
//             default: cout << "Invalid choice! Please enter 1-6.\n";
//         }
//     } while (choice != 6);
//     return 0;
// }


//2.
// #include <iostream>
// #include <algorithm>
// using namespace std;
// int main() {
//     int arr[] = {1, 2, 2, 3, 4, 4, 5};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     sort(arr, arr + n);
//     int j = 0; 
//     for(int i = 1; i < n; i++) {
//         if(arr[i] != arr[j]) {
//             j++;
//             arr[j] = arr[i];
//         }
//     }
//     cout << "Unique elements: ";
//     for(int i = 0; i <= j; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }


//3. 10000


//4.(A)(B)(C)
// #include <iostream>
// using namespace std;
// int main() {
//     int arr[] = {1, 2, 3, 4, 5};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int start = 0, end = n-1;
//     while(start < end) {
//         swap(arr[start], arr[end]);
//         start++;
//         end--;
//     }
//     cout << "Reversed array: ";
//     for(int i = 0; i < n; i++)
//         cout << arr[i] << " ";
//     cout << endl;
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main() {
//     int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
//     int B[3][2] = {{7, 8}, {9, 10}, {11, 12}};
//     int C[2][2] = {0}; 
//     for(int i = 0; i < 2; i++) {
//         for(int j = 0; j < 2; j++) {
//             for(int k = 0; k < 3; k++) {
//                 C[i][j] += A[i][k] * B[k][j];
//             }
//         }
//     }
//     cout << "Result of matrix multiplication:\n";
//     for(int i = 0; i < 2; i++) {
//         for(int j = 0; j < 2; j++)
//             cout << C[i][j] << " ";
//         cout << endl;
//     }
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main() {
//     int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
//     int transpose[3][2]; 
//     for(int i = 0; i < 2; i++) {
//         for(int j = 0; j < 3; j++) {
//             transpose[j][i] = matrix[i][j];
//         }
//     }
//     cout << "Transpose of the matrix:\n";
//     for(int i = 0; i < 3; i++) {
//         for(int j = 0; j < 2; j++)
//             cout << transpose[i][j] << " ";
//         cout << endl;
//     }
//     return 0;
// }


//5.
// #include <iostream>
// using namespace std;
// int main(){
//     int n,m;
//     int sum=0;
//     cout<<"enter the value of row and column :";
//     cin>>n>>m;
//     int arr[n][m];
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>arr[i][j];   
//         }
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             sum= sum + arr[i][j];
//         }
//         cout<<"sum of row "<<i+1<<" is :"<<sum<<endl;
//         sum=0;
//     }
//     for(int j=0;j<m;j++){
//         for(int i=0;i<n;i++){
//             sum= sum + arr[i][j];
//         }
//         cout<<"sum of column "<<j+1<<" is :"<<sum<<endl;
//         sum=0;
//     }
//     return 0;
// }
