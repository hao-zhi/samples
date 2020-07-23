#include <vector>
#include<iostream>
using namespace std;
void merge(vector<int>& a, int left,int mid, int right, vector<int>& b){
	int i = left;
	int j = mid + 1;
	int t = 0;
	while (i <= mid && j <= right){
		if (a[i] <= a[j]){
			b[t++] = a[i++];
		}
		else{
			b[t++] = a[j++];
		}
	}
	while (i <= mid){
		b[t++] = a[i++];
	}
	while (j <= right){
		b[t++] = a[j++];
	}
	t = 0;
	while (left <= right){
		a[left++] = b[t++];
	}
}
void sort(vector<int>& a, int left, int right, vector<int>& b){
	if (left < right){
		int mid = left + (right - left) / 2;
		sort(a, left, mid, b);
		sort(a, mid + 1, right, b);
		merge(a, left, mid, right, b);
	}
}
int main(){
	vector<int> a = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	vector<int> b(9);
	sort(a,0,a.size()-1,b);
	for (int i = 0; i < 9; i++){
		cout << a[i] << endl;
	}
	system("pause");
	return 0;
}
