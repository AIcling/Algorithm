#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

int main(void){
	int n,m;
	cin >> n >> m;
	vector<pair<int,double> > change(n+1);
	vector<double>  ksum(n+1,1);
	vector<double>  thetasum(n+1,0);
	for(int i=1;i<=n;i++){
		int dx;
		double dy;
		cin >> dx >> dy;
		change[i] = make_pair(dx,dy);
		if(dx==1){
		   thetasum[i] = thetasum[i-1];
		   ksum[i] = ksum[i-1]*dy;
		}else{
            ksum[i] = ksum[i-1];
            thetasum[i] = thetasum[i-1]+dy;
        }
	}
	while(m--){
		int i,j; 
		double x,y;
		cin >> i >> j >> x >> y;
		x = x*ksum[j]/ksum[i-1];
		y = y*ksum[j]/ksum[i-1];
		double tempx=x,tempy=y,theta=thetasum[j]-thetasum[i-1];		
		x= tempx*cos(theta)-tempy*sin(theta);
		y= tempx*sin(theta)+tempy*cos(theta);
		printf("%.3f %.3f\n",x,y);
	} 
	return 0;
}
