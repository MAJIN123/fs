// 13年复试题
// 注释代码为另一种做法
// 运行环境：vs2010

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <map>
#include <vector>

using namespace std;

struct PathRequest
{
    string p1;
    string p2;
    int d;

    PathRequest(const string &p1, const string &p2, int d) : p1(p1), p2(p2), d(d) {}
};

int path[101][101];
vector<PathRequest> request;
map<string, int> strtoindex;
// bool used[101];
size_t n = 0;

void init()
{
    memset(path, 1<<5, sizeof(path));
//    memset(used, false, sizeof(used));
}

void readPathInput(const string &fileName)
{
    ifstream in(fileName);
    string s1, s2;
    int n, no = 0;

    in >> n;
    for (int i = 0; i < n; ++i)
    {
        in >> s1 >> s2;
        s1.erase(0, 1);
        s1.erase(s1.size()-1, 1);
        s2.erase(s2.size()-1, 1);

        if (strtoindex.count(s1) == 0)
            strtoindex[s1] = no++;
        if (strtoindex.count(s2) == 0)
            strtoindex[s2] = no++;
        path[strtoindex[s1]][strtoindex[s2]] = 1;
    }
}

void readRequestFile(const string &fileName)
{
    ifstream in(fileName);
    int n;
    string s1, s2, s3;

    in >> n;
    for (int i = 0; i < n; ++i)
    {
        in >> s1 >> s2 >> s3;
        s1.erase(0,1);
        s1.erase(s1.size()-1, 1);
        s2.erase(s2.size()-1, 1);
        s3.erase(s3.size()-1, 1);
        request.push_back(PathRequest(s1, s2, atoi(s3.c_str())));
    }
}

void readData()
{
    readPathInput("PathInput.txt");
    readRequestFile("PathRequest.txt");
	n = strtoindex.size();
}

// bool dfs(int p1, int p2, int dist)
// {
//     if (p1 == p2)
//         return true;
//     if (dist == 0)
//         return false;

//     for (int i = 0; i < n; ++i)
//     {
//         if (path[p1][i] == 1 && !used[i])
//         {
//             used[i] = true;
//             bool ok = dfs(i, p2, dist - 1);
//             used[i] = false;
//             if (ok)
//                 return true;
//         }
//     }
//     return false;
// }

void floyd()
{
	for (size_t k = 0; k < n; ++k)
	{
		for (size_t i = 0; i < n; ++i)
		{
			for (size_t j = 0; j < n; ++j)
			{
				if (path[i][k] + path[k][j] < path[i][j])
					path[i][j] = path[i][k] + path[k][j];
			}
		}
	}
}

void run()
{
    ofstream out("result.txt");

    for (size_t i = 0; i < request.size(); ++i)
    {
        PathRequest pr = request[i];
        out << "[" << pr.p1 << ", " << pr.p2 << ", ";
//        if (dfs(strtoindex[pr.p1], strtoindex[pr.p2], pr.d))
		if (path[strtoindex[pr.p1]][strtoindex[pr.p2]] <= pr.d)
            out << "YES]\n";
        else
            out << "NO]\n";
    }
}

int main()
{
    init();
    readData();
	floyd();//
    run();

    return 0;
}
