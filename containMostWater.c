int maxArea(int* height, int heightSize) {
    int i, j, w, maxwater, head, tail;
    if(heightSize < 2)
        return 0;
    head = maxwater = 0;
    tail = heightSize - 1;
    while(head < tail) {
        w = (height[head]<height[tail]?height[head]:height[tail])*(tail-head);
        if(w > maxwater)
            maxwater = w;
        if(height[head] < height[i])
            head++;
        else
            tail--;
    }
    return maxwater;
}
