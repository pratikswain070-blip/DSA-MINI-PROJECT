// Student Academic Portal - DSA Case Study
// ============================================================================
// GROUP 7: ROLE-BASED DEVELOPMENT SYSTEM
// ============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

// ==================== SHARED STUDENT STRUCTURE ====================
struct Student {
    int id;
    string name;
    float gpa;
    int semester;
    string department;
};

// ============================================================================
//                                👥 SECTION 1: Mahek
//        CONCEPTS: Arrays (vector), Linked Lists, File Organization
// ============================================================================

// --- Array (vector) Storage ---
vector<Student> students;

void addStudent(Student s) {
    students.push_back(s);
    cout << "  Added: " << s.name << endl;
}

void displayStudents() {
    if (students.empty()) { cout << "  No students.\n"; return; }
    cout << "  ID\tName\t\tGPA\tSem\tDept\n  " << string(45,'-') << endl;
    for (auto s : students)
        cout << "  " << s.id << "\t" << s.name << "\t\t" << s.gpa << "\t" << s.semester << "\t" << s.department << endl;
}

// --- Custom Linked List ---
struct ListNode {
    Student data;
    ListNode* next;
};
ListNode* head = NULL;

void insertToList(Student s) {
    ListNode* node = new ListNode;
    node->data = s;
    node->next = head;
    head = node;
}

void deleteFromList(int id) {
    if (!head) { cout << "  List empty.\n"; return; }
    if (head->data.id == id) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        cout << "  Deleted ID " << id << endl; return;
    }
    for (ListNode* curr = head; curr->next; curr = curr->next) {
        if (curr->next->data.id == id) {
            ListNode* temp = curr->next;
            curr->next = temp->next;
            delete temp;
            cout << "  Deleted ID " << id << endl; return;
        }
    }
    cout << "  Not found.\n";
}

void displayList() {
    if (!head) { cout << "  List empty.\n"; return; }
    for (ListNode* c = head; c; c = c->next)
        cout << "  -> " << c->data.name << " (ID:" << c->data.id << ")" << endl;
}

// --- Sequential File Organization ---
void saveFile() {
    ofstream f("students.dat");
    for (auto s : students)
        f << s.id << "|" << s.name << "|" << s.gpa << "|" << s.semester << "|" << s.department << endl;
    f.close();
    cout << "  Saved " << students.size() << " records.\n";
}

void loadFile() {
    ifstream f("students.dat");
    if (!f) { cout << "  File not found.\n"; return; }
    students.clear();
    string line;
    while (getline(f, line)) {
        Student s;
        int p1=line.find('|'), p2=line.find('|',p1+1), p3=line.find('|',p2+1), p4=line.find('|',p3+1);
        s.id = stoi(line.substr(0, p1));
        s.name = line.substr(p1+1, p2-p1-1);
        s.gpa = stof(line.substr(p2+1, p3-p2-1));
        s.semester = stoi(line.substr(p3+1, p4-p3-1));
        s.department = line.substr(p4+1);
        students.push_back(s);
    }
    f.close();
    cout << "  Loaded " << students.size() << " records.\n";
}

// --- Indexed File Organization ---
void saveIndexed() {
    ofstream data("students_data.dat"), idx("students.idx");
    for (auto s : students) {
        long pos = data.tellp();
        data << s.id << "|" << s.name << "|" << s.gpa << "|" << s.semester << "|" << s.department << endl;
        idx << s.id << " " << pos << endl;
    }
    data.close(); idx.close();
    cout << "  Saved indexed files.\n";
}

void searchIndexed(int id) {
    ifstream idx("students.idx");
    if (!idx) { cout << "  Index not found.\n"; return; }
    int rid; long pos; bool found = false;
    while (idx >> rid >> pos) if (rid == id) { found = true; break; }
    idx.close();
    if (!found) { cout << "  Not in index.\n"; return; }
    ifstream data("students_data.dat");
    data.seekg(pos);
    string line; getline(data, line); data.close();
    cout << "  Found: " << line << endl;
}

// ============================================================================
//                                👥 SECTION 2: DHRUV
//        CONCEPTS: Stack (Undo), Queue (Tasks), Searching
// ============================================================================

