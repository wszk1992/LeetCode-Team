    // find the discriminant of overlapping area
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if((C>=E && D>=F && A<=G && B<=H))
            return (C-A)*(D-B)+(G-E)*(H-F)-(min(C,G)-max(A,E))*(min(D,H)-max(B,F));
        else
            return (C-A)*(D-B)+(G-E)*(H-F);
    }
    
    // without checking overlappint
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left = max(A,E), right = max(min(C,G), left);
        int bottom = max(B,F), top = max(min(D,H), bottom);
        return (C-A)*(D-B) - (right-left)*(top-bottom) + (G-E)*(H-F);
    }   
  
