#include <stdio.h>

// Function prototypes
double simply_supported_central_load(double length, double load, double E, double I);
double cantilever_end_load(double length, double load, double E, double I);
double fixed_central_load(double length, double load, double E, double I);
double cantilever_UDL(double length, double load, double E, double I);
double simply_supported_UDL(double length, double load, double E, double I);
double fixed_UDL(double length, double load, double E, double I);

int main() {
    int choice;
    double length, load, E, I, deflection;

    printf("Beam Bending Calculator\n");
    printf("Select the type of beam and loading condition:\n");
    printf("1. Simply Supported Beam with Central Load\n");
    printf("2. Cantilever Beam with End Load\n");
    printf("3. Fixed Beam with Central Load\n");
    printf("4. Cantilever Beam with Uniformly Distributed Load (UDL)\n");
    printf("5. Simply Supported Beam with Uniformly Distributed Load (UDL)\n");
    printf("6. Fixed Beam with Uniformly Distributed Load (UDL)\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);

    // Input common properties
    printf("Enter the length of the beam (m): ");
    scanf("%lf", &length);
    printf("Enter the load (N or N/m for UDL): ");
    scanf("%lf", &load);
    printf("Enter the modulus of elasticity (E) of the material (N/m^2): ");
    scanf("%lf", &E);
    printf("Enter the moment of inertia (I) of the cross-section (m^4): ");
    scanf("%lf", &I);

    // Calculate deflection based on choice
    switch (choice) {
        case 1:
            deflection = simply_supported_central_load(length, load, E, I);
            printf("Deflection for Simply Supported Beam with Central Load: %.6f m\n", deflection);
            break;
        case 2:
            deflection = cantilever_end_load(length, load, E, I);
            printf("Deflection for Cantilever Beam with End Load: %.6f m\n", deflection);
            break;
        case 3:
            deflection = fixed_central_load(length, load, E, I);
            printf("Deflection for Fixed Beam with Central Load: %.6f m\n", deflection);
            break;
        case 4:
            deflection = cantilever_UDL(length, load, E, I);
            printf("Deflection for Cantilever Beam with Uniformly Distributed Load: %.6f m\n", deflection);
            break;
        case 5:
            deflection = simply_supported_UDL(length, load, E, I);
            printf("Deflection for Simply Supported Beam with Uniformly Distributed Load: %.6f m\n", deflection);
            break;
        case 6:
            deflection = fixed_UDL(length, load, E, I);
            printf("Deflection for Fixed Beam with Uniformly Distributed Load: %.6f m\n", deflection);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    return 0;
}

// Deflection for Simply Supported Beam with Central Load
double simply_supported_central_load(double length, double load, double E, double I) {
    return (load * length * length * length) / (48 * E * I);
}

// Deflection for Cantilever Beam with End Load
double cantilever_end_load(double length, double load, double E, double I) {
    return (load * length * length * length) / (3 * E * I);
}

// Deflection for Fixed Beam with Central Load
double fixed_central_load(double length, double load, double E, double I) {
    return (load * length * length * length) / (192 * E * I);
}

// Deflection for Cantilever Beam with Uniformly Distributed Load
double cantilever_UDL(double length, double load, double E, double I) {
    return (5 * load * length * length * length * length) / (384 * E * I);
}

// Deflection for Simply Supported Beam with Uniformly Distributed Load
double simply_supported_UDL(double length, double load, double E, double I) {
    return (5 * load * length * length * length * length) / (384 * E * I);
}

// Deflection for Fixed Beam with Uniformly Distributed Load
double fixed_UDL(double length, double load, double E, double I) {
    return (load * length * length * length * length) / (384 * E * I);
}