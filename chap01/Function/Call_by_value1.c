// call by value ( pass by value)
void swap( int x, int y) {
  int temp;
  temp = x;
  x = y;
  y = temp;
}

int main() 
{
  int a = 10;
  int b = 20;

  swap(a, b);
}
  