#include<stdio.h>
#include <time.h>
#include<stdlib.h>
#include<string.h>

int day_of_week(int year, int month, int day) {
    struct tm date = {0};
    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    date.tm_mday = day;
    time_t t = mktime(&date);
    struct tm *result = localtime(&t);
    return result->tm_wday;
}

int get_max_days_in_month(int year, int month) {
    int days_in_each_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        days_in_each_month[2] = 29;
    }
    return days_in_each_month[month];
}

int isValidDate(int year, int month, int day) {
    if (year < 1 || month < 1 || month > 12) {
        return 0;
    }
    int days_in_each_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        days_in_each_month[2] = 29;
    }
    if (day < 1 || day > days_in_each_month[month]) {
        return 0;
    }
    return 1;
}

void display_calendar() {
    int year, month, days_in_month, i, day, current_day;
    char *days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    int days_in_each_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("Enter year: ");
    scanf("%d", &year);
    printf("Enter month (1-12): ");
    scanf("%d", &month);

    if (month < 1 || month > 12) {
        printf("Invalid month. Please enter a value between 1 and 12.\n");
    	exit(1);
    }

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        days_in_each_month[2] = 29;
    }

    day = day_of_week(year, month, 1);

    printf("\n-----------------------------\n");
    printf("           %d-%02d\n", year, month);
    printf("-----------------------------\n");

    for (i = 0; i < 7; i++) {
        printf("%s ", days[i]);
    }
    printf("\n");
    for (i = 0; i < day; i++) {
        printf("    ");
    }
    current_day = 1;
    while (current_day <= (days_in_month = get_max_days_in_month(year, month))) {
        printf("%3d ", current_day);

        if (++day > 6) {
            printf("\n");
            day = 0;
        }

        current_day++;
    }
    printf("\n\n");
}

void national_holidays(){
    int month,year;
    printf("Enter year(only available for 2024): ");
    scanf("%d",&year);
    printf("Enter month (1-12): ");
    scanf("%d", &month);
    display_calendar(year, month);
    printf("*****************Indian Festivals********************\n\n");

    switch(month){
    case 1:
        printf(" 01-%d-%d : New Year Day\n",month,year);
        printf(" 15-%d-%d : Makara Sankranti\n",month,year);
        printf(" 26-%d-%d : Republic Day\n",month,year);
        break;
    case 2:
        printf(" no holidays available\n");
        break;
    case 3:
        printf(" 08-%d-%d : Mahashivaratri\n",month,year);
        printf(" 25-%d-%d : Holi\n",month,year);
        printf(" 29-%d-%d : Good Friday\n",month,year);
        printf(" 30-%d-%d : Easter Saturday\n",month,year);
        printf(" 31-%d-%d : Easter Sunday\n",month,year);
        break;
    case 4:
        printf(" 09-%d-%d : Ugadi\n",month,year);
        printf(" 14-%d-%d : Dr.Ambedkar Jayanthi\n",month,year);
        printf(" 14-%d-%d : Tamil New Year\n",month,year);
        printf(" 17-%d-%d : Ram Navami\n",month,year);
        printf(" 21-%d-%d : Mahavir Jayanthi\n",month,year);
        break;
    case 5:
        printf(" 01-%d-%d : May Day(Labour Day)\n",month,year);
        printf(" 10-%d-%d : Basava Jayanthi\n",month,year);
        printf(" 23-%d-%d : Buddha Purnima\n",month,year);
        break;
    case 6:
        printf(" 17-%d-%d : Bakrid\n",month,year);
        break;
    case 7:
        printf(" 17-%d-%d : Muharram\n",month,year);
        break;
    case 8:
        printf(" 15-%d-%d : Independence Day\n",month,year);
        printf(" 19-%d-%d : Raksha Bandhan\n",month,year);
        printf(" 26-%d-%d : Janmashtami\n",month,year);
        break;
    case 9:
        printf(" 08-%d-%d : Ganesh Chaturthi\n",month,year);
        printf(" 15-%d-%d : Thiruvonam\n",month,year);
        printf(" 16-%d-%d : Eid\n",month,year);
        break;
    case 10:
        printf(" 02-%d-%d : Gandhi Jayanthi\n",month,year);
        printf(" 02-%d-%d : Mahalaya Amavasye\n",month,year);
        printf(" 12-%d-%d : Vijaya Dashami\n",month,year);
        printf(" 17-%d-%d : Valmiki Jayanthi\n",month,year);
        printf(" 31-%d-%d : Diwali\n",month,year);
        break;
    case 11:
        printf(" 01-%d-%d : Kannada Rajyothsava\n",month,year);
        printf(" 18-%d-%d : Kanakadasa Jayanthi\n",month,year);
        break;
    case 12:
        printf(" 25-%d-%d : Christmas Day\n",month,year);
        printf(" 31-%d-%d : New Year Eve\n",month,year);
        break;
    }
}

