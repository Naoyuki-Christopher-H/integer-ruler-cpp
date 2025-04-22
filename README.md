# **Minimal Ruler Finder**

This program calculates the fewest number of marks needed on a ruler to measure all integer distances from 1 to a specified length `X`. It uses a backtracking algorithm to find the optimal solution, ensuring that the distances between marks are unique and can measure every integer from 1 to `X`.

## **Features**

- Calculates the fewest number of marks required to measure all distances from 1 to `X`.
- Uses a backtracking algorithm to try various combinations of marks until it finds the minimum set.
- Provides a simple interactive user interface to input the ruler length and display results.

---

## **How It Works**

The program solves the problem by placing marks on the ruler and recursively exploring all combinations of marks. It checks if the current set of marks can measure all the distances from 1 to `X` by calculating the pairwise differences between the marks. The solution finds the smallest number of marks needed to measure all distances uniquely.

---

## **Algorithm**

1. **Backtracking**: The algorithm starts by placing the first mark at 0 (the starting point of the ruler). It then attempts to place subsequent marks in all possible positions. For each combination of marks, it checks if all distances from 1 to `X` can be measured.
   
2. **Validation**: For each set of marks, the algorithm calculates all pairwise differences between the marks and ensures that all integer distances from 1 to `X` are represented.

3. **Optimization**: The algorithm tries solutions with the smallest number of marks first, ensuring that the first valid solution found is the one with the fewest marks.

---

## **Usage**

### **Input**
- The user is prompted to enter the integer length `X` of the ruler.

### **Output**
- The program outputs the fewest number of marks required to measure all distances from 1 to `X`.
- It also displays the positions of the marks on the ruler.

### **Example**

**Input:**
```
Enter the integer length of the ruler (X): 6
```

**Output:**
```
Fewest marks needed: 4
Marks on the ruler: 0, 1, 4, 6
```

In this example, the program finds that 4 marks (at positions 0, 1, 4, and 6) are enough to measure all distances from 1 to 6.

---

## **Building and Running the Program**

### **Prerequisites**

You need a C++ compiler (like `g++`) that supports C++11 or later. You also need a basic understanding of how to compile and run C++ programs.

### **Steps to Compile and Run**

1. **Clone this repository**:
   If you haven't already cloned this repository, you can do so by running:
   ```bash
   git clone https://github.com/Naoyuki-Christopher-H/integer-ruler-cpp.git
   cd integer-ruler-cpp
   ```

2. **Compile the program**:
   To compile the program, run the following command:
   ```bash
   g++ -std=c++11 -o minimal_ruler minimal_ruler.cpp
   ```

3. **Run the program**:
   After compilation, run the program with the following command:
   ```bash
   ./minimal_ruler
   ```

4. **Enter the ruler length**:
   The program will prompt you to enter the integer length of the ruler (`X`). After you provide the input, it will display the fewest marks and their positions.

---

## **Code Structure**

### **Files**

- **minimal_ruler.cpp**: The main program that implements the backtracking algorithm and the logic to calculate the fewest marks for the ruler.
- **README.md**: This file, which explains how to use the program and build it.

### **Functions**
- **findFewestMarks**: The main function that tries to find the fewest marks needed to measure all distances from 1 to `X`.
- **backtrackRuler**: Initializes the backtracking process.
- **backtrack**: Recursively tries different combinations of marks to find the valid solution.
- **canMeasureAll**: Verifies if all distances from 1 to `X` can be measured with the current set of marks.

---

## **Contributing**

We welcome contributions to this project! If you would like to contribute, you can:
1. Fork the repository.
2. Create a new branch for your feature or fix.
3. Submit a pull request with a description of your changes.

---

## **Acknowledgements**

This algorithm is based on a classic backtracking approach to find optimal solutions to problems with constraints. It provides a clean and efficient way to solve the problem of measuring all distances with the fewest number of marks.

---
