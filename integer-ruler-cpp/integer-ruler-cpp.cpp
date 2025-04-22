#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

// Function declarations
vector<int> findFewestMarks(int length);
vector<int> backtrackRuler(int maxLength, int numMarks);
vector<int> backtrack(int nextStart, int maxLength, int numMarks, vector<int>& currentMarks);
bool canMeasureAll(const vector<int>& marks, int maxLength);

// Main function: Starts the program execution, prompts for input, and displays results
int main()
{
    int rulerLength;

    // Prompt the user for the length of the ruler (X)
    cout << "Enter the integer length of the ruler (X): ";
    cin >> rulerLength;

    // Calculate the fewest marks needed to measure all lengths from 1 to X
    vector<int> marks = findFewestMarks(rulerLength);

    // Output the number of marks and the actual marks on the ruler
    cout << "Fewest marks needed: " << marks.size() << endl;
    cout << "Marks on the ruler: ";
    for (size_t i = 0; i < marks.size(); ++i)
    {
        cout << marks[i];
        if (i != marks.size() - 1)
        {
            cout << ", "; // Print comma separator for marks
        }
    }
    cout << endl;

    return 0;
}

/**
 * findFewestMarks Function
 * -------------------------
 * This function attempts to find the fewest number of marks that can measure all integer distances from 1 to the given length (X).
 * It starts by trying 2 marks, then 3, and so on up to X + 1 marks, checking after each attempt if a valid ruler can be formed.
 * Once a valid ruler is found, the function returns the marks list.
 *
 * @param length The target ruler length (X).
 * @return A vector of integers representing the fewest marks required to measure all integer distances from 1 to X.
 */
vector<int> findFewestMarks(int length)
{
    // Iterate over possible numbers of marks (starting from 2 to length + 1)
    for (int markCount = 2; markCount <= length + 1; ++markCount)
    {
        // Try to generate a valid ruler with 'markCount' marks
        vector<int> result = backtrackRuler(length, markCount);
        if (!result.empty()) // If a valid ruler is found, return it
        {
            return result;
        }
    }

    // If no valid ruler is found (shouldn't happen for reasonable inputs), return an empty vector
    return {};
}

/**
 * backtrackRuler Function
 * -------------------------
 * Initializes the backtracking process by placing the first mark at 0, and recursively tries to build the rest of the marks.
 * It ensures that we only try placing marks from `nextStart` up to `maxLength`.
 *
 * @param maxLength The target ruler length (X).
 * @param numMarks The number of marks to try placing on the ruler.
 * @return A vector of integers representing a valid set of marks that can measure all integer distances from 1 to X.
 */
vector<int> backtrackRuler(int maxLength, int numMarks)
{
    vector<int> currentMarks;
    currentMarks.push_back(0); // Always include 0 as the first mark (starting point)

    // Start the recursive backtracking with the next possible mark being 1
    return backtrack(1, maxLength, numMarks, currentMarks);
}

/**
 * backtrack Function
 * -------------------
 * A recursive function that tries to place marks on the ruler. It explores all possible combinations of marks
 * and checks if a valid solution exists by invoking `canMeasureAll`.
 *
 * @param nextStart The next mark to consider placing (starting from 1).
 * @param maxLength The target ruler length (X).
 * @param numMarks The total number of marks to be placed on the ruler.
 * @param currentMarks The current set of marks that have been placed so far.
 * @return A vector of integers representing a valid set of marks that can measure all integer distances from 1 to X.
 */
vector<int> backtrack(int nextStart, int maxLength, int numMarks, vector<int>& currentMarks)
{
    // Base case: If we've placed the required number of marks, check if it's a valid solution
    if (currentMarks.size() == static_cast<size_t>(numMarks))
    {
        if (canMeasureAll(currentMarks, maxLength)) // Check if we can measure all distances from 1 to X
        {
            return currentMarks; // Return the valid solution
        }
        return {}; // No valid solution, backtrack
    }

    // Try placing the next mark, from 'nextStart' to 'maxLength'
    for (int i = nextStart; i <= maxLength; ++i)
    {
        currentMarks.push_back(i); // Try placing mark at position i

        // Recursively try to place the next mark
        vector<int> result = backtrack(i + 1, maxLength, numMarks, currentMarks);
        if (!result.empty()) // If a valid solution is found, return it
        {
            return result;
        }

        // Backtrack: Remove the last placed mark and try a different position
        currentMarks.pop_back();
    }

    return {}; // If no valid solution found, return empty vector
}

/**
 * canMeasureAll Function
 * ------------------------
 * This function checks if all integer distances from 1 to `maxLength` can be measured
 * using the current set of marks by comparing all pairwise differences between marks.
 *
 * @param marks A vector of integers representing the marks on the ruler.
 * @param maxLength The target ruler length (X).
 * @return True if all distances from 1 to X can be measured, false otherwise.
 */
bool canMeasureAll(const vector<int>& marks, int maxLength)
{
    unordered_set<int> diffs; // Set to store the unique pairwise differences

    // Generate all pairwise differences and store them in the 'diffs' set
    for (size_t i = 0; i < marks.size(); ++i)
    {
        for (size_t j = i + 1; j < marks.size(); ++j)
        {
            diffs.insert(abs(marks[j] - marks[i])); // Add the absolute difference between marks
        }
    }

    // Check if all distances from 1 to maxLength are present in the set of differences
    for (int i = 1; i <= maxLength; ++i)
    {
        if (diffs.find(i) == diffs.end()) // If any distance is missing, return false
        {
            return false;
        }
    }

    // If all distances are found, return true
    return true;
}
