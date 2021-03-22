/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
void merge(int a[], int si, int mid, int ei);
void mergeSort(int a[], int n);
void helper(int a[], int si, int ei);

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
void merge(int a[], int si, int mid, int ei){
    int copy[ei-si+1];
    int i=si, j=mid+1, k=0;
    while(i<=mid && j<=ei){
        if(a[i]<a[j]){
            copy[k]=a[i];
            k++;
            i++;
        }else{
            copy[k]=a[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
        copy[k]=a[i];
        k++;
        i++;
    }
    while(j<=ei){
        copy[k]=a[j];
        k++;
        j++;
    }
    for(int i=si, k=0; k<(ei-si+1); k++){
        a[i]=copy[k];
        i++;
    }
}
void helper(int a[], int si, int ei){
    if(si>=ei) return;
    int mid=(si+ei)/2;
    helper(a,si,mid);
    helper(a,mid+1,ei);
    merge(a,si,mid,ei);
}

void mergeSort(int a[], int n){
    // Write your code here
    if(n==0 || n==1) return;
    int si=0;
    int ei=n-1;
    helper(a,si,ei);
}
