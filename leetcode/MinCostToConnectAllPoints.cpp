//
// Created by Chinmay Kulkarni on 11/7/22.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

class Point {
public:
    int x, y;

    Point() {}

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    bool equals(Point &point) const {
        return point.x == this->x && point.y == this->y;
    }

    int distance(Point point) {
        return abs(point.x - this->x) + abs(point.y - this->y);
    }
};

bool operator<(const Point &p1, const Point &p2) {
    return p1.x + p1.y < p2.x + p2.y;
}

//class UnionFind {
//public:
//    map<Point, Point> mapVertexParent;
//
//    UnionFind(vector<Point> &points) {
//        for (auto point: points) {
//            mapVertexParent[point] = point;
//        }
//    }
//
//    void print() {
//        for (auto it: mapVertexParent) {
//            cout << it.first << "): " << "(" << parent.first << " " << parent.second << ")\n";
//        }
//    }
//
//    Point findParent(Point &coord) {
//
//    }
//
//    void performUnion(Point &coord1, Point &coord2) {
//
//    }
//};

class Solution {
private:
    map<Point, int> mapCoordIdx;
    unordered_map<int, Point> mapIdxCoord;
    vector<vector<int>> adjMatrix;
    map<int, vector<pair<Point, Point>>> mapDistCoords;

    void initIndicesMaps(vector<vector<int>> &points) {
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0], y = points[i][1];
            Point point = Point(x, y);
            mapCoordIdx[point] = i;
            mapIdxCoord[i] = point;
        }
    }

    void initAdjMatrixDistMap(vector<vector<int>> &points) {
        // Create adjMatrix with 0s
        for (int i = 0; i < points.size(); i++) {
            vector<int> row(points.size(), 0);
            adjMatrix.push_back(row);
        }

        // Fill adjMatrix with distances
        for (auto p1: points) {
            Point src = Point(p1[0], p1[1]);
            int i = mapCoordIdx[src];
            for (auto p2: points) {
                Point dest = Point(p2[0], p2[1]);
                int j = mapCoordIdx[dest];
                int dist = src.distance(dest);
                adjMatrix[i][j] = dist;

                mapDistCoords[dist].push_back(pair<Point, Point>{src, dest});
            }
        }
    }

public:
    int minCostConnectPoints(vector<vector<int>> &points) {
        // Can't create unordered_map of pair<int, int> "easily" in C++
        // So creating map<pair<int, int>>
        initIndicesMaps(points);

        // Create adjacency matrix and
        // Create map<int, pair<pair<int, int>, pair<int, int>>> to store
        // length : coordinates pair
        initAdjMatrixDistMap(points);

        // Main algorithm to find MST
//        UnionFind uf = UnionFind(points);
        // uf.print();
        int minCost = 0;
        set<Point> setPoints;

        for (auto& it: mapDistCoords) {
            int distance = it.first;
            for(auto i: it.second) {
                Point p1 = i.first, p2 = i.second;
                if (setPoints.find(p1) != setPoints.end() && setPoints.find(p2) != setPoints.end()) {
                    // Both points are already in the MST.
                    // Choosing this edge would create a cycle.
                    // Skip this edge
                    continue;
                }
                minCost += distance;
                setPoints.insert(p1);
                setPoints.insert(p2);
            }
        }

        return minCost;
    }
};

int main() {
    Solution solution = Solution();
    vector<vector<int>> points = {
            {0, 0},
            {2, 2},
            {3, 10},
            {5, 2},
            {7, 0}
    };
    int minCost = solution.minCostConnectPoints(points);
    cout << minCost << endl;
}