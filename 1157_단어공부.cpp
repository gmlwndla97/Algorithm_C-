#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
string ans = "";
int alpha[26] = { 0 };
char letter[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K','L', 'M', 'N', 'O', 'P', 'Q', 'R'
, 'S', 'T', 'U', 'V' ,'W' , 'X' ,'Y' , 'Z' };
int main() {
	cin >> ans;
	int max = 0;
	transform(ans.begin(), ans.end(), ans.begin(), tolower);
	for (int i = 0; i < ans.size(); i++) {
		alpha[ans.at(i) - 97]++;
		if (alpha[ans.at(i) - 97] > max)
			max = alpha[ans.at(i) - 97];
	}
	int maxcount = 0;
	int maxindex = 0;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] == max) {
			maxcount++;
			maxindex = i;
		}
	}
	if(maxcount>1) cout << "?" << endl;
	else cout << letter[maxindex] << endl;
	return 0;
}