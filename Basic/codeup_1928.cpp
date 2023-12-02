#include <cstdio>
    int caldays(int y1, int m1,int d1,int y2,int m2,int d2);
    int month[2][13] ={
        {0,31,28,31,30,31,30,31,31,30,31,30,31},
        {0,31,29,31,30,31,30,31,31,30,31,30,31}
    };
    int main(void){
        int days = 0;
        int time1,time2,y1,y2,m1,m2,d1,d2;
        scanf("%d%d",&time1,&time2);
        y1 = time1/10000;
        y2 = time2/10000;
        d1 = time1%100;
        d2 = time2%100;
        m1 = time1%10000 / 100;
        m2 = time2%10000 / 100;
        if(time2<time1) days = caldays(y1,m1,d1,y2,m2,d2);
        else days = caldays(y2,m2,d2,y1,m1,d1);
        printf("%d\n",days);
    }

    int caldays(int y1, int m1,int d1,int y2,int m2,int d2){
        int days = 1;
        int tar_days = 0;
        
        if(y2%4 == 0) tar_days = month[1][m2];
        else tar_days = month[0][m2];
        
        if(y1==y2&&m1==m2){
        while(d2!=d1){
            d2++;
            days++;
         }
        }else if(y1==y2&&m1!=m2){
          while(m2!=m1){
            while(d2!=tar_days+1){
            d2++;
            days++;
            }
            d2 = 1;
            m2++;            
            if(y2%4 == 0) tar_days = month[1][m2];
            else tar_days = month[0][m2];            
         }
         while(d2!=d1){
            d2++;
            days++;
          }            
        }else{
            while(d2!=tar_days+1){
            d2++;
            days++;
            }
            d2=1;
            if (m2!=12) {m2++;}
            else {m2 =1; y2++;}
            while(y2!=y1){               
                while(m2!=13){
                    if(y2%4 == 0) tar_days = month[1][m2];
                    else tar_days = month[0][m2];
                    while(d2!=tar_days+1){
                        d2++;
                        days++;
                    }
                    m2++;
                    d2 = 1;
                }
                m2=1;
                y2++;
            }
            //y1=y2:
            while(m2!=m1){
                if(y2%4 == 0) tar_days = month[1][m2];
                else tar_days = month[0][m2];
                while(d2!=tar_days+1){
                    d2++;
                    days++;
                }
                m2++;
                d2 = 1;
            //m1=m2:
                 while(d2!=d1) {d2++;days++;}      
            }
        }
        return days;
    }