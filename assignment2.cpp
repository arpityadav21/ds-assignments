// 1.
#include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key)
            return mid;   
        else if (arr[mid] < key)
            left = mid + 1;  
        else
            right = mid - 1; 
    }
    return -1; 
}
int main() {
    int n;
    cout<<"enter the size of array: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n;i++){
        cout<<"enter the elements of the array: ";
        cin>>arr[i];
    }
    int key;
    cout << "Enter element to search: ";
    cin >> key;
    int result = binarySearch(arr, n, key);
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found in array" << endl;
    return 0;
}



// 2.
#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;  
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (swapped=false) break;
    }
}
int main() {
    int n;
    cout<<"enter the size of array: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n;i++){
        cout<<"enter the elements of the array: ";
        cin>>arr[i];
    }
    bubbleSort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}



// 3.
#include <iostream>
using namespace std;
int findMissing(int arr[], int n) {
    int total = n * (n + 1) / 2;  
    int sum = 0;
    for (int i = 0; i < n - 1; i++)
        sum += arr[i];
    return total - sum;
}
int main() {
    int n;
    cout<<"enter the size of array: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n;i++){
        cout<<"enter the elements of the array: ";
        cin>>arr[i];
    }
    cout << "Missing Number: " << findMissing(arr, n) << endl;
    return 0;
}



// 4
//(A)
#include <iostream>
using namespace std;
int main() {
    char str1[100], str2[100];
    cout << "Enter first string: ";
    cin.getline(str1, 100);
    cout << "Enter second string: ";
    cin.getline(str2, 100);
    int i = 0;
    while (str1[i] != '\0') i++; 
    int j = 0;
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
    cout << "Concatenated string: " << str1 << endl;
    return 0;
}

//(B)
#include <iostream>
using namespace std;
int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);
    int len = 0;
    while (str[len] != '\0') len++;
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    cout << "Reversed string: " << str << endl;
    return 0;
}

// (C)
#include <iostream>
using namespace std;
bool isVowel(char c) {
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}
int main() {
    char str[100], result[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (!isVowel(str[i])) {
            result[j++] = str[i];
        }
        i++;
    }
    result[j] = '\0';
    cout << "String without vowels: " << result << endl;
    return 0;
}

// (D)
#include <iostream>
#include <cstring>
using namespace std;
int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore();
    char arr[50][100];
    for (int i = 0; i < n; i++) {
        cout << "Enter string " << i+1 << ": ";
        cin.getline(arr[i], 100);
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                char temp[100];
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
    cout << "Strings in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}

//(E)
#include <iostream>
using namespace std;
int main() {
    char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;
    if (ch >= 'A' && ch <= 'Z')
        ch = ch + 32;  
    cout << "Lowercase: " << ch << endl;
    return 0;
}



//5(A)
#include<iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;
    int diag[10]; 
    cout << "Enter all elements of matrix :";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            cin >> val;
            if (i == j) { 
                diag[i] = val;
            }
        }
    }
    cout << "Diagonal Matrix: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                cout << diag[i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}


//5(B)
#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;
    int t[30];
    int k = 0;
    cout << "Enter all elements of matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            cin >> val;
            if (i==j) {          
                t[k++] = val;
            } else if (i-j == 1) { 
                t[k++] = val;
            } else if (j-i == 1) { 
                t[k++] = val;
            }
        }
    }
    cout << "Tri-diagonal Matrix:\n";
    k = 0; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                cout << t[k++] << " ";
            } else if (i - j == 1) {
                cout << t[k++] << " ";
            } else if (j - i == 1) {
                cout << t[k++] << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    return 0;
}


//5(c)
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the size of the matrix: ";
    cin>>n;
    int upper[n];
    for (int i = 0; i < n*(n+1)/2; i++) { 
        cout << "Enter the elements :\n"; 
            cin >> upper[i];
        }
    cout << "Upper Triangular Matrix:\n";
    int k= 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j)
                cout << upper[k++] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    return 0;


