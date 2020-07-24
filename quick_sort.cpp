#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int divide(int left, int right, vector<int>& s){
	// 以s[left]为参考将数组分为小于它的和大于它的两部分，返回s[left]的位置。
	int l = left + 1;
	int r = right;
	int temp = s[left];
	while (l <= r ){
		if (s[l] > temp && s[r] < temp){
			swap(s[l], s[r]);
			l++;
			r--;
		}
		while (l <= r && s[l] <= temp){
			// find left which value larger than povit
			l++;
		}
		while (l <= r && s[r] >= temp){
			// find right which value smaller than povit
			r--;
		}
	}
	swap(s[left], s[l-1]);
	return l-1;
}
void quik_sort(int left, int right, vector<int>& s){
	if (left < right){

		int pivot = divide(left, right, s);
		quik_sort(left, pivot - 1, s);
		quik_sort(pivot + 1, right, s);
	}
}
int main(){
	vector<int> s = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	quik_sort(0, s.size()-1, s);
	for (int i = 0; i < s.size(); i++){
		cout << s[i] << endl;
	}
	system("pause");
	return 0;
}
