// Function to perform scanline filling
void scanFillPolygon(int *x, int *y, int n) {
    int yMin = y[0], yMax = y[0];

    // Find the minimum and maximum y coordinates
    for (int i = 1; i < n; i++) {
        if (y[i] < yMin) yMin = y[i];
        if (y[i] > yMax) yMax = y[i];
    }

    // Loop through scanlines from yMin to yMax
    for (int yScan = yMin; yScan <= yMax; yScan++) {
        int intersections = 0;
        int xIntersections[n];

        // Find intersections of scanline with polygon edges
        for (int i = 0; i < n; i++) {
            int next = (i + 1) % n; //to get the next index
            int y1 = y[i], y2 = y[next];
            if ((y1 < yScan && y2 >= yScan) || (y2 < yScan && y1 >= yScan)) {
                float xIntersect = x[i] + (float)(yScan - y[i]) * (x[next] - x[i]) / (y[next] - y[i]);
                xIntersections[intersections++] = (int)xIntersect;
            }
        }

        // Sort intersections in increasing order
        std::sort(xIntersections, xIntersections + intersections);

        // Fill scanline between pairs of intersection
        for (int i = 0; i < intersections; i += 2) {
            drawHorizontalLine(xIntersections[i], yScan, xIntersections[i + 1]);
        }
    }
}

int main(){
int x[] = {normalizeX(100), normalizeX(400), normalizeX(400), normalizeX(100)};  //ignore the normalization
    int y[] = {normalizeY(50), normalizeY(100), normalizeY(300), normalizeY(350)};
    int n = sizeof(x) / sizeof(x[0]); //number of edges
  scanFillPolygon(x,y,n);
}
