#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
void WriteData(char *filename){
    srand(time(NULL));

    FILE *fp=fopen(filename,"w");
    if(fp==NULL){
        printf("can not open file\n");
        return;
    }

    int n=3,k=4;
    fprintf(fp,"%d ",n);
    fprintf(fp,"%d ",k);
    for(int i=0;i<rand()%1000+100;++i){
        fprintf(fp,"%d ",rand()%1000);
        fprintf(fp,"%d ",rand()%1000);
        fprintf(fp,"%d ",rand()%1000);
        fprintf(fp,"%d ",rand()%1000);
    }

    fclose(fp);
}
void ReadFile(const string &filename,int &n,int &k,vector<vector<int> > &res){
    ifstream in(filename);
    if(!in.is_open()){
        cout<<"can not open\n";
        return;
    }

    in>>n>>k;
    vector<int> tmp;
    n=0;
    while(!in.eof()){
        tmp.clear();
        for(int i=0;i<k;++i){
            int x;
            in>>x;
            tmp.push_back(x);
        }
        res.push_back(tmp);
        n++;
    }

    in.close();
}
double Distance(const vector<int> &p1,const vector<int> &p2){
    double res=0;
    for(int i=0;i<p1.size();++i){
        res+=(p1[i]-p2[i])*(p1[i]-p2[i]);
    }
    return sqrt(res*1.0);
}
void MinDis(const vector<vector<int> > &res,vector<int> &p1,vector<int> &p2,double &dis){
    int x=0,y=0;

    for(int i=0;i<res.size();++i){
        for(int j=0;j<res.size();++j){
            if(i==j){
                continue;
            }
            if(Distance(res[i],res[j])<dis){
                x=i;y=j;
                dis=Distance(res[i],res[j]);
            }
        }
    }

    p1=res[x];
    p2=res[y];
}
void Print_Point(const vector<int> &p1){
    for(int i=0;i<p1.size();++i){
        cout<<p1[i]<<" ";
    }
    cout<<endl;
}
void Print_Set(const vector<vector<int> > &p){
    for(int i=0;i<p.size();++i){
        for(int j=0;j<p[0].size();++j)
            cout<<p[i][j]<<" ";
        cout<<endl;
    }
}
void Nearest_k(const vector<int> &p,vector<vector<int> > res,vector<vector<int> > &PointSet,const int &k){
    int x;
    for(int i=0;i<k;++i){
        x=i;
        for(int j=i+1;j<res.size();++j){
            if(Distance(p,res[j])<Distance(p,res[x])){
                x=j;
            }
        }
        vector<int> tmp=res[i];
        res[i]=res[x];
        res[x]=tmp;
        PointSet.push_back(res[i]);
    }//end for i
}
int main() {
    //WriteData("/home/jinm32/by/2017/data.txt");
    vector<vector<int> > res;
    int n,k;
    ReadFile("/home/jinm32/by/2017/data.txt",n,k,res);
    cout<<"维度："<<k<<" 点的个数："<<n<<endl;

    double dis=65535.0;
    vector<int>p1,p2;
    MinDis(res,p1,p2,dis);
    cout<<"距离最近的两个点是\n";
    Print_Point(p1);
    Print_Point(p2);
    cout<<"距离是："<<dis<<endl;

    vector<vector<int> >NearestPoints;
    Nearest_k(res[0],res,NearestPoints,n);
    cout<<"距离第一个点最近的"<<n<<"个点是"<<endl;
    Print_Set(NearestPoints);


    return 0;
}