void constant_holidays(){
    int year,month;

    printf("Enter year: ");
    scanf("%d",&year);
    printf("Enter month (1-12): ");
    scanf("%d", &month);
    display_calendar(year, month);
    printf("******************General Holidays********************\n\n");

    switch(month){
    case 1:
        printf(" 01-%d-%d : New Year Day\n",month,year);
        printf(" 26-%d-%d : Republic Day\n",month,year);
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        printf(" 14-%d-%d : Dr.Ambedkar Jayanthi\n",month,year);
        printf(" 14-%d-%d : Tamil New Year\n",month,year);
        printf(" 21-%d-%d : Mahavir Jayanthi\n",month,year);
        break;
    case 5:
        printf(" 01-%d-%d : May Day(Labour Day)\n",month,year);
        printf(" 10-%d-%d : Basava Jayanthi\n",month,year);
        printf(" 23-%d-%d : Buddha Purnima\n",month,year);
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        printf(" 15-%d-%d : Independence Day\n",month,year);
        break;
    case 9:
        break;
    case 10:
        printf(" 02-%d-%d : Gandhi Jayanthi\n",month,year);
        printf(" 17-%d-%d : Valmiki Jayanthi\n",month,year);
        break;
    case 11:
        printf(" 01-%d-%d : Kannada Rajyothsava\n",month,year);
        printf(" 18-%d-%d : Kanakadasa Jayanthi\n",month,year);
        break;
    case 12:
        printf(" 25-%d-%d : Christmas Day\n",month,year);
        printf(" 31-%d-%d : New Year Eve\n",month,year);
        break;
    }
}

void addEvents(char *r) {
    int year, month, day;
    char eventName[100];

    printf("Enter year: ");
    scanf("%d", &year);
    printf("Enter month (1-12): ");
    scanf("%d", &month);
    printf("Enter day: ");
    scanf("%d", &day);

    if (!isValidDate(year, month, day)) {
        printf("Invalid date. Please enter a valid date.\n");
        return;
    }

    printf("Enter event name: ");
    scanf(" %[^\n]", eventName);

    FILE *file = fopen(r, "a");
    if (file == NULL) {
        file = fopen(r, "w");
    }
    if (file != NULL) {
        fprintf(file, "%02d/%02d/%04d:%s\n", day, month, year, eventName);
		fclose(file);
		printf("Event added successfully!\n");
    } else {
        printf("Error opening the file.\n");
    }
}

void deleteEvents(char *r) {
    int year, month, day;

    printf("Enter year: ");
    scanf("%d", &year);
    printf("Enter month (1-12): ");
    scanf("%d", &month);
    printf("Enter day: ");
    scanf("%d", &day);

    if (!isValidDate(year, month, day)) {
        printf("Invalid date. Please enter a valid date.\n");
        exit(1);
    }

    FILE *file = fopen(r, "r");

    if (file == NULL) {
        printf("No events found for the specified date.\n");
        exit(1);
    }

   printf("\nEvents for %02d/%02d/%04d:\n", day, month, year);

    char line[100];
    int found = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        int fileDay, fileMonth, fileYear;
        char eventName[50];

        sscanf(line, "%2d/%2d/%4d:%s", &fileDay, &fileMonth, &fileYear, eventName);

        if (fileDay == day && fileMonth == month && fileYear == year) {
            printf("%s\n", eventName); // Print only the event name
            found = 1;
        }
    }

    fclose(file);

    if (!found) {
        printf("No events found for the specified date.\n");
        exit(1);
    }

    printf("\nDo you want to delete an event for the specified date? (1 for Yes, 0 for No): ");
    int deleteChoice;
    scanf("%d", &deleteChoice);

    if (deleteChoice == 1) {
        FILE *inputFile = fopen(r, "r");
        FILE *tempFile = fopen("temp_event.txt", "w");

        if (inputFile == NULL || tempFile == NULL) {
            printf("Error opening the file.\n");
            exit(1);
        }

        while (fgets(line, sizeof(line), inputFile) != NULL) {
            int fileDay, fileMonth, fileYear;
            char eventName[50];

            sscanf(line, "%2d/%2d/%4d:%s", &fileDay, &fileMonth, &fileYear, eventName);

            if (!(fileDay == day && fileMonth == month && fileYear == year)) {
                fprintf(tempFile, "%s", line);
            }
        }

        fclose(inputFile);
        fclose(tempFile);

        remove(r);
        rename("temp_event.txt", "event.txt");

        printf("Event(s) deleted successfully!\n");
    } else {
        printf("No events were deleted.\n");
    }
}

