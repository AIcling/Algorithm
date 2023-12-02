#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct Student{
    char id[13];
    int score;
    int loc_index;
    int rank;
    int local_rank;
} stu[300];
bool cmp(Student a,Student b){
    if(a.score!=b.score) return a.score>b.score;
    else return strcmp(a.id,b.id) < 0;
}
int main(void){
    int N = 0;
    int locations[100];
    scanf("%d",&N);
    int k=0,num=0;
    for(int i=1;i<=N;i++){
        scanf("%d",&k);
        for(int j=0;j<k;j++) {
            scanf("%s %d",stu[num].id,&stu[num].score);
            stu[num].loc_index = i;
            num++;
        }
        sort(stu+num-k,stu+num,cmp);
        stu[num-k].local_rank = 1;
        for(int j=num-k+1;j<num;j++){
            if(stu[j].score!=stu[j-1].score) stu[j].local_rank = 1+j-(num-k);
            else stu[j].local_rank = stu[j-1].local_rank;
        }
    }
        sort(stu,stu+num,cmp);
        stu[0].rank = 1;
        for(int r=1;r<=num;r++){
            if(stu[r].score!=stu[r-1].score) stu[r].rank = r+1;
            else stu[r].rank = stu[r-1].rank;
        }
        printf("%d\n",num);
        for(int a=0;a<num;a++){
            printf("%s %d %d %d\n",stu[a].id,stu[a].rank,stu[a].loc_index,stu[a].local_rank);
        }
}