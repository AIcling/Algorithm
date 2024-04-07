#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<vector<int> > qua_matrix(8,vector<int>(8,0));
vector<vector<double> > photo(8,vector<double>(8,0));
vector<vector<int> > M(8,vector<int>(8,0));
const double PI = acos(-1)/8;
int cal_Mux(vector<vector<double> >& matrix,int i,int j);
int main(void){
    int num;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin >> qua_matrix[i][j];
        }
    }
    cin >> num;
    int T;
    cin >> T;
    for(int i=0;i<num;i++){
    switch (i)
    {
    case 0:
        cin >> photo[0][0];
        break;
    case 1:
        cin >> photo[0][1];
        break;
    case 2:
        cin >> photo[1][0];
        break;
    case 3:
        cin >> photo[2][0];
        break;
    case 4:
        cin >> photo[1][1];
        break;
    case 5:
        cin >> photo[0][2];
        break;
    case 6:
        cin >> photo[0][3];
        break;
    case 7:
        cin >> photo[1][2];
        break;
    case 8:
        cin >> photo[2][1];
        break;
    case 9:
        cin >> photo[3][0];
        break;
    case 10:
        cin >> photo[4][0];
        break;
    case 11:
        cin >> photo[3][1];
        break;
    case 12:
        cin >> photo[2][2];
        break;
    case 13:
        cin >> photo[1][3];
        break;
    case 14:
        cin >> photo[0][4];
        break;
    case 15:
        cin >> photo[0][5];
        break;
    case 16:
        cin >> photo[1][4];
        break;
    case 17:
        cin >> photo[2][3];
        break;
    case 18:
        cin >> photo[3][2];
        break;
    case 19:
        cin >> photo[4][1];
        break;
    case 20:
        cin >> photo[5][0];
        break;
    case 21:
        cin >> photo[6][0];
        break;
    case 22:
        cin >> photo[5][1];
        break;
    case 23:
        cin >> photo[4][2];
        break;
    case 24:
        cin >> photo[3][3];
        break;
    case 25:
        cin >> photo[2][4];
        break;
    case 26:
        cin >> photo[1][5];
        break;
    case 27:
        cin >> photo[0][6];
        break;
    case 28:
        cin >> photo[0][7];
        break;
    case 29:
        cin >> photo[1][6];
        break;
    case 30:
        cin >> photo[2][5];
        break;
    case 31:
        cin >> photo[3][4];
        break;
    case 32:
        cin >> photo[4][3];
        break;
    case 33:
        cin >> photo[5][2];
        break;
    case 34:
        cin >> photo[6][1];
        break;
    case 35:
        cin >> photo[7][0];
        break;
    case 36:
        cin >> photo[7][1];
        break;
    case 37:
        cin >> photo[6][2];
        break;
    case 38:
        cin >> photo[5][3];
        break;
    case 39:
        cin >> photo[4][4];
        break;
    case 40:
        cin >> photo[3][5];
        break;
    case 41:
        cin >> photo[2][6];
        break;
    case 42:
        cin >> photo[1][7];
        break;
    case 43:
        cin >> photo[2][7];
        break;
    case 44:
        cin >> photo[3][6];
        break;
    case 45:
        cin >> photo[4][5];
        break;
    case 46:
        cin >> photo[5][4];
        break;
    case 47:
        cin >> photo[6][3];
        break;
    case 48:
        cin >> photo[7][2];
        break;
    case 49:
        cin >> photo[7][3];
        break;
    case 50:
        cin >> photo[6][4];
        break;
    case 51:
        cin >> photo[5][5];
        break;
    case 52:
        cin >> photo[4][6];
        break;
    case 53:
        cin >> photo[3][7];
        break;
    case 54:
        cin >> photo[4][7];
        break;
    case 55:
        cin >> photo[5][6];
        break;
    case 56:
        cin >> photo[6][5];
        break;
    case 57:
        cin >> photo[7][4];
        break;
    case 58:
        cin >> photo[7][5];
        break;
    case 59:
        cin >> photo[6][6];
        break;
    case 60:
        cin >> photo[5][7];
        break;
    case 61:
        cin >> photo[6][7];
        break;
    case 62:
        cin >> photo[7][6];
        break;
    case 63:
        cin >> photo[7][7];
        break;
    default:
        break;
    }    
    }
    if(T==0){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(j==7) printf("%d\n",(int)photo[i][j]);
                else printf("%d ",(int)photo[i][j]);
            }
        }
    }
    if(T==1){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                photo[i][j] = photo[i][j] *qua_matrix[i][j];
                if(j==7) printf("%d\n",(int)photo[i][j]);
                else printf("%d ",(int)photo[i][j]);
            }
        }  
    }
    if(T==2){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                photo[i][j] = photo[i][j] *qua_matrix[i][j];
            }
        }  
    // 
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                M[i][j] = cal_Mux(photo,i,j);
                if(j==7) printf("%d\n",M[i][j]);
                else printf("%d ",M[i][j]);
            }
        }
    }
    return 0;
}
int cal_Mux(vector<vector<double> >& matrix,int i,int j){
    double res=0,alpha_u,alpha_v;
    for(int u=0;u<8;u++){
        for(int v=0;v<8;v++){
            if(v==0&&u==0) {alpha_v=sqrt(2)/2;alpha_u=sqrt(2)/2;}
            else if(v!=0&&u==0) {alpha_v=1;alpha_u=sqrt(2)/2;}
            else if(v==0&&u!=0) {alpha_v=sqrt(2)/2;alpha_u=1;}
            else  {alpha_v=1;alpha_u=1;}
            double temp = alpha_u*alpha_v*matrix[u][v]*cos(PI*(i+0.5)*u)*cos(PI*(j+0.5)*v);
            res += temp;
        }
    }
    res = res/4 + 128;
    res = (int)round(res);
    if(res>255) res=255;
    if(res<0) res =0;
    return res;
}
