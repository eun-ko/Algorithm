import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Main{
 static final int INF =1000000000;
 static int N,M,X,Y;
// 정점의 개수 N, 간선의 개수 M, 출발점 X, 도착점 Y
 static int[][] adj; //인접 행렬 배열 선언
 static int[] dist;//최소 거리 비용 배열 선언
 static boolean[] visited; //방문 여부 표시할 배열 선언

 public static void main(String[] args) throws IOException{
 BufferedReader br=new BufferedReader(new
InputStreamReader(System.in));
// Scanner클래스보다 속도가 빠른 버퍼리더 이용하기
 StringTokenizer st=null;
 N=Integer.parseInt(br.readLine());
// 정점의 개수 입력받기
 M=Integer.parseInt(br.readLine());
// 간선의 개수 입력받기

 adj=new int[N+1][N+1];
 dist=new int[N+1];
 visited=new boolean[N+1];
// adj,dist,visited 배열 생성
 
 for(int i=1;i<=N;i++) {
 for(int j=1;j<=N;j++) {
 if(i!=j) adj[i][j]=INF;
// 인접행렬을 i==j인 경우를 제외하고 INF로 초기화
 }
 }

 int u,v,cost;
// 정점 u,v와 cost 변수
 while(M-- >0) {
// 간선의 개수만큼 반복문 실행
 st=new StringTokenizer(br.readLine());
// u,v,cost 입력받기
 u=Integer.parseInt(st.nextToken());
 v=Integer.parseInt(st.nextToken());
 cost=Integer.parseInt(st.nextToken());
// 토큰 단위로 나눠서 u,v,cost에 저장
 adj[u][v]=Math.min(adj[u][v], cost);
// 서로 다른 두 정점간 여러 경로 값이 주어질 경우를 대비하여 min값을
adj배열에 넣어주기
 }

 st=new StringTokenizer(br.readLine());
// 출발점과 도착점 입력받기
 X=Integer.parseInt(st.nextToken());
 Y=Integer.parseInt(st.nextToken());
// 토큰 단위로 나눠서 X,Y변수에 저장

 dijkstra(X);
// 다익스트라 함수 호출
 System.out.println(dist[Y]);
// 최종적으로 구한 최소비용을 출력한다
 }

 private static void dijkstra(int start) {
 for(int i=1;i<=N;i++) {
 dist[i]=adj[start][i];
// 시작점에서의 dist[]배열을 초기화하기
 }
 visited[start]=true;
// 시작점에 방문했다고 표시하기
 for(int i=1;i<=N-2;i++) {
 int current=getSmallIndex();
// 방문하지 않은 정점 중 가장 작은 비용의 정점을 찾는
getSmallIndex()함수 호출
 visited[current]=true;
// 그 정점에 방문했다고 표시하기
 for(int j=1;j<=N;j++) {
 if(!visited[j]) {
 dist[j]=Math.min(dist[j], dist[current]+adj[current][j]);
 }
// 방문하지 않은 정점들 중에서 연결된 정점의 최단거리를 갱신한다.
 }
 }
 }

 private static int getSmallIndex() {
 int min=INF;
 int idx=1;
 for(int i=1;i<=N;i++) {
 if(!visited[i]&&dist[i]<min) {
 min=dist[i];
 idx=i;
 }
 // 방문하지 않은 정점 중 가장 작은 비용의 정점을 찾는다
 }
 return idx;
 }
}
