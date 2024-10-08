void incremente(int *a)
{
  (*a)++;
}

void f(int *px, int *py)
{
  if (*px <= *py)
  {
    incremente(&px);
  }
  else
  {
    incremente(&py);
  };
}

