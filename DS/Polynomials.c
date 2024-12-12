#include <stdio.h>
#include <stdlib.h>

// Define the structure for a term in the polynomial
struct Term {
    int coeff;
    int exp;
    struct Term *next;
};

typedef struct Term Term;

// Function prototypes
void insertTerm(Term **poly, int coeff, int exp);
void displayPolynomial(Term *poly);
Term* addPolynomials(Term *poly1, Term *poly2);

int main() {
    Term *poly1 = NULL, *poly2 = NULL, *result = NULL;
    int n, coeff, exp;

    // Input for first polynomial
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d%d", &coeff, &exp);
        insertTerm(&poly1, coeff, exp);
    }

    // Input for second polynomial
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d%d", &coeff, &exp);
        insertTerm(&poly2, coeff, exp);
    }

    // Display input polynomials
    printf("\nFirst Polynomial: ");
    displayPolynomial(poly1);
    printf("Second Polynomial: ");
    displayPolynomial(poly2);

    // Add the two polynomials
    result = addPolynomials(poly1, poly2);

    // Display the result
    printf("\nResultant Polynomial: ");
    displayPolynomial(result);

    return 0;
}

// Function to insert a term into the polynomial
void insertTerm(Term **poly, int coeff, int exp) {
    Term *newTerm = (Term *)malloc(sizeof(Term));
    if (!newTerm) {
        printf("Memory allocation failed!\n");
        return;
    }
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    newTerm->next = NULL;

    if (*poly == NULL || (*poly)->exp < exp) {
        newTerm->next = *poly;
        *poly = newTerm;
    } else {
        Term *current = *poly;
        while (current->next != NULL && current->next->exp >= exp) {
            current = current->next;
        }
        if (current->exp == exp) {
            current->coeff += coeff;
            free(newTerm);
        } else {
            newTerm->next = current->next;
            current->next = newTerm;
        }
    }
}

// Function to display a polynomial
void displayPolynomial(Term *poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }

    Term *current = poly;
    while (current != NULL) {
        printf("%d*x^%d", current->coeff, current->exp);
        current = current->next;
        if (current != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to add two polynomials
Term* addPolynomials(Term *poly1, Term *poly2) {
    Term *result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            insertTerm(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            insertTerm(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            insertTerm(&result, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insertTerm(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insertTerm(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}