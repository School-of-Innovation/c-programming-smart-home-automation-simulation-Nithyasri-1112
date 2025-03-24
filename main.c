/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEFAULT_TEMP 22
#define TEMP_VARIATION 10

void initializeSystem(int rooms, int lights[], int locks[], int motion[], int temperature[]);
void displayMenu();
int getValidRoom(int rooms);
void toggleLight(int rooms, int lights[]);
void readTemperature(int rooms, int temperature[]);
void checkMotion(int rooms, int motion[]);
void securitySystem(int rooms, int locks[]);
void analyzeHouseStatus(int rooms, int lights[], int locks[], int motion[], int temperature[]);

int main() {
    int rooms;

    printf("Enter number of rooms: ");
    while (scanf("%d", &rooms) != 1 || rooms <= 0) {
        printf("Invalid input. Please enter a valid number of rooms: ");
        while (getchar() != '\n'); 
    }

    int lights[rooms], locks[rooms], motion[rooms], temperature[rooms];
    initializeSystem(rooms, lights, locks, motion, temperature);

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice! Please enter a valid option.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1: toggleLight(rooms, lights); break;
            case 2: readTemperature(rooms, temperature); break;
            case 3: checkMotion(rooms, motion); break;
            case 4: securitySystem(rooms, locks); break;
            case 5: analyzeHouseStatus(rooms, lights, locks, motion, temperature); break;
            case 6: printf("Exiting... Goodbye!\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }

    } while (choice != 6);

    return 0;
}

void initializeSystem(int rooms, int lights[], int locks[], int motion[], int temperature[]) {
    for (int i = 0; i < rooms; i++) {
        lights[i] = 0;
        locks[i] = 1;
        motion[i] = 0;
        temperature[i] = DEFAULT_TEMP + (rand() % TEMP_VARIATION);
    }
    printf("System initialized successfully!\n");
}

void displayMenu() {
    printf("\n===== Smart Home Menu =====\n");
    printf("1. Toggle Light\n");
    printf("2. Read Temperature\n");
    printf("3. Check Motion Sensor\n");
    printf("4. Lock/Unlock Security System\n");
    printf("5. House Status Summary\n");
    printf("6. Exit\n");
}

int getValidRoom(int rooms) {
    int room;
    printf("Enter room number (1-%d): ", rooms);
    while (scanf("%d", &room) != 1 || room < 1 || room > rooms) {
        printf("Invalid room number! Try again: ");
        while (getchar() != '\n'); 
    }
    return room - 1; 
}

void toggleLight(int rooms, int lights[]) {
    int room = getValidRoom(rooms);
    lights[room] = !lights[room];
    printf("Light in Room %d is now %s.\n", room + 1, lights[room] ? "ON" : "OFF");
}

void readTemperature(int rooms, int temperature[]) {
    int room = getValidRoom(rooms);
    printf("Temperature in Room %d: %d°C\n", room + 1, temperature[room]);
}

void checkMotion(int rooms, int motion[]) {
    int room = getValidRoom(rooms);
    motion[room] = 1;
    printf("Motion detected in Room %d!\n", room + 1);
}

void securitySystem(int rooms, int locks[]) {
    int room = getValidRoom(rooms);
    locks[room] = !locks[room];
    printf("Room %d is now %s.\n", room + 1, locks[room] ? "LOCKED" : "UNLOCKED");
}

void analyzeHouseStatus(int rooms, int lights[], int locks[], int motion[], int temperature[]) {
    printf("\n===== House Status Summary =====\n");
    for (int i = 0; i < rooms; i++) {
        printf("- Room %d: Light %s, Temp %d°C, %s, %s\n",
               i + 1, lights[i] ? "ON" : "OFF",
               temperature[i],
               motion[i] ? "Motion Detected" : "No Motion",
               locks[i] ? "Locked" : "Unlocked");
    }
}
