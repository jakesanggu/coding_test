// virus polution problem
#include<iostream>
#include<utility>
#include<queue>
//#include<ctime>
using namespace std;

int r,c;
pair<int,int> air = make_pair(-1,-1); //r1,r2

void simulation(int **,int **,int **,int &);
void spread(int **,int **,int **);
void air_cond(int **, int&);

int main(){
    int t,i,j,buf;
    int total_dust=0;

    int **arr1;
    int **arr2;  //for spread
    int **arr3;  //for subtract

    //time_t start,end;
    //time(&start);

    cin>>r>>c>>t;

    arr1 = new int *[r];
    arr2 = new int *[r];
    arr3 = new int *[r];

    for(i=0;i<r;i++){       //map init
        arr1[i]=new int [c];
        arr2[i]=new int [c];
        arr3[i]=new int [c];
        for(j=0;j<c;j++){
            cin>>buf;
            arr1[i][j] = buf;
            arr2[i][j] = 0; arr3[i][j] = 0;
            if(buf == -1)
                (air.first == -1) ? (air.first = i):(air.second=i);
            else
                total_dust += buf;
        }
    }

    for(i=0;i<t;i++)//given time simulation
        simulation(arr1,arr2,arr3, total_dust);
    

/*/  -----debug print start--------
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cout<<arr1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"pair:"<<air.first<<","<<air.second<<endl;
//  -----debug print end-------- */

    //time(&end);

    //cout<<"spent time >> "<<double(end-start)<<endl;
    cout<<total_dust<<endl;
    for(i=0;i<r;i++){
        delete[] arr1[i];
        delete[] arr2[i];
        delete[] arr3[i];
    }
    delete arr1;delete arr2;delete arr3;

    return 0;
}

void simulation(int **arr1,int **arr2,int **arr3,int& total_dust){
    spread(arr1,arr2,arr3);
    air_cond(arr1, total_dust);
}

void spread(int **arr1,int **arr2,int **arr3){
    int i,j;
    int sp,count;

    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            count=0;
            sp = arr1[i][j]/5;
            if(sp == 0 || arr1[i][j] == -1 ){
                arr3[i][j] = arr1[i][j]; 
                continue;}
            if( i-1 >=0 && arr1[i-1][j] != -1){
                count++;arr2[i-1][j]+=sp;}
            if( i+1 < r && arr1[i+1][j] != -1){
                count++;arr2[i+1][j]+=sp;}
            if( j-1 >=0 && arr1[i][j-1] != -1){
                count++;arr2[i][j-1]+=sp;}
            if( j+1 < c && arr1[i][j+1] != -1){
                count++;arr2[i][j+1]+=sp;}
            if( count != 0 )
                arr3[i][j] = arr1[i][j] - (sp*count);
        }
    }
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if((i==air.first && j==0) || (i==air.second && j==0))
                continue;
            arr1[i][j] = arr2[i][j] + arr3[i][j];
            arr2[i][j] = arr3[i][j] = 0;
        }
    }
}

void air_cond(int **arr1, int& dust){
    int i,j;

    //upper side
    for(i=air.first;i>0;i--){ //west
        if(i==air.first)
            dust -= arr1[i-1][0];
        else
            arr1[i][0] = arr1[i-1][0];
    }
    for(i=0;i<c-1;i++)       //north
        arr1[0][i] = arr1[0][i+1];
    
    for(i=0;i<air.first;i++) //east
        arr1[i][c-1] = arr1[i+1][c-1];

    for(i=c-1;i>0;i--){ //south
        if(i == 1){
            arr1[air.first][i] = 0;
            break;
        }
        arr1[air.first][i] = arr1[air.first][i-1];
    }

    //down side
    for(i=air.second;i<r-1;i++){ //west
        if(i==air.second)
            dust -= arr1[i+1][0];
        else
            arr1[i][0] = arr1[i+1][0];
    }
    for(i=0;i<c-1;i++) //south
        arr1[r-1][i] = arr1[r-1][i+1];
    for(i=r-1;i>air.second;i--) //east
        arr1[i][c-1] = arr1[i-1][c-1];
    for(i=c-1;i>0;i--){ //north
        if(i==1){
            arr1[air.second][i]=0;
            break;
        }
        arr1[air.second][i] = arr1[air.second][i-1];
    }

}

