#include <iostream>
#include <vector>
using namespace std;

struct Process {
    int id, arrival, burst, waiting, turnaround;
};

void displayGanttChart(const vector<Process> &procs) {
    cout << "\nGantt Chart:\n";
    for (const auto &p : procs) {
        cout << "| P" << p.id << " ";
    }
    cout << "|\n";
}

int main() {
    vector<Process> procs = {{1, 0, 4}, {2, 1, 3}, {3, 2, 2}};
    displayGanttChart(procs);
    return 0;
}