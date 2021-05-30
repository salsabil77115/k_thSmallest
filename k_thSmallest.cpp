#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int Partition(int A[], int left,int right){
	int p = A[right];
	int i = left-1;
	for (int j = left;j<right;j++) {
		if (A[j] < p){
			i++;
    swap(A[i], A[j]);}
	swap(A[i+1], A[right]);}
	return i+1;}

int k_thSmallest(int A[], int left,int right,int k){
    if (k > 0 && k <= right - left + 1) {


        int p = Partition(A, left, right);
          if (p - left == k - 1)
            return A[k-1];

        if (p - left > k - 1)
            return k_thSmallest(A, left, p - 1, k);
        else
          return k_thSmallest(A, p + 1, right, k);
    }

}

int main()
{
    int Size;
    int k ;
    cout<<"enter size for array:";
    cin>>Size;
    int arr[Size];
    cout<<"enter your array:"<<endl;
    for(int i=0;i<Size;i++){
    cin>>arr[i];}
    cout<<"Enter order:";
    cin>>k;
    cout << "kth smallest element is "
        << k_thSmallest(arr, 0, Size- 1, k);

    return 0;
}
