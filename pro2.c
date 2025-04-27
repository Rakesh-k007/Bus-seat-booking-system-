#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 4
char seats[ROWS][COLS];

void initializeSeats() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            seats[i][j] = 'A';
        }
    }
}

void displaySeats() {
    printf("\nSeat Map of the bus shown below !!\n(A=Available, B=Booked):\n\n");
    printf("      ");
          for(int j=1;j<=COLS;j++){
              printf("  %d ",j);
          }
          printf("\n");
    for(int i = 0; i < ROWS; i++) {
        printf("Row %d:", i+1);
        for(int j = 0; j < COLS; j++) {
            printf(" [%c]", seats[i][j]);
        }
        printf("\n");
    }
}

void saveBookingsToFile() {
    FILE *fp = fopen("bookings.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    for(int i = 0; i <ROWS; i++) {
        for(int j = 0; j <COLS; j++) {
            fprintf(fp, "%c ", seats[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    printf("Bookings saved to file.\n");
}

void bookSeat(int row,int col) {
    if (row < 0|| row > ROWS || col < 0 || col > COLS){
        printf("Invalid seat position.\n");
        return;
    }
    if (seats[row][col] == 'B') {
        printf("Seat already booked.\n");
    } else {
        seats[row][col] = 'B';
        printf("\n  Seat booked successfully.\n");
    }
}

void cancelSeat(int row, int col) {
    if (row < 0 || row > ROWS || col < 0 || col > COLS) {
        printf("Invalid seat position.\n");
        return;
    }
    if (seats[row][col] == 'A') {
        printf("Seat is already available.\n");
    } else {
        seats[row][col] = 'A';
        printf("\n Seat booking cancelled.\n");
    }
}

int main() {
    int choice, row, col;
    initializeSeats();
         printf("*BUS SEAT BOOKING SYSTEM\n");
    while (1) {
          displaySeats();
        printf("\n1. Book Seat\n2. Cancel Seat\n3. Save to File\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter row  to book (1-%d): ",ROWS);
                scanf("%d", &row);
                printf("Enter col to book (1-%d):",COLS);
                scanf("%d",&col);
                bookSeat(row-1, col-1);
                break;
            case 2:
                printf("Enter row to cancel (1-%d): ",ROWS);
                scanf("%d", &row);
                printf("Enter column to cancel (1-%d):",COLS);
                scanf("%d",&col);
                cancelSeat(row-1, col-1);
                break;
            case 3:
                saveBookingsToFile();
                break;
            case 4:
                  printf("Thanks for visiting our panel\n");
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}