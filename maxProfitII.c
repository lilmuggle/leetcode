int maxProfit(int* prices, int pricesSize) {
    int i, pro, start, end, maxpro;
    maxpro = start = 0;
    for(end = 0; end < pricesSize; end++) {
        pro = prices[end] - prices[start];
        if(pro >= 0)
            maxpro += pro;
        start = end;
    }
    return maxpro;
}
