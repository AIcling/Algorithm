#include <iostream>
#include <string>
#include <cmath>
using namespace std;
long long hexToint (string hex){
    return stoi(hex, nullptr, 16);
}
int main(void){
    long long n,nline;
    cin >> n;
    cin.ignore();
    string data;
    data.reserve(n*2);
    if(n%8!=0)  nline = n/8 +1;
    else  nline=n/8;
    while(nline--){
     string line;
     getline(cin,line);
     data += line;
    }
    //init finish
    //find the num of data
    long long Ck[4]={0};
    long long k=0;
    while(1){
        string hexstr = data.substr(0,2);
        data.erase(0,2);
        long long tempc = hexToint(hexstr);
        if(tempc>=128) {Ck[k++]=tempc-128;}
        else {Ck[k]=tempc;break;}
    }
    long long data_num = 0;
    for(long long i=0;i<=k;i++){
        data_num += Ck[i] * pow(128,i);
    }
    //finish
    string output;
    output.reserve(data_num*2);
    while(output.length()!=data_num*2){
        string hexstr = data.substr(0,2);
        data.erase(0,2);
        long long temp = hexToint(hexstr);
        if(temp%4==0){//
            long long sublength = temp/4;
            if(sublength<60){
                sublength++;
                string outstring = data.substr(0,sublength*2);
                output.append(outstring);
                data.erase(0,sublength*2);
            }else{
                long long readnum=0;
                long long readbyte = sublength-59;
                for(long long i=0;i<readbyte ;i++){
                    string hexstr = data.substr(0,2);  
                    data.erase(0,2);
                    long long temp = hexToint(hexstr);
                    readnum += temp*pow(16,2*(readbyte-i-1));
                }
                readnum++;
                string outstring = data.substr(0,readnum*2);
                output.append(outstring);
                data.erase(0,readnum*2);               
            }
        }else if(temp%4==1){
            temp = (temp-1)/4;
            long long l = temp%8 + 4;
            long long h_o = temp/8;
            string hexstr = data.substr(0,2); 
            data.erase(0,2);
            long long l_o = hexToint(hexstr);
            long long o = l_o + h_o*256;
            long long p = output.length()/2;
            if(o>=l){
                long long shift = p-o;
                string outstring = output.substr(shift*2,l*2);
                output.append(outstring);
            }else{
                long long shift = p-o;
                string outstr = output.substr(shift*2,o*2);
                long long outnum = l/o;
                long long resnum = l%o;
                string resstr = output.substr(shift*2,resnum*2);
                while(outnum--){
                    output.append(outstr);
                }
                output.append(resstr);
            }
        }else if(temp%4==2){
            long long l = temp/4+1;
            string hexstr = data.substr(0,2); 
            data.erase(0,2);
            long long o = hexToint(hexstr);
            hexstr = data.substr(0,2); 
            data.erase(0,2);
            o += hexToint(hexstr)*pow(16,2);
            long long p = output.length()/2;
            if(o>=l){
                long long shift = p-o;
                string outstring = output.substr(shift*2,l*2);
                output.append(outstring);
            }else{
                long long shift = p-o;
                string outstr = output.substr(shift*2,o*2);
                long long outnum = l/o;
                long long resnum = l%o;
                string resstr = output.substr(shift*2,resnum*2);
                while(outnum--){
                    output.append(outstr);
                }
                output.append(resstr);
            }                       
        }       
    }
    long long outline = (data_num+7)/8;
    long long rest = data_num%8;
    while(outline--){
        if(outline>0){
            string outstr = output.substr(0,16);
            output.erase(0,16);
            cout << outstr << endl;
        }else{
            string outstr;
            if(rest!=0){ outstr = output.substr(0,rest*2);}
            else{outstr = output.substr(0,16);}
            cout << outstr << endl;
        }
    }
    return 0;
}
