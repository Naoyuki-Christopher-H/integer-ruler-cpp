#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <limits> // For numeric_limits

using namespace std;

/**
 * Function declarations
 */
vector<int> findFewestMarks(int length);
vector<int> backtrackRuler(int maxLength, int numMarks);
vector<int> backtrack(int nextStart, int maxLength, int numMarks, vector<int>& currentMarks);
bool canMeasureAll(const vector<int>& marks, int maxLength);

/**
 * Main function: Starts program execution.
 * - Prompts the user for input.
 * - Handles invalid input using exception handling.
 * - Displays the result: fewest marks and their positions.
 */
int main()
{
    int rulerLength;

    try
    {
        cout << "Enter the integer length of the ruler (X): ";

        // Validate input to ensure it's an integer
        if (!(cin >> rulerLength))
        {
            throw invalid_argument("Invalid input. Please enter a valid integer.");
        }

        // Input must be a positive integer
        if (rulerLength <= 0)
        {
            throw out_of_range("Ruler length must be a positive integer greater than zero.");
        }

        // Attempt to find the fewest marks to measure all distances from 1 to rulerLength
        vector<int> marks = findFewestMarks(rulerLength);

        // Output the result
        cout << "Fewest marks needed: " << marks.size() << endl;
        cout << "Marks on the ruler: ";
        for (size_t i = 0; i < marks.size(); ++i)
        {
            cout << marks[i];
            if (i != marks.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << endl;
    }
    catch (const exception& e)
    {
        // Catch any exceptions thrown during input or processing
        cerr << "Error: " << e.what() << endl;
        return 1; // Exit with error status
    }

    return 0; // Successful execution
}

/**
 * findFewestMarks Function
 * -------------------------
 * Attempts to find the minimal number of marks needed to measure all integer distances from 1 to 'length'.
 *
 * @param length The maximum distance (length of the ruler).
 * @return A vector containing the positions of the fewest marks that can measure all required distances.
 */
vector<int> findFewestMarks(int length)
{
    for (int markCount = 2; markCount <= length + 1; ++markCount)
    {
        vector<int> result = backtrackRuler(length, markCount);
        if (!result.empty())
        {
            return result; // Return first successful configuration
        }
    }

    return {}; // Return empty if no configuration found (should not occur for reasonable lengths)
}

/**
 * backtrackRuler Function
 * -------------------------
 * Initializes the recursive backtracking algorithm with the first mark at position 0.
 *
 * @param maxLength The length of the ruler.
 * @param numMarks The number of marks to place on the ruler.
 * @return A valid configuration of marks, or empty if none found.
 */
vector<int> backtrackRuler(int maxLength, int numMarks)
{
    vector<int> currentMarks;
    currentMarks.push_back(0); // The first mark is always at 0
    return backtrack(1, maxLength, numMarks, currentMarks); // Start backtracking from position 1
}

/**
 * backtrack Function
 * -------------------
 * Recursive function to place marks on the ruler and check for valid configurations.
 *
 * @param nextStart The next candidate position for a new mark.
 * @param maxLength The length of the ruler.
 * @param numMarks Total number of marks to be placed.
 * @param currentMarks The current list of placed marks.
 * @return A valid configuration of marks if found, or an empty vector otherwise.
 */
vector<int> backtrack(int nextStart, int maxLength, int numMarks, vector<int>& currentMarks)
{
    if (currentMarks.size() == static_cast<size_t>(numMarks))
    {
        if (canMeasureAll(currentMarks, maxLength))
        {
            return currentMarks; // Valid configuration
        }
        return {}; // Invalid configuration, backtrack
    }

    for (int i = nextStart; i <= maxLength; ++i)
    {
        currentMarks.push_back(i); // Add new mark

        vector<int> result = backtrack(i + 1, maxLength, numMarks, currentMarks);
        if (!result.empty())
        {
            return result; // Return if valid configuration found
        }

        currentMarks.pop_back(); // Remove last mark to try another position
    }

    return {}; // No valid configuration found in this path
}

/**
 * canMeasureAll Function
 * ------------------------
 * Checks if all integer distances from 1 to maxLength can be measured using the current marks.
 *
 * @param marks A vector containing the mark positions.
 * @param maxLength The maximum distance to check for.
 * @return True if all distances are measurable, false otherwise.
 */
bool canMeasureAll(const vector<int>& marks, int maxLength)
{
    unordered_set<int> diffs;

    // Generate all unique absolute differences between pairs of marks
    for (size_t i = 0; i < marks.size(); ++i)
    {
        for (size_t j = i + 1; j < marks.size(); ++j)
        {
            diffs.insert(abs(marks[j] - marks[i]));
        }
    }

    // Verify that all distances from 1 to maxLength are covered
    for (int i = 1; i <= maxLength; ++i)
    {
        if (diffs.find(i) == diffs.end())
        {
            return false; // Missing distance
        }
    }

    return true; // All distances measurable
}
