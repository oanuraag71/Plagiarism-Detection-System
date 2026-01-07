# Plagiarism-Detection-System

## Overview
A plagiarism detection system implemented in **C** using the **KMP (Knuth-Morris-Pratt)** string matching algorithm. This is an academic project for the **Design & Analysis of Algorithms (DAA)** course demonstrating pattern matching, algorithmic complexity analysis, and efficient string searching.

## Algorithm: KMP (Knuth-Morris-Pratt)

KMP is an efficient string matching algorithm that avoids unnecessary comparisons by using a pre-computed failure function (LPS array).

### How It Works:
1. **LPS Array (Longest Proper Prefix which is also Suffix)**
   - Preprocessing step that identifies overlapping patterns within the pattern string
   - Helps skip unnecessary comparisons during matching
   - Time: O(m) where m = pattern length

2. **Pattern Matching**
   - Uses LPS array to determine when to shift the pattern
   - Avoids re-comparing characters that already match
   - Time: O(n) where n = text length

### Overall Complexity Analysis:
- **Time Complexity**: **O(n + m)**
  - Preprocessing: O(m)
  - Matching: O(n)
  - Total: O(n + m)
  - Much better than Naive O(n*m)

- **Space Complexity**: **O(m)** for the LPS array

## Features

✅ **Efficient Pattern Matching** - O(n + m) time complexity  
✅ **LPS Array Computation** - Optimal failure function preprocessing  
✅ **Multiple Pattern Occurrences** - Finds all plagiarized sections  
✅ **Dynamic Memory Allocation** - Handles large text files  
✅ **Clear Output** - Shows starting indices of plagiarized content  
✅ **Educational** - Well-commented code explaining each step  

## Project Structure
```
├── plagiarism_detector.c      # KMP implementation for plagiarism detection
├── README.md                  # Documentation
└── Makefile (optional)        # Build configuration
```

## Key Functions

### 1. `computeLPS(char *pattern, int m, int *lps)`
- Builds the Longest Proper Prefix which is also Suffix (LPS) array
- Identifies when pattern can safely shift during matching
- **Complexity**: O(m)

### 2. `kmpSearch(char *text, char *pattern)`
- Main KMP search function that finds all pattern occurrences
- Uses LPS array to optimize comparisons
- Returns 1 if pattern found, 0 otherwise
- Prints all starting indices of matches
- **Complexity**: O(n + m)

### 3. `main()`
- Reads text and pattern from user input
- Calls kmpSearch() and displays results
- Returns -1 if no plagiarism detected

## Compilation

```bash
# Simple compilation
gcc -o plagiarism_detector plagiarism_detector.c

# With debugging symbols
gcc -g -o plagiarism_detector plagiarism_detector.c

# With optimizations
gcc -O2 -o plagiarism_detector plagiarism_detector.c
```

## Usage

```bash
./plagiarism_detector

Enter text: The quick brown fox jumps over the lazy dog. The lazy dog sleeps.
Enter pattern: lazy dog
Pattern found at index: 36
Pattern found at index: 50
```

## Example: How KMP Works

**Text**: "ABCCDDEFF ABCD"  
**Pattern**: "ABCD"

1. **LPS Array for "ABCD"**: [0, 0, 0, 0] (no proper prefix = suffix)
2. **Matching**:
   - Matches "ABC" then fails at 'D' vs ' '
   - Shifts pattern by 1 (no optimization here since LPS[2]=0)
   - Eventually finds "ABCD" at index 9

**Without KMP** (Naive approach):
- Would restart comparison from beginning each time
- Multiple unnecessary comparisons

**With KMP**:
- Uses LPS array to skip ahead
- Much faster on large texts with repeated patterns

## Plagiarism Detection Application

### Use Cases:
1. **Document Comparison** - Find copied content between documents
2. **Code Plagiarism Detection** - Identify duplicated code snippets
3. **Content Verification** - Check for unauthorized copying
4. **Academic Integrity** - Detect plagiarized assignments

### Real-World Example:
```
Student A's submission: "The mitochondria is the powerhouse of the cell..."
Student B's submission: "The powerhouse of the cell is the mitochondria..."

System detects: "the cell is the", "mitochondria is the powerhouse"
as common substrings → potential plagiarism detected!
```

## Advantages of KMP

✅ **Linear Time** - O(n + m) vs naive O(n*m)  
✅ **No Backtracking** - Text pointer never moves backward  
✅ **Optimal for Long Patterns** - Scales well with pattern complexity  
✅ **Deterministic** - Always produces same result  
✅ **Space-Efficient** - Only needs LPS array (O(m))  

## Limitations

⚠️ Only handles **exact matches** (case-sensitive)  
⚠️ Doesn't detect **semantic plagiarism** (paraphrased content)  
⚠️ Limited to **single pattern** (can be extended for multiple)  
⚠️ **Large memory files** may need chunked processing  

## Future Enhancements

- Implement **Rabin-Karp** algorithm (polynomial hashing)
- Support **case-insensitive** matching
- Add **regex pattern** support
- Implement **Aho-Corasick** for multiple pattern search
- Build **semantic plagiarism** detection using NLP
- Create **web interface** for easy access
- Add **batch file** processing
- Integrate with **plagiarism databases**

## Learning Outcomes

✅ Understanding **string matching algorithms**  
✅ **Algorithm complexity analysis** (Big-O notation)  
✅ **Dynamic programming** concepts (LPS computation)  
✅ **Memory management** in C  
✅ **Preprocessing optimization** techniques  
✅ **Real-world applications** of algorithms  

## References

1. Knuth, D. E., Morris Jr., J. H., & Pratt, V. R. (1977). "Fast pattern matching in strings"
2. Cormen, T. H., et al. (2009). "Introduction to Algorithms" (3rd ed.)
3. Sedgewick, R., & Wayne, K. (2011). "Algorithms" (4th ed.)

## Author

**Anuraag Oruganti**  
B.Tech CSE, 2nd Year  
Design & Analysis of Algorithms Project  
Interested in Algorithm Design & Competitive Programming

## License

This project is provided as-is for educational purposes. Free to use and modify for learning.

---

**Note**: This implementation focuses on **algorithmic efficiency** and **educational value**. For production plagiarism detection, consider using established tools like Turnitin, Copyscape, or building upon advanced NLP models.
