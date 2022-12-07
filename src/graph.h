#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <string>
#include "utils.h"
#include <sstream>
#include <fstream>
#include <stack>


class Graph {
    public:
        Graph(const std::string& filename, const int& file_length);
        std::unordered_set<int> BFS_Trim(const std::vector<int>& seeds, int bound);
        void BFS(std::unordered_set<int>& nodes, int start, int bound);
        std::map<int, int>&  BFS(int start);
        std::vector<int> getAdjacent(int idx);
        std::map<int, int> brandes_bfs();
        friend std::map<int,std::string>& load_titles(const std::string& filename, const Graph& graph, const int& file_length);
        //SCC
        void getSCCs();
        void dfs_1(int v, std::stack<int> &s);
        void dfs_2(int v, std::map<int, std::vector<int>> &SCCs, int &numComponents, std::map<int, std::vector<int>> &transpose);
    private:
        std::unordered_set<int> idxs_;
        // SCC
        std::map<int, std::vector<int>> graph_;
        std::vector<bool> visited_;
};

std::map<int,std::string>& load_titles(const std::string& filename, const Graph& graph, const int& file_length);