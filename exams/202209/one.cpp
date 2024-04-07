#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main(void){
	int n,m;
	cin >> n >> m;
	vector<pair<int,int> > change(n+1);
	for(int i=1;i<=n;i++){
		int dx,dy;
		cin >> dx >> dy;
		pair<int,int> temp = make_pair(dx,dy);
		change[i] = temp;
	}
	while(m--){
		int x,y;
		cin >> x >> y;
		for(int i=1;i<=n;i++){
			x+=change[i].first;
			y+=change[i].second;
		}
		cout << x <<" "<< y <<endl;
	}
	return 0;
}
