# include <iostream>
# include <chrono>
using namespace std;

void swap(int &a,int &b){
    int t;
    t=a;
    a=b;
    b=t;
}
void Minheapify(int arr[], int n, int i) {
    int min = i;  
    int left = 2 * i + 1;  
    int right = 2 * i + 2; 
    if (left < n && arr[left] < arr[min])
        min = left;
    if (right < n && arr[right] < arr[min])
        min = right;
    if (min != i) {
        swap(arr[i], arr[min]); 
        Minheapify(arr, n, min); 
    }
}
void maxheapify(int arr[], int n, int i) {
    int min = i;  
    int left = 2 * i + 1;  
    int right = 2 * i + 2; 
    if (left < n && arr[left] > arr[min])
        min = left;
    if (right < n && arr[right] > arr[min])
        min = right;
    if (min != i) {
        swap(arr[i], arr[min]); 
        maxheapify(arr, n, min); 
    }
}
void MinHeap(int arr[], int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        Minheapify(arr, n, i);
    }
}
void MaxHeap(int arr[], int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        maxheapify(arr, n, i);
    }
}
void delet(int arr[],int l){
    cout<<"Deleted element is : "<<arr[0]<<endl;
    arr[0] = arr[l-1];
    l = l-1;
    MinHeap(arr,l);
}
void display(int ar[],int len){
    cout<<"Heap is : ";
    for(int j=0;j<len;j++){
        cout<<ar[j]<<"  ";
    }
    cout<<endl;
}

int main(){
    int len;
    cout<<"Enter the length of heap : ";
    cin>>len;
    int arr[len];
    for(int  i=0;i<len;i++){
        cin>>arr[i];
    }
    MinHeap(arr,len);
    display(arr,len);
    delet(arr,len);
    display(arr,len);
    return 0;
}