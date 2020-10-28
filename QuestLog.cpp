/* -------------------------------
 * --------- QuestLog ------------
 * -------------------------------
 * Created by Codie Cottrell on 10/21/20
 * QuestLog is a Directed Acyclic Graph of Quests.
 * Where quests are the nodes and their transition from
 * node to node is based off completion of the prevQuest.
 *
*/
#include <iostream>
#include <utility>
#include <vector>
#include "QuestLog.h"
using namespace std;

QuestLog::QuestLog(vector<string> questFiles, Path paths[], int n, int N) {
    // allocate memory
    head = new Quest*[N]();
    this->questFiles = std::move(questFiles);
    this->N = N;

    // initialize head pointer for all vertices
    for (int i = 0; i < N; i++)
        head[i] = nullptr;

    // add edges to the directed graph
    for (unsigned i = 0; i < n; i++)
    {
        int srcId = paths[i].srcId;
        int endId = paths[i].endId;

        // insert in the beginning
        Quest* newQuest = addQuestNode(srcId, head[endId]);

        // point head pointer to new node
        head[srcId] = newQuest;

    }
}
// add quest to front
Quest* QuestLog::addQuestNode(int dest, Quest *head) {
    Quest* newQuest = new Quest;
    newQuest->id = dest;

    // point the new quest to the current head
    newQuest->nextQuest = head;

    return newQuest;
}

// Destructor
QuestLog::~QuestLog() {
    for (int i = 0; i < N; i++)
        delete[] head[i];

    delete[] head;
}

// print all neighboring vertices of given vertex
void QuestLog::printList(Quest* ptr)
{
    while (ptr != nullptr)
    {
        cout << " -> " << ptr->id << " ";
        ptr = ptr->nextQuest;
    }
    cout << endl;
}

// Graph Implementation in C++ without using STL
int main()
{
    vector<string> questFiles = {"Quests/eccentialItems.txt"};
    // array of graph edges as per above diagram.
    Path paths[] =
            {
                    // pair (x, y) represents edge from x to y
                    { 0, 1}, { 1, 2 }, { 2, 0 }, { 2, 1 },
                    { 3, 2 }, { 4, 5 }, { 5, 4 }
            };

    // Number of vertices in the graph
    int N = 6;

    // calculate number of edges
    int n = sizeof(paths)/sizeof(paths[0]);

    // construct graph
    QuestLog questLog(questFiles, paths, n, N);

    // print adjacency list representation of graph
    for (int i = 0; i < N; i++)
    {
        // print given vertex
        cout << i << " --";

        // print all its neighboring vertices
        questLog.printList(questLog.head[i]);
    }

    return 0;
}