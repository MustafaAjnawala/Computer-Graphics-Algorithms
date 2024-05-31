void bresenham(int x1, int y1, int x2, int y2)
{
  int dx, dy, G;
  int sign_x = 1, sign_y = 1;

  // Swap x & y points if x1 > x2
  if (x1 > x2)
  {
    int temp = x1;
    x1 = x2;
    x2 = temp;

    temp = y1;
    y1 = y2;
    y2 = temp;
  }

  dx = abs(x2 - x1);
  dy = abs(y2 - y1);
  G = (2 * dy) - dx;

  // Determine the sign of slope
  if (y2 < y1)
    sign_y = -1; //so will dec y if(y1>y2) and inc y if(y1<y2)

  if (dx > dy) // GENTLE SLOPE
  {
    while (x1 <= x2)
    {
      putpixel(x1, y1, LIGHTCYAN);
      if (G >= 0)
      {
        y1 += sign_y; //will get accordingly inc or dec
        G = G + 2 * (dy - dx);
      }
      else
      {
        G = G + (2 * dy);
      }
      x1++; //inc by default as we hv already swapped if(x1>x2)
    }
  }
  else // STEEP SLOPE
  {
    while (y1 != y2)
    {
      putpixel(x1, y1, LIGHTCYAN);
      if (G >= 0)
      {
        x1++; //inc by default as we hv already swapped if(x1>x2)
        G = G + 2 * (dx - dy);
      }
      else
      {
        G = G + (2 * dx);
      }
      y1 += sign_y; //will get accordingly inc or dec
    }
  }
}
