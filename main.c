#include <stdio.h>
#include <stdbool.h> //boolean
#define infinity 9999

int n;
int table [100][100];

int dijikstra(int mulai,int akhir){
	int dist[n];
	bool visited[n];
	int i,j,v;
	
	//inisialisasi awal bahwa awalnya infity 
	for(i = 1;i<=n;i++){
		dist[i] = infinity;
		visited[i] = false;
		
	}
	dist[mulai] = 0;
	while(true){ //pengulangan yang diakhiri dengan break
		int u = -1;
		int minDist = infinity;
		//mencari node yang blm dikunjungi dan memiliki distance terkecil
		for(i = 1;i<=n;i++){
			if(visited[i] == false && dist[i] < minDist){
				u = i;
				minDist = dist[i];
			}
		}
		//mengkahiri while;
		if(u == -1 || dist[u] == infinity){
			break;
		}
		visited[u] = true; //Sudah divisited
		for(v = 1;v<=n;v++){
			if(table[u][v]!=0){
				if(dist[v]>dist[u] + table[u][v]){
					dist[v] = dist[u] + table[u][v];
				}
			}
		}
	}
	return dist[akhir];
}
int main(){
	int mulai, akhir;
	int i,j;
	printf("masukan banyak node");
	scanf("%d",&n);
	printf("Masukan jarak node secara matriks \n");
	//jika jarak tidak ada isikan dengan 0
	for(i = 1;i<=n;i++){
		for(j = 1;j<=n;j++){
			scanf("%d",&table[i][j]);
		}
	}
	printf("Masukan node asal \n"); scanf("%d",&mulai);
	printf("masukan node tujuan \n"); scanf("%d",&akhir);
	printf("jarak minimal dari node awal ke node akhir adalah: %d\n",dijikstra(mulai,akhir));
	
}
