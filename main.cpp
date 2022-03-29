#include<iostream>
#include<time.h>

void FillArray(int*, int);
int Partition(int*, int, int);
void QuickSort(int*, int, int);
void PrintList(int*);

#define MAX_ARRAY_LEN 10

using namespace std;
int main(){
    int list[MAX_ARRAY_LEN];
    int max_list_num = 9;
    FillArray(list, max_list_num);
    PrintList(list);
    QuickSort(list, 0,  MAX_ARRAY_LEN);
    PrintList(list);
    return 0;
}

void FillArray(int* list, int max_list_num){
    srand(time(0));
    for(int i = 0; i < MAX_ARRAY_LEN; i++){
        list[i] = rand() % max_list_num + 1;
    }
}

void QuickSort(int* list, int start, int end){
    if(start < end){
        int pIndex = Partition(list, start, end);
        QuickSort(list, start, pIndex - 1);
        QuickSort(list, pIndex+1, end);
    }
}

int Partition(int* list, int start, int end){
    int pivot = list[end];
    int pIndex = start;
    for(int i = start; i < end; i++){
        if(list[i] <= pivot){
            int temp = list[i];
            list[i] = list[pIndex];
            list[pIndex] = temp;
            pIndex++;
        }
    }  
    int temp = list[end];
    list[end] = list[pIndex];
    list[pIndex] = temp;
    
    return pIndex;
}


void PrintList(int* list){
    cout << "The list contains:" << endl;
    for(int i = 0; i < MAX_ARRAY_LEN; i++){
        cout << " " << list[i] << " |";
    }
    cout << endl;
}