# 🎓 Student Academic Portal

A menu-driven C++ application developed to demonstrate the practical implementation of Data Structures and Algorithms (DSA) concepts in a real-world academic management system.

---

# 📖 Project Description

The Student Academic Portal is designed to manage student records while demonstrating various DSA concepts including Arrays, Linked Lists, Stacks, Queues, Searching Algorithms, Sorting Algorithms, Trees, Graphs, File Organization, Dynamic Programming, and Greedy Algorithms.

The project integrates multiple DSA topics into a single application and provides a practical understanding of how different data structures solve different types of problems.

---

# 🏗️ System Architecture

```text
Student Academic Portal
│
├── Student Database
│   ├── Vector (Array)
│   └── Linked List
│
├── Undo & Task Manager
│   ├── Stack
│   └── Queue
│
├── Search & Sort
│   ├── Linear Search
│   ├── Binary Search
│   ├── Bubble Sort
│   ├── Selection Sort
│   ├── Insertion Sort
│   ├── Merge Sort
│   └── Quick Sort
│
├── Trees & Graphs
│   ├── BST
│   ├── AVL Tree
│   ├── BFS
│   └── DFS
│
├── File Handling
│   ├── Sequential File
│   └── Indexed File
│
└── Advanced Algorithms
    ├── Dynamic Programming
    └── Greedy Algorithm
```

---

# 🧩 Data Structures and Algorithms Used

---

## 1. Vector (Array)

### Implementation

```cpp
vector<Student> students;
```

### Purpose

Acts as the primary student database.

### Why Vector?

- Dynamic size
- Fast insertion at the end
- Easy traversal

### Used For

- Storing all student records
- Displaying student information
- Searching operations
- Sorting operations

### Time Complexity

| Operation | Complexity |
|------------|------------|
| Insert | O(1) |
| Access | O(1) |
| Search | O(n) |

---

## 2. Linked List

### Implementation

```cpp
struct ListNode
{
    Student data;
    ListNode* next;
};
```

### Purpose

Demonstrates dynamic memory allocation and linked storage.

### Used For

- Insert student records
- Delete student records
- Traverse records

### Advantages

- Dynamic size
- Efficient insertion/deletion

### Complexity

| Operation | Complexity |
|------------|------------|
| Insert at Beginning | O(1) |
| Delete | O(n) |
| Traverse | O(n) |

---

## 3. Stack (Undo System)

### Implementation

```cpp
stack<string> undoStack;
```

### Purpose

Stores user actions for undo functionality.

### Why Stack?

Stack follows:

```text
LIFO
(Last In First Out)
```

The most recent action is undone first.

### Example

```text
Added Dhruv
Added Rahul
Added Pratik
```

Undo Order:

```text
Pratik
Rahul
Dhruv
```

### Applications

- Undo/Redo Systems
- Browser History
- Function Calls

### Complexity

| Operation | Complexity |
|------------|------------|
| Push | O(1) |
| Pop | O(1) |
| Top | O(1) |

---

## 4. Queue (Task Manager)

### Implementation

```cpp
queue<string> taskQueue;
```

### Purpose

Manages pending tasks.

### Why Queue?

Queue follows:

```text
FIFO
(First In First Out)
```

### Example

Tasks:

```text
Upload Marks
Check Attendance
Generate Report
```

Processing Order:

```text
Upload Marks
Check Attendance
Generate Report
```

### Applications

- CPU Scheduling
- Printer Queue
- Ticket Booking Systems

### Complexity

| Operation | Complexity |
|------------|------------|
| Push | O(1) |
| Pop | O(1) |
| Front | O(1) |

---

## 5. Linear Search

### Purpose

Searches student records one by one.

### Working

Checks every student until the target ID is found.

### Example

```text
101
102
103
104
```

Search 103:

```text
101 ❌
102 ❌
103 ✅
```

### Complexity