void displayEvents(char *r) {
    int year, month;

    // Get user input for year and month
    printf("Enter year: ");
    scanf("%d", &year);
    printf("Enter month (1-12): ");
    scanf("%d", &month);

    // Validate the input date (day is not taken as input)
    if (!isValidDate(year, month, 1)) {
        printf("Invalid date. Please enter a valid date.\n");
        return;
    }

    // Open the file in read mode
    FILE *file = fopen(r, "r");

    if (file == NULL) {
        printf("No events found for the specified month.\n");
        return;
    }

    // Declare parallel arrays to store day, month, year, and event names
    int days[100]; // Assuming a maximum of 100 events (adjust as needed)
    int months[100];
    int years[100];
    char eventNames[100][50];

    // Read events from the file and store in parallel arrays
    int eventCount = 0;
    while (fscanf(file, "%2d/%2d/%4d:%49[^\n]", &days[eventCount],
                  &months[eventCount], &years[eventCount],
                  eventNames[eventCount]) == 4) {
        // Check if the event is for the specified month and year
        if (months[eventCount] == month && years[eventCount] == year) {
            eventCount++;
        }
    }

    fclose(file);

    if (eventCount == 0) {
        printf("No events found for the specified month.\n");
        return;
    }

    // Sort the events based on the day using a basic bubble sort algorithm
    int i,j;
    for (i = 0; i < eventCount - 1; i++) {
        for (j = 0; j < eventCount - i - 1; j++) {
            if (days[j] > days[j + 1]) {
                // Swap days
                int temp = days[j];
                days[j] = days[j + 1];
                days[j + 1] = temp;

                // Swap months
                temp = months[j];
                months[j] = months[j + 1];
                months[j + 1] = temp;

                // Swap years
                temp = years[j];
                years[j] = years[j + 1];
                years[j + 1] = temp;

                // Swap event names
                char tempName[50];
                strcpy(tempName, eventNames[j]);
                strcpy(eventNames[j], eventNames[j + 1]);
                strcpy(eventNames[j + 1], tempName);
            }
        }
    }

    // Display sorted events for the specified month
    printf("\nEvents for %02d/%04d (sorted by day):\n", month, year);

	for (i = 0; i < eventCount; i++) {
        printf("%02d/%02d/%04d: %s\n", months[i], days[i], years[i], eventNames[i]);
    }
}

struct User {
    char username[50]; // Assuming a maximum username length of 50 characters
    char password[50]; // Assuming a maximum password length of 50 characters
};

int userExists(const char *username, const char *password, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return 0; // File does not exist, so the user can't exist.
    }

    struct User user;
    while (fscanf(file, "%49[^#]#%49s\n", user.username, user.password) != EOF) {
        if (strcmp(username, user.username) == 0 || strcmp(password, user.password) == 0) {
            fclose(file);
            return 1; // User found
        }
    }

    fclose(file);
    return 0; // User not found
}

int login(){
    int c,choice;
    char username[50]; // Assuming a maximum username length of 50 characters
    char password[50]; // Assuming a maximum password length of 50 characters
    char filename[50];
    char extension[5]=".txt";

    printf("\nEnter your username: ");
    scanf("%s", username);
    printf("\nEnter your password: ");
    scanf("%s", password);

        // Check if the username and password combination exists in the file
    if (userExists(username, password, "usernames.txt")) {
        printf("Login successful. Welcome, %s!\n", username);

    strcat(username,extension);
    strcpy(filename,username);

        do{
            printf("\nEnter your option\n");
            printf("1. Add Event\n");
            printf("2. Delete Event\n");
            printf("3. Display Events\n");
            scanf("%d",&choice);
            switch(choice){
            case 1:
                addEvents(filename);
                break;
            case 2:
                deleteEvents(filename);
                break;
            case 3:
                displayEvents(filename);
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
            }

            printf("\nPress 1 to continue and 0 to exit from login:");
            scanf("%d", &c);
        }while(c);
    }

    else {
        printf("Invalid username or password. Please try again or register.\n");
        printf("\n");
        return 1;
    }

    return 0;
}

int newregister() {
    char newUsername[50];
    char newPassword[50];
    char extension[5]=".txt";

    printf("\nEnter a new username: ");
    scanf("%s", newUsername);
    printf("Enter a new password: ");
    scanf("%s", newPassword);

    // Check if the new username already exists
    if (userExists(newUsername, newPassword, "usernames.txt")) {
        printf("Username already exists. Please choose a different username.\n");
        printf("\n");
        return 1;
    } else {
        // Register the new username and password by appending to the file
        FILE *file = fopen("usernames.txt", "a");
        if (file == NULL) {
            perror("fopen");
            return 1;
        }

        fprintf(file, "%s#%s\n", newUsername, newPassword);
        fclose(file);

        char *filename = (char *)malloc(20 * sizeof(char)); // Dynamically allocate memory for the filename

        if (filename == NULL) {
            perror("malloc");
            return 1;
        }

        strcat(newUsername,extension);
        strcpy(filename,newUsername);

        FILE *f2 = fopen(filename, "w");

        if (f2 == NULL) {
            printf("Error opening the file.\n");
            free(filename); // Free the allocated memory in case of an error
            return 1;
        }

        fclose(f2);
        printf("Registration successful. Welcome, %s!\n", newUsername);

        return 0;
    }
}

int main() {
    int year, month, cont, ch, l;


    do {
        printf("1. Display Calendar\n");
        printf("2. Indian Festivals\n");
        printf("3. General Holidays\n");
        printf("4. Login\n");
        printf("5. Register\n");
        printf("Enter Your Choice\n");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            display_calendar();
            break;
        case 2:
            national_holidays();
            break;
        case 3:
            constant_holidays();
            break;
        case 4:
            login();
            break;
        case 5:
            newregister();
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }

        printf("\nPress 1 to continue and 0 to exit:");
        scanf("%d", &cont);
    } while (cont);



    return 0;
}
