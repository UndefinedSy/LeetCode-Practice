// 本题旨在寻找一个最小生成树中的关键边与非关键边：
// * 关键边：当一条边被禁用后，生成树无法形成，或者得到的非最小生成树
// * 非关键边：当一条被禁用后仍然可以形成最小生成树，且该边本身是最小生成树中的一个成员。
// 
// 因此我们可以先通过 Kruskal 生成一棵最小生成树作为 baseline
// 之后我们遍历所有的边：
// * 禁用该边后，生成树无法形成，或者得到的非最小生成树。【需要注意的是，如果一条边是关键边，则其不可能是非关键边】
// * 若一条边非关键边，则我们可以预先将该边放入生成树中，再求最小生成树，以判断一条边是否本身是否是最小生成树的成员。


struct Edge
{
    int From_, To_;
    int Weight_;
    int ID_;
    bool Availiable_;
    bool operator < (const Edge& Tmp)
    {
        return Weight_ < Tmp.Weight_;
    }
    Edge(int From, int To, int Weight, int ID, bool Availiable)
    : From_(From), To_(To), Weight_(Weight), ID_(ID), Availiable_(Availiable)
    {}
};

class UnionSet
{
private:
    std::vector<int> Parents;

public:
    void InitUnionSet(int n)
    {
        Parents.resize(n);
        for (int i = 0; i < n; ++i) Parents[i] = i;
    }

    int Find(int x)
    {
        if (x != Parents[x])
            Parents[x] = Find(Parents[x]);
        return Parents[x];
    }

    void Union(int x, int y)
    {
        Parents[x] = y;
    }
};

class Solution {
private:
    int PointNum_, EdgeNum_ = 0;
    std::vector<Edge> Edges_;
    UnionSet EdgeSet_;

    int Kruskal(int Res = 0, int Cnt = 0)
    {
        for (int i = 0; i < EdgeNum_; ++i)
        {
            if (!Edges_[i].Availiable_) continue;

            int From = Edges_[i].From_;
            int To = Edges_[i].To_;
            int Weight = Edges_[i].Weight_;

            From = EdgeSet_.Find(From);
            To = EdgeSet_.Find(To);
            if (From != To)
            {
                EdgeSet_.Union(From, To);
                Res += Weight;
                Cnt++;
                if (Cnt == PointNum_ - 1) return Res;
            }
        }

        return -1; // 1 <= weighti <= 1000
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        PointNum_ = n;

        for (auto&& TmpEdge : edges)
        {
            Edges_.emplace_back(TmpEdge[0], TmpEdge[1], TmpEdge[2], EdgeNum_++, true);
        }
        std::sort(Edges_.begin(), Edges_.end());

        vector<vector<int>> Res;

        EdgeSet_.InitUnionSet(PointNum_);
        int Baseline = Kruskal();
        if (Baseline != -1)
        {
            vector<int> CriticalEdge;
            vector<int> NonCriticalEdge;
            for (auto& CurrentEdge: Edges_)
            {
                int EdgeNo = CurrentEdge.ID_;
                /***************Find Critical Edge*****************/
                CurrentEdge.Availiable_ = false;             
                EdgeSet_.InitUnionSet(PointNum_);
                int TmpCritical = Kruskal();
                CurrentEdge.Availiable_ = true;
                // std::cout << "Target Edge is: " << EdgeNo
                //           << " | Baseline is: " << Baseline
                //           << " || TmpCritical is: " << TmpCritical << std::endl;
                if (Baseline != TmpCritical)
                {
                    CriticalEdge.push_back(EdgeNo);
                    continue;
                }
                /***************Find Critical Edge*****************/
                
                /***************Find Critical Edge*****************/
                EdgeSet_.InitUnionSet(PointNum_);
                EdgeSet_.Union(CurrentEdge.From_, CurrentEdge.To_);
                int TmpNonCritical = Kruskal(CurrentEdge.Weight_, 1);
                if (Baseline == TmpNonCritical)
                    NonCriticalEdge.push_back(EdgeNo);
                /***************Find Critical Edge*****************/
            }
            Res.emplace_back(std::move(CriticalEdge));
            Res.emplace_back(std::move(NonCriticalEdge));
        }

        return Res;
    }
};