# include<stdio.h>

int superSet[20], superSetSize = 0,
    setA[20], setASize = 0,
    setB[20], setBSize = 0,
    bitA[20], bitB[20], result[20];

void getSet(int arr[], int *size, char name) {
    printf("Enter number of elements for Set %c\n", name);
    scanf("%d", size);
    printf("Enter elements of Set %c\n", name);
    for (int i = 0; i < *size; i++) 
    {
        scanf("%d", &arr[i]);
    }
}

// Function to print a set
void printSet(int arr[], int size, char *name) {
    printf("%s: {", name);
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i != size - 1) printf(", ");
    }
    printf("}\n");
}

// Function to print the bit string of a set
void printBitString(int arr[], char *name) {
    printf("Bit string for %s: [", name);
    for (int i = 0; i < superSetSize; i++) {
        printf("%d", arr[i]);
        if (i != superSetSize - 1) printf(", ");
    }
    printf("]\n");
}

// Function to generate bit strings for Set A and B
void generateBitStrings() {
    for (int i = 0; i < superSetSize; i++) {
        bitA[i] = 0;
        bitB[i] = 0;
    }
    // Mark presence of Set A and Set B elements
    for (int i = 0; i < setASize; i++) {
        for (int j = 0; j < superSetSize; j++) {
            if (setA[i] == superSet[j]) bitA[j] = 1;
        }
    }
    for (int i = 0; i < setBSize; i++) {
        for (int j = 0; j < superSetSize; j++) {
            if (setB[i] == superSet[j]) bitB[j] = 1;
        }
    }

    // Print the bit strings for Set A and Set B
    printBitString(bitA, "Set A");
    printBitString(bitB, "Set B");
}

// Function to perform set operations: Union, Intersection, or Difference
void setOperation(char op) {
    generateBitStrings(); // Prepare the bit strings
    for (int i = 0; i < superSetSize; i++) {
        if (op == '|') result[i] = bitA[i] | bitB[i]; // Union
        else if (op == '&') result[i] = bitA[i] & bitB[i]; // Intersection
        else if (op == '-') result[i] = bitA[i] & !bitB[i]; // Difference
    }

    // Print the bit string of the result
    printBitString(result, "Result");

    // Print the result set
    printf("Result of operation: {");
    int first = 1;
    for (int i = 0; i < superSetSize; i++) {
        if (result[i] == 1) {
            if (!first) printf(", ");
            printf("%d", superSet[i]);
            first = 0;
        }
    }
    printf("}\n");
}

// Main function placed at the end
void main() {
    int choice;
    do {
        printf("1. Enter Universal Set\n");
        printf("2. Enter Set A\n");
        printf("3. Enter Set B\n");
        printf("4. Display sets\n");
        printf("5. Union (A OR B)\n");
        printf("6. Intersection (A AND B)\n");
        printf("7. Difference (A - B)\n");
        printf("8. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: getSet(superSet, &superSetSize, 'U'); break;
            case 2: getSet(setA, &setASize, 'A'); break;
            case 3: getSet(setB, &setBSize, 'B'); break;
            case 4:printSet(superSet, superSetSize, "Universal Set");
                   printSet(setA, setASize, "Set A");
                   printSet(setB, setBSize, "Set B");
                   break;
            case 5: setOperation('|'); break; // Union (OR)
            case 6: setOperation('&'); break; // Intersection (AND)
            case 7: setOperation('-'); break; // Difference (A - B)
           

        }
    } 
    while (choice != 8);

}
