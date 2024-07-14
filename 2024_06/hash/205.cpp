/*
给定两个字符串 s 和 t ，判断它们是否是同构的。

如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。

每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。
不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。
*/

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> s2t;
        unordered_map<char,char> t2s;

        for(int i=0;i<s.size();i++){
            char x=s[i],y=t[i];
            if(s2t.find(x)!=s2t.end()&&s2t[x]!=y) return false;
            if(t2s.find(y)!=t2s.end()&&t2s[y]!=x) return false;
            s2t[x] = y;
            t2s[y] = x;
        }
        return true;
    }
};