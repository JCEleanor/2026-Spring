- Using the operator **&** , we can obtain the address of the value stored in a variable. The address
  can be stored in a **pointer** variable.

- Using the operator **\*** , known as the **dereference** operator, we can get or set the value pointed to by a pointer.

- Array variables are secretly **pointers**; however, describe one difference: **array can not be reassigned to a different memory location (while pointers can be reassigned to different address)**

- To the compiler, `p[j]` is equivalent to **\*(p+j)**.

- If `p` is an `int*`, and p = 0x1000, what is the value p + 3? **0x100C**

- The memory segment containing the function call stack is generally called the **stack**.

- Dynamically allocated memory for C++ comes from the **free store**.

- The **new** operator is used to dynamically allocate memory; the result of the operation is a **pointer** to the memory.

- The **delete** operator is used to deallocate dynamically allocated memory.
- Name two types of pointer you should never try to dereference: **nullptr/NULL and dangling pointers**.

- If your program regularly loses pointers to dynamically allocated memory, your program may have this kind of memory error: **memory leak**.

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

There's no issue if the intention is to delete `x`. `x` will be deleted inside `main` if `a` is an odd number, and deleted inside `release` if `a` is an even number.
