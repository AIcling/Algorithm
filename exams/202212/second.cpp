#include <iostream>
#include <vector>
using namespace std;

struct subject{
    int depend;
    int day;
    int early;
    int late;
subject() : depend(0), day(0), early(0), late(0){}
};
int main(void){
    int n,m;
    cin >> n >> m;
    vector<subject> Subjects(m+1);
    for(int i=1;i<=m;i++){
        subject sub;
        cin >> sub.depend;
        Subjects.insert(Subjects.begin()+i,sub);
    }
    for(int i=1;i<=m;i++){
        cin >> Subjects[i].day;
        Subjects[i].late = n+1-Subjects[i].day;
    }
    int flag=0;
    for(int i=1;i<=m;i++){
        if(Subjects[i].depend==0) Subjects[i].early = 1;
        else {
            int index = Subjects[i].depend;
            Subjects[i].early = Subjects[index].early+Subjects[index].day;
        }
        if(i==m)cout << Subjects[i].early << endl;
        else cout << Subjects[i].early << " ";
        int finish = Subjects[i].early+Subjects[i].day;
        if(finish>n+1) flag=1;
    }
    if(flag==0){
        for(int i=m;i>=1;i--){
           if(Subjects[i].depend!=0){
             int index = Subjects[i].depend;
             int lateday = Subjects[i].late - Subjects[index].day;
             if(lateday<Subjects[index].late) Subjects[index].late =lateday;
           }           
        }
    }
    if(flag==0){
        for(int i=1;i<=m;i++){
            if(i==m)cout << Subjects[i].late << endl;
            else cout << Subjects[i].late << " ";
        }
    }
    return 0;
}