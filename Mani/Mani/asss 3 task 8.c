#include <stdio.h>

// Define structure
struct Student {
    char name[50];
    int roll;
    float marks;
    char grade;
};

// Function to calculate grade
char calculateGrade(float marks) {
    if (marks >= 90) return 'A';
    else if (marks >= 75) return 'B';
    else if (marks >= 60) return 'C';
    else if (marks >= 40) return 'D';
    else return 'F';
}

int main() {
    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student students[n];  // array of structures

    // Input student details
    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i+1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll number: ");
        scanf("%d", &students[i].roll);
        printf("Marks: ");
        scanf("%f", &students[i].marks);

        students[i].grade = calculateGrade(students[i].marks);
    }

    // Output student records
    printf("\n--- Student Records ---\n");
    for (i = 0; i < n; i++) {
        printf("Name: %s | Roll: %d | Marks: %.2f | Grade: %c\n",
               students[i].name, students[i].roll, students[i].marks, students[i].grade);
    }

    return 0;
}
