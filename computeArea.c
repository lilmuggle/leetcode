#define min(x,y) (x<y?x:y)
#define max(x,y) (x>y?x:y)
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int area1, area2, area3 = 0;

    area1 = (C - A) * (D - B);
    area2 = (G - E) * (H - F);
    if((min(D,H) < max(B,F)) || (min(C,G) < max(A,E)))
        area3 = 0;
    else
        area3 = (min(D,H)-max(B,F))*(min(C,G)-max(A,E));
    return area1 + area2 - area3;
}
