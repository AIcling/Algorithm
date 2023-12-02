#include <cstdio>
#include <cmath>

const double PI = acos(-1.0);
const double eps = 1e-5;

double f(double R,double h){
    double sector = (acos((R-h)/R)) * R*R;
    double tri = sqrt(R*R - (R-h)*(R-h)) * (R-h);
    double S1 = sector - tri;
    double S2 = PI * R * R / 2;
    return S1/S2;
}
double solve(double R,double r){
    double left=0,right=R,mid;
    while((right-left)>eps){
        mid = (left+right)/2;
        if(f(R,mid) > r) right = mid;
        else left = mid;
    }
    return left;
}

int main(void){
    double R,r;
    scanf("%lf %lf",&R,&r);
    double h = solve(R,r);
    printf("%4lf\n",h);
}