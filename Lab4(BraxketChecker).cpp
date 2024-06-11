#include <iostream>
using namespace std;

	int top = -1;
	char push(char p, char A[]){
		top++;
		A[top]=p;
		cout<<"ENTERED EXPRESSION..." <<endl;
	
	}
	char pop(char p, char A[]){
			if(top==-1){
			cout<<"STACK IS EMPTY... "<<endl;
			}
//		cout<<top;
		if((A[top] == '(') && (p==')') || (A[top] == '{') && (p=='}') || (A[top] == '[') && (p==']')){
		A[top] = ' ';
		top--;
		cout<<"BRACKET EXTRACTED" << endl;}
	}

int main(){
	string s;	
    
    cout<< "ENTER ANY EXPRESSION: ";
    getline(cin,s);
    cout<< "EXPRESSION IS : "<<s << endl;
    int size  = s.size();
    char A[size];
    for (int i = 0; i<=size; i++){
    	if ((s[i] == '(') || (s[i] == '{') || (s[i] == '[')){
    		push(s[i],A);
    		cout << "Array has: ";
        	for (int x = 0; x < size; x++) {
	        cout << A[x] << " ";
			}
			cout<<endl;	
	    }
		else if ((s[i]==')') || (s[i] == '}') || (s[i] == ']')){
			pop(s[i],A);
		}
		else if(top!=-1){
		cout<<"UNBALANCE"<<endl;
		}
	}	
	
return 0;
}


