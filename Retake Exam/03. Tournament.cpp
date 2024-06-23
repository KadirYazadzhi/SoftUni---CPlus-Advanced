#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Team {
    string name;
    int points = 0;
    int scoredGoals = 0;
    int receivedGoals = 0;
};

int main() {
    string line;
    getline(cin, line);
    istringstream teamStream(line);
    vector<Team> teams;
    unordered_map<string, int> teamIndices;
    string teamName;
    int index = 0;

    while (teamStream >> teamName) {
        teams.push_back({teamName});
        teamIndices[teamName] = index++;
    }

    while (getline(cin, line) && line != ".") {
        istringstream matchStream(line);
        string team1, team2;
        int goals1, goals2;
        matchStream >> team1 >> goals1 >> team2 >> goals2;

        int index1 = teamIndices[team1];
        int index2 = teamIndices[team2];

        teams[index1].scoredGoals += goals1;
        teams[index1].receivedGoals += goals2;

        teams[index2].scoredGoals += goals2;
        teams[index2].receivedGoals += goals1;

        if (goals1 > goals2) {
            teams[index1].points += 3;
        } else if (goals1 < goals2) {
            teams[index2].points += 3;
        } else {
            teams[index1].points += 1;
            teams[index2].points += 1;
        }
    }

    for (const auto& team : teams) {
        cout << team.name << " - " << team.points << " - "
             << team.scoredGoals << " - " << team.receivedGoals << endl;
    }

    int maxPoints = max_element(teams.begin(), teams.end(), [](const Team& a, const Team& b) {
        return a.points < b.points;
    })->points;

    vector<string> topTeams;
    for (const auto& team : teams) {
        if (team.points == maxPoints) {
            topTeams.push_back(team.name);
        }
    }

    cout << "Top team(s) : ";
    for (size_t i = 0; i < topTeams.size(); ++i) {
        cout << topTeams[i];
        if (i < topTeams.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    return 0;
}
