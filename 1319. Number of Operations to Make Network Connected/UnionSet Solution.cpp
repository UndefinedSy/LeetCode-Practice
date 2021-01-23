// 解题思路：
// 首先很容易想到，要想使得 N 个节点联通，至少需要 N - 1 条不冗余的边。所以很自然的我们可以用并查集来计算根据输入能得到的非冗余边的数量。
// 进而是联通，题目中里连接两个子网的边是需要从已有的网络中拆下来的，也就是说我们还需要知道冗余边的数量。
// 因此，我们需要维护这两个状态：
// * 冗余边：当一条线路的两个端已经处于同一个子网内时，该边就是一条冗余边。
// * 非冗余边：当一条线路的两个端已经处于两个不同子网时，该边就是一条非冗余边。
// 最后我们只需要比较 冗余边 >=? N - 1 - 非冗余边

class UnionSet
{
private:
    std::vector<int> Parents;
    int Redundancy;
    int RequiredConnections;

public:
    UnionSet(int n)
    : Redundancy(0),
      RequiredConnections(n - 1)
    {
        Parents.resize(n);
    }

    void UnionInit(int n)
    {
        for (int i = 0; i < n; ++i)
            Parents[i] = i;
    }

    int Find(int x)
    {
        if (x != Parents[x])
            Parents[x] = Find(Parents[x]);
        return Parents[x];
    }

    void Union(int x, int y)
    {
        int xx = Find(x);
        int yy = Find(y);

        if (xx == yy)
        {
            Redundancy++;
            // std::cout << x << " & " << y << " has been connected"
            //           << ". Redundancy is: " << Redundancy << std::endl;
            return;
        }
        else
        {
            Parents[xx] = yy;
            RequiredConnections--;
            // std::cout << x << " & " << y << " will be connected"
            //           << ". RequiredConnections is: " << RequiredConnections << std::endl;
        }
    }

    int GetRes()
    {
        if (RequiredConnections > Redundancy)
            return -1;
        else 
            return RequiredConnections;
    }


};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        UnionSet US(n);
        US.UnionInit(n);
        for (auto&& Connection: connections)
        {
            US.Union(Connection[0], Connection[1]);
        }
        return US.GetRes();
    }
};