// --- Stack (Undo) ---
stack<string> undoStack;

void pushUndo(string action) { undoStack.push(action); }

void undoLast() {
    if (undoStack.empty()) { cout << "  Nothing to undo.\n"; return; }
    cout << "  Undo: " << undoStack.top() << endl;
    undoStack.pop();
}

// --- Queue (Tasks) ---
queue<string> taskQueue;

void addTask(string task) { taskQueue.push(task); cout << "  Task added: " << task << endl; }

void processTask() {
    if (taskQueue.empty()) { cout << "  No tasks.\n"; return; }
    cout << "  Processing: " << taskQueue.front() << endl;
    taskQueue.pop();
}

void showTasks() {
    if (taskQueue.empty()) { cout << "  No tasks.\n"; return; }
    queue<string> temp = taskQueue;
    int i = 1;
    while (!temp.empty()) { cout << "  " << i++ << ". " << temp.front() << endl; temp.pop(); }
}

// --- Searching Algorithms ---
void linearSearch(int id) {
    for (int i = 0; i < students.size(); i++)
        if (students[i].id == id) {
            cout << "  Found: " << students[i].name << " (GPA:" << students[i].gpa << ")" << endl; return;
        }
    cout << "  Not found.\n";
}

void binarySearch(int id) {
    vector<Student> sorted = students;
    sort(sorted.begin(), sorted.end(), [](Student a, Student b) { return a.id < b.id; });
    int low = 0, high = sorted.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (sorted[mid].id == id) {
            cout << "  Found: " << sorted[mid].name << " (GPA:" << sorted[mid].gpa << ")" << endl; return;
        }
        if (sorted[mid].id < id) low = mid + 1;
        else high = mid - 1;
    }
    cout << "  Not found.\n";
}

// ============================================================================
//                                👥 SECTION 3: PRANAV
//        CONCEPTS: Sorting Algorithms + Complexity Analysis (Big O)
// ============================================================================

// Bubble Sort - O(n^2) - repeatedly swaps adjacent if out of order
void bubbleSort() {
    vector<Student> t = students;
    for (int i = 0; i < t.size()-1; i++)
        for (int j = 0; j < t.size()-i-1; j++)
            if (t[j].id > t[j+1].id) swap(t[j], t[j+1]);
    cout << "  Bubble Sort (by ID):\n";
    for (auto s : t) cout << "  " << s.id << " " << s.name << " " << s.gpa << endl;
}

// Selection Sort - O(n^2) - finds minimum elements sequentially
void selectionSort() {
    vector<Student> t = students;
    for (int i = 0; i < t.size()-1; i++) {
        int m = i;
        for (int j = i+1; j < t.size(); j++) if (t[j].gpa < t[m].gpa) m = j;
        swap(t[i], t[m]);
    }
    cout << "  Selection Sort (by GPA):\n";
    for (auto s : t) cout << "  " << s.id << " " << s.name << " " << s.gpa << endl;
}

// Insertion Sort - O(n^2) - inserts each into its relative position
void insertionSort() {
    vector<Student> t = students;
    for (int i = 1; i < t.size(); i++) {
        Student key = t[i]; int j = i - 1;
        while (j >= 0 && t[j].gpa > key.gpa) { t[j+1] = t[j]; j--; }
        t[j+1] = key;
    }
    cout << "  Insertion Sort (by GPA):\n";
    for (auto s : t) cout << "  " << s.id << " " << s.name << " " << s.gpa << endl;
}

// Merge Sort - O(n log n) - divide and merge subproblems
vector<Student> mergeTemp;
void mergeParts(int l, int m, int r) {
    vector<Student> left(mergeTemp.begin()+l, mergeTemp.begin()+m+1);
    vector<Student> right(mergeTemp.begin()+m+1, mergeTemp.begin()+r+1);
    int i=0, j=0, k=l;
    while (i < left.size() && j < right.size())
        mergeTemp[k++] = (left[i].id <= right[j].id) ? left[i++] : right[j++];
    while (i < left.size()) mergeTemp[k++] = left[i++];
    while (j < right.size()) mergeTemp[k++] = right[j++];
}
void mergeSort(int l, int r) {
    if (l >= r) return;
    int m = (l+r)/2;
    mergeSort(l, m);
    mergeSort(m+1, r);
    mergeParts(l, m, r);
}

