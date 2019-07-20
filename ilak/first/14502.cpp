// virus polution problem
#include<iostream>
#include<queue>
#include<ctime>
using namespace std;

typedef struct Point{
    int x,y;
}point;

class Map{
private:
    int r,c; //int area; //polution base area
    int pols[2*10]; //2<=pols<=10 x:0~, y:10~
    int pols_size=0;
    int *visited;
    int **map;
public:
    int getPolsSize();
    int getPols(int);
    void map_init(int,int);
    void print_status(void);
    void area_search(void);
    void bfsSearch(int,int);
    bool checkPointValid(int ,int);
};

int main(){
    int r,c;
    Map map;
    time_t start,end;
    time(&start);

    cin>>r>>c;
    map.map_init(r,c);
    map.print_status();
    //map.area_search();
    for(int i=0;i<map.getPolsSize();i++){
        r=map.getPols(i); c=map.getPols(i+10);

        map.bfsSearch(r,c);
    }

    time(&end);
    cout<<"time spended >> "<<double(end-start)<<endl;
    return 0;
}

void Map::bfsSearch(int r,int c){
    queue<point> q;
    int size;
    point tmp;
    if(this->checkPointValid(r-1,c)){
        tmp.x=r-1;tmp.y=c;q.push(tmp);}
    if(this->checkPointValid(r+1,c)){
        tmp.x=r+1;tmp.y=c;q.push(tmp);}
    if(this->checkPointValid(r,c-1)){
        tmp.x=r;tmp.y=c-1;q.push(tmp);}
    if(this->checkPointValid(r,c+1)){
        tmp.x=r;tmp.y=c+1;q.push(tmp);}

    size = q.size();
    cout<<"Queue >>";
    for(int i=0;i<size;i++){
        cout<<"("<<q.front().x<<","<<q.front().y<<"),";
        q.pop();
    }
    cout<<endl;


}

void Map::area_search(void){
    int r,c,i;
    for(i=0;i<pols_size;i++){
        r=pols[i];c=pols[10+i];
        if( r>0 && map[r-1][c]==0 )
            cout<<"r:"<<r-1<<",c:"<<c<<endl;
        if( c>0 && map[r][c-1]==0 )
            cout<<"r:"<<r<<",c:"<<c-1<<endl;
        if( r+1<this->r && map[r+1][c]==0 )
            cout<<"r:"<<r+1<<",c:"<<c<<endl;
        if( c+1<this->c && map[r][c+1]==0 )
            cout<<"r:"<<r<<",c:"<<c+1<<endl;
    }
}

void Map::map_init(int r,int c){
    int **map = new int *[r];
    int i,j,buf;
    int x[10], y[10], area_size;

    visited = new int [r*c];
    for(i=0;i<r*c;i++)
        visited[i] = 0;

    for(i=0;i<r;i++){
        map[i]=new int[c];
        for(j=0;j<c;j++){
            cin >> buf;
            map[i][j]=buf;
            if(buf==2){
                pols[pols_size] = i; //x
                pols[10+pols_size++] = j; //y
            }
        }
    }
    area_size=pols_size;
    for(i=0;i<pols_size-1;i++){
        for(j=i+1;j<pols_size;j++){
            if( (pols[i]+1<r    && pols[i]+1==pols[j] && pols[i+10]  ==pols[j+10]) ||
                (pols[i]>0      && pols[i]-1==pols[j] && pols[i+10]  ==pols[j+10]) ||
                (pols[i+10]+1<r && pols[i]  ==pols[j] && pols[i+10]+1==pols[j+10]) ||
                (pols[i+10]>0   && pols[i]  ==pols[j] && pols[i+10]-1==pols[j+10])){
                area_size--; 
                //cout<<pols[i]<<","<<pols[i+10]<<endl;cout<<pols[j]<<","<<pols[j+10]<<endl;
            }

        }
    }

    this->r=r;this->c=c;
    this->map = map;
    //this->area = area_size;
}

void Map::print_status(void){
    int i,j;

    cout<<"-----------debug print---------\n";
    cout<<"| >> r:"<<r<<",c:"<<c<<"\n";
    //cout<<"| >> area_size:"<<area<<"\n";
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cout << map[i][j] <<" ";
        }
        cout<<"\n";
    }
    cout<<"-------------------------------\n";
}

bool Map::checkPointValid(int r,int c){
    if(r>=0 && r<this->r && c>=0 && c<this->c && map[r][c]==0 && visited[r*this->r+c]==0){
        visited[r*this->r+c]=1;//cout<<"["<<r<<","<<c<<"]"<<endl;
        return true;
    }
    return false;
}

int Map::getPolsSize(){
    return pols_size;
}
int Map::getPols(int x){
    return pols[x];
}

