#include <bits/stdc++.h>
using namespace std;

void count_sort(vector<int>& arr){
  int size = arr.size();

  int maxi = INT_MIN;

  for(int i = 0; i<size; i++){
    maxi = max(maxi, arr[i]);
  }

  vector<int> count(maxi+1, 0);

  for(auto it: arr){
    count[it]++;
  }

  int index = 0;
  for(int i = 0; i<=maxi; i++){
    while(count[i] > 0){
      arr[index++] = i;
      count[i]--;
    }
  }
}

void cocktail_sort(vector<int>& arr){
  int size = arr.size();
  int low = 0;
  int high = size-1;
  bool swapped = true;

  while(swapped){
    swapped = false;

    for(int i = low; i<high-1; i++){
      if(arr[i] > arr[i+1]){
        int temp = arr[i+1];
        arr[i+1] = arr[i];
        arr[i] = temp;
        swapped = true;
      }
    }

    if(!swapped) break;

    if(swapped) swapped = false;

    high--;

    for(int i = high; i>=low; i--){
      if(arr[i] > arr[i+1]){
        int temp = arr[i+1];
        arr[i+1] = arr[i];
        arr[i] = temp;
        swapped = true;
      }
    }

    low++;
  }
}
int main(){
  int n;
  cin >> n;

  vector<int> arr(n);

  for(int i = 0; i<n; i++){
    cin >> arr[i];
  }
  cocktail_sort(arr);

  for(int i = 0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}