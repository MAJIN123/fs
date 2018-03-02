#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
struct Request{
    string s1;
    string s2;
    int d;
    Request(const string &p1,const string &p2,int num):s1(p1),s2(p2),d(num){}
};

vector<vector<string> >flights;
vector<Request> request;

void ReadInputFile(const string &filename){
    ifstream in(filename);
    if (! in.is_open())
    {
        cout << "Error opening file"; exit (1);
    }
    string s1,s2;
    int n;
    in>>n;
    for(int i=0;i<n;++i){
        in>>s1>>s2;
        s1.erase(0,1);
        s1.erase(s1.size()-1,1);
        s2.erase(s2.size()-1,1);
        vector<string> tmp;
        tmp.clear();
        tmp.push_back(s1);
        tmp.push_back(s2);
        flights.push_back(tmp);
    }
}
void ReadRequestFile(const string &filename){
    ifstream in(filename);
    if (! in.is_open())
    {
        cout << "Error opening file"; exit (1);
    }
    string s1,s2,s3;
    int n;
    in>>n;
    for(int i=0;i<n;++i){
        in>>s1>>s2>>s3;
        s1.erase(0,1);
        s1.erase(s1.size()-1,1);
        s2.erase(s2.size()-1,1);
        s3.erase(s3.size()-1,1);
        request.push_back(Request(s1,s2,atoi(s3.c_str())));
    }
}
bool CanReach(string s1,string s2,int count){
    if(count==1){
        for(int i=0;i<flights.size();++i){
            if(flights[i][0]==s1&&flights[i][1]==s2) {
                return true;
            }
        }
    }
    else{
        for(int i=0;i<flights.size();++i){
            if(flights[i][0]==s1) {
                if(CanReach(flights[i][1],s2,count-1)){
                    return true;
                }
            }
        }
        return false;
    }
}
void run(){
    ofstream out("/home/jinm32/by/2013/result.txt");
    for(int i=0;i<request.size();++i){
        Request pr=request[i];
        out<<"["<<pr.s1<<", "<<pr.s2<<", ";
        out << (CanReach(pr.s1, pr.s2, pr.d) ? "YES]\n" : "NO]\n");
    }
}

int main() {
    ReadInputFile("/home/jinm32/by/2013/PathInput.txt");
    ReadRequestFile("/home/jinm32/by/2013/PathRequest.txt");
    run();
    return 0;
}