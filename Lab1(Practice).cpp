#include<iostream>
using namespace std;
//void sum(int c,int d){
//	cout<<c+d;	
//}
//int main(){
////	int a;   // variable initialize and declare
////	int b;
////	//cout<<"UET COMPUTER ENGINEERING DEPARTMENT"<<endl;
////	//cout<<"UET COMPUTER ENGINEERING DEPARTMENT";
////	cout <<"Enter the value of a:";
////	cin>>a;
//	
////for loop:
////	
////	for (int i=1;i<=a;i++) {
////		cout<<"PAKISTAN ZINDABAD"<<endl;
////	}
////	cout <<"Enter the value of b:";
////	cin>>b;
//
////if-else statement:
//
////	if (a>b){
////		cout<<a<<"is greater than "<<b;
////	}
////	else{
////	    cout<<b<<"is greater than "<<a;	
////	}
//	//cout<<"Sum of "<<a<<" and "<<b<<" is " <<a+b<<endl;
////Array:
//	
////	int arr[7]={3,8,9,6,7,0}  //initialize array
////    int arr[7];
////    for (int i=0;i<=6;i++){
////    	cin>>arr[i];
////	}
////	for (int i=0;i<=6;i++){
////    	cout<<arr[i]<<endl;
////	}
//sum(8,9);
//	return 0;
//}
int main ()
{
//   int i, j,n;
//   int a[7] = {1,9,3,8,5,6,7};
//   cout <<"Input list is:\n ";
//   for(i = 0; i<7; i++) {
//      cout <<a[i]<<"\n";
//   }
//cout<<endl;
//for(i = 0; i<7; i++) {
//   for(j = i+1; j<7; j++)
//   {
//      if(a[j] < a[i]) {
//         n = a[i];
//         a[i] = a[j];
//         a[j] = n;
//      }
//   }
//}
//cout <<"Sorted List is:\n";
//for(i = 0; i<7; i++) {
//   cout <<a[i]<<"\n";
//}
int size;
int n =0;
cout<<"Enter size of array: ";
cin>>size;
int array[size];
for(int i=0;i<=size;i++)
{ cin>>array[i];
	for(int j=0;j<i;j++)
	{
	   if(array[i]>array[j])
	   {
	   	 int x= array[j];
	   	 int z = array[i];
	   	 array[j]=z;
	   	 array[i]=x;
		   }	
	}
	for(int k=0;k<=i;k++){
	int n =array[k];
   cout<<"Sorted array is :"<<n<<endl;	
}

}
return 0;
	
}


