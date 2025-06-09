#include <stdio.h>
#include <string.h>
#include <time.h>

void printDayTimetable(char day[]) {
if (strcmp(day, "Monday") == 0) {
printf("\n--- Monday Timetable ---\n");
printf("7:30 - 8:30   : EC\n");
printf("8:30 - 9:30   : PPS\n");
printf("9:30 - 10:30  : EM-I\n");
printf("2:00 - 3:00   : CC Practical\n");
} else if (strcmp(day, "Tuesday") == 0) {
printf("\n--- Tuesday Timetable ---\n");
printf("7:30 - 8:30   : EM-II\n");
printf("8:30 - 9:30   : EM-I\n");
printf("9:30 - 10:30  : EC\n");
printf("12:30 - 1:30  : PPS Practical\n");
} else if (strcmp(day, "Wednesday") == 0) {
printf("\n--- Wednesday Timetable ---\n");
printf("7:30 - 8:30   : EM-II\n");
printf("8:30 - 9:30   : CS\n");
printf("9:30 - 10:30  : PPS\n");
printf("12:30 - 1:30  : CC Practical\n");
printf("2:00 - 3:00   : EC Practical\n");
} else if (strcmp(day, "Thursday") == 0) {
printf("\n--- Thursday Timetable ---\n");
printf("8:30 - 9:30   : EM\n");
printf("9:30 - 10:30  : CS\n");
printf("12:30 - 1:30  : WP Practical\n");
printf("2:00 - 3:00   : EM Practical\n");
} else if (strcmp(day, "Friday") == 0) {
printf("\n--- Friday Timetable ---\n");
printf("7:30 - 8:30   : CC\n");
printf("8:30 - 9:30   : EC\n");
printf("9:30 - 10:30  : EM-II\n");
} else {
printf("\n--- %s Timetable ---\n", day);
printf("Holiday / No lectures scheduled.\n");
}
}

void printFullTimetable() {
printDayTimetable("Monday");
printDayTimetable("Tuesday");
printDayTimetable("Wednesday");
printDayTimetable("Thursday");
printDayTimetable("Friday");
printDayTimetable("Saturday");
}

int main() {
int choice;
char cont;

char *weekdays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};    

do {    
    time_t t = time(NULL);    
    struct tm tm = *localtime(&t);    
    int todayIndex = tm.tm_wday;    

    printf("\n===== ET2 Timetable Menu =====\n");    
    printf("1. View Today's Timetable\n");    
    printf("2. View Tomorrow's Timetable\n");    
    printf("3. View Full Timetable\n");    
    printf("4. Exit\n");    
    printf("Enter your choice: ");    
    scanf("%d", &choice);    

    switch (choice) {    
        case 1:    
            printDayTimetable(weekdays[todayIndex]);    
            break;    
        case 2:    
            printDayTimetable(weekdays[(todayIndex + 1) % 7]);    
            break;    
        case 3:    
            printFullTimetable();    
            break;    
        case 4:    
            printf("Exiting program. Goodbye!\n");    
            return 0;    
        default:    
            printf("Invalid choice. Please enter 1, 2, 3, or 4.\n");    
    }    

    printf("\nDo you want to continue? (y/n): ");    
    getchar();     
    scanf("%c", &cont);    

} while (cont == 'y' || cont == 'Y');    

printf("Thank you for using the timetable program. Goodbye!\n");    

return 0;

}