// Quick Sort - O(n log n) average - partitioning pivot swaps
vector<Student> quickTemp;
int partition(int lo, int hi) {
    int pivot = quickTemp[hi].id, i = lo - 1;
    for (int j = lo; j < hi; j++)
        if (quickTemp[j].id < pivot) swap(quickTemp[++i], quickTemp[j]);
    swap(quickTemp[i+1], quickTemp[hi]);
    return i + 1;
}
void quickSort(int lo, int hi) {
    if (lo < hi) { int p = partition(lo,hi); quickSort(lo,p-1); quickSort(p+1,hi); }
}

void sortMenu() {
    if (students.empty()) { cout << "  No data.\n"; return; }
    cout << "  1.Bubble  2.Selection  3.Insertion  4.Merge  5.Quick\n  Choice: ";
    int ch; cin >> ch;
    switch (ch) {
        case 1: bubbleSort(); break;
        case 2: selectionSort(); break;
        case 3: insertionSort(); break;
        case 4:
            mergeTemp = students; mergeSort(0, mergeTemp.size()-1);
            cout << "  Merge Sort (by ID):\n";
            for (auto s : mergeTemp) cout << "  " << s.id << " " << s.name << " " << s.gpa << endl;
            break;
        case 5:
            quickTemp = students; quickSort(0, quickTemp.size()-1);
            cout << "  Quick Sort (by ID):\n";
            for (auto s : quickTemp) cout << "  " << s.id << " " << s.name << " " << s.gpa << endl;
            break;
        default: cout << "  Invalid.\n";
    }
}

// ============================================================================
//                                👥 SECTION 4: Pratik
//        CONCEPTS: Trees (BST/AVL), Graphs (BFS/DFS), DP, Greedy
// ============================================================================

// --- Binary Search Tree (BST) ---
struct BSTNode {
    Student data;
    BSTNode *left, *right;
    BSTNode(Student s) { data = s; left = right = NULL; }
};
BSTNode* bstRoot = NULL;

BSTNode* insertBST(BSTNode* root, Student s) {
    if (!root) return new BSTNode(s);
    if (s.id < root->data.id) root->left = insertBST(root->left, s);
    else root->right = insertBST(root->right, s);
    return root;
}

void inorderBST(BSTNode* root) {
    if (!root) return;
    inorderBST(root->left);
    cout << "  ID:" << root->data.id << " " << root->data.name << " GPA:" << root->data.gpa << endl;
    inorderBST(root->right);
}

BSTNode* searchBST(BSTNode* root, int id) {
    if (!root || root->data.id == id) return root;
    return (id < root->data.id) ? searchBST(root->left, id) : searchBST(root->right, id);
}

void printTree(BSTNode* root, int space = 0) {
    if (!root) return;
    space += 5;
    printTree(root->right, space);
    cout << endl; for (int i = 5; i < space; i++) cout << " "; cout << root->data.id << endl;
    printTree(root->left, space);
}

// --- AVL Tree (Self Balancing) ---
struct AVLNode {
    Student data;
    AVLNode *left, *right;
    int height;
    AVLNode(Student s) { data = s; left = right = NULL; height = 1; }
};

int getHeight(AVLNode* n) { return n ? n->height : 0; }
int getBalance(AVLNode* n) { return n ? getHeight(n->left) - getHeight(n->right) : 0; }

AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    y->left = x->right; x->right = y;
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    return x;
}
AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    x->right = y->left; y->left = x;
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    return y;
}

