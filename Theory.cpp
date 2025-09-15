#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// cau truc du lieu cho do thi 

struct Graph {
    int n; // so dinh 
    vector <vector < int > > adjMatrix  ; // ma tran ke
    bool isDirected; // dang do thi co huong hay la vo huong 
};

// khoi tao do thi 
void initGraph( Graph& g , int vertices = 0 , bool directed = false ){
    g.n = vertices;
    g.isDirected = directed;
    g.adjMatrix.assign(vertices,vector<int>(vertices,0));
}

// thiet lap so dinh va loai do thi 

void setGraph (Graph& g, int vertices = 0 , bool directed){
    g.n = vertices ; 
    g.isDirected =  false;
    g.adjMatrix.assign(vertices,vector<int>(vertices,0));
}
// them canh cung 
void addEdge (Graph& g , int u , int v , int weight = 1 ){
    if ( u >= 0 && u < g.n && v >= 0 && v < g.n){ // voi u la dinh hang ngang , v la dinh hang doc 
        g.adjMatrix[u][v] += weight ;
        if (!g.isDirected){
            g.adjMatrix[u][v] += weight;
        }
    }else{
        cout << "loi dinh khong hop le ";
    }
}

// xoa canh / cung 
void removeEdge (Graph& g , int u , int v ){
    if (u >=0 && u <g.n && v >= 0 && v <g.n){
        g.adjMatrix[u][v] = 0;
        if (!g.isDirected){
            g.adjMatrix[u][v]=0;
        }
    }
}

// kiem tra co canh cung khong 
bool hasEdge (const Graph& g , int u , int v ){
    if (u >= 0 && u<g.n && v >=0 && v<g.n){
        return g.adjMatrix[u][v] > 0 ;
    }
}

// kiem ta co canh / cung khong 
bool hasEdge (const Graph& g, int u , int v ){
    if (u>=0 && u < g.n && v < g.n && v>= 0){
        return g.adjMatrix[u][v] > 0;
    }
    return false ;
}

// tinh bac cua dinh ( bac ra cho vao do thi co huong )
int getDegree ( const Graph& g , int vertex ){
    if ( vertex < 0 || vertex >= g.n ) return -1 ;
    int degree = 0 ;
    for (int j = 0 ; j < g.n ; j++){
        degree += g.adjMatrix[vertex][j];
    }
    return degree;
}

int getInDegree (const Graph& g , int vertex ){
    if (!g.isDirected || vertex < 0 || vertex >= g.n)
    return -1 ;

    int inDegree = 0 ;
    for (int i = 0 ; i < g.n ; i++ ){
        inDegree += g.adjMatrix[i][vertex];
    }
    return inDegree;
}
// nhap do thi tu ban phim 
void inputFromKeyBoard (Graph& g){
    cout << "nhap loai do thi ( o: vo huong 1: co huong )";
    int directed ; 
    cin >> directed ; 
    g.isDirected = (directed == 1);
    cout << "nhap so dinh";
    cin >> g.n ;
    g.adjMatrix.assign(g.n,vector<int>(g.n, 0));
    cout << "nhap so canh /cung ";
    int m ;
    cin >> m ;
    cout << "nhap " << m << "canh / cung ( dinh nguon , dinh dich )";
    if (g.isDirected) cout << ", trong so neu co 0";
    cout << "):\n"; 
    for (int i = 0 ; i < m ; i++){
        int u , v , w = 1 ;
        cout << "canh / cung " << i+1 << ":";
        cin >> u >> v ;
        // tuy chon nhap trong so 
        char choice ;
        cout << "co trong so (y/n)";
        cin >> choice;
        if (choice == 'y' || choice == 'Y'){
            cout << "nhap trong so :" ;
            cin >> w ; 
        }
        addEdge(g,u,v,w);
        
    }
}

// nhập đồ thị từ file 
bool inputFromFile (Graph& g , const string& filename){
    ifstream  file (filename);
    if (!file.is_open()){
        cout << "loi doc file " << filename;
        return false;
    }
    int directed ; 
    file >> directed >> g.n; // file luu theo dang dong dau tien luu thong tin (1/0 n)
    g.isDirected = (directed == 1);
    g.adjMatrix.assign(g.n , vector<int>(g.n , 0));

    int m;
    file >> m;

    // doc cac canh cung 
    for (int i = 0 ; i < m ; i++){
        int u , v , w = 1 ;
        file >> u >> v ;
        
        // kkiem tra xem co trong so khong 
        if ( file.peek() != '\n' && file.peek() != EOF && file.peek() != ' '){

        }
    }
}


// them canh / cung 
void addEdge (Graph& g, int u , int v , int weigh = 1){
    if (u>=0 && u<g.n && v>=0 && v<=g.n){
        for (int k=0 ; k<weigh; k++ ){
            if (g.isDirected){
                g.edges.push_back({u,v});
            }
        }
    }
}