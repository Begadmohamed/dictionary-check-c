# Word Verification Application 📖

This project implements a **Word Verification** system using the **C programming language**. The application checks the validity of words in an input sentence against a dictionary and suggests corrections for any incorrect words. The dictionary is managed as a **Binary Search Tree (BST)** for efficient word lookup.

---

## Features 🌟

1. **Word Verification**
   - Checks each word in the input sentence against a dictionary.
   - Identifies words that are not present in the dictionary.

2. **Suggestions for Incorrect Words**
   - Provides three suggestions for each incorrect word:
     1. **Predecessor:** Closest word alphabetically before the incorrect word.
     2. **Successor:** Closest word alphabetically after the incorrect word.
     3. **Last Node:** The last word visited in the BST before concluding the word does not exist.

3. **Binary Search Tree (BST)**
   - Efficiently stores and retrieves dictionary words.
   - Ensures quick word verification with minimal search time.

---

## Technologies Used 🛠️

- **C Programming Language**
  - Core concepts utilized:
    - **Binary Search Tree (BST):** For dictionary management.
    - **String Manipulation:** For word processing and comparison.
    - **Dynamic Memory Allocation:** To handle dictionary nodes.

---

## How It Works ⚙️

1. **Input:**
   - A sentence entered by the user.

2. **Word Verification:**
   - Each word in the sentence is checked against the dictionary (stored in a BST).

3. **Suggestions for Incorrect Words:**
   - If a word is not found in the dictionary, the system provides:
     - **Predecessor**
     - **Successor**
     - **Last Node**

4. **Output:**
   - Displays whether each word is correct or incorrect.
   - Provides suggestions for any incorrect words.
