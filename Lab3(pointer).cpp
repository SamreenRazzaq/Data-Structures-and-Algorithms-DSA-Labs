#include <iostream>
using namespace std;
#include <iostream>
int value;
int main() {
  int size;
  int utilize = 0;
  int *array = new int[size];
  cout<<"Enter size of Array: "<<endl;
  cin>>size;
  cout<<endl;
  for (int i = 0; i < size; i++) {
  	if (utilize<0.7 * size){
  		cout << "Enter a value for index " << i << ": ";
  		cin>>value;
    	array[i] = value;
    	utilize++;
	  }
	  }
  if (utilize >= 0.7 * size) {
  	cout<<" You can't add more items bcz Array utilization is 70%"<<endl;
  	int newSize = size * 2;
    cout<<"New size is: "<<newSize<<endl;
    int *newArray = new int[newSize];
    for (int i = 0; i < size; i++) {
      newArray[i] = array[i];
    }
    for (int i = size-1; i < newSize; i++) {
      cout << "Enter a value for index " << i << ": ";
      cin >> newArray[i];
    }
    delete[] array;
    array = newArray;
    size = newSize;
  }
  cout<<"New Array is "<<endl;
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
return 0;
}
