#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N,M,L,K;
struct edge{
    int to,weight;
    edge(int to, int weight) : to(to), weight(weight) {}
};