AVLNode* insertAVL(AVLNode* node, Student s) {
    if (!node) return new AVLNode(s);
    if (s.id < node->data.id) node->left = insertAVL(node->left, s);
    else if (s.id > node->data.id) node->right = insertAVL(node->right, s);
    else return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bal = getBalance(node);
    if (bal > 1 && s.id < node->left->data.id) return rotateRight(node);       // LL
    if (bal < -1 && s.id > node->right->data.id) return rotateLeft(node);      // RR
    if (bal > 1 && s.id > node->left->data.id)                                // LR
        { node->left = rotateLeft(node->left); return rotateRight(node); }
    if (bal < -1 && s.id < node->right->data.id)                              // RL
        { node->right = rotateRight(node->right); return rotateLeft(node); }
    return node;
}
AVLNode* avlRoot = NULL;

void inorderAVL(AVLNode* root) {
    if (!root) return;
    inorderAVL(root->left);
    cout << "  ID:" << root->data.id << " " << root->data.name
         << " GPA:" << root->data.gpa << " h=" << root->height << endl;
    inorderAVL(root->right);
}

// --- Basic Graphs (Adjacency Lists & DFS/BFS) ---
const int COURSES = 6;
vector<int> graph[COURSES];
string courseName[] = {"Math", "Physics", "DSA", "DBMS", "OS", "Networks"};

void initGraph() {
    graph[0].push_back(1); graph[0].push_back(2); // Math -> Physics, DSA
    graph[2].push_back(3); graph[2].push_back(4); // DSA -> DBMS, OS
    graph[1].push_back(4); graph[4].push_back(5); // Physics -> OS, OS -> Networks
}

void BFS(int start) {
    bool visited[COURSES] = {false};
    queue<int> q;
    q.push(start); visited[start] = true;
    cout << "  BFS: ";
    while (!q.empty()) {
        int node = q.front(); q.pop();
        cout << courseName[node] << " -> ";
        for (int next : graph[node])
            if (!visited[next]) { visited[next] = true; q.push(next); }
    }
    cout << "END" << endl;
}

void DFS(int node, bool visited[]) {
    visited[node] = true;
    cout << courseName[node] << " -> ";
    for (int next : graph[node])
        if (!visited[next]) DFS(next, visited);
}

// --- Dynamic Programming (GPA trends) ---
void dpGPATrend() {
    if (students.empty()) { cout << "  No data.\n"; return; }
    int n = students.size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (students[j].gpa <= students[i].gpa)
                dp[i] = max(dp[i], dp[j] + 1);
    int maxLen = *max_element(dp.begin(), dp.end());
    cout << "  GPAs: ";
    for (auto s : students) cout << s.gpa << " ";
    cout << "\n  Longest improving trend = " << maxLen << " students" << endl;
}

// --- Greedy Algorithms (Activity Scheduling) ---
void greedySchedule() {
    struct Event { string name; int start, end; };
    Event ev[] = {{"Workshop",9,11},{"Seminar",10,12},{"Lab",11,13},
                  {"Lecture",12,14},{"Tutorial",13,15},{"Club",14,16}};
    cout << "  Available:\n";
    for (int i = 0; i < 6; i++)
    cout << "    " << ev[i].name << " [" << ev[i].start << "-" << ev[i].end << "]\n";
    cout << "  Selected (no overlaps):\n";
    int lastEnd = 0;
    for (int i = 0; i < 6; i++)
        if (ev[i].start >= lastEnd) { cout << "    -> " << ev[i].name << endl; lastEnd = ev[i].end; }
}

// ============================================================================
//                                ⚙️ GENERAL SYSTEM CONTROLLER
// ============================================================================

Student inputStudent() {
    Student s;
    cout << "  ID: "; cin >> s.id;
    cout << "  Name: "; cin >> s.name;
    cout << "  GPA: "; cin >> s.gpa;
    cout << "  Semester: "; cin >> s.semester;
    cout << "  Department: "; cin >> s.department;
    return s;
}

