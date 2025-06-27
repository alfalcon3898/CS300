# CS300
So the main problem I tackled in these projects was how to efficiently manage and display course information for an academic advising system. I needed to decide which data structures would best support fast insertion, searching, and printing operations, while also ensuring scalability and readability of the code.

To approach the problem, I began by exploring and implementing three different structures: a vector, a hash table, and a binary search tree. Each structure has different time and space trade-offs. I analyzed each for operations like insert and search, especially in worst-case scenarios. Ultimately, I chose a BST for the working version because it supports efficient alphanumeric sorting through in-order traversal, which aligned perfectly with the program's goals.

One challenge I encountered was reading and parsing CSV files with variable numbers of prerequisites. I handled this by using stringstream to tokenize the data, storing prerequisites in a vector, and then validating each one. Debugging tree insertion and course lookup also helped me improve my problem-solving skills with recursive functions and edge case handling.

These projects helped me grow in how I design software. So I now focus more on planning structure up front—choosing the right data structure early on saves a lot of time later. I've also learned the value of keeping functions modular and descriptive. My code is now more readable and maintainable, which will help me in both future classes and industry projects.
