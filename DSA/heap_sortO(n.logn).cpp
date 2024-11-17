# include <iostream>
using namespace std;

void swap(int &a,int &b){
    int t;
    t=a;
    a=b;
    b=t;
}
void heapify(int src[],int dest[],int len){
    for(int i=0;i<len;i++){
        dest[i]=src[i];
    }
      for (int i = 1; i <len; i++) {
        int current = i;
        while (current > 0 && dest[(current - 1) / 2] > dest[current]) {
            swap(dest[(current - 1) / 2], dest[current]);
            current = (current - 1) / 2;
        }
    }
}
void display(int ar[],int len){
    cout<<"Heap is : ";
    for(int j=0;j<len;j++){
        cout<<ar[j]<<"  ";
    }
}

int main(){
    int len;
    cout<<"Enter the length of heap : ";
    cin>>len;
    int arr[len];
    for(int  i=0;i<len;i++){
        cin>>arr[i];
    }
    int heap[len];
    heapify(arr,heap,len);
    display(heap,len);
    return 0;
}