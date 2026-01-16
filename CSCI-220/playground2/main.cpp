#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

template <typename T>
void print(T anything)
{
  cout << anything << endl;
}

void arrays()
{
  int stores[10];
  int stores2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  static int arr[10];

  char chars[3] = {'A', 'B', 'c'};
  for (int i = 0; i < size(chars); i++)
  {
    print(stores2[i]);
  }

  // print(chars);
}

void contiguous()
{
  const int size = 3;
  int arr[size] = {1, 2, 3};
  print(arr);

  for (int i = 0; i < size; i++)
  {
    print(arr[i]);
  }

  cout << "print address: " << endl;
  for (int i = 0; i < size; i++)
  {
    print(&arr[i]);
  }
}

void dynamicArr()
{
  size_t size;
  cout << "enter size: ";
  cin >> size;

  int *p_dynamicArr = new int[size];

  cout << "*p_dynamicArr: " << *p_dynamicArr << endl; // *p_dynamicArr: 0
  cout << "&p_dynamicArr: " << &p_dynamicArr << endl; // &p_dynamicArr: 0x30a1c0c20
  cout << "p_dynamicArr: " << p_dynamicArr << endl;   // p_dynamicArr: 0x7fee03f06140

  delete[] p_dynamicArr;
}

void pointerMath()
{
  int *pDynamicArr = new int[10];
  int *pCurrentArraySlot = pDynamicArr;
  // *pCurrentArraySlot = pCurrentArraySlot[0];

  for (size_t i = 0; i < 10; i++)
  {
    cout << pCurrentArraySlot << endl;
    *pCurrentArraySlot = static_cast<int>(i);
    pCurrentArraySlot++;
  }
}

void aVector()
{
  vector<unsigned int> vec;
  cout << vec.size() << " " << vec.capacity() << endl;
  for (unsigned int i = 0; i < 129; i++)
  {
    vec.push_back(i);
    cout << vec.size() << " " << vec.capacity() << endl;
  }
}

void release(char *p, int n)
{
  if (n % 2 == 0)
    delete[] p;
}

int main()
{
  int a = rand();
  char *x = new char[100];
  cout << "a: " << a << endl;
  if (a % 2 == 1)
  {
    cout << "deleteing x";
    delete[] x;
  }
  release(x, a); // undefined behavior if a is an even number
}
