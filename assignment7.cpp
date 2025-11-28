//1.
#include<iostream>
using namespace std;
void selection_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int mini=i;
        for(int j=i;j<n;j++){
                if(arr[mini]>arr[j]) mini=j;
            }
            int temp=arr[mini];
            arr[mini]=arr[i];
            arr[i]=temp;
    }
}
void bubble_sort(int arr[],int n){
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
void insertion_sort(int arr[],int n){
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j--; 
        }
    }
}
void merge(int arr[], int l, int m, int r){
    int i=l, j=m+1, k=0;
    int temp[r-l+1];

    while(i<=m && j<=r){
        if(arr[i] < arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while(i<=m) temp[k++] = arr[i++];
    while(j<=r) temp[k++] = arr[j++];

    for(int x=0; x<k; x++) arr[l+x] = temp[x];
}
void merge_sort(int arr[], int l, int r){
    if(l>=r) return;
    int m = (l+r)/2;
    merge_sort(arr, l, m);
    merge_sort(arr, m+1, r);
    merge(arr, l, m, r);
}
int partition(int arr[], int l, int r){
    int pivot = arr[r], i = l-1;
    for(int j=l; j<r; j++){
        if(arr[j] < pivot){
            i++;
            int t = arr[i]; arr[i] = arr[j]; arr[j] = t;
        }
    }
    int t = arr[i+1]; arr[i+1] = arr[r]; arr[r] = t;
    return i+1;
}
void quick_sort(int arr[], int l, int r){
    if(l < r){
        int pi = partition(arr, l, r);
        quick_sort(arr, l, pi-1);
        quick_sort(arr, pi+1, r);
    }
}

int main(){
    int n;
    cout<<"enter the size of the array : ";
    cin>>n;
    int arr[n];
    cout<<"enter the elements :";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selection_sort(arr,n);
    bubble_sort(arr,n);
    insertion_sort(arr,n);
    merge_sort(arr, 0, n-1);
    quick_sort(arr, 0, n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}



//2.
#include<iostream>
using namespace std;
void improved_selection_sort(int arr[], int n){
    int left = 0, right = n - 1;
    while(left < right){
        int mini = left;
        int maxi = right;
        if(arr[mini] > arr[maxi]){
            int temp = mini;
            mini = maxi;
            maxi = temp;
        }
        for(int i = left; i <= right; i++){
            if(arr[i] < arr[mini]) mini = i;
            if(arr[i] > arr[maxi]) maxi = i;
        }
        int temp = arr[left];
        arr[left] = arr[mini];
        arr[mini] = temp;
        if(maxi == left) maxi = mini;
        temp = arr[right];
        arr[right] = arr[maxi];
        arr[maxi] = temp;
        left++;
        right--;
    }
}
int main() {
    int n;
    cout << "enter size: ";
    cin >> n;
    int arr[n];
    cout << "enter elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];
    improved_selection_sort(arr, n);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}

