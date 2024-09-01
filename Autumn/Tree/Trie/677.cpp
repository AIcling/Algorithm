/*
设计一个 map ，满足以下几点:
字符串表示键，整数表示值
返回具有前缀等于给定字符串的键的值的总和
实现一个 MapSum 类：
MapSum() 初始化 MapSum 对象
void insert(String key, int val) 插入 key-val 键值对，字符串表示键 key ，整数表示值 val 。
如果键 key 已经存在，那么原来的键值对 key-value 将被替代成新的键值对。
int sum(string prefix) 返回所有以该前缀 prefix 开头的键 key 的值的总和。
*/

#include <string>
#include <unordered_map>

class TrieNode{
public:
    TrieNode* children[26];
    int val;
    TrieNode():val(0){
        for(int i=0;i<26;i++){
            children[i] = nullptr;
        }
    }
};

class MapSum {
public:
    TrieNode* root;
    std::unordered_map<std::string,int> map;
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(std::string key, int val) {
        int new_val = 0;
        if(map.find(key)!=map.end()) {
            new_val = val - map[key];
            map[key] =val;
        }else{
            new_val = val;
            map[key] =val;
        }
        TrieNode *p = root;
        for(char c:key){
            int key = c-'a';
            if(p->children[key]==nullptr) p->children[key] = new TrieNode();
            p = p->children[key];
            p->val += new_val;
        }
    }
    
    int sum(std::string prefix) {
        TrieNode *p = root;
        for(char c:prefix){
            int id = c-'a';
            if(p->children[id]==nullptr) return 0;
            p = p->children[id];
        }
        return p->val;
    }
};