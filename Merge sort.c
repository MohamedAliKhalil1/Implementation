
#include <stdio.h>

void MergeSort(int *arr , int start , int end);
void Merge(int arr[] , int start , int mid , int end);

int main(){
    int arr[5];
    arr[0] = 5;
    arr[1] = 4;
    arr[2] = 3;
    arr[3] = 5;
    arr[4] = 2;
    
    MergeSort(arr , 0 , 4);
    
    for(int i = 0; i < 5; i++)
        printf("%d " , arr[i]);
    return 0;
}

void MergeSort(int *arr , int start , int end){
    
    // base case
    if(start == end)
        return;
    
    // get the middle point of the array 
    int mid = (end + start) / 2;
    
    // divide the left hand side
    MergeSort(arr , start , mid);
    
    // divide the right hand side
    MergeSort(arr , mid + 1 , end);
    
    Merge(arr , start , mid  , end);
}

void Merge(int *arr , int start , int mid , int end){
    
    int lsize = mid - start + 1;
    int rsize = end - mid;
    int l[lsize] , r[rsize];
    
    
    for(int i = 0; i < lsize; i ++)
        l[i] = arr[start + i];
    for(int i = 0; i < rsize; i ++)
        r[i] = arr[mid + 1 + i];
        
    int rindx = 0 , lindx = 0 , arrindx = start;
    
    while(lindx < lsize && rindx < rsize){
        if(l[lindx] < r[rindx])
            arr[arrindx++] = l[lindx++];
        else
            arr[arrindx++] = r[rindx++];
    }
    
    if(lindx >= lsize){
        while(rindx < rsize)
            arr[arrindx++] = r[rindx++];
    }
    else if(rindx >= rsize){
        while(lindx < lsize)
            arr[arrindx++] = l[lindx++];
    }
}
    
 