//5(d)
#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;
    int sym[100]; 
    cout << "Enter all elements of matrix: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            cin >> val;
            if (i >= j) {  
                sym[i*(i+1)/2 + j] = val;
            }
        }
    }
    cout << "Symmetric Matrix: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j)
                cout << sym[i*(i+1)/2 + j] << " ";
            else
                cout << sym[j*(j+1)/2 + i] << " ";  
        }
        cout << endl;
    }
    return 0;
}



//6.
#include <iostream>
using namespace std;

struct Triplet {
    int row, col, val;
};

void printTriplet(Triplet mat[], int size) {
    cout << "Row Col Val\n";
    for (int i = 0; i < size; i++) {
        cout << mat[i].row << "   " << mat[i].col << "   " << mat[i].val << endl;
    }
}

void transpose(Triplet mat[], Triplet trans[], int size) {
    for (int i = 0; i < size; i++) {
        trans[i].row = mat[i].col;
        trans[i].col = mat[i].row;
        trans[i].val = mat[i].val;
    }
}

int add(Triplet A[], int sizeA, Triplet B[], int sizeB, Triplet C[]) {
    int i = 0, j = 0, k = 0;
    while (i < sizeA && j < sizeB) {
        if (A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col))
            C[k++] = A[i++];
        else if (B[j].row < A[i].row || (B[j].row == A[i].row && B[j].col < A[i].col))
            C[k++] = B[j++];
        else {
            C[k] = A[i];
            C[k++].val = A[i++].val + B[j++].val;
        }
    }
    while (i < sizeA) C[k++] = A[i++];
    while (j < sizeB) C[k++] = B[j++];
    return k;
}

int multiply(Triplet A[], int sizeA, Triplet B[], int sizeB, Triplet C[]) {
    int k = 0;
    for (int i = 0; i < sizeA; i++) {
        for (int j = 0; j < sizeB; j++) {
            if (A[i].col == B[j].row) {
                C[k].row = A[i].row;
                C[k].col = B[j].col;
                C[k].val = A[i].val * B[j].val;
                k++;
            }
        }
    }
    return k;
}

int main() {
    Triplet A[] = {{0, 0, 1}, {0, 2, 2}, {1, 1, 3}};
    Triplet B[] = {{0, 1, 4}, {1, 1, 5}, {2, 0, 6}};
    int sizeA = 3, sizeB = 3;

    cout << "Matrix A in Triplet form:\n";
    printTriplet(A, sizeA);
    cout << "\nMatrix B in Triplet form:\n";
    printTriplet(B, sizeB);

    Triplet T[10];
    transpose(A, T, sizeA);
    cout << "\nTranspose of A:\n";
    printTriplet(T, sizeA);

    Triplet C[20];
    int sizeC = add(A, sizeA, B, sizeB, C);
    cout << "\nAddition (A + B):\n";
    printTriplet(C, sizeC);

    Triplet M[20];
    int sizeM = multiply(A, sizeA, B, sizeB, M);
    cout << "\nMultiplication (A * B):\n";
    printTriplet(M, sizeM);

    return 0;
}



// 7.
#include <iostream>
using namespace std;
int countInversions(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j])
                count++;
        }
    }
    return count;
}
int main() {
    int n;
    cout<<"enter the size of array: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n;i++){
        cout<<"enter the elements of the array: ";
        cin>>arr[i];
    }
    cout << "Total Inversions: " << countInversions(arr, n) << endl;
    return 0;
}



// 8.
#include <iostream>
#include <algorithm>
using namespace std;
int countDistinct(int arr[], int n) {
    sort(arr, arr + n);
    int count = 1; 
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1])
            count++;
    }
    return count;
}
int main() {
    int n;
    cout<<"enter the size of array: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n;i++){
        cout<<"enter the elements of the array: ";
        cin>>arr[i];
    }
    cout << "Total distinct elements: " << countDistinct(arr, n) << endl;
    return 0;
}





    




























