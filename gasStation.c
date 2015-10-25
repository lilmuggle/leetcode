int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    for(int i = 0, j; i < gasSize; i = ++j) {
        if(gas[i] >= cost[i]) {
            int start = i, tank = 0;
            for(j = i; j < gasSize + i; j++) {
                tank = tank + gas[j % gasSize] - cost[j % gasSize];
                if(tank < 0)
                    break;
            }
            if(tank >= 0)
                return start;
        }
    }
    return gasSize > 0 ? -1 : 0;
}

//After improvement
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int start = 0, total = 0, tank = 0;
    for(int i = 0; i < gasSize; i++)
        if((tank = tank + gas[i] - cost[i]) < 0) {
            start = i + 1;
            total += tank;
            tank = 0;
        }
    return (total + tank) < 0 ? -1 : start;
}
