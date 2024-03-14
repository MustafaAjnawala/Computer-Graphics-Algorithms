void midPoint(int xc, int yc, int r)
{
  int x, y, d;
  d = 1 - r;
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
      d = d + 2 * x + 1;
    }
    else
    {
      d = d + 2 * (x - y) + 5;
      y = y - 1;
    }
    x = x + 1;
  }
}
