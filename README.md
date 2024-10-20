### Basic data structures in C

## 1. **Singly Linked List** 

A singly linked list consists of nodes where each node contains data and a pointer to the next node.

```markdown
[ Head ] -> [ Data | Next ] -> [ Data | Next ] -> [ Data | Next ] -> NULL
```

## 2. **Doubly Linked List**

In a doubly linked list, each node points to both the previous node and the next node.

```markdown
[ Head ]
    |
    v
NULL <- [ Prev | Data | Next ] <-> [ Prev | Data | Next ] <-> [ Prev | Data | Next ] -> NULL

```

## 3. **Stack**

A stack operates on the LIFO (Last In, First Out) principle, where data is pushed onto the stack and the last entry is the first to be popped.

```markdown
          ______
          | Data 3 |
          | Data 2 |
          | Data 1 |
          |_________|
           (top)
```

## 4. **Queue**

A queue follows the FIFO (First In, First Out) principle, where data is enqueued at one end (rear) and dequeued at the other (front).

```markdown
[ head ] -> [ Data 1 ] -> [ Data 2 ] -> [ Data 3 ] -> [ tail ]
```

## Compilation
```bash
make
```

## Execution

```bash
./main
```
