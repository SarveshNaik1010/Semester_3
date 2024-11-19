#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STUDENTS 12

// Structure to represent each student and their subject
typedef struct {
    int id;
    char subject[20];
    bool isPaired;
} Student;

// Function to display pairs
void displayPairs(Student students[], int pairs[][2], int pairCount) {
    printf("Student Pairs:\n");
    for (int i = 0; i < pairCount; i++) {
        printf("Student %d (%s) --- Student %d (%s)\n",
               students[pairs[i][0]].id, students[pairs[i][0]].subject,
               students[pairs[i][1]].id, students[pairs[i][1]].subject);
    }
}

// Greedy function to pair students with different subjects
void pairStudents(Student students[], int numStudents) {
    int pairs[MAX_STUDENTS / 2][2]; // Array to store paired student indices
    int pairCount = 0;

    for (int i = 0; i < numStudents; i++) {
        if (!students[i].isPaired) { // If the student isn't paired yet
            for (int j = i + 1; j < numStudents; j++) {
                // Check if student is unpaired and has a different subject
                if (!students[j].isPaired && 
                    students[i].id != students[j].id && 
                    strcmp(students[i].subject, students[j].subject) != 0) {
                    
                    pairs[pairCount][0] = i; // Pair student i
                    pairs[pairCount][1] = j; // with student j
                    students[i].isPaired = true;
                    students[j].isPaired = true;
                    pairCount++;
                    break; // Move to the next student to pair
                }
            }
        }
    }

    displayPairs(students, pairs, pairCount);
}

int main() {
    Student students[MAX_STUDENTS] = {
        {1, "Math", false}, {2, "Math", false}, {3, "Science", false}, 
        {4, "Science", false}, {5, "History", false}, {6, "English", false},
        {7, "Geography", false}, {8, "Math", false}, {9, "Science", false},
        {10, "History", false}, {11, "Geography", false}, {12, "English", false}
    };

    printf("Pairing students based on different subjects using a greedy approach:\n");
    pairStudents(students, MAX_STUDENTS);

    return 0;
}
