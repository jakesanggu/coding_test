#include <iostream>
#include <utility>
#include <vector>
#include <stack>

#define MAX_ROW	10
#define MAX_COL	10
#define VIRUS	2
#define WALL	1
#define NORMAL	0

using namespace std;

typedef pair<int,int> pos;
typedef unsigned char UCHAR;
int row,col;


int main(void){

//Decl Variables
	vector <pos> normal;
	stack <pos> virus;
	stack <pos> virus_tmp;

	int area[MAX_ROW][MAX_COL];
	int area_tmp [MAX_ROW][MAX_COL];
	int ans,part_ans;


//Read Row Col info
	cout << "Row Col 입력!" ;
	scanf("%d %d", &row, &col);

	cout << "값 입력" ;
	for( int i =0; i < row; i++ )
		for (int j=0; j < col ; j++){

			scanf("%d", &area[i][j] );

			if(area[i][j] == NORMAL)
				normal.push_back({i,j});
			else if(area[i][j] == VIRUS)
				virus.push({i,j});
	}
	vector  <pos> :: iterator it;
	vector  <pos> :: iterator it2;
	vector  <pos> :: iterator it3;


// 0 인지점 3개를 뽑아서 벽을 세우고 바이러스를 전파시킨다. 그리고 0의 값이 최대가 되는 값이 답
// 전파는 상하좌우만 가능


//서로다른 0 인지점 3개를 뽑는다.

	ans = 0;

	for ( it = normal.begin(); it != normal.end() - 2 ; it++ )
		for ( it2= it + 1 ; it2 != normal.end() - 1 ; it2++)
			for(it3 = it2 + 1; it3 != normal.end(); it3++){

				part_ans = 0;
				virus_tmp = virus;

				for(int i =0; i < MAX_ROW; i++)
					for (int j =0; j < MAX_COL ;j++)
						area_tmp[i][j] = area[i][j];

				//해당 지점을 벽으로 만든다
				area_tmp[it->first][it->second]	= WALL;
				area_tmp[it2->first][it2->second] = WALL;
				area_tmp[it3->first][it3->second] = WALL;

				//바이러스를 전파한다
				bool vis[MAX_ROW][MAX_COL] = {0,};

				 while (!virus_tmp.empty()){

					int x = virus_tmp.top().second;
					int y = virus_tmp.top().first;
					virus_tmp.pop();

        				if (!vis[y][x]){

       					 	vis[y][x] = true;
        				 	area_tmp[y][x] = VIRUS;

						if( y+1 < row && area_tmp[y+1][x] == NORMAL)
							virus_tmp.push({y+1,x});
						if( 0 <= y-1 && area_tmp[y-1][x] == NORMAL)
							virus_tmp.push({y-1,x});
						if( x+1 < col && area_tmp[y][x+1] == NORMAL)
							virus_tmp.push({y,x+1});
						if( 0 <= x-1  && area_tmp[y][x-1] == NORMAL)
							virus_tmp.push({y,x-1});

    						}

					}


				//0인 부분의 합을 측정
				for(int i =0; i < row ; i++)
					for(int j =0 ; j < col ; j++){
						if( area_tmp[i][j] == NORMAL )
							part_ans ++;
				}


				if( part_ans > ans ){
					ans = part_ans;

				}
			}



cout << "정답은 " << ans << "입니다" <<endl;

return 0;
}
