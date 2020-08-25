import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
public class Q1753 {
static int stoi(String S) {
return Integer.parseInt(S);
// 문자열을 정수로 변환할 함수
}
static final int INF = 1000000000;
static int N, M, K;
// 정점의 개수, 간선의 개수, 출발정점을 담을 변수 선언
static List<List<Node>> adList;
//인접 리스트 선언
static int[] dist;
// 최소 거리 비용을 저장할 배열 선언
static boolean[] visited;
// 방문여부표시배열 선언
static PriorityQueue<Node> pq;
// 우선순위큐 선언
public static void main(String[] args) throws IOException {
 BufferedReader br = new BufferedReader(new 
InputStreamReader(System.in));
// Scanner클래스보다 속도가 빠른 버퍼리더 이용하기
 StringTokenizer st = null;
 st = new StringTokenizer(br.readLine());
 N = stoi(st.nextToken());
 M = stoi(st.nextToken());
// 정점의 개수, 간선의 개수를 입력받아 토큰 단위로 나눠서 변수에 저장
 K = stoi(br.readLine());
// 출발정점을 입력받아 변수에 저장

 adList = new ArrayList<>();
// 인접리스트 생성
 adList.add(new<Node> ArrayList());
// 인덱스를 1부터 하기 위해 임의로 한 개를 넣어둠
 for(int i=1; i<=N; i++) {
 adList.add(new<Node> ArrayList());
 }
// 인접리스트 초기화
 dist = new int[N+1];
// 최소 거리 비용 배열 생성
 Arrays.fill(dist, INF);
// dist[]를 INF로 초기화

 while(M-- > 0) {
// 간선의 개수만큼 반복해서 입력받기
 st = new StringTokenizer(br.readLine());
// u,v,cost 입력받기
 int u = stoi(st.nextToken());
 int v = stoi(st.nextToken());
 int cost = stoi(st.nextToken());
// 토큰 단위로 나눠서 u,v,cost에 저장
 adList.get(u).add(new Node(v, cost));
// 인접리스트에 추가
 }

 // 다익스트라 알고리즘 호출
 dijkstra(K);

 // 각 정점까지의 최단거리를 출력
 printAnswer();
 }

 private static void dijkstra(int start) {
 pq = new PriorityQueue<>();
// 우선순위큐 생성
 visited = new boolean[N+1];
// 방문여부 배열 생성
 dist[start] = 0;
// 출발정점의 dist값을 0으로
 pq.add(new Node(start, 0));
// 우선순위큐에 추가
 while(!pq.isEmpty()) {
// 우선순위큐가 빌때까지 반복
 Node current = pq.poll();
 if(visited[current.ID]) continue;
 visited[current.ID] = true;
// 재방문 여부 확인
 for(Node next : adList.get(current.ID)) {
// 연결된 정점들을 확인
 if(dist[next.ID] > dist[current.ID] + next.distance) {
// 다음 정점이 갖고 있는 최단거리가 현재 비용과 다음정점의 distance의 합보다 크다면
 dist[next.ID] = dist[current.ID] + next.distance;
// 최소 거리 비용 갱신
 pq.add(new Node(next.ID, dist[next.ID]));
// 최소 거리 비용이 갱신되는 경우만 queue에 넣기
 }
 }
 }
}

 public static void printAnswer() {
// 결과 출력 메소드
 StringBuilder sb = new StringBuilder();
 for (int i=1; i <= N; i++) {
 sb.append((dist[i] >= INF ? "INF" : dist[i]));
// 경로가 존재하지 않는 경우엔 INF출력
 sb.append("\n");
 }
 System.out.println(sb.toString());
 }
}
class Node implements Comparable<Node>{
// 정점간 연결을 나타내줄 노드클래스
int ID;
int distance;
// 정점과 거리를 저장할 변수
public Node(int ID, int distance) {
this.ID = ID;
this.distance = distance;
// 초기화 생성자
}
 public int compareTo(Node target) {
 // 작은 거리 비용이 먼저 오도록
 return this.distance - target.distance;
 }
}