void studentDatabaseMenu() {
    int choice;
    do {
        cout << "\n========================================\n";
        cout << "   STUDENT DATABASE & LISTS\n";
        cout << "========================================\n";
        cout << "  1. Add Student (Vector, Tree, List)\n";
        cout << "  2. Show Students (Vector Database)\n";
        cout << "  3. Add to Linked List (Custom List)\n";
        cout << "  4. Show Linked List\n";
        cout << "  5. Delete from Linked List\n";
        cout << "  0. Back to Main Menu\n";
        cout << "  Choice: "; cin >> choice;

        switch (choice) {
        case 1: {
            Student s = inputStudent();
            addStudent(s);
            bstRoot = insertBST(bstRoot, s);
            avlRoot = insertAVL(avlRoot, s);
            insertToList(s);
            pushUndo("Added " + s.name);
            break;
        }
        case 2: displayStudents(); break;
        case 3: { Student s = inputStudent(); insertToList(s); break; }
        case 4: displayList(); break;
        case 5: { int id; cout << "  ID to Delete: "; cin >> id; deleteFromList(id); break; }
        case 0: break;
        default: cout << "  Invalid choice.\n";
        }
    } while (choice != 0);
}

void undoTaskManagerMenu() {
    int choice;
    do {
        cout << "\n========================================\n";
        cout << "   UNDO & TASK MANAGER\n";
        cout << "========================================\n";
        cout << "  1. Undo Last Action (Stack)\n";
        cout << "  2. Add Task (Queue)\n";
        cout << "  3. Process Task (Queue)\n";
        cout << "  4. Show Pending Tasks\n";
        cout << "  0. Back to Main Menu\n";
        cout << "  Choice: "; cin >> choice;

        switch (choice) {
        case 1: undoLast(); break;
        case 2: { string t; cout << "  Enter Task: "; cin.ignore(); getline(cin,t); addTask(t); break; }
        case 3: processTask(); break;
        case 4: showTasks(); break;
        case 0: break;
        default: cout << "  Invalid choice.\n";
        }
    } while (choice != 0);
}

void searchSortMenu() {
    int choice;
    do {
        cout << "\n========================================\n";
        cout << "   SEARCH & SORT OPERATIONS\n";
        cout << "========================================\n";
        cout << "  1. Linear Search (Unsorted)\n";
        cout << "  2. Binary Search (Sorted)\n";
        cout << "  3. Sorting Menu (Bubble, Merge, Quick, etc.)\n";
        cout << "  0. Back to Main Menu\n";
        cout << "  Choice: "; cin >> choice;

        switch (choice) {
        case 1: { int id; cout << "  ID to Search: "; cin >> id; linearSearch(id); break; }
        case 2: { int id; cout << "  ID to Search: "; cin >> id; binarySearch(id); break; }
        case 3: sortMenu(); break;
        case 0: break;
        default: cout << "  Invalid choice.\n";
        }
    } while (choice != 0);
}

void treesGraphsMenu() {
    int choice;
    do {
        cout << "\n========================================\n";
        cout << "   TREES & GRAPHS\n";
        cout << "========================================\n";
        cout << "  1. BST Inorder & Visual Tree View\n";
        cout << "  2. BST Search\n";
        cout << "  3. AVL Balanced Tree Inorder View\n";
        cout << "  4. Graph Course Prerequisites View\n";
        cout << "  5. BFS Traversal\n";
        cout << "  6. DFS Traversal\n";
        cout << "  0. Back to Main Menu\n";
        cout << "  Choice: "; cin >> choice;

        switch (choice) {
        case 1:
            cout << "  BST Inorder:\n"; inorderBST(bstRoot);
            cout << "\n  Tree structure:\n"; printTree(bstRoot); break;
        case 2: {
            int id; cout << "  ID to BST Search: "; cin >> id;
            BSTNode* res = searchBST(bstRoot, id);
            if (res) cout << "  Found: " << res->data.name << " GPA=" << res->data.gpa << endl;
            else cout << "  Not found.\n"; break;
        }
        case 3: cout << "  AVL Inorder:\n"; inorderAVL(avlRoot); break;
        case 4:
            cout << "  Course Prerequisites:\n";
            for (int i = 0; i < COURSES; i++) {
                cout << "  " << courseName[i] << " -> ";
                for (int j : graph[i]) cout << courseName[j] << " ";
                cout << endl;
            } break;
        case 5: {
            cout << "  Courses: ";
            for (int i=0;i<COURSES;i++) cout << i << "=" << courseName[i] << " ";
            cout << "\n  Start Node Index: "; int s; cin >> s;
            if (s>=0 && s<COURSES) BFS(s); break;
        }
        case 6: {
            cout << "  Courses: ";
            for (int i=0;i<COURSES;i++) cout << i << "=" << courseName[i] << " ";
            cout << "\n  Start Node Index: "; int s; cin >> s;
            if (s>=0 && s<COURSES) { bool v[COURSES]={}; cout<<"  DFS: "; DFS(s,v); cout<<"END\n"; }
            break;
        }
        case 0: break;
        default: cout << "  Invalid choice.\n";
        }
    } while (choice != 0);
}

