#include "scheduler.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> procs(n);

    cout << "Enter arrival and burst times for each process (arrival burst):\n";
    for (int i = 0; i < n; ++i) {
        procs[i].id = i + 1;
        cin >> procs[i].arrival >> procs[i].burst;
    }

    int prediction = predictSchedule(procs);
    cout << "\nML Predicted next process: " << procs[prediction].id << endl;

    fcfs(procs);
    display(procs);
    displayGanttChart(procs);

    return 0;
}