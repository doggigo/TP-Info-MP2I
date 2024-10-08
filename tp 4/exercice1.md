## Question 1

`incremente` incrémente la valeur vers laquelle pointe le pointeur p passé en argument

## Question 2

non

## Question 3

non, il faut changer set_null : 
```c
void set_null(int **p) {
  *p = NULL;
}
```
et changer son appel : 
```c
int main() {
  ...
  set_null(&ptr);
  ...
}
```

On pourrait faire ceci :
```c
typedef int* pointeur;
```

