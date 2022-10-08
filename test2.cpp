#include<bits/stdc++.h>
using namespace std;
int dis[105][105],ru[105],f[105];
int n,ans,cnt=0;

void topological_sort(){
	while(1){
		int flag=0;
		for(int i=0;i<n;i++){
    		if(!ru[i]){  //入度为0的顶点（即没有前驱任务的任务，那么这个任务就可以做了） 
    			ru[i]--;//变为-1，也就是这个任务做完了，后面不用考虑了 
    			cnt++;
    			flag=1;
    			for(int j=0; j<n; j++){
    				if(dis[i][j]!=-1){//存在以i为前驱任务的任务 
                    	ru[j]--; // 入度减一（把i任务去掉了，则j的前驱任务少了一个） 
                    	f[j]=max(f[j],f[i]+dis[i][j]); //选择最长的工作时间 
                   		ans=max(ans,f[j]);//统计最早完工时间 
                	}	
				}
			}
		}
		if(!flag) break;  //不存在入度为0的点，跳出循环 	
	}
	if(cnt==n) cout<<ans<<endl; //全部顶点和边成功去掉 
	else cout<<"Impossible"<<endl;//存在环 
}

int main(){
	int m, p, x, y;
	cin>>n>>m;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			dis[i][j]=-1;//初始边的权都为-1，因为工作时长可能是0，所以初始dis都赋值为-1 
	while(m--){
		cin>>x>>y>>p;
		dis[x][y]=p;
		ru[y]++;//ru[y]顶点y的入度,(即题目中的y任务的前驱任务们) 
	} 
	topological_sort();    //拓扑排序
	return 0;
}