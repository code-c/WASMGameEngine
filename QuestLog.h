/* --------------------------------------
 * --------- QuestLog Header ------------
 * --------------------------------------
 * Created by Codie Cottrell on 10/21/20
 * QuestLog is a Directed Acyclic Graph of Quests.
 * Where quests are the nodes and their transition from
 * node to node is based off completion of the prevQuest.
 *
*/
#ifndef QUESTLOG_H
#define QUESTLOG_H

/* Quests are nodes which store id of quest (i.e. 1,2,3...200)
 * whether player has visited the quest, completed the quest.
 * stores next quest pointer, and the previous quest pointer
 * As well as the filename of the quest info and stats.
*/
struct Quest {
    int id;
    bool visited, completed;
    Quest *prevQuest, *nextQuest;
    std::string fileName;
};

/* Paths are edges which store whether its been activated.
 * and its beginning quest's and ending quest's ID's
 */
struct Path {
    int srcId,  endId;
    bool activated;
};


class QuestLog {
    std::vector<std::string> questFiles;
    int N; // number of nodes
    void buildQuests();
    Quest* addQuestNode(int dest, Quest* head);
public:
    Quest **head;
    QuestLog(std::vector<std::string> questFiles, Path paths[], int n, int N);
    ~QuestLog(); //deConstructor
    void printList(Quest* ptr);

};




#endif