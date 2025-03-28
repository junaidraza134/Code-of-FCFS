#pragma once
#include <vector>
using namespace std;

struct Process {
    int id;
    int arrival;
    int burst;
    int waiting;
    int turnaround;
    int priority;
};

void fcfs(vector<Process> &procs);
void display(const vector<Process> &procs);
void displayGanttChart(const vector<Process> &procs);
int predictSchedule(const vector<Process> &procs);