```text
Best Case : O(1)
Worst Case: O(n)
```

### Use Case

Suitable for unsorted data.

---

## 6. Binary Search

### Purpose

Provides faster searching.

### Requirement

Data must be sorted.

### Working

Checks middle element and eliminates half of the search space.

### Example

```text
101 102 103 104 105 106 107 108
```

Search 106:

```text
Middle = 104

106 > 104

Discard Left Half

105 106 107 108

Middle = 106

Found
```

### Complexity

```text
O(log n)
```

### Advantage

Much faster than Linear Search.

---

## 7. Sorting Algorithms

Implemented Algorithms:

### Bubble Sort

- Compares adjacent elements
- Swaps if out of order

Complexity:

```text
O(n²)
```

---

### Selection Sort

- Finds minimum element
- Places it in correct position

Complexity:

```text
O(n²)
```

---

### Insertion Sort

- Inserts each element in proper position

Complexity:

```text
O(n²)
```

---

### Merge Sort

- Divide and Conquer
- Splits and merges arrays

Complexity:

```text
O(n log n)
```

---

### Quick Sort

- Uses pivot partitioning

Complexity:

```text
O(n log n) Average
```

---

## 8. Binary Search Tree (BST)

### Purpose

Store student records hierarchically.

### Example

```text
      103
     /   \
   101   105
```

### Operations

- Insert
- Search
- Inorder Traversal

### Complexity

```text
Average: O(log n)
Worst: O(n)
```

---

## 9. AVL Tree

### Purpose

Self-balancing BST.

### Advantage

Maintains balance automatically.

### Complexity

```text
Search : O(log n)
Insert : O(log n)
Delete : O(log n)
```

---

## 10. Graph

### Purpose

Represents course prerequisite relationships.

### Example

```text
Math → Physics
Math → DSA
DSA → DBMS
DSA → OS
```

---

## 11. BFS

### Purpose

Visits nodes level by level.

### Application

Course dependency traversal.

### Complexity

```text
O(V + E)
```

---

## 12. DFS

### Purpose

Visits nodes depth-wise.

### Complexity

```text
O(V + E)
```

---

## 13. Sequential File Organization

### Purpose

Store student data permanently.

### File

```text
students.dat
```

### Used For

- Save records
- Load records

---

## 14. Indexed File Organization

### Purpose

Faster file searching.

### Working

Stores:

```text
ID → File Position
```

Example:

```text
101 → 0
102 → 45
103 → 90
```

---

## 15. Dynamic Programming

### Implementation

Longest Increasing GPA Trend.

### Purpose

Find longest sequence of improving GPAs.

Example:

```text
6.5
7.0
7.8
8.2
```

Trend Length:

```text
4
```

---

## 16. Greedy Algorithm

### Purpose

Select maximum non-overlapping activities.

### Example

```text
Workshop
Seminar
Lab
Lecture
```

Greedy selects activities with no time conflicts.

---

# 👨‍💻 Team Contributions

## Mahek

- Vector
- Linked List
- Sequential Files
- Indexed Files

## Dhruv

- Stack
- Queue
- Linear Search
- Binary Search

## Pranav

- Bubble Sort
- Selection Sort
- Insertion Sort
- Merge Sort
- Quick Sort
- Complexity Analysis

## Pratik

- BST
- AVL Tree
- Graphs
- BFS
- DFS
- Dynamic Programming
- Greedy Algorithm

---

# ▶️ Compilation

```bash
g++ main.cpp -o portal
```

# ▶️ Execution

```bash
./portal
```

---

# 🎯 Learning Outcomes

- Practical implementation of DSA concepts
- Understanding searching and sorting techniques
- Tree and graph traversal algorithms
- File organization methods
- Dynamic Programming and Greedy approaches
- Development of a complete menu-driven application

---

# 📄 Academic Purpose

This project was developed as a Data Structures and Algorithms (DSA) Case Study for educational purposes.