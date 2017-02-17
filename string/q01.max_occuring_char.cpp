#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include<string>
using std::string;
#include<unordered_map>
using std::unordered_map;
#include<climits>
typedef unordered_map<char, int> Map;
typedef Map::iterator iter;
/* unordered map is implementation of hash table which takes O(1) for searching on average */
void fillMap(string str, Map &myMap) {
	for(int i=0; str[i] != '\0'; i++) {
		iter it = myMap.find(str[i]);
		if(it == myMap.end())	{
			myMap.insert(Map::value_type(str[i], 1));
    }
		else {
			it->second++;
    }
  }
}
char getMaxChar(Map myMap) {
	int max = INT_MIN;
	char answer;
	for(iter it = myMap.begin(); it != myMap.end(); it++) {
		if(max < it->second) {
			max  = it->second;
			answer = it->first;
    }
  }
	return answer;
}
int main() {
	string str;
	Map myMap;
	cout << "Enter string:";
	cin >> str;
	getchar();
	fillMap(str, myMap);
	cout << "The first maximum occuring character is: " << getMaxChar(myMap) << endl;		
	return 0;
}
/*
	 Time Complexity - O(n) if we consider that look up in hash table takes O(1) on average, look up on hash table is much faster than tree
   Time Complexity  - O(n^2) if we consider that look up takes O(n) which is the worst case
	 
	 If we solve this problem by map which is the implementation of the RBT which takes O(Logn) time to search n element
	 So, in that time cmpleixty will be O(nLogn)
*/
