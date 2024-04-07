#include <iostream>
using namespace std;

int main(void){
    long n,a,b;
    long long area =0;
    cin >> n >> a >> b;
    while(n--){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1>=0 && y1>=0 && x2<=a && y2 <= b){
            area += (x2-x1)*(y2-y1);
        }else if(x2<=0 || y2<=0 || x1>=a || y1>=b){
            area = area;
        }else if(x1>=0&&x1<a&&x2>=a){
            if(y1<=0&&y2<=b) area += (a-x1)*y2;
            else if(y1<0&&y2>=b) area += (a-x1)*b;
            else if(y1>0&&y2<b) area += (a-x1)*(y2-y1);
            else area += (a-x1)*(b-y1);
        }else if(x2>0&&x2<=a&&x1<=0){
            if(y1<=0&&y2<=b) area += x2*y2;
            else if(y1<0&&y2>=b) area += x2*b;
            else if(y1>0&&y2<b) area += x2*(y2-y1);
            else area += x2*(b-y1);
        }else if(x1>=0&&x2<=a){
            if(y1<=0&&y2<=b) area += (x2-x1)*y2;
            else if(y1<0&&y2>=b) area += (x2-x1)*b;
            else  area += (x2-x1)*(b-y1);
        }else if(x1<0&&x2>a){
            if(y1<=0&&y2<=b) area += a*y2;
            else if(y1<0&&y2>=b) area += a*b;
            else if(y1>0&&y2<b) area += a*(y2-y1);
            else area += a*(b-y1);
        }
    }
    cout << area << endl;
    return 0;
}