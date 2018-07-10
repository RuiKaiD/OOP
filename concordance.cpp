#include "std_lib_facilities.h"

int main(){
	cout<< "Enter word we will store in a vector:\n";
	vector <string> text;
	for (string word; cin >> word;)
		text.push_back(word);

	sort(text);

	cout<<'\n';

	for (string x:text)
		cout << x << '\n';

	string temp;
	int num;
	temp = text[0];
	num = 1;
	//vector <string> result;
	//vector <int> resultn;

	for (int i=1; i < text.size(); i++){
		if (text[i] == temp){
			num++;
		}
		if (text[i] != temp){
			//result.push_back(temp);
			//resultn.push_back(num);
			cout<< "The word " << temp <<  " occurence:  " << num << " times"<<"\n";
			temp = text[i];
			num = 1;

		}

	}
	cout <<"The word " << temp <<  " occurence:  " << num << " times"<<"\n";














}