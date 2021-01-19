struct Edge
{
    int a, b, weight;
    bool operator < (const Edge& Tmp)
    {
        return weight < Tmp.weight;
    }

    Edge(int a_, int b_, int weight_)
    : a(a_), b(b_), weight(weight_)
    {}
};

class Solution {
private:
    int PointNum, EdgeNum = 0;
    std::vector<Edge> Edges;

    int CalcDis(int i, int j, const vector<vector<int>>& points)
    {
        return std::abs(points[i][0] - points[j][0]) + std::abs(points[i][1] - points[j][1]);
    }

    int FindParent(int x, std::vector<int>& Parents)
    {
        if (x != Parents[x])
            Parents[x] = FindParent(Parents[x], Parents);
        return Parents[x];
    }

    int Kruskal(std::vector<int>& Parents)
    {
        std::sort(Edges.begin(), Edges.end());
        int res = 0;
        int cnt = 0;

        for (int i = 0; i < EdgeNum; ++i)
        {
            int a = Edges[i].a;
            int b = Edges[i].b;
            int weight = Edges[i].weight;
            
            a = FindParent(a, Parents);
            b = FindParent(b, Parents);
            if (a != b)
            {
                Parents[a] = b;
                res += weight;
                if (++cnt == PointNum - 1) break;
            }
        }

        if (cnt < PointNum - 1) return -1;
        return res;
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        PointNum = points.size();
        std::vector<int> Parents(PointNum);

        for (int i = 0; i < PointNum; ++i)
        {
            Parents[i] = i;
            for (int j = 0; j < PointNum; ++j)
            {
                if (i == j) continue;
                Edges.emplace_back(i, j, CalcDis(i, j, points));
                EdgeNum++;
            }
        }

        return Kruskal(Parents);
    }
};