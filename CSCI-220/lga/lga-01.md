- Using the operator **&** , we can obtain the address of the value stored in a variable. The address can be stored in a **pointer** variable.

- Using the operator **\*** , known as the **dereference** operator, we can get or set the value pointed to by a pointer.

- Array variables are secretly **pointers**; however, describe one difference: **arrays can not be reassigned to a different memory location (while pointers can be reassigned to different address)**

- To the compiler, `p[j]` is equivalent to **\*(p+j)**.

- If `p` is an `int*`, and p = 0x1000, what is the value p + 3? **0x100C**

- The memory segment containing the function call stack is generally called the **stack**.

- Dynamically allocated memory for C++ comes from the **free store**.

- The **new** operator is used to dynamically allocate memory; the result of the operation is a **pointer** to the memory.

- The **delete** operator is used to deallocate dynamically allocated memory.
- Name two types of pointer you should never try to dereference: **nullptr/NULL and dangling pointers**.

- If your program regularly loses pointers to dynamically allocated memory, your program may have this kind of memory error: **memory leak**.

1. (Basic) Provide the missing line in the code below so that the program prints “42”:

```c++
void go(int* ptr) {
    // <- put your code here
    *ptr = 42;
}
int main() {
    int x = 17;
    go(&x);
    cout << x << endl;
    return 0;
}
```

2. (Basic) What is the output of the following code?

```c++
int a = 42;
int b = 17;

int* p = nullptr;
int* q = &a; // q is a pointer pointing to the address of a

*q = 99; // *q = 99, a = 99, b = 17, p = nullptr
p = q; // *p = 99, *q = 99, a = 99, b = 17
q = &b; // q now pointing to the address of b. a = 99, b = 17, *p = 99, q = &b

*q = 22; // *q = 22, b = 22, a = 99, *p = 99
*p = 77; // *p = 77, a = 77, *q = 22, b = 22

cout << a << " " << b << " " << q << endl; // 77 22 22
```

3. (Intermediate) What is the output of the following code?

```c++
int upper = 10;
int arr[11];

for (int i = 0; i <= upper; i++) arr[i] = i; // arr = [0,1,2,3,4,5,6,7,8,9,10]

for (int* p = arr; p <= arr + upper; p = p + 3) {
    cout << *p << " "; // 0 3 6 9
}

cout << endl;
for (int* q = arr + upper; q >= arr; q = q - 2) {
    cout << *q << " "; // 10 8 6 4 2 0
}
cout << endl;
```

4. Given some class `foo` with a public method named `run()`, write the function `run_all()` that takes in an array of `foo` objects and the length of the array and calls the `run()` method on each object. Give **two** different solutions for looping over the array (i.e., one using array indexing and another using pointers):

```c++
class foo {
public:
    void run(); // actual behavior defined elsewhere
};

void run_all(foo* objects, int len) {
    for (int i = 0; i < len; i++){
        objects[i].run();
    }

    // another way
    foo* ptr = objects;
    foo* endBoundary = objects + len;
    while (ptr < endBoundary){
        ptr->run();
        ptr++;
    }
}
```

5. (Basic) Write a program to dynamically allocate an array of 80 `ints`, fill every array position with 17, then deallocate the array.

```c++
int* arr = new int[80];
for (int i = 0; i < 80; i++){
    arr[i] = 17;
}

// or
for (int * p = arr; p < arr + 80; p++){
    *p = 17;
}

delete[] arr;
```

6. (Basic) What is problematic with this code?

```c++
double* get_sum(double x, double y) {
    double ans = x + y;
    return &ans;
}
```

Dangling pointer. return the address of a local variable ans. When the function finishes and returns, ans is destroyed.

7. (Basic) What is problematic with this code?

```c++
int main() {
    char* s;
    while (true) {
        int n = rand() % 10000;
        delete[] s;
        s = new char[n];
        for (int i = 0; i < n; i++) s[i] = 'a';
    }
}
```

The pointer `char* s` is uninitialized, so `delete[] s;` will cause a seg fault.
infinite loop?

8. (Intermediate) Explain the bug or issue with the code below, or provide a convincing argument that none exists:

```c++
void release(char* p, int n) {
    if (n % 2 == 0) delete[] p;
}
int main() {
    int a = rand();
    char *x = new char[100];
    if (a % 2 == 1) delete[] x;
    release(x, a);
}
```

We can pass a dangling pointer as a function parameter, and it won't crash as long as we don't use that dangling pointer inside that function.

There's no issue if the intention is to delete `x`. The code is **brittle**. `x` will be deleted inside `main` if `a` is an odd number, and deleted inside `release` if `a` is an even number.

9. (Intermediate) Explain the bug or issue with the code below, or providing a convincing argument that none exists:

```c++
int* generate(int n, int bound) {
        int* arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % bound;
        }
        return arr;
}

int main() {
    int* result;
    for (int x = 1; x <= 100000; x++) {
        result = generate(x, x);
        for (int i = 0; i < x; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    delete[] result;
    return 0;
}
```
