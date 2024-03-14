void bresen_circle(int xc, int yc, int r)
{
  int x, y, d;
  d = 3 - 2 * r;
  x = 0;
  y = r;
  while (x <= y)
  {
    putpixel(xc + x, yc + y, RED);
    putpixel(xc - x, yc - y, RED);
    putpixel(xc + x, yc - y, RED);
    putpixel(xc - x, yc + y, RED);
    putpixel(xc + y, yc + x, RED);
    putpixel(xc - y, yc - x, RED);
    putpixel(xc + y, yc - x, RED);
    putpixel(xc - y, yc + x, RED);
    if (d <= 0)
    {
      d = d + 4 * x + 6;
    }
    else
    {
      d = d + 4 * (x - y) + 10;
      y = y - 1;
    }
    x = x + 1;
  }
}
