#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<string>
using std::string;

void getFreq(string str, int count[]) {
	for(int i=0; str[i]!= '\0'; i++) {
		count[str[i]]++;
  }
}
char getMax(string str, int count[]) {
	int max = INT_MIN;
	char answer;
	for(int i=0; i<str.size(); i++) {
		if(max < count[str[i]]) {
			max = count[str[i]];	
			answer = str[i];
    }
  }
	return answer;
}
int main() {
	string str;
	int count[256] = {0};
	cout << "Enter string:";
	cin >> str;
	getFreq(str, count);
  cout << "The first maximum occuring element is " << getMax(str ,count) << endl;
	return 0;
}
