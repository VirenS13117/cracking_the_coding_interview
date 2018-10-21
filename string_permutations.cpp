#include<bits/stdc++.h>
using namespace std;

int counter = 0;
void permutations(string input_string, string current_string){
	if(current_string.size()==input_string.size()){
		cout<<counter++<<" "<<current_string<<"\n";		
		return;
	}
	int current_string_length = current_string.size();
	string adding_character = input_string.substr(current_string_length, 1);
	permutations(input_string,adding_character+current_string);
	for(int i=1;i<current_string_length;i++){
		string new_current_string = adding_character;
		new_current_string += current_string.substr(i,current_string_length-i);		
		new_current_string = current_string.substr(0,i) + new_current_string;				
		permutations(input_string,new_current_string);
	}
	permutations(input_string,current_string+adding_character);
}

void print_permutations(string input_string){
	if(input_string.size()<=1){
		cout<<counter++<<" "<<input_string<<"\n";
		return;
	}
	permutations(input_string,input_string.substr(0,1));
}
int main(){
	string input_string;
	cin>>input_string;//Enter the string
	print_permutations(input_string);
	return 0;
}
