#include <cstdio>   
#include <algorithm>
using namespace std;
struct moon_cake{
    float store;
    float price;
    float single;
}mooncake[10];
bool cmp(moon_cake a,moon_cake b){
    return a.single>b.single;
}
int kinds=0,demand=0;
float sell=0;
int main(void){
    scanf("%d %d",&kinds,&demand);
    for(int i=0;i<kinds;i++) scanf("%f", &mooncake[i].store);
    for(int i=0;i<kinds;i++) scanf("%f", &mooncake[i].price);
    for(int i=0;i<kinds;i++) mooncake[i].single = mooncake[i].price/mooncake[i].store;
    sort(mooncake,mooncake+kinds,cmp);
    // for(int i=0;i<kinds;i++) printf("%f\n",mooncake[i].single);
    bool flag = false;
    int i = kinds;
    for(int i=0;i<kinds;i++){
        if(mooncake[i].store<demand){
            demand -= mooncake[i].store;
            sell += mooncake[i].price;
        }else{
            sell += demand * mooncake[i].single;
            break;
        }
    }
    printf("%f\n",sell);
    return 0;
}