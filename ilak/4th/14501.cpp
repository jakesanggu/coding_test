#include<iostream>
#include<utility>
#include<stack>
using namespace std;

typedef pair<int,int> Pair;

int dfs(int,Pair*,int*,int);

int main(){
    int i;
    int N;  //size
    Pair pairs[15]; //      T/P
    int imposs[15]={0,};//   impossible

    cin>>N;

    for(i=0;i<N;i++){ //init
        cin>>pairs[i].first>>pairs[i].second; //T , P
        if(pairs[i].first+i > N)
            imposs[i]=1;
    }
    
    cout<<dfs(N,pairs,imposs,0)<<endl;

    return 0;
}

int dfs(int N, Pair* pairs, int* imposs,int step){
    int i;
    int money=0,comp_money=0;

    for(i=step;i<N;i++){
        if(imposs[i]==1)
            continue;
        else{
            comp_money = dfs(N,pairs,imposs,i+pairs[i].first);
            if(pairs[i].second + comp_money > money)
                money = comp_money+pairs[i].second;
        }

    }

    return money;
}
