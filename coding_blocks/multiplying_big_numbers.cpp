//4x^3 + 5x^2 - 6x + 14
#include<bits/stdc++.h>
#include<string>
using namespace std;

bool is_smaller(string a, string b);
string subtraction(string a, string b);
string addition(string a, string b);
string multiply(string a, string b);

bool is_smaller(string a, string b){
	if(a[0]=='-'){
		a.erase(a.begin());
	}
	if(b[0]=='-'){
		b.erase(b.begin());
	}
	if(a.size()>b.size()){
		return false;
	}
	else if(a.size()<b.size()){
		return true;
	}
	else{
		int i=0;
		while(a[i]==b[i]){
			i++;
		}
		
		if(a[i]<b[i]){
			return true;
		}
		else{
			return false;
		}
	}
}

string subtraction(string a, string b){
	if(a[0]!='-' && b[0]=='-'){
		b.erase(b.begin());
		return addition(a,b);
	}
	if(a[0]=='-' && b[0]!='-'){
		a.erase(a.begin());
		return "-"+addition(a,b);
	}
	if(a[0]=='-' && b[0]=='-'){
		a.erase(a.begin());
		b.erase(b.begin());
		return subtraction(b,a);
	}
	if(is_smaller(a,b)){
		return "-"+subtraction(b,a);
	}
	int len_a = a.size();
	int len_b = b.size();
	int ind_a = len_a-1;
	int ind_b = len_b-1;
	std::vector<int> answer(max(len_a,len_b),0);
	int ind_c = answer.size()-1;
	while(ind_a>=0 && ind_b>=0){
		int val_a = a[ind_a]-'0';
		int val_b = b[ind_b]-'0';
		if(val_a==-1){
			val_a = 9;
			a[ind_a-1]--;
		}
		if(val_a<val_b){
			val_a += 10;
			a[ind_a-1]--;
		}
		answer[ind_c] = val_a - val_b;
		ind_a--;
		ind_c--;
		ind_b--;
	}
	
	while(ind_a>=0){
		int val = a[ind_a]-'0';
		if(val==-1){
			val = 9;
			a[ind_a-1]--;
		}
		answer[ind_c] = val;
		ind_c--;
		ind_a--;
	}
	int i;
	for (i = 0; answer[i]==0; i++)
	{
	}
	ostringstream oss("");
	for (i=0; i <=answer.size()-1; i++)
	{
		oss<<answer[i];
	}
	return oss.str();
}

string addition(string a, string b){
	if(a[0]=='-' && b[0]=='-'){
		a.erase(a.begin());
		b.erase(b.begin());
		return "-"+addition(a,b);
	}
	else if(a[0]!='-' && b[0]=='-'){
		b.erase(b.begin());
		return subtraction(a,b);
	}
	else if(a[0]=='-' && b[0]!='-'){
		a.erase(a.begin());
		return subtraction(b,a);
	}
	int len_a = a.size();
	int len_b = b.size();
	int ind_a = len_a-1;
	int ind_b = len_b-1;
	std::vector<int> answer(len_a+len_b,0);
	int ind_c = answer.size()-1;
	int my_ans_index = ind_c;
	int val;
	int carry = 0;
	while(ind_a>=0 && ind_b>=0){
		val = (answer[ind_c]) + (b[ind_b]-'0')+(a[ind_a]-'0') + carry;
		answer[ind_c] = val%10;
		carry = val/10;
		ind_a--;
		ind_c--;
		ind_b--;
	}
	while(ind_a>=0){
		val = (answer[ind_c]) + (a[ind_a]-'0') + carry;
		answer[ind_c] = val%10;
		carry = val/10;
		ind_c--;
		ind_a--;
	}
	while(ind_b>=0){
		val = (answer[ind_c]) + (b[ind_b]-'0') + carry;
		answer[ind_c] = val%10;
		carry = val/10;
		ind_c--;
		ind_b--;
	}
	int i;
	for (i = 0; answer[i]==0; i++)
	{
	}
	ostringstream oss("");
	for (; i <=answer.size()-1; i++)
	{
		oss<<answer[i];
	}
	return oss.str();
}



string multiply(string a, string b){
	string sign = "";
	if((a[0]=='-')^(b[0]=='-')){
		sign = '-';
	}
	if(a[0]=='-'){
		a.erase(a.begin());
	}
	if(b[0]=='-'){
		b.erase(b.begin());
	}
	int len_a = a.size();
	int len_b = b.size();
	int ind_a = len_a-1;
	int ind_b = len_b-1;
	std::vector<int> answer(len_a+len_b,0);
	int ind_c = answer.size()-1;
	int my_ans_index = ind_c;
	int val;
	int carry = 0;
	while(ind_b>=0){
		carry = 0;
		ind_c = my_ans_index;
		ind_a = len_a-1;
		while(ind_a>=0){
			val = (answer[ind_c]) + (b[ind_b]-'0')*(a[ind_a]-'0') + carry;
			answer[ind_c] = val%10;
			carry = val/10;
			ind_a--;
			ind_c--;
		}
		if(carry>0){
			answer[ind_c] += carry;
		}
		my_ans_index--;
		ind_b--;
	}
	int i=0;
	while(answer[i]==0){
		i++;
	}
	ostringstream oss("");
	for (; i <=answer.size()-1; i++)
	{
		oss<<answer[i];
	}
	return sign+oss.str();
}

int main(){
	// 4x^3 + 5x^2 - 6x + 14
	string input = "";
	char ch;
	ch = cin.get();
	while(ch!='\n'){
		input += ch;
		ch = cin.get();
	}
	string square = multiply(input,input);
	string cube = multiply(square,input);
	string first = multiply("4",cube);
	string second = multiply("5",square);
	string third = multiply("-6",input);
	string ans = addition(addition(addition(first, second),third),"14");
	cout<<ans<<endl;	
	return 0;
}