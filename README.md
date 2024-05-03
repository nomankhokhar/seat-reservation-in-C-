# Seat Reserved Program

This C++ program allows users to manage seat reservations in a plane. Users can perform various actions such as printing the seating chart, reserving a seat, canceling a seat reservation, resetting the seating chart, and exiting the program.

## Features

- **Print Seating Chart**: Displays the current seating chart of the plane.
- **Reserve a Seat**: Allows users to reserve a seat in the plane by specifying the ticket type (First Class, Business Class, or Economy Class) and the desired seat row and column.
- **Cancel a Seat Reservation**: Enables users to cancel a previously reserved seat by specifying the ticket type and the seat row and column.
- **Reset Seating Chart**: Resets the seating chart, marking all seats as available.
- **Exit Program**: Allows users to exit the program.

## Usage

1. Run the program.
2. Choose an action from the menu by entering the corresponding number:
   - Enter `1` to print the seating chart.
   - Enter `2` to reserve a seat.
   - Enter `3` to cancel a seat reservation.
   - Enter `4` to reset the seating chart.
   - Enter `5` to exit the program.

## Ticket Types

- **First Class**: Seats from row 1 to 2.
- **Business Class**: Seats from row 3 to 6.
- **Economy Class**: Seats from row 7 onwards.

## File Handling

The program utilizes file handling to store and retrieve seat reservation data. The seating chart is stored in a text file named `seats.txt`, where each character represents a seat ('*' for available seats and 'X' for reserved seats).

## Author

- **Author**: Noman Ali
- **Student ID**: L1F20BSCS0554
