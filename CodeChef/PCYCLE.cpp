/* We consider permutations of the numbers 1,..., N for some N. By permutation we mean a rearrangment of the number 1,...,N. For example

2  4  5  1  7  6  3  8

is a permutation of 1,2,...,8. Of course,

1  2  3  4  5  6  7  8

is also a permutation of 1,2,...,8.

We can "walk around" a permutation in a interesting way and here is how it is done for the permutation above:

Start at position 1. At position 1 we have 2 and so we go to position 2. Here we find 4 and so we go to position 4. Here we find 1, which is a position that we have already visited. This completes the first part of our walk and we denote this walk by (1 2 4 1). Such a walk is called a cycle. An interesting property of such walks, that you may take for granted, is that the position we revisit will always be the one we started from!

We continue our walk by jumping to first unvisited position, in this case position 3 and continue in the same manner. This time we find 5 at position 3 and so we go to position 5 and find 7 and we go to position 7 and find 3 and thus we get the cycle (3 5 7 3). Next we start at position 6 and get (6 6) and finally we start at position 8 and get the cycle (8 8). We have exhausted all the positions. Our walk through this permutation consists of 4 cycles.

One can carry out this walk through any permutation and obtain a set of cycles as the result. Your task is to print out the cycles that result from walking through a given permutation.

Input format

The first line of the input is a positive integer N indicating the length of the permutation. The next line contains N integers and is a permutation of 1,2,...,N.

You may assume that N ≤ 1000.

Output format

The first line of the output must contain a single integer k denoting the number of cycles in the permutation. Line 2 should describe the first cycle, line 3 the second cycle and so on and line k+1 should describe the kth cycle.

Examples

Sample input 1:

8
2 4 5 1 7 6 3 8

Sample output 1:

4
1 2 4 1
3 5 7 3
6 6
8 8 

Sample input 2:

8
1 2 3 4 5 6 7 8

Sample output 2:

8
1 1
2 2
3 3
4 4
5 5
6 6
7 7
8 8
*/

#include <iostream>
#include <vector>

void DFS(int node, 
         const std::vector<int>& adj, 
         std::vector<bool>& visited, 
         std::vector<int>& result)
{
    result.push_back(node);
    visited[node] = true;
    
    if (!visited[adj[node]])
        DFS(adj[node], adj, visited, result);
    else
        result.push_back(adj[node]);
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec)
{
    if (vec.size() > 0)
    {
        os << vec[0];
        
        for (int i = 1; i < vec.size(); ++i)
            os << " " << vec[i];
    }
        
    return os;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> adj (n+1);
    std::vector<bool> visited (n+1, false);
    std::vector<std::vector<int>> result;
    
    // Input
    for (int i = 1; i <= n; ++i)
        std::cin >> adj[i];
    
    // Solve
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            std::vector<int> tmp;
            
            DFS(i, adj, visited, tmp);
            
            result.push_back(std::move(tmp));
        }
    }
    
    // Output
    std::cout << result.size() << std::endl;
    for (auto& vec: result)
        std::cout << vec << std::endl;
    
    
    return 0;
}
