void dda(int x1, int y1, int x2, int y2)
{
  float m, yc, xc;
  int dx, dy, y;

  dx = x2 - x1;
  dy = y2 - y1;

  if (x1 > x2 && y1 > y2) // if P1 is in right-down & P2 is in left-top corner.
  {
    //swap x and y coordinates
    int temp = x1;
    x1 = x2;
    x2 = temp;

    temp = y1;
    y1 = y2;
    y2 = temp;
  }

  if (dx != 0)
    m = (float)dy / dx;
  else //(dx=0)simply plotting the vertical line and exiting
  {
    for (y = y1; y <= y2; y++) //only iterating the y coordinates
    {
      putpixel(x1, y, LIGHTCYAN);
    }
    return;
  }

  if (abs(dx) >= abs(dy)) // GENTLE SLOPE
  {
    yc = y1;
    while (x1 <= x2)
    {
      putpixel(x1, y1, LIGHTCYAN);
      x1++;
      yc = yc + m;
      y1 = yc + 0.5; // will round it off to the nearest int as y1 is int type
    }
  }
  else // STEEP SLOPE
  {
    xc = x1;
    while (y1 <= y2)
    {
      putpixel(x1, y1, LIGHTCYAN);
      y1++;
      xc = xc + (1 / m);
      x1 = xc + 0.5;
    }
  }
}
