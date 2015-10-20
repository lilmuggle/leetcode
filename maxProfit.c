int maxProfit(int* prices, int pricesSize) {
    int i, minpri, maxpro;
    maxpro = minpri = 0;
    minpri = prices[0];
    for(i = 0; i < pricesSize; i++) {
        if(prices[i] <= minpri)
            minpri = prices[i];
        maxpro = maxpro > (prices[i] - minpri) ? maxpro : (prices[i] - minpri);
    }
    return maxpro;
}
