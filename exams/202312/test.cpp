#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int compare(vector<int> number1,vector<int> number2){
    int n = number1.size(),flag=1;
    for(int i=0;i<n;i++){
        if(number1[i]>=number2[i]){
            flag=0;
            break;
        }
    }
    return flag;
}
struct _ware
{
    int index;
    int sum;
    vector<int> numbers;
};
bool cmp(_ware ware1,_ware ware2){
    return ware1.sum<ware2.sum ;
}
int main(void){
    int n,m;
    cin >> n >> m;
    vector<_ware> wares;
    for(int i=0;i<n;i++){
        _ware ware;
        ware.index = i+1;
        int sum =0;
        vector<int> numbers;
        for(int j=0;j<m;j++){
            int number;
            cin >> number;
            sum += number;
            numbers.push_back(number);
        }
        ware.sum = sum;
        ware.numbers = numbers;
        wares.push_back(ware);
    }
    sort(wares.begin(),wares.end(),cmp);
    int out[n];
    for(int i=0;i<n;i++){
        int res=0;
        for(int j=i+1;j<n;j++){
            if(compare(wares[i].numbers,wares[j].numbers)){
                res = wares[j].index;
                break;
            }
        }
        int ind = wares[i].index;
        out[ind-1] = res;
    }
	for(int i=0;i<n;i++){
		cout<<out[i]<<endl;
	} 
    return 0;
}