void fileOperationsMenu() {
    int choice;
    do {
        cout << "\n========================================\n";
        cout << "   FILE OPERATIONS\n";
        cout << "========================================\n";
        cout << "  1. Save File (Sequential)\n";
        cout << "  2. Load File (Sequential)\n";
        cout << "  3. Save File (Indexed)\n";
        cout << "  4. Search Indexed File\n";
        cout << "  0. Back to Main Menu\n";
        cout << "  Choice: "; cin >> choice;

        switch (choice) {
        case 1: saveFile(); break;
        case 2: loadFile(); break;
        case 3: saveIndexed(); break;
        case 4: { int id; cout << "  ID to Search in Index: "; cin >> id; searchIndexed(id); break; }
        case 0: break;
        default: cout << "  Invalid choice.\n";
        }
    } while (choice != 0);
}

void advancedAlgorithmsMenu() {
    int choice;
    do {
        cout << "\n========================================\n";
        cout << "   ADVANCED ALGORITHMS\n";
        cout << "========================================\n";
        cout << "  1. Dynamic Programming: GPA Trend (LIS)\n";
        cout << "  2. Greedy: Course Activity Schedule\n";
        cout << "  0. Back to Main Menu\n";
        cout << "  Choice: "; cin >> choice;

        switch (choice) {
        case 1: dpGPATrend(); break;
        case 2: greedySchedule(); break;
        case 0: break;
        default: cout << "  Invalid choice.\n";
        }
    } while (choice != 0);
}

int main() {
    initGraph();
    int choice;
    do {
        cout << "\n========================================\n";
        cout << "      STUDENT ACADEMIC PORTAL\n";
        cout << "========================================\n";
        cout << "  1. Student Database & List Operations\n";
        cout << "  2. Undo System & Task Manager (Stack/Queue)\n";
        cout << "  3. Search & Sort Operations\n";
        cout << "  4. Trees & Graphs (BST, AVL, Traversals)\n";
        cout << "  5. File Operations (Save/Load/Index)\n";
        cout << "  6. Advanced Algorithms (DP/Greedy)\n";
        cout << "  7. Load Sample Dataset\n";
        cout << "  0. Exit Portal\n";
        cout << "  Choice: "; cin >> choice;

        switch (choice) {
        case 1: studentDatabaseMenu(); break;
        case 2: undoTaskManagerMenu(); break;
        case 3: searchSortMenu(); break;
        case 4: treesGraphsMenu(); break;
        case 5: fileOperationsMenu(); break;
        case 6: advancedAlgorithmsMenu(); break;
        case 7: {
            Student samples[] = {
                {101,"Pratik",8.5,4,"CSE"}, {102,"Dhruv",7.8,3,"IT"},
                {103,"Pranav",9.1,5,"CSE"}, {104,"Mahek",6.9,2,"ECE"},
                {105,"Rahul",7.5,4,"ME"},   {106,"Sneha",9.4,6,"CSE"},
                {107,"Arjun",8.2,3,"IT"},   {108,"Pooja",7.0,2,"ECE"}
            };
            for (int i = 0; i < 8; i++) {
                addStudent(samples[i]);
                bstRoot = insertBST(bstRoot, samples[i]);
                avlRoot = insertAVL(avlRoot, samples[i]);
                insertToList(samples[i]);
                pushUndo("Added " + samples[i].name);
            }
            cout << "  8 samples loaded!\n"; break;
        }
        case 0: cout << "  Goodbye!\n"; break;
        default: cout << "  Invalid choice.\n";
        }
    } while (choice != 0);
    return 0;
}