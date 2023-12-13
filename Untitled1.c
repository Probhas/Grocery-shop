#include <stdio.h>
#include<string.h>

// Define a structure for grocery items
struct GroceryItem {
    char name[50];
    double price;
};

// Function to display grocery items
void displayGroceryItems(struct GroceryItem items[], int size) {
    printf("\nGrocery Picker\n");
    for (int i = 0; i < size; ++i) {
        printf("%d. %s - %.2f Tk\n", i + 1, items[i].name, items[i].price);
    }
}

// Function to get user input for item and quantity
void getUserInput(int *item, int *quantity) {
    printf("\nEnter the item number: ");
    scanf("%d", item);
    printf("Enter the quantity: ");
    scanf("%d", quantity);
}

void processNogodPayment(float amount) {
    // Implement Nogod payment processing logic here
    printf("Processing Nogod payment of %.2f BDT\n", amount);
}

void processBikashPayment(float amount) {
    // Implement Bikash payment processing logic here
    printf("Processing Bikash payment of %.2f BDT\n", amount);
}

int main() {
    int item;
    int quantity;
    double totalPrice = 0.0;
    char confirm;
    char addMore;

    // Define an array of grocery items
    struct GroceryItem items[] = {
        {"Milk", 60.00},
        {"Maida", 67.00},
        {"Corn Flour", 75.00},
        {"Khesari Dal", 65.00},
        {"Brown Sugar", 165.00},
        {"White Sugar", 128.00},
        {"Soyabean Oil", 177.00},
        {"Turmeric Powder", 58.00},
        {"Miniket Rice", 788.00},
        {"Soap", 65.00}
    };

    // Display grocery items using the function
    displayGroceryItems(items, sizeof(items) / sizeof(items[0]));

    do {
        // User input using a function
        getUserInput(&item, &quantity);

        if (item < 1 || item > 10) {
            printf("Invalid item number\n");
            return 1; // Exit program with an error code
        }

        // Calculate total price for the current item
        totalPrice += quantity * items[item - 1].price;

        // Ask if the user wants to add more items
        printf("Add more items? (y/n): ");
        scanf(" %c", &addMore);
    } while (addMore == 'y' || addMore == 'Y');

    // Confirmation for the entire order
    printf("\nTotal Price for all items: $%.2f\n", totalPrice);
    printf("Confirm your order (y/n): ");
    scanf(" %c", &confirm);

    if (confirm == 'y' || confirm == 'Y') {
        // Payment method
        printf("\nChoose a payment method:\n");
        printf("1. Cash on Delivery\n");
        printf("2. Online Payment\n");
        int paymentMethod;
        printf("Enter the payment method number: ");
        scanf("%d", &paymentMethod);

        int payentmethod2;
        if(paymentMethod==2){
            printf("1.Nogod\n 2.Bikash\n");
            scanf("%d",&payentmethod2);

    switch (payentmethod2) {
        case 1:
            processNogodPayment(totalPrice);
            break;
        case 2:
            processBikashPayment(totalPrice);
            break;
        default:
            printf("Invalid payment method\n");
            break;
    }

        }
        // Delivery locations
        printf("\nChoose a delivery location:\n");
        printf("1. Chawkbazar\n");
        printf("2. Shershah\n");
        printf("3. Kumira\n");
        printf("4. Bohoddarhat\n");
        printf("5. Agrabad\n");
        int deliveryLocation;
        printf("Enter the delivery location number: ");
        scanf("%d", &deliveryLocation);

        // Time of arrival
        printf("\nYour order will be delivered to ");
        switch (deliveryLocation) {
            case 1:
                printf("Chawkbazar");
                break;
            case 2:
                printf("Shershah");
                break;
            case 3:
                printf("Kumira");
                break;
            case 4:
                printf("Bohoddarhat");
                break;
            case 5:
                printf("Agrabad");
                break;
            default:
                printf("Unknown location");
        }
        printf("\nYour order will be delivered in approximately 1 hour.\n");
        printf("Thank you for shopping with us!\n");

        // File handling - write the order details to a file
        FILE *file = fopen("order_details.txt", "w");
        if (file != NULL) {
            fprintf(file, "Order Details:\nTotal Price: $%.2f\nPayment Method: %d\nDelivery Location: %d\n", totalPrice, paymentMethod, deliveryLocation);
            fclose(file);
        } else {
            printf("Error writing to file.\n");
        }

    } else {
        printf("Order canceled. Thank you!\n");
    }

    return 0;
}
